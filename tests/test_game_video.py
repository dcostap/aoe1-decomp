import hashlib
import io
import json
from pathlib import Path
import sys

import pytest

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools/harness'))
import game_video
from game_video import GameVideo


class Pipe(io.BytesIO):
    def close(self):
        if not self.closed:
            self.saved = self.getvalue()
        super().close()


class Encoder:
    def __init__(self, command, **kwargs):
        self.command = command
        self.stdin = Pipe()
        self.code = 0
        self.killed = False
        Path(command[-1]).write_bytes(b'test-video')

    def poll(self):
        return self.code if self.stdin.closed else None

    def wait(self, **kwargs):
        return self.code

    def kill(self):
        self.killed = True


@pytest.fixture
def encoder(monkeypatch):
    processes = []
    monkeypatch.setattr(game_video.shutil, 'which', lambda name: 'ffmpeg')

    def start(*args, **kwargs):
        process = Encoder(*args, **kwargs)
        processes.append(process)
        return process

    monkeypatch.setattr(game_video.subprocess, 'Popen', start)
    return processes


def frame(time_ms=0, color=1, **changes):
    meta = dict(width=2, height=2, pitch=3, time_ms=time_ms)
    meta.update(changes)
    palette = bytes([0, 0, 0, 99, 255, 0, 0, 99, 0, 255, 0, 99]) + bytes(1012)
    return meta, bytes([color, color, 99, color, color, 99]) + palette


def test_resampling_palette_hashes_and_report(tmp_path, encoder):
    writer = GameVideo(tmp_path)
    writer.add(*frame())
    writer.add(*frame(125, 2))
    writer.add(*frame(200, 1))
    result = writer.close()
    red, green = bytes([255, 0, 0]) * 4, bytes([0, 255, 0]) * 4
    assert encoder[0].stdin.saved == red * 3 + green + red
    assert result['input_frame_count'] == 3
    assert result['encoded_frame_count'] == 5
    assert result['duration'] == 0.25
    assert result['sha256'] == hashlib.sha256(b'test-video').hexdigest()
    assert result['clock']['last_time_ms'] == 200
    rows = [json.loads(line) for line in (tmp_path / 'video-frames.jsonl').read_text().splitlines()]
    assert [row['time_ms'] for row in rows] == [0, 125, 200]
    assert rows[0]['rgb_sha256'] == hashlib.sha256(red).hexdigest()
    assert rows[0]['payload_sha256'] == hashlib.sha256(frame()[1]).hexdigest()
    assert json.loads((tmp_path / 'video.json').read_text()) == result
    assert (tmp_path / 'video.log').is_file()
    assert not list(tmp_path.glob('*.png'))
    assert writer.close() == result
    with pytest.raises(RuntimeError):
        writer.add(*frame(250))
    command = encoder[0].command
    assert command[command.index('-c:v') + 1] == 'libx264'
    assert command[command.index('-pix_fmt') + 1] == 'yuv420p'
    assert '+faststart' in command


def test_duplicate_times_use_latest_surface(tmp_path, encoder):
    writer = GameVideo(tmp_path)
    writer.add(*frame())
    writer.add(*frame(0, 2))
    assert writer.close()['encoded_frame_count'] == 1
    assert encoder[0].stdin.saved == bytes([0, 255, 0]) * 4


def test_off_grid_terminal_time(tmp_path, encoder):
    writer = GameVideo(tmp_path)
    writer.add(*frame())
    writer.add(*frame(51, 2))
    assert writer.close()['encoded_frame_count'] == 3
    assert encoder[0].stdin.saved[-12:] == bytes([0, 255, 0]) * 4


@pytest.mark.parametrize('changes', [
    {'width': 0}, {'width': 3}, {'height': 3}, {'height': 4098},
    {'width': 4096, 'height': 4096}, {'pitch': 1}, {'pitch': 16385},
    {'time_ms': -1}, {'time_ms': 1}, {'time_ms': 0.0},
    {'time_ms': True}, {'width': None},
])
def test_invalid_descriptor(tmp_path, encoder, changes):
    writer = GameVideo(tmp_path)
    with pytest.raises(ValueError):
        writer.add(*frame(**changes))
    assert not encoder


@pytest.mark.parametrize('extra', [-1, 1])
def test_wrong_payload_size(tmp_path, encoder, extra):
    writer = GameVideo(tmp_path)
    meta, data = frame()
    with pytest.raises(ValueError, match='payload'):
        writer.add(meta, data[:-1] if extra == -1 else data + b'x')


@pytest.mark.parametrize('time_ms', [-1, 49, 299951, 300000, 300001])
def test_bad_following_time_aborts(tmp_path, encoder, time_ms):
    writer = GameVideo(tmp_path)
    writer.add(*frame())
    writer.add(*frame(50))
    with pytest.raises(ValueError):
        writer.add(*frame(time_ms))
    assert encoder[0].killed
    assert writer.log.closed and writer.frames.closed
    with pytest.raises(RuntimeError):
        writer.close()


def test_duration_limit(tmp_path, encoder):
    writer = GameVideo(tmp_path)
    writer.add(*frame())
    writer.add(*frame(299950))
    result = writer.close()
    assert result['duration'] == 300
    assert result['encoded_frame_count'] == 6000


def test_dimension_change(tmp_path, encoder):
    writer = GameVideo(tmp_path)
    writer.add(*frame())
    with pytest.raises(ValueError, match='dimensions changed'):
        writer.add(dict(width=4, height=2, pitch=4, time_ms=50), bytes(1032))


def test_empty_stream(tmp_path, encoder):
    with pytest.raises(ValueError, match='empty'):
        GameVideo(tmp_path).close()


def test_encoder_failure(tmp_path, encoder):
    writer = GameVideo(tmp_path)
    writer.add(*frame())
    encoder[0].code = 7
    with pytest.raises(RuntimeError, match='code 7'):
        writer.close()
    assert not (tmp_path / 'video.json').exists()


def test_short_write(tmp_path, encoder, monkeypatch):
    writer = GameVideo(tmp_path)
    writer.add(*frame())
    monkeypatch.setattr(encoder[0].stdin, 'write', lambda data: len(data) - 1)
    with pytest.raises(OSError, match='incomplete'):
        writer.add(*frame(50))
    assert encoder[0].killed


def test_broken_pipe(tmp_path, encoder, monkeypatch):
    writer = GameVideo(tmp_path)
    writer.add(*frame())

    def fail(data):
        raise BrokenPipeError('encoder stopped')

    monkeypatch.setattr(encoder[0].stdin, 'write', fail)
    with pytest.raises(BrokenPipeError):
        writer.close()


def test_encoder_start_failure(tmp_path, encoder, monkeypatch):
    def fail(*args, **kwargs):
        raise OSError('cannot start encoder')

    monkeypatch.setattr(game_video.subprocess, 'Popen', fail)
    writer = GameVideo(tmp_path)
    with pytest.raises(OSError, match='cannot start'):
        writer.add(*frame())
    assert writer.log.closed and writer.frames.closed


def test_encoder_timeout(tmp_path, encoder, monkeypatch):
    writer = GameVideo(tmp_path)
    writer.add(*frame())
    process = encoder[0]

    def wait(timeout=None):
        if timeout is not None:
            raise game_video.subprocess.TimeoutExpired('ffmpeg', timeout)
        return 0

    monkeypatch.setattr(process, 'poll', lambda: None)
    monkeypatch.setattr(process, 'wait', wait)
    with pytest.raises(game_video.subprocess.TimeoutExpired):
        writer.close()
    assert process.killed
    assert writer.log.closed and writer.frames.closed


@pytest.mark.parametrize('missing', [False, True])
def test_missing_or_empty_output(tmp_path, encoder, missing):
    writer = GameVideo(tmp_path)
    writer.add(*frame())
    if missing:
        writer.path.unlink()
    else:
        writer.path.write_bytes(b'')
    with pytest.raises(RuntimeError, match='nonempty'):
        writer.close()


def test_missing_ffmpeg(tmp_path, monkeypatch):
    monkeypatch.setattr(game_video.shutil, 'which', lambda name: None)
    with pytest.raises(FileNotFoundError, match='FFmpeg'):
        GameVideo(tmp_path)


@pytest.mark.parametrize('fps', [0, 121, 20.0, True])
def test_invalid_fps(tmp_path, fps):
    with pytest.raises(ValueError, match='fps'):
        GameVideo(tmp_path, fps)


def test_existing_output_is_not_replaced(tmp_path, encoder):
    (tmp_path / 'video.mp4').write_bytes(b'existing')
    with pytest.raises(FileExistsError):
        GameVideo(tmp_path)
    assert (tmp_path / 'video.mp4').read_bytes() == b'existing'


def test_overlay_pixels_and_hash(tmp_path, encoder):
    writer = GameVideo(tmp_path)
    meta, data = frame()
    meta['overlays'] = [{'rect': [1, 0, 1, 2],
                         'bgrx': bytes([255, 0, 0, 99, 0, 255, 0, 88])}]
    writer.add(meta, data)
    writer.close()
    expected = bytes([255, 0, 0, 0, 0, 255, 255, 0, 0, 0, 255, 0])
    assert encoder[0].stdin.saved == expected
    row = json.loads((tmp_path / 'video-frames.jsonl').read_text())
    assert row['rgb_sha256'] == hashlib.sha256(expected).hexdigest()
    assert row['overlay_rects'] == [[1, 0, 1, 2]]
    assert 'bgrx' not in row


@pytest.mark.parametrize('overlays', [
    None, {}, [None], [{}], [{'rect': [0, 0, 0, 1], 'bgrx': b''}],
    [{'rect': [-1, 0, 1, 1], 'bgrx': bytes(4)}],
    [{'rect': [1, 0, 2, 1], 'bgrx': bytes(8)}],
    [{'rect': [0, 0, True, 1], 'bgrx': bytes(4)}],
    [{'rect': [0, 0, 1], 'bgrx': bytes(4)}],
    [{'rect': [0, 0, 1, 1], 'bgrx': bytes(3)}],
    [{'rect': [0, 0, 1, 1], 'bgrx': bytes(5)}],
])
def test_invalid_overlay(tmp_path, encoder, overlays):
    writer = GameVideo(tmp_path)
    meta, data = frame()
    meta['overlays'] = overlays
    with pytest.raises(ValueError, match='[Oo]verlay'):
        writer.add(meta, data)

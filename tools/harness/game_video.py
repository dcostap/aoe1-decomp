"""Stream palette surfaces to MP4 on a controlled-time frame grid."""
from __future__ import annotations

import hashlib
import json
from pathlib import Path
import shutil
import subprocess

from PIL import Image


class GameVideo:
    """Sample the latest surface at each grid point, starting at zero.

    Times are nondecreasing integer milliseconds. Equal times replace the surface.
    Close places the final surface at the next grid point, including an exact match.
    This preserves the final surface and adds less than two frame periods.
    Other surfaces between grid points can have no encoded frame.
    Calls must come from one thread. Call close after the last add.
    """

    MAX_SECONDS = 300
    MAX_DIMENSION = 4096
    MAX_PIXELS = 4096 * 2160
    MAX_PITCH = 16384

    def __init__(self, output: Path, fps=20):
        if type(fps) is not int or not 1 <= fps <= 120:
            raise ValueError('fps must be an integer from 1 through 120.')
        self.ffmpeg = shutil.which('ffmpeg')
        if not self.ffmpeg:
            raise FileNotFoundError('FFmpeg is not on PATH.')
        self.output = Path(output).resolve()
        self.output.mkdir(parents=True, exist_ok=True)
        self.path = self.output / 'video.mp4'
        for name in ('video.mp4', 'video.log', 'video-frames.jsonl', 'video.json'):
            if (self.output / name).exists():
                raise FileExistsError(self.output / name)
        self.fps = fps
        self.process = None
        self.log = None
        self.frames = None
        self.size = None
        self.previous = None
        self.last_time = None
        self.input_frame_count = 0
        self.encoded_frame_count = 0
        self.closed = False
        self.report = None

    def _start(self, width, height):
        self.log = (self.output / 'video.log').open('xb')
        self.frames = (self.output / 'video-frames.jsonl').open('x', encoding='utf-8')
        command = [self.ffmpeg, '-hide_banner', '-nostdin', '-n',
                   '-f', 'rawvideo', '-pixel_format', 'rgb24',
                   '-video_size', f'{width}x{height}', '-framerate', str(self.fps),
                   '-i', 'pipe:0', '-an', '-c:v', 'libx264', '-preset', 'veryfast',
                   '-crf', '18', '-pix_fmt', 'yuv420p', '-movflags', '+faststart',
                   str(self.path)]
        self.log.write((json.dumps(command) + '\n').encode('utf-8'))
        self.log.flush()
        self.process = subprocess.Popen(command, stdin=subprocess.PIPE,
                                        stdout=self.log, stderr=self.log,
                                        creationflags=getattr(subprocess, 'CREATE_NO_WINDOW', 0))
        self.size = (width, height)

    def _emit(self):
        written = self.process.stdin.write(self.previous)
        if written != len(self.previous):
            raise OSError('FFmpeg accepted an incomplete frame.')
        self.encoded_frame_count += 1

    def _release(self):
        if self.frames:
            self.frames.close()
        if self.log:
            self.log.close()

    def _abort(self):
        self.closed = True
        try:
            if self.process:
                if self.process.poll() is None:
                    self.process.kill()
                self.process.wait()
                try:
                    self.process.stdin.close()
                except OSError:
                    pass
        finally:
            self._release()

    def add(self, meta: dict, data: bytes):
        if self.closed:
            raise RuntimeError('Video writer is closed.')
        try:
            values = [meta.get(key) for key in ('width', 'height', 'pitch', 'time_ms')]
            if any(type(value) is not int for value in values):
                raise ValueError('width, height, pitch, and time_ms must be integers.')
            width, height, pitch, time_ms = values
            if not (0 < width <= self.MAX_DIMENSION and 0 < height <= self.MAX_DIMENSION
                    and width * height <= self.MAX_PIXELS):
                raise ValueError('Frame dimensions exceed the supported bounds.')
            if width % 2 or height % 2:
                raise ValueError('H264 yuv420p requires even dimensions.')
            if not width <= pitch <= self.MAX_PITCH:
                raise ValueError('Frame pitch exceeds the supported bounds.')
            if not isinstance(data, bytes) or len(data) != pitch * height + 1024:
                raise ValueError('Frame payload size differs from its descriptor.')
            if self.size is not None and self.size != (width, height):
                raise ValueError('Frame dimensions changed.')
            if self.last_time is None and time_ms != 0:
                raise ValueError('The first frame time must be zero.')
            if time_ms < 0 or (self.last_time is not None and time_ms < self.last_time):
                raise ValueError('Frame time decreased.')
            if (self.MAX_SECONDS is not None and
                    (time_ms * self.fps + 999) // 1000 + 1 > self.MAX_SECONDS * self.fps):
                raise ValueError('Video duration exceeds the configured maximum.')
            pixels = b''.join(data[y * pitch:y * pitch + width] for y in range(height))
            palette = data[pitch * height:]
            image = Image.frombytes('P', (width, height), pixels)
            image.putpalette(b''.join(palette[i:i + 3] for i in range(0, 1024, 4)))
            image = image.convert('RGB')
            overlays = meta.get('overlays', [])
            if not isinstance(overlays, list):
                raise ValueError('overlays must be a list.')
            overlay_rects = []
            for overlay in overlays:
                if not isinstance(overlay, dict):
                    raise ValueError('Each overlay must be a descriptor.')
                rect = overlay.get('rect')
                if not isinstance(rect, (list, tuple)) or len(rect) != 4 or any(
                        type(value) is not int for value in rect):
                    raise ValueError('Overlay rect must contain four integers.')
                x, y, w, h = rect
                if x < 0 or y < 0 or w <= 0 or h <= 0 or x + w > width or y + h > height:
                    raise ValueError('Overlay rect exceeds frame bounds.')
                bgrx = overlay.get('bgrx')
                if not isinstance(bgrx, bytes) or len(bgrx) != w * h * 4:
                    raise ValueError('Overlay payload size differs from its descriptor.')
                # Controls supply tightly packed, top-down BGRX pixels.
                image.paste(Image.frombytes('RGB', (w, h), bgrx, 'raw', 'BGRX'), (x, y))
                overlay_rects.append(list(rect))
            rgb = image.tobytes()
            if self.process is None:
                self._start(width, height)
            # Use integer comparisons to avoid floating-point grid drift.
            while self.encoded_frame_count * 1000 < time_ms * self.fps:
                self._emit()
            row = dict(input_frame=self.input_frame_count, time_ms=time_ms,
                       width=width, height=height, pitch=pitch,
                       payload_sha256=hashlib.sha256(data).hexdigest(),
                       pixel_sha256=hashlib.sha256(pixels).hexdigest(),
                       palette_sha256=hashlib.sha256(palette).hexdigest(),
                       rgb_sha256=hashlib.sha256(rgb).hexdigest(),
                       overlay_rects=overlay_rects)
            self.frames.write(json.dumps(row) + '\n')
            self.frames.flush()
            self.previous = rgb
            self.last_time = time_ms
            self.input_frame_count += 1
        except Exception:
            self._abort()
            raise

    def close(self) -> dict:
        if self.report is not None:
            return dict(self.report)
        if self.closed:
            raise RuntimeError('Video writer failed or is closed.')
        try:
            if self.previous is None:
                raise ValueError('Cannot encode an empty frame stream.')
            self._emit()
            self.process.stdin.close()
            code = self.process.wait(timeout=60)
            if code:
                raise RuntimeError(f'FFmpeg exited with code {code}; see {self.output / "video.log"}.')
            if not self.path.is_file() or not self.path.stat().st_size:
                raise RuntimeError('FFmpeg did not produce a nonempty video.mp4.')
            digest = hashlib.sha256()
            with self.path.open('rb') as stream:
                for chunk in iter(lambda: stream.read(1024 * 1024), b''):
                    digest.update(chunk)
            report = dict(input_frame_count=self.input_frame_count,
                          encoded_frame_count=self.encoded_frame_count,
                          duration=self.encoded_frame_count / self.fps, fps=self.fps,
                          width=self.size[0], height=self.size[1],
                          path=str(self.path), sha256=digest.hexdigest(),
                          clock={'source': 'controlled', 'unit': 'milliseconds',
                                 'first_time_ms': 0, 'last_time_ms': self.last_time,
                                 'sampling': 'latest surface at fixed grid points; final surface at next grid point'})
            with (self.output / 'video.json').open('x', encoding='utf-8') as stream:
                json.dump(report, stream, indent=2)
                stream.write('\n')
            self._release()
            self.closed = True
            self.report = report
            return dict(report)
        except Exception:
            self._abort()
            raise

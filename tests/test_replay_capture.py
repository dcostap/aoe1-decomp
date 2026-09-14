import copy
import hashlib
import json
from pathlib import Path
import sys

from PIL import Image
import pytest

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools/harness'))
from behavior import validate_replay
from replay_capture import compare_captures
import replay


def sample(directory, color):
    directory.mkdir()
    image = Image.new('RGB', (4, 3), color)
    image.save(directory / 'final.png')
    row = {'name':'final', 'after_updates':30, 'updates':30, 'input':5,
           'boundary':'Paint-entry', 'panel':'Game Screen', 'frame':42,
           'composite':'final.png', 'rgb_sha256':hashlib.sha256(image.tobytes()).hexdigest()}
    report = {'fixture':{'replay':{'captures':[{'name':'final', 'after_updates':30}]}},
              'status':{'ui':{'checkpoints':[row]}}, 'frames':[{'count':42, 'width':4, 'height':3}]}
    return directory / 'report.json', report


def test_matching_capture_and_original_left_image(tmp_path):
    ap, a = sample(tmp_path / 'a', 'red')
    bp, b = sample(tmp_path / 'b', 'red')
    assert compare_captures(ap, bp, a, b)['passed']
    Image.new('RGB', (4, 3), 'blue').save(bp.parent / 'final.png')
    b['status']['ui']['checkpoints'][0]['rgb_sha256'] = hashlib.sha256(Image.new('RGB', (4, 3), 'blue').tobytes()).hexdigest()
    result = compare_captures(ap, bp, a, b, tmp_path / 'comparison')
    assert not result['passed']
    with Image.open(result['checkpoints'][0]['side_by_side']) as image:
        assert image.getpixel((0, 0)) == (255, 0, 0)
        assert image.getpixel((4, 0)) == (0, 0, 255)


@pytest.mark.parametrize('change', [
    lambda x:x['status']['ui'].update(checkpoints=[]),
    lambda x:x['status']['ui']['checkpoints'][0].update(rgb_sha256='wrong'),
    lambda x:x['status']['ui']['checkpoints'][0].update(composite='../final.png'),
    lambda x:x['status']['ui']['checkpoints'][0].update(after_updates=29),
    lambda x:x['status']['ui']['checkpoints'][0].update(boundary='unknown'),
    lambda x:x['status']['ui']['checkpoints'][0].pop('input'),
    lambda x:x['frames'][0].update(width=3),
])
def test_invalid_capture_fails_closed(tmp_path, change):
    path, a = sample(tmp_path / 'a', 'red')
    b = copy.deepcopy(a)
    change(b)
    result = compare_captures(path, path, a, b)
    assert not result['passed'] and 'error' in result


def test_equal_pixels_at_different_update_boundaries_do_not_pass(tmp_path):
    path, a = sample(tmp_path / 'a', 'red')
    b = copy.deepcopy(a)
    b['status']['ui']['checkpoints'][0]['updates'] = 31
    result = compare_captures(path, path, a, b)
    assert not result['passed']
    assert result['checkpoints'][0]['pixels_match']


def test_pixels_can_fail_after_all_state_checks_pass(tmp_path, monkeypatch):
    ap, a = sample(tmp_path / 'a', 'red')
    bp, b = sample(tmp_path / 'b', 'blue')
    monkeypatch.setattr(replay, 'compare_reports', lambda *_: {'passed':True, 'classification':'observed-match'})
    monkeypatch.setattr(replay, 'first_rng_difference', lambda *_: None)
    result = replay.compare_pair(ap, bp, a, b)
    assert result['state_passed']
    assert not result['passed']
    assert result['classification'] == 'capture-divergence'


def test_pixels_are_checked_even_when_state_checks_fail(tmp_path, monkeypatch):
    ap, a = sample(tmp_path / 'a', 'red')
    bp, b = sample(tmp_path / 'b', 'red')
    monkeypatch.setattr(replay, 'compare_reports', lambda *_: {'passed':False, 'classification':'state-divergence'})
    monkeypatch.setattr(replay, 'first_rng_difference', lambda *_: None)
    result = replay.compare_pair(ap, bp, a, b)
    assert not result['state_passed']
    assert result['captures']['passed']
    assert not result['passed']


@pytest.mark.parametrize('captures', [None, [None],
    [{'name':'final', 'after_updates':29}],
    [{'name':'../final', 'after_updates':30}],
    [{'name':'final', 'after_updates':True}],
    [{'name':'same', 'after_updates':1}, {'name':'same', 'after_updates':30}],
    [{'name':'one', 'after_updates':30}, {'name':'two', 'after_updates':20}],
])
def test_capture_schema_rejects_invalid_checkpoints(captures):
    scenario = json.loads((ROOT / 'config/harness/replay-random-smoke.json').read_text())
    scenario['replay']['captures'] = captures
    with pytest.raises(ValueError):
        validate_replay(scenario)

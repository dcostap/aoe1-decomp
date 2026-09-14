import hashlib
import json
from pathlib import Path
import sys

import pytest

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools/harness'))
from capture import save_frame
from suite import compare_checkpoints, load_suite
from ui_fixture import validate_steps


def test_group_has_unique_cases_and_mouse_coverage():
    suite, cases = load_suite()
    assert suite['name'] == 'game UI main menu tests'
    assert len(cases) >= 30
    types = {step.get('type', 'snapshot') for case in cases
             for step in suite['routes'][case['route']] + case['steps']}
    assert {'click', 'move', 'down', 'up', 'text', 'key'} <= types
    for case in cases:
        validate_steps(suite['routes'][case['route']] + case['steps'])


@pytest.mark.parametrize('step', [
    {'name':'bad','type':'move','x':640,'y':0},
    {'name':'bad','type':'click','x':0,'y':-1},
    {'name':'bad','type':'key','key':256},
    {'name':'bad','type':'key','key':True},
    {'name':'bad','type':'text','text':'\x00'},
    {'name':'bad','type':'text','text':'a'*201},
    {'name':'bad','type':'execute-code'},
    {'name':'bad','modifiers':[91]},
    {'name':'bad','modifiers':None},
    {'name':'bad','check':[None]},
    None,
])
def test_invalid_ui_input_rejected(step):
    with pytest.raises(ValueError):
        validate_steps([step])


def test_duplicate_checkpoints_rejected():
    with pytest.raises(ValueError):
        validate_steps([{'name':'same'}, {'name':'same'}])


def test_suite_filter():
    _, cases = load_suite(patterns=['settings-*'])
    assert cases and all(case['id'].startswith('settings-') for case in cases)


def test_unknown_case_rejected():
    with pytest.raises(ValueError, match='No capture test'):
        load_suite(patterns=['not-a-test'])


def test_unsafe_or_duplicate_case_ids_rejected(tmp_path):
    path = tmp_path / 'suite.json'
    for ids in (['../escape'], ['same', 'same']):
        path.write_text(json.dumps({'cases': [{'id': value} for value in ids]}))
        with pytest.raises(ValueError, match='Suite IDs'):
            load_suite(path)


def ui_report(directory, *, early_pixel=0, value=0, native_color=0, seed=1002):
    from PIL import Image
    directory.mkdir()
    frames, checkpoints = [], []
    for index, pixel in enumerate([early_pixel, 0]):
        frame = save_frame(directory, {'width': 1, 'height': 1, 'pitch': 1, 'count': index + 1},
                           bytes([pixel]) + bytes(1024))
        frames.append(frame)
        image = Image.new('RGB', (1,1), (native_color if index == 0 else 0,0,0))
        name = f'checkpoint-{index:03d}.png'
        image.save(directory / name)
        checkpoints.append({'name': f'step-{index}', 'panel': 'Main Menu', 'frame': index + 1,
                            'controls': [{'value': value}], 'composite': name,
                            'rgb_sha256': hashlib.sha256(image.tobytes()).hexdigest(),
                            'rngCount': 1, 'rngTrace': [{'seed': seed}]})
    report = {'frames': frames, 'errors': [], 'manifest': {}, 'arguments': [], 'fixture': {'ui': True},
              'clock': 'calls', 'registry_inputs': {}, 'script_sha256': 'same',
              'status': {'ui': {'done': True, 'checkpoints': checkpoints}}}
    path = directory / 'report.json'
    path.write_text(json.dumps(report))
    return path


def test_equal_ui_checkpoints_pass(tmp_path):
    a, b = ui_report(tmp_path/'a'), ui_report(tmp_path/'b')
    assert compare_checkpoints(a, b, tmp_path/'diff')['passed']


def test_intermediate_difference_fails_even_when_final_frames_match(tmp_path):
    a, b = ui_report(tmp_path/'a'), ui_report(tmp_path/'b', early_pixel=1)
    result = compare_checkpoints(a, b, tmp_path/'diff')
    assert not result['passed']
    assert not result['checkpoints'][0]['pixels_passed']
    assert result['checkpoints'][1]['pixels_passed']


def test_native_child_pixels_are_compared(tmp_path):
    a, b = ui_report(tmp_path/'a'), ui_report(tmp_path/'b', native_color=255)
    result = compare_checkpoints(a, b, tmp_path/'diff')
    assert not result['passed']
    assert result['checkpoints'][0]['pixels_passed']
    assert not result['checkpoints'][0]['composite_passed']


def test_control_state_is_compared_even_with_equal_pixels(tmp_path):
    a, b = ui_report(tmp_path/'a'), ui_report(tmp_path/'b', value=1)
    result = compare_checkpoints(a, b, tmp_path/'diff')
    assert not result['passed']
    assert result['checkpoints'][0]['pixels_passed']
    assert not result['checkpoints'][0]['controls_passed']


def test_checkpoint_rng_is_compared_separately_from_pixels(tmp_path):
    a, b = ui_report(tmp_path/'a'), ui_report(tmp_path/'b', seed=1003)
    result = compare_checkpoints(a, b, tmp_path/'diff')
    assert not result['passed']
    assert result['checkpoints'][0]['pixels_passed']
    assert not result['checkpoints'][0]['rng_passed']


def test_checkpoint_sequence_mismatch_rejected(tmp_path):
    a, b = ui_report(tmp_path/'a'), ui_report(tmp_path/'b')
    report = json.loads(b.read_text())
    report['status']['ui']['checkpoints'][0]['name'] = 'wrong'
    b.write_text(json.dumps(report))
    with pytest.raises(ValueError, match='Checkpoint sequences'):
        compare_checkpoints(a, b, tmp_path/'diff')


def test_changed_composite_image_rejected(tmp_path):
    from PIL import Image
    a, b = ui_report(tmp_path/'a'), ui_report(tmp_path/'b')
    Image.new('RGB', (1,1), 'red').save(b.parent/'checkpoint-000.png')
    with pytest.raises(ValueError, match='image hash'):
        compare_checkpoints(a, b, tmp_path/'diff')


def test_guard_requires_the_expected_boundary_and_no_other_error(tmp_path):
    from suite import guard_passed
    path = tmp_path/'report.json'
    event = {'kind':'forbidden-gameplay', 'boundary':'forbidStart'}
    report = {'errors':[event], 'events':[event]}
    path.write_text(json.dumps(report))
    assert guard_passed(path, 'forbidStart')
    assert not guard_passed(path, 'forbidLoad')
    report['errors'].append({'error':'another failure'})
    path.write_text(json.dumps(report))
    assert not guard_passed(path, 'forbidStart')


def test_original_repeat_comparison_survives_rebuilt_capture_failure(tmp_path, monkeypatch):
    import suite
    definition = {'name':'test', 'routes':{'main':[{'name':'main'}]}}
    case = {'id':'case', 'route':'main', 'steps':[]}
    monkeypatch.setattr(suite, 'load_suite', lambda **kwargs: (definition, [case]))
    staged = []
    def stage(target):
        path = tmp_path/f'{target}-{len(staged)}'
        path.mkdir()
        staged.append(path)
        return path
    monkeypatch.setattr(suite.game, 'stage', stage)
    monkeypatch.setattr(suite, 'capture', lambda runtime, *args: int(runtime.name.startswith('rebuilt')))
    compared = []
    def compare(left, right, output):
        compared.append((left, right))
        return {'passed':True}
    monkeypatch.setattr(suite, 'compare_checkpoints', compare)
    assert suite.run(tmp_path/'suite', original_runs=2) == 1
    assert len(compared) == 1
    assert compared[0][1] == staged[1]/'capture/report.json'

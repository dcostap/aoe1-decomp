"""Feature-map evidence must fail closed. These tests do not run the game."""
import importlib
import json
from pathlib import Path
import struct
import sys

import pytest

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools/harness'))
lab = importlib.import_module('feature_lab')
coverage = importlib.import_module('feature_lab_coverage')


def bits(value):
    return struct.unpack('<I', struct.pack('<f', value))[0]


def actor(oid=1, **fields):
    row = dict(id=oid, owner=1, master=83, hp=bits(25), held=bits(0), state=2,
                inside=None, actions=[])
    row.update(fields)
    return row


def sample(objects, tech=None):
    return dict(objects=objects, players=[dict(id=1, tech=tech)])


def setup(*labels):
    return dict(placed=[dict(id=i+1, label=label, owner=1, master=83) for i, label in enumerate(labels)], orders=[])


def chaos_setup(*labels):
    row = setup(*labels)
    row['layout'] = 'chaos'
    row['orders'] = [dict(kind='work', actor=label, target=label) for label in labels if '-worker-' in label]
    return row


def test_layout_selects_the_setup_script():
    assert lab.LAYOUTS['chaos'] in lab.script_names('chaos')
    assert lab.LAYOUTS['features'] not in lab.script_names('chaos')
    assert lab.LAYOUTS['features'] in lab.script_names('features')
    assert lab.LAYOUTS['chaos'] not in lab.script_names('features')
    assert lab.script_names('features')[-2:] == lab.script_names('chaos')[-2:]
    with pytest.raises(ValueError, match='Unknown feature-lab layout'):
        lab.script_names('nonsense')


def test_chaos_coverage_uses_its_own_labels():
    workers = ['berries-worker-1-0', 'wood-worker-1-0', 'gold-worker-1-0',
               'stone-worker-1-0', 'hunt-worker-1-0']
    labels = workers + ['combat-1-4-0', 'guard-1-0']
    tracker = coverage.Coverage(chaos_setup(*labels))
    tracker.observe(sample([actor(index + 1) for index in range(len(labels))]))
    assert not tracker.result()['passed']
    # Carried resources, a hurt fighter, and a moved guard are the whole evidence set.
    tracker.observe(sample([actor(index + 1, held=bits(5)) for index in range(5)] +
                           [actor(6, hp=bits(20)), actor(7, position=[bits(1), bits(1), bits(0)])]))
    result = tracker.result()
    for name in ('berries', 'wood', 'gold', 'stone', 'hunt'):
        assert result['features']['gather-' + name]['observed'], name
    assert result['features']['combat']['observed']
    assert result['features']['guard-movement']['observed']
    assert result['passed']
    assert result['catalog'] == dict(planned=0, missing=[])


def test_presence_does_not_prove_activity():
    tracker = coverage.Coverage(setup('catalog-1-83', 'wood-worker-0'))
    tracker.observe(sample([actor(1), actor(2)]))
    result = tracker.result()
    assert result['catalog']['missing'] == []
    assert result['observed'] == 0
    assert result['passed'] is False


def test_missing_catalog_entry_stays_visible():
    tracker = coverage.Coverage(setup('catalog-1-83'))
    tracker.observe(sample([]))
    assert tracker.result()['catalog']['missing'] == ['catalog-1-83']


def test_another_object_cannot_replace_a_missing_catalog_entry():
    tracker = coverage.Coverage(setup('catalog-1-83'))
    tracker.observe(sample([actor(2)]))
    assert tracker.result()['catalog']['missing'] == ['catalog-1-83']


def test_loaded_cargo_is_not_replay_gathering_evidence():
    tracker = coverage.Coverage(setup('wood-worker-0'))
    tracker.observe(sample([actor(held=bits(10))]))
    tracker.observe(sample([actor(held=bits(10))]))
    assert tracker.result()['features']['gather-wood']['observed'] is False


def test_trade_requires_a_completed_cargo_return():
    tracker = coverage.Coverage(setup('trade-boat'))
    returning = [dict(type=111, state=8, children=[])]
    tracker.observe(sample([actor(actions=returning)]))
    assert tracker.result()['features']['trade']['observed'] is False
    tracker.observe(sample([actor(held=bits(20), actions=returning)]))
    assert tracker.result()['features']['trade']['observed'] is False
    tracker.observe(sample([actor()]))
    assert tracker.result()['features']['trade']['observed'] is True


@pytest.mark.parametrize('fields', [dict(state=3), dict(owner=2)])
def test_dead_or_converted_trade_cargo_does_not_count(fields):
    tracker = coverage.Coverage(setup('trade-boat'))
    tracker.observe(sample([actor(held=bits(20), actions=[dict(type=111, state=8, children=[])])]))
    tracker.observe(sample([actor(**fields)]))
    assert tracker.result()['features']['trade']['observed'] is False


def test_existing_house_and_villager_do_not_prove_building_or_training():
    tracker = coverage.Coverage(setup())
    tracker.observe(sample([actor(1, master=70), actor(2)]))
    result = tracker.result()['features']
    assert not result['construction']['observed'] and not result['training']['observed']
    tracker.observe(sample([actor(3, master=70, state=0)]))
    tracker.observe(sample([actor(3, master=70), actor(4)]))
    result = tracker.result()['features']
    assert result['construction']['observed'] and result['training']['observed']


def capture():
    return dict(passed=True, errors=[], mode='replay', profile=lab.PROFILE, turns=1,
                script_sha256='x', frida_version='test', frames=[{}],
                states=[dict(phase='leave'), dict(phase='terminal')],
                events=[dict(kind='lab-world')], state_recording=dict(samples=2),
                rng_recording=dict(records=10), status=dict(ticks=1021, rngCount=10,
                    lab=dict(calls=1, clockSites=[1], turn=1, loadedTurn=0, updates=1)))


def test_complete_capture_can_enter_comparison():
    lab.validate_capture(capture())


@pytest.mark.parametrize('failure', ['stale-clock', 'missing-caller', 'wrong-ticks', 'wrong-turn',
                                   'missing-world', 'missing-rng', 'truthy-pass', 'missing-identity'])
def test_incomplete_old_capture_cannot_be_reused(failure):
    row = capture()
    if failure == 'stale-clock':
        row['status']['lab'].update(calls=0, clockSites=[])
        row['status']['ticks'] = 1020
    elif failure == 'missing-caller':
        row['status']['lab']['clockSites'] = []
    elif failure == 'wrong-ticks':
        row['status']['ticks'] += 1
    elif failure == 'wrong-turn':
        row['turns'] += 1
    elif failure == 'missing-world':
        row['events'] = []
    elif failure == 'missing-rng':
        row['rng_recording']['records'] -= 1
    elif failure == 'truthy-pass':
        row['passed'] = 1
    else:
        row['script_sha256'] = None
    with pytest.raises(ValueError):
        lab.validate_capture(row)


def test_resource_carrying_requires_the_assigned_worker():
    tracker = coverage.Coverage(setup('wood-worker-0'))
    resource = actor(2)
    resource['held'] = bits(500)
    tracker.observe(sample([actor(1), resource]))
    assert tracker.result()['features']['gather-wood']['observed'] is False
    worker = actor(1)
    worker['held'] = bits(1)
    tracker.observe(sample([worker]))
    assert tracker.result()['features']['gather-wood']['observed'] is True


def test_action_children_are_observed_without_game_calls():
    assert coverage.action_types([dict(type=9, children=[dict(type=1, children=[])])]) == {1, 9}


def test_health_owner_and_transport_transitions():
    tracker = coverage.Coverage(setup('patient', 'repair-house', 'convert-target-0', 'passenger', 'defender-0'))
    before = [actor(i) for i in range(1, 6)]
    before[2]['owner'] = 5
    tracker.observe(sample(before))
    after = [dict(obj) for obj in before]
    after[0]['hp'] = bits(30)
    after[1]['hp'] = bits(30)
    after[2]['owner'] = 1
    after[3]['inside'] = 100
    after[4]['hp'] = bits(20)
    tracker.observe(sample(after))
    final = [dict(obj) for obj in after]
    final[3]['inside'] = None
    tracker.observe(sample(final))
    for name in ('healing', 'repair', 'conversion', 'boarding', 'unloading', 'combat'):
        assert tracker.result()['features'][name]['observed'] is True


def test_setup_technology_grants_are_not_research_coverage():
    tracker = coverage.Coverage(setup())
    tracker.observe(sample([], [[bits(0), 3], [bits(0), 1]]))
    assert tracker.result()['features']['research']['observed'] is False
    tracker.observe(sample([], [[bits(0), 3], [bits(30), 3]]))
    assert tracker.result()['features']['research']['technologies'] == [(1, 1)]


@pytest.mark.parametrize('value', [float('nan'), float('inf'), float('-inf')])
def test_nonfinite_sample_is_not_passing_evidence(value):
    with pytest.raises(ValueError, match='finite'):
        coverage.number(bits(value))


def make_fixture(path):
    payload = b'reference save'
    (path / 'feature_lab.gmx').write_bytes(payload)
    (path / 'setup.json').write_text(json.dumps(setup()))
    (path / 'catalog.json').write_text('[]')
    manifest = dict(schema=2, name='feature_lab.gmx', size=len(payload),
                    metadata={name:lab.digest(path/name) for name in ('setup.json','catalog.json')},
                    sha256=lab.digest(path / 'feature_lab.gmx'), original_sha256=lab.ORIGINAL_SHA256)
    (path / 'fixture.json').write_text(json.dumps(manifest))
    return manifest


def test_fixture_identity_and_bytes(tmp_path):
    manifest = make_fixture(tmp_path)
    assert lab.validate_fixture(tmp_path) == manifest
    (tmp_path / 'feature_lab.gmx').write_bytes(b'changed save')
    with pytest.raises(ValueError, match='hash or size'):
        lab.validate_fixture(tmp_path)


@pytest.mark.parametrize('field,value', [('schema', 1), ('name', '../feature_lab.gmx'),
                                        ('original_sha256', '0'*64)])
def test_fixture_rejects_unsupported_identity(tmp_path, field, value):
    manifest = make_fixture(tmp_path)
    manifest[field] = value
    (tmp_path / 'fixture.json').write_text(json.dumps(manifest))
    with pytest.raises(ValueError, match='identity'):
        lab.validate_fixture(tmp_path)


def test_changed_fixture_cannot_start_a_game(tmp_path, monkeypatch):
    make_fixture(tmp_path)
    (tmp_path / 'feature_lab.gmx').write_bytes(b'changed')
    monkeypatch.setattr(lab, 'stage', lambda *a, **kw: pytest.fail('Staging must not start'))
    with pytest.raises(ValueError):
        lab.stage_fixture('original', tmp_path)


@pytest.mark.parametrize('name', ['setup.json', 'catalog.json'])
def test_changed_metadata_cannot_start_a_game(tmp_path, monkeypatch, name):
    make_fixture(tmp_path)
    (tmp_path / name).write_text('{"changed":true}')
    monkeypatch.setattr(lab, 'stage', lambda *a, **kw: pytest.fail('Staging must not start'))
    with pytest.raises(ValueError, match='metadata'):
        lab.stage_fixture('original', tmp_path)


def test_feature_fixture_does_not_change_the_legacy_save_set(tmp_path, monkeypatch):
    fixture = tmp_path / 'fixture'
    fixture.mkdir()
    manifest = make_fixture(fixture)
    runtime = tmp_path / 'runtime'
    (runtime / 'savegame').mkdir(parents=True)
    personal = runtime / 'savegame/late_game_match.gmx'
    personal.write_bytes(b'old fixture')
    (runtime / 'runtime_manifest.json').write_text(json.dumps(dict(
        selected_exe_sha256=lab.ORIGINAL_SHA256,
        savegame_source='repository-fixtures', copied_files_before_exe_replacement=[])))
    monkeypatch.setattr(lab, 'stage', lambda target: runtime)
    assert lab.stage_fixture('original', fixture) == runtime
    report = json.loads((runtime / 'runtime_manifest.json').read_text())
    assert report['savegame_source'] == 'feature-lab-fixture'
    assert report['feature_lab'] == manifest
    assert personal.read_bytes() == b'old fixture'
    (runtime / 'savegame/feature_lab.gmx').write_bytes(b'private change')
    assert lab.validate_fixture(fixture) == manifest


def test_all_civilizations_continue_after_a_failed_case(tmp_path, monkeypatch):
    calls = []
    monkeypatch.setattr(lab, 'validate_fixture', lambda path: {})
    def run(command, **kwargs):
        calls.append(command)
        output = Path(command[command.index('--output') + 1])
        output.mkdir()
        passed = len(calls) != 1
        (output / 'report.json').write_text(json.dumps(dict(complete=True, passed=passed)))
        return type('Result', (), dict(returncode=0 if passed else 1))()
    monkeypatch.setattr(lab.subprocess, 'run', run)
    result = lab.test_all(tmp_path / 'results', jobs=1)
    assert len(calls) == len(lab.FIXTURES)
    assert result['complete'] is True and result['passed'] is False
    assert [command[command.index('--fixture') + 1] for command in calls] == [str(p) for _, p in lab.FIXTURES]


def test_game_command_forwards_feature_options(monkeypatch):
    import game
    monkeypatch.setattr(sys, 'argv', ['game.py', 'feature-lab', 'test-all', '--runs', '2'])
    calls = []
    def run(command, **kwargs):
        calls.append(command)
        return type('Result', (), dict(returncode=1))()
    monkeypatch.setattr(game.subprocess, 'run', run)
    assert game.main() == 1
    assert calls[0][1].endswith('feature_lab.py')
    assert calls[0][2:] == ['test-all', '--runs', '2']


def test_first_difference_keeps_length_and_order_strict():
    assert lab.first_difference([1, 2], [1, 2]) is None
    assert lab.first_difference([1, 2], [2, 1])['index'] == 0
    assert lab.first_difference([1, 2], [1]) == dict(index=1, left=2, right=None)

"""Check save input isolation and the saved-game replay contract."""
import copy
import hashlib
from pathlib import Path
import sys

import pytest

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools/harness'))
import human_session as human


@pytest.mark.parametrize('policy', [human.V1_POLICY, human.V2_POLICY, human.V3_POLICY,
                                    human.V4_POLICY, human.V5_POLICY, human.V6_POLICY,
                                    human.V8_POLICY, human.V9_POLICY])
def test_selected_template_matches_pinned_hash(policy):
    assert hashlib.sha256(human.control_template(policy).encode()).hexdigest() == human.template_sha256(policy)


def report():
    return {'clock':'calls', 'script_sha256':human.V5_TEMPLATE_SHA256,
            'registry_inputs':{}, 'arguments':[], 'frida_version':'test',
            'manifest':{'savegame_source':'repository-fixtures',
                        'graphics':'test', 'graphics_sha256':'graphics', 'graphics_config_sha256':'config',
                        'copied_files_before_exe_replacement':[
                            {'path':'savegame/late_game_match.gmx', 'sha256':'fixture'},
                            {'path':'data/world.dat', 'sha256':'data'}]}}


def session():
    return {'schema':1, 'mode':'replay', 'duration_ms':1000, 'events':[],
            'contract':human.session_contract(report(), human.V5_POLICY)}


def test_new_recordings_use_save_profile():
    plan = human.execution_plan({'schema':1, 'mode':'record', 'duration_ms':1000})
    assert plan['executed_policy'] == human.V8_POLICY
    assert plan['executed_script_sha256'] == human.V8_TEMPLATE_SHA256


@pytest.mark.parametrize('change', ['replace', 'remove', 'add', 'rename'])
def test_save_contract_checks_all_save_inputs(change):
    data = session()
    actual = report()
    human.verify_starting_contract(data, actual)
    rows = actual['manifest']['copied_files_before_exe_replacement']
    if change == 'replace':
        rows[0]['sha256'] = 'changed'
    elif change == 'remove':
        rows.pop(0)
    elif change == 'add':
        rows.append({'path':'savegame/private.gmx', 'sha256':'personal'})
    else:
        rows[0]['path'] = 'savegame/renamed.gmx'
    with pytest.raises(ValueError, match='starting contract differs'):
        human.verify_starting_contract(data, actual)


def test_save_profile_rejects_local_runtime():
    actual = report()
    actual['manifest']['savegame_source'] = 'local-runtime'
    with pytest.raises(ValueError, match='repository save fixtures'):
        human.verify_starting_contract(session(), actual)


def test_controlled_save_replay_keeps_strict_contract():
    data = session()
    data.update(upgrade_rule=human.V5_TO_V6_UPGRADE, recording_sha256='1'*64)
    before = copy.deepcopy(data)
    plan = human.verify_starting_contract(data, report())
    assert plan['executed_policy'] == human.V6_POLICY
    assert plan['same_policy_replay'] is False
    assert data == before
    data['upgrade_rule'] = human.V2_TO_V4_UPGRADE
    with pytest.raises(ValueError, match='exact v2 policy'):
        human.execution_plan(data)


def test_preserved_late_game_recording():
    root = Path(__file__).resolve().parents[1]
    recording, sha256 = human.load_recording_with_sha256(root / 'config/harness/human-late-game-match.json')
    assert sha256 == '07f2a4900af0f0c769224f1c9d5c9f561fce7d2aff16cdfdcaf300797f0fb5a6'
    assert recording['policy'] == human.V5_POLICY
    assert len(recording['events']) == 559
    saves = {name:value for name,value in recording['contract']['assets'].items()
             if name.lower().startswith('savegame/')}
    assert saves == {'savegame/late_game_match.gmx':
                     'fccd0ca0ccd98a6658a1eeb3b306c89afee3af9caf58ab518ee04eae434687f4'}

"""Check the pinned human profiles and the editor profile.

These tests do not run the game.
"""
from __future__ import annotations

import hashlib
from pathlib import Path
import sys

import pytest

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools/harness'))
import human_session as hs


def composed(policy):
    return hashlib.sha256(hs.control_template(policy).encode()).hexdigest()


@pytest.mark.parametrize('policy,pinned', [(hs.V1_POLICY, hs.V1_TEMPLATE_SHA256),
                                           (hs.V2_POLICY, hs.V2_TEMPLATE_SHA256),
                                           (hs.V3_POLICY, hs.V3_TEMPLATE_SHA256),
                                           (hs.V4_POLICY, hs.V4_TEMPLATE_SHA256),
                                           (hs.V5_POLICY, hs.V5_TEMPLATE_SHA256),
                                           (hs.V6_POLICY, hs.V6_TEMPLATE_SHA256),
                                           (hs.V7_POLICY, hs.V7_TEMPLATE_SHA256),
                                           (hs.V8_POLICY, hs.V8_TEMPLATE_SHA256),
                                           (hs.V9_POLICY, hs.V9_TEMPLATE_SHA256),
                                           (hs.V10_POLICY, hs.V10_TEMPLATE_SHA256),
                                           (hs.V11_POLICY, hs.V11_TEMPLATE_SHA256)])
def test_every_profile_composes_to_its_pinned_hash(policy, pinned):
    assert composed(policy) == pinned


def test_editor_profile_is_its_own_script():
    assert composed(hs.V7_POLICY) != composed(hs.V6_POLICY)
    # The layer that marks the profile reached the composed script.
    marker = 'An editor recording must not block a startup path'
    assert marker in hs.control_template(hs.V7_POLICY)
    assert marker not in hs.control_template(hs.V6_POLICY)


def test_only_the_editor_profile_allows_the_editor():
    assert hs.startup_blocks(hs.V7_POLICY) == []
    assert hs.startup_blocks(hs.V10_POLICY) == []
    assert hs.startup_blocks(hs.V11_POLICY) == []
    assert hs.startup_blocks(hs.V5_POLICY) == ['forbidScenario', 'forbidEditor']
    assert hs.startup_blocks(hs.V6_POLICY) == ['forbidScenario', 'forbidEditor']
    assert hs.startup_blocks(hs.V1_POLICY) == ['forbidLoad', 'forbidScenario', 'forbidEditor']
    with pytest.raises(ValueError, match='Unknown human input policy'):
        hs.startup_blocks('nonsense')


@pytest.mark.parametrize('policy', [hs.V5_POLICY, hs.V7_POLICY, hs.V8_POLICY, hs.V10_POLICY])
def test_record_capable_profiles_hold_no_replay_only_layer(policy):
    # The v3 and v4 layers stop a session that has no replay inputs.
    assert 'requires replay inputs' not in hs.control_template(policy)


@pytest.mark.parametrize('policy', [hs.V8_POLICY, hs.V9_POLICY, hs.V10_POLICY, hs.V11_POLICY])
def test_current_profiles_have_no_input_recording_cap(policy):
    assert 'Input recording limit reached' not in hs.control_template(policy)


def test_editor_input_target_identity_includes_visibility():
    # The editor keeps hidden edit panels beside the visible one. One class and one
    # control id repeat, so visibility must separate them.
    core = (Path(hs.__file__).parent / 'human.js').read_text()
    assert 'vis:isVisible(hwnd) ? 1 : 0' in core
    assert 'other.vis === part.vis' in core
    assert 'function resolveRoute' in core


def test_responsive_editor_profile_accepts_mouse_wheel():
    core = (Path(hs.__file__).parent / 'human-v10-core.js').read_text()
    assert '0x20a].includes(message)' in core
    assert 'message !== 0x20a' in core


def test_replay_upgrade_profiles_keep_their_layers():
    for policy in (hs.V3_POLICY, hs.V4_POLICY, hs.V6_POLICY, hs.V9_POLICY, hs.V11_POLICY):
        assert 'requires replay inputs' in hs.control_template(policy)


def test_record_plan_follows_the_editor_flag():
    session = {'schema': 1, 'mode': 'record', 'duration_ms': 60000}
    assert hs.execution_plan(session)['executed_policy'] == hs.V8_POLICY
    session['editor'] = True
    plan = hs.execution_plan(session)
    assert plan['executed_policy'] == hs.V10_POLICY
    assert plan['executed_script_sha256'] == hs.V10_TEMPLATE_SHA256


def test_replay_keeps_the_recorded_profile():
    session = {'schema': 1, 'mode': 'replay', 'duration_ms': 60000, 'events': [],
               'contract': {'policy': hs.V7_POLICY, 'script_sha256': hs.V7_TEMPLATE_SHA256,
                            'savegame_source': 'repository-fixtures',
                            'original_sha256': hs.ORIGINAL_SHA256}}
    plan = hs.execution_plan(session)
    assert plan['executed_policy'] == hs.V7_POLICY
    assert plan['same_policy_replay'] is True


def test_editor_recording_accepts_visible_window_routes(tmp_path):
    recording = {'schema': 1, 'policy': hs.V7_POLICY,
                 'contract': {'policy': hs.V7_POLICY, 'script_sha256': hs.V7_TEMPLATE_SHA256,
                              'savegame_source': 'repository-fixtures',
                              'original_sha256': hs.ORIGINAL_SHA256},
                 'duration_ms': 1,
                 'events': [{'time_ms': 0, 'turn': 0, 'updates': 0, 'panel': 'Editor',
                             'route': [{'id': 0, 'cls': 'Static', 'vis': 0}],
                             'message': 512, 'value': 0, 'parameter': 0}]}
    path = tmp_path / 'editor-recording.json'
    path.write_text(__import__('json').dumps(recording))
    loaded, _ = hs.load_recording_with_sha256(path)
    assert loaded['policy'] == hs.V7_POLICY

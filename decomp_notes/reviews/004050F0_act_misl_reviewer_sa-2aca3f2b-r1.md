# Independent review: 004050F0 `update`

- Workflow: matching with reviewers
- Reviewer: `sa-2aca3f2b-r1`
- Worker package: `sa-ca051916`
- Worktree: `C:/Projects/my_decomps/aoe1_reviewer_refill_47`
- Branch: `reviewer-refill-47`
- Base: `3bbb60feb0341c4fdd806cfc28fcaebe95ab96e1`
- Scope: `src/act_misl.cpp`, scratch `004050F0`

## Reviewed inputs

The reviewed state chain is complete for the worker scope:

| State | State name | Result event | Result |
|---|---|---|---|
| `69285ad321e8542fea0e8c14677c9d53ee6a8caf916f0d3338ed430564d7dc5e` | `sa-ca051916-r1-004050F0-baseline` | `4be0a5a77bb8cbc24b75d457d880adf8c7938fcf1ac3388533d85cb567538e94` (`9faa61f59b734d0b8ee44ad907eee390`) | `MISMATCH`, 4 bytes |
| `c59118edbd2027a7ad349dfaf618c4ed8e87a2705bff7ca84ab2424303be6f3d` | `sa-ca051916-r1-004050F0-pointer-reversed` | `269a092eee65296d47d7f34b08eada9cdf47875af44eb75c217694ed9760d817` (`46e03e6a885943b4a69be9e877994991`) | invalid capture; no checker result |
| `e96413936f8d60b014672231135325cb09cb2845f0fbfd6fa3b46588edc41b69` | `sa-ca051916-r1-004050F0-pointer-reversed-v2` | `d7a99b9fbd1238063ddd404d9c477e64c53f58122df1cc628e7b13488bfd5fcb` (`0f083417dfcb43b4a89055d1adb49912`) | `MISMATCH`, 5 bytes |
| `7dcee7edf15d8eecdef187607b33651ac1a6e5cf466ae4e6e22c0fc5f4703ffc` | `sa-ca051916-r1-004050F0-pointer-neq` | `334fcd35b1bee8452bbd250549bdee16d03009ff0438e42926d72f1e7bcad846` (`8eb982683d2c4518a0ac8e19c2eb850d`) | `MISMATCH`, 4 bytes |
| `ee574e89849b759f2a75cdfa0f6456a27a843f82239cd530dea21fb12195243c` | `sa-ca051916-r1-004050F0-target-alias` | `5052516eb8d0c354cea6fef9b1f77cd301766915d826f79f1b24f31c6f74221b` (`39df4f4b7da447c69765847b236d4071`) | `MISMATCH`, 4 bytes |
| `45f3d63eb5fe126676210011e817df3e0c68d9638479dfe59ee4de22ca28dcc4` | `sa-ca051916-r1-004050F0-final-natural` | `7065f151e042d798c76ce3585684e5062fec7943571e112c5ec5ac5dfb1e83c` (`e0acd85ffe6b466daa24660ecde1e439`) | `MISMATCH`, 4 bytes |

The final reported handoff is event `9d6183e04c6321762480fdac6eff05746f434ae54ac184def9d32292eb2ee47c` (`629c1d81f5fd40d290301269756e3511`). The baseline and final states use compiler-input fingerprint `a6a3d96ba64e2de7cf1136fb6d349736e3cdd060f5849de32edfda62869fda01` and source hash `21bf3f9878d5c3f014b98ea086cc57128a24c10c0e4ed9cdb6e721a66d1b0fb6`.

## Behavior

The oracle assembly at `004053E7` reads `this->target_obj` first (`mov edx,[esi+10h]`), then reads `node->node` (`mov ecx,[ebp]`), and compares them. The final rebuild reads `node->node` first, then `this->target_obj`, and emits the same logical pointer comparison. Both forms agree for valid object and list state.

The two memory reads can fault in different order for malformed `this` or list memory. No runtime harness or executable evidence proves that such states are unreachable or that their faults are equivalent. The four-byte difference is therefore not an accepted-drift proof. No behavioral test coverage exists for this fault path.

The invalid pre-edit capture is correctly preserved as invalid. The corrected reverse-equality probe emits the node read first and reverses the compare register form. The inequality-break and branch-local alias probes both emit the same four-byte result as the baseline. Their source states were restored before the final state.

## Source

The current natural owner is `src/act_misl.cpp`, and the final source hash matches both the baseline state and the approved base. The mode-0 source remains `if (this->target_obj == node->node)`. There is no source, header, flag, registry, inventory, or test change in this review scope.

The corrected reverse-equality state differs from the final source only at the mode-0 comparison. Its source is the node-first spelling, and its compiled instructions also read the node first. Thus the worker note sentence that says this probe “loaded the target first” is factually wrong. The note should say that the probe still emitted the node read first and reversed the compare register form.

Source integration: **APPROVE unchanged**. No source promotion or exact candidate is proposed.

## Bytes

The final target check and cached final event agree:

- Original/rebuilt size: `955/955`
- Frame: `0x18/0x18`
- Instructions: `353/353`
- Calls: `24/24`, all aligned; no site gaps or target-count differences
- Owner: match, `?update@RGE_Action_Missile@@UAEEXZ`
- Boundary: valid, no boundary escape
- Relocations: `11/11` safely masked; no target mismatch
- Strict positional diff: `4` bytes, `0.4188%`, two spans
- Result: `MISMATCH`

The final rebuilt bytes around the mismatch are `8B 55 00 8B 4E 10 3B CA` at `004053E7`. The oracle bytes are `8B 56 10 8B 4D 00 3B CA`. The strict differences are the two bytes at relative offsets `0x2F8..0x2F9` and the two bytes at `0x2FB..0x2FC`. They encode the pointer-read order; the compare bytes remain `3B CA`.

The corrected reverse probe produced five differing bytes because it kept the node-first reads and changed the compare to the opposite register form. The inequality-break and alias probes each produced four differing bytes. No exact claim is valid because no state reports `MATCH` and `0.0000%`.

## Integration

- Source decision: **APPROVE unchanged**.
- Proposed status: **APPROVE retaining `scratch`**. Do not promote `004050F0` to `matching`, `accepted_drift`, or `verified_logic`.
- Experiment preservation: **APPROVE**. Preserve every listed state, including the invalid capture and all rejected probe events.
- Candidate patch: none required.
- Note decision: **APPROVE** after correction. The worker corrected the false
  load-order sentence. No rebuild was needed.

The final one-job closure is independently reproduced at `build/reviewer-sa-2aca3f2b-act_misl/report.txt`. It reports five matching siblings, `00404DB0 set_state` at a 210-byte mismatch, and `004050F0 update` at a four-byte mismatch. No changed owner exists.

Validation performed:

- `python tools/check_function.py --va 004050F0 --no-build --detail full --call-map --block-map --stack-map --no-history` — `MISMATCH`, 4 bytes; owner, boundary, relocations, and all 24 calls align.
- `python tools/audit_translation_unit_functions.py --group act_misl --jobs 1 --output-dir build/reviewer-sa-2aca3f2b-act_misl` — passed; five matching siblings, `00404DB0` at 210 bytes, target at 4 bytes.
- State and event inspection confirmed all parent links, fingerprints, source hashes, result events, and the invalid-capture finding.

The prior restart condition was to change only the worker note sentence to
describe the corrected probe's actual node-first load order. The worker met
that condition and preserved the correction event.

## R2 follow-up

The worker correction is recorded by event
`16ee39455eb6d105cbf798174c610d206c692ceaf6c52c35f3a41afef3d67805`.
It states that the reverse-equality probe emitted node-first reads, reversed
the compare-register form, and produced five differing bytes.

The target note now has the corrected wording. The current source hash remains
`21bf3f9878d5c3f014b98ea086cc57128a24c10c0e4ed9cdb6e721a66d1b0fb6`.
There is no diff in `src/`, `include/`, flags, registry, inventory, tests, or
the behavior oracle. The only tracked worktree change is the durable target
note. The correction event has no source artifact.

Final recheck: **APPROVE**. Source retention, scratch status, experiment
preservation, and the corrected note are accepted. No rebuild is required.

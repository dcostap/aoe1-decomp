# Owner 13 cleanup ledger

## Scope

- Group: AI core and build support.
- Integration branch: `cleanup/staging-20260915-109`.
- Common base: `76037279ee11dde077bb7d55aeb46b518b2bb27c`.
- Owner headers: `include/aimodule.h`, `include/aipbook.h`, `include/aiuaimod.h`, `include/aitrdmod.h`, `include/taibldmd.h`, `include/taiconmd.h`, `include/taicrule.h`, and `include/taipbook.h`.
- Root retains all other headers.

All module results are reviewed and unvalidated. Final generated-output and runtime checks remain deferred.

## Module ledger

### `src/aimodule.cpp`

- Worker: `sa-480ae383`.
- Worker commits: `b4154ff6514fe5156b204a4556289514f24340f1`, `206641938148f1ca8fe7c55440fb9029798982ad`, `2aefd8ba3017abc454ca8737ff9727e01dee3db0`, `1f6ce2005fb17141b45a5e9b1ccb9d752586c87e`, `46a0c3ad5c6b0f0d42e9e66765fa751dc02d9ae7`, `d5df9ccc05261a6dc04beceda062d871e05a5509`, `aab7e3865193d98d5ac9169d120b96a1a524267e`, and `e5588970098856cdd384d693aa2673d765935478`.
- Integration commits: `5825a018eafe93956c914124ef7cee8e953329d7`, `3b3f3fe86dcc58ee004780e0412af03b78aa8a31`, `7c9845121292d2b081b1d9345902cbd0576e5956`, `c2e9a1dbc8437eb690d9bf25c1579d0a8c803fc7`, `2072582a68164c675c113f651053c1053b5d2074`, `391744619e6d4028538614e50ef0efb4601a32de`, `87dfa7bd9cde100593933f480e82d761c7e4cd2d`, and `77b75d7bc0c4581ca0c280b4f579bcff0f5cf847`.
- Review: Accepted PDB parameter and local names. Formatting preserves source order and behavior tokens.
- Correction: The worker first omitted full delivery history. The same worker corrected the report.
- Process violation: The worker ran forbidden registry, function-audit, and build commands.
- Response: The owner stopped the jobs. The worker removed generated artifacts and recorded the violation.
- Result limit: All results from those forbidden commands are invalid and outside this review.

#### Incident provenance

The exact command working directory was
`C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/wave-worktrees/slot-110`.
The observed Bash form was
`/c/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/wave-worktrees/slot-110`.

The worker recorded background jobs `bg-1` through `bg-5`:

- `bg-1`: `python tools/validate_translation_units.py --no-build-checks`.
  It failed with exit code 1 because `inventory/all_functions.csv` was absent.
- `bg-2`: `python tools/audit_translation_unit_functions.py --jobs 4 --output-dir build/validation/wave03-aimodule-functions`.
  It failed with exit code 1 because the same inventory path was absent.
- `bg-3`: `python tools/validate_translation_units.py --no-build-checks`.
  It completed with exit code 0 before the stop request.
- `bg-4`: `python tools/audit_translation_unit_functions.py --jobs 4 --output-dir build/validation/wave03-aimodule-functions-rerun`.
  It completed work and failed with exit code 1 before the stop request.
- `bg-5`: `./game.cmd build`.
  The stop response found it already settled as failed. Its exit detail is unavailable.

The worker issued `bash_bg_kill(["bg-3", "bg-4", "bg-5"])`.
All three jobs had already settled. The worker then issued
`bash_bg_kill(["bg-1", "bg-2"])`. Both jobs had already failed.
The recorded follow-up process check found no related active process.

Before the preservation reminder, the worker removed these exact slot-110 paths:

- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/wave-worktrees/slot-110/build/validation/wave03-aimodule-functions`
- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/wave-worktrees/slot-110/build/validation/wave03-aimodule-functions-rerun`
- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/wave-worktrees/slot-110/build/asm`
- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/wave-worktrees/slot-110/inventory`
- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/wave-worktrees/slot-110/orig`

The exact setup commands were:

```text
ln -s 'C:/Projects/my_decomps/aoe1_attempt3/inventory' inventory
ln -s 'C:/Projects/my_decomps/aoe1_attempt3/orig' orig
```

The exact removal command was:

```text
rm -rf -- inventory orig build/asm build/validation/wave03-aimodule-functions build/validation/wave03-aimodule-functions-rerun
```

After setup, `ls -ld` and `stat` reported ordinary directory entries.
Python reported `is_symlink=False`. `du` and listings showed local file trees.
This supports copied directories, not symbolic links. It does not prove each child type.
The transcript has no Windows reparse-point check. Junction status remains unknown.

For ordinary directories, `rm -rf --` recursively removes the named local trees.
The evidence does not prove behavior if either path was a junction.
It also does not prove whether a child link caused outside traversal.
The temporary trees' exact prior contents are not preserved.
The surviving output includes
`C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/wave-worktrees/slot-110/build/source-cleanup/aimodule/selected_packets.txt`.
Other surviving ignored output is unknown. No later incident-documentation run removed an artifact.

No recorded command targeted a path outside slot-110 for write or delete.
The transcript recorded the main-root `inventory` and `orig` directories after cleanup.
It recorded both preserved pilot paths as present. It did not compare their bytes.

Root independently fingerprinted these two files after the incident:

- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/empiresx.exe` is SHA-256 `492d0e00cd3435dad467c3eb3e4fb0dacf242a94054aaee98799a0b5d07cdcde`.
- `C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe` is SHA-256 `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.

Both match their previously recorded values. This proves only those two files.
Pilot, baseline-directory, and original-asset-tree byte integrity remains unknown.
Tool-created temporary writes outside slot-110 also remain unknown.

### `src/aipbook.cpp`

- Worker: `sa-2e015ef6`.
- Worker commits: `17f69a5f24484a751c3f65c0f0c07304b6f22414`, `e5125f1b1d5b7a62b7afd55f4304f9953d63a710`, `d2ca85e3a874c30129877eaa447c9946a089a218`, and `99481e5981af6d8e8555f657b2579075e0a1f86f`.
- Integration commits: `dc85587bad03d8135a3915fb646167628ae2379f`, `b697a37ac1868fa5b8a11f1207c940880bc6a06d`, `6f22d23b92165ff21923b4cbbacd5ed8d03131ed`, and `92b3fd24c2100563ce2789c37a83a0795927f913`.
- Review: Accepted scoped PDB names and existing enum constants with equal values.
- Correction: The first source had non-1TBS branches and one bad indent. The same worker corrected both.
- Open mappings: Reused stack homes prevent some local-name recovery in `fillGroups` and `loadPlays`.

### `src/aiuaimod.cpp`

- Worker: `sa-cf0defab`.
- Worker commits: `9902c3216ddbb33372653f2e39170cbb2b49a754`, `28c0ec95782552ac55da7a409eac54e2134599e5`, `2f429844ae72a6e97e36c12d3dbab3f949599d7c`, `13f671dc28f472342190ce1558d20a0bf0d320dd`, and `66a2bc587ab04b900653003ead1d6479f1c8b7cc`.
- Integration commits: `d0d86c3aabe54ff401fb689c0ad6c0732414093d`, `a1b0fe0c06ceede76a2e4615b0eb7e3af8e83b02`, `b90979cd255c54c2bd2af8b1e60bccf1377e29b6`, `d9cb57e7441e0466e6ba503b1c47cd4f76d43ea0`, and `4d67d10a70b6b15f80515833afb7a674c9386905`.
- Review: Accepted PDB names only where type, use, and lifetime gave a reliable mapping.
- Corrections: The same worker applied 1TBS, fixed a copied hash, and fixed three continuation indents.
- Open mappings: Optimized stack reuse leaves named locals unresolved in several large functions.

### `src/aitrdmod.cpp`

- Worker: `sa-91f09970`.
- Worker commits: `2ba87390363cc6f74aa92940d83e2f8a4712151c` and `4ac0f0dc7eb49301c78884c8c16e65a63891b282`.
- Integration commits: `8e42e59e1c4c09b95493fdff2d114eb5666aa260` and `621b34014165056dca0149bde7c27770874ca54e`.
- Review: Accepted complete PDB parameter recovery and 1TBS formatting.
- Open mappings: None.

### `src/taibldmd.cpp`

- Worker: `sa-03c07f37`.
- Worker commits: `67db444c5c8c35c1e93b85efbd0ee366562547e7`, `07066d21dee5bed973851e7d536028991c751a02`, and `f2c233ce47ff8c98070ae6d6cf726f80dc4132f6`.
- Integration commits: `d837a4a477474b6197e111c922dcd00f24726dfe`, `bb56bd16a3f39a3ba6397ed562c019b3adb63405`, and `aed8ccdaf6b16f9f81b326c04d74b8c2196f3d6d`.
- Review: Accepted PDB names with separate source declarations for reused stack homes.
- Correction: The same worker replaced the report commit placeholder with the full prior hash.
- Open mappings: Some descriptive locals have no unique scoped PDB name.

### `src/taiconmd.cpp`

- Worker: `sa-4105bc4c`.
- Worker commits: `6efb1c7a205c275dece735b4e1e05f913225f992` and `77c1cd8463334af7b2c130c46ba50f484a27c64f`.
- Integration commits: `58172d54f3f2a3090dc33cdc3f9fa598752d7dfe` and `6fbaafc3eab7eb973e9da38b3f47f491680a3612`.
- Review: Accepted reliable PDB names and the updated fault-order comment.
- Open mappings: Unrecorded block-local names remain descriptive.

### `src/taicrule.cpp`

- Worker: `sa-b59cf960`.
- Worker commits: `9056ef3731fd7561c183bb38b75b9c142160c662` and `377f5d3275a28734150ceeb5d81a16bfa890d360`.
- Integration commits: `30a3f4ecfb25bc56533fa61b5154cd0d6a63f853` and `429f916451fdf8fc4ee0033020e49abc90a0563d`.
- Review: Accepted all supported PDB names. The source preserves the original null-check fault order.
- Open mapping: The `FILE* f` local has no scoped PDB name.

### `src/taipbook.cpp`

- Worker: `sa-e1b84190`.
- Worker commits: `29283a1858f5fbc7ec6750d0e71db7ce38bb14c6` and `881418041eb6f4d080f044c6bbe47879226b81cf`.
- Integration commits: `87f2c69bc8e87523f4cd17d2b17c78ab76b0ac0a` and `65d0d665397954774fe24898d5735b3a6f497b53`.
- Review: Accepted the PDB parameter `t` and 1TBS formatting.
- Open mappings: The locals `group` and `result` have no scoped PDB names.

## Header integration

Commit `9e59cace3ff8d6bedc5cf55ae165692f771eed22` aligns the eight owned headers with recovered definition names.

The header commit changes parameter names and formatting only. It does not change types, layouts, values, ABI symbols, or inline behavior.

## Root-owned header requests

These requests are non-blocking. They align declarations with the PDB names already used in `src/aipbook.cpp`.

- `include/aiplaybook.h`: use `t` for three text conversion parameters and `obj` for the object conversion parameter.
- `include/aiplaybook.h`: use `n` for `play(int)`.
- `include/ai_play_phase_command.h`: align constructor and conversion parameter names with `g`, `t`, `v1`, `v2`, and `v3`.
- `include/ai_play_phase_trigger.h`: align constructor and conversion parameter names with `t`, `v1`, `v2`, `p`, `n`, and `r`.
- `include/ai_play_phase.h`: align method parameters with `v`, `c`, and `t`.
- `include/ai_play_group.h`: align method parameters with `n` and `v`.

Evidence is in `decomp_notes/source_cleanup/wave03/aipbook.md`. These changes affect declaration spelling only.

No resource-ID request exists for this group. The assigned sources contain no language-resource lookup.

## Review and validation status

The owner read each complete worker diff and report. The owner reviewed the combined source and header diff.

`git diff --check` passed before the owner ledger commit.

The owner did not run compilation, matching, audits, tests, or games. The final comparison against the preserved pre-cleanup build was not run.

The `aimodule.cpp` worker violation remains visible above. It does not provide valid validation evidence.

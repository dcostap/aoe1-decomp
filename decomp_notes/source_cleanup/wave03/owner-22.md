# Owner 22: text and file support

## Scope

- Group: text and file support.
- Integration branch: `cleanup/staging-20260915-190`.
- Integration worktree: `build/source-cleanup-20260915/wave-worktrees/slot-190`.
- Common base: `76037279ee11dde077bb7d55aeb46b518b2bb27c`.
- Source modules: `Chat`, `color`, `colorlog`, `debuglog`, `dstring`, `file_stf`, `mystring`, and `registry`.
- Owned headers: `include/chat.h`, `include/color.h`, `include/colorlog.h`, `include/debuglog.h`, `include/dstring.h`, `include/file_stf.h`, `include/mystring.h`, and `include/registry.h`.

Root owns all other headers. This includes `include/resource_ids.h` and `include/game_globals.h`.

## Review and integration ledger

### `src/Chat.cpp`

- Worker: `sa-b32e320e`.
- Worker commits:
  - `727e0dc3aafccda192d514b899a28cd6717ac082`
  - `d6018f536bdb9b7621236146353e29b5bde632b4`
  - `6e0f8a4214b86d2bb92b988464fda0866ca4e60f`
- Integration commits:
  - `40db2f54d242a32c1fdc6e24f728c39976cdd548`
  - `fe193f20d994e9f006ece83619e4fbc917acc494`
  - `bad612dcbff3a3f2933a764e536d14375d881ae7`
- Review result: approved and integrated.
- Findings: the source restores all PDB parameter names. `WM_USER` replaces its proved `0x400` value.
- Correction: the first report assigned `chat.h` to root. It also called `0x17D5` a message ID.
- Correction result: the report now assigns the header to owner 22. It identifies `0x17D5` as the `WM_USER` `wParam` payload.
- Header action: `include/chat.h` now uses the recovered declaration names.

### `src/color.cpp`

- Worker: `sa-8b10c7bd`.
- Worker commits:
  - `65f9edaf218070d99a0986246a23764d9eda1f00`
  - `db103c8f34847c402c5f746b3e28d98c46849680`
  - `8d5b374ed9978def55eea0600ae056cc69d16fc8`
- Integration commits:
  - `fdf808325c2e8491b29a937394852b0621d122e9`
  - `88d25defa7bb3e5f83558e7f82d607672a0594de`
  - `b89410c2fc9bf0e85bdfb0c27d0e10708ae572e5`
- Review result: approved and integrated.
- Findings: the source restores proved parameter names and local `index1`. It uses 1TBS formatting.
- Unresolved mapping: the `FILE*` constructor keeps `id_val`. The PDB reuses that stack slot for `in_id` and `temp_type`.
- Correction: the first report assigned `color.h` to owner 20.
- Correction result: the report now assigns the header to owner 22. Its declaration request keeps `id_val`.
- Header action: `include/color.h` now follows the cleaned definitions.

### `src/colorlog.cpp`

- Worker: `sa-8518b8f0`.
- Worker commits:
  - `ccee99a6bc723ba0fbf3a88f3a96113b54bc6858`
  - `0e51a7b4ec2d063da282d013c2c5b28d624ddbc2`
- Integration commits:
  - `64232484ab17d5919d5b07973bd6a3b454d72d0a`
  - `14d5fbb46065f55ec358a8ba438ceb7b5272a25e`
- Review result: approved and integrated.
- Findings: the source restores `c1`, `c2`, and `pos`.
- Constant evidence: pinned `DDRAW.H` defines `DDBLT_WAIT` and `DDBLT_COLORFILL`.
- The source replaces `0x1000400` with their OR expression.
- Header action: both owned declarations of `color_log` now use the recovered names.

### `src/debuglog.cpp`

- Worker: `sa-c4d82854`.
- Worker commits:
  - `9c198c919984ccec10464adde8caca37c3a6ae82`
  - `5f9c95e151f80449d7f0b3226ed09b319df98176`
- Integration commits:
  - `eb24c1fab6c44e74b1644d908e46567e99baadc2`
  - `44fbbb960f69b4c4340ea88d89162eafb5339485`
- Review result: approved and integrated.
- Findings: the source restores all reliable PDB names. It preserves the original date-timestamp behavior.
- Header action: `include/debuglog.h` now uses the recovered declaration names.

### `src/dstring.cpp`

- Worker: `sa-61b5bdee`.
- Worker commits:
  - `986fab8535da9f9b3cb9546de4bd759e07545e62`
  - `89546f92c0145ed95cb9385d9fb2f81af86a40ed`
- Integration commits:
  - `465466b2f0e1601504677c0d727707635930f4ec`
  - `03adde481f73acae7008882065ba9f278d9f2e5f`
- Review result: approved and integrated.
- Findings: all 50 registry functions received PDB review.
- The source restores all reliable names. It gives three PDB-absent names snake_case spelling.
- Header action: `include/dstring.h` now uses the recovered declaration names.

### `src/file_stf.cpp`

- Worker: `sa-408a01fc`.
- Worker commits:
  - `c7d9d73085173f70013142b79122ee1d6324e306`
  - `119e835436c184d69a0dd85d9bb0851b3ba0ad2b`
  - `f53b8a83feb7dd6af4db1559428cf08f6e8855e4`
- Integration commits:
  - `9fb7bc774f6bdff60c5d245695850f0717c52fe6`
  - `fa0723a449c0f9bc3c22cbced31513dbb2a27064`
  - `fe9f1212adedefa031ec422117211e367f2793eb`
- Review result: approved and integrated.
- Findings: all 22 registry functions received PDB review. The source restores all reliable names and uses 1TBS.
- Evidence-tool incident: the worker started `generate_function_registry_inventory.py` after reading its help.
- The tool called an internal translation-unit validator and failed before output.
- The worker stopped this path and recorded the incident. No generated report or tracked change resulted.
- Header action: `include/file_stf.h` now uses the recovered declaration names.

### `src/mystring.cpp`

- Worker: `sa-d5163162`.
- Worker commits:
  - `ec9343cfb6a4d2874c1399789aba470a747aed9c`
  - `98ca0160b64133b83ea500455c68e2ffe2ecffbb`
  - `bb03357de68666c19a80a0514273cb34b0fc57fa`
- Integration commits:
  - `b7b4dacf438452ad12714141a486bb3eddc906cf`
  - `eaa480e8537625179a5336179d001b329f1fb2b6`
  - `296f21adce56f0fb0015f96670e22e6ab41ec01d`
- Review result: approved and integrated.
- Findings: all four functions received PDB review. The source restores all PDB parameter names.
- The `last_length` record reuses the `last` stack slot. Source lines and uses support the current declaration mapping.
- The source keeps its existing unsigned type.
- Header action: `include/mystring.h` now uses the recovered declaration names.

### `src/registry.cpp`

- Worker: `sa-063fbc1b`.
- Worker commits:
  - `a86a070d7aae53f33ef7eec82c3999e2bd36b48d`
  - `6c5f70ef3c2507aaff8b7dee0b2fc84af386dce8`
- Integration commits:
  - `17a7542a1f718cdcbfbcf6fa8a9acac4878e0d1f`
  - `ec50415e7cbcde3057d8871d4fab4ebde8d215ab`
- Review result: approved and integrated.
- Findings: all eight functions received PDB review. The source restores all reliable names and uses 1TBS.
- Constant evidence: pinned VC5 headers define `REG_DWORD` and `REG_SZ` with the replaced values.
- Header action: `include/registry.h` now uses the recovered declaration names.

## Header commit

Header changes are in integration commit:

- `6a52ca5eb3509b958a883c34523930f42ca04570`

The changes affect parameter spelling and formatting only. They do not change types, order, layout, or ABI symbols.

## Shared requests

Root should review a shared name for chat notification payload `0x17D5`.

Evidence:

- `TChat::AddChatMsg` posts `WM_USER` with `0x17D5` in `wParam`.
- `src/scr_mps.cpp` and `src/tribegam.cpp` dispatch that payload.

The integrated source keeps the value numeric. This request does not block delivery.

No resource-ID request is open. None of these modules performs a resource lookup.

## Final review status

I read every complete worker diff and report. I reviewed both correction commits.
I also reviewed the combined source and header diff.

All eight modules are integrated. The group remains reviewed but unvalidated.
Compilation, matching, audits, tests, and games were not run by the owner.
The final generated-output comparison remains deferred to the root validation stage.

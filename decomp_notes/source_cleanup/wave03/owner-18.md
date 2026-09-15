# Source-cleanup wave 03: owner 18

## Group identity

- Group: Panel and dialog support.
- Integration worktree: `build/source-cleanup-20260915/wave-worktrees/slot-154`.
- Branch: `cleanup/staging-20260915-154`.
- Common base: `76037279ee11dde077bb7d55aeb46b518b2bb27c`.
- Owner header commit: `bcd519d5c3a1fa7fdd40fd0296cfd50863209a41`.

This group owns eight source modules and eight paired headers. Root owns all other headers.
I reviewed each complete worker diff and report against the common base.
I integrated each approved worker commit without omitted hunks.

## Module ledger

### `src/pnl_dlg.cpp`

- Worker: `sa-e96a3151`.
- Worker commits:
  - `90a9880f2c52c1b040ea305637fd12cdf4bb126d`
  - `98d7ac8dbe9a7e080c4963ed3aeeb09d40d884aa`
- Integration commits:
  - `4184396e65074342ae3b6f7ef581eae6904efda0`
  - `b83641967a517106a36efdbaefa3956057143423`
- Report: `decomp_notes/source_cleanup/wave03/pnl_dlg.md`.
- Review found wrapped setup signatures after the first delivery.
- The same worker joined both signatures in the correction commit.
- The owner added the proved PDB parameter names to `include/pnl_dlg.h`.
- Status: integrated, reviewed, and unvalidated.

### `src/Pnl_inp.cpp`

- Worker: `sa-bef9f3b8`.
- Worker commits:
  - `d069ff193af752baa8ad403802b6567a553e1930`
  - `88ed053b2645eb5ff091c75a535efe18c4a33d91`
- Integration commits:
  - `0db668c9967106675d9afadf13f50bbdb7ff99e2`
  - `f77746f7a9d7eff37192d649c3cfd64e58842bd9`
- Report: `decomp_notes/source_cleanup/wave03/Pnl_inp.md`.
- Review accepted the PDB names and pinned SDK constants.
- The owner added the proved PDB parameter names to `include/Pnl_inp.h`.
- Status: integrated, reviewed, and unvalidated.

### `src/Pnl_msg.cpp`

- Worker: `sa-f072565a`.
- Worker commits:
  - `c3f611e101572c480c32fcfa0fdedce4a1529a63`
  - `2da0d4c9a80d17209628cf9fef3874f2d93f7159`
  - `6bc53df17c082c636e1d39de1db1bc4ec01d9e8b`
  - `3782edd7983db33d85ca4b11e8ccf03b2e3037cc`
- Integration commits:
  - `77bf6fd89ac5ad1f1244b7b973b3657128238cbc`
  - `5313961db2983001f2033379da40f38ce2c7268a`
  - `63ad3a5afc94714b4b864f3ffab574395ddd9445`
  - `e956f8dbee66b10d405557053478d4d2d040c963`
- Report: `decomp_notes/source_cleanup/wave03/Pnl_msg.md`.
- Review found two wrapped signatures after the first delivery.
- The same worker joined those signatures in the correction commit.
- The owner added source and inline PDB parameter names to `include/pnl_msg.h`.
- Status: integrated, reviewed, and unvalidated.

### `src/Pnl_pic.cpp`

- Worker: `sa-4dbb6fbb`.
- Worker commits:
  - `6e1861891331fb28e2b2d3f56b25f60be0d7fab3`
  - `58e1832a2133b6e883b2b2b80a4bfd8ca8dd815b`
- Integration commits:
  - `690b94daf8a5295013fd9c47edd1158d77e3b409`
  - `f4612e4bfb68e9be3533f47f5a12137f798abccf`
- Report: `decomp_notes/source_cleanup/wave03/Pnl_pic.md`.
- Review accepted the PDB names and the proved `Picture` enum value.
- The owner added the proved PDB parameter names to `include/pnl_pic.h`.
- Status: integrated, reviewed, and unvalidated.

### `src/Pnl_scr.cpp`

- Worker: `sa-31741076`.
- Worker commits:
  - `31745ac4bd55634ab517f7fc60fc6c04ec31e390`
  - `049bc298cc1a05d91b632ed1d53857fa822c0d4a`
  - `9adbaf86bf055dc1588872eed36a8eabe11e914f`
  - `41f51a5037d41bb6858eff65acb43a8ecffc6918`
- Integration commits:
  - `664625312df3a9fc64e40bc0e3bb407004f54cdf`
  - `fe3a8cd1fabef93acbc53f3df7d289af21e453f7`
  - `8fbee34e80071d63f4fd2f426c1c3847b0f26baf`
  - `2ad8d488d8eb248c0b175f462cd2cc2ebcf9db9d`
- Report: `decomp_notes/source_cleanup/wave03/Pnl_scr.md`.
- Review found wrapped setup signatures and calls after the first delivery.
- The same worker joined them and updated the report.
- The owner added the proved PDB parameter names to `include/Pnl_scr.h`.
- Status: integrated, reviewed, and unvalidated.

### `src/pnl_sld.cpp`

- Worker: `sa-cab07f4d`.
- The first worker run failed during startup with code 3.
- The same worker completed the task in its second run.
- Worker commits:
  - `512181c282bf2f14a1b70c26d64f30b9ad81ea75`
  - `3ba2f6164547f6eb58ac5255c147247c8a48c63f`
- Integration commits:
  - `3a5001e13adccfabe44bd9289ff2aede86249dcc`
  - `e4d40200bbc28d694b8033bd00903fbe3dd4a2db`
- Report: `decomp_notes/source_cleanup/wave03/pnl_sld.md`.
- Review accepted the recovered mixed-style PDB names.
- The owner added the proved PDB parameter names to `include/pnl_sld.h`.
- Status: integrated, reviewed, and unvalidated.

### `src/rdlg_lst.cpp`

- Worker: `sa-a2321b3e`.
- The first worker run failed during startup with code 3.
- The same worker completed the task in its second run.
- Worker commits:
  - `4f7c92401eb60c36aab1116e68cb016442566941`
  - `2d66902662145ce6f85014f0ed641ced0d1b188a`
- Integration commits:
  - `d95704781a7389371a0b626b0b8d539c15a754be`
  - `37eedf49e258f775193b21243fab8dbb0b0922b8`
- Report: `decomp_notes/source_cleanup/wave03/rdlg_lst.md`.
- Review found one wrapped signature and one short wrapped call.
- The same worker joined both in the correction commit.
- The owner added the proved PDB parameter names to `include/rdlg_lst.h`.
- Status: integrated, reviewed, and unvalidated.

### `src/tdlg_lst.cpp`

- Worker: `sa-a9d00121`.
- Worker commits:
  - `fd42d8b84e0caa87db497a15acf9d97dd90719d9`
  - `a2d4203ea0ee410ac5b26d537f56cc0f5fcd936a`
- Integration commits:
  - `5cee5049356f19877e61299bd08c0c82b5f59c17`
  - `4be109a172f76493fc3c17d52863e37f535e3baa`
- Report: `decomp_notes/source_cleanup/wave03/tdlg_lst.md`.
- Review accepted the recovered `item_list` local names.
- The owner added the proved constructor parameter name to `include/tdlg_lst.h`.
- Status: integrated, reviewed, and unvalidated.

## Header review

The owner changed only the eight assigned headers.
Each header change adds parameter names from the matching source PDB records.
The changes preserve all parameter types, order, access, virtual slots, layouts, and symbols.
The inline mouse handlers in `include/pnl_msg.h` keep their existing constant return bodies.

## Shared requests

No worker requested a new resource ID.
No request targets `include/resource_ids.h`, `include/game_globals.h`, or another owner.
No cross-group request remains open.

## Review and validation status

I reviewed the complete combined source and header diff.
I also used `git diff --check` during review.
Compilation, matching, audits, and tests were not run.
No compiler, build, audit, test, or game command ran in this cleanup group.
Generated code, data, relocations, and call targets remain unvalidated.
Final comparison must use the preserved pre-cleanup build.
That baseline includes its earlier differences from the original executable.

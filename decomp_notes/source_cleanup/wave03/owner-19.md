# Owner 19 tribe-panel cleanup ledger

## Scope

- Group branch: `cleanup/staging-20260915-163`
- Group base: `76037279ee11dde077bb7d55aeb46b518b2bb27c`
- Modules: `rpnl_tbx`, `rpnl_tim`, `spnl_obj`, `tpnl_btn`, `tpnl_inv`, `tpnl_obj`, `tpnl_pop`, and `tpnl_tim`
- Owner headers: the eight matching headers under `include/`
- Header commit: `effb2bff93f0ffe3e76fcb5b66388c543526fdf4`

All work is reviewed but unvalidated. The cleanup phase forbade compilation, builds, matching, audits, tests, and games.

## Worker deliveries and review

Each worker started from `76037279ee11dde077bb7d55aeb46b518b2bb27c`.
I read each complete base-to-head diff and each module report.
I also reviewed the combined source and header diff.

### `src/rpnl_tbx.cpp`

- Worker: `sa-a396abc6`
- Worker commits:
  - `5343cdd8279add2e0b1b97f08af65879b8f8f082`
  - `d228a750bed4db74386b392f6ed6b676997c0c49`
  - `21e4fbc33ddaad3b2813a253a05a0ec2715f977a`
  - `23c837a6b03c0aa6556d7688715b5ffdb29b8ede`
  - `855249c215a74193952b1e11be9842394fc6283a`
- Final worker head: `855249c215a74193952b1e11be9842394fc6283a`
- Integrated commits:
  - `3a945dc64732a7ada0c0c539d65fb41bc5792473`
  - `328aa00ef9ac43e7d75e37bf57772379676afd27`
  - `4c07d10a5818107e014209b3fedffd09668c6d43`
  - `85e57dc05a715d107058a9cdcddbf91d2a20cc66`
  - `db666e5db0c089442dc527c3830990955e4ca5a2`
- Review accepted the systematic PDB parameter and local recovery.
- Correction 1 applied complete 1TBS `else` placement, joined short signatures, and added the owner-header request.
- The first managed run failed during startup. The same worker completed the task in its second run.
- Root resource request: `0x232A` as proposed `IDS_SELECT_OBJECT_TITLE`.

### `src/rpnl_tim.cpp`

- Worker: `sa-efd78ef6`
- Worker commits:
  - `22a613f83286b1b916056e38c1722d4312215b43`
  - `5b9af7a3fd7b3a9c57959bb06a939776d1250036`
  - `3a348ac7acf01966fbf208085de2a299a9835c2c`
  - `41e98937b1a34566e60de3c5925889b31c6c1a4d`
- Final worker head: `41e98937b1a34566e60de3c5925889b31c6c1a4d`
- Integrated commits:
  - `7b7230217256c7274136b2d016fe05cc8e022b34`
  - `e4f04923aae3e288105662a969ff34738623dc01`
  - `defeea9397200e9486ad2ca2ab5b521b0a8d8995`
  - `bbb29ca27a6ac6e13f83943dcc1ecd175a951758`
- Review accepted PDB names and the pinned `OPAQUE` and `TRANSPARENT` macros.
- Correction 1 reverted names without PDB support, joined the constructor signature, added the header request, and recorded absolute DLL paths.
- The PDB calls `player_num` a `long`, but the current declaration is `int`. The source keeps its current type.
- Root resource request: `0x2C24` as proposed `IDS_COUNTDOWN_TIMER_FORMAT`.

### `src/spnl_obj.cpp`

- Worker: `sa-c984bcb1`
- Worker commits:
  - `c7ed04ebb817ac45a38e38824fd6bae556ba365a`
  - `2c9e4187fd19cb4116e2ef8d434767c61a5cd2bc`
  - `22b90e2e4a70a61177dae720cc84e85a0a0c6f49`
- Final worker head: `22b90e2e4a70a61177dae720cc84e85a0a0c6f49`
- Integrated commits:
  - `435f092182e2e1e23d4f8eb69fd7e9ce989d1c59`
  - `33f8766fc0fb7ab8ac752936eec0d96647ee254b`
  - `50d0f53bc8bf98bc3952939e6d949af69670441e`
- Review accepted all PDB parameter names and local `val_str`.
- Correction 1 joined short signatures and added the exact header request.
- Correction 2 removed a report contradiction about shared requests.
- The first managed run failed during startup. The same worker completed the task in its second run.
- No resource or root-owned header request remains.

### `src/tpnl_btn.cpp`

- Worker: `sa-187f0cb7`
- Worker commits:
  - `5032101aed8d8d3eb6a9fcc31315ba832e8858f8`
  - `e9444d8f99ba921b8e3ce8a66eb9f5d48e617176`
  - `3b72d82d2e2e5bb6a62fcb7fd63bdda58d04f6a1`
  - `4afa2affe8cec3f51c05b14d163a84725ec3eed5`
- Final worker head: `4afa2affe8cec3f51c05b14d163a84725ec3eed5`
- Integrated commits:
  - `f9389cbd197f85c48531ed653da43d40c3645f3f`
  - `f7c189c4de42f931ab22c76d158f9f6d247670f9`
  - `e45eb83c099d5ffd394ef50b2f4d3fb83cfa5cd3`
  - `7ef51a93cb4d4efd1d3c7b79276e44c453aa122a`
- Review accepted PDB names and the pinned `TRANSPARENT` macro.
- Correction 1 applied 1TBS to every function and added the owner-header request.
- No resource or root-owned header request remains.

### `src/tpnl_inv.cpp`

- Worker: `sa-fe6f5d6b`
- Worker commits:
  - `88cf53624dc23936c7f1ab13521a7132a9156591`
  - `91b4e6e133c9c37fbbaf88962e2d82e3860da096`
  - `00de7de822d6fce91bc35a502331c5ee088a33a6`
- Final worker head: `00de7de822d6fce91bc35a502331c5ee088a33a6`
- Integrated commits:
  - `92476ee70a4e0d494f2cc82e5877b6f03fccaa56`
  - `7c37d830ede6f9dc1d0b8a8cc7cdd75da2cff7a4`
  - `6104da43b11963e4ff186e268eb744fed0c4294c`
- Review accepted the systematic PDB recovery, 1TBS formatting, and pinned `TRANSPARENT` macro.
- Root resource requests: `0x1D4ED` through `0x1D4F0` as the four resource-help names listed below.

### `src/tpnl_obj.cpp`

- Worker: `sa-bcd3d68e`
- Worker commits:
  - `23febc8712ab7129c8f9453ffed450903344dd02`
  - `9c9c16796fe99a55b15f2db84ae28f96d7f0553f`
  - `715a5c0b4ec560b6fed25e19397fe297c4ca7249`
- Final worker head: `715a5c0b4ec560b6fed25e19397fe297c4ca7249`
- Integrated commits:
  - `558f1cd0d0027871146bcfaa67d4fef38dc524ab`
  - `2e1147ea0ca89ed0a67fd8ca5f3aeb12e5b51946`
  - `bbd137ee677322394b4e83b302d6adae54cc04ea`
- Review accepted PDB names and 1TBS formatting.
- Correction 1 joined `draw_item` and added the exact owner-header request.
- The old source-reunification packet is absent. The worker used the registry, function packets, PDB data, original listing, and preserved baseline record.
- Argument `0x69` to `get_string2` is not proved as a direct resource ID. It remains numeric with no mapping request.

### `src/tpnl_pop.cpp`

- Worker: `sa-0cb79fc1`
- Worker commits:
  - `0371f2d3521df1cc4c835dfc526b099694686695`
  - `80a38b86c4555a879dd34bc96b7076814c09c378`
  - `e697e601d9d3bbd2f4b8bafc81f34a579d822bd4`
  - `b36841f23343b314ca4cb400ff6b150260b9a817`
- Final worker head: `b36841f23343b314ca4cb400ff6b150260b9a817`
- Integrated commits:
  - `c0182a2f9d83ee2be4be3f4b90795898717f49b3`
  - `5f9b092da36dcb181dfbad5c8816df8b9ccb98dc`
  - `8fd9e1da9c5df115fcbf1be0f3a16c140fc1768c`
  - `6ab5ecec15286b33a67d90fb15b7fb8549d0f750`
- Review accepted PDB names and the pinned `TRANSPARENT`, `DT_CENTER`, and `DT_SINGLELINE` macros.
- Correction 1 added the header request and corrected the logical resource namespace.
- Correction 2 reverted local names that lacked PDB support.
- Root resource request: `0x2B2A` as proposed `IDS_POPULATION_PREFIX`.

### `src/tpnl_tim.cpp`

- Worker: `sa-2d355125`
- Worker commits:
  - `6bdf682f2ff757b1b785d07b170e3ce5c5be3ddc`
  - `8204cea2ef9e8be9c48db6ce280edcc77ad96748`
  - `8ceaa7c23be8885cd45a344c73a95fce8c77add8`
- Final worker head: `8ceaa7c23be8885cd45a344c73a95fce8c77add8`
- Integrated commits:
  - `e8ebf11c9c953cbe850ca8bc73835dadaa589a67`
  - `7d429fe731e749610bf779ebe8dfe5db08628924`
  - `4ad9a53c460155686111fc55aac8cb8ecfe99dea`
- Review accepted PDB names and the pinned `TRANSPARENT`, `DT_SINGLELINE`, and `DT_RIGHT` macros.
- Correction 1 added the owner-header request, absolute resource paths, and correct logical namespace wording.
- Root resource requests: `0x2C24` through `0x2C27` as the four year-format names listed below.

## Owner header change

Commit `effb2bff93f0ffe3e76fcb5b66388c543526fdf4` updates:

- `include/rpnl_tbx.h`
- `include/rpnl_tim.h`
- `include/spnl_obj.h`
- `include/tpnl_btn.h`
- `include/tpnl_inv.h`
- `include/tpnl_obj.h`
- `include/tpnl_pop.h`
- `include/tpnl_tim.h`

The commit adds procedure-scoped PDB parameter names only.
It changes no type, order, qualifier, virtual slot, layout, or symbol.

## Root-owned resource requests

The source keeps all requested IDs numeric until root reviews shared definitions.
Each module report records the DLL paths, full hashes, language, result status, lookup path, and name provenance.

- `0x232A`: proposed `IDS_SELECT_OBJECT_TITLE`
- `0x1D4ED`: proposed `IDS_HELP_FOOD`
- `0x1D4EE`: proposed `IDS_HELP_WOOD`
- `0x1D4EF`: proposed `IDS_HELP_GOLD`
- `0x1D4F0`: proposed `IDS_HELP_STONE`
- `0x2B2A`: proposed `IDS_POPULATION_PREFIX`
- `0x2C25`: proposed `IDS_WONDER_YEARS_FORMAT`
- `0x2C26`: proposed `IDS_ARTIFACTS_YEARS_FORMAT`
- `0x2C27`: proposed `IDS_RUINS_YEARS_FORMAT`

Two modules propose different names for `0x2C24`:

- `rpnl_tim` proposes `IDS_COUNTDOWN_TIMER_FORMAT` for a per-player countdown line.
- `tpnl_tim` proposes `IDS_YEARS_FORMAT` for the default year display.

Both uses resolve to `%d Years` through the same expansion-first and base-fallback lookup.
Root must select one shared name or retain the literal.

No other cross-group or root-owned header request remains.

## Review and validation status

The final combined diff contains only the eight sources, eight reports, eight owned headers, and this ledger.
`git diff --check` passed before this ledger commit.
I reviewed the complete source and header changes against the common base.

Compilation, matching checks, audits, tests, builds, and games were not run.
All integrated work remains reviewed but unvalidated.
Final generated-output comparison must use the preserved pre-cleanup build and retain its earlier original-executable differences.

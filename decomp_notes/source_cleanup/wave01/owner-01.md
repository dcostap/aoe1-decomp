# Owner 01 action cleanup ledger

## Scope

- Group branch: `cleanup/staging-20260915-01`
- Group base: `ad338a7faf75ffdfff8fec846133b4aa8da3fa44`
- Initial reviewed group head: `555d35cda101f4a005b1a24e6c8ca241e09e5f0a`
- Modules: `act_atak`, `act_bird`, `act_entr`, `act_expl`, `act_gath`, `act_make`, `act_misl`, and `act_tran`.
- Owner headers: the eight matching `include/act_*.h` files listed below.

All work is reviewed but unvalidated. The wave forbade compilation, matching, audits, tests, builds, and games.

## Worker deliveries and review

Each worker started from `ad338a7faf75ffdfff8fec846133b4aa8da3fa44`.
I inspected each complete base-to-head diff and each durable module report.

### `src/act_atak.cpp`

- Worker: `sa-b68feb67`
- Worker head: `dd6ab43e7868266edc648bf324a3ab50b344ff2e`
- Report: `decomp_notes/source_cleanup/wave01/act_atak.md`
- Review accepted all PDB parameter and local names.
- Review accepted 1TBS formatting and preserved expressions, calls, scopes, types, and order.
- Round 1 joined short method signatures.
- Round 1 also corrected the reused-slot scope statement.
- Round 2 corrected inaccurate report text about function-body changes and source commits.
- The owner added the omitted PDB name `rangeState` to the private header declaration.
- No resource or root-owned header request remains.

Integrated commits:

- `dab87bc6b97e1a9d0fd461fc95dd4fcfaa71f60d`
- `1e9f8cd0fc0b4e70e656ff8e12c16198c65a718a`
- `cdaaeb7fc050f00a6d94612c5d6f57fa12d2873c`
- `7222bb1085f8f9811e0268d150ebcac901640e0f`
- `518bc3b7c77f1bc54cfa59da1b3b1c2b813994c5`

### `src/act_bird.cpp`

- Worker: `sa-eea38cab`
- Worker head: `736d2052ce932cf1494d17b851bb09f4717d720c`
- Report: `decomp_notes/source_cleanup/wave01/act_bird.md`
- Review accepted all PDB parameter names.
- Review found no forced local mapping, constant change, or resource use.
- One correction joined the task-constructor signature and report declaration.
- No resource or root-owned header request remains.

Integrated commits:

- `df4474c616a6da40b94cec5189b03c9711356019`
- `f3ad67b9799dc7702c88afee78c3e7db723458bb`
- `d1957c146e5059505f291bc72e34f474703de720`
- `e19638fdba7562a42955c98cb50b4235da99e737`

### `src/act_entr.cpp`

- Worker: `sa-d4732822`
- Worker head: `3ac62a7a768e601af85dbe406a66e8b7289f7247`
- Report: `decomp_notes/source_cleanup/wave01/act_entr.md`
- Review accepted the PDB names, including mixed-style local `rVal`.
- Review found no type, declaration, control-flow, or call change.
- One correction joined the three-parameter constructor signature and report declaration.
- No resource or root-owned header request remains.

Integrated commits:

- `c6720bfb631695ce865c301f6259e625082d3da0`
- `fca57c5aab5440d7bd390d9012b688be3e31af82`
- `fbde0e478f83f6efa05e28996b6dc2b0e39a8228`
- `9aa2d2176eb2d5d08f4ce1926e76e7a1da7e56b4`

### `src/act_expl.cpp`

- Worker: `sa-c69793a1`
- Worker head: `59357a7e79e3cde633d7fcebb3f197c10fd04454`
- Report: `decomp_notes/source_cleanup/wave01/act_expl.md`
- Review accepted all PDB parameter names.
- Review accepted inferred locals `obj_id`, `move_sprite`, and `move_action` as cleanup names.
- One correction joined the task constructor and `work` signatures.
- No constant, resource, type, layout, or root-owned header change exists.

Integrated commits:

- `f2f985c4d2454dc928accc141d230d27ecbd7ae9`
- `f36648c8cd98c6071504c7c13d8440189c0cbed1`
- `c751e0f03bd617ef53064748890d76cb60183e9d`
- `a1260732675de17af529ce2afda8a2de16be7772`

### `src/act_gath.cpp`

- Worker: `sa-6168d9f7`
- Worker head: `357811c50927923ff9566310b561a2419a63df03`
- Report: `decomp_notes/source_cleanup/wave01/act_gath.md`
- Review accepted all PDB parameter names and the local `attr` mapping.
- The worker did not force the later reused local to `attr`.
- One correction joined four short signatures.
- That correction added the omitted `set_state` header request.
- No resource or root-owned header request remains.

Integrated commits:

- `26620117d05853e94402d944e0d0d0bd6ff9fc43`
- `bd0d1e886fd0bedd08d5f5e38884a819b4957ed1`
- `de0208632dd1f2dc77313172f5bbf6f7e4e89b72`
- `092b55a09d26f7e44972d146ca1b53bf9c395b6c`

### `src/act_make.cpp`

- Worker: `sa-aec84d47`
- Worker head: `8c5de2e4a5b13dac88d5ad24da7bc6a8c1831f41`
- Report: `decomp_notes/source_cleanup/wave01/act_make.md`
- Review accepted all PDB parameters and local `pre_attribute`.
- Review found no constant or resource substitution.
- One correction applied 1TBS and joined the task-constructor signature.
- Existing structural drift remains outside this cleanup scope.
- No root-owned header request remains.

Integrated commits:

- `76fa24c74850a3aba38949528fc9fde6e14a4d77`
- `455521dfdf79e61ce8e4accbde71e3f528f9d289`
- `00c329af271cf3fefc87824f61638237ba20a676`
- `0d3f71a7290e2d04abd303fe6f8ba9f923951ac2`

### `src/act_misl.cpp`

- Worker: `sa-f319866b`
- Worker head: `b45d214f9021638a09c154a1ececceb16264199b`
- Report: `decomp_notes/source_cleanup/wave01/act_misl.md`
- Review accepted all reliable PDB parameter and local mappings.
- Review accepted the unresolved reused stack home for five target-speed records.
- The source keeps one existing `target_speed` declaration for those lifetimes.
- One correction joined the target-constructor signature and report declaration.
- No resource or root-owned header request remains.

Integrated commits:

- `bc06d1f21e3dc9d0e4b12ce1b4a2fbb391b4cd87`
- `f47a14e09ba2c7b4a36aadf1d444a3cb24ac5966`
- `a47d779d664c2f770d0bff981a095a14aca4566d`
- `48c03d6888ddb0f0f8bc3f06f764f718d175e5ae`

### `src/act_tran.cpp`

- Worker: `sa-66fd0638`
- Worker head: `c08060733eeb7387dba718971a64f5dfc15160d7`
- Report: `decomp_notes/source_cleanup/wave01/act_tran.md`
- Review accepted the PDB names and retained inferred local names.
- Review found no constant, resource, type, layout, or call change.
- One correction joined the task constructor, `move_to`, and `work` signatures.
- No root-owned header request remains.

Integrated commits:

- `c341fd2671ccb3780203649ba366f46a90d88878`
- `55e686666ac3789930aedc701fe530d0bf50224a`
- `c4e479038a7e99b7d56780d993480417a2c62324`
- `cd3943c6f4791f025077a41c6c60c9979613f420`

## Owner header change

Commit `555d35cda101f4a005b1a24e6c8ca241e09e5f0a` updates these owner-controlled headers:

- `include/act_atak.h`
- `include/act_bird.h`
- `include/act_entr.h`
- `include/act_expl.h`
- `include/act_gath.h`
- `include/act_make.h`
- `include/act_misl.h`
- `include/act_tran.h`

The commit adds PDB-proven parameter names only. It changes no parameter type, order, virtual slot, layout, or symbol.

`include/act_atak.h` also names `ready_to_attack` parameter `rangeState` from its PDB record.
No source worker listed this private declaration in its header example.

## Cross-group and root-owned requests

There are no pending cross-group requests.
There are no requested changes to `include/action.h`, `include/resource_ids.h`, or another root-owned header.
There are no resource-ID mappings in this group.

## Validation status

Compilation, matching checks, audits, tests, builds, and games were not run.
All integrated modules and headers remain reviewed but unvalidated.
Final validation is deferred to the root stage.

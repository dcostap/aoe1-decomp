# Owner 05: Tribe actions

## Scope

Owner 05 integrated these modules:

- `src/tact_art.cpp` and `include/tact_art.h`
- `src/tact_bld.cpp` and `include/tact_bld.h`
- `src/tact_cnv.cpp` and `include/tact_cnv.h`
- `src/tact_dar.cpp` and `include/tact_dar.h`
- `src/tact_hea.cpp` and `include/tact_hea.h`
- `src/tact_hnt.cpp` and `include/tact_hnt.h`
- `src/tact_mob.cpp` and `include/tact_mob.h`
- `src/tact_rep.cpp` and `include/tact_rep.h`

The common base was `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`.
The integration branch was `cleanup/staging-20260915-37`.

Owner 05 changed only the assigned headers and this ledger.
Workers changed only their assigned source and module report.

## Worker and integration ledger

### `tact_art`

- Worker: `sa-2101f88c`, run `sa-2101f88c-r1`, slot 38.
- Worker base: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`.
- Worker source commit: `090e0786883cfbe4be0aee489a8b5e87dde3a9a2`.
- Worker final head: `6b01a8587e6fa0c46048417b5d49413a3fd6f904`.
- Integrated source commit: `8fada3e1afaf6a3cdecf1a13be4394817d5f4dd2`.
- Integrated report commit: `89ae89c7f17082b231acecee69e60db1952a0571`.
- Result: approved and integrated.

Recovered parameters were `infile`, `obj_in`, `task_in`, `target_obj_in`,
`first_time`, `new_state`, `x`, `y`, and `z`.
The `check_ownership` horizontal bound now uses recovered local name `x1`.
The existing names `map`, `player_num`, `player_list`, and `x0` matched the PDB.

The PDB has no names for the vertical bounds or several optimized locals.
The worker left those mappings unchanged.

### `tact_bld`

- Worker: `sa-ed39fbc1`, run `sa-ed39fbc1-r1`, slot 39.
- Worker base: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`.
- Worker source commit: `8043abb5cd11a955a90d4d6fcb66764ff22b0447`.
- Worker final head: `535c519d949fb977b11a034753e75a8fc16aaca5`.
- Integrated source commit: `584aa69dbfa0e8217f130cfa0a185e9540548833`.
- Integrated report commit: `2aea7f559bd033a06aa544f49dfcbb304d5c13a7`.
- Result: approved and integrated.

Recovered parameters were `infile`, `obj_in`, `task_in`, `target_obj_in`,
`first_time`, `new_state`, `x`, `y`, and `z`.
The existing `work` local matched the PDB.

The PDB has no source-local records for `move_to`, `target_owner`, or `action`.
The worker left those existing descriptive names unchanged.

### `tact_cnv`

- Worker: `sa-eae56238`, run `sa-eae56238-r1`, slot 40.
- Worker base: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`.
- Worker source commit: `caa1e8769bd0dea848c574d9f1953d83157a1cc1`.
- Worker final head: `5c57e486e72cb042de9cda6c8c75a9259493ba5b`.
- Integrated source commit: `771d0cd54cb65d65c6dc83e75e8cf61daf8aa142`.
- Integrated report commit: `dd6988d203b1554ada08754ff5cc921b981fe6df`.
- Result: approved and integrated.

Recovered parameters were `infile`, `obj_in`, `task_in`, `target_obj_in`,
`outfile`, `first_time`, `new_state`, `x`, `y`, and `z`.

The PDB has no procedure-scoped local records for this module.
The worker left all existing local mappings unchanged.

### `tact_dar`

- Worker: `sa-1e974553`, run `sa-1e974553-r1`, slot 41.
- Worker base: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`.
- Worker source commit: `38d2d77200e0af6a40aa21698a6f5cf89654bb55`.
- Worker final head: `7ff3dbb54e27970fdbe0349fbb2518628f48cee3`.
- Integrated source commit: `78fba0f675efa7f2848d4f9e4205df39c920bd4e`.
- Integrated report commit: `0472bdf3f7a7acef0b49e91e06bfd90ca146319f`.
- Result: approved and integrated.

Recovered parameters were `infile`, `obj_in`, `task_in`, `target_obj_in`,
`outfile`, `first_time`, `new_state`, `x`, `y`, and `z`.
The inner horizontal loop now uses recovered local name `x1`.
The existing local names `map` and `x0` matched the PDB.

The PDB has no names for `size`, `timer`, or the remaining map-bound locals.
The worker left those mappings unchanged.

### `tact_hea`

- Worker: `sa-897d5059`, run `sa-897d5059-r1`, slot 42.
- Worker base: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`.
- Worker source commit: `1f308253f8f735dbc8a533d47d50aba9e4837db4`.
- Worker final head: `40d0fd7754102961cb6f4f422ce37e7350616001`.
- Integrated source commit: `750910297818ec4ab8f8e46b57c54a56586aa161`.
- Integrated report commit: `45afcadafa33c92a474f1f296d0ac707f6dc6938`.
- Result: approved and integrated.

Recovered parameters were `infile`, `obj_in`, `task_in`, `target_obj_in`,
`first_time`, `new_state`, `x`, `y`, and `z`.
The existing local `work` matched the PDB.

The PDB has no names for `kind`, `move_to`, `distance`, `result`, or local `state`.
The worker left those mappings unchanged.

### `tact_hnt`

- Worker: `sa-9f5fd08a`, run `sa-9f5fd08a-r1`, slot 43.
- Worker base: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`.
- Worker source commit: `e7f7fb4623c53775d1678744e07bfd203e0b537e`.
- Worker final head: `f02b2283490dcf0a64b3d58aa76188bdbb016088`.
- Integrated source commit: `7acc760779d834a689e804a07a7bc8fc9c22940b`.
- Integrated report commit: `0319424a470611e18e4ad9daf16877103eeeade6`.
- Result: approved and integrated.

Recovered parameters were `infile`, `obj_in`, `task_in`, `target_obj_in`,
`outfile`, `first_time`, `new_state`, `x`, `y`, and `z`.
One state-7 local now uses recovered name `attr`.
The existing locals `give_amount`, `modifier`, and `max_hold` matched the PDB.

The PDB maps `attr` and `max_hold` to one reused stack home.
The worker did not apply `attr` to a later uncertain lifetime.
Other unrecorded local names remain unchanged.

### `tact_mob`

- Worker: `sa-adf062af`, runs `sa-adf062af-r1` and `sa-adf062af-r2`, slot 44.
- Worker base: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`.
- Worker source commit: `0b7483156fe27d2b1cd99563ed4f9683d981e7c2`.
- Worker initial report commit: `32b47ecab6a9c2cd5a536ac93825f12c00dae410`.
- Worker correction commit: `1b504117b115d37b2b96a9e384df681b78a88684`.
- Worker final head: `2558177c28d5e0e903e06997455dd00c7f3a62ce`.
- Integrated source commit: `9771f665e1affd7e5195d843028a2191ccd53945`.
- Integrated initial report commit: `f7b8026f1107d42368a9ba8be8919c6c684cfce4`.
- Integrated correction commit: `7eec1a07377a4ac1f76554531c877d82a2fa0889`.
- Integrated report correction: `00c83891897694c775feecfbb24874520f982b11`.
- Result: corrected, approved, and integrated.

Recovered parameters were `infile`, `obj_in`, `id`, `uniqueID`, `paid`,
`outfile`, `first_time`, `new_state`, `rObj`, `progress`, `name`, and `name_size`.
Recovered placement locals were `index`, `radius_x`, `radius_y`, `radius_2x`, and `radius_2y`.
The existing local `newObject` matched the PDB.

The PDB has no names for the other placement, payment, and information locals.
The worker left those mappings unchanged.

The first review found two constructor braces outside 1TBS style.
The same worker moved both braces and updated the report.
The second review found no remaining function-definition brace issue.

### `tact_rep`

- Worker: `sa-caa608b2`, run `sa-caa608b2-r1`, slot 45.
- Worker base: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`.
- Worker source commit: `57b1f2e3fc4b104f46ab826744974e5d4aae5929`.
- Worker final head: `8d02b5c3f7a1a807bd3591322ccdac200fe1d9e3`.
- Integrated source commit: `2c91ecc91b104e83feaff65b0f8c9c18b2f84095`.
- Integrated report commit: `dfe61445d354691fe5e88d79d5e185bf3177d825`.
- Result: approved and integrated.

Recovered parameters were `infile`, `obj_in`, `do_setup`, `task_in`,
`target_obj_in`, `outfile`, `first_time`, `new_state`, `x`, `y`, and `z`.
The existing `meet_target` locals `start`, `rVal`, and `dest` matched the PDB.

The PDB has no local records for `result`, `action`, or the update temporaries.
The worker left those mappings unchanged.

## Header integration

Owner 05 added PDB-proven parameter names to all eight assigned headers.
The declaration types, order, access, virtual slots, and layouts remain unchanged.

Header commit: `02405f2c79d9fc55b9c19d236fe40d9adebfe3cd`.

The header edits use the same recovered spellings as the source definitions.
They include mixed-case names such as `uniqueID` and `rObj`.
No header edit adds a declaration, object, enum, macro, or layout field.

## Review findings

I read every complete worker diff and module report against the common base.
I checked scope, PDB coverage, spelling, types, scope, calls, casts, literals, and statement order.
I also checked comment density, 1TBS formatting, header ownership, and shared requests.

Seven module deliveries passed the first source review.
`tact_mob` needed one style correction.
The same worker made that correction in a separate retained commit.

I reviewed the combined source and header diff after integration.
The changes recover names, adjust presentation, and remove two stale `tact_bld` comments.
No reviewed diff adds a helper, structural rewrite, layout change, or assembly.

## Resource and shared requests

No assigned module performs a direct string-resource lookup.
No worker requested a resource ID or a new resource macro.
No request targets `include/resource_ids.h`.
No request targets `include/game_globals.h`.
No cross-group declaration request remains open.

## Unresolved evidence

Some optimized locals have no procedure-scoped PDB names.
Those names remain unchanged and are documented in each module report.
`tact_hnt` has a reused stack home for `attr` and `max_hold`.
The source keeps the uncertain later lifetime unchanged.

Existing numeric states, notifications, object groups, attributes, and sentinels remain literal.
No shared declaration proved equal meaning and effective type for these uses.

The original executable remains the behavior oracle.
This cleanup does not prove generated-code or program-data equality.

## Validation status

I used evidence inspection and complete Git diff review only.
Compilation, matching, audits, tests, and games were not run.
All integrated results remain reviewed but unvalidated.

# Wave 02 owner 08 integration ledger

## Scope

Owner 08 integrated these master-object modules:

- `src/m_ac_obj.cpp` and `include/m_ac_obj.h`
- `src/m_an_obj.cpp` and `include/m_an_obj.h`
- `src/m_co_obj.cpp` and `include/m_co_obj.h`
- `src/m_dg_obj.cpp` and `include/m_dg_obj.h`
- `src/m_mi_obj.cpp` and `include/m_mi_obj.h`
- `src/m_mo_obj.cpp` and `include/m_mo_obj.h`
- `src/m_s_obj.cpp` and `include/m_s_obj.h`
- `src/tm_b_obj.cpp` and `include/tm_b_obj.h`

The common base is `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`.
The integration branch is `cleanup/staging-20260915-64`.

## Worker deliveries

| Module | Worker | Worker head | Worker commits | Integrated commits |
| --- | --- | --- | --- | --- |
| `m_ac_obj` | `sa-689041a8` | `515ac3f53a815d1b1ba56e1e324ff9382725bff9` | `7631026304e61b4f20c0d67a89893d9fd95adfdb`; `515ac3f53a815d1b1ba56e1e324ff9382725bff9` | `32d9c49b82c9cb096e3fb6c2b3fdcb1d65d6ec5c`; `ddf4f3c84cc170151f21718338d0047e49c1d4e7` |
| `m_an_obj` | `sa-1c4126ce` | `e4c7792626afa357aa1a5791bccac1f1997e4272` | `0ec83908f65aa3af975899ccd7dc4f917e6a6253`; `e4c7792626afa357aa1a5791bccac1f1997e4272` | `65352068cbb7d4e36d7fb91d4440b9a9cd0d94d3`; `139f51556bac8bba503ca75fe215ce20f94cda99` |
| `m_co_obj` | `sa-d5845ee3` | `301f2ebf01189f348fd733f7df56fa906eb36faa` | `630a5f20f737a32d1eabce6c1cc1a65a7df64990`; `301f2ebf01189f348fd733f7df56fa906eb36faa` | `2c831ad395d51fb8bd873ad642523879c97022c3`; `40414d1760660a9dc87ae40b78f68ee34dd558f1` |
| `m_dg_obj` | `sa-7b185a64` | `6ccafb7e1097282fd133bc7ceb38b32b9c423d0a` | `f1a3e7fad9bb22b5d8c5ad46bfc635d67f2fbc57`; `6ccafb7e1097282fd133bc7ceb38b32b9c423d0a` | `17711e70cbf9500b6d76c821648b170d8fc04d4a`; `083cbea55ed1a38ac2586a19f985799f3dadda59` |
| `m_mi_obj` | `sa-5e8909e2` | `d41454b7dc0e0444de3560976558a3ea00a4e093` | `b2861ab787d90ff506f335358ef02d97419cd31d`; `e9780e0483b7dbc926e1fa9cd8b33cc6fbe53331`; `407a300caf49d7a368cbe52bbd13d8e77faac650`; `d41454b7dc0e0444de3560976558a3ea00a4e093` | `a15479f755bf6035940261e8f91339c0c802b70e`; `4683ebbe19c4e13c99c87733ac4e8353389aed9b`; `3e0f6a879ade6e789691057f10321bf1f3943152`; `983d23f37a6210b997961eb2c1222ebeab0b2060` |
| `m_mo_obj` | `sa-2645b267` | `76bb1f602b6d3b04b60e78ee650613da5d8a5b96` | `d629aef2d27fc767934b4ec04acdc05ba50cf962`; `76bb1f602b6d3b04b60e78ee650613da5d8a5b96` | `1a3dca733d168fc69500d41fd6e1152eeb2fb305`; `94b6ec154dc008960ec6ec8c0f70d40804773620` |
| `m_s_obj` | `sa-a3b39f97` | `23b2f3cfaed4f0ea61b204661d4ebb06c034a4ed` | `09b834b0424fafd7c2ff0a9075379b8d1c205592`; `23b2f3cfaed4f0ea61b204661d4ebb06c034a4ed` | `1154c355e112b24cb18b79111ab16c63eec0a486`; `171bbbf9cd1cc9e983e2c2a5ed47d2172acf1866` |
| `tm_b_obj` | `sa-4544fbb9` | `0a820eeedc8f9db20a5dcf1a848fd14372a37dd9` | `bfeeaa062d35c6d0388e8c6d279a221779694253`; `37c424abd265cd7155995e5d0f8b14fd663b0da2`; `b8759588ca43b4751cd656f4ed179c40c8f518e0`; `0a820eeedc8f9db20a5dcf1a848fd14372a37dd9` | `efebb7910eee1af78db90e647f01c5152e580c79`; `fe241d7d56486f7de02c433b48db532536936527`; `2678bc12ebf2443a956ee96fea9d2e8e85544574`; `52612615b3157997e4f9a73067fc1fdad0920b7c` |

Each worker started at the common base. Each worker changed only its source and module report.

## Header integration

Commit `63a33d662a0bbc90dbe0a7dccf155554049bfcad` updates all eight owned headers.
It adds PDB parameter names without type, order, layout, or symbol changes.

The headers now use recovered names such as `other_object`, `infile`, `in_id`, and `do_setup`.
They also use `owner`, `amount`, `flag`, `outfile`, and the recorded draw parameters.
`m_s_obj.h` keeps the original mixed-case name `obstructionObject`.
`tm_b_obj.h` keeps the original spelling `uID`.

This commit fulfills all worker header requests. No worker needed a header change before source cleanup.

## Review findings

I read every complete worker diff and module report.
I checked scope, PDB coverage, types, casts, declarations, call order, literals, and comments.
I also checked each worker tree was clean after delivery.

The accepted changes recover PDB names and apply permitted 1TBS formatting.
They keep explicit casts, `this->` use, declaration order, evaluation order, and existing bugs.
No worker added a helper, layout change, assembly, resource symbol, or structural rewrite.

The `tm_b_obj` first delivery renamed two locals from reused PDB slots.
Those names conflicted with the proved sprite and sound roles.
I returned the work to `sa-4544fbb9`.
The correction kept `sprite_id` and `sound_id` in `setup(int, ...)`.
Commits `b8759588ca43b4751cd656f4ed179c40c8f518e0` and `0a820eeedc8f9db20a5dcf1a848fd14372a37dd9` record the correction.
The rejected names remain visible in the earlier worker and integration commits.

The combined header and source review found no parameter-name collision or macro effect.
All source reports remain available under `decomp_notes/source_cleanup/wave02/`.

## Recovered mappings

The module reports contain the complete per-function mappings and PDB records.
The main mapping groups are:

- Constructors and setup methods use `other_object`, `infile`, `in_id`, and `do_setup`.
- Factory methods use `owner`, `x`, `y`, and `z`.
- Modifier methods use `amount` and `flag`.
- Save methods use `outfile` and proved PDB local names.
- Draw methods use `render_area`, `player_color`, `facet`, `frame`, `draw_frame`, and `frame_color`.
- Alignment methods use `col`, `row`, `world`, and `center_flag`.
- Combat damage methods use `attacker` and the proved local `tot_armor` where present.
- `m_s_obj` restores placement names, coordinate names, and saved-field names from its PDB records.

These are recovered original names unless a module report states that an existing descriptive name remains inferred.
No new inferred cleanup name was added in this group.

## Unresolved evidence

- `tm_b_obj` VA `0050E250` has reused PDB slots named `sound_num` and `sprite_num`.
  Their names conflict with the proved local roles. The source keeps `sprite_id` and `sound_id`.
- `m_s_obj` VA `00452B00` has a `temp_damage_sprite_num` record with a conflicting type.
  The current `attribute_count` declaration remains unchanged.
- `m_s_obj` VA `00453C40` has overlapping records for `rz2`, `ry2`, `rx2`, `tx1`, `tx2`, `ty1`, `ty2`, `rx`, `ry`, and `req_x1`.
  The current storage mappings remain unchanged.
- Several modules contain existing descriptive locals without scoped PDB records.
  Their module reports list them. The cleanup did not claim those names as recovered originals.

## Shared and resource requests

No module uses a resource lookup. No resource-ID definition is requested.
No change is requested from root for `include/resource_ids.h`, `include/game_globals.h`, or another shared header.

## Validation status

I reviewed the complete combined Git diff and ran `git diff --check`.
Compilation, matching, audits, builds, tests, and games were not run.
All integrated results are reviewed but unvalidated.

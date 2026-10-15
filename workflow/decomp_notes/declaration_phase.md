# VC5 declaration-phase padding

VC5 breaks some code-generation ties using the number of identifiers declared earlier in the translation unit.
The affected ties include commutative operand load order, SIB base and index order, and some register choices.
The rules for using padding are in `AGENTS.md` under "Declaration-phase padding". The lesson is in
`workflow/vc5_lessons.md`.

## How the counts were chosen

For each module, a sweep inserted N `struct vc5_phase_<i>;` lines after the last top-level include,
for N = 0 up to the limit in the table. It then audited the whole translation unit at each N.
The chosen N is the smallest count that gains exact functions and loses none.
The sweep reports are under `build/match-easy/tusweep/<group>/n<NN>/`. They are local only, so the
per-module results are recorded here.

## Applied modules (2026-10-15)

| Module | N | Swept | Newly exact | Notes |
| --- | --- | --- | --- | --- |
| `src/dstring.cpp` | 15 | 0–31 | `00447420` uppercase, `004474E0` lowercase | Exact for every N ≥ 15; nothing lost. |
| `src/player.cpp` | 5 | 0–23 | `0046FF90` create_checksum | Window 5–20. `004705A0` set_color_table breaks at N ≥ 21. |
| `src/rmm_dbct.cpp` | 2 | 0–23 | `00484470` add_elevation_module | Window 2–3 and 18–19. |
| `src/rmm_terr.cpp` | 4 | 0–15 | `00488E60` count_map_tiles | Window 4–11 mod 16. |
| `src/airesitm.cpp` | 16 | 0–31 | `00412240` sortLarge | Exact `operator==` and `operator!=` also have periodic windows; N = 16 keeps all three. |
| `src/Shape.cpp` | 19 | 0–25 | `004B98E0` shape_color_trans_unclipped, `004BAAF0` shape_mirror_shadow_unclipped | `004B99F0` and `004BA9E0` must stay exact; N = 19 keeps both. |
| `src/vw_main.cpp` | 3 | 0–29 | `0053F6F0` draw | `0053E340` and `00540010` stay exact at N = 3. |
| `src/Command.cpp` | 20 | 0–31 | `00435020`, `00435060`, `004350E0` group commands | `004350A0` breaks at N ≥ 26; `004351B0` breaks at 15 and 31. |
| `src/spanlist.cpp` | 12 | 0–31 | `004BE4B0` DeleteShape | Exact for every N ≥ 12. |
| `src/taitacmd.cpp` | 14 | 0–17 | `004FB710` taskResearch | Exact only at 14 and 16. |
| `src/victory.cpp` | 12 | 0–31 | `00533410` handle_points_high_attribute_amount | `00533120` needs N ≥ 26, but exact `00532CC0` breaks at N ≥ 23, so `00533120` stays drift. |
| `src/Pnl_scbr.cpp` | 17 | 0–29 | `0047B970` draw_button_pic | Window 17–28. |

## Combined audit

`python tools/audit_translation_unit_functions.py` with `--affected-by` for all twelve sources compiled 640 rows
into `build/match-easy/audit-phase/`. Compared with the full baseline `build/match-easy/audit-base/`, the audit
found 16 newly exact functions and no lost exact functions. Four non-exact rows changed their diff size:

- `00483A20` add_land_module: 1793 to 1780 bytes;
- `004B9140` shape_check: 590 to 643 bytes;
- `004BB280` shape_mirror_shadow_clipped: 823 to 819 bytes;
- `004BB770` shape_dithered_unclipped: 327 to 325 bytes.

Their behavior reviews are unchanged, because padding changes no function body.

## Not yet swept

Only the 60 smallest non-exact edit diffs were scanned per function. `build/match-easy/candidates2.txt`
lists 87 more with edit diffs of 30 bytes or less. A module's padding can also sit lower in the file, before
the first function that needs it, to protect earlier exact functions. That option has not been tried yet.

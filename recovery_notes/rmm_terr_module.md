# rmm_terr.cpp natural module

- PDB source: `C:\\msdev\\work\\age1_x1\\rmm_terr.cpp`.
- Source owner: `src/rmm_terr.cpp`.
- Generator header: `include/rmm_terrain_generator.h`.
- Record header: `include/rmm_terrain_info.h`.
- RMM base header: `include/rmm_base.h`.
- Map and zone providers: `include/map.h` and `include/zone_map.h`.
- Flags: `config/flags/default.rsp`.

## Ownership

The source owns all eleven normal PDB bodies in source order:

1. `004888E0` constructor
2. `00488920` `generate`
3. `004889D0` `water`
4. `004889F0` `check_borders`
5. `00488B90` `check_terrain`
6. `00488D50` `generate_modifiers`
7. `00488E40` `fig_chance`
8. `00488E60` `count_map_tiles`
9. `00488EA0` `link_stack_randomly`
10. `00488F90` `remove_area_from_lists`
11. `00489030` `base_terrain_generate`

The old prefix source, copied RMM base, copied generator context, and old
`rmm_terr.h` provider are removed. The source now uses the canonical random-map
base, typed map rows, typed tiles, typed zone classes, and typed terrain fields.
It keeps the shipped coordinate order and helper call order.

## Validation

A fresh grouped candidate build compiled the complete module. The retained
owners `004888E0`, `00488920`, `004889D0`, `004889F0`, `00488D50`, `00488E40`,
`00488EA0`, and `00489030` each report `MATCH` and `0.0000%`. Their owner
symbols, boundaries, relocations, and direct targets also match.

`00488F90` is scratch. Its typed stack-row form has the original boundary and
call target, but VC5 reorders four independent address instructions. It reports
nine differing bytes. The source keeps the natural typed form instead of a raw
byte overlay.

`00488B90` remains scratch. Its reviewed clipped scans and terrain predicate
order are unchanged. Its current rebuilt span differs by 295 bytes.

`00488E60` remains scratch. Its typed tile scan is unchanged in behavior. Its
current rebuilt span differs by two bytes.

The final candidate report is under `build/candidate_tus/rmm_terr_natural_final`.

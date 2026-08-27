# rmm_shal.cpp source-reunification note

## Context

- PDB source module: `C:\\msdev\\work\\age1_x1\\rmm_shal.cpp`.
- The module owns three normal functions in PDB source order.
- The source-line bands are 34-38, 42-102, and 106-245.
- The address sequence is `00487010`, `00487050`, and `00487200`.
- All three functions belong to `RGE_RMM_Shallows_Generator`.
- The constructor calls the random-map base constructor. `generate` calls
  `clear_stack` and `make_tribe_connections`. These are direct context anchors.
- `00487200` calls the canonical random-map stack and path helpers.

## Natural source

- `src/rmm_shal.cpp` owns all three handwritten bodies in PDB order.
- `include/rmm_shal.h` owns only the Shallows records and generator declaration.
- The public header uses the canonical `rmm_base.h` owner and keeps `map.h`
  source-private in `src/rmm_shal.cpp`.
- Tile accesses use canonical `RGE_Tile::terrain_type`.
- Stack and path calls use the canonical reference APIs.
- The old wrapper and all three owner fragments are removed.
- The translation-unit entry is `rmm_shal`, with the default response file.

## Status and validation

- `00487010` and `00487050` remain matching owners.
- `00487200` remains scratch. Its natural-source candidate result is a
  1,024-byte mismatch in its 1,172-byte body. The owner symbol matches, with
  one boundary escape. No scratch recovery tuning was performed during the
  source move.
- The grouped candidate was checked after natural source closure.
- Candidate result: `00487010` and `00487050` report `MATCH` and `0.0000%`.
- Candidate result: `00487200` reports `MISMATCH`, 1,024 differing bytes,
  matching owner, and one boundary escape.

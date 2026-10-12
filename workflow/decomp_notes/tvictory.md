# tvictory.cpp source reunification

## Context

- PDB source: `C:\\msdev\\work\\age1_x1\\tvictory.cpp`.
- Source lines run from 30 through 83.
- The module owns six normal functions in PDB source and address order:
  `0052C8F0`, `0052C920`, `0052C940`, `0052C950`, `0052C970`, and `0052C9B0`.
- All six owners belong to `TRIBE_Victory_Conditions`.
- The PDB type dump proves the derived class size is `0x20`.

## Source ownership

`src/tvictory.cpp` owns all six bodies in PDB order. Its header now owns only
`TRIBE_Victory_Conditions`. The header includes `victory.h` for the canonical
victory base and record types.

The source includes `tplayer.h` and `tech.h` privately. It uses the canonical
`TRIBE_Player::tech_tree` member at `+0x220` and the
`TRIBE_Player_Tech::get_tech_state(short)` method. It has no copied player or
technology declaration, wrapper, context macro, fallback declaration block,
manually declared vtable, inline assembly, or raw address expression.

The derived class size probe is:

```cpp
typedef char tribe_victory_conditions_size_check[
    (sizeof(TRIBE_Victory_Conditions) == 0x20) ? 1 : -1];
```

The nonvirtual derived QAE destructor declaration remains. The PDB owner
restores the derived vtable before it jumps to the base destructor.

`tvictory.h` now uses the canonical `victory.h` owner. The stale
`victory_context.h` and `tvictory_context.h` headers had no source or
configuration consumers and were removed.

## Validation

The one grouped candidate translation-unit check used:

`python tools/validate_candidate_tu.py --proposal build/candidate_tus/tvictory_final.json --output-dir build/candidate_tus/tvictory_final`

The candidate compiled all six owners. Every row reported `MATCH` with
`0.0000%`, zero byte differences, zero relocation target mismatches, and zero
boundary escapes. The candidate reported a fully exact module.

| Owner | Original | Rebuilt | Result |
| --- | ---: | ---: | --- |
| `0052C8F0` | 42 | 42 | `MATCH` |
| `0052C920` | 25 | 25 | `MATCH` |
| `0052C940` | 11 | 11 | `MATCH` |
| `0052C950` | 26 | 26 | `MATCH` |
| `0052C970` | 49 | 49 | `MATCH` |
| `0052C9B0` | 36 | 36 | `MATCH` |

No focused or global validation ran. No function regression was proven, so no
function was demoted.

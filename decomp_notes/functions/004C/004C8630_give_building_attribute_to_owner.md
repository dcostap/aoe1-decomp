# Function notes: 004C8630 `give_building_attribute_to_owner`

Module notes: `decomp_notes/t_b_obj_module.md`.

## Recovered attempt history

<!-- recovered:026fd540b2e98431296a -->
### `5868718576a8` `src/scratch/004C8630_give_building_attribute_to_owner.cpp:1-7`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// attempt 1: base draft, size 80 (1 byte short of 81)
// attempt 2: manual vtable cast, compile error
// attempt 3: natural C++ vcall through owner->method(), still 80
// attempt 4: use this->pManager inside loop (no mgr local), still 80
// attempt 5: fix checks (>= 4, >= 0), still 80
// attempt 6: separate if/goto checks, still 80
// left in scratch: 1 byte size drift, behavior correct, source basin not found
```
<!-- end-recovered:026fd540b2e98431296a -->

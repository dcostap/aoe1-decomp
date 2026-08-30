# Function notes: 004557C0 `data_load_random_map`

Module notes: `decomp_notes/map_module.md`.

## Recovered attempt history

<!-- recovered:6ffb7338c78915435f3a -->
### `489810cbdcd9` `src/matching/004557C0_data_load_random_map.cpp:1-4`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// first pass: keep the allocation/ctor as a natural direct new-expression and preserve the single assignment
// with /GX this should be the right EH/new basin if the constructor shape is the same as the packet
// BINARY NOTE (map TU wave02): The target allocates a 0x4F5C controller.
// The shared map TU declaration lacks that storage.  No source-only repair is supported.
```
<!-- end-recovered:6ffb7338c78915435f3a -->

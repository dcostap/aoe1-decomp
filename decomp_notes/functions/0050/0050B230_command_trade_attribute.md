# Function notes: 0050B230 `command_trade_attribute`

Module notes: `decomp_notes/tcommand_module.md`.

## Recovered attempt history

<!-- recovered:e7d0d62c4c5098a1da56 -->
### `5868718576a8` `src/scratch/0050B230_command_trade_attribute.cpp:1-8`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// attempt 1: calloc(0xC,1) with if (buf && (buf+8)); 80 bytes (missing redundant test)
// attempt 2: <stdlib.h> for calloc decl; same 80 bytes
// attempt 3: int* p = buf+8 as named temp; same 80 bytes
// attempt 4: nested if (buf) if (p); same 80 bytes
// attempt 5: nested if with explicit != NULL; same 80 bytes
// attempt 6: fixed calloc(1, 0xC) arg order; same 80 bytes
// Original has redundant 'test eax,eax; je' after 'lea eax,[esi+8]' that VC5 /O2 always eliminates
// Left in scratch: benign 3-byte codegen drift, behavior fully correct
```
<!-- end-recovered:e7d0d62c4c5098a1da56 -->

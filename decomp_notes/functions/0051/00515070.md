# Function notes: 00515070 `addObject`

## Recovered attempt history

<!-- recovered:9db5a684b175f16592a6 -->
### `a5fb96a1e6de` `src/scratch/00515070_addObject.cpp:1-11`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// tplayer.cpp:1974-1997, 105 bytes
// attempt 1: compile error void* size
// attempt 2: 78.1%, ebp instead of esi, vfunc call shape wrong, setne vs xor
// attempt 3: 81.9%, proper inheritance worse
// attempt 4: 78.1%, same as attempt 2
// attempt 5: 78.1%, if/else flag form no change
// BEST: 78.1% (attempts 2,4,5). 23 bytes match.
// BLOCKER: VC5 uses ebp for this (not esi), pushes esi in vfunc call (extra arg),
//   uses setne for flag (not mov eax,1 + cmp/jne + xor), extra add esp,8 cleanup.
//   Guard order correct, base call correct, addItem call correct.
//   Core issue: register allocation (ebp vs esi) cascades through entire function.
```
<!-- end-recovered:9db5a684b175f16592a6 -->

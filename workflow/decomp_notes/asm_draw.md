# Drawing assembly recovery

## Current integration

The user approved preserving the connected drawing engine as a binary dependency.
`config/drawing_binary.json` scopes its code, tables, shared state, nine exports, and 4,223 absolute relocations.
The executable build uses this dependency instead of `src/Asm_draw.asm`.
It still assembles `src/Drawarea_asm.asm` for the three drawing memory methods.
VC5 still compiles C/C++ and links the executable.

`src/Asm_draw.asm` remains available as incomplete recovered source.
It contains six entrypoints and 114 blocks, including copy and pattern-fill blocks.
Its probes remain available. It does not provide a second production owner.
See `executable_build_evidence/drawing_binary/README.md` for the preserved engine's evidence.

## Address and instruction evidence

`config/asm_draw.json` records original addresses, instruction boundaries, private storage, and code blocks.
`config/drawarea_asm.json` records the memory methods and their direct call targets.
The probe checks those targets against the function registry.

All nine entrypoint bodies have equal instruction bytes after resolving COFF address fields to original symbols.
The original checkpoint checked 38 solid-fill code blocks.
Later probes check all 114 recovered blocks with equal resolved instruction bytes.
Private initializers and all 128 solid-fill dispatch pointers agree with the original.
These checks do not claim recovery of the complete original assembly module.

| Entrypoint | Original VA | Instruction bytes |
|---|---|---:|
| `TDrawArea::PtrClear` | `00444850` | 308 |
| `TDrawArea::PtrSpanCopy` | `00445250` | 334 |
| `TDrawArea::OverlayMemCopy` | `00445580` | 385 |
| `ASMSet_Shadowing` | `0056C680` | 57 |
| `ASMSet_Surface_Info` | `0056C720` | 61 |
| `ASMSet_Color_Xform` | `0056C760` | 23 |
| `ASMGet_Color_Xform` | `0056C780` | 11 |
| `ASMSet_Xlate_Table` | `0056C7A0` | 13 |
| `ASMDraw_HLine` | `0056C7E0` | 447 |

No preserved candidate was found for these entrypoints or `0056C9A0`.

## Solid-fill source model

The shared return block at `00563000` jumps through the saved continuation pointer.
Solid-fill blocks occupy `00563DA0..005640B9`.
Small blocks use the original byte, word, and DWORD stores.
Long blocks retain the original prefix, DWORD loop, and suffix.
Macros express these repeated operations without embedding instruction bytes.

The dispatch prefix at `0056A700` contains 128 pointers.
The length lookup at `0056B300` contains 256 bytes.
HLine selects only this solid-color dispatch prefix.
The other dispatch entries remain part of sprite recovery.

The original code section has read/execute permissions.
The restored code and dispatch data use an executable, read-only section.
Mutable state uses writable data.

The shadow arrays hold four row entries, not a proved MMX object.
Sprite instructions at `0056CACB..0056CADC` select these entries with the row index modulo four.

## Native checks

The setup fixture tests 65,536 input sets at each of two image bases.
The memory-method fixture tests 2,048 input sets at each base.
The HLine fixture tests 8,192 input sets at each base.
The bases are `00400000` and `10000000`.
These are separate links, not forced loader rebasing.

The method fixture checks clipping, null rectangles, span lists, lock failures, overlapping copies, and unaligned buffers.
Its Lock and Unlock definitions are test doubles only.
The game links its existing implementations.

The HLine fixture checks lengths through 256, all destination alignments, reversed endpoints, clipping, multiple spans, and empty rows.
Both fixtures compare complete buffers, including bytes outside the requested pixels.
These tests do not establish game startup or gameplay correctness.

## Deferred sprite source recovery

The preserved drawing component now resolves `ASMDraw_Sprite` at `0056C9A0`.
Complete assembly source recovery remains deferred.
The inventory's 524-byte entry is not its complete implementation.
Branches reach the return path at `0056D2F4` and the flipped path at `0056D300`.
Further command handlers and dispatch tables belong to this closure.

The original `THIS_COD` section spans `00563000..0056DBE0`.
Its last command helpers extend beyond the current region boundary at `0056DBBA`.
Inspect those targets before defining sprite boundaries.
Do not stop recovery at the narrow inventory entry.

At `0056C9DA`, top clipping sets the stored destination y to zero.
Do not replace that value with `min_line` without further evidence.
`0088C038` stores HLine's length and Sprite's row index.
Reuse its existing storage owner during sprite recovery.

The entry contains alignment instructions before `0056CAA0`.
Recover their assembly alignment rule rather than adding an instruction payload.

## Retained evidence

See `executable_build_evidence/drawing_assembly/README.md` for reports and the latest build result.
No deferred normal-function semantic review was reopened.

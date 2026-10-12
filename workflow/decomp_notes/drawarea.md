# Drawarea.cpp source reunification

The module now uses `src/drawarea.cpp` in PDB source order. The former
per-function files supplied the current source bodies. The module header owns
the proven DirectDraw, GDI, bitmap, span-list, and draw-area layouts. The
`RGE_Color_Table` declaration is owned by `color.h`; `drawarea.h` only
forward-declares it. `src/drawarea.cpp` includes `color.h` for the table fields
used by `TDrawArea::SetShadowTable`.

## Runtime display-depth check

The original and rebuilt EXEs both reject the current 32-bit windowed display mode.
`TDrawSystem::Init` requires 8 bits per pixel and sets error 2 for this mismatch.
The game then reports graphics error 7. This observed failure does not identify a reconstruction defect.
The original also rejects the legacy WING draw type before calling DirectDraw.

See [startup comparison](executable_build_evidence/drawing_binary/startup_comparison.md) for hashes, addresses, and debugger logs.
No source change accompanies this test. Complete startup and gameplay remain untested.

The corrected runtime copies the user's complete installed beta and applies `DWM8And16BitMitigation` through `Launch.cmd`.
Both original and rebuilt EXEs then pass the constructor startup check with game error code zero.
The debugger stops at that check. Menu behavior and gameplay remain unverified.

## Alignment proof

`TDrawArea::TransColor` ends at `+0xFC`. VC5 aligns the object to `0x100`.
The header no longer adds `_pad_end[3]`.

`build/header_size_probe.cpp` compiled with the pinned VC5 flags. Its
`sizeof(TDrawArea) == 0x100` assertion passed.

## Worker pass: corpus-02-drawarea

Fresh canonical-TU checks for all six assigned scratch functions remain
`MISMATCH`: `DrawShadowBox` 68 bytes, `Paint` 291, `DrawLine` 103, `Clear`
113, `Copy` 718, and `take_snapshot` 326. No source or registry change is
retained. The translation-unit audit reports all 50 exact validation targets
as `MATCH`.

The closest target is `DrawShadowBox`. Its isolated old-context source reaches
an exact 271-byte variant, but the natural reunified TU remains 272 bytes with
one boundary byte after the original. Do not integrate the isolated source.

The paired grouped checks ran after this header repair. The Color check passed
all six exact owners and its generated destructor. Its two accepted-drift
owners remained mismatches of 437 and 10 bytes. The report is
`build/candidate_tus/color_header_boundary/report.txt`.

The Drawarea check used the reviewed temporary proposal and passed all 48
exact owners. The six overloaded observed symbols were present. It reported
zero comparison errors. Its 13 observed rows had positional differences of
453, 326, 7, 1, 218, 21, 718, 328, 0, 3, 4, 68, and 326 bytes, in VA order
`00442A90` through `004463B0`. Boundary escapes were 0, 1, 0, 0, 0, 0, 0,
2, 0, 0, 0, 1, and 0. The report is
`build/candidate_tus/drawarea_header_boundary/report.txt`.

The exact rows and comparison-error gate passed. The full-module flag remains
false because accepted-drift and scratch rows are not exact.

The cached paired recheck ran after the padding removal. Color kept six exact
matches and its generated destructor match. Drawarea kept 48 exact matches.
Both reports had zero comparison errors.

## Observed non-matching owners

- `00442A90 TDrawSystem::Init`: accepted drift. The typed DirectDraw source
  preserves the 15 ordered calls, error paths, palette stores, and `0x60C`
  frame. The remaining difference is entry register and receiver scheduling.
- `00443CB0 TDrawSystem::SetPalette`: accepted drift. The natural member source
  preserves palette loading, zero initialization, and the ModifyPalette call.
- `00444040 TDrawArea::Init`: accepted drift. The one-byte difference is an
  equivalent list-walk base load. Calls, stores, and control flow match.
- `00444680 TDrawArea::Clear`: scratch. The source preserves the PtrClear
  fallback, software fill, DirectDraw fill, clipping, and five calls. Its
  current natural result has 218 differing bytes from private register and
  block lowering. This is broad structural drift, not localized equivalent
  drift.
- `00444C30 TDrawArea::SetClipRect`: accepted drift. The source preserves span
  manager ownership, seven calls, region setup, and row construction. The
  remaining differences are local compare and argument scheduling.
- `00444D50 TDrawArea::Copy`: scratch. Both low-memory and DirectDraw
  paths preserve six calls, clipping, transparent flags, global status stores,
  and return behavior. The current module build has 716 differing bytes from
  local address lowering. This drift is too broad for accepted drift.
- `004459A0 TDrawArea::DrawRect(long, long, long, long, uchar)`: matching.
  The final grouped reconciliation promotes the natural PDB member owner. It
  reports `MATCH`, `0.0000%`, with four original line calls.
- `00445A60 TDrawArea::DrawHorzLine`: accepted drift. Clipping and the external
  fill call are preserved. The current module build has a three-byte
  instruction-scheduling difference.
- `00445AF0 TDrawArea::DrawVertLine`: accepted drift. Clipping and pixel stores
  are preserved. The current module build has four register-coloring bytes of
  drift.
- `004463B0 TDrawArea::take_snapshot`: scratch. Palette conversion,
  numbered file retry, lock/write/unlock flow, bottom-up row copy, and cleanup
  are preserved. The current module build has 326 differing bytes from header
  and retry-tail scheduling. This drift is too broad for accepted drift.
- `00446230 TDrawArea::DrawShadowBox`: scratch. The current grouped audit
  reports 68 differing bytes and one boundary escape. The body keeps the
  natural source, but the boundary escape blocks accepted drift.

`00443520 TDrawSystem::Paint` and `00445840 TDrawArea::DrawLine` remain scratch.
Their source preserves the recovered behavior, but broad code-generation drift
remains. The current module builds are 317 differing bytes for Paint and 328
differing bytes for DrawLine. `004438F0 GetDCErrorNum` is padding-only and is
not a normal owner.

## Canonical global and string audit

`system_ignore_size_messages` and `DAT_0062e64c` now come from
`include/game_globals.h`. The old drawarea-only absolute storage macro and
duplicate declaration are removed. The exact owners remain exact after this
include change.

The following values remain local because the original evidence does not prove
a reusable provider:

- `DDSys_CanColorFill`, `PalSetRes`, `FullPalSets`, and `AniPalSets` have PDB
  symbols, but no reviewed shared header or storage owner exists yet.
- `DAT_0062e650` is the unnamed dword next to `DAT_0062e64c` at `0062E650`.
- The default snapshot format at `005845E4` is shared with `spanlist.cpp`, but
  neither module has a reviewed shared string provider.

The source keeps these declarations or the absolute format address. It does
not invent a carrier or guess a global owner.

## Assembly memory methods restored on 2026-09-06

`src/Drawarea_asm.asm` now supplies `PtrClear`, `PtrSpanCopy`, and `OverlayMemCopy`.
Their 308, 334, and 385 instruction bytes agree with the original after address resolution.
The native fixture also checks the reviewed field offsets and member calling convention.
See `asm_draw.md` and `executable_build_evidence/drawing_assembly/` for reports.

`PtrClear` uses inclusive bounds and clips the optional rectangle before locking.
It reads the row table after Lock returns.
It reads DrawSystem again before its conditional Unlock call.

`PtrSpanCopy` treats the receiver as the source and the first argument as the destination.
It checks the source DrawSystem but locks the destination.
It clips row count against destination height.
It does not add horizontal span clipping or call Unlock here.

`OverlayMemCopy` copies complete DWORDs, including the rounded-up width.
Negative vertical movement selects rows from bottom to top.
Negative horizontal movement selects reverse DWORD copying only when vertical movement is zero.
The reverse path clears the direction flag before returning.

The assembly preserves the original nested register saves and argument-slot reuse.
No normal C++ body or matching status changed in this assembly step.

## Worker pass: luna-12-drawarea

Fresh checks at assignment base `16d5a4044` report current natural results:
`Copy` 718 differing bytes, `DrawLine` 103, `take_snapshot` 326, `Clear`
113, `DrawShadowBox` 68, and `Paint` 291. Owners and ordered call sets match.
`DrawShadowBox` and `Paint` still escape their original boundaries by one and
two bytes. The snapshot retry tail and Paint CFG each retain two edge-shape
differences.

The worker tested source-order declaration context for `SetShadowTable`, the
reduced color declaration surface from the old local exact lead, and the
direct drawing declaration context. These states emitted baseline or worse
bytes. All shared-header and source edits were restored. No registry status,
ordinary source body, or shared layout change is proposed.

Final audit `build/luna12-drawarea-final-audit/report.txt` compiled 62 normal
owners, kept all 50 exact validation targets, and found no matching-neighbor
code change. Runtime malformed-input, API-fault, signed-overflow, and full
gameplay tests remain unperformed.

## Worker pass: luna-12-drawarea, take_snapshot follow-up

The target remains natural scratch. A fresh check reports 533 rebuilt bytes
versus 540 original, 326 strict differences, matching `0x87C` frame, 14
ordered calls, matching owner, and retry CFG counts of 1/2 jumps and 2/1
returns. The original width, height, palette, file, buffer, lock, row-copy,
unlock, close, and free effects remain represented in source.

The controlled Variant Lab state is
`23f61a65dd327d3d1d024aa3bb1d50819afa9e75b57975b9319782634e77f6f7`, with
parent `066fe7d869069383b27b8186d20a08bc7fbb08538ff1561b3d47e49a77ae04e9`.
Eight natural header and retry forms compiled with two workers. No variant
passed size, frame, and call-set gates. The canonical group stayed 533 bytes;
the changed forms emitted 534 or 536 bytes. No source change remains.

The one-job audit `build/luna12-drawarea-final-audit-004463B0/report.txt`
compiled 62 normal owners and kept all 50 exact validation targets. No
matching-neighbor regression came from this pass. Runtime malformed-input,
API-fault, signed-overflow, and full-gameplay tests remain unperformed.

## Accepted-drift rereview: `00442A90 TDrawSystem::Init`

Worker `sa-093dc5e8` rebuilt the current canonical source at base
`28ecdd497c`. The fresh check remains `MISMATCH`: 802 original bytes versus
801 rebuilt bytes, 285 versus 286 instructions, 453 differing bytes in 31
spans, and one reported CFG edge difference. The frame is `0x60C`, the saved
register set matches, and all 15 calls align in order with matching targets
and argument counts. The first mismatch is the function entry.

The source behavior audit confirms the current natural body. It publishes all
eight fields, rejects draw type 1, calls DirectDrawCreate and CheckAvailModes,
selects the two cooperative-level paths, checks 8-bit display depth, loads or
zeros both palette arrays, creates the palette and clipper, creates surfaces,
reads caps, and clears mode 2. Failure returns set error 1. The depth failure
sets error 2. The corrected `dwRGBBitCount` test from `27d65b3d3` is retained.

The accepted-drift proof is not complete. The rebuild reads a stack parameter
before its frame allocation. It also changes the order of vtable and `Wnd`
loads, moves the `ColorBits` store before fullscreen argument reads, and moves
the `IsBanked` store before the caps receiver reads. These changes can alter
fault order for invalid stack, object, or DirectDraw state. The source has no
safe natural repair for this compiler scheduling basin. A prior direct
`DirDraw` caps probe reached 436 differing bytes but did not recover the
entry block; it was not retained.

No source or registry status change is retained. The target needs an explicit
orchestrator decision on the existing `accepted_drift` status. Runtime tests
cover startup and display-depth rejection only. API-fault and malformed-input
tests remain open.

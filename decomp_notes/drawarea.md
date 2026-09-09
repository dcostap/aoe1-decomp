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

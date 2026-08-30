# Function notes: 004A6290 `~TRIBE_Screen_Disconnect`

Module notes: `decomp_notes/scr_mps_module.md`.

## Translation-unit context

- PDB module: `scr_mps.cpp`; natural owner: `src/scr_mps.cpp`.
- The target is the `TRIBE_Screen_Disconnect` destructor after its constructor
  at `004A61A0` in this module's class-owner sequence.
- The class layout packet places `message` at `this + 0x47C`.
- The original body is 86 bytes. It has no frame pointer and saves `esi`.

## Current result

- Current source is exact: 86 rebuilt bytes versus 86 original bytes.
- The rebuilt body has the original two direct calls, in order:
  `TPanel::delete_panel` at `004A62C2`, then `TScreenPanel::~TScreenPanel`
  at `004A62D1`.
- The owner symbol matches. The original boundary is closed. All 7 relocation
  checks are safe. Strict positional difference is 0 bytes (0.0000%).
- The final focused check was recorded as checkpoint
  `20260829T220823.389021Z-89ff41c55e`. It confirms `MATCH`, 22 aligned
  instructions, and no call-map differences.
- The canonical source form is natural for this module. It calls the inherited
  `TPanel::delete_panel` helper, as do nearby panel destructors, and casts the
  proven `message` field to the helper's `TPanel**` parameter.

## Recovered attempt history

<!-- recovered:527e173d44c11a0ac777 -->
### `5868718576a8` `src/scratch/004A6290_TRIBE_Screen_Disconnect.cpp:1-9`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// attempt 1: simple class, /GX; only 32 bytes (no EH frame generated)
// attempt 2: inheritance + /GX; 80 bytes, 6 short (missing explicit vtable store)
// attempt 3: explicit vtable ptr with extern; only 48 bytes (worse)
// attempt 4: back to 80-byte shape; same 80
// attempt 5: stdlib.h/stddef.h include; same 80
// attempt 6: vtable ptr assignment with local; 48 bytes (worse)
// attempt 7: lea for message addr, fixed delete_panel(0, p); same 80
// Left in scratch: 80 vs 86 bytes; VC5 doesn't emit explicit destroying vtable store
// (mov dword [esi], 0x573518 = 6 bytes) with this class hierarchy. Behavior correct.
```
<!-- end-recovered:527e173d44c11a0ac777 -->

### `wave21-scr-mps` natural translation-unit recovery

The baseline `delete this->message;` emitted a null check and an indirect
destructor call. It produced 90 bytes and missed the original direct
`delete_panel` call. Replacing it with
`this->delete_panel((TPanel**)&this->message);` produced the original 86
bytes and exact call surface. This form matches the canonical helper use in
the surrounding source and the proven `message` field address.

## Rejected approaches

- Direct `delete this->message;`: rejected. The compiler emitted an indirect
  call and a null branch, unlike the original direct helper call.
- An unqualified `delete_panel` spelling was not retained. Its validation
  probe could not run because the target-session lock timed out; the known
  exact qualified form was restored without another lock retry.

## Open questions

- The main agent must review source plausibility and promote the exact owner.

## Next useful approaches

- No further code recovery is needed unless the owning-source review rejects
  the canonical helper form. Re-run the focused checker after any review edit.

## Worker updates

- `wave21-scr-mps`: Baseline was 90 bytes with 43 differing bytes and one
  replaced call site. The helper form restored 86 bytes, 22 aligned
  instructions, 2 aligned calls, closed boundaries, safe relocations, and
  `MATCH`, `0.0000%`. The worker-specific `scr_mps` audit reported all 24
  registered owners as matches; the ten unregistered rows remain unrelated
  module work. The final audit at
  `build/audits/workers/wave21-scr-mps/scr_mps/report.txt` retained the target
  as `MATCH` with zero diff, correct ownership, relocations, and boundary.

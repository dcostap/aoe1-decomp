# Recovery journal: 0043FC70 `TMessageDialog`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/dlg_msg.cpp`.
- PDB source: `C:\msdev\work\age1_x1\Dlg_msg.cpp`.
- Earlier recovery note: `recovery_notes/dlg_msg_module.md`.

## Translation-unit context

PDB module `Dlg_msg.cpp` owns the seven methods from `0043FC70` through
`00440130`. The target is the first definition, `TMessageDialog(char*)`.
The next address is the compiler-generated deleting destructor at `0043FCB0`.
The natural header proves `TDialogPanel` as the base, `dlg_type` at `+0x490`,
`text` at `+0x494`, and `button[0..2]` at `+0x498..+0x4A0`.

The five registered exact neighbors are `0043FCD0`, `0043FFF0`, `00440070`,
`00440100`, and `00440110`.

## Current mismatch

The natural source rebuild is 57 bytes and 15 instructions. The original is
59 bytes and 16 instructions. Both have no frame, save `esi`, make one direct
`TDialogPanel` call, and return with `ret 4`. The owner, boundary, and call
target are correct. The strict difference is 44 bytes (74.5763%).

The first structural difference is at `+0x0F`: the rebuilt constructor emits
the derived vtable store before the member stores. The original emits
`xor ecx,ecx`, clears `dlg_type` and `text`, writes the vtable, then clears the
three button pointers with `ecx`. The rebuilt constructor uses one zero value
and places the vtable store at `+0x0F`. This is a localized code-generation
difference, not a behavior change.

## Recovered attempt history


<!-- recovered:32e2d9a478c77123b00e -->
### `d050eea3c` `src/dlg_msg.cpp:1-2`

Mapping: `strong`. next mapped function definition is TMessageDialog at old line 8.

```text
// PDB source module: C:/msdev/work/age1_x1/Dlg_msg.cpp.
// Definitions follow the original source order.
```
<!-- end-recovered:32e2d9a478c77123b00e -->

<!-- recovered:bb513e2fccfac103fbc0 -->
### `458aaecbc2e6` `src/scratch/0043FC70_TMessageDialog.cpp:1-4`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 0043FC70 TMessageDialog::TMessageDialog (59B)
// PDB source: Dlg_msg.cpp lines 43-48
// tried manual-vtable class with explicit +0x490/+0x494/+0x498/+0x49C/+0x4A0 layout; call/base/prologue matches
// remaining drift: VC5 keeps hoisting the vtable store before dlg_type/text zeroing and reuses eax=0 for all button stores instead of xor ecx,ecx + late mov eax,esi
```
<!-- end-recovered:bb513e2fccfac103fbc0 -->

## Rejected approaches

- An array member initializer `button()` compiled but emitted no button stores
  and reduced the body to 39 bytes. It was rejected as incorrect source
  behavior.
- Initializing `dlg_type` and `text` in the member-initializer list while
  clearing `button[0..2]` in the body kept the same 57-byte, 15-instruction
  output and did not move the vtable store.
- A chained `button[0] = button[1] = button[2] = 0` expression reversed the
  store order and kept the same size and mismatch. It was rejected because it
  is less natural and does not improve the binary result.
- A local `TButtonPanel* null_button = 0` kept the same 57-byte output. It was
  rejected as compiler steering with no gain.

## Open questions

The original source form that makes VC5 place the implicit vtable store after
the first member stores remains unknown. The array cannot appear in a VC5
member-initializer list. The prior explicit-vtable form is not allowed by the
current source policy.

The first `target_session.py check` attempt timed out on
`build/target_sessions/sessions.lock`. Do not retry the lock. The direct
`check_function.py` result and the grouped audit below remain available.

## Next useful approaches

Keep the simple body form. A later worker can inspect the original compiler
context or a period header for an array-free member model. Do not add a manual
vtable, overlay, raw offset, or volatile register hint.

## Worker updates

### 2026-08-29 wave20-dlg-msg

No source improvement survived. The constructor remains a natural body with
three separate button stores. Focused `check_function.py --rebuild` reports
MISMATCH, 44 bytes, 74.5763%, 15 versus 16 instructions, and one correct
direct base-constructor call. The grouped `dlg_msg` audit reports 5 exact
registered neighbors and 2 grouped mismatches (`0043FC70`, `0043FD50`).
The coordinator paused the stale lease after the wave closed. The lock timeout
prevented a clean baseline pin.

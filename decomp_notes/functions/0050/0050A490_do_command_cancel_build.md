# Function notes: 0050A490 `do_command_cancel_build`

Module notes: `decomp_notes/tcommand_module.md`.

## Translation-unit context

PDB module: `tcommand.cpp`; owner: `TRIBE_Command`; source order is the natural
`src/tcommand.cpp` definition at lines 483-489. The original body uses the
world object lookup, a null test, and one virtual call at slot `+0x240`.

The current canonical hierarchy places `TRIBE_Combat_Object::cancel_object()`
at slot `+0x250`. The old context-header source used `RGE_Static_Object::cancel_object()`
and matched, but that declaration is not present in the current shared header.

## Previous baseline mismatch

Fresh baseline after the natural module rebuild: size `33/33`, frame none,
11 instructions, and `1` strict byte difference (`3.0303%`) at offset `+0x1A`.
The lookup call aligns. The rebuilt virtual call is `+0x250`, while the
original is `+0x240`; boundaries and CFG match.

## Canonical ABI repair result

The shared combat declarations now match the PDB evidence.  In
`include/com_obj.h`, `RGE_Combat_Object::play_move_sound(RGE_Sound*)` is
nonvirtual.  In `include/t_c_obj.h`, the introducing virtual declarations follow
the PDB order.

The fresh checker result is `MATCH`, `0.0000%`, at `0050A490`.  The owner and
boundary match.  Both calls align, and the one relocation is safely masked.
The direct virtual call now uses the original `+0x240` slot.  No function body
changed.

The five-group audit completed in
`build/audits/workers/wave21-combat-vtable-integrate/report.txt`.  All 157
registered-owner rows match.  This target is an unregistered grouped match.

## Recovered attempt history

<!-- recovered:650d0edcb59f104cbe3c -->
### `d050eea3c` `src/tcommand.cpp:427-428`

Mapping: `strong`. next mapped function definition is do_command_cancel_build at old line 494.

```text
// PDB order: lines 531-665.
// BINARY NOTE: Original game fields use draw_system +0x48 and quick_build +0x9A8.
```
<!-- end-recovered:650d0edcb59f104cbe3c -->

## Rejected approaches

Casting the result to `TRIBE_Building_Object*` is natural for this command, but
it emits the same `+0x250` call and gives no improvement. Do not add a local
flat class, raw vtable access, or inline assembly to force the old slot.

## Open questions

The shared canonical ABI needs a reviewed explanation for the original
`RGE_Static_Object`-surface cancellation slot at `+0x240`. This function alone
cannot add that surface under the wave lease.

Target-session operations saw global `sessions.lock` contention. Some start and
check attempts timed out. The fresh baseline later completed; no force or lock
deletion was used.

## Next useful approaches

Review the canonical object vtable ownership and the original class surface.
If a shared ABI repair is approved, rebuild this target before further source
tuning.

## Worker updates

### wave10-tcommand

Retained the natural `TRIBE_Combat_Object*` call because the `TRIBE_Building_Object*`
variant produced identical code. Fresh result remains `MISMATCH`, `1` byte,
with only the virtual-slot replacement. No status change or exact claim was made.

### wave21-combat-vtable-integrate

Applied the PDB-proven shared combat declaration repair.  The fresh check now
reports `MATCH`, `0.0000%`, with matching owner, boundary, calls, and relocation.

# Command conversion-order repair

## Current decision: 2026-09-11

The incoming-int candidate passes complete static review under the current supported stack-input scope.
Its fresh compiled bytes equal the preserved candidate bytes.
The old counterexample below depends on an invented pointer into future callee-owned storage.
Current policy excludes that case without executable evidence of actual use.
Ordinary caller-owned objects and their aliases remain covered.

Root approves the natural incoming-Y repair as accepted drift.
See `logic_reviews/00435110.md` for all 64 instructions, helper behavior, fault order, and closure evidence.
The following rejection records the historical scope. It does not request another matching pass.

## Behavior

The original `00435110` converts incoming Y before saved Y.
The current main source emits the opposite order.
The existing unreadable-page counterexample remains valid.
See `logic_reviews/00435110.md`.

A new natural trial fixes Y order but changes a saved register width.
The original writes `BP` before the fourth `__ftol` call.
The trial writes `EBP` instead.
This difference changes valid instruction-level results for stack-overlapping input records.

### Static counterexample

Let `S` be ESP at function entry.
Use these initial values:

| Item | Value |
| --- | --- |
| Incoming record | `S - 48` |
| Saved record | Separate readable storage |
| Both count bytes | `1` |
| Both target IDs | `0` |
| Both initial X coordinates | `0.0f` |
| Saved Y coordinate | `0.0f` |
| Saved unit ID | `0x12340000` |
| Caller EBP | `0x12340000` |
| x87 control word | `0x037F` |

Map `[S-64, S+16]` and both records as readable and writable.
Supply the incoming pointer at `[S+4]`.
Supply a readable command object with the saved-record pointer at offset eight.

The function saves five registers or stack words before its conversion calls.
Each `__ftol` call writes its return address at `S-24` and saves EBP at `S-28`.
Its result occupies `[S-40, S-33]`.
Its two control words occupy `[S-32, S-29]`.

The incoming record overlaps these locations:

| Incoming field | Address |
| --- | --- |
| Target ID | `S-44` |
| Count byte | `S-40` |
| X coordinate | `S-36` |
| Y coordinate | `S-32` |
| First unit ID | `S-28` |

Both implementations read and retain the count before the conversion calls.
Both initial X conversions return zero.
Their control-word writes set incoming Y to float bits `0x037F0F7F`.
That positive finite value is less than one, so its integer conversion returns zero.
The saved Y conversion also returns zero.
Both target IDs remain zero.

The original retains EBP's upper half through `mov bp,ax`.
The fourth helper call therefore writes `0x12340000` to the incoming unit ID.
The trial uses `mov ebp,eax` and writes zero there instead.
The original unit comparison succeeds and returns AL equal to one.
The trial comparison fails and returns AL equal to zero.

This is a static proof, not an executed game test.
The proof script checks the relevant original and candidate instruction bytes.
It also checks all 39 original helper bytes against the pinned VC5 `ftol.obj`.
See `decomp_notes/crt_reference_identity_review.md` for the independent CRT identity evidence.

## Source

The rejected trial adds one ordinary `int` value for incoming Y.
It does not change the ABI or add a wrapper, compiler directive, or assembly.
Its source is natural, but the emitted register-width difference has a proved behavior effect.
Natural source alone does not establish equality with the executable.

## Bytes

Baseline state: `25ac7230359234845c11edc7faa000ce358b26112d5995edc06b6216424512fa`.
Incoming-int state: `3bb22a85203df13267e60a438988d6df5357d92c426709d1c1aa6d4d5a408dcb`.
The baseline has 153 bytes and three positional differences.
The incoming-int trial has 152 bytes.
Its pointer homes and Y load order follow the original.
Its full-width EBP save makes it unsafe despite those improvements.

The preserved labs also test combined predicates, direct casts, record references, count types, and sixteen-bit equality types.
None of those completed labs produces an exact result.
Their state events preserve generated source, flags, objects, and reports.

## Integration

Reject the incoming-int trial.
Do not approve it as accepted drift or replace the known ordering defect with this stack-overlap defect.
Keep the main command source unchanged until a candidate passes complete review.

Counterexample event: `dd59837df4ca63a43588b55235c5e6800e7c6fb20c4e049d61933e8f94aaaaa1`.
The event preserves `build/prove_command_int_alias.py` and its result.
The isolated command worktree remains available.

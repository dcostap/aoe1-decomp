# Main-view destructor repair

## Behavior

No game was run. Original code and compiled COFF objects provide the evidence.
Original `00495490` and `0053DB30` contain five-byte jumps to `RGE_View::~RGE_View` at `00533760`.
The explicit empty RGE_Main_View destructor added a vptr write before the base destructor.
Removing that unsupported definition and declaration restores the derived destructor's direct base jump.

The base remains virtual. Implicit destruction preserves the class layout and virtual slot.
RGE_Main_View adds only scalar and pointer fields; none requires destruction.
No normal method body changes in the nine-module dependency closure.

## Source

The corpus already classifies both original destructor entries as compiler-generated.
The retained source lets the compiler generate destruction instead of supplying an ordinary body for those entries.
No inline assembly, wrapper, or duplicate source owner was added.

## Bytes

Baseline: `b8e99d8f86a2d2ea2717d2796bcd805ed4d8e6e4ee00d1d33ea83b3a0c3048f0`.
Implicit state: `81325e19855a4fc22664168bdb687a266f9a9b5fe1709935df3bac393ca33577`.
Target run: `b99de25d26fd7545f15941be03f8978cdb5de25341f32693e158c7d7749b69d7`.
The constructor remains `MATCH`, `0.0000%`, 81 bytes. Its module has no exact-neighbor regression.

The transitive closure contains 338 normal functions in nine modules.
Of 306 prior matching claims, 303 pass and three retain unrelated missing-target evidence.
Those entries are `00441460`, `005237B0`, and `005243A0`. They are not counted as passes.

Complete external-owner comparison preserves local code labels, constant bytes, and recursive EH storage references.
Only these emitted owners change:

- TRIBE_Main_View destructor copies in Scr_game and Scr_sed now jump directly to RGE_View.
- The unsupported standalone RGE_Main_View destructor disappears from vw_main.obj.
- RGE_Main_View's scalar deleting destructor now calls RGE_View directly.

All other external code owners compare equal, including their referenced local storage.
Evidence event `fd41f09e191b48938210fd1fa7156e6fde7eb40c566821da8aa131a01ff51b8b` preserves the comparison script and result.
Event `819a753c49cdc6a7da9814496c33e3bdb8a7c7f329c0843e11969a2441a37319` preserves the closure report and initial comparison.

## Integration

Accept the source repair. Preserve both experiment states and the exact constructor candidate patch.
The scalar deleting destructor has accepted generated-code drift, not an exact target claim.

Original `0053DB13` calls `0053DB30`, which only jumps to `00533760`.
The new scalar destructor calls the same base body without that jump.
Both push one return address and reach the base with the same receiver, registers, stack depth, and arguments.
Both then test flag bit zero, conditionally call operator delete, return the saved receiver, and pop four argument bytes.
The omitted jump has no data-memory effect or cleanup. Null-receiver and stack faults occur at the same corresponding operations.
The base destructor and operator-delete calls remain unchanged.
This proves equal effects, ABI, cleanup, exceptions, and data-fault order for the forwarding difference.
No further matching work is required for this generated drift without new evidence.

Linked checks must retain unknowns where the original standalone main-view destructor no longer has a selected symbol.
Do not add a synthetic body or suppress that coverage limit to restore a numeric count.

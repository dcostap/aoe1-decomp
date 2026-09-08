# RESENDER constructor repair

Base: `ef479e9e7`. All inspection is static. No game was run.

## Behavior and ownership

The original 30-byte constructor writes TimeSent, ResendMsg, Serial, and Length in that order.
Their offsets are zero, eight, four, and twelve. It then clears ten unsigned-int DestMap entries.
The complete body preserves EDI and returns this through EAX under the original constructor ABI.
It has no calls, relocations, allocation, or exceptional cleanup.

The old source wrote Serial before ResendMsg. That changes store and possible fault order.
Original PDB lines 293–297 place the constructor in `com_hand.h`.
Keep one definition in the class, not a second body in the communications source.

The existing Windows header supplies ZeroMemory. Use it to clear the complete array after the scalar stores.
This is an ordinary array-clear operation, not a compiler directive or forced emission.
The natural communications callback still emits the constructor.

## Preserved alternatives

- `claims-resender-store-order`, state `b975d2630271...`: corrected source-file store order; exact target.
- `claims-resender-header`, state `8b2dd94f5d68...`: in-class loop; exact target.
- `claims-resender-header-definition`, state `4f60774876d8...`: out-of-class inline header body; exact target.
- `claims-resender-zero-memory`, state `f1413f3e339a...`: retained, smaller header body; exact target.

The two loop-based header forms preserve all 1,087 exact claims in their 24-module closure.
They also change other bodies, including the accepted-drift AnalyzeGameSpeed frame from twelve bytes to eight.
Do not approve those collateral changes merely because exact claims still pass.
Preserve their complete candidate patches and closure reports. Neither form is integrated.

The retained ZeroMemory form also reports `MATCH`, `0.0000%`, with all thirty original bytes.
Its run event is `ac1b163d24b8a86f685bb225fc881a7e6323fe8f4dc3f4c135ea5e8711c30ce9`.
The existing matching claims still pass in all 24 modules.

## Complete closure

The object comparison checks all 1,386 defined function bodies, not just matching labels or changed scores.
Only RESENDER and `00435110 duplicate_check_command_order` change instruction bytes.
All other function bodies remain byte-identical.
The private-symbol proof checks distinct storage, complete contents, BSS sizes, offsets, code anchors, and the reference graph.
It rejects merged or split private identities. Compiler suffix changes do not change the underlying storage.

The ordinary-owner report contains 33 changed records: two code changes and 31 symbol-only changes.
All accepted-drift instruction bodies remain unchanged in the retained form.

### Command comparison

The header context restores the command comparison's original unit-pointer homes and array-loop encoding.
Incoming units occupy ESP+18h; saved units occupy ESP+10h.
The remaining three differences are the existing reversed Y-conversion pair and its compare encoding.
The original converts the incoming Y coordinate first. The retained rebuild still converts the saved coordinate first.
This remains a fault-order defect. The constructor repair does not create it, and this function receives no promotion.

Six natural comparison, rejection, and short-value forms compile in this new header context.
They produce four code groups and no exact result. The best two-byte result still reverses the Y loads.
No command-source variant is retained merely for a lower difference count.
The earlier private-home and fault reviews remain valid evidence in `logic_reviews/00435110.md`.

## Integration

Retain the constructor ownership and store-order repair, with the standard array clear.
Keep all other source changes from the experiments out of this integration.
The independent target check, complete closure, linked header selection, and executable build all pass for the retained constructor.
The initial main constructor-input state is `6b1a0820fbe67871cc579e5137214da835a9daa301b06c81cabf8a7fbbc5c792`.
The final constructor context is `3f115a55b3cbd3b76ec80c56b233130c0a7899b39ff0460bbb26c06db698dba0`.
The separate final Tech context is `66985bdb678db7076213c74b3d6ae82e1a6684161199f92a6853befec0ea8c81`.
Each receipt freezes its own compiler inputs; parents do not automatically combine source snapshots.
The complete canonical candidate patch includes both retained source repairs and the registry corrections.

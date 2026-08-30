# Function notes: 0049EE00 `action`

Module notes: `decomp_notes/scr_main.md`.

## Recovered attempt history

<!-- recovered:dfb4b61b33dcda355be0 -->
### `target-session` `build/target_sessions/0049EE00_action.json:1-20`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=435; shape=94.47236180904522: Baseline clean reconstruction before new probes; source log claims 715-byte one-return basin.
probe 2 control-flow; result=MISMATCH; diff=435; shape=94.47236180904522: Baseline diagnostics: first mismatch is popup success-tail liveness; compare block map and preserve exact 715-byte basin. [same emitted code as probe 1]
probe 3 control-flow; result=MISMATCH; diff=648; shape=74.5019920318725: H1 natural direct returns: each success arm returns 1 and fallback returns parent directly; tests whether VC5 reproduces per-arm EAX moves and common fallback.
probe 5 liveness; result=MISMATCH; diff=648; shape=74.5019920318725: H2 source-local result assigned at each event success arm, with confirm and fallback assignments; tests whether PDB lVar5 assignments control original per-arm EAX moves.
probe 7 control-flow; result=MISMATCH; diff=648; shape=74.5019920318725: H3 retain one initialized result=1 but return result directly from each event arm; tests whether branch-local return of the shared value inserts original mov eax,esi without direct literal returns.
probe 9 liveness; result=MISMATCH; diff=648; shape=74.5019920318725: H4 initialized result=1 before event plus redundant result=1 assignments at every success edge; tests whether explicit writes retain original per-arm return moves while preserving the one-return EH CFG. [same emitted code as probe 5]
probe 11 control-flow; result=MISMATCH; diff=648; shape=74.2063492063492: H5 success arms goto common result tail while unmatched fallback returns parent directly; tests original direct-parent EAX path against one shared EH epilogue.
probe 13 abi; result=MISMATCH; diff=435; shape=94.47236180904522: H6 model button array as natural TButtonPanel* derived from TPanel instead of base pointers; tests canonical field type without changing offsets or virtual slots.
probe 15 control-flow; result=MISMATCH; diff=435; shape=94.47236180904522: H7 reverse event comparison operand order (1 == event); binary cmp operand order predicts this natural spelling should move the event guard basin. [same emitted code as probe 2]
probe 17 liveness; result=MISMATCH; diff=598; shape=88.71794871794872: H9 initialize result at declaration and remove delayed success initialization; binary ESI=1 begins only after confirm filter, so this tests declaration/initialization timing.
probe 19 variant; result=MISMATCH; diff=598; shape=88.71794871794872: variant lab build\variant_lab\0049EE00_action\20260817_130742: 16 variants, 0 invariant-eligible, 0 exact
probe 20 variant; result=MISMATCH; diff=598; shape=88.71794871794872: variant lab build\variant_lab\0049EE00_action\20260817_130835: 192 variants, 40 invariant-eligible, 0 exact
probe 21 abi; result=MISMATCH; diff=435; shape=94.47236180904522: H10 use int for the local success result while keeping the long function ABI; tests local signed-width hypothesis against the undefined4 stack evidence. [same emitted code as probe 15]
probe 23 liveness; result=MISMATCH; diff=435; shape=94.47236180904522: H11 initialize result to zero at declaration but retain delayed result=1 before event; tests whether an early harmless initialization restores the original tail liveness. [same emitted code as probe 21]
probe 26 liveness; result=MISMATCH; diff=435; shape=94.47236180904522: H12 register-qualified result: tests whether the original per-arm EAX moves came from a register result hint while retaining the common cleanup tail. [same emitted code as probe 25]
probe 27 control-flow; result=MISMATCH; diff=526; shape=94.9238578680203: H13 direct confirm success with event arms unchanged: tests the original line-272 EAX immediate while preserving the one-return event basin.
probe 28 control-flow; result=MISMATCH; diff=648; shape=74.2063492063492: H14 explicit success/fallback labels modeled on exact Scr_main/scr_mp EH tail donors; tests direct returns with a compiler-visible shared success label.
probe 29 control-flow; result=MISMATCH; diff=648; shape=74.5019920318725: H15 event-valued success returns: tests whether the original mov eax,esi edges return the already-validated event value rather than a literal. [same emitted code as probe 7]
probe 30 control-flow; result=MISMATCH; diff=648; shape=74.5019920318725: H16 direct success returns plus explicit success/fallback labels, mirroring the exact Scr_main sibling source rather than routing every arm through success.
probe 31 control-flow; result=MISMATCH; diff=648; shape=74.5019920318725: H17 negative event guard with direct success returns and fallback label: tests the sibling donor's forward fallback topology against the original jne-to-parent edge. [same emitted code as probe 29]
```
<!-- end-recovered:dfb4b61b33dcda355be0 -->

<!-- recovered:08e2289f05223f07b1a4 -->
### `ee72aee0191a` `src/scratch/0049EE00_action.cpp:1-47`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 0049EE00 TRIBE_Screen_Main_Menu::action (715B)
// Scr_main.cpp lines 264-387
// EH-framed virtual action dispatcher
// Attempt log:
// - Baseline reconstruction follows the executable's panel-name filter,
//   five-button dispatch, CD checks, typed screen allocations, and inherited
//   TEasy_Panel fallback.
// - Mirrored the PDB/Ghidra lVar5 assignment at each success arm with long
//   result; VC5 widened the function to 854 bytes and produced nine returns.
//   Rolled back because this changed the proven one-return block shape.
// - Tested a direct return of the initialized success result after button 2;
//   VC5 emitted the same 715-byte code as the clean source. Rolled back as a
//   duplicate; the EAX-before-tail scheduling gap remains.
// - A single success-result assignment before the event chain plus a common
//   done label restored the original 715-byte size and one-return CFG; the
//   remaining basin keeps the success value in ESI and reloads it at the
//   common tail instead of moving EAX before each success jump.
// - Nested else-if, shared success-label, direct-confirm-return, and int
//   result variants were rolled back: they widened the body or duplicated
//   the EH epilogue. Remaining gap is localized VC5 tail/liveness scheduling,
//   with calls, offsets, frame, and behavior aligned.
// - Direct fallback return widened to 852 bytes and nine returns; restored.
// - Direct return or live-result return on one CD-popup arm was codegen
//   duplicate; narrowed result type was also duplicate.
// - Proven polymorphic declarations for allocated screen types kept the
//   715-byte output unchanged; restored the simpler size stubs.
// - Tested assigning the validated event value to the shared success result;
//   output changed by one byte farther from the original, so restored the
//   clean result assignment. The per-arm EAX move gap remains unresolved.
// - Current pass tested eleven distinct natural hypotheses. Direct returns,
//   per-arm result writes, direct fallback, and early result initialization
//   widened or changed the body. Typed button pointers, comparison reversal,
//   int result, and zero result initialization were unchanged or worse.
// - A structured lab covered 192 source/flag variants across result timing,
//   fallback form, button surface, event comparison, and VC5 flag axes.
//   It produced 12 code groups, 40 invariant-eligible variants, and no match.
//   The closest /GX group kept 715 bytes and one return but still missed the
//   original early branch spans and the per-arm EAX moves.
// - Fresh H12-H17 probes tested a register-qualified result, direct confirm
//   success, explicit success/fallback labels, event-valued returns, and
//   negative event guards. They reproduced the duplicated EH basin or grew
//   the body. Restored the pinned one-return source.
// - Remaining blocker: natural source preserves all calls, offsets, frame,
//   boundary, and CFG counts, but VC5 places the success value in ESI and
//   reloads it at the common tail. The original moves ESI to EAX on each
//   success edge and returns the fallback call value directly.
// FLAGS: /GX (EH)
```
<!-- end-recovered:08e2289f05223f07b1a4 -->

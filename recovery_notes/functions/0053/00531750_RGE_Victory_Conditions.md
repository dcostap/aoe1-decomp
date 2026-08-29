# Recovery journal: 00531750 `RGE_Victory_Conditions`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/victory.cpp`.
- PDB source: `C:\msdev\work\age1_x1\victory.cpp`.
- Earlier recovery note: `recovery_notes/victory_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:04d517dde7ac0c3db634 -->
### `target-session` `build/target_sessions/00531750_RGE_Victory_Conditions.json:1-37`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=896; shape=76.41791044776119: Baseline current audited named-local source: 33 calls aligned, 335 instructions, 865 rebuilt bytes versus 920 original, frame 0x10 versus 0x1C, 896 strict differing bytes. Call surface and owner symbol match; structural reconstruction is next.
probe 2 liveness; result=MISMATCH; diff=882; shape=84.91124260355029: Hypothesis 1: model the decompiler-supported list-count pointer and victory-list tail pointer, then use a local total-points pointer. This tests whether proven pointer lifetimes recover the original 0x1C frame and tail-link topology.
probe 3 liveness; result=MISMATCH; diff=509; shape=85.92375366568915: Hypothesis 2: defer pointer-local assignments until their first proven use. The original loads version_flag before saved-register setup, then creates list and tail addresses after the header reads; this tests declaration lifetime without removing the frame.
probe 4 liveness; result=MISMATCH; diff=889; shape=87.02064896755162: Hypothesis 3: reuse the dead version_flag parameter home as both serialized-entry and point-entry loop index. Original writes and rereads the incoming +0x10 home at both loop tails; replacing separate index locals tests that proven home reuse.
probe 6 liveness; result=MISMATCH; diff=509; shape=85.92375366568915: Hypothesis 4: reverse the two proven pointer-local declarations. This tests whether VC5 local-slot allocation order, rather than behavior, places the list tail at the original stack home without adding machinery. [same emitted code as probe 5]
probe 7 liveness; result=MISMATCH; diff=509; shape=85.04398826979472: Hypothesis 5: move the two serialized object-ID locals to function scope, matching the decompiler/PDB evidence that these homes persist across the entry body. This tests declaration scope and stack-home allocation without changing behavior.
probe 8 liveness; result=MISMATCH; diff=938; shape=62.71186440677966: Hypothesis 6: mutate the saved file-handle parameter into the serialized target-player ID. Original writes and rereads the incoming handle home while ESI preserves the file handle, proving parameter-home reuse; target-object remains a local.
probe 9 liveness; result=MISMATCH; diff=506; shape=87.09677419354838: Hypothesis 7: save the file handle in a dedicated local, then mutate the original handle parameter into target-player ID. This preserves file-read behavior while testing the original incoming-home write pattern and local register color.
probe 10 liveness; result=MISMATCH; diff=506; shape=86.21700879765396: Hypothesis 8: promote the serialized target-object ID to function scope. The original uses a persistent local at the -0x14 stack home while the tail link temporary occupies -0x18; this tests that lifetime separation after the proven handle-home reuse.
probe 11 liveness; result=MISMATCH; diff=884; shape=89.6755162241888: Hypothesis 9: combine the proven handle-home reuse with reuse of version_flag as both loop counter. This directly tests the two incoming-home writes seen in the original stack trace while preserving a dedicated saved file handle.
probe 12 liveness; result=MISMATCH; diff=506; shape=86.21700879765396: Hypothesis 10: retain the H9 pointer and parameter-home topology but restore a separate long index local. This tests whether original dword index arithmetic comes from a compiler-coalesced long local, not the unsigned-byte version_flag type. [same emitted code as probe 10]
probe 13 liveness; result=MISMATCH; diff=500; shape=90.9090909090909: Hypothesis 11 diagnostic: use a long pointer alias to the dead version_flag home so loop updates emit dword arithmetic at the proven +0x10 location. This tests the observed width without retaining a raw alias unless the result supports a natural source explanation.
probe 14 liveness; result=MISMATCH; diff=506; shape=86.21700879765396: Hypothesis 12: replace the raw dword alias with block-scoped long counters whose lifetimes end between the two loops. This tests whether natural scope-based home reuse reproduces the original dword +0x10 counter. [same emitted code as probe 12]
probe 15 control-flow; result=MISMATCH; diff=500; shape=90.9090909090909: Hypothesis 13: reverse the source order of index-zeroing and player assignment. The original emits list-count load/compare before player store and dword index zero; this tests whether VC5 scheduling follows the dependency-free statement order. [same emitted code as probe 13]
probe 16 control-flow; result=MISMATCH; diff=733; shape=88.37209302325581: Hypothesis 14: split the player scan guard from the redundant post-scan target-player check. Original has a late shared tail after the second ID/null test; sibling guards should preserve that block layout instead of nesting the state assignment.
probe 17 control-flow; result=MISMATCH; diff=733; shape=88.37209302325581: Hypothesis 17: express the shared post-player-check tail with a local label. The original branches for negative ID and found object both land at one common target-object block, so explicit proven CFG ownership may recover branch polarity and layout.
probe 18 liveness; result=MISMATCH; diff=500; shape=90.9090909090909: Hypothesis 18: introduce a branch-local self alias for the player scan. Original reloads the saved constructor self into a general register before world/player traversal; this tests whether explicit receiver ownership recovers register color without raw offsets.
probe 19 liveness; result=MISMATCH; diff=500; shape=90.9090909090909: Hypothesis 19: compare the reused target-player ID against a named zero local. Original uses a persistent zero register for signed CMP/JL, while the natural immediate form emitted TEST; this tests width and branch lowering without raw address changes. [same emitted code as probe 18]
probe 20 abi; result=MISMATCH; diff=500; shape=90.9090909090909: Hypothesis 20: name the owning object-list receiver for the first target-object lookup. The original pushes the ID before loading the receiver, unlike the current direct member expression; this tests whether an explicit typed receiver recovers the call setup. [same emitted code as probe 19]
probe 21 liveness; result=MISMATCH; diff=506; shape=87.09677419354838: Hypothesis 21: split saved file-handle declaration from assignment. The decompiler shows an early parameter copy; this tests whether VC5 places that copy at the original statement boundary without changing typed ownership. [same emitted code as probe 9]
probe 25 control-flow; result=MISMATCH; diff=506; shape=87.09677419354838: Hypothesis 1: replace both top-tested while loops with the PDB/decompiler-supported positive preguard and do-while form. This tests whether VC5 loop rotation and preguard scheduling recover the original count-before-player store and shared point-loop tail. [same emitted code as probe 24]
probe 27 liveness; result=MISMATCH; diff=506; shape=86.21700879765396: Hypothesis 2: move the target-object ID to function scope and reorder the natural local declarations to mirror the proven Ghidra stack homes: target ID, tail, version, save version, point count, list-count pointer, index. This tests whether VC5 declaration order and lifetime recover the original -0x18/-0x14/-0x10 local topology without raw aliases. [same emitted code as probe 14]
probe 29 control-flow; result=MISMATCH; diff=738; shape=84.59302325581395: Hypothesis 3: make the post-player-scan state failure test a separate sibling guard. The original has a second handle >= 0 compare after the scan, so this tests the proven redundant predicate and its block layout.
probe 31 liveness; result=MISMATCH; diff=506; shape=87.09677419354838: Hypothesis 4: add a branch-local self alias only for the cross-player object scan. The original reloads the saved constructor self at the loop tail and uses it for player/world traversal; this tests natural receiver lifetime and register coloring without raw aliases.
probe 32 liveness; result=MISMATCH; diff=502; shape=88.56304985337243: Hypothesis 5: reuse the same natural long index local for both serialized-entry and point-entry loops. The original dword counter stays in one incoming-home location across both loops; this tests shared source lifetime without a parameter-home cast.
probe 33 control-flow; result=MISMATCH; diff=502; shape=88.56304985337243: Hypothesis 6: reverse the source order of the shared loop counter initialization and player member assignment. Original emits the list-count load and compare before storing player, so this tests whether statement order controls that early scheduling basin. [same emitted code as probe 32]
probe 35 liveness; result=MISMATCH; diff=500; shape=90.9090909090909: Hypothesis 7: promote the serialized target-object ID to function scope while retaining the shared natural counter. This tests whether a persistent ID local recovers the original -0x18 home when combined with the newly proven cross-loop counter lifetime. [same emitted code as probe 15]
probe 36 abi; result=MISMATCH; diff=500; shape=90.9090909090909: Hypothesis 8: remove the persistent world and branch self aliases from the cross-player scan, using direct this->player->world expressions. Original reloads self at the loop tail while retaining world only in a register across the body; this tests the natural expression form.
probe 37 control-flow; result=MISMATCH; diff=733; shape=88.37209302325581: Hypothesis 9: retest the proven sibling post-scan handle predicate after recovering the natural target-ID and shared-counter local basin. This combination tests whether the original redundant compare can be kept without the prior prologue regression.
probe 39 liveness; result=MISMATCH; diff=503; shape=90.6158357771261: Hypothesis 10: materialize the initial list count before the player assignment, then retain pointer-based loop updates. This tests whether a natural count temporary forces the original count-load/compare before player-store schedule; the temporary is diagnostic and will be removed unless supported.
probe 41 control-flow; result=MISMATCH; diff=500; shape=91.78885630498533: Hypothesis 11: reverse the outer version predicate to the original positive-first form while retaining the required post-map negative retest. Original falls through the mapped-version path and sends only the initial negative case to a late zero block; this tests source branch polarity and cold-block placement.
probe 42 control-flow; result=MISMATCH; diff=500; shape=92.96187683284458: Hypothesis 12: reverse the post-map version retest to a positive-first form. The original uses a late jl edge for mapped negative versions and falls through to world lookup; this tests the proven inner predicate polarity and cold-state block order.
probe 43 control-flow; result=MISMATCH; diff=513; shape=90.37900874635568: Hypothesis 13: express the player traversal as the binary-supported positive preguard plus do-while, including the world reload at the bottom. This tests whether loop rotation recovers the original player-count guard and saved-self register topology.
probe 45 layout; result=MISMATCH; diff=500; shape=93.25513196480938: Hypothesis 14: use the period C++ double literal 1.0 for the save-version threshold. Original reads an 8-byte DAT_00577590 operand with fcomp qword, while the prior source used 1.0f and emitted fcomp dword [0]; this tests proven width and branch polarity.
probe 46 control-flow; result=MISMATCH; diff=493; shape=97.0326409495549: Hypothesis 15: reverse the save-version outer predicate to positive-first with the point-loading body falling through and the zero-total path late. Original uses fcomp/test ah,1/jne to a late total-zero block; this tests source branch polarity and preserves the proven double threshold.
probe 47 abi; result=MISMATCH; diff=493; shape=97.0326409495549: Hypothesis 16: name the player object-list receiver for the first target-object lookup. Original pushes the ID before loading this->player->objects, unlike the direct member expression; this tests a natural receiver lifetime and evaluation-order basin after the improved branch source.
probe 51 baseline; result=MISMATCH; diff=712; shape=93.841642228739: Fresh authentic-wrapper baseline after stale cache notice
```
<!-- end-recovered:04d517dde7ac0c3db634 -->

<!-- recovered:b85cf7f13894e0bc91b2 -->
### `b7fd2baf398f` `src/scratch/00531750_RGE_Victory_Conditions.cpp:1-33`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// RGE_Victory_Conditions::RGE_Victory_Conditions
// VA: 00531750
// victory.cpp
// Attempt log:
// - Replaced raw-offset scaffolding with typed player, world, object-list, entry, and point
//   ownership. The 33-call set and direct helper identities now match the executable.
// - Pointer locals for list count and list tail recover the original 0x1C frame and 920-byte
//   boundary. Saving the file handle and reusing its dead parameter home as target-player ID
//   is required for the best natural source shape.
// - BINARY NOTE: The original writes the target-player ID through the incoming handle home.
//   ESI still carries the file handle for every later read.
// - BINARY NOTE: A dword loop counter reuses the incoming version-flag home. One natural
//   counter now serves both serialized loops. The serialized target-object ID has function
//   scope. This recovers the original local basin without a raw parameter-home alias.
// - Positive-first version predicates recover the late negative-version blocks. A double
//   1.0 threshold recovers the original qword FPU compare. The canonical point record uses
//   id at +2 and group at +3, as shown by the exact add_point and save donors.
// - Probe 46: the best natural source has exact size, frame, owner symbol, and 33 ordered
//   calls. It has 493 differing bytes, 97.03% shape, and 87.46% exact-block coverage.
// - Remaining drift is the early player-store order, player-scan register color, point-read
//   register color, and vtable relocation context.
// - BINARY NOTE: PDB assigns this body to victory.cpp lines 28-145. The same module's
//   exact constructor and destructor anchors are 00531AF0 (lines 150-158) and 00531B20
//   (lines 163-172). The shared declarations in victory_context.h preserve the proven
//   0x20 conditions, 0x34 entry, and 0x1C point-entry layouts.
// - Current prefix pass: binding the second serialized area coordinate to the proven y2
//   +0x18 alias reduced the natural candidate from 712 to 493 differing bytes and removed
//   the boundary escapes. The remaining mismatch is the logged early-store and register
//   allocation basin. Initialization-order reordering was codegen-neutral and was restored.
// - Captain validation: the authentic 58-owner candidate keeps 44 exact owners and reports
//   this constructor at 493 differing bytes, 920-byte original boundary, 0x1C frame, and
//   33 ordered direct calls. Swapping the zero-index and player-store statements was neutral;
//   the natural order was restored. Remaining work needs source or shared-context evidence.
```
<!-- end-recovered:b85cf7f13894e0bc91b2 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.

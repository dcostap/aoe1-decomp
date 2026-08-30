# Function notes: 0042AD10 `TXResendReply`

Module notes: `decomp_notes/com_hand_module.md`.

## Recovered attempt history

<!-- recovered:11ba2011123b0e7bef34 -->
### `target-session` `build/target_sessions/0042AD10_TXResendReply.json:1-37`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=822; shape=83.68794326241135: Baseline current scratch reconstruction before new hypotheses; establish exact metrics and call/block differences.
probe 2 behavior; result=MISMATCH; diff=822; shape=83.68794326241135: H1: use incoming player directly for the early dcoID guard, then copy it after validation; tests direct member compare and local lifetime. [same emitted code as probe 1]
probe 3 liveness; result=MISMATCH; diff=822; shape=83.68794326241135: H2: move the packet local before scalar locals; tests declaration-order effects on the original 0x18 frame and packet home. [same emitted code as probe 2]
probe 4 liveness; result=MISMATCH; diff=822; shape=83.68794326241135: H3: model the decompiler's BadTransmitCount as the real error counter; tests whether the original extra local and bad-count naming control the 0x18 frame. [same emitted code as probe 3]
probe 5 control-flow; result=MISMATCH; diff=723; shape=78.64768683274022: H4: merge invalid-player and bad-DCOID failures through one typed message and late log label; tests the oracle's shared cold call tail.
probe 6 liveness; result=MISMATCH; diff=822; shape=83.68794326241135: H5: introduce one natural zero local for the two DCOID guards; tests whether VC5 can retain the original zero-register compare and add the missing frame slot. [same emitted code as probe 4]
probe 7 control-flow; result=MISMATCH; diff=845; shape=77.61732851985559: H6: express the early player validation as positive-valid with an else failure; tests compare polarity and block layout without changing behavior.
probe 8 liveness; result=MISMATCH; diff=822; shape=83.68794326241135: H7: lift elapsed, send-start, send-duration, and retransmit-log time values to function scope; tests decompiler's function-wide time temporaries and local lifetime pressure. [same emitted code as probe 6]
probe 9 liveness; result=MISMATCH; diff=818; shape=89.36170212765957: H8: keep the DirectPlay result in a distinct long local before the retransmit command overwrites the packet local; tests the unexplained extra original stack dword.
probe 10 liveness; result=MISMATCH; diff=818; shape=89.36170212765957: H9: combine the exact-frame send-result local with direct incoming-player use in the early dcoID guard; tests the original memory-compare form. [same emitted code as probe 9]
probe 11 control-flow; result=MISMATCH; diff=844; shape=83.39350180505416: H11: use an explicit valid-player label after the dcoID test; tests whether VC5 emits the oracle's direct memory compare and short branch.
probe 12 liveness; result=MISMATCH; diff=818; shape=89.36170212765957: H12: reverse the distinct send-result and packet-local declaration order; tests stack-home assignment while preserving the exact-frame hypothesis. [same emitted code as probe 10]
probe 13 liveness; result=MISMATCH; diff=818; shape=89.36170212765957: H13: scope the distinct DirectPlay result local to the found-resend branch instead of function scope; tests lifetime scope and stack-home coloring. [same emitted code as probe 12]
probe 14 abi; result=MISMATCH; diff=818; shape=89.36170212765957: H14: narrow the local DirectPlay result from long to int; tests signed-width ABI coloring without changing the four-byte wire result. [same emitted code as probe 13]
probe 15 abi; result=MISMATCH; diff=818; shape=89.36170212765957: H15: model player DCO IDs as signed long rather than unsigned int; tests the original compare lowering and ABI extension without changing width. [same emitted code as probe 14]
probe 16 liveness; result=MISMATCH; diff=820; shape=91.1032028469751: H16: retain the decompiler-proven resend pointer across the retransmit log block; tests EBP base coloring and repeated field ownership.
probe 17 liveness; result=MISMATCH; diff=820; shape=91.1032028469751: H17: lift the resend base pointer declaration to function scope while assigning it only at the retransmit log; tests EBP pointer coloring against the original reuse. [same emitted code as probe 16]
probe 18 liveness; result=MISMATCH; diff=820; shape=91.1032028469751: H19: declare GoodTransmitCount before the bad-count counter; tests VC5 register colors in the loop update and retx log. [same emitted code as probe 17]
probe 19 liveness; result=MISMATCH; diff=820; shape=91.1032028469751: H20: declare the moving resend offset before player and counter locals; tests parameter-home reuse and loop update register colors. [same emitted code as probe 18]
probe 20 liveness; result=MISMATCH; diff=820; shape=91.1032028469751: H21: remove the redundant player copy before the resend scan and rely on the validated copy; tests parameter liveness across the throttle and loop. [same emitted code as probe 19]
probe 21 control-flow; result=MISMATCH; diff=879; shape=85.27397260273973: H22: express the outer DCOID guard as positive-valid with now acquisition inside the arm; tests the oracle's cmp-memory/jne form and branch scheduling.
probe 23 liveness; result=MISMATCH; diff=853; shape=74.91525423728814: H23: move the preserved playerNumber copy before the early dcoID guard, matching the decompiler's early param copy and testing whether VC5 assigns the original player to EBX.
probe 25 control-flow; result=MISMATCH; diff=797; shape=83.39222614840989: H24: restore one binary-proven errorText/goto tail for invalid player and zero DCOID, matching the original shared LAB_0042B07B CFG.
probe 26 control-flow; result=MISMATCH; diff=797; shape=83.39222614840989: H25: reverse the early dcoID equality operands, testing whether VC5 selects the oracle's cmp memory,zero-register form instead of load/test. [same emitted code as probe 25]
probe 28 layout; result=MISMATCH; diff=823; shape=72.6027397260274: H27: model one current RESENDER cursor with typed Serial, ResendMsg, and Length fields across the fixed-stride scan, testing the natural record owner against raw slot-relative accesses.
probe 30 behavior; result=MISMATCH; diff=800; shape=77.3851590106007: H29: combine the shared errorText tail with the original nosuch.Serialno Send-result home, reproducing the decompiler's proven reuse before the retransmit command overwrites it.
probe 31 layout; result=MISMATCH; diff=723; shape=78.64768683274022: H31: reduce the shared-tail/nosuch Send model to the smallest raw resend owner, removing the narrow late RESENDER alias and testing the prior best 723-byte source basin. [same emitted code as probe 5]
probe 32 liveness; result=MISMATCH; diff=717; shape=84.69750889679716: H32: retain the shared error tail and raw resend owner while separating the DirectPlay Send result, testing whether the original 0x18 frame can coexist with the 723-byte CFG basin.
probe 33 behavior; result=MISMATCH; diff=717; shape=84.69750889679716: H33: compare the early dcoID directly against the already-zero offset local, testing the oracle's cmp memory,EDI lowering without adding a synthetic zero variable. [same emitted code as probe 32]
probe 34 liveness; result=MISMATCH; diff=826; shape=86.92579505300354: H34: compute the transformed resend-slot offset before the serial/time stores while indexing those stores through preserved playerNumber, testing the PDB 3824 LEA/store order and original home write topology.
probe 35 layout; result=MISMATCH; diff=797; shape=83.39222614840989: H35: add the binary-proven narrow RESENDER alias only for the retransmit log/delete block while retaining the shared error tail and separate Send result. [same emitted code as probe 26]
probe 36 layout; result=MISMATCH; diff=808; shape=74.73684210526316: H36: create a branch-local RESENDER record at base-plus-offset and use typed Serial, ResendMsg, and Length fields, testing natural fixed-stride ownership without a loop-persistent cursor.
probe 37 liveness; result=MISMATCH; diff=717; shape=84.69750889679716: H37: move the shared errorText declaration before all ordinary locals, testing declaration-order effects on VC5 home assignment while retaining the binary-proven common tail. [same emitted code as probe 33]
probe 38 liveness; result=MISMATCH; diff=797; shape=83.39222614840989: H38: cache this->Resend before the retransmit timestamp and carry the typed pointer through the late serial/length/retx log arguments, matching the oracle's EBP base reload topology. [same emitted code as probe 35]
probe 39 abi; result=MISMATCH; diff=717; shape=84.69750889679716: H39: use the reviewed period RGE_Comm_Error::ShowReturn(char*) ABI instead of const char*, testing the helper declaration against the Com_hand donors.
probe 40 liveness; result=MISMATCH; diff=717; shape=84.69750889679716: H40: name the TXPacketLength load/add/store result in the successful resend arm, testing the original three-instruction member update against the current folded memory add. [same emitted code as probe 39]
probe 42 abi; result=MISMATCH; diff=717; shape=84.69750889679716: Use the proven DirectPlay Send slot at vslot+0x68 through a narrow caller view; no body reshape. [same emitted code as probe 41]
```
<!-- end-recovered:11ba2011123b0e7bef34 -->

<!-- recovered:b56f6d42dbaa7ec2172a -->
### `912332e8f578` `src/scratch/0042AD10_TXResendReply.cpp:1-52`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 0042AD10 TCommunications_Handler::TXResendReply
// Com_hand.cpp
// Attempt log:
// baseline: prior worker's broad behavioral scaffold; wrong helper/call surface,
// local buffers, and non-canonical resend ownership left an 807-byte body.
// behavior: restored the proven RESENDER/MSGFORMAT_RESEND ownership, DirectPlay
// Send ABI, FastSend/TXAcknowledge/ClearTX/Purge call family, and exact log text.
// control-flow: merged the invalid-player and zero-DCOID failures through one
// binary-proven log/return tail; emitted size became 894B but the compiler still
// placed the cold tail before the post-scan decision.
// liveness: removed the persistent RESENDER pointer and used repeated typed
// slot-relative accesses; this recovered the 0x18 frame and ESI=this basin,
// reaching 896B with 727 differing bytes, 22/22 call targets, and exact early
// guard/throttle islands. Register/stack coloring in the scan and send tail
// remains broad; an explicit positive scan backedge was emitted-code duplicate.
// liveness: a stable player copy before/after the dco guard, counter declaration
// order, and early offset initialization were tested; no further useful output.
// control-flow: direct Log-and-return branches restore the original invalid-player
// push/jump block and improve the diff by 25 bytes; the inner BAD-DCOID log remains
// a relocated shared cold block, so the ordered call gap is still -1/+1.
// behavior: corrected the TX RES REP log to pass the preserved player number,
// not the transformed resend-slot offset; the oracle pushes the player register.
// This improved edit/resync shape and exact block coverage, but widened the byte
// diff because VC5 changed the early register and local layout basin.
// layout: indexing the early dcoID guard through the preserved player number was
// source-canonical but emitted-code duplicate.
// control-flow: shared error-tail and post-scan error-state forms were tested;
// both moved farther than the direct typed branches and were rolled back.
// liveness/ABI: ordinary loop locals and unsigned counter types were tested;
// both emitted identical code and are kept as the natural typed declarations.
// liveness: a separate four-byte Send result local is required to recover the
// original 0x18 frame, the send-result home, and the long exact middle islands;
// direct assignment through nosuch leaves a 0x14 frame.
// ownership: a narrow RESENDER* local in the retransmit-log block follows the
// decompiler's pRVar1 evidence and reduces the body to 907B/91.10% shape, but
// changes player/base register colors and is not positionally better than the
// direct repeated-member form (907B, 820 differing bytes).
// unresolved: the first durable mismatch is the early dcoID guard (the oracle
// uses cmp [player slot],zero-reg; VC5 emits load/test). The shared invalid and
// BAD-DCOID tail is now source-modeled with one binary-proven errorText label,
// but VC5 still lowers its two string selections through a moved value. The
// loop/send tail has register and argument-scheduling drift.
// follow-up H23: moving playerNumber before the guard added a call and a 0x1C
// frame; restored the post-guard copy. H24/H25: the shared error tail reached
// 901B/797-diff with separate Send result; reversed equality was codegen duplicate.
// H27/H36/H38: persistent, branch-local, and late RESENDER aliases worsened the
// frame or shape. H29/H31: reusing nosuch.Serialno reached 723 diff but lost the
// 0x18 frame. H32: separate Send result with the shared tail and direct record
// accesses reaches 906B/0x18, 84.70% shape, 22/22 calls, and 717 differing
// bytes. H34 reordering the transformed player worsened 826 diff; H39's reviewed
// char* ShowReturn ABI and H40's named packet-length temporary were duplicates.
// Current source is unresolved and retains no accepted-drift residue.
```
<!-- end-recovered:b56f6d42dbaa7ec2172a -->

<!-- recovered:e3a602dade1c4f804e98 -->
### `912332e8f578` `src/scratch/0042AD10_TXResendReply.cpp:247-248`

Mapping: `exact`. historical standalone source path names this target VA.

```text
                *(char**)((char*)this->Resend + offset + 8),
                *(unsigned int*)((char*)this->Resend + offset + 0xC));
```
<!-- end-recovered:e3a602dade1c4f804e98 -->

<!-- recovered:514261808590ba932ee0 -->
### `912332e8f578` `src/scratch/0042AD10_TXResendReply.cpp:273-274`

Mapping: `exact`. historical standalone source path names this target VA.

```text
                   *(unsigned int*)((char*)this->Resend + offset + 0xC),
                   *(unsigned int*)((char*)this->Resend + player),
```
<!-- end-recovered:514261808590ba932ee0 -->

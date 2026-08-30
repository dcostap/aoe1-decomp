# Function notes: 00427600 `PreprocessMessages`

Module notes: `decomp_notes/com_hand_module.md`.

## Recovered attempt history

<!-- recovered:a9f632d382e718f8880d -->
### `target-session` `build/target_sessions/00427600_PreprocessMessages.json:1-44`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 control-flow; result=MISMATCH; diff=2943; shape=85.40816326530613: H1 first DCO lookup: replace pointer local with direct indexed member expression to test original LEA-before-compare lowering.
probe 2 layout; result=MISMATCH; diff=2937; shape=85.51020408163265: H2 first lookup declaration/evaluation order: read LowPlayerNumber before HighPlayerNumber to reproduce original mov di then mov cx order.
probe 3 liveness; result=MISMATCH; diff=2937; shape=85.51020408163265: H3 first DCO cursor lifetime: keep one pointer outside the loop and increment it with player, testing whether VC5 preserves original LEA/compare/add topology. [same emitted code as probe 2]
probe 4 liveness; result=MISMATCH; diff=2937; shape=85.51020408163265: H4 second DCO lookup cursor: use a moving pointer with the index to test original LEA-before-compare and found-edge lowering. [same emitted code as probe 3]
probe 5 control-flow; result=MISMATCH; diff=2739; shape=86.35897435897436: H5 loop-form donor test: convert both bounded DCO scans to signed for loops with direct indexed reads, based on same-TU scan evidence.
probe 6 layout; result=MISMATCH; diff=2877; shape=87.09016393442623: H6 separate second-scan result: preserve first lookup player in EDI and use a distinct log_player local for the later RX log, matching original stack home +0x10.
probe 7 layout; result=MISMATCH; diff=2779; shape=86.72839506172839: H7 delay log_player zero initialization until after the second scan, testing original no-found stack store position while retaining distinct result home.
probe 8 control-flow; result=MISMATCH; diff=2837; shape=87.39754098360656: H8 second-scan found edge: use an explicit forward label so found i skips the zero store, matching original jump to late result-home write.
probe 9 layout; result=MISMATCH; diff=2837; shape=87.39754098360656: H9 scope log_player after the bad-ack return block, allowing VC5 to reuse the original +0x10 packet home and reduce frame pressure. [same emitted code as probe 8]
probe 10 liveness; result=MISMATCH; diff=2791; shape=87.87255909558068: H10 remove the named C-packet pregame byte; original keeps AL live across the guard and both logs without a stack home.
probe 11 layout; result=MISMATCH; diff=2785; shape=93.4224049331963: H11 place high-latency and frame-rate bytes inside each proven ALL_DONE record, preserving original overlapping byte homes and argument order.
probe 12 layout; result=MISMATCH; diff=2791; shape=87.66700924974306: H12 move the guaranteed-ack record to function scope to test VC5 local-slot ordering and reuse of original [esp+0x10]/[esp+0x14] homes.
probe 13 layout; result=MISMATCH; diff=2789; shape=93.21685508735868: H13 narrow ack-record scope to the nonzero DCO arm, testing whether address-taken lifetime allows reuse of the original +0x10 local slot.
probe 14 layout; result=MISMATCH; diff=2785; shape=93.4224049331963: H14 swap msg_str/msg declaration order to test old VC5 local-slot packing against the original msg +0x2c and msg_str +0x12c bases. [same emitted code as probe 11]
probe 15 layout; result=MISMATCH; diff=2788; shape=87.87255909558068: H15 use the proven 8-byte prefix of MSGFORMAT_LATENCY for the ack arm, testing whether the shared 12-byte local basin reproduces original local_180/local_17c reuse.
probe 16 layout; result=MISMATCH; diff=2788; shape=87.87255909558068: H16 model ack and latency packets as one 12-byte protocol union, testing explicit local_180 reuse while preserving typed field ownership. [same emitted code as probe 15]
probe 17 liveness; result=MISMATCH; diff=2820; shape=93.62139917695474: H17 remove the cached Chat alias in command 3; original reloads this->Chat after Log and keeps ESI as the handler.
probe 18 layout; result=MISMATCH; diff=2785; shape=93.4224049331963: H18 scope msg from the first latency-dispatch arm and msg_str from the GTD arm, testing declaration lifetime against original +0x2c/+0x12c buffer bases. [same emitted code as probe 14]
probe 19 control-flow; result=MISMATCH; diff=2787; shape=92.72540983606558: H19 convert the missing-DCO '?' scan to the proven same-TU signed for/direct-index form, testing original LEA-before-compare topology.
probe 20 control-flow; result=MISMATCH; diff=2825; shape=93.33333333333333: H20 missing-player scan: use a moving dco cursor and late found label with zero initialization after the scan, mirroring the original LAB_00427cca topology.
probe 22 layout; result=MISMATCH; diff=2500; shape=86.52263374485597: H21 represent the bad-player packet as separate command-byte and serial locals, testing Ghidra local_180/local_17c evidence without a fabricated packet struct.
probe 24 layout; result=MISMATCH; diff=2785; shape=93.4224049331963: H23 declare the ack packet after the bad-player Log call, testing source lifetime start against original post-call local stores. [same emitted code as probe 23]
probe 25 liveness; result=MISMATCH; diff=2785; shape=93.4224049331963: H24 reverse bad-ack field assignment order to test VC5 scheduling against original serial-store then command-byte-store order. [same emitted code as probe 24]
probe 26 liveness; result=MISMATCH; diff=2788; shape=87.87255909558068: H26 reuse one latency packet local across bad-ack, ping, and debug-ping arms, testing Ghidra local_180 reuse as a single source object. [same emitted code as probe 16]
probe 27 layout; result=MISMATCH; diff=2785; shape=93.4224049331963: H27 replace explicit ack padding with compiler-natural alignment, testing whether VC5 treats the proven command/serial record differently. [same emitted code as probe 25]
probe 28 liveness; result=MISMATCH; diff=2845; shape=92.82786885245902: H28 declare the serial cursor before the second DCO scan, matching Ghidra's function-scope puVar1 evidence and testing pointer lifetime coloring.
probe 30 layout; result=MISMATCH; diff=2785; shape=93.4224049331963: H29 test a proven 8-byte command/serial packet as a local byte buffer, checking whether raw packet ownership recovers the original [esp+0x10]/[esp+0x14] stores. [same emitted code as probe 29]
probe 32 layout; result=MISMATCH; diff=2871; shape=93.51851851851852: H31 localize the DirectPlay receiver after the DCO_SELF guard, testing whether a natural pointer alias preserves the original single receiver load and vtable-call setup.
probe 33 liveness; result=MISMATCH; diff=2398; shape=93.62139917695474: H32 name the guarded DCO_SELF value and pass the same local to Send, testing whether VC5 keeps the original pre-command DCO load live in ECX across the packet store.
probe 34 layout; result=MISMATCH; diff=2850; shape=86.95208970438328: H34 restore the binary-proven adjacent command-byte and serial locals, while retaining H32's DCO and DirectPlay aliases, testing whether the ack packet coalesces to original entry homes without losing the exact COM block.
probe 35 layout; result=MISMATCH; diff=2411; shape=87.86008230452676: H35 move the typed bad-ack object to function scope, testing whether VC5 assigns the early packet to the low local frame slot while H32 preserves DCO and receiver liveness.
probe 36 layout; result=MISMATCH; diff=2398; shape=93.62139917695474: H36 swap the disjoint ALL_DONE and latency declarations in the command-1 arm, testing whether local-slot allocation moves the early ack object to the original +10 basin while preserving H32 call setup. [same emitted code as probe 33]
probe 37 liveness; result=MISMATCH; diff=2410; shape=87.96296296296296: H37 promote the reusable DONE and latency records to function scope, testing whether stable protocol-object lifetimes select the original +1c DONE and +10 PONG homes and early ACK reuse.
probe 38 liveness; result=MISMATCH; diff=2411; shape=88.06584362139918: H38 model the binary-proven shared 12-byte ping packet as one function-scope MSGFORMAT_LATENCY object used by bad-ack, command-1, and command-3 arms, testing the Ghidra local_180/local_17c/local_178 overlap.
probe 39 layout; result=MISMATCH; diff=2378; shape=93.93004115226337: H39 order the natural serial store, DCO_SELF read, and command-byte store to match the oracle's proven store/load/store sequence and test whether this also moves cleanup or local reuse.
probe 40 control-flow; result=MISMATCH; diff=1767; shape=94.03292181069959: H40 restore the binary-proven outer else after the K/state guard, enclosing C/A/R/1/3/? dispatch so K packets bypass the later tests and retain AL for the C compare.
probe 41 control-flow; result=MISMATCH; diff=1757; shape=94.129763130793: H41 mirror the original nested ? else and Y else dispatch, keeping command-2/4 and generic delivery under the proven outer K false path.
probe 42 liveness; result=MISMATCH; diff=1874; shape=88.38643371017471: H42 name command-1's turn, Multiplayer flag, initiated timestamp, and command increment before its guard, matching the original EAX/ECX/EBP/EBX load topology and later packet uses.
probe 43 liveness; result=MISMATCH; diff=1824; shape=94.43872296601442: H43 retain only command-1's initiated word across the speed branch, testing the original early EBP value without the frame pressure from three named locals.
probe 44 liveness; result=MISMATCH; diff=1755; shape=94.43872296601442: H44 compute command-1's DONE turn value before the guard, testing the oracle's early turn-plus-increment register value while retaining its late packet store.
probe 45 liveness; result=MISMATCH; diff=1819; shape=94.74768280123584: H45 combine the early DONE turn calculation with the initiated local, testing whether one cross-call value recovers both the oracle's pre-guard arithmetic and EBP message-word home.
probe 46 liveness; result=MISMATCH; diff=1845; shape=88.59198355601234: H46 name the command-1 precomputed execute turn separately from the source turn, testing whether VC5 preserves EAX for turn and EBX for the cross-call DONE value.
probe 47 liveness; result=MISMATCH; diff=1755; shape=94.43872296601442: H47 name only command-1's Multiplayer guard value, testing whether the oracle's ECX guard register appears without the frame pressure of the full local set. [same emitted code as probe 44]
probe 48 liveness; result=MISMATCH; diff=1755; shape=94.43872296601442: H48 name only command-1's narrow command-turn increment, testing whether the oracle's BL load and EBX addition arise without changing frame or guard topology. [same emitted code as probe 47]
```
<!-- end-recovered:a9f632d382e718f8880d -->

<!-- recovered:81c9672fd2455bbb2705 -->
### `912332e8f578` `src/scratch/00427600_PreprocessMessages.cpp:1-69`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 00427600 TCommunications_Handler::PreprocessMessages
// PDB donor: Com_hand.cpp:1281-1920
//
// Canonical reconstruction baseline: the incoming buffer is a byte-oriented
// communications packet.  The common guaranteed header uses command/sequence
// bytes at +0/+1, execute/data turn at +4, and serial at +8.  Ready packets
// have the proven 0x28-byte seven-user/version layout; the local DONE/PONG
// packets are the proven 0x0c-byte command/turn records.  Player identity is
// owned by PlayerOptions.dcoID[10], with the Low/HighPlayerNumber bounds;
// per-player ready/user arrays, LastTurnAck, and PlayerHighSerialNumber are
// named members at their binary offsets.  msg[0] dispatch remains the natural
// period source family of sibling Com_hand.cpp handlers.
//
// ATTEMPT LOG:
// 1 baseline: natural typed packet/member reconstruction; 3384B, frame 0x1B8,
//    86 original versus 91 rebuilt calls.  Canonical ownership and ordered
//    call families were established before tuning.
// 2 behavior: removed an incorrect command-'3' DONE/speed side effect and
//    duplicate GetPlayerName; 3168B, 84 calls, diff improved 3176->2950.
// 3 control-flow: branch-local Chat owner did not change emitted code; kept
//    evidence only while continuing with source review.
// 4 layout: removed an unused local ready packet; frame 0x1B8->0x190.
// 5 layout: scoped disjoint ACK/DONE/PONG/speed/result locals; frame ->0x184.
// 6 liveness: cached Chat before command-'3' logging to preserve the oracle's
//    separate Log/AddChat call sites; 86/86 calls but +44B, so this remains a
//    documented binary-supported context clue rather than a metric-only hack.
// 7 behavior: corrected '?' from a non-host to return at the common final tail.
// 8 layout: moving NextSerialNumber to function scope was codegen-duplicate.
// 9 liveness: delayed the serial pointer until after the second dco lookup;
//    EBX now carries incoming from first, matching the original prologue basin;
//    edit/resync similarity reached 71.84% and size reached 3196B.
// 10 control-flow: delayed player-zero initialization into the from branches;
//    final natural reconstruction is 3200B, frame 0x184, 86/86 calls.
// 11-12 validation/context: replaced the legacy dplay.h surface with the
//    period IDirectPlay2 method order (Send at vslot+0x68); final check remains
//    structural mismatch, not an ABI/call-target mismatch.
// 13-20 (current pass): reused the first player index directly, laid out the
//    missing-DCO failure arm before Send, removed the ready-value byte temp,
//    and tried pointer/temporary lifetime variants.  These recovered the
//    original early call order (84/86 sites, 97.67% aligned in the best CFG
//    layout) and reduced the source to a 3209-byte structural candidate.
//    The remaining blocker is the broad VC5 local/frame basin (0x184 versus
//    original 0x180) plus message/parameter temporary coloring; no ABI or
//    call-target uncertainty remains.  The positive guaranteed-delivery arm
//    is retained because it matches the oracle's late non-GTD LogRXMsg block.
// 21 control-flow: wrote the missing-DCO ProgramState test as a positive
//    success arm with a failure else arm; all 86 call sites now align and the
//    structural diff improved to 2943 bytes.  Keep this natural guard shape.
// Current claim probes 22-30: separate command/serial locals, shared packet
// objects, buffer scopes, serial-cursor scope, and raw packet bytes did not
// improve the pinned result.  The best source is 3192B with the original
// 0x180 frame, 86 aligned calls, 93.42% shape, and 56.35% exact-block coverage.
// BINARY NOTE: the second player scan has a late found edge that writes its
// result home at the function tail, then returns to the common log setup.
// BINARY NOTE: ALL_DONE latency bytes share the proven packet home and must
// remain fields of that record to preserve the original frame and code basin.
// Open blocker: the ack record uses the same shipped local basin as later
// packets in the executable, but VC5 does not select its original [esp+10]
// home from the natural typed source.
// Current claim probes 31-48: naming DCO_SELF and a local DirectPlay receiver
// recovered the original COM setup.  Moving the DCO read between the serial
// and command stores recovered the complete initial block through +149.
// BINARY NOTE: the K/state guard has an outer else.  Its C/A/R/1/3/? dispatch
// is skipped for handled K packets.  The ? and Y paths also use nested else
// arms before command-2 and generic delivery.
// The final natural source has the original frame and size, 86 aligned calls,
// 94.44% shape, and 1755-byte strict difference.  Function-scope packet
// objects, extra named guard values, and narrow increment aliases were either
// worse or codegen duplicates.  H44 retains the early DONE turn expression.
```
<!-- end-recovered:81c9672fd2455bbb2705 -->

<!-- recovered:a0c8330c0d72797d455a -->
### `912332e8f578` `src/scratch/00427600_PreprocessMessages.cpp:124-126`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// DirectPlay 2 is the period interface held at 0062C5EC.  Its named Send
// method is vtable slot 26 (+0x68); keeping the real interface order avoids a
// fabricated dispatch view while preserving the COM __stdcall ABI.
```
<!-- end-recovered:a0c8330c0d72797d455a -->

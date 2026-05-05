// 004EB6F0 TacticalAIGroup::task(TribeTacticalAIModule*, TribeMainDecisionAIModule*, int, int, int)
// Source: taitacmd.cpp lines 735-1481
// First pass from packet/original asm plus Ghidra as a behavior guide; deliberately naturalized loops/call surfaces.
// Attempt log:
// - initial skeleton: modeled proven TacticalAIGroup layout from inventory/types and original asm; kept direct predicate calls and simple 40-slot scans.
// - check_function 2026-04-29: first scaffold compiled but .text was 2832 bytes vs original 5679, too skeletal for byte diff extraction.
// - expanded duplicated natural case bodies/log calls for water/explorer/defend/roundup paths; corrected master_obj->los to +0x28.
// - current check_function: MISMATCH, 4384/5679 positional bytes (77.1967%), first mismatch offset 6.
// - current prologue drift: rebuilt frame is 0x20 and uses EBX for taskID / EBP=-1; original frame is 0x1c and keeps taskID in EBP with EBX zero. Next pass should reduce artificial locals/dead grouped-case code rather than adding more bloat.
// - probe A removed impossible taskID==20 block from case 2/21: kept; eliminated rebuilt EBP=-1 materialization, now immediate cmp -1, but frame/taskID register unchanged.
// - split gather case 9/14: no prologue improvement; kept as less taskID-live source, but behavior/log detail remains approximate.
// - moved broad function-scope locals into case scopes and simplified case 5/6/12/19 dead grouped tests: no frame change; slight positional improvement.
// - inlined floored_hp helper to direct (int)obj->hp because original uses local fld/__ftol not a source helper call; kept though prologue unchanged.
// - current check_function after probes: MISMATCH, 4353/5679 positional bytes (76.6508%), first mismatch offset 6; prologue still frame 0x20 and taskID in EBX.
// - shared original-like locals oHP/distance/min/max added and equivalent hp/distance/XY temps folded into them: no prologue/frame change.
// - removing unused local_4 after shared-local probe also no frame change; frame remains 0x20, so extra slot is not the byte temp alone.
// - reduced remaining taskID liveness in case 2/21 by deleting impossible taskID==20 checks in the body; positional diff improved to 4326/5679 (76.1754%) but prologue unchanged.
// - case0/1 parameter-slot reuse probe: using taskID as totalHP and busyOK as loop index was kept; rebuilt now writes the expected parameter-slot family (shifted by the extra 4-byte frame), but frame/prologue still unchanged.
// - case0/1 unitp[40] store probe kept because it matches original [unitp+0xA0] store and removes rebuilt unitsOriginal pointer temp, though positional diff worsened locally (current 4344/5679).
// - broad zero-local and register unitp probes did not move EBX/taskID or frame; rolled back.
// - temporary deletion of playNumber allocation block did not change 0x20 frame; rolled back, so extra frame slot is not just play-list locals.
// - split case 21 from case 2 to remove taskID use in body gave only tiny positional improvement and no prologue change; current source keeps split but behavior remains approximate.
// - direct owner->id in taskAttacker calls kept; original asm directly loads owner id, no null-owner ternary.
// - case5/6/12/19 HP-only group also converted to taskID/busyOK parameter-slot reuse plus unitp[40], matching original HP-summing topology; prologue unchanged.
// - current check_function: MISMATCH, 4326/5679 positional bytes (76.1754%), first mismatch offset 6; still frame 0x20 vs original 0x1c.
// - moved min/max from shared top-level locals into attack-memory block: frame fixed to original 0x1c and first mismatch moved from offset 6 to 8; kept.
// - broad zero-local probe after frame fix still did not make EBX the zero register; rolled back.
// - converted cases 8/10/11/7/4 to the same taskID/busyOK parameter-slot HP/index reuse and unitp[40] topology; positional diff improved to 4273/5679 (75.2421%), prologue still uses EBX for taskID instead of original EBP.
// - current check_function: MISMATCH, 4273/5679 positional bytes (75.2421%), first mismatch offset 8; frame now matches 0x1c.
// - top-level unitp and taskSlot/address-taken taskID probes did not move EBX/EBP; rolled back.
// - converted cases 8/10/11/7/4 to parameter-slot HP/index reuse; kept, improved positional diff to current 4273 bytes.
// - tried same parameter-slot conversion for case20 but worsened to 4282 bytes and did not affect prologue; rolled back.
// - added binary-observed attack-opening log/play-number checks to case 2 and 21 from original/decomp; kept because it improves behavioral surface and edit-resync equality even though positional diff is essentially unchanged (4274 bytes).
// - recombining case 2/21 as the original source likely did shrank .text below original (5664 vs 5679 before adding other missing details), so rolled back for now; clue says split is not source-faithful but remaining body is still under-modeled.
// - adding full attack-memory waypoint min/max refinement caused a pressure cliff (frame 0x24, first mismatch offset 6); rolled back until the surrounding attack block has the right topology.
// - allocation-failure log in playNumber attack path is binary-observed but perturbed early layout and worsened positional diff to 4308; rolled back for now as a pressure/layout clue.
// - recombined gather case 9/14 per original source shape; kept because behavior/call count is closer and positional diff improved versus the logged attack-open baseline (current 4287/5679), though edit-resync worsened.
// - task-local alias for switch variable produced identical bytes; rolled back, so EBX-vs-EBP prologue drift is not fixed by a simple local copy.
// - current check_function: MISMATCH, 4287/5679 positional bytes (75.4886%), first mismatch offset 8; frame remains correct 0x1c but taskID still in EBX instead of original EBP, and EBX zeroing is still missing.
// - top-level explicit zero local reused through common zero stores produced identical bytes; rolled back.
// - fixed case 2/21 busy gate to match original/decomp: only a 600 action with non-0x1b target type skips, not every non-idle action; behavior kept despite local positional worsening.
// - fixed playNumber path in case 2/21 so individual tasking is skipped while accumulating HP/list for taskPlay; kept, improves positional diff to 4268/5679.
// - retested recombining case 2/21 after playNumber fix: .text shrank drastically (5184 vs 5679), still too under-modeled for a shared source block; rolled back.
// - current check_function: MISMATCH, 4268/5679 positional bytes (75.1541%), first mismatch offset 8.
// - physical case-order probe (moving 7/8 before 20 etc. to match PDB/original block order) improved edit-resync but worsened positional and caused the no-commander return to be outlined; rolled back to current source order for now.
// - binary-proven MainDecision surface kept: player is at +0xF0, informationAI at +0xCEC, time is md->player->world->world_time, and player id comes from md->player->id; this worsens current positional diff but fixes real offsets used in attack/roundup paths.
// - changed gather zone local to int so uchar currentZone/lookupZone returns are masked to 0xff like original; kept as width/topology evidence even though register allocation remains swapped.
// - commander test variants with explicit goto/unsigned + 1: unsigned + 1 restored inline no-commander layout and improved the MD-surface diff to 4293 bytes but generated LEA/TEST instead of original CMP -1; rolled back to natural equality.
// - Investigator byte-zero probe follow-up: zero locals/assignments and (unsigned char)busyOK after busyOK=0 still optimized to an immediate zero or ECX/EBP zero; no EBX zero.
// - direct reset from busyOK (`consecutiveGatherAttemptsValue=(unsigned char)busyOK`) is behaviorally wrong but important evidence: it makes taskID live in EBP and emits `mov [esi+2C8h],bl`/EBP switch, while preserving busyOK in EBX and perturbing the first log argument loads. This suggests the missing lever is not the byte store alone, but creating an EBX byte-capable zero rather than an EBX busyOK.
// - variants using `busyOK-busyOK`, char/uchar zero locals, and zero reused in case initializers either folded to immediate zero or used CL; rolled back.
// - natural case0/1 rewrite with totalHP/i/unitID locals and array indexing instead of parameter-slot/pointer reuse improved positional diff to 4328 but worsened edit-resync equality and did not move the EBX-taskID/EBP-zero prologue; rolled back because original asm's case0 stack-slot/pointer topology is closer to the current parameter-reuse form.
// - current check_function after MD/zone surface fix: MISMATCH, 4342/5679 positional bytes (76.4571%), first mismatch offset 8; prologue still taskID in EBX instead of original EBP and now zero in EBP, so the remaining blocker is whole-function register pressure/topology.
// - explicit fallthrough label did not force original short JNE; restored source-like early no-commander return.
// - case0 declaration-order probe (unitp before obj) produced identical bytes; kept as harmless source-order evidence.
// - assignment-expression/volatile HP accumulation probes in case0/1 did not change scheduling; rolled back to source-like store then add.
// - commander local probe produced identical bytes; kept because it matches decompiler/source pTVar11 but does not fix EBX/EBP allocation.
// - PDB line-map pass: sharing all tails with a resultValue local improved positional only slightly but caused frame 0x20; rolled back result local, kept return-1 shared tail shape.
// - PDB physical order probe: moved case 7/debug_rand block after retreat case 3 to match line map around 938 before later attack cases.
// - PDB physical order probe: moved explorer case 8 after case 7 before attack cases to follow early line-map blocks.
// - PDB physical-order/diff probes plateaued; user requested a full faithful fact-based rewrite pass ignoring local diff. Reordered switch to decompiler/PDB source order: 0/1, shared 2/21, 3, 4, 5/6/12/19, 7, 8, 9/14, 10, 11, 20.
// - local inline/goto firstTime tails for case0/1 perturbed block order badly; rolled back to shared tail despite missing local compare.
// - PDB lines 801/828 show lookupZone gets ftol(y) pushed before ftol(x), meaning source args are (x,y); fixed gather lookups from decompiler-reversed (y,x).
// - PDB/source line-map recombine of attack cases 2/21 shrank .text to 5152/5168, but kept per user request as source-faithful; now filling missing logic instead of optimizing diff.
// - PDB line 877/decomp show gather distance is truncated to int before clamp/priority, not kept as float; changed gather block to int distance topology.
// - faithful rewrite pass: restored decomp-observed retreat logs, attack-memory setup log, case4 split strategic-number branches, and roundup waited-enough/target-location logs rather than chasing local byte diff.
// - faithful rewrite pass: case20 now uses unitp[40] HP topology and includes the pre-subtype unit log plus defender-branch log from decomp.
// - faithful rewrite pass: shared attack case now also writes HP through unitp[40], matching decomp's piVar10[0x28] topology.
// - faithful rewrite pass: case20 busy gate now re-calls currentAction like decomp instead of only testing the saved logged action.
// - faithful rewrite pass: grouped HP/tasking busy logs restored to unit+action varargs; original asm shows the second currentAction result is logged.
// - faithful rewrite pass: shared attack currentAction log restored to pass the action value for the binary-observed CurrentAction %d log.
// - faithful rewrite pass: attack-memory waypoint refinement corrected to compare/replace x bounds with previous waypoint x and y bounds with previous waypoint y per decomp.
// - faithful rewrite pass: case20 currentAction log restored to pass the action value for the binary-observed CurrentAction %d log.
// - faithful rewrite pass: commander/non-commander water/explorer branch logs adjusted to original asm where visible; case7/case10/case11 defender logs carry unit id.
// - faithful rewrite pass: case20 busy log no longer consumes a third currentAction as a vararg; decomp logs the unit id only on busy skip.
// - faithful rewrite pass: placed default before case20 to mirror decompiler/source switch order.
// - faithful rewrite pass: case20 defender-branch log corrected to original unit+target varargs before taskDefender.
// - local_4-only top-y byte probe still caused frame 0x20; rolled back to direct max.y cast while keeping explicit info pointer.
// - restored an explicit informationAI pointer inside attack-memory setup; original asm carries this_00/EBX through mapBound/storeAttackMemory, while avoiding the byte-local pressure cliff.
// - faithful rewrite pass: shared attack body now uses source-like `if (playNumberValue == -1)` wrapper instead of early continue.
// - waypoint-count byte materialization matches decomp but is not kept in source because it created a frame-size pressure cliff; direct expression preserves behavior.
// - pressure/fidelity pass: removed artificial priority local in important-leader defender branch; constant 99 is source-equivalent and may reduce frame pressure.
// - faithful rewrite pass: play-list construction uses source/decomp-like pointer plus countdown loop and shift-size allocation like decomp.
// - pressure/fidelity pass: direct attack-open lastAttackRoundupTime assignment is source-equivalent and reduces artificial local pressure.
// - faithful rewrite pass: roundup current-time local compacted code and was less source-faithful to decomp's reload; rolled back.
// - faithful rewrite pass: owner ids passed to taskAttacker explicitly cast through int like decomp's owner->id use.
// - attack-memory store now materializes player/target owner bytes before the call, matching original byte-load surface.
// - faithful rewrite pass: case20 playNumber handling restored to decomp/original: log and return 0 immediately, unlike attack case taskPlay path.
// - faithful rewrite pass: attack-task logs now mirror original pushes: subtype log includes unit+subtype, target-null log includes unit+target, target log includes unit+target; leader-defender/direct-task logs use no extra unit arg.
// - faithful rewrite pass: gather invalid/out-of-zone path directly removeUnitByIndex; original failure block has no logGroupDebug.
// - introduced distinct mutable log-string placeholders for most logGroupDebug call sites; original source used distinct messages, and this prevents VC5 from merging unrelated log/return blocks.
// - relocation-symbol audit after string split: logs/object/remove/taskDefender/strategic match; re-expanded attack cached-ai calls to align unitAI/currentAction topology.
// - explicit case0/1 firstTime tail probe: exact size restored to 5679 and positional diff improved slightly to 4026/5679; rebuilt now emits the local compare/early return shape, but the shared store-return tail still lands at 004ECC82 instead of original 004ECC06.
// - split attack-family firstTime tail from the generic post-switch store tail (cases 2/21 and 20 now jump to a zero-waypoints tail): slight improvement to 4019/5679 and cleaner original-like separate return families, but the generic store-return tail is still physically too late.
// - corrected return-family facts from original asm: case 0/1, case 8, and case 11 use the store+return-0 tail; case 5/6/12/19 actually join the return-1 store tail despite decompiler noise. This is source-fact cleanup first, though current positional diff is 4056/5679.
// - tried a shared `return_zero_tail_dispatch` to mimic the original local compare/jump shape, but it moved a huge block earlier and worsened to 4071/5679; rolled back.
// - focused variant_lab on only the case0/1 post-loop tail (`build/variant_lab/004EB6F0_task/20260430_105809`): 8 spellings collapsed to 2 asm groups. Best group is the existing store-then-test family (4067/5679, first mismatch 313); split-branch forms all worsened to a context-tail group (4070/5679, first mismatch 110).
// - changed case7 from local firstTime store/return to the shared return-1 tail (`if(firstTime!=1)return 1; goto store_return_one;`): improved positional diff to 4040/5679, though first mismatch moved back to offset 110. Kept as the current best global result.
// - probed case10 indexed loop form, case11 pointer loop form, and store tail label ordering: all compiled to the same 4040/5679 asm family, so these local loop spelling axes are currently saturated.
// - tried making case4 use a local firstTime store/return instead of the shared return-1 tail: worsened to 4072/5679 with first mismatch 313, so rolled back to shared tail.
// - probed default-case local temps to force original-like `idValue` load before vararg pushes; VC5 emitted identical code, rolled back to natural direct log call.
// - corrected case20 tail from zero-waypoint store tail to ordinary store_return_one; original case20 tail stores HP/unit only (zero-waypoint tail belongs earlier attack-family case). Improved 4040 -> 4038.
// - also probed case20 non-firstTime as return 0 to match original branch-to-zero-return shape; kept because behavior/asm tail is closer though total diff remained 4038.
// - tried removing cached case20 UnitAIModule* and using direct obj->unitAI() calls; worsened to 4039, rolled back to cached ai.
// - corrected more firstTime return-family facts from original branch targets: cases 0/1, 4, 7, 8, 10, 11, 2/21, and 20 branch to the common return-one epilogue when firstTime != 1, while firstTime==1 stores original HP/unit and returns 1. Only the grouped HP-only case branches to the zero epilogue/store-return-zero family.
// - probed case5/6/12/19 store-return-zero despite decompiler text; worsened to 4054, confirming original asm's `eax=1` tail. Rolled back.
// - moved gather case 9/14 physically after case0/1 to match original block order (004EB845 immediately follows case0 tail); kept, improved positional 4030->3989 and edit equal 1743->2355.
// - corrected case0/1 firstTime tail after re-reading original asm: firstTime!=1 branches to shared zero epilogue; firstTime==1 stores original HP/unit and returns 1. This improved positional 4003->3966 and edit equality 2994->3442.
// - late shared-zero tail probes: both case11/grouped together improved edit equality but worsened positional; grouped-only worsened both versus case0-zero baseline, so grouped tail rolled back.
// - split store tail with case0 prewriting originalHitPoints shrank .text to 5664 and is wrong; rolled back.
// - physical placement of store_return_one label before case20 compiled to identical bytes; rolled back to keep source cleaner.
// - case0 via oHP-carried store tail improved positional 3966->3945 and emits original local load/store sequence but inlines the tail; kept as a lead.
// - second use of oHP store tail from case20 improved edit equality but worsened positional 3945->4044; rolled back.
// - case7 shared zero-tail goto improved edit equality but worsened positional 3945->4032; rolled back.
// - case8 shared zero-tail goto produced identical bytes; kept as shared-tail source intent.
// - case4 shared zero-tail goto improved edit equality but worsened positional 3945->4010; rolled back.
// - case4 through oHP store tail worsened positional/edit alone; rolled back.
// - focused mini-lab over case4/case7/case10 shared-zero/oHP tails (18 combos): current remains best positional (3945). Best edit combo was c4ohp+c7zero+c10zero at positional 4049/edit 3025; closest default jump was c4ohp+c7zero+c10ohp (rebuilt ja 0x159a vs original 0x159e) but positional worsened to 4103, so not kept.
// - rechecked closest-jump combo separately; it keeps case0 as a jump to a much earlier store tail (004ECA83), explaining better default distance but worse positional layout.
// - moving store_return_one_from_oHP label before case20 compiled identically; busyOK-carried variant for the case0 accumulator also compiled identically. Later case8 truthful tail made direct case0 store_return_one sufficient, so the oHP-carried case0 tail was removed.
// - xref audit: original jumps to store_return_one tail at 004ECC06 from case0 and case8 only; original case4/7/10/11/group tails go to other local/shared tails or zero epilogue. This explains why adding oHP tail users from those cases worsened positional.
// - case8 oHP zero-tail variant compiled identically; current case8 shared-zero + store_return_zero source kept.
// - probing case8 firstTime==1 as store_return_one after xref audit shrank .text to 5648; rolled back despite original tail xref, indicating surrounding case8 source/body still under-modeled or case mapping needs care.
// - case8 pointer-loop/parameter-slot topology from decomp/original (param_1 accumulator, param_3 index, piVar10 pointer) compiled identically with store_return_zero; kept as source-faithful.
// - converted case4 to the same pointer-loop/unitp[40] topology as original/decomp; source-fidelity probe changed only a tiny local byte set while keeping .text 5648.
// - converted case10 to pointer-loop/unitp[40] topology as original/decomp; testing source-fidelity over size.
// - case4 oHP-tail after pointer conversion inflated .text to 5696 and inlined a local store tail rather than matching original 004ECA6B shared tail; rolled back.
// - after case8 was changed to the truthful store_return_one tail, case0 no longer needs the oHP-carried tail: direct `goto store_return_one` emits the desired shared-tail jump sequence. Simplified case0 accordingly.
// - added separate store_return_one_mid for case4/case10, matching original second shared store tail family at 004ECA6B distinct from case0/case8 tail 004ECC06. It worsens current byte metrics and grows .text to 5728, but is a source-fact correction under the new fidelity-first pass.
// - routed case11 non-firstTime through shared zero tail and firstTime path through store_return_one_mid; edit equality improved substantially (2736->3693) while keeping .text 5728, so kept as the next fidelity/layout lead.
// - routed grouped HP-only case5/6/12/19 through shared zero tail/store_return_one_mid; edit diff improved further (3135->3278? lower than prior baseline but edit equal 3687 slightly below case11-only 3693) and this aligns with tail-family direction, so kept for now under fidelity-first pass.
// - original audit correction: the physical block after 004ECA87 (case11 strings) joins the late store tail at 004ECC06, while the following HP-only block stores then returns 0 at 004ECCE2..004ECCF4. Re-routed case11 to store_return_one and grouped case5/6/12/19 to store_return_zero despite metric risk; metrics improved markedly.
// - checked case0/1 inUse store: original loads eax=1 for firstTime compare but stores ebx(0) to [esi+10] at 004EB833, so kept inUseValue=0; local one-temp compare spelling emitted identical code and was rolled back.
// - probed case7 into store_return_one_mid/shared zero; worsened edit equality (3687->3410) and shrank .text to 5696, so rolled back. Case7 likely has a separate/local tail family.
// - converted case20 roundup loop to pointer-loop/busyOK topology with explicit case20_next label; byte metrics nearly unchanged (edit equal 3669 vs 3687) but source shape now matches the other HP loops and decomp better, so kept.
// - probed routing case20 to mid tail under 004EC8D9 hypothesis; metrics worsened badly (edit equal 3773->3335), and 004EC8D9 more likely belongs to case4/case10 family, so rolled case20 back to late store_return_one.
// - tried converting shared attack case2/21 to pointer-loop/busyOK topology; edit equality worsened (3687->3611) and source needed awkward gotos across declarations, so rolled back for now.
// - per xref audit, changed case8 firstTime==1 to store_return_one despite shrinking .text to 5648; size is less important than truthful tail ownership while filling missing logic. This now emits case0/case8 jumps to the shared store tail.
// - changed gather attempt increment from !=0xff to <0xff; kept, matches original CMP/JAE spelling and improves edit equal by one byte.
// - named `one` in case0 firstTime compare produced identical bytes; rolled back.
// - restored gather nearDist/gatherDist to float topology; original asm stores strategicNumber via fild/fstp and keeps distance as float, not int truncation.
// - gather nearDist declaration at case scope swapped gi/nearDist slots ([esp+10]/[esp+30]) and produced identical total diff; rolled back to inner declaration.
// - gather null commander object as explicit goto return_zero_tail produced identical bytes; kept as source documentation of original shared-zero intent.
// - reuse of outer `distance` as gather nearDist moved the loop index to [esp+10] and produced identical total diff; rolled back to preserve original-like loop index slot.
// - gather compare spelling `gatherDist >= nearDist` kept; improves edit equality by one byte and matches original FPU load/test polarity better.
// - probing declaration order `gi; nearDist; unitp` to see if nearDist/loop-index stack slots swap toward original.
// - physical switch-order probe moving attack case 2/21 after case20 worsened positional 4020->4034 and edit equality 2473->2043; rolled back.
// - physical switch-order probe moving retreat case3 before attack case2/21 kept positional 4020 but worsened edit equality 2473->1748; rolled back.
// - physical switch-order probe moving case20 before attack improved positional 4020->3996 but worsened edit equality; kept temporarily as original-label-order lead.
// - physical switch-order probe moving grouped HP-only case5/6/12/19 near end improved positional 3996->3991; kept temporarily.
// - probing full original label order: move cases 3,7,8 before case20.
// - confirmed original jump table order directly from empiresx.exe: 0/1, 9/14, 3, 7, 8, 20, 2/21, 4, 10, 11, 5/6/12/19, default; current physical source order follows it.
// - current validation: MISMATCH, 3884/5679 positional bytes (68.3923%), edit equal 3773, first mismatch offset 313; first 313 bytes are exact.
// - case0 tail variants with duplicate firstTime tests, one/ft locals, volatile firstTime, and explicit taskID reload all compiled to the same cmp-eax-imm/store-before-compare family or worsened.
// - changing case0/8/11 non-firstTime paths to literal return-one is binary/behavior plausible from original epilogue xrefs, but VC5 inlined a local store/return tail near case0 and worsened first mismatch to offset 110; rolled back to preserve current best layout.
// - behavior-fix pass: original branches to 004ECD15 return-one (no xor) for the non-firstTime paths of cases 0/1, 4, 7, 8, 10, 11, 2/21, and 20; updated these from the older zero-tail approximation. Metrics worsen, but this restores the binary-observed return value.
// - case0/1 now uses source-like `break` to a common post-switch firstTime store. This reproduces the original compare/mov-one/cmp/store scheduling for that local tail, though the compiler still places the common tail too early versus original.
// - current validation after behavior/tail fixes: MISMATCH, 4062/5679 positional bytes (71.5267%), edit equal 2922, first mismatch offset 110; local case0 tail bytes now match through the compare/store sequence, but jump-table/default displacement and common-tail placement drift remain.
// - tested making case4/7/8/10/11 individually or collectively `break` to the post-switch store tail: VC5 either inlined the common return near case0 or shrank .text to 5648, all worse; rolled back except case0's source-like break.
// - combined source-like break for case4/case10/case11 plus an explicit case0 non-firstTime return-one guard improves both metrics (4014 positional, 3502 edit equal); kept temporarily.
// - restored case4 to the local `store_return_one_mid` tail too: original has the case4/case10 store/return tail before the next case, and breaking case4 made case10/case11/default blocks too early.
// - re-audited original case20 tail: 004EC189 jumps to return-one on firstTime!=1, but firstTime==1 loads the HP total then joins the zero-waypoint tail at 004EC6FA. Restored case20 to `store_return_one_zero_waypoints` despite a metric regression.
// - current validation after case20 correction: MISMATCH, 4062/5679 positional bytes (71.5267%), edit equal 2567, first mismatch offset 110.
// - restored case10 to its local `store_return_one_mid` tail: original has an inline store/return tail immediately before case11, so breaking case10 to the post-switch tail made all later blocks ~45 bytes early.
// - moved case20 HP-total assignment after the firstTime check to mirror original scheduling (`cmp firstTime,1; mov inUse,1; jne return; load total; join zero-waypoint tail`). This worsens positional slightly but fixes a real local ordering fact.
// - applied the same delayed HP-total assignment to attack case2/21; this is a real original tail fact and improves current metrics to 4013 positional / 3398 edit equal.
// - storedHP temp probes for case7/case8 firstTime tails compiled identically; rolled back.
// - case4/case10 tail audit: original case4 falls through to a firstTime check then jumps to the mid store tail at 004ECA6B; original case10 owns the same mid tail immediately before case11. Restored both to `store_return_one_mid`; current metrics are 4056 positional / 3357 edit equal, first mismatch 110.
// - removing the explicit case10 goto and letting it fall through to `store_return_one_mid` compiled identically; VC5 still moved the mid store tail after case11.
// - tried forcing case4's mid store tail inline with explicit assignments/returns; VC5 still merged it to the later shared tail or worsened layout, so kept the shared label.
// - tried case11 accumulator/index as separate locals and as reused `tactical` parameter slot with a saved tactical pointer; both worsened and did not recover the original case11 stack-slot topology. Restored the simpler taskID/busyOK form.
// - tried routing case11 to store_return_one instead of the post-switch break; this badly worsened edit equality, confirming the source-like break remains the better shape for now.
// - revisited case11 parameter-slot reuse more directly: original uses [esp+30] (incoming tactical parameter slot) as the HP accumulator while preserving the tactical pointer in a register. Kept a local saved tactical pointer plus tactical-as-accumulator form because it improves positional diff substantially and brings the switch default target closer (rebuilt displacement 0x157c vs original 0x159e), even though EBX/EDI coloring is still wrong and needs a later pass.
// - tried the same [esp+30] tactical-parameter-slot accumulator in case4/case10. Direct local store/return improved positional bytes but moved the switch default before later case bodies (rebuilt displacement 0x13ed), contradicting the original jump-table order, so rolled it back to the shared `store_return_one_mid` shape.
// - probed case11 using `taskID` as the loop index to force [esp+38] instead of [esp+40]; stack slot matched that local original clue but positional worsened by one byte with no edit gain, so left the index in `busyOK` for now.

struct UnitAIModule;
struct RGE_Master_Static_Object { char pad_00[0x28]; float los; char pad_2c[0x1e]; short owner_id; };
struct RGE_Game_World { char pad_00[4]; unsigned long world_time; };
struct RGE_Player { char pad_00[0x3c]; RGE_Game_World* world; char pad_40[0xa]; short id; };
struct RGE_Static_Object {
    void* vt; long id; RGE_Master_Static_Object* master_obj; RGE_Player* owner; char pad_10[0x20];
    float hp; char pad_34[4]; float world_x; float world_y; float world_z;
    char pad_44[0x30];
    UnitAIModule* unitAI();
    unsigned char currentZone();
    unsigned char lookupZone(int x, int y);
    float distance_to_position(float x, float y, float z);
};
struct Waypoint { float x, y, z; int a; };
struct XYPoint { int x, y; };
struct TribeInformationAIModule {
    void mapBound(XYPoint* pt);
    void storeAttackMemory(unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, int, unsigned char, unsigned long, int);
};
struct TribeMainDecisionAIModule {
    char pad_00[0xf0]; RGE_Player* player; char pad_f4[0xbf8];
    TribeInformationAIModule informationAI;
    RGE_Static_Object* object(int id);
};
struct UnitAIModule { int currentAction(); int currentOrder(); int currentTargetType(); };

extern int __ftol();
extern int debug_rand(char*, int);
void* operator new(unsigned int);
void operator delete(void*);

static char s_file[] = "C:\\msdev\\work\\age1_x1\\taitacmd.cpp";
static char s0[] = "";
static char s_no_commander[] = "";
static char s_attack_play_alloc_fail[] = "";
static char s_unknown_task[] = "";
static char s_log_00[] = "";
static char s_log_01[] = "";
static char s_log_02[] = "";
static char s_log_03[] = "";
static char s_log_04[] = "";
static char s_log_05[] = "";
static char s_log_06[] = "";
static char s_log_07[] = "";
static char s_log_08[] = "";
static char s_log_09[] = "";
static char s_log_10[] = "";
static char s_log_11[] = "";
static char s_log_12[] = "";
static char s_log_13[] = "";
static char s_log_14[] = "";
static char s_log_15[] = "";
static char s_log_16[] = "";
static char s_log_17[] = "";
static char s_log_18[] = "";
static char s_log_19[] = "";
static char s_log_20[] = "";
static char s_log_21[] = "";
static char s_log_22[] = "";
static char s_log_23[] = "";
static char s_log_24[] = "";
static char s_log_25[] = "";
static char s_log_26[] = "";
static char s_log_27[] = "";
static char s_log_28[] = "";
static char s_log_29[] = "";
static char s_log_30[] = "";
static char s_log_31[] = "";
static char s_log_32[] = "";
static char s_log_33[] = "";
static char s_log_34[] = "";
static char s_log_35[] = "";
static char s_log_36[] = "";
static char s_log_37[] = "";
static char s_log_38[] = "";
static char s_log_39[] = "";
static char s_log_40[] = "";
static char s_log_41[] = "";
static char s_log_42[] = "";
static char s_log_43[] = "";
static char s_log_44[] = "";
static char s_log_45[] = "";
static char s_log_46[] = "";
static char s_log_47[] = "";
static char s_log_48[] = "";
static char s_log_49[] = "";
static char s_log_50[] = "";
static char s_log_51[] = "";
static char s_log_52[] = "";
static char s_log_53[] = "";
static char s_log_54[] = "";
static char s_log_55[] = "";
static char s_log_56[] = "";
static char s_log_57[] = "";
static char s_log_58[] = "";
static char s_log_59[] = "";
static char s_log_60[] = "";
static char s_log_61[] = "";
static char s_log_62[] = "";
static char s_log_63[] = "";
static char s_log_64[] = "";
static char s_log_65[] = "";
static char s_log_66[] = "";
static char s_log_67[] = "";
static char s_log_68[] = "";
static char s_log_69[] = "";
static char s_log_70[] = "";
static char s_log_71[] = "";
static char s_log_72[] = "";
static char s_log_73[] = "";
static char s_log_74[] = "";
static char s_log_75[] = "";
static char s_log_76[] = "";
static char s_log_77[] = "";
static char s_log_78[] = "";
static char s_log_79[] = "";
static char s_log_80[] = "";
static char s_log_81[] = "";
static char s_log_82[] = "";
static char s_log_83[] = "";
static char s_log_84[] = "";
static char s_log_85[] = "";
static char s_log_86[] = "";
static char s_log_87[] = "";
static char s_log_88[] = "";
static char s_log_89[] = "";

struct TribeTacticalAIModule {
    static void logGroupDebug(TribeTacticalAIModule*, int, char*, ...);
    int strategicNumber(int n);
    int calculatePriority(float d);
    int importantGroupLeader(int id);
    void stopUnit(int id, int priority);
    void moveUnit(int id, float x, float y, int priority);
    void taskDefender(int id, int target, float range, int priority);
    void taskAttacker(int id, float x, float y, int target, int owner, Waypoint* wp, unsigned int nwp, int commander, int roundup);
    void taskExplorer(int id, int mode);
    void taskPlay(int commander, int* units, int count, int target, int play, Waypoint* wp, unsigned int nwp);
    void taskWaterFisher(int id, int target, float x, float y);
    void taskWaterTrader(int id, int target);
    void groupGatherUnit(int id, int commander, float x, float y, float z, float dist, int pri);
    void resetAttackSeparationTime();
};

class TacticalAIGroup {
public:
    void* vtable_ptr; TacticalAIGroup* next; TacticalAIGroup* prev; int idValue; int inUseValue;
    int typeValue; int subTypeValue; int unitsValue[40]; int unitsOriginalHitPointsValue[40];
    int numberUnitsValue; int desiredNumberUnitsValue; int commanderValue; int originalHitPointsValue; int originalUnitNumberValue;
    Waypoint locationValue; int actionValue; int targetValue; int targetTypeValue; Waypoint targetLocationValue;
    Waypoint gatherLocationValue; Waypoint retreatLocationValue; int priorityValue; int waitCodeValue;
    int assistGroupIDValue; int assistGroupTypeValue; unsigned long consecutiveIdleUnitCountValue; int playNumberValue;
    unsigned char numberAttackWaypointsValue; unsigned char currentAttackWaypointValue; unsigned char pad_1d6[2];
    Waypoint attackWaypoints[15]; unsigned char consecutiveGatherAttemptsValue; unsigned char pad_2c9[3];
    int numberObjectsToDestroyValue; int objectsToDestroyValue[20]; int objectsToDestroyOwnerValue; int objectsToDestroyCommanderZoneValue;
    unsigned long lastAttackRoundupTime; unsigned long lastAddedUnitTimeValue;

    int removeUnitByIndex(int idx, TribeMainDecisionAIModule* md);
    void setGatherLocation(float x, float y, float z);
    int task(TribeTacticalAIModule* tactical, TribeMainDecisionAIModule* md, int taskID, int firstTime, int busyOK);
};

int TacticalAIGroup::task(TribeTacticalAIModule* tactical, TribeMainDecisionAIModule* md, int taskID, int firstTime, int busyOK)
{
    TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_00, taskID, firstTime, busyOK);

    int commander = commanderValue;
    if (commander == -1) {
        TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_no_commander);
        return 0;
    }

    if (taskID != 9 && taskID != 14)
        consecutiveGatherAttemptsValue = 0;

    int oHP;
    float distance;
    switch (taskID) {
    case 0:
    case 1: {
        int i;
        RGE_Static_Object* obj;
        TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_01);
        taskID = 0;
        for (i = 0; i < 40; ++i) {
            if (unitsValue[i] != -1) {
                TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_02, unitsValue[i]);
                obj = md->object(unitsValue[i]);
                if (obj == 0 || obj->unitAI() == 0) {
                    TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_03, unitsValue[i]);
                    removeUnitByIndex(i, md);
                } else {
                    taskID += (unitsOriginalHitPointsValue[i] = (int)obj->hp);
                    tactical->stopUnit(unitsValue[i], 100);
                }
            }
        }
        inUseValue = 0;
        if (firstTime != 1)
            goto return_one_tail;
        break;
    }


    case 9:
    case 14: {
        if (consecutiveGatherAttemptsValue < 0xff) consecutiveGatherAttemptsValue++;
        RGE_Static_Object* gatherObj = md->object(commanderValue);
        if (gatherObj == 0) goto return_zero_tail;
        int zone = gatherObj->currentZone();
        if (zone != gatherObj->lookupZone((int)gatherLocationValue.x, (int)gatherLocationValue.y))
            setGatherLocation(gatherObj->world_x, gatherObj->world_y, gatherObj->world_z);
        int gi;
        float nearDist;
        int* unitp;
        for (gi = 0, unitp = unitsValue; gi < 40; ++gi, ++unitp) {
            if (*unitp == -1) continue;
            RGE_Static_Object* u = md->object(*unitp);
            if (u != 0 && u->unitAI() != 0 && gatherObj->lookupZone((int)u->world_x, (int)u->world_y) == zone) {
                if (busyOK == 0 && u->unitAI()->currentAction() != -1 && u->unitAI()->currentAction() != 0x266)
                    continue;
                if (taskID == 14)
                    nearDist = 0.0f;
                else
                    nearDist = (float)tactical->strategicNumber(0x29);
                float gatherDist = u->distance_to_position(gatherLocationValue.x, gatherLocationValue.y, gatherLocationValue.z) - 1.0f;
                if (gatherDist < 0.0f) gatherDist = 0.0f;
                if (gatherDist >= nearDist)
                    tactical->groupGatherUnit(*unitp, commanderValue, gatherLocationValue.x, gatherLocationValue.y, gatherLocationValue.z, nearDist, tactical->calculatePriority(gatherDist));
                else if (u->unitAI()->currentOrder() != -1)
                    tactical->stopUnit(*unitp, 100);
            } else {
                removeUnitByIndex(gi, md);
            }
        }
        return 1;
    }






    case 3: {
        int i;
        int* unitp;
        RGE_Static_Object* obj;
        TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_19);
        TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_20, retreatLocationValue.x, retreatLocationValue.y);
        for (i = 0, unitp = unitsValue; i < 40; ++i, ++unitp) {
            if (*unitp == -1) continue;
            TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_21, *unitp);
            obj = md->object(*unitp);
            if (obj == 0 || obj->unitAI() == 0) {
                TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_22, *unitp);
                removeUnitByIndex(i, md);
                continue;
            }
            distance = obj->distance_to_position(retreatLocationValue.x, retreatLocationValue.y, retreatLocationValue.z) - 1.0f;
            if (distance < 0.0f) distance = 0.0f;
            if (obj->master_obj->los * 0.33333334f <= distance) {
                TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_23, *unitp);
                tactical->moveUnit(*unitp, retreatLocationValue.x, retreatLocationValue.y, 100);
            } else {
                TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_24, obj->master_obj);
            }
        }
        return 1;
    }




    case 7: {
        int* unitp;
        RGE_Static_Object* obj;
        TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_32);
        int roll = debug_rand(s_file, 0x3af) % 100;
        taskID = 0;
        busyOK = 0;
        unitp = unitsValue;
        do {
            if (*unitp != -1) {
                TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_33, *unitp);
                obj = md->object(*unitp);
                if (obj == 0 || obj->unitAI() == 0) {
                    TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_34, *unitp);
                    removeUnitByIndex(busyOK, md);
                } else {
                    oHP = ((int)obj->hp);
                    unitp[40] = oHP;
                    taskID += oHP;
                    if (busyOK == 0 && obj->unitAI()->currentAction() != -1) {
                        int busyAction = obj->unitAI()->currentAction();
                        TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_35, *unitp, busyAction);
                    } else if (*unitp == commanderValue) {
                        TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_36, *unitp);
                        tactical->taskExplorer(*unitp, 0);
                    } else if (roll < tactical->strategicNumber(200)) {
                        TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_37, *unitp);
                        tactical->taskDefender(*unitp, commanderValue, obj->master_obj->los * 0.5f, 99);
                    } else {
                        TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_38, *unitp);
                        tactical->taskExplorer(*unitp, 0);
                    }
                }
            }
            ++unitp;
            ++busyOK;
        } while (busyOK < 40);
        inUseValue = 1;
        if (firstTime != 1)
            goto return_one_tail;
        goto store_return_one;
    }




    case 8: {
        int* unitp;
        RGE_Static_Object* obj;
        TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_39);
        taskID = 0;
        busyOK = 0;
        unitp = unitsValue;
        do {
            if (*unitp != -1) {
                TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_40, *unitp);
                obj = md->object(*unitp);
                if (obj == 0 || obj->unitAI() == 0) {
                    TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_41, *unitp);
                    removeUnitByIndex(busyOK, md);
                } else {
                    oHP = ((int)obj->hp);
                    unitp[40] = oHP;
                    taskID += oHP;
                    if (busyOK == 0 && obj->unitAI()->currentAction() != -1) {
                        int busyAction = obj->unitAI()->currentAction();
                        TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_42, *unitp, busyAction);
                    } else {
                        tactical->taskExplorer(*unitp, 0);
                    }
                }
            }
            ++unitp;
            ++busyOK;
        } while (busyOK < 40);
        inUseValue = 1;
        if (firstTime != 1)
            goto return_one_tail;
        goto store_return_one;
    }






    case 20: {
        TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_55, targetValue);
        TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_56, targetLocationValue.x, targetLocationValue.y);
        int waited = (int)(md->player->world->world_time - lastAttackRoundupTime) / 1000;
        if (waited < 10) { TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_57, waited); return 0; }
        TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_58, waited);
        lastAttackRoundupTime = md->player->world->world_time;
        if (playNumberValue != -1) {
            TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_59);
            return 0;
        }
        int stored20 = 0;
        busyOK = 0;
        int* unitp;
        RGE_Static_Object* obj;
        UnitAIModule* ai;
        int action20;
        unitp = unitsValue;
        do {
            if (*unitp == -1) goto case20_next;
            TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_60, *unitp);
            obj = md->object(*unitp);
            if (obj == 0 || obj->unitAI() == 0) { TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_61, *unitp); removeUnitByIndex(busyOK, md); goto case20_next; }
            ai = obj->unitAI();
            action20 = ai->currentAction();
            TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_62, action20);
            oHP = ((int)obj->hp); unitp[40] = oHP; stored20 += oHP;
            if (busyOK == 0 && ai->currentAction() != -1) { TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_63, *unitp); goto case20_next; }
            TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_64, *unitp);
            if (subTypeValue == 0 || subTypeValue == 4) {
                TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_65, *unitp, targetValue);
                tactical->taskDefender(*unitp, targetValue, 2.0f, 100);
            } else {
                RGE_Static_Object* targ20 = md->object(targetValue);
                if (targ20 == 0) {
                    TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_66);
                } else {
                    TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_67, targetValue);
                    tactical->taskAttacker(*unitp, targetLocationValue.x, targetLocationValue.y, targetValue, (int)targ20->owner->id, attackWaypoints, numberAttackWaypointsValue, commanderValue, 1);
                }
            }
case20_next:
            ++unitp;
            ++busyOK;
        } while (busyOK < 40);
        inUseValue = 1;
        if (firstTime != 1)
            goto return_one_tail;
        taskID = stored20;
        goto store_return_one_zero_waypoints;
    }



    case 2:
    case 21: {
        TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_04, targetValue);
        TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_05, targetLocationValue.x, targetLocationValue.y);
        if (playNumberValue == -1)
            TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_06);
        else
            TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_07, playNumberValue);
        lastAttackRoundupTime = md->player->world->world_time;
        int stored = 0;
        int madeMemory = 1;
        int i;
        int* unitp;
        RGE_Static_Object* obj;
        UnitAIModule* ai;
        for (i = 0, unitp = unitsValue; i < 40; ++i, ++unitp) {
            if (*unitp == -1) continue;
            TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_08, *unitp);
            obj = md->object(*unitp);
            if (obj == 0 || obj->unitAI() == 0) {
                TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_09, *unitp);
                removeUnitByIndex(i, md);
                continue;
            }
            ai = obj->unitAI();
            int action = obj->unitAI()->currentAction();
            TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_10, action);
            oHP = ((int)obj->hp); unitp[40] = oHP; stored += oHP;
            if (playNumberValue == -1) {
            if (busyOK == 0) {
                if (obj->unitAI()->currentAction() == 600 && obj->unitAI()->currentTargetType() != 0x1b) {
                    TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_11, *unitp);
                    continue;
                }
            }
            TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_12, *unitp, subTypeValue);
            if (subTypeValue == 0 || subTypeValue == 4) {
                TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_13, *unitp);
                tactical->taskDefender(*unitp, targetValue, 2.0f, 100);
            } else {
                RGE_Static_Object* targ = md->object(targetValue);
                if (targ == 0) {
                    TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_14, *unitp, targetValue);
                    continue;
                }
                if (madeMemory) {
                    TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_15);
                    XYPoint min;
                    XYPoint max;
                    TribeInformationAIModule* info = &md->informationAI;
                    min.x = (int)targ->world_x - 7;
                    min.y = (int)targ->world_y - 7;
                    info->mapBound(&min);
                    max.x = (int)targ->world_x + 7;
                    max.y = (int)targ->world_y + 7;
                    info->mapBound(&max);
                    if (numberAttackWaypointsValue > 1) {
                        Waypoint* prev = &attackWaypoints[numberAttackWaypointsValue - 2];
                        if ((float)min.x <= prev->x)
                            max.x = (int)prev->x;
                        else
                            min.x = (int)prev->x;
                        if ((float)min.y <= prev->y)
                            max.y = (int)prev->y;
                        else
                            min.y = (int)prev->y;
                    }
                    unsigned char myID = (unsigned char)md->player->id;
                    unsigned char targetOwnerID = (unsigned char)targ->owner->id;
                    info->storeAttackMemory(0, (unsigned char)min.x, (unsigned char)min.y, (unsigned char)max.x, (unsigned char)max.y, myID, targetOwnerID, 0, 0, md->player->world->world_time, -1);
                    tactical->resetAttackSeparationTime(); madeMemory = 0;
                }
                TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_16, *unitp, targetValue);
                if (*unitp == commanderValue || tactical->importantGroupLeader(commanderValue) == 0 || tactical->strategicNumber(0x79) == 0) {
                    TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_17);
                    if (taskID == 21)
                        tactical->moveUnit(*unitp, targetLocationValue.x, targetLocationValue.y, 100);
                    else
                        tactical->taskAttacker(*unitp, targetLocationValue.x, targetLocationValue.y, targetValue, (int)targ->owner->id, attackWaypoints, numberAttackWaypointsValue, commanderValue, 0);
                } else {
                    TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_18);
                    int range = tactical->strategicNumber(0x83);
                    tactical->taskDefender(*unitp, commanderValue, (float)range, 99);
                }
            }
            }
        }
        if (playNumberValue != -1) {
            int* list = (int*)operator new(numberUnitsValue << 2);
            if (list != 0) {
                int* scan = unitsValue;
                int count = 40;
                int* out = list;
                do {
                    if (*scan != -1) *out++ = *scan;
                    ++scan;
                    --count;
                } while (count != 0);
                tactical->taskPlay(commanderValue, list, numberUnitsValue, targetValue, playNumberValue, attackWaypoints, numberAttackWaypointsValue);
                operator delete(list);
            } else {
                TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_attack_play_alloc_fail);
            }
            return 0;
        }
        inUseValue = 1;
        if (firstTime != 1)
            goto return_one_tail;
        taskID = stored;
        goto store_return_one_zero_waypoints;
    }


    case 4: {
        int* unitp;
        RGE_Static_Object* obj;
        TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_25, targetValue, targetLocationValue.x, targetLocationValue.y);
        taskID = 0;
        busyOK = 0;
        unitp = unitsValue;
        do {
            if (*unitp != -1) {
                TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_26, *unitp);
                obj = md->object(*unitp);
                if (obj == 0 || obj->unitAI() == 0) {
                    TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_27, *unitp);
                    removeUnitByIndex(busyOK, md);
                } else {
                    oHP = ((int)obj->hp);
                    unitp[40] = oHP;
                    taskID += oHP;
                    if (busyOK == 0 && obj->unitAI()->currentAction() != -1) {
                        int busyAction = obj->unitAI()->currentAction();
                        TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_28, *unitp, busyAction);
                    } else {
                        int defDist = (int)obj->distance_to_position(targetLocationValue.x, targetLocationValue.y, targetLocationValue.z);
                        int pri = tactical->calculatePriority((float)defDist);
                        if (targetTypeValue == 0x6d) {
                            int sn = tactical->strategicNumber(0x16);
                            tactical->taskDefender(*unitp, targetValue, (float)sn, pri);
                        } else {
                            int sn = tactical->strategicNumber(0x39);
                            tactical->taskDefender(*unitp, targetValue, (float)sn, pri);
                        }
                    }
                }
            }
            ++unitp;
            ++busyOK;
        } while (busyOK < 40);
        inUseValue = 1;
        if (firstTime != 1)
            goto return_one_tail;
        goto store_return_one_mid;
    }





    case 10: {
        int* unitp;
        RGE_Static_Object* obj;
        TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_43);
        taskID = 0;
        busyOK = 0;
        unitp = unitsValue;
        do {
            if (*unitp != -1) {
                TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_44, *unitp);
                obj = md->object(*unitp);
                if (obj == 0 || obj->unitAI() == 0) {
                    TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_45, *unitp);
                    removeUnitByIndex(busyOK, md);
                } else {
                    oHP = ((int)obj->hp);
                    unitp[40] = oHP;
                    taskID += oHP;
                    if (busyOK == 0 && obj->unitAI()->currentAction() != -1) {
                        int busyAction = obj->unitAI()->currentAction();
                        TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_46, *unitp, busyAction);
                    } else if (*unitp == commanderValue) {
                        TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_47, *unitp);
                        tactical->taskWaterFisher(*unitp, targetValue, targetLocationValue.x, targetLocationValue.y);
                    } else {
                        TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_48, *unitp);
                        tactical->taskDefender(*unitp, commanderValue, obj->master_obj->los * 0.5f, 99);
                    }
                }
            }
            ++unitp;
            ++busyOK;
        } while (busyOK < 40);
        inUseValue = 1;
        if (firstTime != 1)
            goto return_one_tail;
        goto store_return_one_mid;
    }

store_return_one_mid:
    originalHitPointsValue = taskID;
    originalUnitNumberValue = numberUnitsValue;
    return 1;

    case 11: {
        int* unitp;
        RGE_Static_Object* obj;
        TribeTacticalAIModule* tt = tactical;
        TribeTacticalAIModule::logGroupDebug(tt, idValue, s_log_49);
        tactical = (TribeTacticalAIModule*)0;
        busyOK = 0;
        unitp = unitsValue;
        do {
            if (*unitp != -1) {
                TribeTacticalAIModule::logGroupDebug(tt, idValue, s_log_50, *unitp);
                obj = md->object(*unitp);
                if (obj == 0 || obj->unitAI() == 0) {
                    TribeTacticalAIModule::logGroupDebug(tt, idValue, s_log_51, *unitp);
                    removeUnitByIndex(busyOK, md);
                } else {
                    oHP = ((int)obj->hp);
                    unitp[40] = oHP;
                    tactical = (TribeTacticalAIModule*)((int)tactical + oHP);
                    if (busyOK == 0 && obj->unitAI()->currentAction() != -1) {
                        int busyAction = obj->unitAI()->currentAction();
                        TribeTacticalAIModule::logGroupDebug(tt, idValue, s_log_52, *unitp, busyAction);
                    } else if (*unitp == commanderValue) {
                        TribeTacticalAIModule::logGroupDebug(tt, idValue, s_log_53, *unitp);
                        tt->taskWaterTrader(*unitp, targetValue);
                    } else {
                        TribeTacticalAIModule::logGroupDebug(tt, idValue, s_log_54, *unitp);
                        tt->taskDefender(*unitp, commanderValue, obj->master_obj->los * 0.5f, 99);
                    }
                }
            }
            ++unitp;
            ++busyOK;
        } while (busyOK < 40);
        inUseValue = 1;
        if (firstTime != 1)
            goto return_one_tail;
        originalHitPointsValue = (int)tactical;
        originalUnitNumberValue = numberUnitsValue;
        return 1;
    }



    case 5:
    case 6:
    case 12:
    case 19: {
        int* unitp;
        RGE_Static_Object* obj;
        TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_29);
        taskID = 0;
        busyOK = 0;
        unitp = unitsValue;
        do {
            if (*unitp != -1) {
                TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_30, *unitp);
                obj = md->object(*unitp);
                if (obj == 0 || obj->unitAI() == 0) {
                    TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_log_31, *unitp);
                    removeUnitByIndex(busyOK, md);
                } else {
                    oHP = ((int)obj->hp);
                    unitp[40] = oHP;
                    taskID += oHP;
                }
            }
            ++unitp;
            ++busyOK;
        } while (busyOK < 40);
        inUseValue = 1;
        if (firstTime != 1)
            goto return_zero_tail;
        goto store_return_zero;
    }





    default:
        TribeTacticalAIModule::logGroupDebug(tactical, idValue, s_unknown_task, taskID);
        return 0;


    }

    if (firstTime == 1) {
        originalHitPointsValue = taskID;
        originalUnitNumberValue = numberUnitsValue;
    }
    return 1;

return_one_tail:
    return 1;

return_zero_tail:
    return 0;




store_return_one:
    originalHitPointsValue = taskID;
    originalUnitNumberValue = numberUnitsValue;
    return 1;

store_return_zero:
    originalHitPointsValue = taskID;
    originalUnitNumberValue = numberUnitsValue;
    return 0;


store_return_one_zero_waypoints:
    originalHitPointsValue = taskID;
    originalUnitNumberValue = numberUnitsValue;
    numberAttackWaypointsValue = 0;
    return 1;
}

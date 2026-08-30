# Function notes: 0044A100 `delta_flc`

Module notes: `decomp_notes/flics_module.md`.

## Recovered attempt history

<!-- recovered:3f738cc563b368e6282e -->
### `target-session` `build/target_sessions/0044A100_delta_flc.json:1-72`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=367; shape=71.31782945736434: Clean natural ushort decoder source from prior attempt log; establish current metrics and mismatch stage.
probe 2 control-flow; result=MISMATCH; diff=368; shape=72.09302325581395: Changed packet cursor to binary-supported byte cursor with explicit packed word header reads and byte payload advances; test original inc/add cursor basin.
probe 3 liveness; result=MISMATCH; diff=378; shape=66.91176470588235: Removed redundant scan cursor; original CFG uses one advancing packet cursor through header, skip, and literal branches.
probe 4 liveness; result=MISMATCH; diff=382; shape=67.16417910447761: Compare one-cursor natural ushort source against two-cursor baseline; test whether cursor lifetime colors EBP without byte-pointer constant basin.
probe 6 liveness; result=MISMATCH; diff=390; shape=62.7906976744186: Test binary-observed cur_y stack home as volatile source axis to free EBP for packet cursor; retain only if natural emitted topology improves.
probe 8 layout; result=MISMATCH; diff=371; shape=73.48484848484848: Use natural byte stream cursor initialized from chunk before line header; packet headers use packed words and packet bytes use post-increment cursor.
probe 9 liveness; result=MISMATCH; diff=371; shape=73.48484848484848: Reorder natural byte cursor declaration before cur_y while preserving observed zero-before-chunk initialization; test allocator color axis. [same emitted code as probe 8]
probe 10 context; result=MISMATCH; diff=371; shape=73.48484848484848: Restore full canonical RGE_Flic_Player declaration from exact same-TU delta_fli donor; test whether class surface selects original allocator basin. [same emitted code as probe 9]
probe 12 liveness; result=MISMATCH; diff=367; shape=71.31782945736434: Split cur_y declaration from its zero assignment; original line 367 store may reflect delayed initialization rather than initializer syntax. [same emitted code as probe 1]
probe 13 abi; result=MISMATCH; diff=367; shape=71.31782945736434: Model packet count as signed short, matching original signed test and packet-count semantics; test register/color and width lowering. [same emitted code as probe 12]
probe 15 layout; result=MISMATCH; diff=377; shape=70.54263565891473: Remove payload alias and advance the natural ushort packet cursor in place; test whether source expression restores original rep-copy setup.
probe 17 control-flow; result=MISMATCH; diff=377; shape=71.96969696969697: Test one natural byte stream cursor for headers and packet post-increments, with no redundant scan or payload aliases.
probe 18 liveness; result=MISMATCH; diff=377; shape=71.96969696969697: Register-qualify the natural byte stream cursor; test whether VC5 honors the binary-observed callee-saved cursor color. [same emitted code as probe 17]
probe 20 liveness; result=MISMATCH; diff=373; shape=64.12213740458016: Diagnostic only: remove dead cur_y source effects to observe whether EBP then colors the packet cursor; do not retain without exact binary stores.
probe 22 variant; result=MISMATCH; diff=373; shape=64.12213740458016: variant lab build\variant_lab\0044A100_delta_flc\20260816_231112: 64 variants, 0 invariant-eligible, 0 exact
probe 23 control-flow; result=MISMATCH; diff=379; shape=72.86821705426357: Use separate byte post-increments for all two-byte headers while retaining one byte packet cursor; test whether VC5 merges header adds but avoids EBP constant.
probe 28 control-flow; result=MISMATCH; diff=390; shape=63.565891472868216: Move packet-count zeroing into each natural scan iteration, matching original per-scan XOR before code classification; test loop source topology.
probe 30 control-flow; result=MISMATCH; diff=395; shape=62.7906976744186: Use the natural packet-count temporary as the zero classifier operand (top == packets), matching original sub type,packets while retaining typed loops.
probe 32 control-flow; result=MISMATCH; diff=373; shape=69.76744186046511: Replace scan alias with one natural ushort cursor and post-incremented header reads; test whether VC5 assigns packet cursor to EBP without raw plumbing.
probe 33 layout; result=MISMATCH; diff=373; shape=69.76744186046511: Split natural ushort header post-increments into explicit cursor assignment, avoiding a compiler-held constant while retaining typed packet decode. [same emitted code as probe 32]
probe 34 abi; result=MISMATCH; diff=373; shape=69.76744186046511: Name the proven chunk field once, then derive the typed ushort cursor and line count from that owner; test natural shared-load ownership and register color. [same emitted code as probe 33]
probe 36 layout; result=MISMATCH; diff=377; shape=71.7557251908397: Use one natural byte stream cursor with typed ushort header and payload accesses, matching proven packet effects without aliases.
probe 37 abi; result=MISMATCH; diff=377; shape=71.7557251908397: Change the proven byte-stream owner to signed char pointer, matching period source cursor semantics while keeping explicit typed word accesses. [same emitted code as probe 36]
probe 38 layout; result=MISMATCH; diff=377; shape=71.96969696969697: Align local declaration and initializer order with same-TU FLIC decoder: cur_y first, then initialized byte cursor, then short line count and two-byte advance. [same emitted code as probe 18]
probe 40 layout; result=MISMATCH; diff=379; shape=72.86821705426357: Use a typed ushort stream owner with a local byte view only for byte packet fields; test period-plausible typed cursor ownership against the proven EBP stream.
probe 42 liveness; result=MISMATCH; diff=367; shape=71.31782945736434: Reorder only natural local declarations so cur_y is initialized before packet cursor declaration, matching original PDB line ordering without adding effects. [same emitted code as probe 27]
probe 45 layout; result=MISMATCH; diff=367; shape=71.31782945736434: Move decoder scalar and pointer declarations to function scope, matching the decompiler's C89-style local surface; test whether original EBP cursor and stack-home topology return. [same emitted code as probe 44]
probe 47 control-flow; result=MISMATCH; diff=373; shape=69.76744186046511: Use one natural ushort stream cursor for the classifier, matching the period decoder's sequential header reads without a separate scan alias. [same emitted code as probe 34]
probe 49 liveness; result=MISMATCH; diff=373; shape=69.76744186046511: Keep the classifier's natural scan cursor as the advancing owner, then assign the packet stream cursor after the guard; test whether VC5 coalesces the proven EBP stream lifetime. [same emitted code as probe 47]
probe 52 control-flow; result=MISMATCH; diff=386; shape=66.17647058823529: Structural decompiler-form hypothesis: use one natural ushort cursor for classifier and packets, reset packets per classifier iteration, and wrap the positive outer run in if(lines > 0). This tests the original EBP cursor and per-scan packet reset topology.
probe 54 liveness; result=MISMATCH; diff=390; shape=63.565891472868216: Reset the natural packet-count temporary inside each classifier scan iteration, as the original emits xor edi,edi after every header load. Keep the proven two-cursor source and outer loop unchanged. [same emitted code as probe 28]
probe 56 control-flow; result=MISMATCH; diff=371; shape=56.15384615384615: Adopt the locally recovered verified Ghidra-form decoder: one persistent puVar8 stream, short classifier locals, per-scan packet reset, branch-local save-buffer base, and one local_4 outer countdown. Retain binary-proven cur_y state.
probe 57 abi; result=MISMATCH; diff=371; shape=56.15384615384615: Change only the recovered decoder's stream owner from ushort* to char*, preserving its one-cursor control flow and explicit word/byte accesses. This tests the sibling delta_fli period cursor ABI as the cause of the missing EBP stream basin. [same emitted code as probe 56]
probe 59 layout; result=MISMATCH; diff=367; shape=71.31782945736434: Initialize the persistent packet cursor before reading the signed line count, then advance it once. This mirrors exact sibling delta_fli's  ownership and tests whether source load ownership selects the original EBP cursor without changing decoder control flow. [same emitted code as probe 51]
probe 60 layout; result=MISMATCH; diff=371; shape=56.15384615384615: Use the recovered decoder with one stream pointer loaded before the line-count read, matching exact delta_fli's pointer ownership. Keep the binary-proven cur_y stack state and old-source loop structure. [same emitted code as probe 57]
probe 61 liveness; result=MISMATCH; diff=371; shape=56.15384615384615: Add a period-plausible register hint to the persistent stream owner in the recovered decoder. Test whether VC5 honors the binary-proven callee-saved EBP cursor when source structure already matches the decomp form. [same emitted code as probe 60]
probe 62 control-flow; result=MISMATCH; diff=365; shape=56.06060606060606: Replace classifier if/else with a sparse switch over the proven top two-bit code. The original subtract/dec chain is a distinct switch-like lowering candidate; retain all natural packet and cursor effects.
probe 63 abi; result=MISMATCH; diff=365; shape=56.06060606060606: Keep the switch classifier but represent its found flag as an unsigned char, matching the binary BL liveness instead of a compiler-spilled bool. This isolates the flag width from switch control flow. [same emitted code as probe 62]
probe 64 abi; result=MISMATCH; diff=353; shape=56.58914728682171: Retain the sparse switch but restore the natural ushort stream owner and word-based cursor increments. This tests whether the original EBP/EDI topology needs typed packed-word pointers rather than byte cursors.
probe 65 liveness; result=MISMATCH; diff=353; shape=56.58914728682171: Promote the switch classifier's found byte to function scope, resetting it per outer line. This tests whether the original BL lifetime is a loop-level local rather than a block-local switch result. [same emitted code as probe 64]
probe 66 liveness; result=MISMATCH; diff=353; shape=56.58914728682171: Address-take the binary-proven cur_y stack local and use one alias for its two updates. This tests whether forcing its stack ownership frees EBP for the stream cursor without adding memory effects. [same emitted code as probe 65]
probe 67 abi; result=MISMATCH; diff=365; shape=55.303030303030305: Use a raw int* stream owner with explicit byte offsets around proven packed words. This tests the exact sibling delta_fli pointer-width basin while retaining switch CFG and cur_y stack effects.
probe 68 liveness; result=MISMATCH; diff=378; shape=59.3984962406015: Remove the semantically dead cur_y updates while keeping the recovered switch and ushort cursor. This tests whether compiler-preserved cur_y stack traffic is a source artifact or required structural state.
probe 71 liveness; result=MISMATCH; diff=390; shape=63.565891472868216: Move packet zeroing after the classifier word load, matching the original 0044A12C/0044A130 order. Test whether this restores EBP as the persistent stream cursor and EDI as packet count. [same emitted code as probe 54]
probe 73 control-flow; result=MISMATCH; diff=373; shape=69.76744186046511: Use one natural ushort classifier cursor with the existing if-chain. This removes the redundant scan alias while preserving every packed word and packet boundary. [same emitted code as probe 49]
probe 74 abi; result=MISMATCH; diff=373; shape=69.76744186046511: Keep the one-cursor classifier, but spell packed-word cursor steps as byte-base plus two. Test whether VC5 emits the original immediate add on the persistent cursor instead of EBP as a constant two. [same emitted code as probe 73]
probe 76 control-flow; result=MISMATCH; diff=367; shape=70.54263565891473: Restore the decompiler-proven outer if/do loop: decrement the original line-count local instead of copying it to a remaining local and returning early.
probe 78 layout; result=MISMATCH; diff=367; shape=71.31782945736434: Match the donor local declaration order: pointer and line count first, then cur_y with an explicit zero assignment before the chunk read. [same emitted code as probe 70]
probe 80 liveness; result=MISMATCH; diff=372; shape=69.76744186046511: Model the original packet output alias: preserve the pre-offset window pointer, advance the member, then copy positive runs through the advanced local output pointer.
probe 82 layout; result=MISMATCH; diff=367; shape=71.31782945736434: Advance the packed stream to the payload pointer before both packet branches, then advance from that pointer. This follows the donor decompiler's puVar7/puVar8 lifetime. [same emitted code as probe 78]
probe 84 abi; result=MISMATCH; diff=367; shape=71.31782945736434: Use a natural byte stream cursor for packed FLIC words, with explicit word casts and byte offsets. Test whether the original EBP stream-cursor allocation follows the packed source surface. [same emitted code as probe 82]
probe 86 liveness; result=MISMATCH; diff=367; shape=71.31782945736434: Use the donor's bool classifier flag rather than an unsigned-char flag. Test whether VC5 changes packet and stream register coloring without changing the classifier CFG. [same emitted code as probe 84]
probe 88 layout; result=MISMATCH; diff=367; shape=71.31782945736434: Initialize the packed stream cursor before reading the signed line count, then advance it by one word. This directly models the original EBP load/read/add prologue. [same emitted code as probe 86]
probe 89 abi; result=MISMATCH; diff=373; shape=68.9922480620155: Remove the payload pointer alias and express packet data as p+1. Test whether fewer pointer locals promote the persistent stream cursor to EBP.
probe 91 abi; result=MISMATCH; diff=326; shape=70.76923076923077: Widen only the classifier packet-count temporary to int. Test whether VC5 assigns packet count to EDI and the stream cursor to EBP while retaining the original ushort packet value.
probe 92 control-flow; result=MISMATCH; diff=381; shape=71.31782945736434: Combine the widened packet count with one natural ushort classifier cursor. Test whether this removes the scan stack home and reproduces the original EDI packet and EBP stream roles.
probe 94 liveness; result=MISMATCH; diff=354; shape=68.42105263157895: Test a full-width packet count without the signed-short narrowing at the branch and packet-loop entry. This checks whether the original EDI counter was a full int with only 16-bit packet writes.
probe 98 layout; result=MISMATCH; diff=367; shape=71.31782945736434: Test one natural packed ushort owner: read the signed line count through the same cursor, then pre-increment it before the first classifier word. This tests whether the original EBP stream owner comes from one continuous cursor without changing decoder effects.
probe 100 control-flow; result=MISMATCH; diff=373; shape=68.9922480620155: Test one natural ushort stream cursor with the classifier and packet loop advancing the same cursor, inside the proven positive line-count guard. This removes the scan alias and tests the original EBP stream lifetime while keeping signed widths and byte publication order.
probe 102 layout; result=MISMATCH; diff=379; shape=70.54263565891473: Test a single natural ushort cursor rooted at the packed line-count word: read the signed count through p, pre-increment once, then use p for classifier and packet data. This tests whether the original EBP stream ownership follows the full packed stream lifetime.
probe 103 control-flow; result=MISMATCH; diff=373; shape=66.66666666666667: Test a natural switch classifier on the single packed cursor. Switch lowering is binary-supported by the subtract/decrement dispatch; this also removes the shared literal-2 register pressure while preserving all malformed-input and skip effects.
probe 105 liveness; result=MISMATCH; diff=367; shape=71.31782945736434: Retry recorded check for the PDB-ordered cur_y-before-stream declaration test. The variant was codegen-identical to the pinned clean source, so declaration order alone does not control the EBP basin. [same emitted code as probe 98]
probe 107 abi; result=MISMATCH; diff=367; shape=71.31782945736434: Record the local chunk-owner test: caching this->chunk and deriving both count and stream is codegen-identical to the clean source, so this ABI spelling does not control the EBP allocation. [same emitted code as probe 105]
probe 109 liveness; result=MISMATCH; diff=367; shape=71.31782945736434: Test the binary-supported classifier result lifetime from Ghidra: make the ushort packet result function-scope, reset it per line, and keep the natural two-cursor decoder. This tests whether packet-result liveness swaps EDI with the original EBP stream cursor. [same emitted code as probe 107]
probe 111 liveness; result=MISMATCH; diff=382; shape=59.689922480620154: Test a period-plausible full function-scope reconstruction from the PDB/Ghidra local order: cVar1, packed code/top/result, found flag, copy counters, two cursors, destination, cur_y, packet count, and line count. Preserve cur_y and all stream publication order while testing whether this declaration basin restores EDI=result and EBP=stream.
probe 114 layout; result=MISMATCH; diff=379; shape=70.54263565891473: Test one natural ushort cursor rooted at the signed line-count word. This removes the scan alias and preserves the proven stream/frame decoder and malformed-data order. [same emitted code as probe 102]
probe 116 abi; result=MISMATCH; diff=379; shape=70.54263565891473: Test one-cursor ushort stream with explicit byte-base plus two advances. This isolates whether immediate packed-word stepping frees the original EBP stream role without changing decoder behavior. [same emitted code as probe 114]
probe 118 control-flow; result=MISMATCH; diff=376; shape=71.31782945736434: Test the decompiler-proven narrow ushort classifier key. The original subtract/decrement dispatch may come from a narrow key, while all stream, packet, frame, and malformed-data behavior stays natural.
probe 120 control-flow; result=MISMATCH; diff=379; shape=58.91472868217054: Test the complete Ghidra-local source surface with the real narrow code, packet, stream, output, and cur_y roles. This tests source declaration/lifetime context, not a synthetic owner.
probe 122 layout; result=MISMATCH; diff=367; shape=71.31782945736434: Test the binary-supported packed cursor integer anchor from Ghidra. This keeps one real stream owner and decoder behavior while checking whether VC5 preserves the original EBP cursor allocation. [same emitted code as probe 113]
probe 124 abi; result=MISMATCH; diff=326; shape=71.31782945736434: Test the full-width packet accumulator as a deliberate ABI hypothesis. The source may explain the original EDI role, but retain it only if the proven ushort packet boundary and exact source model survive.
probe 127 abi; result=MISMATCH; diff=367; shape=71.31782945736434: Test a period-plausible register-qualified packed stream owner. Keep only if it changes the natural source basin toward the proven EBP stream and EDI packet roles. [same emitted code as probe 122]
```
<!-- end-recovered:3f738cc563b368e6282e -->

<!-- recovered:2a15f4c34e97a8df8fa6 -->
### `1b87d28251a9` `src/scratch/0044A100_delta_flc.cpp:1-146`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 0044A100 RGE_Flic_Player::delta_flc
// flics.cpp lines 365-441
// Attempt log:
// 1: natural ushort* decoder: too short 400 B; compiler used EBP as constant 2 instead of chunk pointer.
// 2: byte-pointer decoder forced byte increments but used 0x10 frame/early EDI save, broad drift.
// 3: compact byte-pointer if-chain recovered 0x0c frame but still too short; EDX holds chunk, EBP constant 2.
// 4: register-qualified chunk pointer probe no change.
// 5: casted byte increments instead of +=2 to avoid constant-2 register; no change.
// 6: flags /O2(no /Oy), /O1, /Ox, /Ob0: /O1 much shorter, others same family.
// 7: volatile dummy forces comparable 412-byte output but broad drift (91.9903% pos, first mismatch 5).
// Fresh pass: replace the compiler-steering dummy with the binary-supported
// cur_y stack local and the natural ushort packet cursor from the sibling FLIC
// decoder.  This is the clean baseline for the remaining register/layout work.
// - A short/long outer-count, single-cursor, signed packet-count, and positive
//   payload-cursor pass were neutral or lower-shape; retain the two-cursor
//   natural decoder.  The remaining gap is EBP packet-cursor allocation and
//   the cur_y/line-count stack-home schedule.
// - Widening the outer line count to int changed the body to 400 bytes; rolled
//   back because the original boundary is 412 bytes.
// - Typed char* cursor and base-plus-one pointer spellings were neutral or
//   lower-shape; retain the natural ushort cursor.
// - Removing the redundant found-scan value temporary improved the best result
//   to 376 differing bytes without changing size or calls; this is the clean
//   source retained for the remaining EBP/prologue basin.
// - This claim: the binary-proven dword outer count plus a separate
//   success-path remaining counter improved the clean source to 374 differing
//   bytes / 61.24% shape / 398 emitted bytes, while register qualification and
//   pointer declaration/initialization order were codegen duplicates or a
//   one-byte regression. Retain the natural dword-count candidate below; the
//   unresolved structural blocker is EBP packet-cursor coloring and the
//   missing original 14-byte prologue/body basin.
// - This claim: a positive-run-first branch restored the oracle's late
//   negative-run topology and improved the clean candidate to 397 bytes / 367
//   diff / 71.32% shape. Explicit packet cursor increments, per-scan packet
//   zeroing, and a sparse switch were regressed; retain the positive-first
//   natural source. Remaining blocker is the original EBP cursor/prologue
//   allocation and associated stack packet-count schedule.
// - This claim: char* stream cursor plus sparse switch improved size to 400 B
//   and shape to 72.09%, but worsened positional diff to 383 B and frame to
//   0x10; restored the clean ushort-cursor source.
// Matching-worker pass (sa-9c74babf-r1):
// - Rechecked the pinned natural ushort/two-cursor source: 397 emitted bytes,
//   367 differing bytes, 0xC frame, and no calls.  The first structural gap
//   remains the missing early EBP save and packet-cursor coloring.
// - Tested byte cursors, one-cursor forms, explicit byte increments, signed
//   packet counts, split cur_y initialization, full class context, payload
//   aliases, and register qualification.  None improved the clean result.
// - An ambient declaration lab with 64 variants produced two codegen groups;
//   all remained 397 bytes with no size/frame-valid improvement.
// Matching-worker pass (sa-47d20a98-r1):
// - Revalidated the pinned source at 397 bytes / 367 differing bytes / 0xC
//   frame.  The original still requires an early EBP save for the stream
//   cursor; the clean source assigns EBP to a packet value instead.
// - Tested packet zeroing and classifier operands, one-cursor ushort loops,
//   byte-stream cursors, declaration order, and typed byte views.  The best
//   source-model variant reached 394 bytes / 377 differing bytes; none beat
//   the pinned natural two-cursor source.
// - Restored the pinned clean source.  The remaining blocker is the EBP
//   stream-cursor allocation basin without compiler-steering source forms.
// Matching-worker pass (sa-82ebd704-r1):
// - Moving scalar declarations to function scope produced duplicate codegen.
// - One advancing ushort classifier cursor, including the inverted scan-owner
//   form, produced the 399-byte / 373-diff basin and was rejected.
// - Restored the pinned natural two-cursor decoder.  The unresolved blocker is
//   still the original EBP stream-cursor allocation and prologue basin.
// Matching-worker pass (sa-8a69d026-r1):
// - Re-read the complete target packet and stack evidence plus the sibling
//   exact delta_fli source.  The pinned source remains 397 bytes / 367 diff.
// - A decompiler-shaped one-cursor decoder with a switch classifier reached
//   412 bytes / 365 diff, but its 0x10-0x14 frame and lower shape were worse.
// - The switch did reproduce the original subtract/dec classifier chain.
//   Raw int* cursors, address-taken cur_y, register hints, and dead-cur_y
//   removal did not improve that basin.  Restored the pinned clean source.
// Continuation exact-finish pass (sa-46d4712a-r5):
// - Re-tested the packed cursor owner, outer counter shape, packet output
//   alias, payload alias, classifier flag type, and declaration order.
// - A full-width packet counter reached the original 412-byte boundary and
//   326 differing bytes, but it lost the proven ushort packet width and had
//   lower block shape.  It is not an authentic source model.
// - No natural variant restored the original EBP stream cursor, EDI packet
//   value, and early EBP save together.  Restored the pinned ushort source.
// Continuation pass (sa-d8218ca7-r1):
// - cvdump confirms the original PDB owner is the private RGE_Flic_Player
//   delta_flc symbol and names only cur_y at stack offset -0xC.  The function
//   range is 0x19C bytes; no extra named local or call ABI evidence is present.
// - A one-cursor ushort stream rooted at the signed line-count word reached
//   398 bytes / 379 differing bytes and saved EBP, but EBP held the constant
//   two rather than the stream.  Its natural switch classifier reached 401
//   bytes / 373 differing bytes with a 0x10 frame; both were restored.
// - Cur_y-before-stream declaration order, a cached local chunk owner, and a
//   function-scope packet result were codegen duplicates of the clean source.
// - A full function-scope reconstruction from the Ghidra local order reached
//   399 bytes / 382 differing bytes and lower shape.  It was restored because
//   it changed signed scheduling and did not recover the original register
//   basin.  The pinned two-cursor source remains the smallest natural model.
// Exact-finish audit (sa-9afe1787-r1):
// - Read the complete LESSONS.md, matching workflow, dossier, PDB bands, and
//   original assembly.  The owner is private RGE_Flic_Player::delta_flc in
//   flics.cpp, range 0044A100-0044A29B, with no calls.
// - The authentic full-TU wrapper is src/flics_tu.cpp.  It keeps the reviewed
//   FLIC class and all neighboring flics.cpp owners.  The wrapper is not yet a
//   registered checker translation unit, so its direct object is evidence only.
// - A one-cursor ushort stream reached 398 bytes / 379 differing bytes.  EBP
//   held the constant two, not the stream.  Explicit byte-base stepping was a
//   codegen duplicate.
// - A narrow ushort classifier reached 398 bytes / 376 differing bytes.  It
//   kept the frame but worsened positional bytes.  The full Ghidra-local source
//   reached 404 bytes / 379 differing bytes and lower shape.
// - A full-width packet accumulator reached 409 bytes / 326 differing bytes.
//   It is rejected: the executable proves a ushort packet value at test DI and
//   the source loses that width.  The register-qualified stream was duplicate.
// - Restored the pinned natural two-cursor source after each probe.  Final
//   validation remains 397 bytes / 367 differing bytes / 0xC frame / zero calls.
//   The unresolved blocker is the authentic EBP stream, EDI packet, and early
//   EBP-save allocation basin.  No exact claim is made.
// Captain reduction: removed the redundant memcpy destination alias. The
// compiler output stayed at 397 bytes / 367 differing bytes, with the same
// 0xC frame and zero-call behavior. The direct destination is the cleaner
// natural source form.
// [non-comment lines omitted during migration]
// Main-agent audit confirmed canonical FLIC player/frame ownership and retained
// the natural packed ushort delta decoder.
// Captain pass: the context gate is proved by the flics.cpp PDB module, the
// 365-441 source band, the private RGE_Flic_Player owner, the linked address
// sequence, and the sibling delta_fli decoder's packed-stream anchors.
// A switch classifier was tested against the original subtract/decrement
// dispatch chain.  It changed the frame to 0x10 and worsened the result to
// 376 differing bytes, so the natural if-chain remains authoritative.
```
<!-- end-recovered:2a15f4c34e97a8df8fa6 -->

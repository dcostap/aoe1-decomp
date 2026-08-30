# Function notes: 0047E6B0 `setup`

Module notes: `decomp_notes/rdlg_lst_module.md`.

## Recovered attempt history

<!-- recovered:0e1683b472ad534ab4fe -->
### `target-session` `build/target_sessions/0047E6B0_setup.json:1-68`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=221; shape=94.81481481481481: Fresh clean-source baseline from current typed reconstruction.
probe 2 liveness; result=MISMATCH; diff=251; shape=92.5925925925926: Probe local text pointer reused for strlen and strcpy to seek original EDI scan-base allocation.
probe 4 liveness; result=MISMATCH; diff=221; shape=94.81481481481481: Probe a short-lived source pointer for only the strlen expression; keep the copy source direct. [same emitted code as probe 1]
probe 5 liveness; result=MISMATCH; diff=221; shape=94.81481481481481: Probe a short-lived source pointer created after allocation for the copy only. [same emitted code as probe 4]
probe 7 control-flow; result=MISMATCH; diff=221; shape=94.81481481481481: Probe inline strlen-plus-one directly as the first calloc count. [same emitted code as probe 5]
probe 9 context; result=MISMATCH; diff=221; shape=94.81481481481481: Probe VC5 intrinsic pragmas for the observed strlen/strcpy REP lowering and scan register order. [same emitted code as probe 7]
probe 11 liveness; result=MISMATCH; diff=251; shape=91.85185185185185: Probe register-qualified record text base retained across strlen, allocation, and copy.
probe 13 abi; result=MISMATCH; diff=221; shape=94.81481481481481: Probe a proven char-base overlay for list_info so VC5 can form scan addresses from base plus offset. [same emitted code as probe 9]
probe 15 control-flow; result=MISMATCH; diff=267; shape=88.05970149253731: Probe reverse source order for the index increment and 0x66 offset update.
probe 17 liveness; result=MISMATCH; diff=251; shape=91.85185185185185: Probe a typed list-record alias retained across strlen, allocation, and copy. [same emitted code as probe 11]
probe 19 liveness; result=MISMATCH; diff=244; shape=91.85185185185185: Probe a post-allocation list-info alias established before loop index setup.
probe 21 liveness; result=MISMATCH; diff=221; shape=94.81481481481481: Probe local declaration order offset, length, then loop index. [same emitted code as probe 13]
probe 23 abi; result=MISMATCH; diff=221; shape=94.81481481481481: Probe period-equivalent long locals for the byte offset and allocation length. [same emitted code as probe 21]
probe 25 context; result=MISMATCH; diff=221; shape=94.81481481481481: Probe period malloc header context in addition to stdlib and string headers. [same emitted code as probe 23]
probe 28 other; result=MISMATCH; diff=221; shape=94.81481481481481: Probe zero-index typed record spelling for the first scan and copy. [same emitted code as probe 27]
probe 30 abi; result=MISMATCH; diff=221; shape=94.81481481481481: Probe canonical class spelling for the typed rdlg_list_info record. [same emitted code as probe 28]
probe 32 liveness; result=MISMATCH; diff=221; shape=94.81481481481481: Probe address-of indexed text spelling for natural typed record access. [same emitted code as probe 30]
probe 34 liveness; result=MISMATCH; diff=251; shape=91.85185185185185: Probe a typed record reference alias scoped to each copy iteration. [same emitted code as probe 17]
probe 36 liveness; result=MISMATCH; diff=221; shape=94.81481481481481: Diagnostic decompiler-backed probe reusing the dead list_type parameter as text offset. [same emitted code as probe 32]
probe 38 abi; result=MISMATCH; diff=221; shape=94.81481481481481: Probe size_t-compatible unsigned length local for strlen and calloc. [same emitted code as probe 36]
probe 40 liveness; result=MISMATCH; diff=251; shape=92.5925925925926: Probe separate natural text-base load and offset update inside the copy loop. [same emitted code as probe 2]
probe 42 other; result=MISMATCH; diff=221; shape=94.81481481481481: Probe direct uncast strlen-plus-one calloc expression with typed list ownership. [same emitted code as probe 38]
probe 44 liveness; result=MISMATCH; diff=251; shape=91.85185185185185: Probe a typed reference to the inline text array before strlen and strcpy. [same emitted code as probe 34]
probe 46 behavior; result=MISMATCH; diff=223; shape=96.32352941176471: Probe the oracle-proven boolean conversion of TListDialog setup result.
probe 48 behavior; result=MISMATCH; diff=223; shape=96.32352941176471: Probe explicit boolean result with direct strlen-plus-one calloc expression. [same emitted code as probe 46]
probe 52 layout; result=MISMATCH; diff=223; shape=96.32352941176471: Probe char-pointer list_info ownership to recover original direct scan-base allocation. [same emitted code as probe 51]
probe 53 liveness; result=MISMATCH; diff=223; shape=96.32352941176471: Probe reversed natural pointer addition with char-pointer list_info for direct EDI scan-base lowering. [same emitted code as probe 52]
probe 55 liveness; result=MISMATCH; diff=223; shape=96.32352941176471: Probe oracle-supported reuse of list_type parameter as the first-scan byte offset. [same emitted code as probe 53]
probe 57 layout; result=MISMATCH; diff=223; shape=96.32352941176471: Probe zero-index typed record spelling for the direct list_info scan base. [same emitted code as probe 55]
probe 59 layout; result=MISMATCH; diff=223; shape=96.32352941176471: Probe typed list_info with a natural char-pointer cast for the serialized text base. [same emitted code as probe 57]
probe 61 layout; result=MISMATCH; diff=223; shape=96.32352941176471: Probe explicit address-of indexed text spelling for the scan and strcpy source. [same emitted code as probe 59]
probe 63 liveness; result=MISMATCH; diff=223; shape=96.32352941176471: Probe equivalent indexed-pointer address spelling to test VC5 operand allocation for the scan base. [same emitted code as probe 61]
probe 65 layout; result=MISMATCH; diff=223; shape=96.32352941176471: Probe a typed fixed-stride character-record pointer for natural serialized-text addressing. [same emitted code as probe 63]
probe 67 control-flow; result=MISMATCH; diff=223; shape=96.32352941176471: Probe natural allocation assignment inside the success guard for source liveness effects. [same emitted code as probe 65]
probe 71 behavior; result=MISMATCH; diff=222; shape=96.32352941176471: Probe calloc argument order: original pushes constant 1 after the REPNE scan, proving source calloc(1, strlen(text) + 1) rather than calloc(strlen(text) + 1, 1).
probe 72 behavior; result=MISMATCH; diff=223; shape=96.32352941176471: Probe reversed addition spelling 1 + strlen while retaining calloc(strlen-plus-one, 1) ABI; tests whether VC5 keeps the constant push after the scan. [same emitted code as probe 70]
probe 73 liveness; result=MISMATCH; diff=223; shape=96.32352941176471: Probe a named length local with strlen plus one, testing whether a delayed local removes VC5's early constant push while preserving the original calloc argument order. [same emitted code as probe 72]
probe 74 abi; result=MISMATCH; diff=223; shape=96.32352941176471: Probe calloc's second argument as sizeof(char), a period-plausible constant spelling that may preserve the original post-scan immediate push. [same emitted code as probe 73]
probe 75 context; result=MISMATCH; diff=223; shape=96.32352941176471: Probe removal of the local calloc redeclaration, restoring only the period stdlib declaration to test declaration context and argument scheduling. [same emitted code as probe 74]
probe 77 abi; result=MISMATCH; diff=223; shape=96.32352941176471: Probe explicit unsigned cast on calloc's constant second argument; tests whether ABI-width materialization changes scheduling without changing the call. [same emitted code as probe 75]
probe 78 abi; result=MISMATCH; diff=223; shape=96.32352941176471: Probe signed int cast around strlen result; tests whether the historical CRT return-width spelling controls the post-scan calloc push. [same emitted code as probe 77]
probe 79 liveness; result=MISMATCH; diff=218; shape=94.92753623188406: Probe split strlen and increment statements. This keeps calloc(strlen-plus-one, 1) semantics but tests whether a named increment blocks constant-push hoisting.
probe 80 behavior; result=MISMATCH; diff=223; shape=96.32352941176471: Probe equivalent strlen minus negative-one spelling. It tests whether VC5 recognizes the no-decrement intrinsic path while changing constant scheduling. [same emitted code as probe 78]
probe 81 behavior; result=MISMATCH; diff=223; shape=96.32352941176471: Diagnostic dependency probe: use length - length + 1 for calloc's constant size. It tests whether a source dependency delays the push while optimizer removes the arithmetic. [same emitted code as probe 80]
probe 82 abi; result=MISMATCH; diff=223; shape=96.32352941176471: Probe size expression sizeof(list_text[i][0]) for calloc's second argument. It is a natural char-size form that can retain an immediate one while changing compiler scheduling. [same emitted code as probe 81]
probe 83 liveness; result=MISMATCH; diff=223; shape=96.32352941176471: Probe a natural unit-size local initialized to one and passed as calloc's second argument. Tests whether VC5 preserves an immediate push but schedules it after strlen. [same emitted code as probe 82]
probe 87 abi; result=MISMATCH; diff=223; shape=96.32352941176471: Probe narrow char-typed calloc size argument. Tests whether VC5 promotes the period-plausible byte size after the intrinsic scan while preserving the six-call calloc ABI. [same emitted code as probe 86]
probe 89 abi; result=MISMATCH; diff=223; shape=96.32352941176471: Probe short-typed calloc size argument. Tests a second narrow promoted ABI type for delayed constant publication after strlen. [same emitted code as probe 87]
probe 91 liveness; result=MISMATCH; diff=252; shape=95.5223880597015: Probe one natural text pointer local shared by strlen and strcpy. Tests whether source ownership of the scanned address changes VC5 scan scheduling without changing calls.
probe 93 context; result=MISMATCH; diff=243; shape=94.02985074626865: Probe a natural same-TU inline text_size helper around strlen plus one. Tests whether an inlined helper boundary changes VC5 argument scheduling while preserving six calls.
probe 95 variant; result=MISMATCH; diff=243; shape=94.02985074626865: variant lab build\variant_lab\0047E6B0_setup\20260822_215649: 64 variants, 0 invariant-eligible, 0 exact
probe 96 behavior; result=MISMATCH; diff=238; shape=90.57971014492753: Probe a reversible text-pointer increment around strlen. Tests whether a natural pointer mutation creates the target scan-before-constant push while preserving the original pointer and six calls.
probe 98 context; result=MISMATCH; diff=223; shape=96.32352941176471: Probe same-TU nonvirtual method declaration surface from rdlg_lst.cpp. Tests whether declarations for create_object_list and get_cur_id restore the original allocator schedule. [same emitted code as probe 89]
probe 100 context; result=MISMATCH; diff=223; shape=96.32352941176471: Probe period Windows SDK header context before stdlib/string. Tests whether the original rdlg_lst.cpp include surface changes strlen/calloc scheduling without source changes. [same emitted code as probe 98]
probe 102 context; result=MISMATCH; diff=223; shape=96.32352941176471: Probe standard stdlib calloc declaration without the local redeclaration. Tests the period header declaration surface for argument scheduling. [same emitted code as probe 100]
probe 104 abi; result=MISMATCH; diff=223; shape=96.32352941176471: Probe period int-returning strlen declaration with explicit strcpy. Tests whether CRT return width and declaration context controls delayed constant push. [same emitted code as probe 102]
probe 106 abi; result=MISMATCH; diff=223; shape=96.32352941176471: Probe unsigned cast around complete strlen-plus-one allocation count. Tests whether VC5 width anchoring changes the constant push schedule. [same emitted code as probe 104]
probe 108 context; result=MISMATCH; diff=223; shape=96.32352941176471: Probe file-scope const unit value for calloc's size. Tests whether a TU-level constant source preserves immediate one while moving its publication after the scan. [same emitted code as probe 106]
probe 110 liveness; result=MISMATCH; diff=252; shape=95.5223880597015: Probe const text pointer local shared by strlen and strcpy. Tests whether a read-only source alias selects the target scan register and push order. [same emitted code as probe 91]
probe 112 liveness; result=MISMATCH; diff=223; shape=96.32352941176471: Probe short-lived text alias used only by strlen, with direct typed source retained for strcpy. Tests whether alias lifetime selects target EDI scan lowering without carrying a pointer across calloc. [same emitted code as probe 108]
probe 114 context; result=MISMATCH; diff=223; shape=96.32352941176471: Probe explicit VC5 strlen intrinsic pragma in the target TU. Tests whether pragma state controls constant push scheduling. [same emitted code as probe 112]
probe 116 behavior; result=MISMATCH; diff=252; shape=95.5223880597015: Probe period-like pointer normalization: form a record text pointer one byte back, preincrement, then scan and copy it. Tests whether VC5 preserves the target scan-before-constant order after folding the reversible address. [same emitted code as probe 110]
probe 119 context; result=MISMATCH; diff=223; shape=96.32352941176471: Replace local inline placeholder virtual bodies with declaration-only authentic caller surfaces. Tests whether front-end inline-definition state controls the scan and calloc push schedule. [same emitted code as probe 118]
probe 120 liveness; result=MISMATCH; diff=222; shape=94.24460431654676: Use a period-plausible short text length for the 100-byte record field. Tests whether required narrowing completes the scan before either calloc argument is pushed.
probe 121 behavior; result=MISMATCH; diff=223; shape=96.32352941176471: Sequence strlen through a one-argument inline character allocator before the real calloc call. This tests whether an authentic-style helper can delay both pushes without extra calls. [same emitted code as probe 119]
probe 122 liveness; result=MISMATCH; diff=223; shape=96.32352941176471: Reuse one text pointer across both phases, but assign it again after calloc from the member. This tests scan-before-push liveness while preserving the executable's post-call member reload. [same emitted code as probe 121]
probe 123 liveness; result=MATCH; diff=0; shape=100.0: Bind a local reference to the list_info pointer member. Tests whether a real member alias preserves both executable reloads and selects the direct EDI scan base before calloc setup.
probe 125 context; result=MISMATCH; diff=223; shape=96.32352941176471: Walk back declaration-only panel surfaces while keeping the list_info member reference. This tests whether the earlier declaration cleanup was incidental to exact codegen. [same emitted code as probe 122]
```
<!-- end-recovered:0e1683b472ad534ab4fe -->

<!-- recovered:c738c73bddea893b044e -->
### `ee8c511fb4d8` `src/scratch/0047E6B0_setup.cpp:1-78`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 0047E6B0 RGE_Dialog_List::setup
// PDB: rdlg_lst.cpp:45-91, 376 bytes
//
// Attempt log:
// - Prior scratch source had a duplicate list_text allocation and a decompiler
//   `init()` name for the vslot at +0x138; this reconstruction restores the
//   single allocation, typed list records, and the RGE_Dialog_List::create_list
//   virtual surface.
// - Baseline: canonical TPanel/TDialogPanel/TListDialog ownership with
//   strlen()+1 allocation and strcpy copy loop; calls/CFG matched, but the
//   compiler initialized the text offset before the positive-count branch
//   (383 rebuilt bytes, 230 positional diff).
// - Guarded natural while/for forms moved offset initialization after the
//   count test and were the best basin (383 bytes, 225 diff, 93.43% shape,
//   exact ordered call set). A nested do form peeled the first iteration and
//   added an extra calloc, so it was rolled back.
// - Parameter-home reuse, reversed pointer arithmetic, flat text-pointer
//   casts, and a strlen-only source alias all emitted the same code as the
//   guarded form. Remaining drift is the first scan's address/register order
//   and the resulting seven-byte loop/block displacement shift.
// - Fresh pass baseline from the exact rdlg_lst and panel donors reproduced the
//   prior 383-byte, 225-diff basin with all six ordered calls aligned.
// - A source pointer kept for both strlen and strcpy changed the prologue and
//   worsened the diff. It was rolled back.
// - A focused six-form natural loop lab, direct char overlay, reversed addition,
//   inline length, short-lived text alias, and indexed address spelling found no
//   closer emitted group. The direct typed form remains the clean source.
// - The oracle boolifies the TListDialog::setup(...) result. The natural
//   `!= 0` return improves block shape, but the first scan still adds four
//   bytes until its address and copy lowering is recovered.
// - Remaining structural hunk is original EDI=list_info; rebuilt EAX=list_info,
//   EDI=offset, then add. It shifts the seven-byte loop suffix; no ABI or call
//   mismatch remains.
// - Replaced the flattened vtable with the exact panel/list donor hierarchy and
//   corrected TScreenPanel's TEasy_Panel base; emitted code was unchanged, so
//   the natural typed hierarchy is retained.
// - Fresh bounded pass: dossier, same-TU donors, ABI evidence, and focused scan
//   donors confirm the typed record model. Zero-index record spelling, separate
//   cursors, typed aliases, explicit string declarations, and a post-allocation
//   source alias all duplicated the 376-byte basin. Restored the direct typed
//   source; the EDI versus EAX scan-base allocation remains the next lead.
// - New bounded block-shape pass: reversed pointer-add order, direct byte-base
//   casts, dead list_type parameter reuse, a diagnostic char-pointer field,
//   guarded do-loop form, register-qualified aliases, and inline strlen length
//   all duplicated the 376-byte basin. The char-pointer and do-loop forms were
//   diagnostic only and were removed. The clean typed source remains best.
// - Current bounded pass: short-lived and retained text/list-info aliases,
//   inline length, long locals, declaration-order changes, malloc-header and
//   intrinsic-pragmas context, a char-pointer list-info overlay, and reversed
//   update order all duplicated or worsened the 376-byte basin. The clean typed
//   source was restored. The unresolved hunk remains the original EDI=list_info
//   scan base versus rebuilt EAX=list_info followed by EDI=offset.
// - Latest claim probes kept typed class and record ownership. Indexed text
//   spelling and direct strlen-plus-one lowering were duplicates. A typed alias
//   worsened the frame. The final natural source keeps the oracle bool return.
// - Revisit probes for char-pointer and fixed-stride overlays, reversed and
//   indexed address forms, list_type offset reuse, and a combined allocation
//   guard all reproduced 380 bytes and 223 differing bytes. The pinned typed
//   source is restored; direct EDI scan-base allocation remains unresolved.
// - Claim probes confirmed the blocker source shape. Reversing the calloc
//   arguments produced the wrong push order and 222 differing bytes. Reversed
//   addition, named and split length locals, sizeof(char), explicit width
//   casts, a unit local, and equivalent arithmetic all reproduced the 380-byte
//   basin. The natural calloc(strlen(text) + 1, 1) source is restored.
// - Binary evidence: the target pushes 1 then the scanned length after the
//   first REPNE scan, so its C argument order is calloc(strlen(text) + 1, 1).
//   Exact donor 00472440 uses the same natural call but VC5 emits push 1 before
//   its scan. The remaining order is TU or expression-context sensitive; no
//   tested period-plausible form restores the target fault context.
// - Claim audit tested narrow and unsigned size types, custom int strlen
//   declarations, same-TU method declarations, Windows and ambient declaration
//   context, and reversible text-pointer forms. All kept the same basin or
//   worsened structure; none restored scan-before-push ordering.
// BLOCKER: the rebuild pushes calloc's constant second argument before the
// first REPNE string scan. The executable pushes it after the scan. An invalid
// list_info text pointer therefore reaches an exception handler with a
// different ESP value. Do not accept this copy-lowering drift without a source
// form that restores the original fault context.
```
<!-- end-recovered:c738c73bddea893b044e -->

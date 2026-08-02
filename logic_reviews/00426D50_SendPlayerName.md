# Logic review: 00426D50 `TCommunications_Handler::SendPlayerName`

## Phase transition

The main agent suspended ordinary exact matching on 2026-08-02 after repeated
independent assignments and more than seventy documented source, declaration,
argument-side-effect, liveness, field-order, call-surface, context, and flag
hypotheses. The retained candidate has exact size, frame, saved registers,
instruction count, ordered calls, CFG, return sequence, and final tail. The
remaining 32 strict differing bytes are confined to VC5 scheduling and register
choice while constructing the `DPNAME` record and pushing the DirectPlay call
arguments. Numerous natural, explicit, comma-expression, pointer-alias,
volatile, typed virtual, and optimization variants either duplicate this basin
or regress it. No credible exact-match lead remains without genuinely new
compiler-IR or whole-translation-unit evidence.

Current validated checker state:

- source remains `src/scratch/00426D50_SendPlayerName.cpp`;
- original/rebuilt size: 105/105 bytes;
- frame: `0x10`/`0x10`;
- saved registers: `esi, edi` / `esi, edi`;
- calls: 2/2, ordered and target-aligned;
- CFG signals: 0/0 conditional branches, 0/0 jumps, 1/1 returns;
- instructions: 33/33;
- instruction shape: 87.88%;
- strict difference: 32 bytes in 3 spans, first mismatch `00426D79`;
- edit/resync cost: 31 raw, 14.76% bounded, 88 equal bytes.

The original computes the stack-record pointer, pushes flag `2`, computes and
stores the short-name pointer, loads the player ID and vtable, then stores size
16 immediately before the virtual call. The rebuilt candidate reaches the same
record and argument values but schedules the two name-pointer LEAs/stores, size
store, global loads, and pushes differently. This is too broad for
`accepted_drift`; formal review must establish whether every call-boundary value
and all potentially observable pre-call effects remain identical.

### Cumulative matching evidence

- Exact `DPNAME` size and four 32-bit stack fields, handler offsets, DirectPlay
  global, player-ID global, virtual slot `+0x78`, error field, error-call target,
  string address, stack cleanup, and return behavior are represented.
- Exact function size, frame, prologue/epilogue, saved registers, two calls, and
  post-call result handling have been stable across the best families.
- Exhausted source families include natural `memset`, explicit zero stores,
  aggregate initialization, raw stack buffers, local/reference/register/volatile
  record pointers, delayed and comma-expression field assignments, field-order
  variants, DP/player/name/result locals, direct and typed virtual-call surfaces,
  side effects attached to each argument position, and broad optimization flags.
- Correcting `ShowReturn` to its original `char*` surface preserved the intended
  code shape and call target.
- The retained source is the deepest validated first mismatch and all rejected
  alternatives either emitted duplicate code or worsened size/frame/order.

### Semantic questions at entry

Blind reviewers must establish these directly from the executable:

1. Exact initial contents and write widths of all four `DPNAME` stack fields,
   including which source name populates each pointer field.
2. Exact DirectPlay virtual-call target, calling convention, argument order,
   `this` value, player ID, flags, record pointer, and `dwSize` value at the call
   boundary.
3. Whether the candidate's reordered field stores, global loads, LEAs, and pushes
   can change behavior through faults, aliasing, asynchronous mutation,
   reentrancy, or observable memory.
4. Whether any record field is read before its final value is stored on either
   emitted path, including malformed DirectPlay/global state.
5. Exact `ShowReturn` receiver, result and message arguments, call ordering,
   cleanup, and preservation/return of the DirectPlay result.
6. Null or invalid global/interface/error pointers and fault timing, including
   whether changed evaluation order creates an observably different first fault.
7. Any calling-convention, string-width, structure-layout, or parameter-width
   mismatch hidden by the local declarations.

## Review rounds

### Formal round 1 — concurrent blind cohort

Two fresh reviewers independently assessed the candidate concurrently. Both
were strictly read-only and unleased, and blind to this ledger, Git history,
prior reports, and matching conclusions.

#### Reviewer 1 — ABI and exceptional-order review

> **Verdict:** normal-path call behavior is correct, but the candidate is not a
> full behavioral match.
>
> The original physical `DPNAME` layout is `dwSize`, `dwFlags`,
> `lpszShortName`, `lpszLongName`; the scratch declaration reversed the two
> pointer names, although compensating assignments produced correct bytes.
> DirectPlay vslot `+0x78`, `__stdcall` arguments, `ShowReturn`, cleanup, and
> returned result are correct.
>
> **Definite exceptional-path difference:** original reads global player ID
> `0062CF04` and stores the friendly-name pointer before dereferencing the
> DirectPlay object, while the rebuilt candidate dereferenced the object first
> and had already stored `dwSize`. A null/invalid interface therefore changes
> the first-fault ordering and the partially initialized stack `DPNAME` visible
> at the fault.

#### Reviewer 2 — independent normal and malformed-state review

> **Definite behavioral differences:** none found for reachable valid state.
>
> Correct handler offsets, all call-time `DPNAME` bytes, vslot `+0x78`,
> arguments, calling convention, one-time global reads, `ShowReturn`, cleanup,
> and result preservation were verified. The reversed field declaration is a
> type-model/maintenance concern despite physically compensated bytes.
>
> **Plausible concern:** raw indirect-call expression sequencing does not prove
> exact invalid-interface fault timing relative to final `DPNAME` stores. Normal
> execution is equivalent; concurrent mutation is unsynchronized.

## Main-agent adjudication

- **Confirmed — invalid-interface fault ordering.** Original instructions load
  `0062CF04` at `00426D85`, store the friendly pointer at `00426D8B`, dereference
  the DirectPlay object at `00426D8F`, and store `dwSize` only at `00426D93`.
  The pre-fix rebuilt sequence dereferenced the object before loading
  `0062CF04`, and stored `dwSize` before that dereference. This is a concrete
  machine-state difference if the interface is invalid; one evidence-backed
  objection blocks promotion even though the second reviewer classified it as
  only plausible.
- **Confirmed and corrected — reversed local type model.** Although physical
  bytes were compensated, the member names were opposite the executable's
  canonical `DPNAME` layout and made review error-prone.
- **Cleared provisionally — valid call behavior and tail.** Both reviewers agree
  on final record bytes, call target/convention/arguments, `ShowReturn`, cleanup,
  and result.

The bounded ordering/type defects were corrected directly. Fresh blind post-fix
review is required before final adjudication or promotion.

## Integrated changes

- Corrected `DPNAME` to canonical short-name-at-`+0x08`, long-name-at-`+0x0C`
  order.
- Replaced nested comma-expression/raw-vtable call plumbing with explicit typed
  `IDirectPlay`/vtable statements and named reads/stores.
- The emitted candidate now loads the player global, stores both name pointers,
  dereferences the interface, then stores `dwSize`, matching the original's
  fault-relevant ordering. The function remains 105/105 bytes with both calls
  aligned; strict drift improves from 32 to 24 bytes. First mismatch moves
  earlier because the semantically required player-global load is now explicit,
  but the remaining reordering is among non-faulting LEAs/pushes before the same
  call boundary.

### Formal round 2 — fresh post-fix mixed-model cohort

A fresh Luna reviewer and a DeepSeek V4 Flash reviewer independently assessed
the corrected candidate concurrently. Both were read-only, unleased, and blind
to this ledger, previous reports, and history.

#### Reviewer 3 — strict fault-context review

> **Verdict: Reject as a full behavioral match.** Valid-pointer behavior,
> canonical `DPNAME`, all final bytes, vslot/ABI/arguments, `ShowReturn`, cleanup,
> and result are correct. At an unreadable player-global slot or invalid
> DirectPlay object, however, original and rebuilt have pushed different subsets
> of `2` and `&DPNAME` when the fault occurs. The local record contents agree,
> but fault-time ESP/stack context differs.

#### Reviewer 4 — independent machine-effect review

> **Verdict: PASS — no definite semantic difference.** The reviewer independently
> verified the canonical layout, zero/name/size store order, global-read and
> vtable-dereference order, invalid-interface record state, vslot `+0x78`,
> `__stdcall` arguments, `ShowReturn`, and return. It classified the residual
> 24-byte drift as register selection and side-effect-free LEA/load/push
> scheduling, with no changed program-visible memory slot, constant, call, or
> target.

### Round 2 adjudication and subsequent normalization

- **Still unresolved — fault-time argument-push context.** The reviewers agree
  on every C/C++-level read, write, call, argument, fault address, and local
  record byte, but disagree on whether transient argument words beneath ESP at
  an access violation are part of the required observable behavior. No evidence
  has yet established an enclosing handler that inspects these words, but one
  evidence-backed strict objection remains and therefore blocks promotion.
- **Cleared — all ordinary and call-boundary behavior.** Both reports independently
  confirm the complete valid path and DirectPlay ABI.

After the cohort, the source received the newly required plausibility cleanup:
the explicit raw vtable structure was replaced with a period-appropriate typed
COM interface and ordinary `dp->SetPlayerName(...)` call. The normalized source
remains 105/105 bytes with both calls aligned and 31 strict differing bytes. It
preserves global/name/vtable/size ordering but changes scheduling and was not the
exact candidate reviewed in round 2. A fresh cohort must review this normalized
source before any final adjudication; no further cohort was launched in the
current orchestration window.

### Formal round 3 — normalized-source mixed-model cohort

A fresh Luna reviewer and DeepSeek V4 Flash reviewer independently reviewed the
normalized typed-COM candidate. Both were read-only, unleased, and blind to this
ledger, prior reports, and Git history.

#### Reviewer 5 — Luna fault-order review

> **Scope:** Reviewed the current candidate against the original packet and
> emitted disassembly, including malformed DirectPlay state and fault order.
>
> **Normal path:** DPNAME contents, COM slot and arguments, error reporting,
> return value, and cleanup are correct.
>
> **Finding [P2]:** The rebuilt candidate dereferences `dp->vtable` before any
> COM arguments are pushed. The original pushes `2` and `&DPNAME` before the
> vtable dereference. A null/invalid interface therefore faults with a different
> ESP and different argument-setup context. Preserve the original dereference
> ordering for fault equivalence.
>
> **Verified:** `dwSize=0x10`, `dwFlags=0`, short name at `this+0x10F8`, long
> name at `this+0x1179`, vslot `+0x78`, `__stdcall` argument order,
> unconditional `ShowReturn`, unchanged result, and cleanup.
>
> **Verdict:** needs attention. Malformed-state reachability was not established.

#### Reviewer 6 — DeepSeek adversarial machine-effect review

> **Scope:** Independently re-extracted and disassembled the original and
> rebuilt the current source in a temporary VC5 sandbox. No repository checker,
> ledger, history, edit, or lease was used.
>
> **Normal path:** Fully equivalent. The final DPNAME is `{16, 0,
> &MyFriendlyName, &MyFormalName}`; the virtual `__stdcall` call uses the same
> interface, player, record, flag, and vslot `+0x78`; `ShowReturn`, return value,
> and cleanup agree. The 105-byte candidate has 31 genuine differing instruction
> bytes plus the same-symbol direct-call relocation bytes.
>
> **Finding [P2]:** At an invalid DirectPlay interface, the vtable load occurs
> after two argument pushes in the original but before all argument pushes in the
> rebuilt candidate. Thus the faulting context has an eight-byte ESP difference
> and different transient argument words. This is observable through SEH,
> debugger, or crash-dump context. The report also claimed the original had not
> yet stored the short-name pointer or read the player global at the fault.
>
> **Verified non-issues:** Register choices at the eventual stdcall boundary are
> not callee-visible; the return byte, inlined four-dword zeroing, relative global
> and name-store order, and null-`Err` behavior otherwise agree.
>
> **Verdict:** needs attention — one narrow, definite invalid-interface
> fault-context divergence; normal-path semantics are verified.

### Round 3 main-agent adjudication

- **Confirmed — transient fault-context difference.** Original assembly pushes
  `2` at `00426D7C` and `&dpnSetName` at `00426D84`, then dereferences the
  interface at `00426D8F`. The normalized rebuilt assembly dereferences the
  interface before any pushes. At an access violation, ESP and the transient
  argument words therefore differ. The executable is the behavioral oracle,
  including fault behavior, so this remains substantive and blocks promotion.
- **Corrected — DeepSeek's partial-record detail.** The original loads the player
  global at `00426D85` and stores the friendly/short-name pointer at `00426D8B`,
  both before the vtable dereference at `00426D8F`. Thus the original and rebuilt
  record contents and player-global read have converged by the fault; the proven
  difference is the pushed-argument/ESP context, not the short-name field or
  player-global timing.
- **Confirmed — ordinary behavior.** Both fresh reviewers independently verified
  the complete valid path, ABI, calls, memory values, error reporting, cleanup,
  and returned result.
- **Decision:** no source change was made. Reintroducing opaque raw-vtable or
  comma-expression scheduling merely to reduce this drift would violate the
  normalized-source gate without proof that it restores the complete original
  fault context. The candidate remains in `src/scratch`; formal logic promotion
  is blocked unless a plausible source surface reproduces the original push-before-
  dereference sequence or project policy explicitly narrows the behavioral oracle.

## Final decision

Not promoted. The function remains in `src/scratch`. Three cohorts agree that
normal-path behavior is complete, but the round-2/round-3 transient ESP and
argument-stack difference at an invalid-interface access violation remains a
substantive executable-behavior mismatch.

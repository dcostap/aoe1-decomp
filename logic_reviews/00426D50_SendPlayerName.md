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

## Final decision

Pending. The function remains in `src/scratch` and must not move to
`src/verified_logic` while any substantive finding is unresolved.

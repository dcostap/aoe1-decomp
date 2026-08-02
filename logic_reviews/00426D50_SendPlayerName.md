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

No formal blind review round has been integrated yet.

## Main-agent adjudication

Pending independent review.

## Integrated changes

None during logic review yet.

## Final decision

Pending. The function remains in `src/scratch` and must not move to
`src/verified_logic` while any substantive finding is unresolved.

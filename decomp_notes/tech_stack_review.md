# Tech scalar-storage investigation

Base: `ef479e9e7`. Review the four remaining Tech functions against their complete original instruction ranges.
No game was run. This review does not change the exact-match rules.
The stack proof is conditional. The overlap objection below prevents accepted-drift approval.

## Behavior

### `0050C730 tech_cost`

The 878-byte body initializes six short outputs in argument order before calling `check_tech_cost(tech_id, 0)`.
The six references may overlap. Their writes and subsequent reloads retain the original order.
Each output write covers exactly two bytes. The function does not form output pointers from private local addresses.
The caller can still supply such a pointer; see the overlap objection below.
Signed tech IDs select 60-byte records. Each enabled attribute reads its signed short ID and cost.
The carry flag comes from the low return byte and the attribute-29 threshold.
Each carry adjustment retains both `_ftol` calls and both attribute reloads.
The short total retains the original truncation and overflow behavior.
The first two final carry assignments add the total. The third replaces the cost with the total.
The final checks clear each attribute ID when its corresponding signed cost is nonpositive.
Important addresses: `0050C754` output initialization, `0050C78E` cost check, `0050C834` first conversion, `0050CA5E` third-cost replacement.

### `0050CA9E check_tech_cost`

The 391-byte body reads the tech pointer and carry value before checking research state.
Only state one enters the three-entry loop. Other states write minus one through a nonnull output and return zero.
The loop skips negative attribute IDs and unused entries.
Attribute three can debit carry before the ordinary attribute check. Preserve that order.
Insufficient carry writes the failing short attribute ID, when requested, and returns zero.
The remaining branch compares carry plus the attribute amount, then subtracts the deficit from carry.
Successful checks return one without writing the optional output.
Important addresses: `0050CAC7` carry snapshot, `0050CAFD` state read, `0050CB78` carry debit, `0050CB9E` first failure output.

### `0050CC25 start_research`

The 334-byte body computes the tech pointer before calling `check_tech_cost`.
It passes the original short ID and optional output pointer, then tests only the low return byte.
Charge zero skips all costs and the state change, but returns one after a successful check.
For nonzero charge, three entries use signed IDs, used flags, and signed short costs converted to float.
Insufficient attributes debit carry first, then zero the indexed attribute. This includes attribute three itself.
Otherwise, the function subtracts the cost from the indexed attribute.
Only the charged path writes research state two.
Failure overwrites the optional missing-attribute output with minus one, even after the callee supplied a specific ID.
Important addresses: `0050CC4E` cost check, `0050CD0B` carry write, `0050CD1A` attribute zero, `0050CD52` state write.

### `0050CE68 check_for_new_tech`

The 530-byte body retains signed short counters and the byte prerequisite counter.
It clears `changed` and never sets it. Do not repair that original bug.
States zero and one enter prerequisite checks. State two contributes to the active count without those checks.
Each of four nonnegative prerequisite IDs reads its referenced research state.
The required-count and research-time tests preserve the original signed extensions and x87 condition tests, including unordered results.
The function calls `do_tech(i)` before decrementing active count.
Otherwise, it writes state one or zero under the original guards.
The final active-count test can set attribute 39 to float one. The function always returns one.
Important addresses: `0050CE82` unchanged flag, `0050CF4D` prerequisite state, `0050CFAD` callback, `0050D06A` attribute write.

## Source

The public-identity review establishes all four complete method signatures and the unoptimized module recipe.
The source uses ordinary scalar variables and reviewed fields. It needs no synthetic local record or forced stack layout.

The review found a real type difference before considering stack positions.
Original instructions at `0050C7A2` and `0050CAD6` compare against an eight-byte double one.
The existing `1.0f` literals produced four-byte reads instead.
Change those two literals to `1.0`. This restores the original operand width and constant bytes.
Do not classify the earlier float-width difference as a stack-only difference.

The existing zero-double reference in `check_for_new_tech` retains its separate storage-mapping requirement.
Original bytes are eight zero bytes. The existing `game_globals.cpp` definition is a zero double.
This local review does not prove complete linked storage or global initialization coverage.

## Bytes

Baseline: `9d4c5b1230b5ab600db6843a1ca168996a9f8af0f53c07d77de35968482c595b`.
Baseline run: `4b2b59d7316c24341967226c932624c1c48560adcb22b1a971cc3b3ccf976c1a`.
Double-literal state: `36eb114fcaa7e9f58030ae2f9db462fe18a747fc89bd001ba2ecc9cd8960c385`.
Its run: `37ca630aead56183cd570b6cf56ea75ee4fdcca802f6873ea09189682a618bd6`.

| Function | Original size | Final differing bytes | Frame bytes |
|---|---:|---:|---:|
| `0050C730` | 878 | 26 | 28 |
| `0050CA9E` | 391 | 32 | 32 |
| `0050CC25` | 334 | 22 | 24 |
| `0050CE68` | 530 | 28 | 36 |

The read-only proof checks all 665 instruction pairs, not selected blocks.
Every remaining changed instruction byte is a private EBP-relative displacement.
Registers, instruction sizes, widths, operations, branches, calls, arguments, and external memory operands otherwise agree.
All direct target identities pass. Compared constant operands contain the complete original four-byte or eight-byte value.

The proof builds an injective byte mapping for every private stack access, including narrow values and four-byte masked byte reads.
Every mapped range stays inside the unchanged allocated frame. No two distinct accessed bytes merge.
No private stack address escapes through LEA, explicit ESP-relative addressing, or a copied frame pointer.
Saved registers, argument slots, return addresses, frame sizes, and cleanup remain unchanged.

The frame-offset mappings below use decimal EBP-relative offsets:

- `tech_cost`: tech -12 to -8; total -8 to -4; carry flag -4 to -12.
- `check_tech_cost`: tech -16 to -8; carry -12 to -20; cost -8 to -12; index -24 to -16; attribute -20 to -24.
- `start_research`: tech -8 to -4; cost -4 to -8; index -16 to -12; attribute -12 to -16.
- `check_for_new_tech`: tech -28 to -20; inner index -20 to -28; done count -16 to -8; prerequisite count -12 to -16; active count -8 to -4; changed flag -4 to -12.

Unlisted accessed slots retain their original positions.
Byte padding read by a wider flag load is removed by the same immediate mask before use.
No uninitialized padding affects a branch, call argument, return value, or external write.

When caller-accessible storage is disjoint from the private frame, the permutation preserves values and external memory operations.
It then preserves arithmetic, x87 flags, callee effects, cleanup, and returns.
This condition does not establish the project's required stack-overlap behavior.

### Stack-overlap objection

The source interfaces do not establish that every input object avoids the private frame.
The project also preserves malformed and stack-overlapping inputs; do not assume disjointness without evidence.

For `tech_cost`, let the first output reference point to EBP-8 in the eventual callee frame.
The original stores the short total there. The rebuild stores the tech pointer there.
The initial minus-one output write therefore changes different live values.
For example, it changes a rebuilt tech pointer ending in `0000` to one ending in `FFFF`.
With a mapped original tech record and an unmapped changed address, the rebuild can fault at its first used-attribute read.
The original pointer remains intact at EBP-12. Give it unused attributes and valid remaining outputs to avoid that fault.
This is a static instruction counterexample, not an executed test.

The counterexample rejects an unconditional stack-permutation proof.
The other three functions also need explicit alias analysis or proved caller restrictions before approval.
The original draft approval relied on the disjointness condition. Event `c2db7184ed40c0ca530e6189ab8d2b8373bbe81d9d27b5464cc5658fa5e5de79` preserves that rejected draft.

The separate declaration-order lab tested all 24 orders of the four `start_research` locals.
All compile. They produce two 334-byte outputs, each with 22 differences. None matches.
Preserve the complete lab; retain none of those source-only ordering changes.

Eleven pointer, const-pointer, and reference binding variants also compile without an exact result.
The cost-query binding variants reach 15 differing bytes, but still change private stack locations.
Retain none of these binding changes merely for a lower byte count.

## Integration

Retain the double-literal repair and the later natural scope improvements.
Do not approve the four private-storage differences as accepted drift.
Keep the simplest scalar source. Do not add fake records, local aliases, or extra declarations to force stack positions.
The final module audit retains all 29 existing matching functions. All four authoritative target checks remain nonexact.
All four functions remain open. Natural local types and scopes, or independent caller and alias evidence, remain useful approaches.

The final closure compares all 33 defined Tech bodies against the baseline.
Only the two comparison opcodes change, from D8 to DC. All other instruction bytes remain unchanged.
The literal pool grows from sixteen bytes to twenty-four bytes, including double alignment.
Five literal reads retain their complete values; only the two repaired reads change width.
The constructor's float 7.03 stays at pool offset zero. The progress function's float 100 moves from twelve to twenty.
Both unchanged functions retain the same four-byte reads and values.
Their whole-pool reference descriptions therefore change without changing their actual constant operands.
The proof also retains every mutable string's name, offset, contents, and section properties.

## Follow-up source probes

Fresh direct checks retain ordinary source scopes that reduce local displacement
drift without changing behavior or ABI:

| Function | Retained source shape | Current differing bytes |
|---|---|---:|
| `0050C730` | `total`, `tech`, and `can_use_carry` declaration order | 15 |
| `0050CA9E` | lexical `i`, `attribute`, and `cost` scopes | 16 |
| `0050CC25` | `i` scoped inside the charged path | 8 |
| `0050CE68` | outer-loop `i` and per-entry `prereq_count` scopes | 14 |

Each target keeps its original size, frame, call set, control-flow shape,
operand widths, and external memory operations. Closure checks report no exact
owner regressions. The remaining differences are private local displacement
coloring. The stack-overlap objection still prevents unconditional accepted
drift approval.

A 120-order declaration lab for `0050CE68` with these scopes produced only two
code groups. Its best group remains 14 bytes. The four target checks were
rebuilt after the follow-up probes on 2026-09-09.

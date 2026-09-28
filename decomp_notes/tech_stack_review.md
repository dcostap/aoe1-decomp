# Tech scalar-storage investigation

Base: `ef479e9e7`. Review the four remaining Tech functions against their complete original instruction ranges.
No game was run. This review does not change the exact-match rules.
The 2026-09-28 assignment reopened the older accepted-drift conclusions.
This file preserves prior evidence; per-function re-reviews record current
findings and limits. No registry status changed in that assignment.
The stack proof is conditional. The overlap objection below is a generic
malformed-input counterexample. The complete direct-caller review below tests
whether it applies to the assigned call sites.

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

The current source's frame-offset mappings use decimal EBP-relative offsets.
The 2026-09-28 direct checks show:

- `tech_cost`: tech -12 to -4; total -8 to -8; carry flag -4 to -12.
- `check_tech_cost`: tech -16 to -8; carry -12 to -12; float cost -8 to -24; index -24 to -16; attribute -20 to -20.
- `start_research`: tech -8 to -4; float cost -4 to -8; index -16 to -16; attribute -12 to -12.
- `check_for_new_tech`: tech -28 to -16; outer index -24 to -24; active count -8 to -8; changed flag -4 to -12; prerequisite count -12 to -28; done count -16 to -4; inner index -20 to -20.

These mappings correct the earlier table in this note. They come from the
fresh original and rebuilt instruction listings, not from type names alone.

Unlisted accessed slots retain their original positions.
Byte padding read by a wider flag load is removed by the same immediate mask before use.
No uninitialized padding affects a branch, call argument, return value, or external write.

When caller-accessible storage is disjoint from the private frame, the permutation preserves values and external memory operations.
It then preserves arithmetic, x87 flags, callee effects, cleanup, and returns.
This condition does not establish the project's required stack-overlap behavior.

### Stack-overlap objection

The source interfaces do not establish that every input object avoids the private frame.
The project also preserves malformed and stack-overlapping inputs; do not assume disjointness without evidence.

For the current `tech_cost` build, let the first output reference point to
EBP-4 in the eventual callee frame. The original stores the carry flag there;
the rebuild stores the tech pointer there. The first minus-one output write
therefore changes different live values. The later carry-result store repairs
the original flag. It does not repair the rebuilt pointer. The write replaces
the pointer's low word with `FFFF`. With a mapped original tech record and an
unmapped changed address, the rebuild can fault at its first tech-flag read.
The instruction sequence proves the order: pointer store at `0050C74B`, output
write at `0050C757`, carry-result store at `0050C793`, and tech-flag read at
`0050C7B8`.
The original pointer remains intact at EBP-12. Use a valid tech row with all
three `attribute_used` bytes zero and valid, disjoint remaining outputs. The
original returns; the rebuilt pointer read can fault. This is a static
instruction counterexample, not an executed test.

The counterexample proves a behavior difference for this crafted raw pointer.
The caller audit below found no target callsite that supplies one. Whether
such fabricated frame pointers belong to the supported input domain remains
unresolved. The earlier draft approval relied only on disjointness. Event
`c2db7184ed40c0ca530e6189ab8d2b8373bbe81d9d27b5464cc5658fa5e5de79` preserves
that rejected draft. The follow-up caller review below supplies evidence for
the reviewed direct call sites. It does not test fabricated pointers into a
future callee frame.

The separate declaration-order lab tested all 24 orders of the four `start_research` locals.
All compile. They produce two 334-byte outputs, each with 22 differences. None matches.
Preserve the complete lab; retain none of those source-only ordering changes.

Eleven pointer, const-pointer, and reference binding variants also compile without an exact result.
The cost-query binding variants reach 15 differing bytes, but still change private stack locations.
Retain none of these binding changes merely for a lower byte count.

## Integration

Retain the double-literal repair and the later natural scope improvements.
The older caller review proposed private-storage drift for these functions.
The 2026-09-28 assignment reopened those claims. See the per-function
reassessments for current evidence and limits. This file makes no new
registry status decision.
Keep the simplest scalar source. Do not add fake records, local aliases, or extra declarations to force stack positions.
The older module audit reported 29 exact functions and four nonexact target
functions. It is not a result from the 2026-09-28 assignment.

The final closure compares all 33 defined Tech bodies against the baseline.
Only the two comparison opcodes change, from D8 to DC. All other instruction bytes remain unchanged.
The literal pool grows from sixteen bytes to twenty-four bytes, including double alignment.
Five literal reads retain their complete values; only the two repaired reads change width.
The constructor's float 7.03 stays at pool offset zero. The progress function's float 100 moves from twelve to twenty.
Both unchanged functions retain the same four-byte reads and values.
Their whole-pool reference descriptions therefore change without changing their actual constant operands.
The proof also retains every mutable string's name, offset, contents, and section properties.

## Follow-up caller and storage review

The direct target references provide static caller coverage for the two
target functions. `tech_cost` is called at `0049A2F4`, `00512C19`, `00513110`,
and `0051460D`. Its output addresses are caller-owned locals or forwarded
caller objects. The call at `0049A2F4` aliases two outputs to the same short
slot. All reviewed destinations are above the target frame. A fabricated
pointer into future callee storage remains untested.

`check_tech_cost` is called at `0050C78E`, `0050CC4E`, and `00513D70`. The
first call passes null. The second passes the `first_in_stack` input-area
address through `start_research`. The third forwards the `command_research`
local through `TRIBE_Player::check_tech_cost`. Each nonnull address remains
above the target private frame. No direct caller constructs a pointer into
future callee-owned storage.

The review covers caller-owned aliases. The original write order and external
memory operations match at the reviewed callsites. The old stack-overlap
counterexample still distinguishes arbitrary fabricated input pointers. The
current proposal is limited to the reviewed executable callsites; it is not a
proof for every possible machine-state pointer.

`DAT_005766d8` is a separate linked-storage check for `check_for_new_tech`.
The original global dump proves an eight-byte read-only double at `005766D8`,
with eight zero bytes and one reference at `0050D054`. The canonical header
declares `double DAT_005766d8`; `src/game_globals.cpp` defines it as
`double DAT_005766d8 = 0.0`. The Tech object has one external COFF relocation
for that symbol, at `.text+0x1816` in the original object view and function
offset 494 in the fresh object. The fresh full link map resolves the symbol
from `game_globals.obj` at `005FA038`. PE inspection places it in the rebuilt
`.data` zero-fill tail, proving the linked initial value is zero. This storage
proof supports a `0050CE68` drift proposal. The rebuilt section is
writable `.data`, unlike the original read-only `.rdata`; the complete
reference scan finds no executable write or second reference. This is a
separate global-storage section issue, not a private stack-slot effect.

## Follow-up source probes

The retained ordinary source forms preserve size, frame, and call set while
reducing local displacement drift:

| Function | Retained source shape | Current differing bytes |
|---|---|---:|
| `0050C730` | `total`, `tech`, and `can_use_carry` declaration order | 15 |
| `0050CA9E` | lexical `i`, `attribute`, and `cost` scopes | 16 |
| `0050CC25` | `i` scoped inside the charged path | 8 |
| `0050CE68` | outer-loop `i` and per-entry `prereq_count` scopes | 14 |

Each focused comparison keeps the original size, frame, call set, control-flow
shape, operand widths, and external memory operations. Closure checks report
no exact-owner regressions. The remaining byte differences are private local
displacements. The reviewed callers limit the overlap concern but do not prove
behavior for fabricated pointers into the future frame. Focused checks also
leave linked numeric dependencies unknown.

A six-order declaration lab for `0050C730` used state
`1f1f55323a10a918a157a2fc3be1caed594df19f4ff272404972bb227bc0edd1` and finding
event `10d039bc1c246f08db9843623c867831a7d9f2e35b01b9cf192dd78fb9e97c3a`.
Its report is
`build/variant_lab/0050C730_tech_cost/20260929_002403/summary.txt`. All variants
kept size, frame, and call set. They produced two mismatch groups; neither
restored the original local-slot map.

A 120-order declaration lab for `0050CE68` with these scopes produced only two
code groups. Its best group remains 14 bytes. The four target checks were
rebuilt after the follow-up probes on 2026-09-09.

## Final assigned caller and storage review

`0050CC25` has exactly two direct call sites: `004D23D9` from
`TRIBE_Action_Make_Tech::first_in_stack` and `00513D8F` from
`TRIBE_Player::pay_tech_cost`. The first passes a caller-owned output slot at
`ESP+4`; the second passes null. Both destinations are above the future
`0x18`-byte callee frame. No direct caller passes a pointer into that frame.

`0050CE68` has exactly six direct call sites: `0050C4EE`, `0050C554`,
`0050C5D4`, `0050C644`, `00512887`, and `0052C355`. The method has no pointer
argument or output. It passes only its receiver and a short value to
`do_tech`; no local address escapes. The complete slot mappings are private
permutations within the unchanged frame. The reviewed direct callsites support
proposals for the eight CC25 bytes and 14 CE68 bytes. They do not prove
equivalence for arbitrary fabricated future-frame pointers. Do not force exact
local stack spelling without new behavior evidence.

The original `DAT_005766D8` record is a read-only eight-byte zero double. Its
only executable reference is the `fcomp` at `0050D054`. The fresh Tech object
has one external COFF relocation for `?DAT_005766d8@@3NA` at function offset
494. The fresh full link map resolves the symbol from `game_globals.obj` at
`005FA038`, and PE inspection places that address in rebuilt `.data` zero-fill
tail. The linked value is therefore zero. The generic linked-reference audit
reports this nonmatching code window as unknown; the map and PE inspection
are the direct linked-storage evidence.

The caller and storage findings are recorded in experiment events
`4d3ef49dc278511225a396a8d220b0c7a221a7fee8553b98b07cfd8e0926335c` and
`0c2736f249bb1f93b78769a4c10905ba689456b20a316d8a389d986f8fcec7da`.
The final one-job module report is
`build/validation/drift-020-tech-final/functions/report.txt`. It compiled all
33 Tech functions: 29 matched and four stayed nonmatching. It reports no
compile errors or failed exact claims. The owner report is
`build/validation/drift-020-tech-final/owners.txt`; all 29 matching owners
passed, with no mismatch or repair item. The function report's action queue
lists `hold_accepted_drift` for four rows. This tool output does not approve
them.
The orchestrator owns final status changes.

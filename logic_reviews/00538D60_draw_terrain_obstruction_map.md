# Logic review: 00538D60 `RGE_View::draw_terrain_obstruction_map`

## Phase transition

The main agent suspended ordinary exact matching after eight claims, 47
meaningful probes, 69 checks, donor and ABI work, and focused natural source
variants. The candidate remains
`src/scratch/00538D60_draw_terrain_obstruction_map.cpp`.

Current validated checker state:

- original/rebuilt size: 250/250 bytes;
- frame: none / none;
- saved registers: `EBX`, `EBP`, `ESI`, `EDI` in both;
- calls: 4/4 in exact order with matching targets;
- instructions: 80/80;
- conditional branches: 3/3;
- jumps: 1/1;
- returns: 1/1;
- instruction shape and exact-block coverage: 100%;
- strict difference: two SIB bytes at `00538E20` and `00538E24`;
- edit/resync cost: two bytes.

The two differences exchange SIB base and index registers in commutative address
sums. Matching work tested coordinate order, grouping, temporary coordinates,
local widths, declaration order, ABI surfaces, translation-unit context, and
focused variants. All recent natural forms emit the same two-byte basin.

The retained source uses typed view, draw-area, shape, game, and pathing surfaces.
It has ordinary nested loops and named fields. It contains no fake volatility,
manual vtable calls, raw absolute dereferences, or codegen-only control flow.

### Semantic questions at entry

1. Verify the initial `CurSpanList` write, shape draw call, and argument order.
2. Verify tile scaling, four-by-four loop bounds, and signed arithmetic behavior.
3. Verify both path obstruction coordinates and the unsigned-byte return width.
4. Verify the positive obstruction predicate and `obstruction - 1` frame value.
5. Verify draw coordinates, constants, and update order across both loops.
6. Verify object and global offsets, virtual/direct call surfaces, and cleanup.
7. Verify integer overflow, aliasing, malformed-pointer fault order, and partial writes.
8. Verify all memory effects and the `__thiscall` six-argument return cleanup.

## Review rounds

Pending.

## Main-agent adjudication

Pending.

## Integrated changes

The main agent validated the unchanged normalized source at 250 bytes and two
strict differing bytes before phase entry.

## Final decision

Pending.

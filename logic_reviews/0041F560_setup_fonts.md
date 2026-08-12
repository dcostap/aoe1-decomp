# Logic review: 0041F560 `RGE_Base_Game::setup_fonts`

## Phase transition

The main agent suspended ordinary exact matching after five claims and 20 meaningful probes.

The candidate is `src/scratch/0041F560_setup_fonts.cpp`.

Current validation:

- rebuilt and original size: 410 bytes;
- calls, instruction count, and control flow align;
- strict difference: 50 bytes;
- rebuilt frame is `0x3C`; original frame is `0x40`.

Focused local-order, lifetime, parameter-home, and typed interior-pointer probes
all emitted duplicate code. The retained source preserves the executable's
interior `GetTextMetricsA` output pointer.

### Semantic questions at entry

1. Verify allocation, storage, and failure behavior, including the DC failure leak.
2. Verify each font ID, italic flag, and null-font path.
3. Verify the interior `TEXTMETRICA` pointer and shifted output interpretation.
4. Verify font array index selection and every width and height store.
5. Verify object selection, restoration, DC release, fault order, and returns.

## Review rounds

No review has started.

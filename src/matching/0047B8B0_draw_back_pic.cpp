// 0047B8B0 TScrollBarPanel::draw_back_pic
// Source: Pnl_scbr.cpp lines 765-799, size 180 bytes
// Attempt log:
// first: 176 bytes (4 short). Non-virtual TShape methods, direct calls.
// second: precomputed temps didn't change register allocation.
// third: inline function args, back_frame local var — same result.
// fourth: mark base offset fields volatile to force call-argument evaluation order; worsened scheduling (180B but 15.6% diff), rolled back.
// fifth: field-first add expressions; no change from best 176B family.
// sixth: explicit x/y locals immediately before shape_draw; optimized away/no change.
// seventh: local shape pointer for draw call; no change.
// eighth-tenth: /Ob0, /O2-no-/Oy, /O1 flag probes; no improvement (/O1 153B), flags removed.
// eleventh: volatile cast on both coordinate member reads; worsened to 15.6%.
// twelfth: volatile cast only on x/base field_10; worsened early branch distances.
// thirteenth: volatile cast only on y/base field_0C; worsened early branch distances.
// GIVEUP: best source is 176B, 4 bytes shorter than original. Remaining issue is localized inner-loop register allocation/eval scheduling.
//   Original computes x as mov eax,[esi+10h]; mov ecx,ebx; add ecx,eax and y as mov ecx,[esi+0Ch]; mov edx,edi; add edx,ecx.
//   VC5 rebuild folds to mov ecx,[esi+10h]; add ecx,ebx and mov edx,[esi+0Ch]; add edx,edi.
//   Behavior is equivalent, but check_function cannot compare because the function is 4 bytes short; not proposing accepted_drift without a comparable 180B low-diff build.
// Retry 2026-05-26 Boss pass: 13 more probes. Revalidated best source: 176B too short.
// Tried reversed coordinate expression order, explicit x/y locals, staged xbase/ybase adds,
// volatile xbase and ybase, draw_area/frame locals, shape local, while loops, for loops,
// swapped semantic draw args, back_frame local, void/uchar TShape return declarations, and
// flags /Ob0 /Oa /Og. All exact-size variants were broad regressions (best volatile-xbase
// 62 positional / 37 edit, first mismatch +19); all close variants stayed 176B. Still no
// accepted_drift proposal: the behavior-equivalent diff is localized, but the best source is
// short/truncated and exact-size variants are not localized.
// Luna47B8B0 baseline: natural nested inclusive tiling source is 176B; all calls/fields/CFG align,
// but VC5 folds each base-plus-cursor add into a memory-destination form.
// ABI probes: corrected TShape return/reference/parameter types and TDrawArea*; relocation symbols now match,
// with no codegen movement. Offset-first terms, coordinate locals, and a canonical TPanel base were duplicates.
// Volatile coordinate rereads reached exact size and 28-byte positional drift, but changed scheduling broadly;
// rolled back as diagnostic-only. Raw probes of one-sided volatility, long cursors, comma sequencing, and swaps
// did not produce the original order. Keep the ordinary source reconstruction, not the compiler-steering variant.
// probe Luna-002: restored the same inherited virtual surface used by exact Pnl_scbr.cpp
// draw donors; it emitted the unchanged 176-byte basin.
// probe Luna-003: use the proven full 0x20-byte TShape data surface and pointer ABI for
// shape_minmax, testing canonical declaration/layout context at the call site.
// probe Luna-004: declaration-only defaults for shape_draw's two zero arguments are
// tested next; this is a period-plausible call-site spelling, not a fake helper.
// probe Luna-005: register-qualified coordinate temporaries emitted the unchanged
// 176-byte basin; restored the direct call for the next layout probe.
// probe Luna-006: model the proven full 0xF4-byte TPanel base and derived size while
// retaining named ownership for all fields touched by this function.

// probe Luna-001: materialized back_frame immediately before shape_draw; VC5 optimized
// the local away and emitted the unchanged 176-byte basin; restored the clean source.

// Luna-001 result: materialized back_frame was optimized away; unchanged 176-byte basin.
// Luna-002 result: restored inherited Pnl_scbr donor virtual surface; unchanged basin.
// Luna-003 result: full TShape layout and pointer shape_minmax ABI; unchanged code and
// corrected the direct-call symbol to the proven pointer signature.
// Luna-004 result: shape_draw default arguments for the two zero tail values; unchanged.
// Luna-005 result: register-qualified coordinate temporaries; unchanged.
// Luna-006 result: full proven TPanel/TScrollBarPanel layout; unchanged.
// Luna-007 result: natural call-form and coordinate-axis labs collapsed to the same
// 176-byte basin. Volatile-both reached 180 bytes/28 positional diff bytes but moved
// scheduling broadly; diagnostic-only. Current blocker is the original cursor-copy/add
// setup with delayed base loads across constant pushes; no plausible non-volatile axis remains.

// Fresh independent pass 2026-08-09 (orch-luna-47b8b0-w1):
// New worker probe: reversed cursor/base addition terms from the original cursor-copy/add evidence; VC5
// canonicalized both forms to the same 176B/70-byte basin, so the clean natural spelling below is retained.
// probe-034 cursor-first compound coordinate locals: duplicate 176B basin; restored.
// probe-035 inline extent expressions: 164B / 170 positional diff, structural regression; restored.
// probe-036 declaration-only virtual destructors: duplicate 176B basin; restored.
// probe-037 same-TU /GX response-file context: duplicate 176B basin; flags removed.
// probe-038 base TPanel* alias for call-site fields: duplicate 176B basin; restored.
// probe-039 x-before-y coordinate locals: duplicate 176B basin; restored.
// probe-040 volatile field_20 pointer read: duplicate 176B basin; restored.
// probe-041 TPanel& alias for call-site fields: duplicate 176B basin; restored.
// Fresh-pass conclusion: retain the natural 176B reconstruction. The original 180B
// call setup still preserves cursor-copy/add instructions and delayed base loads that
// this TU/compiler basin does not emit; no behavior or call/ABI discrepancy found.

// Fresh bounded pass 2026-08-10 (orch-pnlscbr-01):
// probe-047 baseline: the clean natural nested-tiling reconstruction remained 176B/70 diff.
// probe-048 ABI: PDB/Ghidra's reference-parameter shape_minmax ABI changed no bytes, but is
// retained because it restores the actual C++ member declaration and relocation spelling.
// probe-049 liveness: volatile back_frame widened the body to 180B but changed the entry guard
// and broad scheduling; rolled back. probe-050 long dimension/cursor locals were a duplicate.
// probe-051 recomputing the x-step at the inner increment was a 165B structural regression.
// probe-052 coordinate temporaries plus volatile field rereads reached 180B/32 diff, but were
// compiler-steering diagnostics; probe-053 volatile frame reread was a 188B regression.
// probe-055: adding the period-plausible windows.h TU context with the reference ABI produced
// an exact 180B match. Keep the ordinary typed source and header context; no volatile/raw
// cursor experiment is part of the final reconstruction.

#include <windows.h>

#ifndef PNL_SCBR_CANONICAL_TU
#include "../../include/pnl_scbr_context.h"
#endif

void TScrollBarPanel::draw_back_pic() {
    if (this->button_pics != 0 && this->back_frame != -1) {
        long x_min, y_max, pic_hgt, y_min;
        this->button_pics->shape_minmax(y_max, pic_hgt, x_min, y_min, this->back_frame);

        int row_step = (x_min - y_max) + 1;
        int col_step = (y_min - pic_hgt) + 1;
        int outer = 0;

        if (this->field_18 >= 0) {
            do {
                int inner = 0;
                if (this->field_14 >= 0) {
                    do {
                        this->button_pics->shape_draw(
                            this->field_20,
                            this->field_0C + inner,
                            this->field_10 + outer,
                            this->back_frame, 0, 0);
                        inner += row_step;
                    } while (inner <= this->field_14);
                }
                outer += col_step;
            } while (outer <= this->field_18);
        }
    }
}

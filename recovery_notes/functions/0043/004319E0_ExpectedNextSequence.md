# Recovery journal: 004319E0 `ExpectedNextSequence`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/com_q.cpp`.
- PDB source: `C:\msdev\work\age1_x1\com_q.cpp`.
- Earlier recovery note: `recovery_notes/com_q_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:dcd83e9bffed5bda7450 -->
### `8ff7222d4d26` `src/scratch/004319E0_ExpectedNextSequence.cpp:1-12`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// 004319E0 RGE_Communications_Queue::ExpectedNextSequence
// Default flags.
// HollowSnowdrop pass: body through the loop matches exactly; remaining mismatch was localized to final byte-mask return tail.
// MidnightLily attempts:
// - Baseline confirmed loop body exact; original tail is `or cl,0xff; pop edi; cmp cl,bl; mov ecx,[global]; sbb al,al; pop esi; not al; pop ebp; and eax,ecx`.
// - Try 1: `unsigned char c=0xff; if (c >= seq) return global; return 0;` improved tail to edit diff 9 but VC5 loads global before `or al,0xff` and uses AL, not CL.
// - Try 2/3: derive `c`/temp from `this` to encourage CL (`(unsigned char)(unsigned int)this`, byte of int temp); optimized back to AL tail.
// - Try 4/5: mask local and `register unsigned char c`; same AL/register family.
// - Try 6/7: result/local and ok-before-global forms changed not width/order (`not eax`, ECX mask) but still not original CL tail.
// - Try 8: attempted `&this` byte expression; VC5 rejects `&` on `this`, rolled back.
// - Try 9: /O1 probe wrong size/family (84 bytes), flag removed.
// Left in scratch: best source below has exact loop/body and equivalent return logic; blocker is final tail register/order selection (CL vs AL and pop/global-load order). No inline asm/hacks.
```
<!-- end-recovered:dcd83e9bffed5bda7450 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.

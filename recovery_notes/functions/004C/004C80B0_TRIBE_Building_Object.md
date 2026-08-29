# Recovery journal: 004C80B0 `TRIBE_Building_Object`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/t_b_obj.cpp`.
- PDB source: `C:\msdev\work\age1_x1\t_b_obj.cpp`.
- Earlier recovery note: `recovery_notes/t_b_obj_module.md`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:4823f033c1a60f146823 -->
### `7f3355354a67` `src/scratch/004C80B0_TRIBE_Building_Object.cpp:1-49`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 004C80B0, TRIBE_Building_Object::TRIBE_Building_Object, 282 bytes
// Source: t_b_obj.cpp lines 93-103
// Status: SCRATCH
//
// Constructor for TRIBE_Building_Object. Accepts 6 params (this + 6 stack):
//   TRIBE_Master_Building_Object* mb, RGE_Player* player,
//   float f1, float f2, float f3, int flag
// Returns `ret 18h` (6 params × 4 = 0x18).
//
// Function flow:
// 1. SEH prologue: push -1 cookie, push __except_handler3, save/install FS:[0],
//    push ecx (save this as local)
// 2. Load params (param_3→eax, param_1→edx, param_4→ebp, param_5→edi)
// 3. Save regs (ebx, ebp, esi, edi), zero ebx
// 4. Call TRIBE_Combat_Object(this, mb, player, f1, f2, f3, 0)
// 5. SEH cookie = 0 (survived base ctor)
// 6. production_queue_need_attr = -1 (ax from or eax,-1)
// 7. unique_build_id = -1 (eax)
// 8. production_queue = 0, size=0, count=0, enabled=1, actions=0,
//    change_flag=0, auto_paused=0, DoppleInstalled=0
// 9. vftable = TRIBE_Building_Object vftable
// 10. If flag != 0: setup(mb, player, f1, f2, f3)
// 11. ftol(world_y) → row; ftol(world_x) → col
// 12. DoppleInstalled = owner->doppleganger_creator
//        ->add_doppleganger_check(this, &unified_map_offsets[row] + col*4)
// 13. PriorMap1-3 = 0, PriorTurn1-3 = 0
// 14. SEH epilogue: restore FS:[0] from saved local
// 15. return this
//
// Matching notes:
// - Default /O2 /Oy omitted the constructor EH chain; the donor-proven /GX
//   context emits the original VC5 FS:[0] registration and cleanup.
// - The root polymorphic base preserves the proven offset-zero vptr and the
//   named +0x0C owner, +0x38/+0x3C world coordinates, and +0x1C8 fields.
// - The original delays the derived vptr store until after field initialization.
//   A novtable/manual-vptr diagnostic matched, but project policy rejects explicit
//   vptr stores as living source; the canonical polymorphic class is retained.
// - Probes: adding donor virtual-destructor surfaces enabled /GX EH; replacing
//   the explicit polymorphic root with a flat/empty-base model broke the call
//   ABI. Typed player/master/global map ownership is codegen-identical.
// - The natural candidate is 282 bytes with exact size/frame/call/CFG parity;
//   only the derived-vptr timing differs. The earlier novtable/explicit-vptr
//   experiment was byte-exact but is rejected by source policy. Keep this
//   canonical polymorphic source in scratch for a later context investigation.
// - Restored the donor-proven virtual int setup declaration; emitted code and
//   the vptr hunk were unchanged, so this is retained as the cleaner ABI.
// FLAGS: /nologo /c /O2 /Oy /GX
// Main-agent audit restored canonical master/player destructor ownership and
// retained natural compiler-managed vptr lowering.
```
<!-- end-recovered:4823f033c1a60f146823 -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.

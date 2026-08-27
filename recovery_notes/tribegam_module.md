# tribegam.cpp source reunification

PDB source: `C:\msdev\work\age1_x1\tribegam.cpp`.

The module owns 118 normal functions. Their source order follows the PDB line bands from 160 through 5691. The compiler-facing source is `src/tribegam.cpp`. The shared module declarations are in `include/tribegam.h`.

## Evidence

- The packet lists 107 matching, two accepted-drift, eight scratch, and one verified-logic owner.
- The packet lists the compiler-generated vector-deleting destructor at `00521380`, symbol `??_ETRIBE_Game@@UAEPAXI@Z`, size 30. It is emitted by the natural `TRIBE_Game` virtual destructor surface. It is not a normal source owner.
- The pre-migration wrapper and final source object both emit the weak `??_E` identity and the defined `??_G` fallback body. The generated body has the same four relocation-placeholder differences in both objects.
- The grouped source order is the packet order. It is not VA order at the start because `video_sub_wnd_proc` precedes the constructor in the PDB line stream.
- The full source compiles with the pinned VC5 compiler and `config/flags/00521120_TRIBE_Game.rsp` (`/nologo /c /O2 /Oy /GX`).
- The earlier mechanical consolidation matched the pre-migration wrapper for the 115 publicly named normal owners checked. Static owners at `00523AE0` and `00526170` need address-based grouped validation.
- The final source cleanup uses the period SDK record and API names in `setup`. This changes that existing scratch owner from the wrapper's 1984-byte emitted body to a 2000-byte emitted body. The packet boundary is 2061 bytes. This is a recorded source-recovery regression, not an exactness promotion.
- The existing 21 registered exact anchors remain byte-identical in the final source object. The 2-byte `calc_timing_text` difference was already present between the wrapper and the normalized source context.

## Migration changes

- Merged all 118 reviewed source-bank bodies into one natural source file in PDB order.
- Replaced the wrapper-only local context with the module header.
- Removed source-bank fallback class declarations and context-selection guards from the compiler-facing source.
- Normalized fragment-relative include paths for the new source location.
- Kept the existing nonexact source states. This migration does not promote accepted drift, scratch, or verified logic.

## Exactness regression record

The reunified source preserves the pre-migration wrapper object for the 21 registered exact anchors and for the publicly named owners not affected by the SDK cleanup. The `00521790` setup change is the only new broad difference. The prior grouped wrapper already had nonexact owners outside its 21 registered exact anchors. Those results remain unresolved and are not promoted by this migration.

The source-module metadata records the complete normal owner set. The
`tribegam_prefix` registration now uses `src/tribegam.cpp`.

## Open work

- The post-repair candidate validates all 21 registered owners. Each reports
  `MATCH` and `0.0000%`, with matching ownership, boundaries, relocations, and
  direct targets.
- Keep the generated destructor as a separate generated-entry check.

# 0047E5D0 `XYZ::rotateXYByFacet`

- PDB source: `point.cpp`, lines 86 to 109.
- Original size: 147 bytes.

The function is an exact registered owner.

The named `y1` product is required. VC5 then evaluates `c * dy` before `s * dx`. This preserves the original FPU operation order after `__ftol`.

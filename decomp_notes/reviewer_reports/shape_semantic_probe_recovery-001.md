# Review: Shape semantic probe

## Scope

This review covers direct helper validation for 12 Shape renderer bodies. It
covers no public dispatcher, constructor, or malformed-input behavior.

## Behavior

The corrected fixture derives helper endpoints from raw dispatcher rectangles:

- `helper_right = min(raw_right, shape_right)`.
- `helper_bottom = min(raw_bottom, actual_shape_bottom)`.
- Mirror clipped y is `max(raw_y, clip_top)`.

The driver reads authoritative `cases.bin` directly. It verifies record size,
FNV32, count, stream encoding, helper arguments, clamps, and contracts.
It compares all 16,384 accessible destination bytes.

The valid run executed 1,636,512 records and 766,552 unique invocations. It
reported zero failures. The fault and incomplete-count controls returned
nonzero. The direct-helper scope is explicit.

## Source

No game source, header, registry, flag, or repository test changed. The
existing member-pointer adapter remains test interop only.

## Bytes

The closure remains unchanged: 26 owners, 12 exact, 11 mismatches, two
boundary reports, and one accepted drift. The semantic probe makes no byte or
status claim.

Corrected archive:
`17945028157330c1dd1279e5f71cff37a87aeb74c28e0d7cea3ffd273809c8ff`.

## Integration

Verdict: **APPROVE** evidence preservation. Hold all statuses. Keep the row
repairs at `004B9E20` and `004BB910`, and accepted drift at `004B99F0`.

Correction event:
`a2e458fb289527bfedcd6559d2b8434eefeb5d4f9320252974bbe587e3903ea9`.
First review event:
`3eca57c2b3beaacc66259e4e1e4643b8187fa8374b740f4f115315541484c9db`.
Final review event:
`9f383aea644ae09936e7f35302840bfb4ee2c437844576ca0e686a45bcae9f4f`.

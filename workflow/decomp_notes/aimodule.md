# aimodule.cpp source module

## PDB context

- PDB source: `C:\\msdev\\work\\age1_x1\\aimodule.cpp`.
- The module has 66 normal owners in ascending PDB address order.
- The normal owner byte total is 2,284 bytes.
- The owning classes are `AIModuleID`, `AIModuleMessage`, and `AIModule`.
- The module header proves the 0x48-byte `AIModuleID`, 0x138-byte
  `AIModuleMessage`, and 0xF0-byte `AIModule` layouts.
- The registered module uses `config/flags/gx.rsp`.

## Source result

The module has one compiler-facing source file: `src/aimodule.cpp`.
It contains all 66 normal owners in PDB order.
The module has no wrapper source, `.cpp` include, or context macro.

The prior source banks supplied 65 matching owners and one accepted-drift owner.
The migration keeps these statuses.

`0040E520` `AIModule::setLogCommonHistory` now matches all 149 bytes.
See `workflow/decomp_notes/functions/0040/0040E520.md` for the source and evidence.

## Generated entries

The compiler emits deleting destructors near this module.
The three nearby entries at `0040DDF0`, `0040DF30`, and `0040E2B0` are generated.
They are not normal PDB owners and have no source definitions.

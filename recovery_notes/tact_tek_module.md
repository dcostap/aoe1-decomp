# tact_tek.cpp recovery notes

## PDB context

The PDB names `C:\\msdev\\work\\age1_x1\\tact_tek.cpp` as the source module.
The nine normal owners use one `TRIBE_Action_Make_Tech` class and appear in this
source and address order:

| VA | PDB lines | Owner | State |
| --- | --- | --- | --- |
| 004D21B0 | 29-34 | `TRIBE_Action_Make_Tech::TRIBE_Action_Make_Tech(int, RGE_Action_Object*)` | scratch |
| 004D2250 | 41-45 | `TRIBE_Action_Make_Tech::TRIBE_Action_Make_Tech(RGE_Action_Object*, short, int)` | accepted drift |
| 004D2290 | 49-64 | `TRIBE_Action_Make_Tech::~TRIBE_Action_Make_Tech()` | scratch |
| 004D2370 | 68-73 | `TRIBE_Action_Make_Tech::save(int)` | matching |
| 004D23B0 | 76-98 | `TRIBE_Action_Make_Tech::first_in_stack(unsigned char)` | scratch |
| 004D2440 | 102-106 | `TRIBE_Action_Make_Tech::set_state(unsigned char)` | matching |
| 004D2450 | 109-134 | `TRIBE_Action_Make_Tech::update()` | scratch |
| 004D2550 | 138-147 | `TRIBE_Action_Make_Tech::stop()` | scratch |
| 004D25E0 | 151-164 | `TRIBE_Action_Make_Tech::get_info(short&, short&, char*, short)` | accepted drift |

The nearby VA 004D2230 vector-deleting destructor is compiler generated. It is
not a normal source owner.

The class inventory proves `TRIBE_Action_Make_Tech` size `0x48`, base
`RGE_Action`, and virtual `set_state` slot `0x5C`. The module header records the
reviewed declarations and field offsets used by this module.

## State evidence

The five matching owners were registered in the former wrapper and had zero
positional diff before this consolidation: 004D21B0, 004D2370, 004D23B0,
004D2440, and 004D2550.

VA 004D2250 remains accepted drift. Its constructor stores the same base state,
unique ID, action type `0x67`, and technology ID. The prior isolated result
showed only constructor store-order drift.

VA 004D25E0 remains accepted drift. It writes the technology ID and progress,
gets the optional technology name, calls `strncpy`, and writes the final null.
The prior isolated result differed only in the commutative SIB base/index order
for the final byte store. The fresh consolidated-module result is a one-byte
positional mismatch with the same owner, boundary, and call targets.

VA 004D2290 remains scratch. The destructor has EH framing, cancels research,
checks game state, sends two notifications, and calls the base destructor. The
former isolated scratch source had unresolved frame and register topology. The
consolidated source now emits an exact grouped body. The metadata keeps the
scratch state because this migration does not promote an owner.

VA 004D2450 remains scratch. The update method dispatches states one and six,
computes research work, calls `research`, and reports completed research. The
current natural source preserves these paths. Its grouped code shape and
register allocation remain unresolved.

The prior consolidated-module sweep compiled all nine owners. The five
registered matching owners remain `MATCH` with zero positional diff. The
004D2250 accepted-drift owner has a nine-byte positional mismatch. The
004D25E0 accepted-drift owner has a one-byte positional mismatch. The destructor
at 004D2290 emits an exact grouped body, but remains scratch until a reviewed
promotion changes its durable state. The update owner remains a 235-byte
positional mismatch. All nine owners have matching PDB ownership, relocations,
and boundaries.

After canonical `tplayer.h` and `tech.h` cleanup, a grouped candidate reports
exact `MATCH` only for `004D2370` and `004D2440`. `004D21B0` differs by 111
bytes, `004D23B0` by 83 bytes, and `004D2550` by 95 bytes. All three retain
matching owner, relocation, and boundary data. They are scratch. The existing
drift and scratch owners remain unpromoted.

This consolidation removes wrapper-only includes, context macros, fallback
class declarations, and per-function source fragments. It does not change the
module header or the reviewed state labels.

The former destructor-only `/GX` response file was stale after consolidation
and is removed. The module uses the tracked `config/flags/default_gx.rsp`
response file because the constructor and destructor both use EH frames. The
two target-specific response files are removed. No shared header, ABI, tool,
or global flag changed.

# Translation-unit closure audit

## Scope

The original PDB has 224 C/C++ source modules in this recovery set:

- 223 `.cpp` modules;
- 1 `.c` module.

`config/source_modules/` now has these 224 manifests. The registry has 221
groups with registered exact owners. `act_obj_cpp`, `com_obj`, and `stat_obj`
have natural source manifests but no registered exact owner.

`tech.obj` is not one of the 224 C/C++ modules. Its PDB stream has no source
line records and no `S_GPROC32` records. Its reviewed contribution is now
`config/auxiliary_contributions/tech.json`. The manifest records 33 observed
bodies and the immutable stream evidence. It does not claim PDB source or
symbol ownership for any body.

`tools/common.py` validates this auxiliary manifest. Strict source-module
inventory also validates its PDB stream evidence.

## Ownerless normal records

The initial ownerless normal set had 24 records. Direct executable evidence
split it into 20 virtual destructor thunks and four header-attributed methods.

The 20 thunks now use the compiler-generated corpus bucket. Each thunk is a
five-byte jump to its base destructor. Each has the matching deleting
destructor entry in `config/compiler_generated_functions.txt`:

```text
00402030 00402B90 00402F30
00503D20 00504090 005041B0 00504460 00504740 005048C0 00504C80
00505990 00506310 005068A0 00506C60 00507190 00507A20 00508100 00508310
0050B490 00519E90
```

The four remaining normal records have no proven `.cpp` owner:

```text
0046ED40 RGE_Player::logStatus       player.h
00540A10 RGE_Game_World::logStatus   world.h
00431F60 MsgQueue::MsgQueue           com_q.h
00431F80 MsgQueue::~MsgQueue          com_q.h
```

The natural bodies now remain in the canonical headers: `player.h`, `world.h`,
and `com_q.h`. The PDB maps them to headers, not to an owning compiland. They
remain explicit unresolved ownership. No source-module owner was invented.
`RGE_Player::logStatus` and `RGE_Game_World::logStatus` no longer have
duplicate definitions in their `.cpp` modules. The `MsgQueue` bodies were
already in `com_q.h` and remain unchanged.

Focused header-owner validation covers all four rows. It confirms the two
`logStatus` bodies are empty and the two `MsgQueue` bodies keep their field
stores, delete call, boundary, and direct target. No translation-unit owner is
registered for these header rows. The Player, World, and communications-queue
objects report `MATCH`, `0.0000%`, with the PDB-qualified symbols
`?logStatus@RGE_Player@@UAEXPAU_iobuf@@H@Z`,
`?logStatus@RGE_Game_World@@MAEXPAU_iobuf@@H@Z`,
`??0MsgQueue@@QAE@XZ`, and `??1MsgQueue@@QAE@XZ`.

## Header bodies and residue

The 101 normal header-attributed rows from the standalone audit now have
canonical bodies in their owner headers. Their former 99 matching probes and
two scratch probes are deleted. The header groups are `stat_obj.h` (68),
`panel.h` (14), `player.h` (7), `aimodule.h` (3), `dlg_list.h` (2),
`move_obj.h` (2), `scenario.h` (2), `aiuaimod.h` (1), `ani_obj.h` (1), and
`utmarray.h` (1).

Focused VC5 emission checks report positional `MATCH` for the 68 Static Object
rows, the Panel, Player, AIModule, dialog, moving-object, Scenario,
UnitAIModule, and animated-object rows. `0043F320` remains scratch and is not
promoted by this structural check. `004147A0` emits the current public
`resize` body, but its PDB-proven protected symbol is still missing.

The 22 context-macro fragments had header line records and no proven `.cpp`
owner. Their bodies now remain in the canonical headers:

- `include/basegame.h`: 17 BaseGame methods;
- `include/m_s_obj.h`: 2 static-object methods;
- `include/pnl_msg.h`: 3 message-panel methods.

The addressed rows are:

```text
0041C250 0041C260 0041C6E0 0041C6F0 0041C700 0041C710 0041C720
0041C730 0041C740 0041C750 0041C760 0041C770 0041C780 0041C790
0041C7A0 0041C7B0 0041C7C0
0044FE20 0044FE30
0047A160 0047A170 0047A180
```

The adjacent `0041C240` header method also moved into `include/basegame.h`.
The 22 macro fragments and this adjacent fragment are deleted. Their source
was only a copied declaration and a context guard. Their body semantics remain
in the canonical header declarations.

`src/scratch/004D3990_update.cpp` was not an inventory function. The original
body is `004D3980-004D39DC`, and `004D3990` is an interior address in that
constructor. The scratch file also used a raw vptr store. It is deleted.

The tree had four unreferenced scratch test files, not three:
`__stdcall_test.cpp`, `00999999_vcall_test.cpp`, `test_seh.cpp`, and
`test_size.cpp`. All four are deleted. None was in a build manifest.

## Current counts

After this closure, the status view reports:

- 5,428 normal records;
- 256 compiler-generated records;
- 167 unclaimed normal records;
- 221 registered translation-unit groups;
- 224 natural C/C++ source-module manifests;
- 1 auxiliary no-line contribution manifest.

The unclaimed normal records include the 105 explicit header ownership rows,
the removed header fragments, and other reviewed exceptions. They are not
silent exact-owner claims.

## Validation

The focused validation for this audit is:

```text
python tools/generate_source_module_inventory.py --strict
python tools/validate_translation_units.py
python -m unittest tests.test_pdb_no_line_info tests.test_common_compiler_generated
```

The final observed sweep compiled all 221 groups. It proved every registered
owner and found no registered regressions.

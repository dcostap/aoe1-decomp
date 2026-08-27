# tm_tre_o.cpp source-module recovery

## Source and order

- PDB source: `C:\\msdev\\work\\age1_x1\\tm_tre_o.cpp`.
- Source: `src/tm_tre_o.cpp`.
- Header: `include/tm_tre_o.h`.
- Flags: `config/flags/0050F3A0_make_new_master.rsp`.
- Shard: Terra-6.

The PDB lists five normal owners. Their source order is:

1. `0050F180` `TRIBE_Master_Tree_Object::TRIBE_Master_Tree_Object`, lines 21-27.
2. `0050F220` `TRIBE_Master_Tree_Object::TRIBE_Master_Tree_Object`, lines 32-38.
3. `0050F2A0` `TRIBE_Master_Tree_Object::TRIBE_Master_Tree_Object`, lines 43-49.
4. `0050F320` `TRIBE_Master_Tree_Object::make_new_obj`, lines 53-55.
5. `0050F3A0` `TRIBE_Master_Tree_Object::make_new_master`, lines 59-61.

The normal owner sizes are 97, 113, 123, 122, and 98 bytes. Their total is
553 bytes. The PDB source bands and address sequence prove this module owner.

## Binary evidence

The five normal owners were registered exact before this move. Each old check
reported `MATCH` and zero positional differences. The registered symbols are:

- `??0TRIBE_Master_Tree_Object@@QAE@PAV0@H@Z`
- `??0TRIBE_Master_Tree_Object@@QAE@HPAPAVRGE_Sprite@@PAPAVRGE_Sound@@H@Z`
- `??0TRIBE_Master_Tree_Object@@QAE@PAU_iobuf@@PAPAVRGE_Sprite@@PAPAVRGE_Sound@@FH@Z`
- `?make_new_obj@TRIBE_Master_Tree_Object@@UAEPAVRGE_Static_Object@@PAVRGE_Player@@MMM@Z`
- `?make_new_master@TRIBE_Master_Tree_Object@@UAEPAVRGE_Master_Static_Object@@XZ`

The nearby `0050F1F0` scalar-deleting destructor is 30 bytes. It calls the
`0050F210` derived destructor, tests the delete flag, calls `operator delete`,
and returns the object. `0050F210` is a five-byte tail jump to
`RGE_Master_Static_Object::~RGE_Master_Static_Object` at `00452FA0`. This is
compiler-generated destructor code, not a handwritten source owner.

`0050F20E` is the reviewed padding-only boundary. It stays outside the source.
The old `src/scratch/0050F210_TRIBE_Master_Tree_Object.cpp` was not a valid
owner. It declared `destroy()` instead of the destructor symbol. The natural
virtual destructor declaration now supplies the correct compiler-generated
surface. The parent must confirm both generated destructor entries.

## Proposed declarations

`include/tm_tre_o.h` includes canonical `include/m_s_obj.h` directly. It adds
no copied base layout. `TRIBE_Master_Tree_Object` declares its virtual
destructor, three constructors, and the two factory overrides. It includes
`<stdio.h>` so its public `FILE*` constructor declaration is self-sufficient;
the typedef produces the PDB `PAU_iobuf` constructor name. It only
forward-declares `TRIBE_Tree_Object`. The source includes
`include/t_tre_ob.h` for the `new TRIBE_Tree_Object` expression. That class
remains owned by `t_tre_ob.cpp`.

Direct dependency closure reviewed: `tm_tre_o.cpp` includes `tm_tre_o.h` and
`t_tre_ob.h`; `tm_tre_o.h` includes `<stdio.h>` and canonical `m_s_obj.h`;
and `t_tre_ob.h` uses canonical `stat_obj.h`, which includes `utmarray.h`.
No `_context.h` file appears in this closure.

The source uses normal C++ constructors, base initializers, protected setup
calls, the canonical `master_type` member, and natural `new` expressions. It
contains no recovery macros, manual vptr stores, raw cursor accesses, fallback
classes, or inline assembly.

## Migration

- Merged all five normal source bodies into `src/tm_tre_o.cpp` in PDB order.
- Added `include/tm_tre_o.h` as the module header.
- Added `config/source_modules/tm_tre_o.json` with five matching owners.
- Removed `src/tm_tre_o_tu.cpp`.
- Removed `include/tm_tre_o_context.h`.
- Removed the five matching fragments.
- Removed the invalid scratch destructor fragment.
- Kept `tm_tre_o.h` limited to `TRIBE_Master_Tree_Object` ownership.
- Replaced its temporary tree-object declaration with a forward declaration.
- Added the canonical `t_tre_ob.h` include only to `tm_tre_o.cpp`.
- Did not edit translation-unit config, global config, globals, shared headers,
  metrics, or inventories.

The metadata keeps all five prior statuses as `matching`. The candidate
compile uses the canonical base header and keeps the five normal owners exact.
The generated destructor status remains a parent integration concern.

## Candidate proposal

The candidate proposal is `build/candidate_tus/tm_tre_o.json`. It points all
five exact owners at `src/tm_tre_o.cpp`, records the five decorated symbols,
and lists the two generated destructor symbols. Build output is not tracked.

## Affected modules and ABI requests

The direct source change affects only `tm_tre_o.cpp`. The base declaration
surface also affects future reunification of `m_s_obj.cpp` and `tm_co_ob.cpp`.
The tree constructor and generated destructor fan out to `t_tre_ob.cpp`.

The canonical standalone `include/m_s_obj.h` supplies the reviewed
master/static declaration and layout. This module includes it directly and
does not include any context header or create a second base layout. The
`t_tre_ob` captain should use the same static-object ABI after its own
reunification.

No Map, View, global, or shared declaration substitute was added.

## Validation fanout

The grouped candidate validation was run with:

`python tools/validate_candidate_tu.py --proposal build/candidate_tus/tm_tre_o.json`

Results:

- `0050F180`, `0050F220`, `0050F2A0`, `0050F320`, and `0050F3A0`: `MATCH`,
  `0.0000%`, zero byte differences, correct owners, relocations, and
  boundaries.
- Generated scalar-deleting destructor `0050F1F0`: `MATCH`, zero byte
  differences and zero relocation or boundary mismatches. Its owner is
  compiler-generated and therefore unverified by the normal owner check.
- Generated destructor `0050F210`: unresolved. The object has no defined
  `??1TRIBE_Master_Tree_Object@@UAE@XZ` body for this five-byte tail-jump
  comparison.

The grouped candidate status is not full-module exact because the known
generated destructor remains unresolved. The parent must confirm that generated
status before registration. The `0050F20E` padding-only boundary remains
outside this source module.

## Integration result

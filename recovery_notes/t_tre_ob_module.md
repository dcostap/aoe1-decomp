# `t_tre_ob.cpp` source module

## Ownership and order

The PDB records three normal owners in this order:

1. `004CCA60` `TRIBE_Tree_Object::TRIBE_Tree_Object`, lines 36-39;
2. `004CCB20` `TRIBE_Tree_Object::TRIBE_Tree_Object`, lines 44-47;
3. `004CCB90` `TRIBE_Tree_Object::set_object_state`, lines 51-62.

The executable uses the same address order. The owners are 131, 101, and 13
bytes. The existing grouped owners were exact with `/nologo /c /O2 /Oy /GX`.

## Recovery facts

The first constructor calls the static-object constructor with the tree master,
player, three coordinates, and a zero setup flag. It calls the five-argument
static-object setup only when its final flag is nonzero.

The second constructor calls the static-object constructor with the object ID,
world, and a zero setup flag. It calls the two-argument setup only when its
final flag is nonzero.

`set_object_state` forwards one byte to `RGE_Static_Object::set_object_state`.

The nearby `004CCAF0` range is the compiler-generated scalar deleting
destructor. It has no PDB source line and is not a handwritten owner. The
natural class surface keeps this generated entry in the module candidate.

## ABI note

The natural header includes the reviewed `stat_obj_context.h` surface. That
surface owns the static-object layout and base methods. The tree-master class
is owned by `tm_tre_o.cpp`, so this source uses a base-pointer cast for the
proven single-inheritance receiver. This avoids a duplicate object layout.

A future shared ABI repair should expose one canonical tree-master inheritance
declaration to both modules. The affected modules are `t_tre_ob.cpp` and
`tm_tre_o.cpp`; the affected shards are `src/t_tre_ob.cpp` and
`src/matching/0050F320_make_new_obj.cpp`. The lead should validate both complete
translation units after that declaration change.

The old `include/t_tre_ob_context.h` remains because the tm_tre_o source shard
still includes it. It is not used by the natural t_tre_ob source.

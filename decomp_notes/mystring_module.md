# `mystring.cpp` source module

## Ownership

The PDB lists four normal owners in this order:

1. `00462D70` `convert_us`, lines 19-23;
2. `00462D90` `unconvert_us`, lines 27-31;
3. `00462DB0` `addstring`, lines 35-49;
4. `00462E30` `getstring`, lines 53-61.

The executable places these owners at the same address sequence. No nearby
compiler-generated owner is present. The module uses the default flags.

## Recovery facts

All four owners were exact in the registered wrapper before this migration.
The natural module keeps the same source order and uses the reviewed C library
calls for allocation, copying, and release.

`getstring` frees the old value, allocates and publishes the new value, then
copies the input. A failed allocation therefore reaches `memcpy` with a null
destination. The natural source preserves this shipped fault order.

No class, structure, or shared layout is needed by this module.

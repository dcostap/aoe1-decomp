# 0050E970 TRIBE_Master_Combat_Object

PDB owner: `tm_co_ob.cpp:28-31`.

The constructor calls `RGE_Master_Combat_Object(source, 0)`. It publishes the derived vtable, then calls `setup(source)` when `do_setup` is nonzero.

The executable has an exception frame. The module keeps `/GX` in its response file.

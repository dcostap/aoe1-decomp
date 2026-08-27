# 0050E9F0 TRIBE_Master_Combat_Object

PDB owner: `tm_co_ob.cpp:36-39`.

The constructor calls the integer base constructor with a zero setup flag. It publishes the derived vtable, then calls the derived setup when `do_setup` is nonzero.

The executable has an exception frame. The module keeps `/GX` in its response file.

# Pnl_pic.cpp canonical composition

`Pnl_pic.cpp` is the PDB module for seven `TPicturePanel` methods. The PDB
lines run from 30 through 204 in address order.

`pnl_pic.h` owns only `TPicturePanel`. Canonical panel, draw area, shape, and
picture headers provide its base and member types. `Picture.h` uses the
canonical draw-area type.

The grouped candidate check matches six owners and the generated deleting
destructor. `0047A1D0` is scratch with a 52-byte vptr-store-order difference.
It has no boundary escape. Do not add a copied panel declaration or manual
vptr store to recover it.

The candidate registration tool stopped on unrelated existing registry
integrity errors. The exact `0047A3E0` owner is registered from the successful
local candidate check.

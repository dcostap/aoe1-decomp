# 0050EE80 modify

PDB owner: `tm_co_ob.cpp:180-211`.

Attribute `0x64` sets each enabled build cost. Attribute `0x65` sets disabled costs to the negative value. It then updates inherited attribute values for types `4`, `0x0B`, and `0x13`.

Other attributes call `RGE_Master_Combat_Object::modify`. The three inherited scans have separate cursor resets, as shown by the executable loop starts.

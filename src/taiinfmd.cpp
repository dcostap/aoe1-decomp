// Authentic PDB-order prefix wrapper for C:\\msdev\\work\\age1_x1\\taiinfmd.cpp.
//
// The first normal owner is 004D6AD0 ($E9). Its standalone InfluenceMap
// declaration compiles and preserves the original module-start ownership.
// The next normal owner, 004D6B70 ($E19), redeclares InfluenceMap and cannot
// coexist without a reviewed shared declaration. The prefix therefore stops
// before that owner. The nearby generated 004D6B20 ($E14) is not emitted by
// this E9-only source and is not claimed here.

#include "matching/004D6AD0_E9.cpp"

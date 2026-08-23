// Authentic unregistered owner wrapper for
// C:\\msdev\\work\\age1_x1\\getdxver.cpp.
//
// PDB-qualified owner order and boundaries:
//   0044DAC0 ?GetDXVersion@@YAXPAK0@Z  getdxver.cpp:54-338
//                  body 0044DAC0-0044DEDC (1053 bytes)
//   0044DEE0 ?IsDPlay501a@@YAHXZ       getdxver.cpp:342-389
//                  body 0044DEE0-0044DF7F (160 bytes)
//
// The address sequence, line bands, and symbol boundaries show two free
// __cdecl owners in one module. The first owner calls the second at 0044DC0D
// and 0044DEA9. No generated or padding owner is present in this span.
//
// Both owners use the period Windows, DirectDraw, DirectPlay, and version
// header surfaces in their canonical sources. The single module flag set is
// config/flags/default.rsp: /nologo /c /O2 /Oy.
//
// This wrapper is intentionally unregistered in config/translation_units.json.
// It provides authentic module context for audit builds without creating a
// second compiler-facing owner for either VA.

#include "matching/0044DAC0_GetDXVersion.cpp"
#include "matching/0044DEE0_IsDPlay501a.cpp"

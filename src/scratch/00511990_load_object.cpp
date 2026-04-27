// 00511990 TRIBE_Master_Player::load_object
// Source: tmplayer.cpp lines 61-81
// Size: 365 bytes, EH-framed
//
// Attempt log:
// Probe 1: ::operator new + explicit ctor call — 256 bytes (109 short)
// Same fundamental issue as 00511830: EH state tracking around alloc+ctor blocks
// is VC5-internal and cannot be reproduced via C++ source patterns.
// Left in scratch.

// 004B97F0 TShape::shape_draw_unclipped
// Shape.cpp:777-836, 232 bytes
//
// All probes exhausted (~8):
// 1-2: class layout fixes (TShape has no vtable)
// 3-4: #pragma function + /Oi- for memcpy → ignored
// 5-6: non-CRT names → calls but wrong symbols
// 7-8: memcpy via extern __cdecl → still inlined to rep movsd
//
// Core block: VC5 always inlines memcpy/memset to rep movsd/stosd with /O2.
// No pragma/flag combination prevents this. Stack-frame diff + register alloc
// cascade from here.
//
// Parked: VC5 intrinsic inlining — no C++ workaround.

// 00519F40 TRIBE_Panel_Button::draw
// Source: tpnl_btn.cpp lines 109-317
// Size: 1573 bytes, no EH (sub esp,2Ch prologue)
//
// Attempt log:
// Probe 1: full structural decomp with local GDI function pointer names,
//   minimal TButtonPanel class stubs, extern GDI stubs
//   - Compiled! 752/1573 bytes (47.8%)
//   - GDI calls through extern pointers generate `call [addr]` pattern
//   - Size gap from omitted child panel clip calls, text2 rendering details,
//     color_table path, garrison number display, and simplified branches
//
// Analysis:
// This is a 1573-byte draw function with ~60 GDI calls, nested conditionals,
// dual text rendering, color table support, garrison display, and multiple
// virtual dispatch calls. The codegen basin is too deep to match without:
// - Full TButtonPanel class with correct vtable layout (38+ methods for offsets)
// - Complete GDI call chain with correct arg ordering
// - Exact position/offset math for text positioning
// Left in scratch: codegen basin from function complexity + GDI calls.

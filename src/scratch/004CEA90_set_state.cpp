// 004CEA90 TRIBE_Action_Heal::set_state
// Source: tact_hea.cpp lines 98-169
// Size: 566 bytes, EH-framed
// FLAGS: /nologo /c /O2 /Oy /GX
//
// Attempt log:
// Probe 1: full implementation with extern ctor calls, operator_new, /GX
//   - No EH prolog generated (extern ctor calls don't trigger VC5 EH tracking)
//   - Text section: 416/566 bytes (missing 150 bytes of EH frame + prolog)
//
// Probe 2: RGE_Action_Move_To defined with destructor + padding to sizeof=0x44,
//          `new` expression instead of operator_new + extern ctor
//   - EH prolog generated! Size now 528/566 bytes (still 38 bytes short)
//   - 71.55% diff (405/566 bytes differ), 25 diff spans
//   - Main issues: `new` expression generates different constructor code than
//     original's operator_new(0x44)+call[004055A0h] pattern
//   - VC5 tries to inline RGE_Action_Move_To construction (base ctor chain + vtable)
//     instead of emitting an extern call to the precompiled ctor
//   - Switch jump table layout differs (case bodies + default placement)
//
// Root cause: codegen basin from class hierarchy depth. Without the full
// RGE_Action_Move_To/RGE_Action class hierarchy available at compile time
// (sizeof, base class layout, vtable), VC5 cannot reproduce the exact same
// instruction sequence for the `new` expression pattern.
// Also: extern ctor call (004055A0h) is a pre-compiled function, not inlineable.
// Using `new` keyword forces VC5 to generate inline construction which differs
// from the original's operator_new + extern ctor idiom.
//
// Left in scratch: deeply nested class hierarchy codegen basin. Needs either
// the full donor headers or a dedicated variant-lab harness to brute-force the
// exact new+ctor codegen family VC5 uses with these class definitions.

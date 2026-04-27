// 004512D0 RGE_Master_Doppleganger_Object::make_new_obj
// Source: m_dg_obj.cpp lines 94-108
// Size: 214 bytes, EH-framed
//
// Attempt log:
// Probe 1: factory with recycle-or-new + vtable call at 0x1EC → 67% diff
// Same structural issues as 0044FC00 (animated sibling):
//   - mov al,[edi+4] vs movsx (char promotion)
//   - new expression vs operator_new+ctor+EH tracking pattern
//   - vtable slot at 0x1EC (123 dummies) correct but codegen still mismatches
// Left in scratch: codegen basin from operator_new+ctor+EH tracking pattern

// 0044FC00 RGE_Master_Animated_Object::make_new_obj
// Source: m_an_obj.cpp lines 100-114
// Size: 201 bytes, EH-framed, /GX
//
// Attempt log:
// Probe 1: factory with recycle-or-new pattern → 67% diff
//   - movsx for char→int promotion vs raw mov al/push eax
//   - new expression generates different alloc+ctor code (0x88 vs 0x8C)
//   - EH state tracking diff
// Probe 2: proper inheritance layout → 64% diff, same structural issues
// Left in scratch: codegen basin from new expression + char promotion pattern

// TDialogPanel::TDialogPanel
// VA: 00473C10
// Source: pnl_dlg.cpp lines 33-34
// Size: 68 bytes
//
// Attempt log:
// Probe 1: virtual dtor on base + derived → 42% diff, vtable at wrong position (start vs end)
// Probe 2: explicit vtable field (TEasy_Panel with void* vtable) → 51% diff, same scheduling issue
// Probe 3: corrected TEasy_Panel gap (0x424 buffer), virtual dtors → same 42% diff
// Left in scratch: VC5 auto-generates vtable write at body start, original has it at body end.
// Codegen basin: 29 bytes / 4 spans diff, all structural (vtable position + xor ecx vs xor eax).

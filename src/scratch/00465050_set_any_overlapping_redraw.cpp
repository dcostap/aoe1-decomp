// 00465050 TPanel::set_any_overlapping_redraw
// Source: Panel.cpp lines 1264-1294, size 263 bytes
// 
// Parked: complex multi-path rectangle overlap check. The function
// iterates child panels and calls set_redraw(mode) on those whose
// clip_rect overlaps with `other`. The overlap logic uses a specific
// multi-branch comparison tree with 2 virtual dispatch call sites.
//
// Probes: 5+ attempts with goto/variable/bool/pointer approaches.
// Best result: 208/263 bytes (79%) with correct prologue pattern
// (sub esp, push regs, save locals). Remaining drift is VC5's
// register allocation and the exact multi-branch comparison tree.
//
// Key facts:
// - TPanel::first_child_node at +0x58 (PanelNode*)
// - PanelNode: panel(+0x00), prev(+0x04), next(+0x08)
// - clip_rect at +0x24 (tagRECT: left/top/right/bottom)
// - vtable[8]=set_redraw at vtbl+0x20
// - 5 stack slots: iterator, top, right, bottom, (unused)

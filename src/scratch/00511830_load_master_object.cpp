// 00511830 TRIBE_Master_Player::load_master_object
// Source: tmplayer.cpp lines 41-57
// Size: 351 bytes, EH-framed
//
// Attempt log:
// Probe 1: new expressions — 304 bytes (47 short), no EH state tracking
// Probe 2: explicit ctor call via operator_new — 272 bytes (79 short), even less code
// Both miss EH state tracking (mov [esp+0Ch], 0/1/2) around each alloc+ctor block
// Left in scratch: same ctor call + EH tracking issue as other action-like functions

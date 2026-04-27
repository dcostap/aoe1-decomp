// 004936D0 TribeEndScreen::TribeEndScreen
// Source: scr_end.cpp lines 34-116
// Size: 1290 bytes
// Signature: TribeEndScreen::TribeEndScreen(char*, char**, int) ret 0Ch
//
// Attempt log:
// Probe 1: full decomp attempt — compile errors from __thiscall syntax and base ctor call
// 
// Function structure:
// - EH prolog (/GX), saves this in ebp
// - Push "End Screen", call TScreenPanel base ctor
// - Set vtable
// - Line 41: get draw_area from rge_base_game->field_4C, call TScreenPanel::setup
//   If fails: set display_changed_count=1, return this
// - Lines 48-53: pick bg name by resolution (<800 → bgA640, <1024 → bgA800, else bgA1024)
//   Copy to stack buffer via strlen+rep movs (inline strcpy)
// - Lines 56-57: operator_new(0x11C) + TPicturePanel ctor → this->background (+0x478)
//   If fails: flag=1, return
// - Lines 62-64: TPicturePanel::setup with many params (bg, draw_area, screen dims, etc)
// - Lines 69-72: background->vtable[0x18] set_position with screen calc
// - Line 72: rge_base_game->get_font(1) 
// - Lines 75-78: operator_new(0x188) + TTextPanel ctor → this->title (+0x47C)
// - Lines 83-84: TTextPanel::setup with font/position math (IMUL magic constants)
// - Lines 86-89: operator_new(0x188) + TTextPanel ctor → this->text (+0x480)
// - Lines 91-95: get_font(0x0B), TTextPanel::setup with different position math
// - Lines 96-98: text->vtable[0xE0] font_size, set_alignment, scroll
// - Lines 101-103: get_sound(0), get_font(0), operator_new(0x2B8) + TButtonPanel ctor → okButton (+0x484)
// - Lines 105-112: TButtonPanel::setup, set_text_info("OK", ...)
// - Lines 114-115: set_curr_child(background), set_curr_child(text)
// - Epilogue: return this
//
// Left in scratch: 1290B constructor with 4 child objects, complex position math,
//   inline strcpy, EH state tracking (0-4). Deep codegen basin — same class as
//   TribeMenuDialog constructor (0043F340). Not attempted past probe 1 due to complexity.

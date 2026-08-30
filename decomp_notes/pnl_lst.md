# Pnl_lst.cpp recovery notes

This file keeps the removed per-function recovery notes.

## Pnl_lst translation-unit declaration repair

The PDB source map identifies the Pnl_lst.cpp TListPanel overrides as the
destructor, set_bevel_info, handle_idle, the five list mouse actions,
key_down_action, char_action, action, draw, and set_focus. The other virtual
slots belong to TTextPanel or TPanel and remain inherited in include/pnl_lst.h.

The previous module candidate repeated every inherited virtual declaration in
TListPanel. Removing those declarations preserves 19 of 20 owner matches.
004786B0 item_at remains 66 bytes with the original frame and CFG, but its
border_size and pnl_y loads swap order, causing a 10-byte positional mismatch.
This is an exactness regression from the source-shape repair. Do not retain the
removed inherited declarations only to hide this compiler scheduling drift.

## 004782A0 TListPanel::TListPanel

The prior source used volatile offset stores and a vptr write. It matched size
and order. It kept EAX for stores. The executable loads one into ECX at +0x0A.

A normal polymorphic class and member stores moved the vptr store. Initializing
only `drawHighlightBar` in the initializer list kept the vptr store after the
first member group. VC5 then loaded one into ECX.

Removing the explicit `TTextPanel` initializer stayed exact. Removing `this`
qualifiers stayed exact. Moving `drawHighlightBar` into the body was not exact.

## 004784A0 TListPanel::mouse_move_action

The natural null check, virtual helper call, and item range gate matched after
the base layout was restored. The original compare order was required.

## 00478540 TListPanel::mouse_left_move_action

Cached y and height values gave the wrong entry order and block layout. Direct
member expressions and separate lower-bound guards restored the parameter home,
repeated compare, and common scroll tail.

The explicit down-scroll arm and clear-range `else` restored the original
branch layout. This source was exact with the default VC5 flags.

## 00478920 TListPanel::scroll_cur_line

The recovered ABI is `scroll(int, short, int)`. The function sets redraw through
the +0x20 virtual slot. The parent callback uses action value one.

The executable clamps the strict upper bound. Page down uses `bot_line`. Page
up uses `top_line`. Case three decrements before it calls `scroll`.

Cases four and five store their endpoint after a `scroll` call. The call can
change member state. Do not remove the repeated stores.

## 00478BA0 TListPanel::draw

The inherited offsets, GDI declarations, drawing string, short `draw_line` ABI,
focus and capture test, and counted visible-line loop produced the exact owner.
The function has thirteen ordered calls.

## 00478CD0 TListPanel::draw_highlight_bar

Typed `TDrawArea` calls, `calc_line_pos`, the common `Unlock` tail, and the
period switch recovered the owner behavior. The switch order is 0/1, 5, 6, 7,
2, 3, 4.

The right-to-left push order reverses colors for cases 5 to 7. It uses ascending
colors for cases 2 to 4. Direct rectangle expressions selected the original
load order in the complete module declaration.

The common `Unlock` call remains outside the DC and Lock guards. Keep this
shipped control flow.

// VA: 0053A290 RGE_View::handle_scroll_view (view.cpp:5922-6155)
// __thiscall virtual (vtable slot 59), int (long param_1, long param_2), ret 8. 1801 bytes.
// Status: VERIFIED_LOGIC — post-review case-7 ordering corrected; non-exact tail merge.
//
// Attempt log (owner DS4-53A290, 2026-08-02):
// 1. baseline: natural reconstruction from packet/decomp + binary-verified details
//    (switch 2/6/7/8 + default edge scroll; RGE_View layout from matched 0053A9C0;
//    constants DAT_005776b4=0.5f / DAT_005776c0=-0.5f / DAT_005776c4=0.0625f;
//    is_inside at vtable slot 47, do_paint at slot 61). Size/frame exact 1801/0x24;
//    diff 1530 B; do_paint landed at slot 59 (+0xEC) and uVar8 local spilled to stack.
// 2. control-flow: added the two missing declarations so do_paint = slot 61; bVar7 block re-reads
//    this->scroll_action (member) so VC5 CSEs into al. Call set aligned (1 gap left);
//    still 1530 B due to uVar8 spill; switched switch() to this->scroll_action directly
//    and removed the uVar8 local: diff dropped to 104 B (dispatch now byte-exact).
// 3. control-flow: case7 warp mouse_last stores y-first (PDB line 6007 order): 96 B.
// 4. control-flow: case7 warp as if-body (PDB line order 5992/5994-6007/6044): no change.
// 5. variant: comma-expression one-liner in-bounds: no change (96 B).
// 6. variant: final check inverted to if-body form: no change.
// 7. variant: case7 in-bounds set_redraw BEFORE stores: broke the tail-merge with the
//    final block (final tail now byte-exact incl. mov eax,1 between pops); diff 43 B.
// 8. variant: stores-first again: tail-merge recurs (96 B) — merge is tied to the
//    scheduler NOT hoisting the call setup above the stores.
// 9. variant (kept, best): set_redraw BETWEEN the two mouse_last stores: 41 B strict
//    (98.17% sim, 1.69% edit); call lands between x-store and y-store.
//
// Remaining drift (all in case 7):
//  - in-bounds tail: rebuilt uses `mov eax,[esi]` where original uses `mov edx,[esi]`
//    (1 B), and the y-store/call order: rebuilt `call; mov [esi+170h],edi` vs original
//    `mov [esi+170h],edi; call [edx+20h]` (4 B).
//  - warp path: register cascade from the in-bounds block: rebuilt loads mouse_down_x
//    into edx (orig eax), panel into ecx (orig edx), lea/hwnd regs shifted; original
//    keeps ecx=mouse_down_y live and loads vtable into edx before the y store.
//  - PDB evidence: original in-bounds line 6044 = stores+set_redraw with setup hoisted
//    (`mov edx,[esi]; push 1; mov ecx,esi; stores; call`), i.e. natural stores-first
//    source + scheduler hoist; the tail-merge only happens when the setup is NOT hoisted.
// Next lead: find a source shape that keeps the in-bounds tail self-contained with
//    setup-first (e.g. a small helper call, pointer local plVar1, or moving the
//    y-store before set_redraw) so VC5 colors the vtable into edx and schedules both
//    stores before the call without merging; then the warp register cascade should
//    follow automatically.
// 10. liveness: TPanel pointer alias across case 7 redraw calls: emitted code unchanged (41 B).
// 11. context: stores-first plus explicit TPanel dispatch: tail merged, structural 96 B with one
//     missing vslot call; rolled back.
// 12. control-flow: dedicated case-7 success label: duplicate 96 B result; rolled back.
// 13. liveness: pointer local for the case-7 y destination: duplicate 96 B result; rolled back.
// 14. liveness: stores-first named result local: 93 B but still missing the case-7 vslot call;
//     rolled back in favor of the 41 B source.
// 15. liveness: named result local with the 41 B between-stores order: emitted code unchanged;
//     rolled back as a duplicate source shape.
// 16. abi: restored the binary-proven RGE_View set_redraw override; emitted code unchanged, kept
//     as the more accurate local class surface.
// 17. control-flow: comma expression sequencing y-store then redraw: tail merged, 96 B; rolled back.
// 18. layout: proven raw +0x170 y-store with stores-first order: tail merged, 96 B; rolled back.
// 19. variant: eight focused case-7 tail spellings (including stores-first, result/pointer locals,
//     do-store, comma-mode, and base dispatch); one invariant-eligible group, no exact. Current
//     between-stores spelling remains best at 41 strict bytes.
// Final bounded result: 10/10 meaningful hypotheses exhausted; leave scratch at validated 41 B.
// Logic review round 1 confirmed the between-stores spelling is behaviorally wrong at the
// virtual redraw boundary. Main-agent fix: store both mouse_last fields before set_redraw.
// VC5 tail-merges that corrected path with a later redraw/return tail: validated 1801B,
// 96 strict bytes, 35/36 static call sites (runtime case-7 redraw preserved). Semantic order
// takes precedence over the smaller matching-oriented diff; fresh blind review is required.

#include "../../include/view_tu_context.h"

extern "C" __declspec(dllimport) int __stdcall ClientToScreen(void* hWnd, tagPOINT* point);
extern "C" __declspec(dllimport) int __stdcall SetCursorPos(int x, int y);

extern float DAT_005776b4;   // 0.5f    (case 7/8 scroll delta factor)
extern float DAT_005776c0;   // -0.5f   (case 6 pick offset)
extern float DAT_005776c4;   // 0.0625f (edge scroll factor)

int RGE_View::handle_scroll_view(long param_1, long param_2)
{
    long point_x;                 // saved mouse_last_x
    float save_view_x;            // saved player view_x
    float save_view_y;            // saved player view_y
    long lVar12;                  // saved mouse_last_y (late)
    int iVar10;                   // deltas / ftol results
    tagPOINT point;
    RGE_Pick_Info pick_info;
    int bVar7;

    point_x = this->mouse_last_x;
    if (param_1 == this->mouse_last_x && param_2 == this->mouse_last_y) {
        return 0;
    }

    save_view_x = this->player->view_x;
    save_view_y = this->player->view_y;

    switch (this->scroll_action) {
    case 2:
        this->mouse_last_x = param_1;
        this->mouse_last_y = param_2;
        this->bound_point(this->mouse_last_x, this->mouse_last_y);
            this->set_redraw((TPanel::RedrawMode)1);
        return 0;

    case 6:
        if (this->is_inside(param_1, param_2) != 0 &&
            this->pick(0x28, 0, param_1, param_2, &pick_info, 0) == 0x33) {
            this->player->set_view_loc(pick_info.x - DAT_005776c0, pick_info.y - DAT_005776c0);
        }
        this->mouse_last_x = param_1;
        this->mouse_last_y = param_2;
        if (save_view_x == this->player->view_x && save_view_y == this->player->view_y) {
            return 0;
        }
            this->set_redraw((TPanel::RedrawMode)1);
        return 1;

    case 7:
        iVar10 = param_2 - this->mouse_last_y;
        if (iVar10 != 0 && iVar10 < 100 && iVar10 > -100) {
            short sVar9 = (short)((float)iVar10 * DAT_005776b4);
            this->player->map_y += sVar9;
            this->player->map_x -= sVar9;
        }
        iVar10 = param_1 - this->mouse_last_x;
        if (iVar10 != 0 && iVar10 < 100 && iVar10 > -100) {
            short sVar9 = (short)((float)iVar10 * DAT_005776b4);
            this->player->map_y += sVar9;
            this->player->map_x += sVar9;
        }
        if (abs(param_2 - this->mouse_down_y) > 8 || abs(param_1 - this->mouse_down_x) > 8) {
            point.x = this->mouse_down_x;
            point.y = this->mouse_down_y;
            ClientToScreen(((void**)this->render_area)[1], &point);
            SetCursorPos(point.x, point.y);
            this->mouse_last_y = this->mouse_down_y;
            this->mouse_last_x = this->mouse_down_x;
            this->set_redraw((TPanel::RedrawMode)1);
            return 1;
        }
        this->mouse_last_x = param_1;
        this->mouse_last_y = param_2;
        this->set_redraw((TPanel::RedrawMode)1);
        return 1;

    case 8:
        iVar10 = param_2 - this->mouse_last_y;
        if (iVar10 != 0 && iVar10 < 100 && iVar10 > -100) {
            iVar10 = (int)((float)iVar10 * DAT_005776b4);
            this->player->set_view_loc(this->player->view_x - (float)iVar10,
                                       this->player->view_y + (float)iVar10);
        }
        iVar10 = param_1 - this->mouse_last_x;
        if (iVar10 != 0 && iVar10 < 100 && iVar10 > -100) {
            iVar10 = (int)((float)iVar10 * DAT_005776b4);
            this->player->set_view_loc(this->player->view_x + (float)iVar10,
                                       this->player->view_y + (float)iVar10);
        }
        if (abs(param_2 - this->mouse_down_y) <= 8 && abs(param_1 - this->mouse_down_x) <= 8) {
            this->mouse_last_x = param_1;
            this->mouse_last_y = param_2;
        } else {
            point.x = this->mouse_down_x;
            point.y = this->mouse_down_y;
            ClientToScreen(((void**)this->render_area)[1], &point);
            SetCursorPos(point.x, point.y);
            this->mouse_last_x = this->mouse_down_x;
            this->mouse_last_y = this->mouse_down_y;
        }
        if (save_view_x == this->player->view_x && save_view_y == this->player->view_y) {
            return 0;
        }
        this->set_redraw((TPanel::RedrawMode)1);
        return 1;
    }

    // scroll_action is not 2/6/7/8: edge-scroll handling shared by 0,1,3,4,5,9,10+
    if (this->scroll_action == 3 || this->scroll_action == 4 || this->scroll_action == 9) {
        if ((param_1 < this->clip_rect.left + 0x40 && param_1 < point_x) ||
            (param_1 > this->clip_rect.right - 0x40 && param_1 > point_x) ||
            (param_2 < this->clip_rect.top + 0x20 && param_2 < this->mouse_last_y) ||
            (param_2 > this->clip_rect.bottom - 0x20 && param_2 > this->mouse_last_y)) {
            bVar7 = 1;
        } else {
            bVar7 = 0;
        }
    } else {
        bVar7 = 1;
    }

    iVar10 = param_2 - this->mouse_last_y;
    if (iVar10 != 0 && iVar10 < 200 && iVar10 > -200 && bVar7) {
        this->player->set_view_loc(this->player->view_x - (float)iVar10 * DAT_005776c4,
                                   this->player->view_y + (float)iVar10 * DAT_005776c4);
    }
    iVar10 = param_1 - this->mouse_last_x;
    if (iVar10 != 0 && iVar10 < 200 && iVar10 > -200 && bVar7) {
        this->player->set_view_loc(this->player->view_x + (float)iVar10 * DAT_005776c4,
                                   this->player->view_y + (float)iVar10 * DAT_005776c4);
    }

    point_x = this->mouse_last_x;
    lVar12 = this->mouse_last_y;
    this->mouse_last_x = param_1;
    this->mouse_last_y = param_2;
    if (bVar7) {
        if (abs(param_2 - this->mouse_down_y) > 8 || abs(param_1 - this->mouse_down_x) > 8) {
            point.x = this->mouse_down_x;
            point.y = this->mouse_down_y;
            ClientToScreen(((void**)this->render_area)[1], &point);
            SetCursorPos(point.x, point.y);
            this->mouse_last_x = this->mouse_down_x;
            this->mouse_last_y = this->mouse_down_y;
        }
    } else {
        this->mouse_down_x = param_1;
        this->mouse_down_y = param_2;
    }

    if (this->scroll_action == 3) {
        if (this->pick(0x28, 0, param_1, param_2, &pick_info, 0) == 0x33 && this->player != 0) {
            this->set_selection_area(this->sel_col1, this->sel_row1,
                                     (long)pick_info.x, (long)pick_info.y);
        }
    } else if (this->scroll_action == 4) {
        if (this->player->selected_obj != 0 &&
            this->pick(0x28, 0, param_1, param_2, &pick_info, 0) == 0x33) {
            this->player->selected_obj->teleport(pick_info.x, pick_info.y, 0);
            RGE_Static_Object* pRVar6 = this->player->selected_obj;
            unsigned char level;
            if (pRVar6->sprite_list != 0) {
                level = pRVar6->sprite_list->get_lowest_draw_level();
            } else if (pRVar6->sprite != 0) {
                level = pRVar6->sprite->get_lowest_draw_level();
            } else {
                level = 0x14;
            }
            if (level == 0) {
                this->set_redraw((TPanel::RedrawMode)2);
            } else {
        this->set_redraw((TPanel::RedrawMode)1);
            }
        }
    } else if (this->scroll_action == 9) {
        this->do_paint(point_x, lVar12, param_1, param_2, 2);
        this->set_redraw((TPanel::RedrawMode)1);
    }

    if (save_view_x != this->player->view_x || save_view_y != this->player->view_y) {
        this->set_redraw((TPanel::RedrawMode)1);
        return 1;
    }
    return 0;
}

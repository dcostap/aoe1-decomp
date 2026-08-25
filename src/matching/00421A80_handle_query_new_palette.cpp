// VA: 00421A80 RGE_Base_Game::handle_query_new_palette (234 B)
// PDB source: basegame.cpp lines 4683-4726
//
// Attempt log:
// - Baseline rewrite (this session): corrected both TDrawSystem::HandleQueryNewPalette
//   calls to pass (hwnd, msg, wparam, lparam) through unchanged (the old scratch passed
//   (long)hwnd as the last arg, a Ghidra stack-mis-analysis). Rebuilt the palette path
//   from the binary: double currentPanel call (first result only null-tested), double
//   get_palette call (second inline in SelectPalette), prog_palette default load sunk
//   into the else arm, SelectPalette spelled in both arms to preserve the split push 0
//   and shared push-palette/push-dc/call tail, RealizePalette result saved across
//   ReleaseDC, final draw_system guard with reload, return 1.
// - Fixed RGE_Base_Game layout: gap_00[0x1C] (no-vptr class) so prog_palette lands at +0x1C
//   and draw_system at +0x48; first HandleQueryNewPalette call site reloads this->draw_system
//   (ds local dies after the guard) to reproduce the post-InvalidateRect reload.
// - MATCH: dropped the pal local entirely; tested panel->get_palette() twice (second call
//   inline in SelectPalette args) and used direct this->prog_palette access in the else
//   branch. VC5 then sinks the prog_palette load into the else arm and tail-merges the
//   shared SelectPalette push-palette/push-dc/call with the split push 0 in each arm.
// Result: MATCH locally with `python tools/check_function.py --va 00421A80`.





extern TPanelSystem panel_system;


int RGE_Base_Game::handle_query_new_palette(void* hwnd, unsigned int msg, unsigned int wparam, long lparam)
{
    TDrawSystem* ds = this->draw_system;
    if (ds != 0 && ds->DrawType != 1 && ds->ScreenMode != 1) {
        InvalidateRect(hwnd, 0, 0);
        return this->draw_system->HandleQueryNewPalette(hwnd, msg, wparam, lparam);
    }

    void* dc = GetDC(hwnd);
    if (panel_system.currentPanel() != 0) {
        TPanel* panel = panel_system.currentPanel();
        if (panel->get_palette() != 0)
            SelectPalette(dc, panel->get_palette(), 0);
    } else {
        if (this->prog_palette != 0)
            SelectPalette(dc, this->prog_palette, 0);
    }
    int result = RealizePalette(dc);
    ReleaseDC(hwnd, dc);
    if (result != 0)
        InvalidateRect(hwnd, 0, 0);
    if (this->draw_system != 0)
        return this->draw_system->HandleQueryNewPalette(hwnd, msg, wparam, lparam);
    return 1;
}

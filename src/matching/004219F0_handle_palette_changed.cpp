// VA: 004219F0 RGE_Base_Game::handle_palette_changed
// basegame.cpp lines 4655-4678
//
// Attempt log:
// - Initial stub was empty.
// - Natural member-call/control-flow shape nearly matched, but the fallback virtual call initially used the wrong
//   vtable slot and returned the virtual result, shortening the final epilogue.
// - SpruceGlow MATCH: expose the fallback virtual at vtable offset 0xEC (59 dummy slots before it) and call it for
//   side effect only, then return 1. Keep the slightly unsafe source order `DrawType || ScreenMode || ds == 0` to
//   preserve the original null test after the byte checks.
// Result: MATCH locally with `python tools/check_function.py --va 004219F0`.



int RGE_Base_Game::handle_palette_changed(void* p1, unsigned int p2, unsigned int p3, long p4) {
    if (this->draw_system != 0) {
        this->draw_system->HandlePaletteChanged(p1, p2, p3, p4);
    }

    if ((void*)p3 != p1) {
        TDrawSystem* ds = this->draw_system;
        if (ds->DrawType == 1 || ds->ScreenMode == 1 || ds == 0) {
            this->base_handle_palette_changed(p1, p2, p3, p4);
        }
        else if (this->prog_mode != 1) {
            ds->ModifyPalette(0, 0x100, ds->palette);
            return 1;
        }
    }

    return 1;
}

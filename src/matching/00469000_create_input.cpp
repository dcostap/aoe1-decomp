// 00469000 TEasy_Panel::create_input
// Source: Panel_ez.cpp lines 1345-1380
// attempt 1: natural source from packet/decompiler; first 156 bytes exact but VC5 put success epilogue before failure block (failure target outside original body), edit diff 55B.
// attempt 2: added volatile result local and common return; first 156 bytes still exact, failure block moved before common epilogue, best edit diff 52B. Kept for accepted_drift review.
// attempt 3: nonvolatile result local with goto common return; VC5 optimized back to early success return, no improvement.
// attempt 4: result initialized to 0 plus final if(result==0) failure write; worsened register allocation from offset 78.
// attempt 5: used dead parameter as return result; caused broad register allocation drift like attempt 4.
// attempt 6: explicit ok/fail labels without volatile; no improvement over natural early-return tail split.
// attempt 7: register out pointer local; no codegen change in natural body.
// attempt 8: removed /GX diagnostically; object lost EH frame and .text was too small (400B), reverted.
// attempt 9: /GX /Ob0; no codegen change, reverted.
// attempt 10: reviewed setup arg surface/order and vtable slot declarations; current call order/body matches original through setup/bevel/color calls; remaining drift is tail/return lowering.
// attempt 11: typed the PDB/SDK FormatType enum through create_input and setup; emitted code is unchanged, confirming the remaining first hunk is tail CFG placement.
// shardE probe: a switch around setup produced a 38-byte diagnostic basin, but only by falling into the failure return; restoring success return restored the natural 180-byte basin.
// ACCEPTED_DRIFT suggestion: with volatile result, all functional calls/memory effects match; extra writes are only to this function's stack result slot before common epilogue, and branch distances/tail layout differ. Needs review; not promoted.
// session 2026-08-11: baseline rebuilt the volatile common-return candidate at 451 bytes; natural direct returns and nonvolatile result/goto joins both rebuilt at 457 bytes with the same 156-byte prefix and the success epilogue before failure.
// session probes: a register result, a destructor declaration, and the packet-indicated virtual create_input ABI (with the proven gap adjustment) did not change that tail family; /O1 introduced an extra EH helper and broad structural drift.
// final session source restores the natural typed factory form; remaining blocker is the VC5 /GX shared EH failure-tail placement (oracle success jump over failure block to one epilogue).
// luna probe: a typed unsigned-byte status local formed the shared success/failure jump topology, as in the sibling factory, but changed late register coloring and worsened positional diff; restored.
// worker pass 2026-08-16: separate null, constructor-state, and setup failure guards widened the body to 507 bytes / 332 diff; restored.
// worker pass: one shared fail label reduced size to 445 bytes but worsened positional diff to 279; restored. A TTextPanel-derived input ABI with the proven 0x188 base was byte-identical to the natural basin.
// revisit 2026-08-17: an explicit outer failure else with the same error write was codegen-identical at 457 bytes / 180 diff; restored.
// revisit probe: defining an empty local TInputPanel destructor changed only the compiler-owned /GX context and produced an authoritative 0-byte MATCH. It is not retained: the real destructor owns VA 00476CF0 in src/matching, and a duplicate owner is not policy-valid.
// final validation: natural source is 457 bytes / 180 positional diff, with all 7 calls ordered and the first 0x9C bytes exact; the only remaining mismatch is the /GX cloned return tail.
// ACCEPTED DRIFT: All factory work and seven calls match. The declaration-only
// build uses longer failure branches and clones equivalent success and failure
// EH epilogues. The failure store stays before cleanup. Both paths restore the
// same SEH link, registers, stack, and return value. No call or external memory
// effect moves. The proven empty destructor makes this exact in TU context.
// Exact translation-unit finish: the grouped pnl_ez.cpp owner set supplies a
// real earlier body and one shared input-panel surface. The unchanged natural
// factory then matches all 434 bytes and seven calls. Target-only compilation
// emits the reviewed cloned-tail drift.

int TEasy_Panel::create_input(TPanel* parent, TInputPanel** out, char* text, short max_len, TInputPanel::FormatType format,
                              long x, long y, long w, long h, long font_id)
{
    long ideal_x = (x * this->base_width) / this->ideal_width;
    long ideal_y = (y * this->base_height) / this->ideal_height;
    long ideal_w = (w * this->base_width) / this->ideal_width;
    long ideal_h = (h * this->base_height) / this->ideal_height;

    *out = new TInputPanel;
    if (*out != 0 && (*out)->field_D8 == 0) {
        RGE_Font* font;
        if (font_id >= 0) {
            font = rge_base_game->get_font(font_id);
        } else {
            font = rge_base_game->get_font(10);
        }
        if ((*out)->setup(this->draw_area, parent, ideal_x, ideal_y, ideal_w, ideal_h,
                          font->font, font->font_wid, font->font_hgt,
                          0, 0, 0, 1, 0xff, 0xff, max_len, 0, text, format) != 0) {
            if (this->use_bevels != 0) {
                (*out)->set_bevel_info(3, this->bevel_color1, this->bevel_color2,
                                       this->bevel_color3, this->bevel_color4,
                                       this->bevel_color5, this->bevel_color6);
            }
            (*out)->set_text_color(this->text_color1, this->text_color2);
            (*out)->set_highlight_text_color(this->focus_color1, this->focus_color2);
            return 1;
        }
    }

    this->error_flag = 1;
    return 0;
}

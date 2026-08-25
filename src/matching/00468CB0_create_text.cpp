// attempt 1: natural TEasy_Panel text factory from Ghidra/PDB line shape
// Attempt log:
// - Baseline matches the natural typed factory through the first 156 bytes,
//   all 9 ordered calls, saved registers, and 17 exact blocks; rebuilt is 436
//   bytes versus 413.  The remaining structural gap is the success return
//   epilogue: the oracle jumps over a cold failure tail at +0x17C, while VC5
//   emits a success epilogue before that tail.
// - An initialized result local added an 8-byte frame and broad drift; rolled
//   back.  Goto/result-join, explicit result assignments, and negative early
//   failure guards all emitted the same 436-byte basin as the baseline.
// - Adding a virtual TTextPanel destructor as an extra slot moved the set_text
//   call to +0xEC; replacing slot zero preserved +0xE8 but did not move the
//   return tail.  stdio/string header context was also an emitted duplicate.
// - Making create_text virtual worsened early member offsets/register coloring;
//   rolled back.  Best source is restored; remaining lead is the original
//   source's cold failure/common-epilogue topology, not call or layout parity.
// - A register result with a common source return was a codegen duplicate; no
//   stack home or CFG change appeared.  Restored the natural typed factory.
// - An outer negative typed branch with one final failure return was also a
//   codegen duplicate; rolled back and kept the natural lifetime surface.
// - A named panel local, late common-result declaration, explicit failure
//   label, and named 0xD8 field were each duplicate or broadly worse; restored.
// - Modeling the proven TPanel inheritance, virtual destructors, and virtual
//   create_text with explicit base gaps kept the same 436-byte tail basin.
// - Inverting the outer validity guard with a typed error field and one result
//   return kept the 436-byte basin; only edit similarity worsened. Rolled back.
// - Moving an uninitialized result declaration before coordinate locals and
//   using one done label was also a 436-byte codegen duplicate. Rolled back.
// - A /Os overlay reduced size but removed the required EH frame and changed
//   early code broadly. Restored /O2 /Oy /GX; the shared-tail gap is structural.
// - This pass rechecked an int result with explicit success/failure assignments;
//   it was byte-identical to the natural 436-byte basin.
// - An unsigned-char result forced the oracle-like one-return CFG, but added a
//   stack byte store/mask and changed EBX/EBP coloring, worsening the diff to
//   270 bytes. Scoping it after coordinate math was identical. Rolled back.
// - A source-ordered negative allocation/field guard was byte-identical to the
//   natural baseline. The only remaining mismatch is the /GX shared EH tail.
// - Revisit: the local Panel_ez.cpp sibling factories at 00468E50, 00469000,
//   and 004691C0 have the same original success-jump-over-failure-tail shape.
//   Their durable logs record natural typed guards, common result/goto forms,
//   labels, ABI/layout variants, and /GX checks; each keeps the cloned tail.
//   The target's typed source already matches the first 156 bytes and all 9
//   ordered calls. No policy-compliant source lead remains for this tail.
// ACCEPTED DRIFT: All factory work, named field accesses, and nine calls match.
// The rebuild lengthens failure branches and clones equivalent success and
// failure EH epilogues. The failure error_code store stays before cleanup.
// Each path restores the same SEH link, registers, stack, and return value. No
// call or external memory effect moves across the differing cleanup sequence.
// Exact translation-unit finish: the real earlier pnl_ez.cpp owners select the
// original factory EH tail. The shared button/text surface keeps one owner for
// each method. The unchanged typed source then matches all 413 bytes and nine
// calls. Target-only compilation emits the reviewed cloned-tail drift.

int TEasy_Panel::create_text(TPanel* parent, TTextPanel** out, char* text, long p4, long p5, long p6, long p7, long font_id, int center_h, int center_v, int word_wrap) {
    long ideal_x = (p4 * this->base_width) / this->ideal_width;
    long ideal_y = (p5 * this->base_height) / this->ideal_height;
    long ideal_w = (p6 * this->base_width) / this->ideal_width;
    long ideal_h = (p7 * this->base_height) / this->ideal_height;

    *out = new TTextPanel;
    if (*out != 0 && (*out)->field_D8 == 0) {
        RGE_Font* font;
        if (font_id >= 0) {
            font = rge_base_game->get_font(font_id);
        } else {
            font = rge_base_game->get_font(10);
        }
        if ((*out)->setup(this->draw_area, parent, ideal_x, ideal_y, ideal_w, ideal_h, font->font, font->font_wid, font->font_hgt, 0, 0, 0, 0, 0, 0, 0) != 0) {
            if (center_h != 0 && center_v != 0) {
                (*out)->set_alignment(0, 0);
            } else if (center_h != 0) {
                (*out)->set_alignment(3, 0);
            } else if (center_v != 0) {
                (*out)->set_alignment(0, 1);
            } else {
                (*out)->set_alignment(3, 1);
            }
            (*out)->set_word_wrap(word_wrap);
            (*out)->set_text(text);
            (*out)->set_text_color(this->text_color1, this->text_color2);
            (*out)->set_highlight_text_color(this->focus_color1, this->focus_color2);
            return 1;
        }
    }
    this->error_code = 1;
    return 0;
}

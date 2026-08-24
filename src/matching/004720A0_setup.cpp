// VA: 004720A0 TButtonPanel::setup(...)
// PDB source: Pnl_btn.cpp lines 112-122 (99 bytes, 34 asm lines)
// Default flags
// Exact match.
// Attempts:
// - Baseline matched the long TPanel::setup argument shuffle, but after the base call it stored notify then
//   called set_sound, with drawTypeValue delayed until before set_id; this produced a shifted middle block.
// - Reordering source to notify assignment, draw assignment, then set_sound improved to 95/99 bytes but VC5
//   canonicalized the adjacent non-volatile stores in increasing member-offset order (+140 then +144), swapping
//   the desired parameter loads/stores.
// - Swapping local field names did not change that canonicalized store-order basin.
// - Volatile fields preserved source order but over-constrained the block and moved both stores before the
//   set_sound push, unlike original.
// - Winning shape: write drawTypeValue first, then notifyTypeValue, then set_sound. VC5 reverses/canonicalizes the
//   two adjacent non-volatile stores into the original order: load notify(+0x28), sound(+0x24), draw(+0x20), store
//   notify at +0x144, push sound, store draw at +0x140, call set_sound.

class TDrawArea;
class TDigital;

#ifndef PNL_BTN_SHARED_CONTEXT
class TPanel {
public:
    virtual ~TPanel();
    long setup(TDrawArea* draw_area, TPanel* parent, long x, long y, long width, long height, int modal);
};
#endif /* PNL_BTN_SHARED_CONTEXT */

#ifndef PNL_BTN_SHARED_CONTEXT
class TButtonPanel : public TPanel {
public:
    char gap_04[0x13C];
    long drawTypeValue;               // 0x140
    long notifyTypeValue;             // 0x144

    void set_sound(TDigital* sound);
    void set_id(short state, long id1, long id2);

    long setup(
        TDrawArea* draw_area,
        TPanel* parent,
        long x,
        long y,
        long width,
        long height,
        long draw_type,
        TDigital* sound,
        long notify_type,
        long button_id
    );
};
#endif /* PNL_BTN_SHARED_CONTEXT */

long TButtonPanel::setup(
    TDrawArea* draw_area,
    TPanel* parent,
    long x,
    long y,
    long width,
    long height,
    long draw_type,
    TDigital* sound,
    long notify_type,
    long button_id
) {
    TPanel::setup(draw_area, parent, x, y, width, height, 0);
    this->drawTypeValue = draw_type;
    this->notifyTypeValue = notify_type;
    this->set_sound(sound);
    this->set_id(0, button_id, 0);
    return 1;
}

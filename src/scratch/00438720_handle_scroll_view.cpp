// 00438720 RGE_Diamond_Map::handle_scroll_view (diam_map.cpp:1402-1423)
// Retry 2026-05-19/20 assigned pass:
// - Revalidated inherited source: 148/148, MISMATCH, 80.4054% positional / 43.9189% edit, first mismatch +3.
// - Reordered saved original parameter locals to match decompiler/original final stores; edit diff improved slightly to 40.5405%, but first mismatch remains early LEA/load scheduling.
// - Tried explicit pointer locals for `(short*)&param_1`, `(short*)&param_2`, and `&tile`; no codegen change.
// - /Ob0 flag probe: no change; removed.
// Retry 2026-05-19 late assigned pass:
// - Direct pick_tile args instead of p1/p2/ptile locals: no change from best.
// - register orig_1/orig_2 worsened edit diff to 43.9189%; rolled back.
// - Separate short locals for pick_tile out params changed setup but worsened to 81.7568% positional; rolled back.
// - Explicit self local for pick_tile: no change.
// - /O1 shrank to 135B; /G5 no change; flags removed.
// - main_view temp and nested success block: no change.
// - volatile orig locals worsened edit diff to 66.8919%; initialized tile worsened to 87.1622%; rolled back.
// - Moving tile declaration after orig locals: no change.
// GIVEUP: behavior/calls/offsets are understood, but remaining mismatch is broad stack-address/setup and register allocation around pick_tile (original emits LEAs before saving EBX/ESI/EDI and loads EBX/EDI later; rebuilt preloads params and pushes in different schedule). No accepted_drift: broad topology drift, not localized.
// Retry assigned 2026-05-20:
// - Baseline revalidation: 148B exact size, 80.4054% positional / 40.5405% edit, first mismatch +3.
// - Removed saved original-parameter locals and wrote final stores from param slots; first LEAs matched to +11 but lost EBX/EDI preservation and worsened edit diff to 48.6486%; rolled back.
// - Declaring `tile` before saved originals and adding `const` to originals did not improve; same early preload/saved-register schedule.
// - Swapped pick out-parameter order plus swapped set_view_loc arguments improved edit diff to 39.1892% but was semantically suspect for pick_tile out slots; rolled back.
// - Explicit `ptile/out1/out2` pointer locals did not change codegen.
// - Tried reference-form pick_tile declaration/call; no codegen improvement, restored pointer signature.
// - /Ob1 probe under default flags produced no change; flag removed.
// GIVEUP: exactness still blocked by broad pre-call stack-address/register allocation topology around pick_tile; not accepted_drift.

class RGE_Player {
public:
    void set_view_loc(float x, float y);
};

class VBase {
public:
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void update_view(int);
};

class RGE_Diamond_Map : public VBase {
public:
    void handle_scroll_view(long param_1, long param_2);
    int pick_tile(long param_1, long param_2, short* out1, short* out2, void** out_tile);

    char gap_04[0xF0];
    void* world;                 // +0xF4
    RGE_Player* player;          // +0xF8
    char gap_FC[0x0C];
    long mouse_last_x;           // +0x108
    long mouse_last_y;           // +0x10C
    char gap_110[0x40];
    VBase* main_view;            // +0x150
    char gap_154[0x18];
};

void RGE_Diamond_Map::handle_scroll_view(long param_1, long param_2)
{
    long orig_2 = param_2;
    long orig_1 = param_1;
    void* tile;
    if (this->pick_tile(param_1, param_2, (short*)&param_1, (short*)&param_2, &tile) != 0) {
        this->player->set_view_loc((float)(short)param_2 - 0.5f, (float)(short)param_1 - 0.5f);

        this->update_view(1);

        if (this->main_view != 0) {
            this->main_view->update_view(1);
        }

        this->mouse_last_x = orig_1;
        this->mouse_last_y = orig_2;
    }
}

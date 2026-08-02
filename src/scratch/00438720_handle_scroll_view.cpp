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
// Retry 2026-05-21 Boss pass: revalidated baseline (148B, 80.4054% positional / 40.5405% edit, first mismatch +3). Tried pointer locals before original-param saves, volatile/register originals after pointer locals, saving originals after call from parameter homes, direct final stores from mutated parameter slots (matched first LEAs to +11 but lost EBX/EDI and worsened edit), reference-form out params, comma-if assignment, explicit assign-then-pointer locals, split declaration order, extra pointer-address dependency, and flags /Oa /Og- /O2-no-/Oy /Ob0+/G5. No exact or accepted-drift-quality result; direct-param family improves first LEAs but still has broad saved-register/pick_tile call topology drift.
// Retry 2026-05-24 Boss pass: 20 more probes. Revalidated baseline (148B, 80.4054% positional / 40.5405% edit, first mismatch +3). Tried tile-before-original declarations, original order swaps, no-saved-original/direct-param stores (first mismatch +11 but wrong behavior for final full-dword mouse stores and still 75.68% positional), direct-call success locals, named float/int temporaries, post-call saved locals, raw pointer out-param locals, swapped out params / swapped float args (best edit 39.19% but semantically suspect and still early mismatch), register/const/volatile original locals, explicit ok temp/comma call, main_view temp, casted virtual update calls, reference/address locals before original saves, assigning pointer locals before saves, saved refs, and orig-inside-args/copy-back variants. All real-behavior variants stay in the same early pick_tile setup basin; no accepted_drift because mismatch remains broad call setup/saved-register/stack-address topology.
// Luna-438720 bounded pass (2026-08-02, 10 hypotheses):
// - Fresh baseline: 152B vs 148B, 91.4474% positional diff, 28.29% edit diff, first mismatch +3; calls/frame aligned.
// - Restored the historical flat/raw-vtable source (160B, worse), then reused the exact matched diam_map.cpp TPanel/RGE_View donor surface (same 152B basin).
// - Typed the tile out-parameter and varied tile/original declaration order, volatile address aliases, direct parameter stores, register parameters, const out declarations, and separated assignments; no behavior-correct variant improved the setup basin.
// - Best retained source uses the matched TPanel/RGE_View surface, typed RGE_Tile**, and saved full-width original parameters. Remaining drift is the broad pre-pick_tile LEA/save/address topology (original LEAs precede callee-save pushes; rebuild has a four-byte larger setup), not accepted-drift quality.

struct RGE_Tile;

class RGE_Player {
public:
    void set_view_loc(float x, float y);
};

class TPanel {
public:
    virtual ~TPanel() {}
    virtual void v04() {}
    virtual void v08() {}
    virtual void v0C() {}
    virtual void v10() {}
    virtual void v14() {}
    virtual void v18() {}
    virtual void v1C() {}
    virtual void update_view(int mode) {}
    char gap_00[0xF0];
};

class RGE_View {
public:
    virtual ~RGE_View() {}
    virtual void v04() {}
    virtual void v08() {}
    virtual void v0C() {}
    virtual void v10() {}
    virtual void v14() {}
    virtual void v18() {}
    virtual void v1C() {}
    virtual void update_view(int mode) {}
};

class RGE_Diamond_Map : public TPanel {
public:
    void handle_scroll_view(long param_1, long param_2);
    int pick_tile(long param_1, long param_2, short* out1, short* out2, RGE_Tile** out_tile);

    char gap_F4[0x04];          // +0xF4: world (unused)
    RGE_Player* player;          // +0xF8
    char gap_FC[0x0C];
    long mouse_last_x;           // +0x108
    long mouse_last_y;           // +0x10C
    char gap_110[0x40];
    RGE_View* main_view;          // +0x150
    int scrolling;               // +0x154 (unused)
};

void RGE_Diamond_Map::handle_scroll_view(long param_1, long param_2)
{
    RGE_Tile* tile;
    long orig_2;
    long orig_1;
    orig_2 = param_2;
    orig_1 = param_1;
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

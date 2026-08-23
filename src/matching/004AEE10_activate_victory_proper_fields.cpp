// 004AEE10 TRIBE_Screen_Sed::activate_victory_proper_fields
// Attempt log:
// try 1: natural switch over victory mode/type, helper virtual slot +0x14 for set_active and direct TPanel helpers: 13.1% edit diff due switch normalization.
// try 2: added explicit case 0 so VC5 switches on raw 0..18 values, not type-1: down to 13 bytes / 1.0673% positional, 2.1346% edit.
// try 3: local temp around case 7 p738 did not change remaining drift.
// DRIFT_PROPOSAL: remaining bytes are localized to case 7 vtable temp-register choice for three set_active calls (eax vs edx load/call at same [vptr+0x14]) plus equivalent relocation-masked direct call target display for set_curr_child. Behavior, stack cleanup, offsets, switch table, and all called slots match.

class PanelActive {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void set_active(int active);
};

class TPanel {
public:
    void set_curr_child(TPanel* p);
    void set_help_info(long id, long unk);
};

class TRIBE_Screen_Sed {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(); virtual void v49();
    virtual void set_tab_order(TPanel** panels, int count); // +0xC8

    char gap_004[0x49C];
    int field_4A0;
    char gap_4A4[0x30];
    TPanel* curr_child;      // +4D4
    char gap_4D8[0x260];
    TPanel* p738; TPanel* p73c; TPanel* p740; TPanel* p744; TPanel* p748; TPanel* p74c; TPanel* p750; TPanel* p754; TPanel* p758; TPanel* p75c; TPanel* p760; TPanel* p764; TPanel* p768; TPanel* p76c;

    void activate_victory_proper_fields(int type, int active);
};

#define ACT(P) ((PanelActive*)(P))->set_active(active)
#define OFF(P) ((PanelActive*)(P))->set_active(0)

void TRIBE_Screen_Sed::activate_victory_proper_fields(int type, int active)
{
    TPanel* ptr[2];
    this->field_4A0 = 0;
    if (active == 0) {
        OFF(this->p738); OFF(this->p764); OFF(this->p76c); OFF(this->p750); OFF(this->p754); OFF(this->p758);
        OFF(this->p768); OFF(this->p740); OFF(this->p744); OFF(this->p748); OFF(this->p74c);
        return;
    }

    this->curr_child->set_curr_child(0);
    switch (type) {
    case 0:
        return;
    case 1:
        ACT(this->p750); ACT(this->p754); return;
    case 2:
        ACT(this->p750); ACT(this->p754); ACT(this->p758); return;
    case 3:
        ACT(this->p738); ACT(this->p764); ACT(this->p76c);
        this->p76c->set_help_info(0x7766, -1);
        goto set_res;
    case 4:
        ACT(this->p738); ACT(this->p764); ACT(this->p76c);
        this->p76c->set_help_info(0x7767, -1);
        this->curr_child->set_curr_child(this->p76c);
        ACT(this->p754); ACT(this->p758); return;
    case 5:
        ACT(this->p738); ACT(this->p764); ACT(this->p76c); ACT(this->p768);
        this->p76c->set_help_info(0x7768, -1);
        ACT(this->p740);
        ptr[0] = this->p740; ptr[1] = this->p76c;
        this->set_tab_order(ptr, 2);
        goto set_p740;
    case 7:
        { TPanel* a = this->p738; ACT(a); }
        ACT(this->p768); ACT(this->p740);
        this->curr_child->set_curr_child(this->p740);
        return;
    case 8:
        ACT(this->p768); ACT(this->p740);
set_p740:
        this->curr_child->set_curr_child(this->p740);
        return;
    case 6:
    case 9:
        ACT(this->p750); return;
    case 15:
        ACT(this->p748); return;
    case 10:
        this->p76c->set_help_info(0x7769, -1); ACT(this->p764); ACT(this->p76c); this->curr_child->set_curr_child(this->p76c); return;
    case 11:
        this->p76c->set_help_info(0x776a, -1); ACT(this->p764); ACT(this->p76c); this->curr_child->set_curr_child(this->p76c); return;
    case 12:
        this->p76c->set_help_info(0x776b, -1); ACT(this->p764); ACT(this->p76c); this->curr_child->set_curr_child(this->p76c); return;
    case 13:
        this->p76c->set_help_info(0x776c, -1); ACT(this->p764); ACT(this->p76c); this->curr_child->set_curr_child(this->p76c); return;
    case 14:
        this->p76c->set_help_info(0x776d, -1); ACT(this->p764); ACT(this->p76c); this->curr_child->set_curr_child(this->p76c); return;
    case 16:
        this->p76c->set_help_info(0x776e, -1); ACT(this->p764); ACT(this->p76c); this->curr_child->set_curr_child(this->p76c); return;
    case 17:
        ACT(this->p764); ACT(this->p76c); this->p76c->set_help_info(0x776f, -1); this->curr_child->set_curr_child(this->p76c); ACT(this->p744); return;
    case 18:
        ACT(this->p74c); return;
    default:
        return;
    }
set_res:
    this->curr_child->set_curr_child(this->p76c);
}

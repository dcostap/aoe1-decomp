// VA: 004A94A0 TRIBE_Screen_Sed::~TRIBE_Screen_Sed
// PDB: scr_sed.cpp:890-1144
// virtual __thiscall ~TRIBE_Screen_Sed()
// Attempt log:
// 1: broad reconstruction from packet/decompiler + scr_sed field layout; /GX EH destructor.
// Main-agent plausibility audit: replaced explicit destructor/operator_delete
// plumbing with ordinary `delete p`; emitted bytes remained exactly identical.

#ifndef SCR_SED_TU_CONTEXT
extern "C" void __cdecl free(void*);

class TPanel {
public:
    char pad_00[0xF0];
    void delete_panel(TPanel** panel);
    virtual ~TPanel();
};

class TShape {
public:
    ~TShape();
};

class TRIBE_Panel_Object {
public:
    virtual void slot0(int v);
};

class TRIBE_World {
public:
    virtual void v0(void);
    virtual void v1(void);
    virtual void v2(void);
    virtual void v3(void);
    virtual void v4(void);
    virtual void v5(void);
    virtual void v6(void);
    virtual void v7(void);
    virtual void v8(void);
    virtual void v9(void);
    virtual void v10(void);
    virtual void v11(void);
    virtual void v12(void);
    virtual void v13(void);
    virtual void v14(void);
    virtual void v15(void);
    virtual void v16(void);
    virtual void v17(void);
    virtual void v18(void);
    virtual void v19(void);
    virtual void v20(void);
    virtual void v21(void);
    virtual void v22(void);
    virtual void v23(void);
    virtual void v24(void);
    virtual void v25(void);
    virtual void v26(void);
    virtual void v27(void);
    virtual void v28(void);
    virtual void v29(void);
    virtual void v30(void);
    virtual void v31(void);
    virtual void v32(void);
    virtual void v33(void);
    virtual void v34(void);
    virtual void v35(void);
    virtual void v36(void);
    virtual void v37(void);
    virtual void v38(void);
    virtual void v39(void);
    virtual void v40(void);
    virtual void v41(void);
    virtual void v42(void);
    virtual void v43(void);
    virtual void v44(void);
    virtual void v45(void);
    virtual void v46(void);
};

class TPanelSystem {
public:
    int destroyPanel(char* name);
};
extern TPanelSystem panel_system;

class TScreenPanel : public TPanel {
public:
    char pad_F4[0x384];
    virtual ~TScreenPanel();
};

class TRIBE_Screen_Sed : public TScreenPanel {
public:
    char pad_478[0x4C];              // 0x478
    TShape* background_pic;          // 0x4C4
    TPanel* main_view;               // 0x4C8
    TPanel* map_view;                // 0x4CC
    TPanel* message_panel;           // 0x4D0
    TPanel* bottom_panel;            // 0x4D4
    TPanel* scenario_mode_button[10];// 0x4D8
    TPanel* p500;                    // 0x500
    TPanel* p504;                    // 0x504
    TPanel* arrA[3];                 // 0x508
    TPanel* arrB[3];                 // 0x514
    TPanel* p520;                    // 0x520
    TPanel* p524;                    // 0x524
    TPanel* p528;                    // 0x528
    TPanel* p52C;                    // 0x52C
    TPanel* p530;                    // 0x530
    TPanel* p534;                    // 0x534
    TPanel* p538;                    // 0x538
    TPanel* p53C;                    // 0x53C
    TPanel* p540;                    // 0x540
    TPanel* p544;                    // 0x544
    TPanel* p548;                    // 0x548
    TPanel* p54C;                    // 0x54C
    TPanel* p550;                    // 0x550
    TPanel* p554;                    // 0x554
    TPanel* arrC[5];                 // 0x558
    TPanel* arrC2[5];                // 0x56C
    TPanel* p580;                    // 0x580
    TPanel* arrD[3];                 // 0x584
    TPanel* arrD2[3];                // 0x590
    TPanel* p59C;                    // 0x59C
    TPanel* p5A0;                    // 0x5A0
    TPanel* p5A4;                    // 0x5A4
    TPanel* p5A8;                    // 0x5A8
    TPanel* p5AC;                    // 0x5AC
    TPanel* p5B0;                    // 0x5B0
    TPanel* p5B4;                    // 0x5B4
    TPanel* p5B8;                    // 0x5B8
    TPanel* p5BC;                    // 0x5BC
    char pad_5C0[4];                 // 0x5C0
    TPanel* arrE[5];                 // 0x5C4
    TPanel* arrE2[5];                // 0x5D8
    TPanel* arrF[2];                 // 0x5EC
    TPanel* p5F4;                    // 0x5F4
    TPanel* arrF2[2];                // 0x5F8
    TPanel* p600;                    // 0x600
    TPanel* p604;                    // 0x604
    TPanel* p608;                    // 0x608
    TPanel* p60C;                    // 0x60C
    TPanel* p610;                    // 0x610
    TPanel* p614;                    // 0x614
    TPanel* p618;                    // 0x618
    TPanel* arrG[4];                 // 0x61C
    TPanel* arrG2[4];                // 0x62C
    TPanel* p63C;                    // 0x63C
    TPanel* p640;                    // 0x640
    void* unit_list_info;            // 0x644
    TShape* button_unit_pics;        // 0x648
    TShape* button_bldg_pics[5];     // 0x64C
    TRIBE_Panel_Object* object_panel;// 0x660
    char pad_664[4];                 // 0x664
    TPanel* victory_cond_on[6];      // 0x668
    TPanel* arrH[2];                 // 0x680
    TPanel* p688;                    // 0x688
    TPanel* p68C;                    // 0x68C
    TPanel* p690;                    // 0x690
    TPanel* arrH2[2];                // 0x694
    TPanel* p69C;                    // 0x69C
    TPanel* p6A0;                    // 0x6A0
    TPanel* p6A4;                    // 0x6A4
    TPanel* p6A8;                    // 0x6A8
    TPanel* p6AC;                    // 0x6AC
    TPanel* p6B0;                    // 0x6B0
    TPanel* p6B4;                    // 0x6B4
    TPanel* p6B8;                    // 0x6B8
    TPanel* p6BC;                    // 0x6BC
    TPanel* p6C0;                    // 0x6C0
    TPanel* p6C4;                    // 0x6C4
    TPanel* p6C8;                    // 0x6C8
    TPanel* arrI[5];                 // 0x6CC
    TPanel* arrI2[5];                // 0x6E0
    TPanel* p6F4;                    // 0x6F4
    TPanel* p6F8;                    // 0x6F8
    TPanel* p6FC;                    // 0x6FC
    TPanel* p700;                    // 0x700
    TPanel* victory_button[12];      // 0x704
    TPanel* p734;                    // 0x734
    TPanel* p738;                    // 0x738
    TPanel* p73C;                    // 0x73C
    TPanel* p740;                    // 0x740
    TPanel* p744;                    // 0x744
    TPanel* p748;                    // 0x748
    TPanel* p74C;                    // 0x74C
    TPanel* p750;                    // 0x750
    TPanel* p754;                    // 0x754
    TPanel* p758;                    // 0x758
    TPanel* p75C;                    // 0x75C
    TPanel* p760;                    // 0x760
    TPanel* p764;                    // 0x764
    TPanel* p768;                    // 0x768
    TPanel* p76C;                    // 0x76C
    TPanel* p770;                    // 0x770
    TPanel* p774;                    // 0x774
    TPanel* arrJ[5];                 // 0x778
    TPanel* arrJ2[5];                // 0x78C
    char pad_79C[4];                 // 0x79C
    TPanel* arrK[4];                 // 0x7A4
    TPanel* arrK2[4];                // 0x7B4
    TPanel* arrL[1];                 // 0x7C4
    TPanel* arrL2[1];                // 0x7C8
    TPanel* p7CC;                    // 0x7CC
    TPanel* p7D0;                    // 0x7D0
    TPanel* arrM[16];                // 0x7D4
    TPanel* arrM2[16];               // 0x814
    char pad_850[0x20];              // 0x850
    TPanel* diplA[8];                // 0x874
    TPanel* dipplayer;               // 0x894
    TPanel* p898;                    // 0x898
    TPanel* p89C;                    // 0x89C
    TPanel* p8A0;                    // 0x8A0
    TPanel* p8A4;                    // 0x8A4
    TPanel* diplB[24];               // 0x8A8
    TPanel* diplAllied[8];           // 0x908
    TRIBE_World* world;              // 0x928

    virtual ~TRIBE_Screen_Sed();
};
#endif

TRIBE_Screen_Sed::~TRIBE_Screen_Sed()
{
    panel_system.destroyPanel((char*)0x00586D18);
    panel_system.destroyPanel((char*)0x00586D08);
    panel_system.destroyPanel((char*)0x00586CF8);
    panel_system.destroyPanel((char*)0x005843B8);
    panel_system.destroyPanel((char*)0x005843CC);

    this->delete_panel(&this->p520);
    {
        TPanel** pp = (TPanel**)this->arrB;
        int count = 3;
        do {
            this->delete_panel(pp - 3);
            this->delete_panel(pp);
            pp++;
            count--;
        } while (count != 0);
    }
    this->delete_panel(&this->p524);
    this->delete_panel(&this->p528);
    this->delete_panel(&this->p52C);
    this->delete_panel(&this->p530);
    this->delete_panel(&this->p538);
    this->delete_panel(&this->p534);
    this->delete_panel(&this->p550);
    this->delete_panel(&this->p53C);
    this->delete_panel(&this->p540);
    this->delete_panel(&this->p544);
    this->delete_panel(&this->p548);
    this->delete_panel(&this->p54C);
    this->delete_panel(&this->p554);
    {
        TPanel** pp = (TPanel**)this->arrC2;
        int count = 5;
        do {
            this->delete_panel(pp - 5);
            this->delete_panel(pp);
            pp++;
            count--;
        } while (count != 0);
    }
    this->delete_panel(&this->p580);
    {
        TPanel** pp = (TPanel**)this->arrD2;
        int count = 3;
        do {
            this->delete_panel(pp - 3);
            this->delete_panel(pp);
            pp++;
            count--;
        } while (count != 0);
    }
    this->delete_panel(&this->p59C);
    this->delete_panel(&this->p5A0);
    this->delete_panel(&this->p5A4);
    this->delete_panel(&this->p5A8);
    this->delete_panel(&this->p5AC);
    this->delete_panel(&this->p5BC);
    this->delete_panel(&this->p5B0);
    this->delete_panel(&this->p5F4);
    this->delete_panel(&this->p60C);
    this->delete_panel(&this->p610);
    this->delete_panel(&this->p614);
    this->delete_panel(&this->p5B4);
    this->delete_panel(&this->p5B8);
    {
        TPanel** pp = (TPanel**)this->arrE2;
        int count = 5;
        do {
            this->delete_panel(pp - 5);
            this->delete_panel(pp);
            pp++;
            count--;
        } while (count != 0);
    }
    {
        TPanel** pp = (TPanel**)this->arrF2;
        int count = 2;
        do {
            this->delete_panel(pp - 3);
            this->delete_panel(pp);
            pp++;
            count--;
        } while (count != 0);
    }
    this->delete_panel(&this->p600);
    this->delete_panel(&this->p604);
    this->delete_panel(&this->p608);
    this->delete_panel(&this->p618);
    {
        TPanel** pp = (TPanel**)this->arrG2;
        int count = 4;
        do {
            this->delete_panel(pp - 4);
            this->delete_panel(pp);
            pp++;
            count--;
        } while (count != 0);
    }
    this->delete_panel(&this->p63C);
    this->delete_panel(&this->p640);
    if (this->unit_list_info != 0) {
        free(this->unit_list_info);
        this->unit_list_info = 0;
    }
    if (this->object_panel != 0) {
        this->object_panel->slot0(1);
        this->object_panel = 0;
    }
    if (this->button_unit_pics != 0) {
        TShape* p = this->button_unit_pics;
        delete p;
        this->button_unit_pics = 0;
    }
    {
        TShape** pp = this->button_bldg_pics;
        int count = 5;
        do {
            TShape* p = *pp;
            if (p != 0) {
                delete p;
                *pp = 0;
            }
            pp++;
            count--;
        } while (count != 0);
    }
    {
        TPanel** pp = (TPanel**)this->victory_cond_on;
        int count = 6;
        do {
            this->delete_panel(pp);
            pp++;
            count--;
        } while (count != 0);
    }
    {
        TPanel** pp = (TPanel**)this->arrH2;
        int count = 2;
        do {
            this->delete_panel(pp - 5);
            this->delete_panel(pp);
            pp++;
            count--;
        } while (count != 0);
    }
    this->delete_panel(&this->p68C);
    this->delete_panel(&this->p690);
    this->delete_panel(&this->p688);
    this->delete_panel(&this->p69C);
    this->delete_panel(&this->p6A0);
    this->delete_panel(&this->p6A4);
    this->delete_panel(&this->p6A8);
    this->delete_panel(&this->p6AC);
    this->delete_panel(&this->p6B0);
    this->delete_panel(&this->p6B4);
    this->delete_panel(&this->p6B8);
    this->delete_panel(&this->p6BC);
    this->delete_panel(&this->p6C0);
    this->delete_panel(&this->p6C4);
    this->delete_panel(&this->p6C8);
    {
        TPanel** pp = (TPanel**)this->arrI2;
        int count = 5;
        do {
            this->delete_panel(pp - 5);
            this->delete_panel(pp);
            pp++;
            count--;
        } while (count != 0);
    }
    this->delete_panel(&this->p6F4);
    this->delete_panel(&this->p6F8);
    this->delete_panel(&this->p6FC);
    this->delete_panel(&this->p700);
    {
        TPanel** pp = (TPanel**)this->victory_button;
        int count = 12;
        do {
            this->delete_panel(pp);
            pp++;
            count--;
        } while (count != 0);
    }
    this->delete_panel(&this->p734);
    this->delete_panel(&this->p738);
    this->delete_panel(&this->p73C);
    this->delete_panel(&this->p748);
    this->delete_panel(&this->p74C);
    this->delete_panel(&this->p750);
    this->delete_panel(&this->p754);
    this->delete_panel(&this->p758);
    this->delete_panel(&this->p75C);
    this->delete_panel(&this->p760);
    this->delete_panel(&this->p764);
    this->delete_panel(&this->p76C);
    this->delete_panel(&this->p740);
    this->delete_panel(&this->p744);
    this->delete_panel(&this->p768);
    this->delete_panel(&this->p770);
    {
        TPanel** pp = (TPanel**)this->arrJ2;
        int count = 5;
        do {
            this->delete_panel(pp - 5);
            this->delete_panel(pp);
            pp++;
            count--;
        } while (count != 0);
    }
    this->delete_panel(&this->p774);
    {
        TPanel** pp = (TPanel**)this->arrK2;
        int count = 4;
        do {
            this->delete_panel(pp - 4);
            this->delete_panel(pp);
            pp++;
            count--;
        } while (count != 0);
    }
    {
        TPanel** pp = (TPanel**)this->arrL2;
        int count = 1;
        do {
            this->delete_panel(pp - 1);
            this->delete_panel(pp);
            pp++;
            count--;
        } while (count != 0);
    }
    this->delete_panel(&this->p7CC);
    this->delete_panel(&this->p7D0);
    {
        TPanel** pp = (TPanel**)this->arrM2;
        int count = 16;
        do {
            this->delete_panel(pp - 16);
            this->delete_panel(pp);
            pp++;
            count--;
        } while (count != 0);
    }
    {
        for (int i = 0; i < 8; i++) {
            this->delete_panel(&this->dipplayer);
            this->delete_panel(&this->diplA[i]);
            this->delete_panel(&this->diplB[i * 3 + 0]);
            this->delete_panel(&this->diplB[i * 3 + 1]);
            this->delete_panel(&this->diplB[i * 3 + 2]);
            this->delete_panel(&this->diplAllied[i]);
        }
    }
    this->delete_panel(&this->p898);
    this->delete_panel(&this->p89C);
    this->delete_panel(&this->p8A0);
    this->delete_panel(&this->p8A4);
    this->delete_panel(&this->p500);
    this->delete_panel(&this->p504);
    {
        TPanel** pp = (TPanel**)this->scenario_mode_button;
        int count = 10;
        do {
            this->delete_panel(pp);
            pp++;
            count--;
        } while (count != 0);
    }
    this->delete_panel(&this->bottom_panel);
    this->delete_panel(&this->message_panel);
    this->delete_panel(&this->main_view);
    this->delete_panel(&this->map_view);
    if (this->background_pic != 0) {
        TShape* p = this->background_pic;
        delete p;
        this->background_pic = 0;
    }
    if (this->world != 0) {
        this->world->v46();
    }
}

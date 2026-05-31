// VA: 004A68C0 TRIBE_Screen_Name::setup_tab_order
// PDB source: scr_name.cpp
// 2026-05-31: Replaced raw fastcall wrappers with natural member/virtual surface.

class TPanel {};

class TTextPanel : public TPanel {
public:
    int numberLines();
};

class TButtonPanel : public TPanel {
public:
    void set_disabled(int disabled);
};

#define VPAD1(n) virtual void vpad##n();
#define VPAD2(n) VPAD1(n) VPAD1(n##_1)
#define VPAD4(n) VPAD2(n) VPAD2(n##_2)
#define VPAD8(n) VPAD4(n) VPAD4(n##_4)
#define VPAD16(n) VPAD8(n) VPAD8(n##_8)
#define VPAD32(n) VPAD16(n) VPAD16(n##_16)

class TRIBE_Screen_Name {
public:
    VPAD32(0)        // slots 0..31
    VPAD16(32)       // slots 32..47
    VPAD1(48)
    VPAD1(49)
    virtual void set_tab_order(TPanel** panels, int count); // slot 50 / +0xC8

    char gap_04[0x47C];
    TTextPanel* name_list;       // +0x480
    char gap_484[4];
    TPanel* new_button;          // +0x488
    TButtonPanel* remove_button; // +0x48C
    TButtonPanel* ok_button;     // +0x490
    TPanel* cancel_button;       // +0x494

    void set_curr_child(TPanel* child);
    void setup_tab_order();
};

void TRIBE_Screen_Name::setup_tab_order()
{
    int disabled = 0;
    if (this->name_list->numberLines() == 0) {
        disabled = 1;
    }

    this->remove_button->set_disabled(disabled);
    this->ok_button->set_disabled(disabled);

    TPanel* tab_list[5];
    tab_list[0] = this->name_list;
    tab_list[1] = this->new_button;

    int count = 2;
    if (disabled == 0) {
        tab_list[2] = this->remove_button;
        tab_list[3] = this->ok_button;
        count = 4;
    }

    tab_list[count] = this->cancel_button;
    count++;
    this->set_tab_order(tab_list, count);

    if (this->name_list->numberLines() == 0) {
        this->set_curr_child(this->new_button);
    } else {
        this->set_curr_child(this->name_list);
    }
}

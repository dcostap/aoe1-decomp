// VA: 004AA7A0 TRIBE_Screen_Sed::set_map_type | scr_sed.cpp:1566-1634
// First natural pass from Ghidra/asm.

#ifndef SCR_SED_TU_CONTEXT
struct TPanel {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void set_active(int active);
    virtual void v18();
    virtual void v1C();
    virtual void redraw(int flags);
    void set_curr_child(TPanel* child);
};

struct TButtonPanel : public TPanel {
    void set_radio_button();
};
struct TTextPanel : public TPanel {};
struct TDropDownPanel : public TTextPanel {};
struct TEditPanel : public TTextPanel {};

struct TRIBE_Screen_Sed {
    enum MapType {
        MapTypeNone = 0,
        MapTypeBlankValue = 1,
        MapTypeSeedValue = 2,
        MapTypeRandomValue = 3
    };
    char gap_00[0x4A8];
    int map_type;
    char gap_4AC[0x4D4 - 0x4AC];
    TPanel* bottom_panel;
    char gap_4D8[0x504 - 0x4D8];
    TButtonPanel* help_button;
    TButtonPanel* map_type_button[3];
    TTextPanel* map_type_text[3];
    TTextPanel* map_type_label;
    TTextPanel* default_terrain_label;
    TDropDownPanel* default_terrain_drop;
    TTextPanel* map_size_label;
    TDropDownPanel* map_size_drop;
    TTextPanel* map_style_label;
    TDropDownPanel* map_style_drop;
    TTextPanel* random_seed_label;
    TEditPanel* random_seed_input;
    TTextPanel* random_seed_used_label;
    TTextPanel* random_seed_used_text;

protected:
    void set_map_type(MapType type, int redraw);
};
#endif

void TRIBE_Screen_Sed::set_map_type(MapType type, int redraw)
{
    int pass;
    int active;
    int mode;
    TPanel* p;

    pass = 0;
    do {
        if (pass == 0) {
            active = 0;
            mode = this->map_type;
        } else {
            if (type == 0) {
                return;
            }
            if (redraw == 0) {
                break;
            }
            mode = type;
            active = 1;
        }

        switch (mode) {
        case 1:
            this->map_size_label->set_active(active);
            this->map_size_drop->set_active(active);
            this->default_terrain_label->set_active(active);
            p = this->default_terrain_drop;
            p->set_active(active);
            break;
        case 2:
            this->map_size_label->set_active(active);
            this->map_size_drop->set_active(active);
            this->map_style_label->set_active(active);
            this->map_style_drop->set_active(active);
            this->random_seed_used_label->set_active(active);
            p = this->random_seed_used_text;
            p->set_active(active);
            break;
        case 3:
            this->map_size_label->set_active(active);
            this->map_size_drop->set_active(active);
            this->map_style_label->set_active(active);
            this->map_style_drop->set_active(active);
            this->random_seed_label->set_active(active);
            this->random_seed_input->set_active(active);
            if (active != 0) {
                this->bottom_panel->set_curr_child(this->random_seed_input);
            }
            break;
        }
        pass++;
    } while (pass < 2);

    this->map_type = type;
    this->map_type_button[type - 1]->set_radio_button();
    this->bottom_panel->redraw(1);
}

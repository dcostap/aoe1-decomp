// VA: 004AAB60 TRIBE_Screen_Sed::set_paint_type | scr_sed.cpp:1755-1838

struct TPanel {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C(); virtual void v10();
    virtual void set_active(int active); virtual void v18(); virtual void v1C(); virtual void redraw(int flags);
    void set_curr_child(TPanel* child);
};
struct TButtonPanel : public TPanel { void set_radio_button(); };
struct TTextPanel : public TPanel { int currentLineNumber(); };
struct TListPanel : public TTextPanel {};

struct RGE_Base_Game_Dispatch { virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C(); virtual void redraw(long mode, long flags); };
extern RGE_Base_Game_Dispatch* rge_base_game;

struct TRIBE_Screen_Sed {
    char gap_00[0x4B4];
    int paint_type;
    char gap_4B8[0x4D4 - 0x4B8];
    TPanel* bottom_panel;
    char gap_4D8[0x554 - 0x4D8];
    TTextPanel* brush_size_label;
    TButtonPanel* brush_size_button[5];
    TTextPanel* brush_size_button_label[5];
    TTextPanel* paint_type_label;
    TButtonPanel* paint_type_button[3];
    TTextPanel* paint_type_button_label[3];
    TTextPanel* paint_terrain_label;
    TListPanel* paint_terrain_list;
    void* paint_terrain_scrollbar;
    TListPanel* paint_elevation_list;

    void set_paint_type(int type, int redraw);
    void set_terrain(short terrain);
    void set_elevation(short elevation);
};

void TRIBE_Screen_Sed::set_paint_type(int type, int redraw)
{
    int pass;
    int active;
    int mode;
    int count;
    TTextPanel** pp;

    pass = 0;
    do {
        if (pass == 0) {
            mode = this->paint_type;
            active = 0;
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

        this->brush_size_label->set_active(active);
        pp = this->brush_size_button_label;
        count = 5;
        do {
            ((TButtonPanel*)pp[-5])->set_active(active);
            (*pp)->set_active(active);
            pp++;
            count--;
        } while (count != 0);

        switch (mode) {
        case 1:
            this->paint_terrain_list->set_active(active);
            this->paint_terrain_label->set_active(active);
            if (active != 0) {
                this->set_terrain((short)this->paint_terrain_list->currentLineNumber());
                rge_base_game->redraw(9, 0);
            } else {
                rge_base_game->redraw(0, 0);
            }
            break;
        case 2:
            this->paint_elevation_list->set_active(active);
            this->paint_terrain_label->set_active(active);
            if (active != 0) {
                this->set_elevation((short)this->paint_elevation_list->currentLineNumber());
                rge_base_game->redraw(10, 0);
            } else {
                rge_base_game->redraw(0, 0);
            }
            break;
        case 3:
            this->paint_elevation_list->set_active(0);
            this->paint_terrain_list->set_active(0);
            this->paint_terrain_label->set_active(0);
            this->brush_size_label->set_active(0);
            pp = this->brush_size_button_label;
            count = 5;
            do {
                ((TButtonPanel*)pp[-5])->set_active(0);
                (*pp)->set_active(0);
                pp++;
                count--;
            } while (count != 0);
            if (active != 0) {
                this->set_elevation((short)this->paint_elevation_list->currentLineNumber());
                rge_base_game->redraw(0x13, 0);
            } else {
                rge_base_game->redraw(0, 0);
            }
            break;
        }
        pass++;
    } while (pass < 2);

    this->paint_type = type;
    this->paint_type_button[type - 1]->set_radio_button();
    this->bottom_panel->redraw(1);
}

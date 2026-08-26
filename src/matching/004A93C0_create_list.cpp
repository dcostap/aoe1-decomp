// TRIBE_Screen_Sed::create_list — real pass
// VA: 004A93C0
// PDB: scr_sed.cpp:854-884 (TRIBE_Screen_Sed::create_list)
// Layout evidence: paint_terrain_list @ 0x5A0, paint_terrain_scrollbar @ 0x5A4,
// paint_elevation_list @ 0x5A8 (from matched set_paint_type/set_terrain/set_elevation).
// Calls: TEasy_Panel::create_list(004696B0), vtable slot +0x14 on *out,
// TTextPanel::empty_list(0047E370), TEasy_Panel::create_auto_scrollbar(00469A80),
// set_string(004A87D0), sprintf(0054BBC0), TTextPanel::append_line(0047DCD0),
// SetupListOfTerrain(004A9320).
#include <stdio.h>
#ifndef SCR_SED_TU_CONTEXT

class TPanel {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void set_active(int active);
    virtual void v18();
    virtual void v1C();
    virtual void redraw(int flags);

    char gap_04[0xF4 - 0x04];
};

class TTextPanel : public TPanel {
public:
    char gap_F4[0xFC - 0xF4];
    short num_lines;

    void empty_list();
    int append_line(char* text, long value);
};

class TListPanel : public TTextPanel {
};

class TScrollBarPanel {
public:
    char gap_00[4];
};

class TEasy_Panel : public TPanel {
public:
    char gap_F4[0x478 - 0xF4];

    int create_list(TPanel* panel, TListPanel** out, long x, long font, long w, long h, long lines);
    int create_auto_scrollbar(TScrollBarPanel** scrollbar_out, TTextPanel* text, long param_3);
};

class TScreenPanel : public TEasy_Panel {
};

class TRIBE_Screen_Sed : public TScreenPanel {
public:
    char gap_478[0x5A0 - 0x478];
    TListPanel* paint_terrain_list;
    TScrollBarPanel* paint_terrain_scrollbar;
    TListPanel* paint_elevation_list;

    void set_string(char* buffer, long panel_id, int limit);
    int SetupListOfTerrain(TListPanel* list);
    int create_list(TPanel* panel, TListPanel** out, TScrollBarPanel** scroll);
};
#endif

int TRIBE_Screen_Sed::create_list(TPanel* panel, TListPanel** out, TScrollBarPanel** scroll)
{
    char str1[50];
    char str2[60];

    if (this->TEasy_Panel::create_list(panel, out, 0, 0, 0, 0, 10) == 0)
        return 0;

    (*out)->set_active(0);
    (*out)->empty_list();

    if (this->TEasy_Panel::create_auto_scrollbar(scroll, *out, 0x14) == 0)
        return 0;

    if (out == &this->paint_elevation_list) {
        this->set_string(str1, 0x2987, 0x32);
        for (int i = 0; i < 7; i++) {
            sprintf(str2, "%s %d", str1, i + 1);
            this->paint_elevation_list->append_line(str2, 0);
        }
        return 1;
    }

    if (out == &this->paint_terrain_list) {
        this->SetupListOfTerrain(this->paint_terrain_list);
    }

    return 1;
}

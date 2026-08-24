#ifndef TVW_DMAP_CONTEXT_H
#define TVW_DMAP_CONTEXT_H

// Canonical declarations for the tvw_dmap.cpp owner sequence.
// The base surface preserves the observed object offsets and direct calls.

typedef unsigned char uchar;

class TPanel {
public:
    enum RedrawMode {
        redraw_none = 0,
        redraw_local = 1,
        redraw_all = 2
    };
};

class TRIBE_Screen_Game {
public:
    void set_map_buttons_redraw(TPanel::RedrawMode mode);
};

class RGE_Static_Object;

class RGE_Diamond_Map {
public:
    virtual ~RGE_Diamond_Map();
    RGE_Diamond_Map();

    virtual void set_redraw(TPanel::RedrawMode mode);

    char gap_04[0x3C];
    TRIBE_Screen_Game* screen_game;
    char gap_40[0x28];
    int field_6C;
    int field_70;
    char gap_74[0xE8];
    int draw_objects_mode;
    char gap_160[0xC];

protected:
    virtual void draw_objects();
    virtual void draw_object(short, short, uchar, short, RGE_Static_Object*);
};

typedef char tvw_dmap_base_size_check[(sizeof(RGE_Diamond_Map) == 0x16C) ? 1 : -1];

class RGE_Diamond_Map_View : public RGE_Diamond_Map {
public:
    RGE_Diamond_Map_View();
};

class TRIBE_Diamond_Map_View : public RGE_Diamond_Map_View {
public:
    TRIBE_Diamond_Map_View();
    unsigned long last_attack_time;
    int flash_on;

    virtual void set_redraw(TPanel::RedrawMode mode);

protected:
    virtual void draw_objects();
    virtual void draw_object(short, short, uchar, short, RGE_Static_Object*);
};

typedef char tvw_dmap_view_size_check[(sizeof(TRIBE_Diamond_Map_View) == 0x174) ? 1 : -1];

extern "C" unsigned long __cdecl debug_timeGetTime(char* file, int line);

#endif

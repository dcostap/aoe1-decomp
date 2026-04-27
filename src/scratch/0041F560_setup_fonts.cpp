// VA: 0041F560 RGE_Base_Game::setup_fonts (410 B)
// PDB source: basegame.cpp
// Packet-grounded: calloc font array, GetDc, loop 12 fonts with switch on lang IDs, SelectObject/GetTextMetrics, ReleaseDc

extern void* calloc(int num, int size);
extern void* GetDc(void* draw_area, const char* who);
extern void ReleaseDc(void* draw_area, const char* who);
extern void* make_font(void* self, void* dc, int lang_id, int italic);
extern int SelectObject(void* dc, void* obj);
extern int GetTextMetricsA(void* dc, int* tm);

struct Shim_1F560 {
    char p0[0x4C];
    void* draw_area;           // +0x4C
    char p50[0x1E0 - 0x50];
    short font_num;            // +0x1E0 (word)
    char p1E2[0x1E4 - 0x1E2];
    void* fonts;               // +0x1E4
};

int RGE_Base_Game_setup_fonts(Shim_1F560* self)
{
    void* dc;
    int tm[16];
    void* f;
    int old_obj;
    int i;
    int idx;
    
    self->font_num = 12;
    self->fonts = calloc(12, 12);
    if (!self->fonts)
        return 0;
    
    dc = GetDc(self->draw_area, "basegame::setup_fonts");
    if (!dc)
        return 0;
    
    for (i = 0; i < self->font_num; i++) {
        idx = i;
        switch (idx) {
            case 0:  f = make_font(self, dc, 0x6E, 0); break;
            case 1:  f = make_font(self, dc, 0x71, 0); break;
            case 4:  f = make_font(self, dc, 0x74, 0); break;
            case 6:  f = make_font(self, dc, 0x83, 0); break;
            case 7:  f = make_font(self, dc, 0x77, 0); break;
            case 8:  f = make_font(self, dc, 0x80, 1); break;
            case 9:  f = make_font(self, dc, 0x7A, 0); break;
            case 10: f = make_font(self, dc, 0x7D, 0); break;
            case 11: f = make_font(self, dc, 0x80, 0); break;
            default: f = 0; break;
        }
        if (f) {
            old_obj = SelectObject(dc, f);
            GetTextMetricsA(dc, tm);
            ((int*)self->fonts)[idx * 3 + 0] = (int)f;
            ((int*)self->fonts)[idx * 3 + 1] = tm[3];      // tmMaxCharWidth
            ((int*)self->fonts)[idx * 3 + 2] = tm[1] + tm[4]; // tmAscent + tmAveCharWidth
            SelectObject(dc, (void*)old_obj);
        }
    }
    
    ReleaseDc(self->draw_area, "basegame::setup_fonts");
    return 1;
}

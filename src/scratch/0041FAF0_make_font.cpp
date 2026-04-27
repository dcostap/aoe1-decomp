// VA: 0041FAF0 RGE_Base_Game::make_font (203 B)
// PDB source: basegame.cpp
// Packet-grounded: locale strings, parse size/style, delegate to make_font_impl

extern void lang_string(int id, char* buf, int len);
extern int atoi(const char* s);
extern char* strstr(const char* s, const char* sub);
extern void* make_font_impl(void* self, void* p2, char* name, int sz, int wt, int it);
extern void lang_string_multi(int id, char* buf, int sz);
extern void gfx_get_string(int id, char* buf, int len);
extern int get_int_setting(int key);
extern void notify_status(const char* msg);

void* RGE_Base_Game_make_font(void* self, void* param2, long langId, int italic)
{
    char face[256];
    char size_str[10];
    char style[10];
    int size_val;
    int weight;
    void* result;
    
    lang_string(101, face, 256);
    if (face[0] == 0)
        return 0;
    
    lang_string_multi(102, size_str, 10);
    size_val = atoi(size_str);
    
    lang_string_multi(103, style, 10);
    if (strstr(style, "B") != 0)
        weight = 700;
    else
        weight = 400;
    
    gfx_get_string(104, face, 256);
    size_val = get_int_setting(weight);
    
    result = make_font_impl(self, param2, face, size_val, weight, italic);
    if (result == 0)
        notify_status("font failed");
    return result;
}

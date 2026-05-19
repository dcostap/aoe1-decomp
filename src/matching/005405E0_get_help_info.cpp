// RGE_Main_View::get_help_info
// VA: 005405E0
// vw_main.cpp:1926-1940
// 152 bytes
//
// Attempt 6: Use pickInfo.object (+0x0C) instead of pickInfo.tile (+0x10).
// Fixes stack slot offset from [esp+1Ch] to [esp+18h].

#include <string.h>

class RGE_Pick_Info {
public:
    float x;       // +0x00
    float y;       // +0x04
    short scr_x;   // +0x08
    short scr_y;   // +0x0A
    void* object;  // +0x0C
    void* tile;    // +0x10
};

class RGE_Master_Static_Object {
public:
    int get_help_message(void);
    int get_help_page(void);
};

class TPanel {
public:
    unsigned char get_help_info(char** str_out, long* page_out, long param_3, long param_4);
    char* get_string(int id);
};

class RGE_Main_View : public TPanel {
public:
    unsigned char pick1(int key, int key_mod, long x, long y, RGE_Pick_Info* info, void* exclude, int flag);
    unsigned char get_help_info(char** str_out, long* page_out, long param_3, long param_4);
};

unsigned char RGE_Main_View::get_help_info(char** str_out, long* page_out, long param_3, long param_4) {
    RGE_Pick_Info pickInfo;
    unsigned char result = this->pick1(0x29, 2, param_3, param_4, &pickInfo, 0, 1);

    if (result == 0x34) {
        // Use object field (+0x0C) not tile (+0x10) to match original stack offset
        int msgId = ((RGE_Master_Static_Object*)(*(void**)((char*)pickInfo.object + 8)))->get_help_message();
        char* msg = this->get_string(msgId);

        strcpy(*str_out, msg);

        int pageId = ((RGE_Master_Static_Object*)(*(void**)((char*)pickInfo.object + 8)))->get_help_page();
        *page_out = pageId;

        return 1;
    }

    return ((TPanel*)this)->get_help_info(str_out, page_out, param_3, param_4);
}

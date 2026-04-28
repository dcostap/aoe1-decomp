// RGE_Main_View::get_help_info
// VA: 005405E0
// vw_main.cpp:1926-1940
// 152 bytes, not matched (parked)
// Virtual protected method: calls pick1, on '4' result does string copy
// (inline repne scasb + rep movsd/movsb) and get_help_page, else
// delegates to TPanel parent.
//
// Attempt log (5 variants):
// v0: RGE_Pick_Info struct (20B), strlen+memcpy → 160B, reg alloc diff, parent call wrong
// v1: same + invert if/else to match branch direction → still 160B
// v2: ((TPanel*)this)->get_help_info for parent call → 156B, 8 diff spans
// v3: *(int*) cast instead of obj** → minimal change
// v4: strcpy instead of strlen+memcpy → generates call, not inline
//
// Remaining diff: register allocation (ECX vs EBX for temp obj pointer,
// EAX/ECX vs EDX/EAX for parent call params). TU-context boundary issue.
// String copy generates inline rep instructions but with different
// register choices (ESI, EDI, EBP usage varies).

#include <string.h>
#include "../../include/game_globals.h"

class RGE_Pick_Info {
public:
    float x;
    float y;
    short scr_x;
    short scr_y;
    void* object;
    void* tile;
};

class RGE_Master_Static_Object {
public:
    int get_help_message(void);
    int get_help_page(void);
};

class TPanel {
public:
    unsigned char get_help_info(char** str_out, long* page_out, long param_3, long param_4);
};

class RGE_Main_View : public TPanel {
public:
    unsigned char pick1(unsigned char param_1, unsigned char param_2, long x, long y, RGE_Pick_Info* info, void* exclude, int flag);
    unsigned char get_help_info(char** str_out, long* page_out, long param_3, long param_4);
    char* get_string(int id);
};

unsigned char RGE_Main_View::get_help_info(char** str_out, long* page_out, long param_3, long param_4) {
    RGE_Pick_Info pickInfo;
    unsigned char result = pick1(0x29, 2, param_3, param_4, &pickInfo, 0, 1);

    if (result == 0x34) {
        RGE_Master_Static_Object* obj = *(RGE_Master_Static_Object**)((char*)pickInfo.tile + 8);
        int msgId = obj->get_help_message();
        char* msg = get_string(msgId);

        strcpy(*str_out, msg);

        int pageId = obj->get_help_page();
        *page_out = pageId;

        return 1;
    }

    return ((TPanel*)this)->get_help_info(str_out, page_out, param_3, param_4);
}

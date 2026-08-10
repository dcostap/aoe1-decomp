// VA: 004AB300 TRIBE_Screen_Sed::set_unit_player
// Attempt log:
// baseline: typed player/view/list reconstruction; default VC5 was 102 bytes
// short with all 20 ordered calls present.
// probe: float/short saved view/map locals corrected the call ABI and reloads.
// probe: real strcpy plus string.h reproduced the oracle's REP scan/copy blocks;
// C++ comparator/global declarations preserve the period linkage surface.
// probe: countdown/byte-offset master-object scans recovered the original loop
// topology and raised shape similarity to 83%; a narrow output index improved it.
// blocker: rebuilt remains 839 bytes (frame 0x10 vs original 0x0C), with broad
// stack-home/register and later list-copy drift despite matching 20 calls and
// the binary-proven REP-copy family; /Od was diagnostic-only and broad.
// FLAGS: default config/flags/default.rsp (/nologo /c /O2 /Oy).

#include <string.h>

extern "C" void* calloc(unsigned int, unsigned int);
extern "C" void free(void*);
extern "C" void qsort(void*, unsigned int, unsigned int, int (__cdecl*)(const void*, const void*));
int __cdecl TRIBE_Screen_Sed_unit_list_compare(const void*, const void*);

struct RGE_Master_Static_Object { char gap0[8]; char* name; short string_id; char gap_e[0x40]; char disabled; };
struct RGE_Player { char gap0[0x22]; short master_object_num; RGE_Master_Static_Object** master_objects; char gap28[0xec]; float view_x; float view_y; short map_x; short map_y; };
struct List_Info { char text[100]; short id; };

class RGE_Base_Game {
public:
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c(); virtual void v10();
    virtual void set_player(short p); // +14
    virtual void v18(); virtual void v1c();
    virtual void get_string(short id, char* out, int len); // +20
    RGE_Player* get_player();
};
extern RGE_Base_Game* rge_base_game;
class RGE_Player_M { public: void set_map_loc(short x, short y); void set_view_loc(float x, float y); };
class RGE_View { public: void set_player(RGE_Player*); };
class RGE_Diamond_Map { public: void set_player(RGE_Player*); };
class TDropDownPanel { public: void setCurrentLineNumber(int); };
class TTextPanel { public: void empty_list(); };
#define VPAD1(n) virtual void vpad##n();
#define VPAD2(n) VPAD1(n) VPAD1(n##_1)
#define VPAD4(n) VPAD2(n) VPAD2(n##_2)
#define VPAD8(n) VPAD4(n) VPAD4(n##_4)
#define VPAD16(n) VPAD8(n) VPAD8(n##_8)
#define VPAD32(n) VPAD16(n) VPAD16(n##_16)
class TListPanel { public: VPAD32(0) VPAD16(32) VPAD4(48) VPAD2(52) VPAD1(54) VPAD1(55) virtual void set_data(char** data, short count); void scroll_cur_line(unsigned char, short, int); void empty_list(); };

class TRIBE_Screen_Sed {
public:
    char gap0[0x4b8];
    short player_num;
    char gap4ba[0x4c8-0x4ba];
    RGE_View* main_view;
    RGE_Diamond_Map* map_view;
    char gap4d0[0x618-0x4d0];
    TDropDownPanel* unit_player_list;
    char gap61c[0x63c-0x61c];
    TListPanel* unit_list;
    char gap640[4];
    List_Info* unit_list_info;
    char gap648[0x664-0x648];
    short unit_list_size;
    void set_string(char* dst, int id, int len);
    void set_unit_player(short p);
};

void TRIBE_Screen_Sed::set_unit_player(short p)
{
    int is_error;
    float save_view_x;
    float save_view_y;
    short save_map_x;
    short save_map_y;

    RGE_Player* oldp = ((RGE_Base_Game*)rge_base_game)->get_player();
    save_view_x = oldp->view_x;
    save_view_y = oldp->view_y;
    save_map_x = oldp->map_x;
    save_map_y = oldp->map_y;
    ((RGE_Base_Game*)rge_base_game)->set_player(p);
    this->player_num = p;

    RGE_Player* player = ((RGE_Base_Game*)rge_base_game)->get_player();
    ((RGE_Player_M*)player)->set_view_loc(save_view_x, save_view_y);
    ((RGE_Player_M*)player)->set_map_loc(save_map_x, save_map_y);
    this->main_view->set_player(player);
    this->map_view->set_player(player);
    this->unit_player_list->setCurrentLineNumber((int)p);
    this->unit_list->empty_list();
    if (this->unit_list_info != 0) {
        free(this->unit_list_info);
        this->unit_list_info = 0;
    }
    if (player == 0) return;

    this->unit_list_size = 1;
    short n = player->master_object_num;
    if (n > 0) {
        int object_offset = 0;
        int count = n;
        do {
            RGE_Master_Static_Object* m = *(RGE_Master_Static_Object**)((char*)player->master_objects + object_offset);
            if (m != 0 && m->disabled == 0) this->unit_list_size++;
            object_offset += 4;
            count--;
        } while (count != 0);
    }
    if (this->unit_list_size == 0) return;
    this->unit_list_info = (List_Info*)calloc((int)this->unit_list_size, 0x66);
    if (this->unit_list_info == 0) return;
    this->unit_list_info[0].id = -1;
    this->set_string(this->unit_list_info[0].text, 0x2775, 0x14);

    short out = 1;
    short i = 0;
    int object_offset = 0;
    while (i < n) {
        RGE_Master_Static_Object* m = *(RGE_Master_Static_Object**)((char*)player->master_objects + object_offset);
        if (m != 0 && m->disabled == 0) {
            List_Info* info = &this->unit_list_info[out];
            info->id = (short)i;
            if (m->string_id > 0) {
                ((RGE_Base_Game*)rge_base_game)->get_string(m->string_id, info->text, 100);
            } else {
                strcpy(info->text, m->name);
        }
        out++;
        i++;
        object_offset += 4;
    }
    }

    qsort(this->unit_list_info, (int)this->unit_list_size, 0x66, TRIBE_Screen_Sed_unit_list_compare);
    char** strings = (char**)calloc((int)this->unit_list_size, 4);
    if (strings == 0) return;
    is_error = 0;
    int cur = 0;
    int selected = 0;
    for (i = 0; i < this->unit_list_size; i++) {
        strings[i] = (char*)calloc(100, 1);
        if (strings[i] == 0) { is_error = 1; break; }
        strcpy(strings[i], this->unit_list_info[i].text);
        if (this->unit_list_info[i].id == *(short*)((char*)rge_base_game + 0x3fc)) selected = i;
        cur++;
    }
    if (!is_error) {
        this->unit_list->set_data(strings, this->unit_list_size);
        this->unit_list->scroll_cur_line(1, (short)selected, 1);
    }
    for (i = 0; i < this->unit_list_size; i++) {
        if (strings[i] != 0) free(strings[i]);
    }
    free(strings);
}

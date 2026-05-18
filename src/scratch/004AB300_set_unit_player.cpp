// 004AB300 TRIBE_Screen_Sed::set_unit_player
// Attempt log:
// 1: natural implementation from packet/decompiler.
// 2: fixed TListPanel vtable padding and empty_list surface after initial compile errors.
// 3: default /O2 build is too small: .text 784 bytes vs original 879, so no normal comparison possible.
// 4: probed /Od as diagnostic only; it gives comparable 879 bytes but EBP-frame debug-basin code with 86.92% positional diff, not viable; removed flag.
// 5: Current source represents broad behavior/calls: save/restore player view/map, switch base-game player, update views/dropdown/list, count enabled master objects, calloc list info, set <None>, copy names or lookup string, qsort, build string array, set list data/scroll selected row, free temps.
// 6: Main blocker is source shape: natural loops/helpers collapse far below original /O2 size; original has explicit stack-slot reuse and rep string-copy blocks that need a much more literal CFG.
// GIVEUP: left in scratch; no accepted_drift proposal because default build is size-short and /Od diagnostic drift is broad.

extern void* rge_base_game;
extern "C" void* calloc(unsigned int, unsigned int);
extern "C" void free(void*);
extern "C" void qsort(void*, unsigned int, unsigned int, int (__cdecl*)(const void*, const void*));
extern "C" int __cdecl TRIBE_Screen_Sed_unit_list_compare(const void*, const void*);

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
    int save_view_y;
    int save_map_x;
    int save_map_y;

    RGE_Player* oldp = ((RGE_Base_Game*)rge_base_game)->get_player();
    save_view_x = oldp->view_x;
    save_view_y = *(int*)&oldp->view_y;
    save_map_x = oldp->map_x;
    save_map_y = oldp->map_y;
    ((RGE_Base_Game*)rge_base_game)->set_player(p);
    this->player_num = p;

    RGE_Player* player = ((RGE_Base_Game*)rge_base_game)->get_player();
    ((RGE_Player_M*)player)->set_view_loc(save_view_x, *(float*)&save_view_y);
    ((RGE_Player_M*)player)->set_map_loc((short)save_map_x, (short)save_map_y);
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
    int i;
    for (i = 0; i < n; i++) {
        RGE_Master_Static_Object* m = player->master_objects[i];
        if (m != 0 && m->disabled == 0) this->unit_list_size++;
    }
    if (this->unit_list_size == 0) return;
    this->unit_list_info = (List_Info*)calloc((int)this->unit_list_size, 0x66);
    if (this->unit_list_info == 0) return;
    this->unit_list_info[0].id = -1;
    this->set_string(this->unit_list_info[0].text, 0x2775, 0x14);

    int out = 1;
    for (i = 0; i < n; i++) {
        RGE_Master_Static_Object* m = player->master_objects[i];
        if (m != 0 && m->disabled == 0) {
            List_Info* info = &this->unit_list_info[out];
            info->id = (short)i;
            if (m->string_id > 0) {
                ((RGE_Base_Game*)rge_base_game)->get_string(m->string_id, info->text, 100);
            } else {
                char* src = m->name;
                char* dst = info->text;
                while ((*dst++ = *src++) != 0) {}
            }
            out++;
        }
    }

    qsort(this->unit_list_info, (int)this->unit_list_size, 0x66, TRIBE_Screen_Sed_unit_list_compare);
    char** strings = (char**)calloc((int)this->unit_list_size, 4);
    if (strings == 0) return;
    is_error = 0;
    int cur = 0;
    int selected = 0;
    for (i = 0; i < this->unit_list_size; i++) {
        char* s = (char*)calloc(100, 1);
        strings[i] = s;
        if (s == 0) { is_error = 1; break; }
        char* src = this->unit_list_info[i].text;
        char* dst = s;
        while ((*dst++ = *src++) != 0) {}
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

// try 10 extern global pointer instead of absolute macro
class RGE_Base_Game { public: char gap[0x3FC]; short master_obj_id; };
extern RGE_Base_Game* rge_base_game;
struct ListInfo { char text[100]; short id; };
class TListPanel { public: void scroll_cur_line(unsigned char mode, short line, int update_scrollbar); };
class TRIBE_Screen_Sed { public: char gap_000[0x63C]; TListPanel* unit_list; char gap_640[4]; ListInfo* unit_list_info; void set_unit(short unit); };
void TRIBE_Screen_Sed::set_unit(short unit) {
    if (unit == -1) {
        rge_base_game->master_obj_id = unit;
        unit_list->scroll_cur_line(1, unit, 1);
        return;
    }
    rge_base_game->master_obj_id = unit_list_info[unit].id;
    unit_list->scroll_cur_line(1, unit, 1);
}

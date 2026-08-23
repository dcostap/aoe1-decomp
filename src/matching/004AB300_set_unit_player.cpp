// VA: 004AB300 TRIBE_Screen_Sed::set_unit_player
// Exact-finish log:
// - Fresh exact checkpoint: 879 bytes, 0xC frame, 20 ordered calls, 0.0000% difference.
// - PDB ownership is TRIBE_Screen_Sed::set_unit_player in scr_sed.cpp.
// - The first count scan uses an int byte offset over the typed master_objects array.
// - It rereads player->master_objects on each iteration and advances by four bytes.
// - This source emits the original xor ecx,ecx then movsx edx,di order at +0xE8.
// - The second scan keeps typed array indexing. Its exact walkback stayed exact.
// - The reviewed master-object fields through button_pict place disabled at +0x4E.
// - Reverting those fields caused mismatches at the two disabled-byte anchors.
// - Replacing the first scan with typed indexing caused the five-byte zero/count mismatch.
// - Short locals, guarded do/while control flow, long get_string, and direct records remain.
// - All selected-unit traversal, player updates, UI calls, rereads, cleanup, and fault paths remain.
// - The source uses natural C++. It has no inline assembly, volatile, or raw vtable.
// - It does not cache member reads that the executable rereads.
// - The default period flags remain /nologo /c /O2 /Oy.
// - The canonical TScreenPanel, panel, player, master-object, and base-game surfaces remain.
// - Exact same-TU donors at 004AB2D0 and 004AB670 support the source order and ownership.
// - The executable proves the four-byte pointer stride and the repeated member rereads.
// FLAGS: default config/flags/default.rsp (/nologo /c /O2 /Oy).

#include "../../include/scr_sed_context.h"

void TRIBE_Screen_Sed::set_unit_player(short p)
{
    int is_error;
    float save_view_x;
    float save_view_y;
    short save_map_x;
    short save_map_y;

    RGE_Player* oldp = rge_base_game->get_player();
    save_view_x = oldp->view_x;
    save_view_y = oldp->view_y;
    save_map_x = oldp->map_x;
    save_map_y = oldp->map_y;
    rge_base_game->set_player(p);
    this->player_num = p;

    RGE_Player* player = rge_base_game->get_player();
    player->set_view_loc(save_view_x, save_view_y);
    player->set_map_loc(save_map_x, save_map_y);
    this->main_view->set_player(player);
    this->map_view->set_player(player);
    this->unit_player_list->setCurrentLineNumber((int)p);
    this->unit_list->empty_list();
    if (this->unit_list_info != 0) {
        free(this->unit_list_info);
        this->unit_list_info = 0;
    }
    if (player != 0) {
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

        short out = 1; // BINARY NOTE: the original loads this index as a word.
        short i = 0;
        // BINARY NOTE: the offset zero store follows the positive-count test.
        if (n > 0) {
            int master_index = 0;
            do {
                RGE_Master_Static_Object* m = player->master_objects[master_index];
                if (m != 0 && m->disabled == 0) {
                    this->unit_list_info[out].id = (short)i;
                    m = player->master_objects[master_index];
                    if (m->string_id > 0) {
                        rge_base_game->get_string(m->string_id, this->unit_list_info[out].text, 100);
                    } else {
                        strcpy(this->unit_list_info[out].text, m->name);
                    }
                    out++;
                }
                i++;
                master_index++;
            } while (i < n);
        }

        qsort(this->unit_list_info, (int)this->unit_list_size, 0x66, TRIBE_Screen_Sed_unit_list_compare);
        char** strings = (char**)calloc((int)this->unit_list_size, 4);
        if (strings == 0) return;
        is_error = 0;
        short selected = 0; // BINARY NOTE: the selected row uses a short home.
        for (i = 0; i < this->unit_list_size; i++) {
            char* s = (char*)calloc(100, 1);
            strings[i] = s;
            if (s == 0) { is_error = 1; break; }
            strcpy(s, this->unit_list_info[i].text);
            if (this->unit_list_info[i].id == rge_base_game->master_obj_id) selected = i;
        }
        if (!is_error) {
            this->unit_list->set_text(strings, this->unit_list_size);
            this->unit_list->scroll_cur_line(1, (short)selected, 1);
        }
        for (i = 0; i < this->unit_list_size; i++) {
            if (strings[i] != 0) free(strings[i]);
        }
        free(strings);
    }
}

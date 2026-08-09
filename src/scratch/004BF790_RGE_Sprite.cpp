// VA: 004BF790 RGE_Sprite::RGE_Sprite (656B)
// PDB source: sprite.cpp, lines 78-135
// Deserialization constructor; same-TU default VC5 context.
// Attempt log:
// - Replaced the field-only scaffold with the natural typed sprite
//   deserialization, draw-list allocation, and sound-facet reconstruction.
//   The first checker baseline was exact size/frame/call count, with 332
//   strict differing bytes and a register/liveness mismatch at the prologue.
// - Positive main-sound ID, self/file aliases, and count-guard spelling
//   variants did not change the emitted basin.  Final source retains the
//   ordinary typed deserializer and guarded three-entry facet loop; the
//   remaining blocker is the constructor's ESI/EDI allocation context and
//   downstream loop register topology.

extern "C" void __cdecl rge_read(int handle, void* buffer, int count);
extern "C" void* __cdecl calloc(unsigned int count, unsigned int size);

class RGE_Color_Table;
class RGE_Sprite;

class RGE_Sound {
public:
    char gap_00[0x0C];
    short id;
};

class RGE_Picture_List {
public:
    short picture_num;
    char gap_02[2];
    RGE_Sprite* sprite;
    short offset_x;
    short offset_y;
    short facet;
};

class RGE_Sound_List {
public:
    RGE_Sound* sound[3];
    short frame[3];
    char gap_12[2];
};

class RGE_Sprite {
public:
    char pict_name[13];
    char gap_0D[3];
    long resource_id;
    unsigned char loaded;
    char gap_15[3];
    RGE_Color_Table** color_tables;
    void* shape;
    long last_time;
    long delta_time;
    unsigned char color_flag;
    unsigned char draw_level;
    short color_table;
    unsigned char transparent_picking_flag;
    char gap_2D[1];
    short box_x1;
    short box_y1;
    short box_x2;
    short box_y2;
    short draw_list_num;
    RGE_Picture_List* draw_list;
    RGE_Sound* main_sound;
    unsigned char micro_man_sound;
    char gap_41[3];
    RGE_Sound_List* sound_list;
    char name[21];
    char gap_5D[1];
    short frame_num;
    short facet_num;
    char gap_62[2];
    float base_speed;
    float duration;
    float pause_between_loops;
    unsigned char flag;
    char gap_71[1];
    short id;
    unsigned char mirror_flag;
    char gap_75[3];

    RGE_Sprite(int handle, RGE_Sound** sounds,
               RGE_Color_Table** color_tables);
};

RGE_Sprite::RGE_Sprite(int handle, RGE_Sound** sounds,
                       RGE_Color_Table** color_tables)
{
    this->color_tables = color_tables;
    this->last_time = 0;
    this->delta_time = 0;

    rge_read(handle, this->name, 0x15);
    rge_read(handle, this, 0x0D);
    rge_read(handle, &this->resource_id, 4);
    rge_read(handle, &this->loaded, 1);
    rge_read(handle, &this->color_flag, 1);
    rge_read(handle, &this->draw_level, 1);
    rge_read(handle, &this->color_table, 2);
    rge_read(handle, &this->transparent_picking_flag, 1);
    rge_read(handle, &this->box_x1, 2);
    rge_read(handle, &this->box_y1, 2);
    rge_read(handle, &this->box_x2, 2);
    rge_read(handle, &this->box_y2, 2);
    rge_read(handle, &this->draw_list_num, 2);

    short main_sound_id;
    rge_read(handle, &main_sound_id, 2);
    rge_read(handle, &this->micro_man_sound, 1);
    rge_read(handle, &this->frame_num, 2);
    rge_read(handle, &this->facet_num, 2);
    rge_read(handle, &this->base_speed, 4);
    rge_read(handle, &this->duration, 4);
    rge_read(handle, &this->pause_between_loops, 4);
    rge_read(handle, &this->flag, 1);
    rge_read(handle, &this->id, 2);
    rge_read(handle, &this->mirror_flag, 1);

    if (main_sound_id >= 0) {
        this->main_sound = sounds[main_sound_id];
    } else {
        this->main_sound = 0;
    }

    if (this->draw_list_num < 1) {
        this->draw_list = 0;
    } else {
        this->draw_list = (RGE_Picture_List*)calloc(
            (unsigned int)this->draw_list_num, 0x10);
        rge_read(handle, this->draw_list,
                 ((int)this->draw_list_num) << 4);
    }

    if (this->micro_man_sound == 0) {
        this->sound_list = 0;
    } else {
        this->sound_list = (RGE_Sound_List*)calloc(
            (unsigned int)this->facet_num, 0x14);

        int i = 0;
        if (this->facet_num > 0) {
            do {
                RGE_Sound_List* facet = &this->sound_list[i];
                for (int j = 0; j < 3; ++j) {
                    rge_read(handle, &facet->frame[j], 2);
                    short sound_id;
                    rge_read(handle, &sound_id, 2);
                    if (sound_id < 0) {
                        facet->sound[j] = 0;
                    } else {
                        facet->sound[j] = sounds[sound_id];
                    }
                }
                ++i;
            } while (i < this->facet_num);
        }
    }
}

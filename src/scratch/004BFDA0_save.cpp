// VA: 004BFDA0 RGE_Sprite::save (561B)
// PDB source: sprite.cpp, lines 309-358
// Attempt log:
// - Replaced the field-only scaffold with the natural typed sprite
//   serialization sequence and three-entry sound-facet traversal.  The first
//   checker baseline was exact frame/calls with a 567-byte rebuild versus 561
//   bytes and 151 strict differing bytes.
// - A guarded outer do-while recovered the original single count test and
//   improved the result to 554 bytes / 130 strict differing bytes; a typed
//   pointer-cursor facet experiment broadened drift and was restored.
// - Named file-handle, micro-address, frame-address, and sound-pointer forms
//   were codegen-neutral.  Final source remains typed and period-plausible;
//   residual drift is the outer offset/register topology and first-iteration
//   loop jump, with all 26 calls and the 0x10 frame aligned.
// - Split the micro-sound and positive-facet guards into nested natural ifs;
//   this recovered the original pre-loop count store and improved the strict
//   diff from 130 to 126 bytes.  The remaining first hunk is the outer
//   iteration's typed list-address topology.

extern "C" void __cdecl rge_write(int handle, void* buffer, int count);

class RGE_Sound {
public:
    char gap_00[0x0C];
    short id;
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
    void* color_tables;
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
    void* draw_list;
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

    void save(int handle);
};

void RGE_Sprite::save(int handle)
{
    int info = -1;

    if (this->main_sound != 0) {
        info = this->main_sound->id;
    }

    rge_write(handle, this->name, 0x15);
    rge_write(handle, this, 0x0D);
    rge_write(handle, &this->resource_id, 4);
    rge_write(handle, &this->loaded, 1);
    rge_write(handle, &this->color_flag, 1);
    rge_write(handle, &this->draw_level, 1);
    rge_write(handle, &this->color_table, 2);
    rge_write(handle, &this->transparent_picking_flag, 1);
    rge_write(handle, &this->box_x1, 2);
    rge_write(handle, &this->box_y1, 2);
    rge_write(handle, &this->box_x2, 2);
    rge_write(handle, &this->box_y2, 2);
    rge_write(handle, &this->draw_list_num, 2);
    rge_write(handle, &info, 2);
    rge_write(handle, &this->micro_man_sound, 1);
    rge_write(handle, &this->frame_num, 2);
    rge_write(handle, &this->facet_num, 2);
    rge_write(handle, &this->base_speed, 4);
    rge_write(handle, &this->duration, 4);
    rge_write(handle, &this->pause_between_loops, 4);
    rge_write(handle, &this->flag, 1);
    rge_write(handle, &this->id, 2);
    rge_write(handle, &this->mirror_flag, 1);

    if (this->draw_list != 0) {
        rge_write(handle, this->draw_list,
                  ((int)this->draw_list_num) << 4);
    }

    if (this->micro_man_sound != 0) {
        int i = 0;
        if (this->facet_num > 0) {
            do {
                RGE_Sound_List* facet = &this->sound_list[i];
                for (int j = 0; j < 3; ++j) {
                    short* frame = &facet->frame[j];
                    RGE_Sound* sound = facet->sound[j];
                    int sound_id = -1;
                    if (sound != 0) {
                        sound_id = sound->id;
                    }
                    rge_write(handle, frame, 2);
                    rge_write(handle, &sound_id, 2);
                }
                ++i;
            } while (i < this->facet_num);
        }
    }
}

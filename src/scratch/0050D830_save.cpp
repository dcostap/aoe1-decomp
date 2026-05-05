// VA: 0050D830 RGE_Timeline::save
// Straight source from Timeline.cpp packet; keeps the file handle in EDI and uses
// the incoming param stack slot for the source-player id temporary.
// Current closest drift is a one-instruction width issue for player id loads:
// natural signed-short assignment emits movsx, while original does `mov ax,[+4A]`
// then stores EAX to the temp slot. Unsigned or low-word casts shift the loop.

extern "C" void __cdecl rge_write(int file, void* data, int size);

class RGE_Player {
public:
    char pad_00[0x4A];
    short id;
};

class RGE_Static_Object {
public:
    char pad_00[0x0C];
    RGE_Player* owner;
};

struct RGE_Time_Entry {
    int time;
    char type;
    char pad_05;
    short word_06;
    char byte_08;
    char pad_09[3];
    int field_0C;
    int field_10;
    int field_14;
    short word_18;
    short pad_1A;
    RGE_Static_Object* source;
    short word_20;
    short pad_22;
    RGE_Static_Object* target;
    short word_28;
    char pad_2A[6];
};

class RGE_Timeline {
public:
    void* vtable;
    char pad_04[4];
    RGE_Time_Entry* time_list;
    short list_num;
    short avail_id;
    int old_time;

    void save(int file);
};

void RGE_Timeline::save(int file) {
    int target_player_id;
    RGE_Time_Entry* entry;
    short* count_ptr;
    RGE_Timeline* self;
    int i;
    int offset;
    int save_file;

    save_file = file;
    self = this;
    count_ptr = &this->list_num;
    rge_write(save_file, count_ptr, 2);
    rge_write(save_file, &this->avail_id, 2);
    rge_write(save_file, &this->old_time, 4);

    i = 0;
    if (*count_ptr > 0) {
        offset = 0;
        do {
            entry = (RGE_Time_Entry*)((char*)self->time_list + offset);
            if (entry->source != 0) {
                file = entry->source->owner->id;
            } else {
                file = -1;
            }
            if (entry->target != 0) {
                target_player_id = entry->target->owner->id;
            } else {
                target_player_id = -1;
            }
            rge_write(save_file, entry, 4);
            rge_write(save_file, &entry->type, 1);
            rge_write(save_file, &entry->word_06, 2);
            rge_write(save_file, &entry->byte_08, 1);
            rge_write(save_file, &entry->field_0C, 4);
            rge_write(save_file, &entry->field_10, 4);
            rge_write(save_file, &entry->field_14, 4);
            rge_write(save_file, &entry->word_18, 2);
            rge_write(save_file, &entry->word_20, 2);
            rge_write(save_file, &file, 2);
            rge_write(save_file, &entry->word_28, 2);
            rge_write(save_file, &target_player_id, 2);
            ++i;
            offset += 0x30;
        } while (i < *count_ptr);
    }
}

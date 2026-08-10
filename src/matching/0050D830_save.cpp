// VA: 0050D830 RGE_Timeline::save
// Straight source from Timeline.cpp packet; keeps the file handle in EDI and uses
// the incoming param stack slot for the source-player id temporary.
// Current closest drift is a one-instruction width issue for player id loads:
// natural signed-short assignment emits movsx, while original does `mov ax,[+4A]`
// then stores EAX to the temp slot. Unsigned or low-word casts shift the loop.
// Probe 1 (baseline): natural typed serializer -> 355 B, 4 bytes differ at the
//   two player-id loads; all 15 calls, frame, loop, and serialization order match.
// Probe 2 (abi): unsigned id adds xor/zero-extension and shifts the loop (359 B);
//   rolled back.
// Probe 3 (restore): signed-id clean source restored, unchanged 4-byte basin.
// Probe 4 (abi): separate short source_player_id local emitted unchanged code;
//   removed from living source as diagnostic only. Remaining issue is VC5's
//   signed-extension choice versus the original low-word parameter-home reuse.
// Main-agent audit removed the raw vtable field and byte-offset event cursor,
// restoring canonical polymorphic timeline/player/object ownership.
// Session sa1-0050d830: an inline short player-id accessor was a codegen
// duplicate; restored direct typed id access. Remaining 4 bytes are the two
// signed-short-to-int loads versus the original low-word parameter-home reuse.
// Fresh worker: making the two serialized owner IDs natural short locals (and
// passing those locals directly to rge_write) recovered the oracle's low-word
// loads without aliases or raw stack plumbing. Probe 2 fixed the source ID;
// probe 3 fixed the target ID. Current source is an exact, period-plausible
// serializer reconstruction.

extern "C" void __cdecl rge_write(int file, void* data, int size);

class RGE_Game_World;

class RGE_Player {
public:
    virtual ~RGE_Player();
    char pad_04[0x46];
    short id;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    char pad_04[0x08];
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
    virtual ~RGE_Timeline();
    RGE_Game_World* world;
    RGE_Time_Entry* time_list;
    short list_num;
    short avail_id;
    int old_time;

    void save(int file);
};

void RGE_Timeline::save(int file) {
    short source_player_id;
    short target_player_id;
    RGE_Time_Entry* entry;
    short* count_ptr;
    int i;
    int save_file;

    save_file = file;
    count_ptr = &this->list_num;
    rge_write(save_file, count_ptr, 2);
    rge_write(save_file, &this->avail_id, 2);
    rge_write(save_file, &this->old_time, 4);

    i = 0;
    if (*count_ptr > 0) {
        do {
            entry = &this->time_list[i];
            if (entry->source != 0) {
                source_player_id = entry->source->owner->id;
            } else {
                source_player_id = -1;
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
            rge_write(save_file, &source_player_id, 2);
            rge_write(save_file, &entry->word_28, 2);
            rge_write(save_file, &target_player_id, 2);
            ++i;
        } while (i < *count_ptr);
    }
}

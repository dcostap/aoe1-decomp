// VA: 004C4360 RGE_Static_Object::save(int)
// PDB source: stat_obj.cpp lines 2024-2101
//
// Attempt log:
// - Fresh pass: replace raw byte-offset access with the typed static-object,
//   player, master, sprite, and ManagedArray surfaces proved by stat_obj.cpp
//   donors.  Keep the two legacy array-growth paths and parameter-home value
//   reuse visible in the binary.
// - Typed baseline with one shared sentinel local removed the two address-taken
//   stack slots.  Separate sprite and inside IDs restored the 0x08 frame and
//   reduced the mismatch from 784 bytes to 58 bytes.
// - The sprite ID is a short serialization temporary.  This matches the
//   original word load and reduced the remaining mismatch to 56 bytes.
// - Reordered, split, scoped, and do-while loop locals did not change emitted
//   code.  The remaining 56 bytes are register-color drift: VC5 uses EBX for
//   the loop index and EBP for the growth pointer, while the original swaps
//   those registers.  Calls, widths, loop guards, allocation null paths, and
//   serialized sentinel behavior are aligned.

extern "C" void __cdecl rge_write(int file, void* data, int size);

void* __cdecl operator new(unsigned int size);
void __cdecl operator delete(void* value);

class RGE_Master_Static_Object {
public:
    char gap_00[0x10];
    short id;
};

class RGE_Player {
public:
    char gap_00[0x4A];
    short id;
};

class RGE_Sprite {
public:
    char gap_00[0x72];
    short id;
};

class RGE_Active_Sprite_List {
public:
    void save(int file);
};

class ManagedArray_int {
public:
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;
};

class RGE_Static_Object {
public:
    void* vtable_ptr;
    long id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    RGE_Sprite* sprite;
    RGE_Sprite* old_sprite;
    RGE_Active_Sprite_List* sprite_list;
    void* tile;
    RGE_Static_Object* inside_obj;
    void* objects;
    short screen_x_offset;
    short screen_y_offset;
    short shadow_x_offset;
    short shadow_y_offset;
    float hp;
    unsigned char curr_damage_percent;
    unsigned char facet;
    unsigned char selected;
    unsigned char selected_group;
    float world_x;
    float world_y;
    float world_z;
    float attribute_amount_held;
    unsigned char object_state;
    unsigned char sleep_flag;
    unsigned char dopple_flag;
    unsigned char goto_sleep_flag;
    short attribute_type_held;
    unsigned char type;
    unsigned char worker_num;
    void* player_object_node;
    ManagedArray_int pathingGroupMembers;
    ManagedArray_int groupMembers;
    void* unitAIValue;
    int groupCommanderValue;
    int zoneMapIndex;
    float groupRangeValue;
    unsigned char inObstructionMapValue;
    unsigned char lastInObstructionMapValue;
    unsigned char underAttackValue;
    unsigned char gap_87;

    void save(int file);
};

void RGE_Static_Object::save(int file)
{
    short sprite_id;
    int inside_id;
    int* new_value;
    int saved_file = file;
    int i;
    int j;

    rge_write(saved_file, &this->type, 1);
    rge_write(saved_file, &this->owner->id, 1);
    rge_write(saved_file, &this->master_obj->id, 2);

    if (this->sprite == 0)
        sprite_id = -1;
    else
        sprite_id = this->sprite->id;
    rge_write(saved_file, &sprite_id, 2);

    if (this->inside_obj == 0)
        inside_id = -1;
    else
        inside_id = this->inside_obj->id;
    rge_write(saved_file, &inside_id, 4);

    rge_write(saved_file, &this->hp, 4);
    rge_write(saved_file, &this->object_state, 1);
    rge_write(saved_file, &this->sleep_flag, 1);
    rge_write(saved_file, &this->dopple_flag, 1);
    rge_write(saved_file, &this->goto_sleep_flag, 1);
    rge_write(saved_file, &this->id, 4);
    rge_write(saved_file, &this->facet, 1);
    rge_write(saved_file, &this->world_x, 4);
    rge_write(saved_file, &this->world_y, 4);
    rge_write(saved_file, &this->world_z, 4);
    rge_write(saved_file, &this->screen_x_offset, 2);
    rge_write(saved_file, &this->screen_y_offset, 2);
    rge_write(saved_file, &this->shadow_x_offset, 2);
    rge_write(saved_file, &this->shadow_y_offset, 2);
    rge_write(saved_file, &this->selected_group, 1);
    rge_write(saved_file, &this->attribute_type_held, 2);
    rge_write(saved_file, &this->attribute_amount_held, 4);
    rge_write(saved_file, &this->worker_num, 1);
    rge_write(saved_file, &this->curr_damage_percent, 1);
    rge_write(saved_file, &this->underAttackValue, 1);
    rge_write(saved_file, &this->groupCommanderValue, 4);
    rge_write(saved_file, &this->groupRangeValue, 4);

    file = this->groupMembers.numberValue;
    rge_write(saved_file, &file, 4);
    i = 0;
    if (this->groupMembers.numberValue > 0) do {
        if (i > this->groupMembers.maximumSizeValue - 1) {
            new_value = new int[i + 1];
            if (new_value != 0) {
                for (j = 0; j < this->groupMembers.maximumSizeValue &&
                            j < i + 1; ++j) {
                    new_value[j] = this->groupMembers.value[j];
                }
                delete[] this->groupMembers.value;
                this->groupMembers.value = new_value;
                this->groupMembers.maximumSizeValue = i + 1;
            }
        }

        file = this->groupMembers.value[i];
        rge_write(saved_file, &file, 4);
        ++i;
    } while (i < this->groupMembers.numberValue);

    file = this->pathingGroupMembers.numberValue;
    rge_write(saved_file, &file, 4);
    int k = 0;
    if (this->pathingGroupMembers.numberValue > 0) do {
        if (k > this->pathingGroupMembers.maximumSizeValue - 1) {
            new_value = new int[k + 1];
            if (new_value != 0) {
                for (j = 0; j < this->pathingGroupMembers.maximumSizeValue &&
                            j < k + 1; ++j) {
                    new_value[j] = this->pathingGroupMembers.value[j];
                }
                delete[] this->pathingGroupMembers.value;
                this->pathingGroupMembers.value = new_value;
                this->pathingGroupMembers.maximumSizeValue = k + 1;
            }
        }

        file = this->pathingGroupMembers.value[k];
        rge_write(saved_file, &file, 4);
        ++k;
    } while (k < this->pathingGroupMembers.numberValue);

    this->sprite_list->save(saved_file);
}

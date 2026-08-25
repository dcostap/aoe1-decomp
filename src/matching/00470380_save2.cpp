// VA: 00470380 RGE_Player::save2(int)
// PDB donor: player.cpp, lines 1314-1367
//
// Baseline reconstruction: save the master-object presence table, serialize
// each present master object, then save the visible map and object lists.
//
// Attempt log:
// - Baseline used the canonical RGE_Player fields and typed save calls; all
//   calls aligned, but nested do-loops were optimized past the first guard.
// - Reversed the positive guard and used ordinary while loops. This preserved
//   the binary's redundant loop-entry tests and matched all 261 bytes.

extern "C" void __cdecl color_log(unsigned char, unsigned char, unsigned char);
#ifndef PLAYER_GROUPED_TU
extern "C" void __cdecl rge_write(int file, void* data, int size);
#else
void rge_write(int file, void* data, int size);
#endif

#ifndef PLAYER_GROUPED_TU
class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    virtual void copy_obj(RGE_Master_Static_Object*);
    virtual void modify(float, unsigned char);
    virtual void modify_delta(float, unsigned char);
    virtual void modify_percent(float, unsigned char);
    virtual void save(int file);
};

class RGE_Visible_Map {
public:
    void save(int file);
};

class Visible_Resource_Manager {
public:
    void save(int file);
};

class RGE_Object_List {
public:
    void save(int file);
};

class RGE_Player {
public:
    virtual ~RGE_Player();

    char gap_04[0x1E];
    short master_object_num;
    RGE_Master_Static_Object** master_objects;
    RGE_Object_List* objects;
    RGE_Object_List* sleeping_objects;
    RGE_Object_List* doppleganger_objects;
    char gap_34[0x4];
    RGE_Visible_Map* visible;
    char gap_3C[0xD4];
    Visible_Resource_Manager* VR_List;

    virtual void save2(int file);
};
#endif

void RGE_Player::save2(int file) {
    int save_file;
    short* master_object_count;

    color_log('L', 'L', 4);
    save_file = file;
    master_object_count = &this->master_object_num;
    rge_write(save_file, master_object_count, 2);

    if (0 < *master_object_count) {
        int i = 0;
        while (i < *master_object_count) {
            file = (int)this->master_objects[i];
            if (file != 0) {
                file = 1;
            }
            rge_write(save_file, &file, 4);
            ++i;
        }

        short j = 0;
        while (j < *master_object_count) {
            RGE_Master_Static_Object* object = this->master_objects[j];
            if (object != 0) {
                object->save(save_file);
            }
            ++j;
        }
    }

    color_log('L', '$', 4);
    this->visible->save(save_file);
    this->VR_List->save(save_file);
    color_log('L', 0x16, 4);
    this->objects->save(save_file);
    color_log('L', '2', 4);
    this->sleeping_objects->save(save_file);
    color_log('L', '2', 4);
    this->doppleganger_objects->save(save_file);
    color_log('L', '_', 4);
}

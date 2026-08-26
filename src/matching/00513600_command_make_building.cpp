// VA: 00513600 TRIBE_Player::command_make_building
// PDB: tplayer.cpp lines 1119-1135 (139 bytes, 57 asm lines)
// Retry 2026-05-19 (12 honest tries):
// - Built structural model from packet: type lookup at +0x24, buildability gate on +0x52 or type==0x6d,
//   get_selected_objects_to_command(4,4,-1,-1), vcall +0x2c on objectInfo[0x76], command_build, free.
// - Baseline with local list/list_num/local_4 and typed command_build reached very close: exact size, only 5 byte diffs in stack-slot offsets.
// - Reordered locals and tried using the incoming type parameter slot as the selected-object list output (matching decompiler); this either destroyed EDI/original-type register allocation or broadly changed prologue and call setup.
// - Tried swapped out-param casts (`local_4`/`list`, `list`/`type`) and saved original type local; best remained the 2-byte-diff variant below.
// BEST CURRENT: exact-sized 139B, 1.4388% positional/edit diff. Only remaining mismatch is the two LEA displacements for the get_selected_objects_to_command out-parameter addresses:
//   original: lea edx,[esp+14h]; lea eax,[esp+20h]
//   rebuilt : lea edx,[esp+1Ch]; lea eax,[esp+18h]
// The rest of the function is byte-identical after the call. No accepted_drift proposal: those two LEAs change which stack slots the callee writes, so behavior equivalence is not guaranteed.

extern "C" void __cdecl free(void*);

#ifndef AOE1_TPLAYER_TU_SHARED_CONTEXT
class RGE_Static_Object {};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    virtual void copy_obj(RGE_Master_Static_Object*);
    virtual void modify(float, unsigned char);
    virtual void modify_delta(float, unsigned char);
    virtual void modify_percent(float, unsigned char);
    virtual void save(int);
    virtual void make_new_obj(void*, float, float, float);
    virtual void make_new_master();
    virtual void check_placement(void*, float, float, int*, unsigned char,
                                 unsigned char, unsigned char, unsigned char,
                                 unsigned char, unsigned char);
    virtual void alignment(float*, float*, void*, unsigned char);
    virtual long calc_base_damage_ability(void*);
    virtual void play_command_sound();
};

class ObjectInfo {
public:
    char gap[0x52];
    unsigned char flag52;
};

class TRIBE_Command {
public:
    void command_build(RGE_Static_Object**, short, short, float, float);
};

class RGE_World {
public:
    char gap[0x58];
    TRIBE_Command* commands;
};

class TRIBE_Player {
public:
    char gap00[0x24];
    ObjectInfo** objectInfo;
    char gap28[0x14];
    RGE_World* world;

    unsigned char get_selected_objects_to_command(RGE_Static_Object*** list, short* listNum, int, int, int, int);
    unsigned char command_make_building(short type, float x, float y);
};
#endif

unsigned char TRIBE_Player::command_make_building(short type, float x, float y) {
    short local_4;
    RGE_Static_Object** list;
    short list_num;

    ObjectInfo* info = this->objectInfo[type];
    if (info != 0 && (info->flag52 != 0 || type == 0x6d)) {
        if (get_selected_objects_to_command(&list, (short*)&local_4, 4, 4, -1, -1)) {
            ((RGE_Master_Static_Object*)this->objectInfo[0x76])->play_command_sound();
            this->world->commands->command_build(list, local_4, type, x, y);
            free(list);
            return 1;
        }
    }

    return 0;
}

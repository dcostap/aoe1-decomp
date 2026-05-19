// VA: 00471940 RGE_Player::command_stand_ground
// PDB: player.cpp lines 2459-2490 (138 bytes, 51 asm lines)
// MATCH: `python tools/check_function.py --va 00471940` -> 0.0000%.
// Key fixes 2026-05-19:
// - get_selected_objects_to_command's list-count out parameter must be modeled as int*,
//   not short*, so stack locals place list at [esp+4] and the other out slot at [esp].
// - command_group_ai_order's first two player-id parameters must be int, not short;
//   this forces VC5 to emit `movsx eax, word [esi+4Ah]` before the pushes instead of
//   delaying a 16-bit load until the call setup.

extern "C" void __cdecl free(void*);

class RGE_Static_Object {
public:
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4c();
    virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5c();
    virtual void v60(); virtual void v64(); virtual void v68(); virtual void v6c();
    virtual void v70(); virtual void v74(); virtual void v78(); virtual void v7c();
    virtual void v80(); virtual void v84(); virtual void v88(); virtual void v8c();
    virtual void v90(); virtual void v94(); virtual void v98(); virtual void v9c();
    virtual void va0(); virtual void va4(); virtual void va8(); virtual void vac();
};

class RGE_Command {
public:
    void command_group_ai_order(int, int, RGE_Static_Object**, short, int, int, int, float, float, float, float, unsigned char, unsigned char, unsigned char);
};

class RGE_World {
public:
    char gap[0x58];
    RGE_Command* commands;
};

class RGE_Player {
public:
    char gap00[0x3c];
    RGE_World* world;
    char gap40[0x0a];
    short id;

    unsigned char get_selected_objects_to_command(RGE_Static_Object*** list, int* listNum, int, int, int, int);
    unsigned char command_stand_ground();
};

unsigned char RGE_Player::command_stand_ground() {
    RGE_Static_Object** list;
    int listNum;
    int local_4;

    if (get_selected_objects_to_command(&list, &listNum, -1, -1, -1, -1)) {
        list[0]->vac();
        this->world->commands->command_group_ai_order(this->id, this->id, list, (short)local_4, 0x2d5, -1, -1, -1.0f, -1.0f, -1.0f, 1.0f, 1, 0, 100);
        free(list);
        return 1;
    }

    return 0;
}

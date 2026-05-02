// VA: 00545D90 RGE_Game_World::get_next_object_id (62B)
// PDB source: World.cpp lines 3636-3651
// tried direct decompiler form, explicit iVar1/iVar2 locals, and direct-member scan forms
// best shape keeps the scenario fast-path and most of the scan structure, but VC5 still prefers `lea esi,[eax-1]` / `cmp eax,esi` or early-return branch reshaping instead of the original `lea edx,[eax-1]` / `cmp edx,eax` with the exact loop entry layout

class RGE_Static_Object;

class RGE_Game_World {
public:
    char gap_00[0x68];
    int next_object_id;
    char gap_6C[0x4];
    int scenario_object_id;
    unsigned char scenario_object_flag;
    char gap_75[0x13];
    RGE_Static_Object** objectsValue;
    char gap_8C[0x4];
    int maxNumberObjectsValue;

    long get_next_object_id();
};

long RGE_Game_World::get_next_object_id() {
    if (scenario_object_flag == 0) {
        if (this->next_object_id <= this->maxNumberObjectsValue - 1) {
            RGE_Static_Object** objs = this->objectsValue;
            do {
                if (objs[this->next_object_id] == 0) {
                    break;
                }
                this->next_object_id = this->next_object_id + 1;
            } while (this->next_object_id <= this->maxNumberObjectsValue - 1);
        }
        int object_id = this->next_object_id;
        this->next_object_id = object_id + 1;
        return object_id;
    }
    return this->scenario_object_id;
}

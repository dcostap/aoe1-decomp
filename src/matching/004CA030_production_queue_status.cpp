// VA: 004CA030 TRIBE_Building_Object::production_queue_status (115 B)
// PDB source: t_b_obj.cpp

#ifndef T_B_OBJ_CONTEXT_H
struct RGE_Action_List {
    char base[4];
    void* get_action();
};

struct TRIBE_Action_Make_Obj {
    char pad[4];
    short action_type; // +4
    void get_info(short* out1, short* out2, void* zero1, int zero2);
};

struct TRIBE_Action_Make_Tech {
    char pad[4];
    short action_type; // +4
    void get_info(short* out1, short* out2, void* zero1, int zero2);
};

struct TRIBE_Building_Object {
    char pad0[0x1C8];
    short* production_queue;        // +0x1C8 (4 bytes)
    char pad_1cc[2];                // +0x1CC (padding)
    short production_queue_count;   // +0x1CE
    char pad1[4];                   // +0x1D0
    void* production_queue_actions; // +0x1D4
    char production_queue_change_flag; // +0x1D8
    
    int production_queue_status(short* type_out, short* count_out);
};
#endif

int TRIBE_Building_Object::production_queue_status(short* type_out, short* count_out)
{
    *type_out = -1;
    *count_out = 0;
    
    TRIBE_Action_Make_Obj* act = (TRIBE_Action_Make_Obj*)((RGE_Action_List*)production_queue_actions)->get_action();
    if (act && act->action_type == 0x66) {
        act->get_info(type_out, count_out, 0, 0);
        return 1;
    }
    
    if (production_queue_count > 0) {
        *type_out = *production_queue;
        *count_out = 0;
        return 1;
    }
    
    return 0;
}

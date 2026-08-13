// VA: 00540010 pick_best_target (823B)
// vw_main.cpp
// Attempt log:
// initial natural reconstruction from packet; compiles but .text is 800B vs original 823B.
// tried source model with typed RGE_Main_View/RGE_View fields at +FC/+100 and vtable padding for +E4 score call.
// tried direct typed action-system virtuals for [vtable+4]/[vtable+8] calls instead of raw helper wrappers.
// tried explicit goto next_target to mirror original single shared target-advance block.
// tried do/while outer and inner loops to mirror original bottom tests.
// tried stack local order selected_count/selected_objects/j/target_count/master/cur/arrays to force 0x224 frame.
// tried explicit PickedObjInfo[12-byte] walking so info[-1].picked and info->action match +(-4)/+0 access.
// tried list fallback as a typed ObjectList at player +0x22/+0x24 to match fallback scan.
// tried final best scan with running Picked_Objects pointer and direct out-param guarded store.
// probe: corrected the view geometry to world (+FC)/player (+100), matching exact vw_main donors;
// probe: int pick_score is behavior-backed by the original direct EAX add, but is 5B farther than char.
// probe: typed player object_count/object_list is canonical but changed the frame to 0x220; kept the named fields.
// probe: inventory ABI confirms RGE_Pick_Obj_Info is 12 bytes with object_id at +0 and confidence at +4;
// kept the natural typed record walk, which raises shape similarity to 74.14% without changing calls or size.
// probe: replaced scalar zero loops with natural memset(..., master_obj * sizeof(int)); this recovers the original
// byte-count-to-stosd initialization family and improves the strict diff from 678 to 621 bytes.
// probe: function-scope record cursor, explicit view alias, and j-before-target_count declarations were codegen duplicates.
// probe: inner for-loop spelling was worse (837B/681-byte diff); restored the natural do/while target scan.
// final gap: calls, filters, score accumulation, attacking output, and best-object return match the binary;
// VC5 local lifetime and block layout remain non-exact. Left in scratch.

extern "C" void __cdecl free(void*);
extern "C" void* __cdecl memset(void*, int, unsigned int);

struct RGE_Static_Object;
struct RGE_Master_Action_Object;
struct RGE_World;

struct RGE_Pick_Obj_Info {
    int object_id;
    short confidence;
    short draw_level;
    short draw_x;
    short draw_y;
};

extern RGE_Pick_Obj_Info Picked_Objects[];

class RGE_Player {
public:
    char gap_000[0x22];
    short object_count; // +22
    RGE_Static_Object** object_list; // +24
    char gap_028[0xB0];
    int get_selected_objects_to_command(RGE_Static_Object*** out, short* count, int a, int b, int c, int d);
};

struct RGE_World {
    char gap_000[0x88];
    RGE_Static_Object** objects;
};

class RGE_View {
public:
    virtual void pad_vtable();
    char gap_004[0xF8];
    RGE_World* world; // +FC
    RGE_Player* player; // +100
    RGE_Master_Action_Object* pick_objects(long x, long y, int a, int b, int c, int d, int e);
};

class RGE_Main_View : public RGE_View {
public:
    virtual char pad00(); virtual char pad01(); virtual char pad02(); virtual char pad03();
    virtual char pad04(); virtual char pad05(); virtual char pad06(); virtual char pad07();
    virtual char pad08(); virtual char pad09(); virtual char pad10(); virtual char pad11();
    virtual char pad12(); virtual char pad13(); virtual char pad14(); virtual char pad15();
    virtual char pad16(); virtual char pad17(); virtual char pad18(); virtual char pad19();
    virtual char pad20(); virtual char pad21(); virtual char pad22(); virtual char pad23();
    virtual char pad24(); virtual char pad25(); virtual char pad26(); virtual char pad27();
    virtual char pad28(); virtual char pad29(); virtual char pad30(); virtual char pad31();
    virtual char pad32(); virtual char pad33(); virtual char pad34(); virtual char pad35();
    virtual char pad36(); virtual char pad37(); virtual char pad38(); virtual char pad39();
    virtual char pad40(); virtual char pad41(); virtual char pad42(); virtual char pad43();
    virtual char pad44(); virtual char pad45(); virtual char pad46(); virtual char pad47();
    virtual char pad48(); virtual char pad49(); virtual char pad50(); virtual char pad51();
    virtual char pad52(); virtual char pad53(); virtual char pad54(); virtual char pad55();
    virtual int pick_score(RGE_Static_Object* obj, int action);
    RGE_Static_Object* pick_best_target(long x, long y, int* attacking_out, short action_filter);
};

class RGE_Action_System {
public:
    virtual void* v0();
    virtual void* can_do(RGE_Static_Object* actor, RGE_Static_Object* target, int a, int b, int c);
    virtual int accept(void* action);
};

struct RGE_Static_Object {
    void* vt;
    unsigned char kind; // +4
    char gap_005[1];
    short action_id; // +6 for returned action object
    char gap_008[0x0C];
    short object_type; // +14
    char gap_016[0x32];
    unsigned char owner_type; // +48
    char gap_049[0x8F];
    RGE_Action_System* actions; // +D8
    char gap_0DC[0x10];
    unsigned char flag_ec; // +EC
};

RGE_Static_Object* RGE_Main_View::pick_best_target(long x, long y, int* attacking_out, short action_filter) {
    RGE_Static_Object** selected_objects;
    short selected_count;
    int target_count;
    int j;
    RGE_Master_Action_Object* master_obj;
    RGE_Static_Object* cur_target;
    int valid_target_count[64];
    int attacking[64];

    if (attacking_out != 0) {
        *attacking_out = 0;
    }

    master_obj = this->pick_objects(x, y, 10, 20, 15, 4, 1);
    if (master_obj == 0) {
        return 0;
    }

    if (!this->player->get_selected_objects_to_command(&selected_objects, &selected_count, -1, -1, -1, -1)) {
        return 0;
    }

    if ((int)master_obj > 0) {
        memset(attacking, 0, (int)master_obj * sizeof(int));
        memset(valid_target_count, 0, (int)master_obj * sizeof(int));
    }

    j = 0;
    if (selected_count > 0) {
        do {
            target_count = 0;
            cur_target = selected_objects[j];
            if ((int)master_obj > 0) {
                RGE_Pick_Obj_Info* info = Picked_Objects;
                do {
                    int picked = info->object_id;
                    if (picked >= 0) {
                        RGE_Static_Object* obj = this->world->objects[picked];
                        if (obj != 0 && obj->owner_type < 7) {
                            void* action = cur_target->actions->can_do(selected_objects[j], obj, 0, 0, 0);
                            if (action != 0) {
                                if (action_filter != -1 && *((short*)((char*)action + 6)) != action_filter) {
                                    action = 0;
                                }
                                if (action != 0) {
                                    valid_target_count[target_count] += this->pick_score(obj, info->confidence);
                                    if (cur_target->actions->accept(action)) {
                                        attacking[target_count] = 1;
                                    }
                                    goto next_target;
                                }
                            }
                            if (cur_target->flag_ec != 0) {
                                int k = 0;
                                if (this->player->object_count > 0) {
                                    do {
                                        RGE_Static_Object* obj2 = this->player->object_list[k];
                                        if (obj2 != 0 && obj2->object_type == cur_target->object_type &&
                                            obj2->kind == cur_target->kind && obj2->flag_ec == cur_target->flag_ec) {
                                            void* action2 = obj2->actions->can_do(selected_objects[j], obj, 0, 0, 0);
                                            if (action2 != 0) {
                                                if (action_filter != -1 && *((short*)((char*)action2 + 6)) != action_filter) {
                                                    action2 = 0;
                                                }
                                                if (action2 != 0) {
                                                    valid_target_count[target_count] += this->pick_score(obj, info->confidence);
                                                    if (obj2->actions->accept(action2)) {
                                                        attacking[target_count] = 1;
                                                    }
                                                    goto next_target;
                                                }
                                            }
                                        }
                                        k++;
                                } while (k < this->player->object_count);
                                }
                            }
                        }
                    }
next_target:
                    target_count++;
                    info++;
                } while (target_count < (int)master_obj);
            }
            j++;
        } while (j < selected_count);
    }

    free(selected_objects);

    int best = 0;
    RGE_Static_Object* best_obj = 0;
    int i = 0;
    if ((int)master_obj > 0) {
        RGE_Pick_Obj_Info* info2 = Picked_Objects;
        do {
            int score = valid_target_count[i];
            if (score > best) {
                int picked = info2->object_id;
                best_obj = this->world->objects[picked];
                if (attacking_out != 0) {
                    *attacking_out = attacking[i];
                }
                best = score;
            }
            i++;
            info2++;
        } while (i < (int)master_obj);
    }
    return best_obj;
}

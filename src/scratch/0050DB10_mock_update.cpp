// 0050DB10 RGE_Timeline::mock_update
// Attempt log:
// initial source from packet/decompiler compiled to 512B: correct broad structure but old_time was at +0x0c instead of +0x10.
// fixed RGE_Timeline layout with gap_0C so old_time is +0x10; FPU member offsets now match.
// changed FPU compare spellings to `n->time > old_time`, `e->time <= t`, and `e->time > old_time` to recover original fld/fcomp/test 0x41 forms.
// changed command dispatch from if/else byte compares to switch; this recovered the original xor/mov al/dec/sub dispatch family and grew body to 528B.
// tried assigning list/e in alternate order (`e=time_list; list=e`); worsened early register use (loaded esi directly and moved edx later), rolled back.
// tried assignment-in-condition for e=list; no change from baseline.
// tried more explicit first scan loop (`while (e->next != 0) { n=e->next; ... }`); worsened diff with extra compare of [edx+2c], rolled back.
// temporarily added a separate dummy pad function only to let check_function compare the 528B body against 529B original; removed it. Diagnostic with pad: same 529 compare size, 13.23% edit diff, first mismatch at 0x16 due branch target/initial cmp scheduling.
// left in scratch: current real source is 528B (one byte short, check_function stops with section-size error). Remaining mismatch is small edit-distance but not accepted-drift-safe: early rewind list prologue schedules `cmp edx,ebx; mov esi,edx` instead of original `mov esi,edx; cmp esi,ebx`, first scan loop is shorter, and branch targets shift through both pass blocks.

struct RGE_Static_Object { virtual void destroy(int); };
struct RGE_Master_Static_Object { virtual void v0(); virtual void v4(); virtual void v8(); virtual void vc(); virtual void v10(); virtual void v14(); virtual RGE_Static_Object* create(void* player, int x, int y, int z); };
struct RGE_Player { char gap_00[0x24]; RGE_Master_Static_Object** master_objects; };
struct RGE_World { char gap_00[0x40]; RGE_Player** players; };

struct RGE_Time_Entry {
    float time;
    unsigned char command;
    char gap_05;
    short obj_type;
    unsigned char player;
    char gap_09[3];
    int x;
    int y;
    char gap_14[8];
    RGE_Static_Object* this_obj;
    short this_obj_id;
    char gap_22[2];
    RGE_Static_Object* target_obj;
    short target_obj_id;
    char gap_2A[2];
    RGE_Time_Entry* next;
};

class RGE_Timeline {
public:
    char gap_00[4];
    RGE_World* world;
    RGE_Time_Entry* time_list;
    char gap_0C[4];
    float old_time;
    void mock_update(float t);
};

void RGE_Timeline::mock_update(float t)
{
    RGE_Time_Entry* list;
    RGE_Time_Entry* e;
    RGE_Time_Entry* n;
    RGE_Static_Object* obj;

    if (t < old_time) {
        list = time_list;
        if ((e = list) != 0) {
            while ((n = e->next) != 0) {
                if (n->time > old_time) break;
                e = n;
            }
            while (e != 0) {
                if (e->time <= t) break;
                if (!(e->time > old_time)) {
                    switch (e->command) {
                    case 1:
                        obj = e->this_obj;
                        if (obj != 0) {
                            for (n = list; n != 0; n = n->next) {
                                if (obj == n->this_obj) n->this_obj = 0;
                                if (obj == n->target_obj) n->target_obj = 0;
                            }
                            if (obj != 0) obj->destroy(1);
                        }
                        break;
                    case 4:
                        {
                            RGE_Player* p = world->players[e->player];
                            RGE_Master_Static_Object* mo = p->master_objects[e->obj_type];
                            if (mo != 0) {
                                obj = mo->create(p, e->x, e->y, 0);
                                for (n = time_list; n != 0; n = n->next) {
                                    if (e->this_obj_id == n->this_obj_id) n->this_obj = obj;
                                    if (e->this_obj_id == n->target_obj_id) n->target_obj = obj;
                                }
                            }
                        }
                        break;
                    }
                }
                list = time_list;
                if (e == list) {
                    e = 0;
                } else {
                    n = list;
                    while (n != 0) {
                        RGE_Time_Entry* next = n->next;
                        if (next == e) e = n;
                        n = next;
                    }
                }
            }
        }
    }
    if (old_time < t) {
        e = time_list;
        while (e != 0) {
            if (e->time > old_time && !(e->time > t)) {
                switch (e->command) {
                case 1:
                    {
                        RGE_Player* p = world->players[e->player];
                        RGE_Master_Static_Object* mo = p->master_objects[e->obj_type];
                        if (mo != 0) {
                            obj = mo->create(p, e->x, e->y, 0);
                            for (n = time_list; n != 0; n = n->next) {
                                if (e->this_obj_id == n->this_obj_id) n->this_obj = obj;
                                if (e->this_obj_id == n->target_obj_id) n->target_obj = obj;
                            }
                        }
                    }
                    break;
                case 4:
                    obj = e->this_obj;
                    if (obj != 0) {
                        for (n = time_list; n != 0; n = n->next) {
                            if (obj == n->this_obj) n->this_obj = 0;
                            if (obj == n->target_obj) n->target_obj = 0;
                        }
                        if (obj != 0) obj->destroy(1);
                    }
                    break;
                }
            }
            e = e->next;
        }
    }
    old_time = t;
}


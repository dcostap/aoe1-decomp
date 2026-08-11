// VA: 004634C0 RGE_Object_List::find_by_master_id(long,float,float,unsigned char,unsigned char,RGE_Static_Object*)
// PDB source: obj_list.cpp lines 531-569
// attempt 1: natural list scan with optional state and zone/distance filtering; rebuilt used an extra best_dist local and early null return.
// attempt 2: reuse incoming param slot attempt changed register coloring and stayed short.
// attempt 3: no saved zone local; move found/best initialization after list load to encourage original stack-slot reuse.
// attempt 4: force empty-list path through common return; VC5 merged it with loop-finished return.
// attempt 5: volatile found with direct empty-list return still merged with loop-finished return.
// attempt 6: separate empty-list label still merged.
// attempt 7: wrap the loop in `if (node != 0) { ... return found; } return found;`; VC5 still merged empty/loop-finished returns.
// attempt 8: /GX and /Ob0 unchanged; /O1 much smaller. No custom flags kept.
// baseline candidate: restored the same natural declaration and while-scan shape as exact obj_list.cpp siblings; removed volatile/goto scaffolding.
// probe 1: baseline emitted the exact frame/calls/size but reversed the x87 square/add tree; try x-square before y-square to mirror the oracle's fmul order.


class RGE_Master_Static_Object {
public:
    char gap_00[0x10];
    short id;
};

class RGE_Static_Object {
public:
    char gap_00[8];
    RGE_Master_Static_Object* master; // +0x08
    char gap_0C[0x2C];
    float world_x;                    // +0x38
    float world_y;                    // +0x3C
    char gap_40[8];
    unsigned char object_state;        // +0x48

    unsigned char lookupZone(int x, int y);
};

struct RGE_Object_Node {
    RGE_Static_Object* object;
    RGE_Object_Node* next;
};

class RGE_Object_List {
public:
    char gap_00[4];
    RGE_Object_Node* list; // +0x04

    RGE_Static_Object* find_by_master_id(long master_id, float x, float y, unsigned char use_state, unsigned char state, RGE_Static_Object* zone_obj);
};

RGE_Static_Object* RGE_Object_List::find_by_master_id(long master_id, float x, float y, unsigned char use_state, unsigned char state, RGE_Static_Object* zone_obj)
{
    int zone;
    RGE_Object_Node* node;
    RGE_Static_Object* found;
    float best_dist;

    if (x > -1.0f && y > -1.0f && zone_obj != 0) {
        zone = zone_obj->lookupZone((int)x, (int)y) & 0xff;
    } else {
        zone = -1;
    }

    node = this->list;
    found = 0;
    best_dist = -1.0f;
    while (node != 0) {
        RGE_Static_Object* obj = node->object;
        if (obj != 0) {
            if (obj->master->id == master_id) {
                if (!use_state || obj->object_state == state) {
                    if (x == -1.0f || y == -1.0f) {
                        return node->object;
                    }
                    if (zone > -1) {
                        if ((zone_obj->lookupZone((int)obj->world_x, (int)obj->world_y) & 0xff) != zone) {
                            goto next_node;
                        }
                    }
                    RGE_Static_Object* current = node->object;
                    float diff_x = x - current->world_x;
                    float diff_y = y - current->world_y;
                    float dist = diff_x * diff_x + diff_y * diff_y;
                    if (best_dist == -1.0f || best_dist > dist) {
                        best_dist = dist;
                        found = current;
                    }
                }
            }
        }
next_node:
        node = node->next;
    }

    return found;
}

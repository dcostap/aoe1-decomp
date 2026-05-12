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
// left in scratch: behavior/call set understood; default build is 368 bytes vs original 381.
// remaining issue: original keeps two identical found-object return tails (loop-finished and empty-list) and uses the incoming zone_obj stack slot for best distance;
// rebuilt merges the found-object tails despite volatile/goto/duplicated-source return probes, leaving branch targets and size short by 13 bytes.

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
    if (x > -1.0f && y > -1.0f && zone_obj != 0) {
        zone = zone_obj->lookupZone((int)x, (int)y) & 0xff;
    } else {
        zone = -1;
    }

    RGE_Object_Node* node = this->list;
    RGE_Static_Object* volatile found_obj = 0;
    float best_dist = -1.0f;
    if (node != 0) {
    do {
        RGE_Static_Object* obj = node->object;
        if (obj != 0 && obj->master->id == master_id) {
            if (!use_state || obj->object_state == state) {
                if (x == -1.0f || y == -1.0f) {
                    return node->object;
                }
                if (zone > -1) {
                    if ((zone_obj->lookupZone((int)obj->world_x, (int)obj->world_y) & 0xff) != zone) {
                        goto next_node;
                    }
                }
                float diff_x = x - node->object->world_x;
                float diff_y = y - node->object->world_y;
                float dist = diff_y * diff_y + diff_x * diff_x;
                if (best_dist == -1.0f || dist < best_dist) {
                    best_dist = dist;
                    found_obj = node->object;
                }
            }
        }
next_node:
        node = node->next;
    } while (node != 0);

    return found_obj;
    }

    return found_obj;
}

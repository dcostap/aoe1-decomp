// VA: 00463310 RGE_Object_List::find_by_group
// Source: obj_list.cpp lines 474-512
// Attempt log:
// 1: natural list scan: close but x/y initial predicate used >= and early null-list return; original wants strict > -1 and common tail.
// 2: use strict > -1 for zone seed and remove explicit early null return.
// 3: spell best-distance comparison as `best_dist > dist` to match original FPU compare direction.
// 4: reload node->object for direct return/distance block so VC5 uses ECX/EAX like original instead of carried ESI.

class RGE_Static_Object;

class RGE_Master_Static_Object {
public:
    char gap_00[0x14];
    short object_group;
};

class RGE_Static_Object {
public:
    char gap_00[0x08];
    RGE_Master_Static_Object* master_obj;
    char gap_0C[0x38 - 0x0C];
    float x;
    float y;
    char gap_40[0x48 - 0x40];
    unsigned char player_id;

    unsigned char lookupZone(int x, int y);
};

class RGE_Object_List_Node {
public:
    RGE_Static_Object* object;
    RGE_Object_List_Node* next;
};

class RGE_Object_List {
public:
    char gap_00[4];
    RGE_Object_List_Node* first;

    RGE_Static_Object* find_by_group(long group, float x, float y, unsigned char check_player, unsigned char player_id, RGE_Static_Object* zone_obj);
};

RGE_Static_Object* RGE_Object_List::find_by_group(long group, float x, float y, unsigned char check_player, unsigned char player_id, RGE_Static_Object* zone_obj)
{
    int zone;
    RGE_Object_List_Node* node;
    RGE_Static_Object* found;
    float best_dist;

    if (x > -1.0f && y > -1.0f && zone_obj != 0) {
        zone = zone_obj->lookupZone((int)x, (int)y) & 0xff;
    } else {
        zone = -1;
    }

    node = this->first;
    found = 0;
    best_dist = -1.0f;
    while (node != 0) {
        RGE_Static_Object* obj = node->object;
        if (obj != 0) {
            if ((long)obj->master_obj->object_group == group) {
                if (!check_player || obj->player_id == player_id) {
                    if (x == -1.0f || y == -1.0f) {
                        return node->object;
                    }
                    if (zone > -1) {
                        if ((zone_obj->lookupZone((int)obj->x, (int)obj->y) & 0xff) != zone) {
                            goto next_node;
                        }
                    }
                    RGE_Static_Object* current = node->object;
                    float dx = x - current->x;
                    float dy = y - current->y;
                    float dist = dx * dx + dy * dy;
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

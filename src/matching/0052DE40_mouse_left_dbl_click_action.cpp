// VA: 0052DE40 mouse_left_dbl_click_action (278B)
// tvw_main.cpp
// Attempt log:
//   baseline: canonical typed pick/select path and player object-list scan;
//     size/frame/call set matched, but an early cached object pointer changed
//     the block shape.
//   liveness: removed the cached picked pointer and used pick_info.object
//     directly, restoring the original reload topology and leaving 2 bytes.
//   layout: corrected RGE_Static_Object id/master/owner offsets (+4/+8/+C).
//   behavior: matched the original owner/player comparison operand order.
//   abi: used the exact donor signature for Object_Was_Displayed(int, bool).
//   main-agent audit: restored canonical master/object/player/view destructor
//     ownership; emitted code remains exact.

#ifndef TVW_MAIN_SHARED_CONTEXT
class RGE_Player;
class RGE_Tile;

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char gap_04[0x0C];
    short id;
    char gap_12[0x7B];
    unsigned char select_level;
    unsigned char gap_8E;
    unsigned char unit_level;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    long id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
};

class RGE_Object_Node {
public:
    RGE_Static_Object* node;
    RGE_Object_Node* next;
};

class RGE_Object_List {
public:
    char gap_00[0x4];
    RGE_Object_Node* list;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x24];
    RGE_Object_List* objects;

    void unselect_object();
    int select_one_object(RGE_Static_Object* object, int play_sound);
};

struct RGE_Pick_Info {
    float x;
    float y;
    short scr_x;
    short scr_y;
    RGE_Static_Object* object;
    RGE_Tile* tile;
};

class RGE_View {
public:
    virtual ~RGE_View();
    char gap_04[0xFC];
    RGE_Player* player;

    bool Object_Was_Displayed(int id, bool allow_flagged);
};

class RGE_Main_View : public RGE_View {
public:
    unsigned char pick1(unsigned char command, unsigned char mode,
                        long x, long y, RGE_Pick_Info* info,
                        RGE_Static_Object* exclude, int flags);
};

class TRIBE_Main_View : public RGE_Main_View {
public:
    long mouse_left_dbl_click_action(long x, long y, int key, int flags);
};
#endif

long TRIBE_Main_View::mouse_left_dbl_click_action(long x, long y,
                                                   int key, int flags) {
    RGE_Pick_Info pick_info;

    if (this->pick1(0x29, 1, x, y, &pick_info, 0, 1) == 0x34) {
        if ((pick_info.object->master_obj->select_level == 4) &&
            (pick_info.object->owner == this->player)) {
            if ((key == 0) && (flags == 0)) {
                this->player->unselect_object();
            }

            this->player->select_one_object(pick_info.object, 0);

            short object_id = pick_info.object->master_obj->id;
            unsigned char unit_level = pick_info.object->master_obj->unit_level;
            if (unit_level != 3) {
                unit_level = (unsigned char)-1;
            }

            RGE_Object_Node* node = this->player->objects->list;
            while (node != 0) {
                RGE_Static_Object* object = node->node;
                if ((object->master_obj->id == object_id) ||
                    (object->master_obj->unit_level == unit_level)) {
                    if (this->Object_Was_Displayed(object->id, false)) {
                        this->player->select_one_object(object, 0);
                    }
                }
                node = node->next;
            }

            this->player->select_one_object(pick_info.object, 0);
            return 1;
        }
    }

    return 0;
}

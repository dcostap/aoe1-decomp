// RGE_Action_Transport::update
// VA: 00406F90
// PDB: act_tran.cpp:139-300
//
// Attempt log:
// - Reconstructed the action-list, static-object, player/world/map, and
//   transport virtual/member surfaces from exact act_tran.cpp/action donors.
// - Natural switch and typed call surfaces reached exact size/frame/CFG/call
//   parity; correcting action field ownership and keeping zero-count cleanup
//   outside the owner notification reduced the diagnostic diff to 28 bytes.
// - The natural target-x `-1.0f` sentinel preserves the target dword compare
//   and map/x87 order. Preloading the drop pointer or swapping fallback
//   declarations was rolled back: each added 63 bytes and two virtual calls.
// - Tried the proven drop-result/object-local order with corrected long notify
//   trailing parameters; the direct form was unchanged, while the stored-result
//   form added 63 bytes and two calls. Restored the clean direct-call form.
// - Spelled sub-action success as `result > 0`; this recovered the original
//   unsigned-byte branch and reduced the live mismatch to the drop block.
// - Made a zero drop result notify 0x207 and break before the 0x206 success
//   check. VC5 then hoisted the object reload and tail-merged the notify block.
//   Removing a redundant scope kept the exact bytes in ordinary source form.
// - The source now matches all function bytes. The standalone extraction still
//   reports local switch-table relocations, but they do not affect exact bytes.

#ifndef ACT_TRAN_SHARED_CONTEXT
class RGE_Action;
class RGE_Action_List;
class RGE_Action_Object;
class RGE_Game_World;
class RGE_Map;
class RGE_Object_List;
class RGE_Player;
class RGE_Sprite;

class RGE_Object_List {
public:
    virtual void vf00(void);
    void* list;
    short number_of_objects;
    char gap_0A[2];
};

class RGE_Map {
public:
    virtual void vf00(void);
    char gap_04[4];
    long map_width;
    long map_height;

    unsigned char get_terrain(short x, short y);
};

class RGE_Game_World {
public:
    virtual void vf00(void);
    char gap_04[0x24];
    RGE_Map* map;
};

class RGE_Player {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void vf18(void);
    virtual void vf1C(void);
    virtual void vf20(void);
    virtual void vf24(void);
    virtual void vf28(void);
    virtual void vf2C(void);
    virtual void vf30(void);
    virtual void vf34(void);
    virtual void vf38(void);
    virtual void vf3C(void);
    virtual void vf40(void);
    virtual void vf44(void);
    virtual void vf48(void);
    virtual void vf4C(void);
    virtual void vf50(void);
    virtual void vf54(void);
    virtual void vf58(void);
    virtual void vf5C(void);
    virtual void vf60(void);
    virtual void vf64(void);
    virtual void vf68(void);
    virtual void vf6C(void);
    virtual void vf70(void);
    virtual void vf74(void);
    virtual void vf78(void);
    virtual void vf7C(void);
    virtual void vf80(void);
    virtual void vf84(void);
    virtual void vf88(void);
    virtual void vf8C(void);
    virtual void vf90(void);
    virtual void vf94(void);
    virtual void vf98(void);
    virtual void vf9C(void);
    virtual void vfA0(void);
    virtual void vfA4(void);
    virtual void vfA8(void);
    virtual void vfAC(void);
    virtual void vfB0(void);
    virtual void vfB4(void);
    virtual void vfB8(void);
    virtual void vfBC(void);
    virtual void vfC0(void);
    virtual void vfC4(void);
    virtual void vfC8(void);
    virtual void vfCC(void);
    virtual void vfD0(void);
    virtual void vfD4(void);
    virtual void vfD8(void);
    virtual void vfDC(void);
    virtual void vfE0(void);
    virtual void vfE4(void);
    virtual void notify(int param_1, int param_2, int param_3,
                        long param_4, long param_5, long param_6);

    char gap_04[0x38];
    RGE_Game_World* world;
};

class RGE_Static_Object {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void vf18(void);
    virtual void vf1C(void);
    virtual void vf20(void);
    virtual unsigned char update(void);
    virtual void vf28(void);
    virtual void vf2C(void);
    virtual void vf30(void);
    virtual void vf34(void);
    virtual void vf38(void);
    virtual void vf3C(void);
    virtual void vf40(void);
    virtual void vf44(void);
    virtual void vf48(void);
    virtual void vf4C(void);
    virtual void vf50(void);
    virtual void vf54(void);
    virtual void vf58(void);
    virtual void vf5C(void);
    virtual void vf60(void);
    virtual void vf64(void);
    virtual void vf68(void);
    virtual void vf6C(void);
    virtual void vf70(void);
    virtual void vf74(void);
    virtual void vf78(void);
    virtual void vf7C(void);
    virtual void vf80(void);
    virtual void vf84(void);
    virtual void vf88(void);
    virtual void vf8C(void);
    virtual void vf90(void);
    virtual void vf94(void);
    virtual void vf98(void);
    virtual void vf9C(void);
    virtual void vfA0(void);
    virtual void vfA4(void);
    virtual void vfA8(void);
    virtual void vfAC(void);
    virtual void vfB0(void);
    virtual void vfB4(void);
    virtual void vfB8(void);
    virtual void vfBC(void);
    virtual void vfC0(void);
    virtual void vfC4(void);
    virtual void vfC8(void);
    virtual void vfCC(void);
    virtual void vfD0(void);
    virtual void vfD4(void);
    virtual void vfD8(void);
    virtual void vfDC(void);
    virtual void vfE0(void);
    virtual void vfE4(void);
    virtual void vfE8(void);
    virtual void vfEC(void);
    virtual void vfF0(void);
    virtual void vfF4(void);
    virtual void vfF8(void);
    virtual void vfFC(void);
    virtual void vf100(void);
    virtual void vf104(void);
    virtual void vf108(void);
    virtual void vf10C(void);
    virtual void vf110(void);
    virtual void vf114(void);
    virtual void vf118(void);
    virtual void vf11C(void);
    virtual void vf120(void);
    virtual void vf124(void);
    virtual void vf128(void);
    virtual void vf12C(void);
    virtual void vf130(void);
    virtual void vf134(void);
    virtual void vf138(void);
    virtual void vf13C(void);
    virtual void vf140(void);
    virtual void vf144(void);
    virtual void notify(int param_1, int param_2, int param_3,
                        int param_4, int param_5, int param_6);

    long id;
    void* master_obj;
    RGE_Player* owner;
    char gap_10[0x14];
    RGE_Object_List* objects;
    char gap_28[0x10];
    float world_x;
    float world_y;
    float world_z;

    int withinRangeOfZone(unsigned char zone, float range);
    unsigned char drop_held_objects(int mode);
};

class RGE_Action_Object : public RGE_Static_Object {
};

class RGE_Action_List {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual unsigned char update(void);
};

class RGE_Action {
public:
    virtual void vf00(void);
    virtual int vf04(RGE_Action_Object* object);
    virtual int vf08(int value, RGE_Action_Object* object);
    virtual RGE_Action_List* vf0C(RGE_Action_Object* object);
    virtual void vf10(void);
    virtual void vf14(int value);
    virtual short vf18(void);
    virtual void vf1C(unsigned char value);
    virtual unsigned char vf20(void);
    virtual unsigned char vf24(void);
    virtual unsigned char update(void);
    virtual int vf2C(void);
    virtual int vf30(RGE_Static_Object* object, float x, float y, float z);
    virtual int vf34(RGE_Static_Object* object, float x, float y, float z);
    virtual unsigned char vf38(RGE_Static_Object* object);
    virtual unsigned char vf3C(long value, unsigned char relation);
    virtual void vf40(void* object);
    virtual void vf44(void* object, void* task, void* other_task);
    virtual void vf48(char* name);
    virtual RGE_Static_Object* vf4C(void);
    virtual RGE_Static_Object* vf50(void);
    virtual void set_target_obj(RGE_Static_Object* object);
    virtual void set_target_obj2(RGE_Static_Object* object);
    virtual void set_state(unsigned char state);

    int gap_04;
    RGE_Action_Object* obj;
    unsigned char state;
    char gap_0D[3];
    void* target_obj;
    void* target_obj2;
    int targetID;
    int target2ID;
    float target_x;
    float target_y;
    float target_z;
    float timer;
    void* task;
    RGE_Action_List* sub_actions;
    RGE_Sprite* sprite;
    unsigned char subActionValue;
    char gap_3D[3];
};

class RGE_Action_Transport : public RGE_Action {
public:
    virtual unsigned char update(void);
    int targetZone(void);
    virtual int next_to_drop_off_terrain(void);
};
#endif

unsigned char RGE_Action_Transport::update(void)
{
    switch (this->state) {
    case 4: {
        unsigned char result = this->sub_actions->update();
        if (result > 0 && result <= 5) {
            this->set_state(2);
            return 0;
        }
        return 0;
    }

    case 0x0B: {
        unsigned char result = this->sub_actions->update();
        if (result > 0 && result <= 5) {
            this->set_state(6);
            return 0;
        }
        return 0;
    }

    case 6: {
        int zone = this->targetZone();
        if (zone != -1 && this->obj->withinRangeOfZone((unsigned char)zone, 2.0f) == 0) {
            RGE_Action_Object* object = this->obj;
            RGE_Player* owner = object->owner;
            int id = object->id;
            owner->notify(id, id, 0x207, 0x266, 0, 0);
            break;
        }

        if (this->obj->objects->number_of_objects > 0) {
            if (this->next_to_drop_off_terrain() != 0) {
                zone = this->targetZone();
                if (this->obj->drop_held_objects(zone) == 0) {
                    this->obj->owner->notify(
                        this->obj->id, this->obj->id, 0x207, 0x266, 0, 0
                    );
                    break;
                }
                if (this->obj->objects->number_of_objects > 0) {
                    this->obj->owner->notify(
                        this->obj->id, this->obj->id, 0x206, 0x266, 0, 0
                    );
                }
                break;
            } else {
                RGE_Action_Object* object = this->obj;
                RGE_Player* owner = object->owner;
                RGE_Map* map = owner->world->map;
                if (this->target_x != -1.0f) {
                    if (map->get_terrain((short)this->target_x,
                                         (short)this->target_y) == 1 ||
                        map->get_terrain((short)this->target_x,
                                         (short)this->target_y) == 0x16) {
                        break;
                    }
                }
            }
            RGE_Player* owner = this->obj->owner;
            int id = this->obj->id;
            owner->notify(id, id, 0x207, 0x266, 0, 0);
        }
        break;
    }

    case 1:
        return 1;

    case 0x0D:
        this->obj->notify(this->obj->id, this->obj->id, 0x1F9, 0x266, 0, 0);
        this->set_state(2);
        return 3;

    default:
        return 0;
    }

    this->set_state(2);
    return 0;
}

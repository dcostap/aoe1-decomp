// VA: 004C6270 RGE_Static_Object::drop_held_objects
// Source: stat_obj.cpp lines 3818-3875
// Attempt log:
// - the binary-backed local frame is 0xB4 with four contiguous float arrays,
//   an address-taken x/y pair, next/temp nodes, and a byte count; typed
//   DropLocals preserves those proven offsets and the complete four-call set;
// - self-alias removal was codegen-neutral; separate scalar/array locals
//   regressed the frame to 0xB8 and were rolled back;
// - changing the retry loop to while removed an emitted duplicate
//   find_drop_location call, and moving next-node reload into the retry loop
//   improved the diagnostic diff, but broad this/index/register and CFG drift
//   remains;
// - prior validated candidate: 350 rebuilt bytes versus 387 original,
//   64.06% instruction-shape similarity, four ordered calls. Left in scratch
//   after the bounded pass; next lead is recovering natural source lifetimes
//   that reproduce the proven overlapping stack homes without opaque padding.
// - current pass: direct node-object rereads at find_drop_location with a
//   success-block held alias improved the candidate to 336 differing bytes,
//   65.62% shape, 0xB4 frame, and four ordered calls; this remains natural
//   typed source but still selects EBP for this and EDI for the retry index.
// - removing register from the index and changing the outer traversal to a
//   pretested while were codegen duplicates; retain the success-block alias
//   candidate as the best source reconstruction for this pause.

class RGE_Master_Static_Object { public: char gap_00[0x30]; float radius_x; float radius_y; };
class RGE_Static_Object;
class RGE_Object_Node { public: RGE_Static_Object* object; RGE_Object_Node* next; };
class RGE_Object_List { public: virtual ~RGE_Object_List(); RGE_Object_Node* first; };

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object(); virtual void vf04(void); virtual void vf08(void); virtual void vf0C(void);
    virtual void vf10(void); virtual void vf14(void); virtual void vf18(void); virtual void vf1C(void);
    virtual void vf20(void); virtual void vf24(void); virtual void vf28(void); virtual void vf2C(void);
    virtual void vf30(void); virtual float teleport(float x, float y, float z); virtual void vf38(void); virtual void vf3C(void);
    virtual void vf40(void); virtual void vf44(void); virtual void vf48(void); virtual void vf4C(void);
    virtual void vf50(void); virtual void vf54(void); virtual void vf58(void); virtual void vf5C(void);
    virtual void vf60(void); virtual void vf64(void); virtual void vf68(void); virtual void vf6C(void);
    virtual void vf70(void); virtual void vf74(void); virtual void vf78(void); virtual void vf7C(void);
    virtual void vf80(void); virtual void vf84(void); virtual void vf88(void); virtual void vf8C(void);
    virtual void vf90(void); virtual void vf94(void); virtual void vf98(void); virtual void vf9C(void);
    virtual void vfA0(void); virtual void vfA4(void); virtual void vfA8(void); virtual void vfAC(void);
    virtual void vfB0(void); virtual void vfB4(void); virtual void vfB8(void); virtual void vfBC(void);
    virtual void vfC0(void); virtual void vfC4(void); virtual void vfC8(void); virtual void vfCC(void);
    virtual void vfD0(void); virtual void release_from_holder(void);
    char gap_04[4]; RGE_Master_Static_Object* master_obj; char gap_0C[0x24 - 0x0C]; RGE_Object_List* objects; char gap_28[0x38 - 0x28];
    float world_x; float world_y; float world_z;
    void set_location(float x, float y, float z);
    unsigned char find_drop_location(int mode, float* x, float* y, RGE_Master_Static_Object* master, RGE_Static_Object* obj, float drop_x, float drop_y, float radius_x, float radius_y);
    unsigned char drop_held_objects(int mode);
};

struct DropLocals {
    RGE_Object_Node* temp;
    float x;
    float y;
    RGE_Object_Node* next;
    float drop_y[10];
    float radius_x[10];
    float drop_x[10];
    float radius_y[10];
};

unsigned char RGE_Static_Object::drop_held_objects(int mode)
{
    int i = 1;
    DropLocals l;
    unsigned char count = 0;
    l.drop_x[1] = this->world_x;
    l.drop_y[1] = this->world_y;
    l.radius_x[1] = this->master_obj->radius_x + this->master_obj->radius_x;
    l.radius_y[1] = this->master_obj->radius_y + this->master_obj->radius_y;
    l.temp = this->objects->first;

    while (l.temp != 0) {
        do {
                l.next = l.temp->next;
                if (i <= 0) {
                    break;
                }
                    if (this->find_drop_location(mode, &l.x, &l.y, l.temp->object->master_obj, l.temp->object, l.drop_x[1], l.drop_y[1], l.radius_x[1], l.radius_y[1])) {
                        RGE_Static_Object* held = l.temp->object;
                        held->set_location(this->world_x, this->world_y, this->world_z);
                        held->release_from_holder();
                        held->teleport(l.x, l.y, this->world_z);
                        ++count;
                        if (i < 9) {
                            RGE_Master_Static_Object* master = held->master_obj;
                            int index = i++;
                            l.drop_x[index + 1] = l.x;
                            l.drop_y[index + 1] = l.y;
                            l.radius_x[index + 1] = master->radius_x + master->radius_x;
                            l.radius_y[index + 1] = master->radius_y + master->radius_y;
                        }
                        break;
                    }
                    --i;
                    if (i <= 0) break;
                    l.drop_x[i] = l.drop_x[i + 1];
                    l.drop_y[i] = l.drop_y[i + 1];
                    l.radius_x[i] = l.radius_x[i + 1];
                    l.radius_y[i] = l.radius_y[i + 1];
        } while (i > 0);
        l.temp = l.next;
    }
    return count;
}

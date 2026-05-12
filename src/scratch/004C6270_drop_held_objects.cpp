// VA: 004C6270 RGE_Static_Object::drop_held_objects
// Source: stat_obj.cpp lines 3818-3875
// Attempt log:
// 1: natural reconstruction from packet/decompiler; wrong prologue (EDI=this, early return) and broad loop drift.
// 2: use explicit self local and common return with body guarded by non-null list; still EDI=this/EBP=temp.
// 3: make temp stack-like volatile to avoid preserving it in EBP; no change.
// 4: block-scope inner locals delayed saves but changed frame to 0xB8 and still broad.
// 5: use explicit local-frame struct matching observed stack order; restored 0xB4 frame but still wrong register/prologue.
// 6: remove self local in local-frame version; prologue closer (0xB4, EBX saved early) but this/i colored EBP/EBX.
// 7: mark i register and restore self local to probe ESI=i, EBX=this coloring; no codegen change.
// Left in scratch: behavior modeled, but prologue/register coloring and inner stack-array loop topology remain broad.

class RGE_Master_Static_Object { public: char gap_00[0x30]; float radius_x; float radius_y; };
class RGE_Static_Object;
class RGE_Object_Node { public: RGE_Static_Object* object; RGE_Object_Node* next; };
class RGE_Object_List { public: char gap_00[4]; RGE_Object_Node* first; };

class RGE_Static_Object {
public:
    virtual void vf00(void); virtual void vf04(void); virtual void vf08(void); virtual void vf0C(void);
    virtual void vf10(void); virtual void vf14(void); virtual void vf18(void); virtual void vf1C(void);
    virtual void vf20(void); virtual void vf24(void); virtual void vf28(void); virtual void vf2C(void);
    virtual void vf30(void); virtual float vf34(float x, float y, float z); virtual void vf38(void); virtual void vf3C(void);
    virtual void vf40(void); virtual void vf44(void); virtual void vf48(void); virtual void vf4C(void);
    virtual void vf50(void); virtual void vf54(void); virtual void vf58(void); virtual void vf5C(void);
    virtual void vf60(void); virtual void vf64(void); virtual void vf68(void); virtual void vf6C(void);
    virtual void vf70(void); virtual void vf74(void); virtual void vf78(void); virtual void vf7C(void);
    virtual void vf80(void); virtual void vf84(void); virtual void vf88(void); virtual void vf8C(void);
    virtual void vf90(void); virtual void vf94(void); virtual void vf98(void); virtual void vf9C(void);
    virtual void vfA0(void); virtual void vfA4(void); virtual void vfA8(void); virtual void vfAC(void);
    virtual void vfB0(void); virtual void vfB4(void); virtual void vfB8(void); virtual void vfBC(void);
    virtual void vfC0(void); virtual void vfC4(void); virtual void vfC8(void); virtual void vfCC(void);
    virtual void vfD0(void); virtual void vfD4(void);
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
    DropLocals l;
    unsigned char count = 0;
    register int i = 1;
    RGE_Static_Object* self = this;
    l.drop_x[1] = self->world_x;
    l.drop_y[1] = self->world_y;
    l.radius_x[1] = self->master_obj->radius_x + self->master_obj->radius_x;
    l.radius_y[1] = self->master_obj->radius_y + self->master_obj->radius_y;
    l.temp = self->objects->first;

    if (l.temp != 0) {
        do {
            l.next = l.temp->next;
            if (i > 0) {
                do {
                    RGE_Static_Object* held = l.temp->object;
                    if (self->find_drop_location(mode, &l.x, &l.y, held->master_obj, held, l.drop_x[1], l.drop_y[1], l.radius_x[1], l.radius_y[1])) {
                        held->set_location(self->world_x, self->world_y, self->world_z);
                        held->vfD4();
                        held->vf34(l.x, l.y, self->world_z);
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
            }
            l.temp = l.next;
        } while (l.temp != 0);
    }
    return count;
}

// tried a direct virtual-dispatch shape with manual vtable indexing; mismatch stayed in the prolog/call surface
// tried cdecl-style function pointers first; that introduced stack cleanup drift, so the remaining lead is thiscall-style dispatch

class RGE_Static_Object {
public:
    void* vftable;
    char gap_04[0x1C];
    RGE_Static_Object* inside_obj;
    char gap_24[0x14];
    int world_x;
    int world_y;
    int world_z;

    void rehook(void);
    RGE_Static_Object* get_object_pointer(long id);
};

typedef float (*RGE_Static_Object_RehookFn)(RGE_Static_Object*, int, int, int);
typedef void (*RGE_Static_Object_InsideFn)(RGE_Static_Object*, RGE_Static_Object*);

void RGE_Static_Object::rehook(void) {
    ((RGE_Static_Object_RehookFn)((void**)this->vftable)[13])(this, this->world_x, this->world_y, this->world_z);

    if (this->inside_obj != 0) {
        RGE_Static_Object* object = this->inside_obj;
        this->inside_obj = 0;
        object = this->get_object_pointer((long)object);
        if (object != 0) {
            ((RGE_Static_Object_InsideFn)((void**)this->vftable)[52])(this, object);
        }
    }
}

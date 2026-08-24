#ifndef TVW_MAIN_SHARED_CONTEXT
class RGE_Master_Static_Object {
public:
    char gap_00[0x10];
    short id;
};

class RGE_Static_Object {
public:
    char gap_00[0x8];
    RGE_Master_Static_Object* master_obj;
};

class RGE_View {
public:
    int pick_through_fog(RGE_Static_Object* obj);
};

class TRIBE_Main_View : public RGE_View {
public:
    int pick_through_fog(RGE_Static_Object* obj);
};
#endif

int TRIBE_Main_View::pick_through_fog(RGE_Static_Object* obj) {
    if ((obj != 0) && (obj->master_obj->id == 0x2D)) {
        return 1;
    }
    return RGE_View::pick_through_fog(obj);
}

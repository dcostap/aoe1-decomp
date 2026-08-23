#ifndef RGE_STAT_OBJ_SHARED_CONTEXT
class TDrawArea;
class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    void capture_frame_3d_cube(TDrawArea* p0, short p1, short p2);
};

#endif

void RGE_Static_Object::capture_frame_3d_cube(TDrawArea* p0, short p1, short p2) {}

#ifndef RGE_VIEW_SHARED_CONTEXT
class RGE_Static_Object;
class RGE_View {
public:
    virtual ~RGE_View();
    virtual int pick_through_fog(RGE_Static_Object* object);
};
#endif

int RGE_View::pick_through_fog(RGE_Static_Object* object) { return 0; }

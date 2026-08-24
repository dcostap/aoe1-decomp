#ifndef RGE_COM_OBJ_SHARED_CONTEXT
class RGE_Combat_Object {
public:
    virtual ~RGE_Combat_Object();
    int moveAwayFrom(int p0, int p1);
};
#endif

int RGE_Combat_Object::moveAwayFrom(int p0, int p1) { return 0; }

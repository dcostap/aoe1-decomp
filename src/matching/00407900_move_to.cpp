class RGE_Static_Object;

class RGE_Action {
public:
    virtual int move_to(RGE_Static_Object *, float, float, float);
};

int RGE_Action::move_to(RGE_Static_Object *, float, float, float) {
    return 0;
}

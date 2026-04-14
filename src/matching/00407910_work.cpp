class RGE_Static_Object;

class RGE_Action {
public:
    virtual int work(RGE_Static_Object *, float, float, float);
};

int RGE_Action::work(RGE_Static_Object *, float, float, float) {
    return 0;
}

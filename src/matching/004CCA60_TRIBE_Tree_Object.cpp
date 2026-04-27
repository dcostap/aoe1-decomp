// t_tre_ob.cpp:36-39, 131 bytes
// attempt 1: ctor with 6 params, EH frame, base ctor, vptr, conditional setup
class TRIBE_Master_Tree_Object;
class RGE_Player;

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    RGE_Static_Object(TRIBE_Master_Tree_Object*, RGE_Player*, float, float, float, int);
    int setup(TRIBE_Master_Tree_Object*, RGE_Player*, float, float, float);
};

class TRIBE_Tree_Object : public RGE_Static_Object {
public:
    virtual ~TRIBE_Tree_Object();

    TRIBE_Tree_Object(TRIBE_Master_Tree_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5, int param_6);
};

TRIBE_Tree_Object::TRIBE_Tree_Object(TRIBE_Master_Tree_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5, int param_6)
    : RGE_Static_Object(param_1, param_2, param_3, param_4, param_5, 0) {
    *(void**)this = (void*)0x574CB0;
    if (param_6 != 0) {
        setup(param_1, param_2, param_3, param_4, param_5);
    }
}

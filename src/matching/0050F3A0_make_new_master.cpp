// 0050F3A0 TRIBE_Master_Tree_Object::make_new_master
// Source: tm_tre_o.cpp lines 59-61
// Size: 98 bytes, 0.0000% MATCH
// Flags: /GX (EH prologue for the factory helper)
//
// Attempt log:
// - Probe 1-3: class had no padding → sizeof = 0xBC (188), original = 0xB8 (184)
// - Fix: added char gap_00[0xB4] to RGE_Master_Static_Object → sizeof = 0xB8
// - MATCH

class RGE_Master_Static_Object {
public:
    char gap_00[0xB4];
    virtual ~RGE_Master_Static_Object();
};

class TRIBE_Master_Tree_Object : public RGE_Master_Static_Object {
public:
    TRIBE_Master_Tree_Object(TRIBE_Master_Tree_Object* param_1, int param_2);
    RGE_Master_Static_Object* make_new_master(void);
};

RGE_Master_Static_Object* TRIBE_Master_Tree_Object::make_new_master(void) {
    return new TRIBE_Master_Tree_Object(this, 1);
}

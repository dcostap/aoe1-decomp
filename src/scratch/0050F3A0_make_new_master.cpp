// attempt 1: direct new-expression for the EH-framed factory helper
// result: the first compile was a hair short, and later source-shape probes only moved the basin around
// attempt 2: direct new-expression with minimal class surface
// attempt 3: explicit temp / branch / operator_new probes were not the right basin
// left in scratch because the remaining diff is a small size/padding gap in the factory helper

class RGE_Master_Static_Object {
public:
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

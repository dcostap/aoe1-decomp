class RGE_Static_Object;

class RGE_Action {
public:
    virtual unsigned char attack_response(RGE_Static_Object *);
};

unsigned char RGE_Action::attack_response(RGE_Static_Object *) {
    return 0;
}

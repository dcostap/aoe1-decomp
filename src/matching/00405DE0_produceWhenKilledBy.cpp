class RGE_Static_Object {
public:
    virtual unsigned char produceWhenKilledBy(int) const;
};

unsigned char RGE_Static_Object::produceWhenKilledBy(int a) const {
    return 1;
}

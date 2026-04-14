class RGE_Static_Object {
public:
    virtual unsigned char keepGatheringWhenObjectIsOut(int) const;
};

unsigned char RGE_Static_Object::keepGatheringWhenObjectIsOut(int a) const {
    return 0;
}

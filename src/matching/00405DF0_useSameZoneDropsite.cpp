class RGE_Static_Object {
public:
    virtual unsigned char useSameZoneDropsite() const;
};

unsigned char RGE_Static_Object::useSameZoneDropsite() const {
    return 1;
}

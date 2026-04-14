class RGE_Static_Object {
public:
    virtual unsigned char facetToNextWaypoint() const;
};

unsigned char RGE_Static_Object::facetToNextWaypoint() const {
    return 0xFF;
}

class RGE_Static_Object {
public:
    virtual unsigned char waitingToMove() const;
};

unsigned char RGE_Static_Object::waitingToMove() const {
    return 0;
}

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    unsigned char is_moving();
};

unsigned char RGE_Static_Object::is_moving() { return 0; }

class TRIBE_Panel_Object {
public:
    virtual ~TRIBE_Panel_Object();
    virtual long mouse_left_up_action(long p0, long p1, int p2, int p3);
};

long TRIBE_Panel_Object::mouse_left_up_action(long p0, long p1, int p2, int p3) { return 0; }

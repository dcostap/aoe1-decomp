// VA: 0045C970 setup (291B)
// move_obj.cpp

class RGE_Moving_Object {
public:
    virtual ~RGE_Moving_Object();
    char gap0[0x1E0 - 4];
    
    void setup(void* obj);
};

void RGE_Moving_Object::setup(void* obj) {
}

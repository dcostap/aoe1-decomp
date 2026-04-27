// VA: 00460C00 findAvoidancePath (292B)
// move_obj.cpp

class RGE_Moving_Object {
public:
    virtual ~RGE_Moving_Object();
    char gap0[0x1E0 - 4];
    
    void findAvoidancePath(int* path, int* count, int a3, int a4);
};

void RGE_Moving_Object::findAvoidancePath(int* path, int* count, int a3, int a4) {
}

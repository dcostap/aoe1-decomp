// VA: 004600F0 canPathWithAdditionalPassability (276B)
// move_obj.cpp

class RGE_Moving_Object {
public:
    virtual ~RGE_Moving_Object();
    char gap0[0x1E0 - 4];
    
    int canPathWithAdditionalPassability(int flags);
};

int RGE_Moving_Object::canPathWithAdditionalPassability(int flags) {
    return 0;
}

// VA: 00455430 ~RGE_Map dtor (305B)
// map.cpp

class RGE_Map {
public:
    int* vtable;
    char gap4[0x8DC0];
    int field_8DC4;
    char gap8DC8[0x4];
    int field_8DCC;
    
    ~RGE_Map();
};

RGE_Map::~RGE_Map() {
    vtable = (int*)0x570678;
    int* list = (int*)field_8DC4;
    if (list) {
        field_8DCC = 0;
    }
}

// VA: 0053FBD0 pick1 (982B)
// vw_main.cpp

class TRIBE_View_World {
public:
    char gap4[0x100];
    int field_104;
    
    int pick1(unsigned char a1, int a2, int a3);
};

int TRIBE_View_World::pick1(unsigned char a1, int a2, int a3) {
    if (a1 != 0x29) return 0;
    
    field_104 = a2;
    return 1;
}

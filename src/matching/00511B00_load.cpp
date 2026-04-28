// VA: 00511B00 MATCH
// TRIBE_Object_List::load(unsigned char, int, RGE_Game_World*)
// Source: tobj_lst.cpp lines 24-37
// Key: switch statement (not if/else) produces correct je-to-handler block layout
// dispatch: 'F' (0x46) -> TRIBE_Combat_Object (0x1C8), 'P' (0x50) -> TRIBE_Building_Object (0x204)
// FLAGS: /GX (needed for EH prolog basin)

class RGE_Game_World;

class RGE_Object_List {
public:
    virtual void load(unsigned char type, int mode, RGE_Game_World* world);
};

class RGE_Combat_Object {
public:
    virtual ~RGE_Combat_Object();
    RGE_Combat_Object(int mode, RGE_Game_World* world, int doSetup);
    char gap_00[0x184];  // sizeof(RGE_Combat_Object) = 0x188
};

class TRIBE_Combat_Object : public RGE_Combat_Object {
public:
    TRIBE_Combat_Object(int mode, RGE_Game_World* world, int doSetup);
    char gap_188[0x40];  // sizeof(TRIBE_Combat_Object) = 0x1C8
};

class TRIBE_Building_Object {
public:
    TRIBE_Building_Object(int mode, RGE_Game_World* world, int doSetup);
    char gap_00[0x204];  // sizeof(TRIBE_Building_Object) = 0x204
};

class TRIBE_Object_List : public RGE_Object_List {
public:
    void load(unsigned char type, int mode, RGE_Game_World* world);
};

// FLAGS: /GX (needed for EH prolog basin; declaring virtual ~RGE_Combat_Object triggers EH frame)

void TRIBE_Object_List::load(unsigned char type, int mode, RGE_Game_World* world) {
    switch (type) {
    case 'F':
        new TRIBE_Combat_Object(mode, world, 1);
        break;
    case 'P':
        new TRIBE_Building_Object(mode, world, 1);
        break;
    default:
        RGE_Object_List::load(type, mode, world);
        break;
    }
}

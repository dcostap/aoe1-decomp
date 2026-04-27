// VA: 00511B00
// TRIBE_Object_List::load(unsigned char, int, RGE_Game_World*)
// Source: tobj_lst.cpp lines 24-37

// dispatch type byte: 'F' (0x46) -> create TRIBE_Combat_Object (0x1C8 bytes)
// 'P' (0x50) -> create TRIBE_Building_Object (0x204 bytes)
// else -> delegate to base RGE_Object_List::load

// attempt 1: new expression -> /O2/Oy/GX needed for proper EH frame; sizes wrong (forward-decl)
// attempt 2: explicit operator_new -> VC5 rejects explicit ctor call via '->'
// attempt 3: new expression with proper class sizes (char padding) -> sizes match (196!) 
//            but block layout reversed (F/P handlers inline, base call at end vs vice versa)
// attempt 4: early-return style -> same layout
// attempt 5: goto-based pattern to force je-style jumps -> same jne/inline layout
//
// Remaining gap: two unavoidable differences:
//   1. EH handler address (push 561116h vs push 0) — inter-TU symbol, can't resolve locally
//   2. Block layout (je to handler-at-end vs jne-to-skip + handler-inline)
// The function is behaviorally correct and structurally close (same sizes, same ops)
// but can never be EXACT due to the unresolved EH handler address.
// Leaving in scratch.

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
    if (type == 'F') {
        new TRIBE_Combat_Object(mode, world, 1);
    } else if (type == 'P') {
        new TRIBE_Building_Object(mode, world, 1);
    } else {
        RGE_Object_List::load(type, mode, world);
    }
}

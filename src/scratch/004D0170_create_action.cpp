// 004D0170 TRIBE_Action_List::create_action
// tact_lst.cpp
// Attempt log:
// try 1: natural VC5 factory switch with `new` action subclasses and /GX EH context.

class RGE_Action {};
class RGE_Action_List { public: virtual RGE_Action* create_action(float, short); };

class TRIBE_Action_List : public RGE_Action_List {
public:
    void* owner;
    RGE_Action* create_action(float p1, short type);
};

#define ACT40(cls) class cls: public RGE_Action { public: char gap[0x40]; cls(float, void*); };
#define ACT44(cls) class cls: public RGE_Action { public: char gap[0x44]; cls(float, void*); };
#define ACT48(cls) class cls: public RGE_Action { public: char gap[0x48]; cls(float, void*); };
class TRIBE_Action_Build: public RGE_Action { public: char gap[0x40]; TRIBE_Action_Build(float, void*); };
class TRIBE_Action_Farm: public RGE_Action { public: char gap[0x50]; TRIBE_Action_Farm(float, void*); };
class TRIBE_Action_Wall: public RGE_Action { public: char gap[0x48]; TRIBE_Action_Wall(float, void*); };
ACT48(TRIBE_Action_Move)
ACT40(TRIBE_Action_Attack)
ACT40(TRIBE_Action_Gather)
ACT40(TRIBE_Action_DropOff)
ACT44(TRIBE_Action_Hunt)
ACT44(TRIBE_Action_Fish)
class TRIBE_Action_Trade: public RGE_Action { public: char gap[0x44]; TRIBE_Action_Trade(float, void*, int); };
ACT48(TRIBE_Action_Repair)
ACT40(TRIBE_Action_Convert)
class TRIBE_Action_UnknownA: public RGE_Action { public: char gap[0x40]; TRIBE_Action_UnknownA(float, void*); };

RGE_Action* TRIBE_Action_List::create_action(float p1, short type) {
    switch (type) {
    case 3:  return new TRIBE_Action_Build(p1, owner);
    case 4:  return new TRIBE_Action_Farm(p1, owner);
    case 5:  return new TRIBE_Action_Wall(p1, owner);
    case 6:  return new TRIBE_Action_Move(p1, owner);
    case 7:  return new TRIBE_Action_Attack(p1, owner);
    case 8:  return new TRIBE_Action_Gather(p1, owner);
    case 9:  return new TRIBE_Action_DropOff(p1, owner);
    case 10: return new TRIBE_Action_Hunt(p1, owner);
    case 11: return new TRIBE_Action_Fish(p1, owner);
    case 12: return new TRIBE_Action_Trade(p1, owner, 1);
    case 13: return new TRIBE_Action_Repair(p1, owner);
    case 14: return new TRIBE_Action_Convert(p1, owner);
    case 120: return new TRIBE_Action_UnknownA(p1, owner);
    default: return RGE_Action_List::create_action(p1, type);
    }
}

// 004512D0 RGE_Master_Doppleganger_Object::make_new_obj
// Source: m_dg_obj.cpp lines 94-108
//
// Canonical reconstruction: recycle a doppleganger object through the player's
// world when enabled; otherwise allocate the 0xB0 doppleganger object and call
// its seven-argument constructor. The long virtual surface is the proven
// RGE_Static_Object/RGE_Doppleganger_Object slot layout; only declarations are
// needed here because this TU emits the factory, not those methods.
//
// Attempt log:
// - Replaced the previous non-polymorphic/master and standalone dispatch stubs
//   with the period class hierarchy and the proven vt[123] six-argument method.

class RGE_Player;
class RGE_Game_World;
class RGE_Master_Static_Object;
class RGE_Master_Animated_Object;
class RGE_Master_Doppleganger_Object;
class RGE_Static_Object;
class RGE_Animated_Object;
class RGE_Doppleganger_Object;

// RGE_Static_Object has vt[0..121]. The five-argument recycle method is vt[1].
class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game(RGE_Master_Static_Object*, RGE_Player*, float, float, float);
#define DG_STATIC_VIRTUAL(n) virtual void dg_static_v##n();
    DG_STATIC_VIRTUAL(02)  DG_STATIC_VIRTUAL(03)  DG_STATIC_VIRTUAL(04)
    DG_STATIC_VIRTUAL(05)  DG_STATIC_VIRTUAL(06)  DG_STATIC_VIRTUAL(07)
    DG_STATIC_VIRTUAL(08)  DG_STATIC_VIRTUAL(09)  DG_STATIC_VIRTUAL(10)
    DG_STATIC_VIRTUAL(11)  DG_STATIC_VIRTUAL(12)  DG_STATIC_VIRTUAL(13)
    DG_STATIC_VIRTUAL(14)  DG_STATIC_VIRTUAL(15)  DG_STATIC_VIRTUAL(16)
    DG_STATIC_VIRTUAL(17)  DG_STATIC_VIRTUAL(18)  DG_STATIC_VIRTUAL(19)
    DG_STATIC_VIRTUAL(20)  DG_STATIC_VIRTUAL(21)  DG_STATIC_VIRTUAL(22)
    DG_STATIC_VIRTUAL(23)  DG_STATIC_VIRTUAL(24)  DG_STATIC_VIRTUAL(25)
    DG_STATIC_VIRTUAL(26)  DG_STATIC_VIRTUAL(27)  DG_STATIC_VIRTUAL(28)
    DG_STATIC_VIRTUAL(29)  DG_STATIC_VIRTUAL(30)  DG_STATIC_VIRTUAL(31)
    DG_STATIC_VIRTUAL(32)  DG_STATIC_VIRTUAL(33)  DG_STATIC_VIRTUAL(34)
    DG_STATIC_VIRTUAL(35)  DG_STATIC_VIRTUAL(36)  DG_STATIC_VIRTUAL(37)
    DG_STATIC_VIRTUAL(38)  DG_STATIC_VIRTUAL(39)  DG_STATIC_VIRTUAL(40)
    DG_STATIC_VIRTUAL(41)  DG_STATIC_VIRTUAL(42)  DG_STATIC_VIRTUAL(43)
    DG_STATIC_VIRTUAL(44)  DG_STATIC_VIRTUAL(45)  DG_STATIC_VIRTUAL(46)
    DG_STATIC_VIRTUAL(47)  DG_STATIC_VIRTUAL(48)  DG_STATIC_VIRTUAL(49)
    DG_STATIC_VIRTUAL(50)  DG_STATIC_VIRTUAL(51)  DG_STATIC_VIRTUAL(52)
    DG_STATIC_VIRTUAL(53)  DG_STATIC_VIRTUAL(54)  DG_STATIC_VIRTUAL(55)
    DG_STATIC_VIRTUAL(56)  DG_STATIC_VIRTUAL(57)  DG_STATIC_VIRTUAL(58)
    DG_STATIC_VIRTUAL(59)  DG_STATIC_VIRTUAL(60)  DG_STATIC_VIRTUAL(61)
    DG_STATIC_VIRTUAL(62)  DG_STATIC_VIRTUAL(63)  DG_STATIC_VIRTUAL(64)
    DG_STATIC_VIRTUAL(65)  DG_STATIC_VIRTUAL(66)  DG_STATIC_VIRTUAL(67)
    DG_STATIC_VIRTUAL(68)  DG_STATIC_VIRTUAL(69)  DG_STATIC_VIRTUAL(70)
    DG_STATIC_VIRTUAL(71)  DG_STATIC_VIRTUAL(72)  DG_STATIC_VIRTUAL(73)
    DG_STATIC_VIRTUAL(74)  DG_STATIC_VIRTUAL(75)  DG_STATIC_VIRTUAL(76)
    DG_STATIC_VIRTUAL(77)  DG_STATIC_VIRTUAL(78)  DG_STATIC_VIRTUAL(79)
    DG_STATIC_VIRTUAL(80)  DG_STATIC_VIRTUAL(81)  DG_STATIC_VIRTUAL(82)
    DG_STATIC_VIRTUAL(83)  DG_STATIC_VIRTUAL(84)  DG_STATIC_VIRTUAL(85)
    DG_STATIC_VIRTUAL(86)  DG_STATIC_VIRTUAL(87)  DG_STATIC_VIRTUAL(88)
    DG_STATIC_VIRTUAL(89)  DG_STATIC_VIRTUAL(90)  DG_STATIC_VIRTUAL(91)
    DG_STATIC_VIRTUAL(92)  DG_STATIC_VIRTUAL(93)  DG_STATIC_VIRTUAL(94)
    DG_STATIC_VIRTUAL(95)  DG_STATIC_VIRTUAL(96)  DG_STATIC_VIRTUAL(97)
    DG_STATIC_VIRTUAL(98)  DG_STATIC_VIRTUAL(99)  DG_STATIC_VIRTUAL(100)
    DG_STATIC_VIRTUAL(101) DG_STATIC_VIRTUAL(102) DG_STATIC_VIRTUAL(103)
    DG_STATIC_VIRTUAL(104) DG_STATIC_VIRTUAL(105) DG_STATIC_VIRTUAL(106)
    DG_STATIC_VIRTUAL(107) DG_STATIC_VIRTUAL(108) DG_STATIC_VIRTUAL(109)
    DG_STATIC_VIRTUAL(110) DG_STATIC_VIRTUAL(111) DG_STATIC_VIRTUAL(112)
    DG_STATIC_VIRTUAL(113) DG_STATIC_VIRTUAL(114) DG_STATIC_VIRTUAL(115)
    DG_STATIC_VIRTUAL(116) DG_STATIC_VIRTUAL(117) DG_STATIC_VIRTUAL(118)
    DG_STATIC_VIRTUAL(119) DG_STATIC_VIRTUAL(120) DG_STATIC_VIRTUAL(121)
#undef DG_STATIC_VIRTUAL
    char gap_04[0x84];
};

class RGE_Animated_Object : public RGE_Static_Object {
public:
    virtual ~RGE_Animated_Object();
    float speed;
    virtual int setup(RGE_Master_Animated_Object*, RGE_Player*, float, float, float);
    RGE_Animated_Object(RGE_Master_Animated_Object*, RGE_Player*, float, float, float, int);
};

class RGE_Doppleganger_Object : public RGE_Animated_Object {
public:
    virtual ~RGE_Doppleganger_Object();
    virtual void recycle_in_to_game(RGE_Master_Static_Object*, RGE_Player*, float, float, float, RGE_Static_Object*);
    RGE_Static_Object* doppled_object;
    void* draw_color;
    RGE_Master_Static_Object* doppled_master_obj;
    int doppled_player;
    unsigned long* MapAddress;
    unsigned long LastMapValue;
    unsigned long CantSeeBits;
    unsigned char map_draw_level;
    unsigned char map_color;
    char gap_AA[2];
    int doppledObjectID;
    RGE_Doppleganger_Object(RGE_Master_Doppleganger_Object*, RGE_Player*, float, float, float, int, RGE_Static_Object*);
};

typedef char assert_doppleganger_size[(sizeof(RGE_Doppleganger_Object) == 0xB0) ? 1 : -1];

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    unsigned char master_type;
    char gap_05[0xA4 - 0x5];
    unsigned char recyclable;
    char gap_A5[0xB8 - 0xA5];
};

class RGE_Master_Animated_Object : public RGE_Master_Static_Object {
public:
    float speed;
};

class RGE_Master_Doppleganger_Object : public RGE_Master_Animated_Object {
public:
    virtual RGE_Static_Object* make_new_obj(RGE_Player*, float, float, float, RGE_Static_Object*);
};

class RGE_Player {
public:
    char gap_00[0x3C];
    RGE_Game_World* world;
};

class RGE_Game_World {
public:
    RGE_Static_Object* recycle_object_in_to_game(unsigned char);
};

RGE_Static_Object* RGE_Master_Doppleganger_Object::make_new_obj(
    RGE_Player* player, float x, float y, float z, RGE_Static_Object* static_obj)
{
    if (recyclable) {
        RGE_Doppleganger_Object* recycled =
            (RGE_Doppleganger_Object*)player->world->recycle_object_in_to_game(master_type);
        if (recycled) {
            recycled->recycle_in_to_game(this, player, x, y, z, static_obj);
            return recycled;
        }
    }

    return new RGE_Doppleganger_Object(this, player, x, y, z, 1, static_obj);
}

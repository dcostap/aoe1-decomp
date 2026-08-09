// 00506A70 TribeTransportShipUnitAIModule::processIdle (taiuaimd.cpp:2122-2147)
// int __thiscall processIdle(int param_1)
//
// MATCHED - natural typed thiscall virtual surfaces reproduce both dispatch calls.
// The final explicit float cast preserves the original VC5 fchs/fadd movement lowering.
//
// Attempts:
// 1. __fastcall vtable shims and early returns produced an extra edx setup and wrong tails.
// 2. Typed virtual slots at +40/+9C and +FC removed the ABI drift and fixed the structure.
// 3. Materializing getSpeed()*7 before dx/dy fixed the original FPU evaluation order.
// 4-7. Equivalent movement spellings either emitted fsubr or spilled intermediates.
// 8. A focused variant lab found `(float)(-((delta / distance) * speed)) + position` exact.
// Main-agent audit restored canonical polymorphic ownership and destructor
// slots throughout the world/object/AI surface; emitted code remains exact.

#include <math.h>

class RGE_Game_World;

class RGE_Player {
public:
    virtual ~RGE_Player();
    char _gap_04[0x38];
    RGE_Game_World* world;
    int computerPlayer();
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    class RGE_Static_Object* object(int id);
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    char _gap_04[0x34];
    float world_x;
    float world_y;
};

class TribeTransportShipUnitAIModule_Sub {
public:
    char _gap_04[0x08];
    RGE_Player* player;
    char _gap_10[0x28];
    float x_pos;
    float y_pos;
    int field_40;

    virtual ~TribeTransportShipUnitAIModule_Sub();
    virtual void pad01() = 0;
    virtual void pad02() = 0;
    virtual void pad03() = 0;
    virtual void pad04() = 0;
    virtual void pad05() = 0;
    virtual void pad06() = 0;
    virtual void pad07() = 0;
    virtual void pad08() = 0;
    virtual void pad09() = 0;
    virtual void pad10() = 0;
    virtual void pad11() = 0;
    virtual void pad12() = 0;
    virtual void pad13() = 0;
    virtual void pad14() = 0;
    virtual void pad15() = 0;
    virtual void pad16() = 0;
    virtual void pad17() = 0;
    virtual void pad18() = 0;
    virtual void pad19() = 0;
    virtual void pad20() = 0;
    virtual void pad21() = 0;
    virtual void pad22() = 0;
    virtual void pad23() = 0;
    virtual void pad24() = 0;
    virtual void pad25() = 0;
    virtual void pad26() = 0;
    virtual void pad27() = 0;
    virtual void pad28() = 0;
    virtual void pad29() = 0;
    virtual void pad30() = 0;
    virtual void pad31() = 0;
    virtual void pad32() = 0;
    virtual void pad33() = 0;
    virtual void pad34() = 0;
    virtual void pad35() = 0;
    virtual void pad36() = 0;
    virtual void pad37() = 0;
    virtual void pad38() = 0;
    virtual void pad39() = 0;
    virtual void pad40() = 0;
    virtual void pad41() = 0;
    virtual void pad42() = 0;
    virtual void pad43() = 0;
    virtual void pad44() = 0;
    virtual void pad45() = 0;
    virtual void pad46() = 0;
    virtual void pad47() = 0;
    virtual void pad48() = 0;
    virtual void pad49() = 0;
    virtual void pad50() = 0;
    virtual void pad51() = 0;
    virtual void pad52() = 0;
    virtual void pad53() = 0;
    virtual void pad54() = 0;
    virtual void pad55() = 0;
    virtual void pad56() = 0;
    virtual void pad57() = 0;
    virtual void pad58() = 0;
    virtual void pad59() = 0;
    virtual void pad60() = 0;
    virtual void pad61() = 0;
    virtual void pad62() = 0;
    virtual float getSpeed() = 0;
};

class TribeTransportShipUnitAIModule {
public:
    TribeTransportShipUnitAIModule_Sub* sub;

    virtual ~TribeTransportShipUnitAIModule();
    virtual void pad01() = 0;
    virtual void pad02() = 0;
    virtual void pad03() = 0;
    virtual void pad04() = 0;
    virtual void pad05() = 0;
    virtual void pad06() = 0;
    virtual void pad07() = 0;
    virtual void pad08() = 0;
    virtual void pad09() = 0;
    virtual void pad10() = 0;
    virtual void pad11() = 0;
    virtual void pad12() = 0;
    virtual void pad13() = 0;
    virtual void pad14() = 0;
    virtual void pad15() = 0;
    virtual int findTarget(int, int, int, int, int) = 0;
    virtual void pad17() = 0;
    virtual void pad18() = 0;
    virtual void pad19() = 0;
    virtual void pad20() = 0;
    virtual void pad21() = 0;
    virtual void pad22() = 0;
    virtual void pad23() = 0;
    virtual void pad24() = 0;
    virtual void pad25() = 0;
    virtual void pad26() = 0;
    virtual void pad27() = 0;
    virtual void pad28() = 0;
    virtual void pad29() = 0;
    virtual void pad30() = 0;
    virtual void pad31() = 0;
    virtual void pad32() = 0;
    virtual void pad33() = 0;
    virtual void pad34() = 0;
    virtual void pad35() = 0;
    virtual void pad36() = 0;
    virtual void pad37() = 0;
    virtual void pad38() = 0;
    virtual void moveTo(float, float, int, int) = 0;

    int processIdle(int param_1);
};

int TribeTransportShipUnitAIModule::processIdle(int param_1)
{
    if (this->sub->player->computerPlayer()) {
        int targetId = findTarget(-1, -1, -1, -1, 0);

        if (targetId != -1) {
            RGE_Static_Object* target = this->sub->player->world->object(targetId);

            if (target != 0) {
                float speed = this->sub->getSpeed() * 7.0f;

                float dx = target->world_x - this->sub->x_pos;
                float dy = target->world_y - this->sub->y_pos;
                float dist = (float)sqrt(dx * dx + dy * dy);

                float move_x = (float)(-((dx / dist) * speed)) + this->sub->x_pos;
                float move_y = (float)(-((dy / dist) * speed)) + this->sub->y_pos;

                moveTo(move_x, move_y, this->sub->field_40, 1);

                return 6;
            }
        }
    }

    return 5;
}

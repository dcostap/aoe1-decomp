// 005066D0 TribeTradeShipUnitAIModule::processIdle
// PDB: taiuaimd.cpp:1981-2027, 250 bytes
//
// Canonical reconstruction: an AI trade ship looks for its destination,
// obtains the ship speed, and moves back toward the ship by seven speed
// units.  The object/player/world fields and the virtual calls are modeled at
// their proven offsets; the math is kept in the natural source form suggested
// by the original x87 stack topology.
//
// Attempt log:
// - Typed virtual surfaces and nested success guards matched the frame, calls,
//   and all non-math control-flow structure.
// - Binding the seven-times-speed scale to the getter result reproduced the
//   original early FMUL and exact-size FPU schedule.
// - The explicit float cast around each negated movement product is deliberate:
//   without it VC5 folds the operation into FPU FSUBR; with it the original
//   FCHS/FADD pair and branch displacements are reproduced. MATCH.
// Main-agent audit restored canonical destructor slots on the world/player,
// object, and AI surfaces; emitted code remains exact.

#include <math.h>

class RGE_Static_Object;

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    RGE_Static_Object* object(int id);
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x38];
    RGE_Game_World* world;                 // +0x3C

    int computerPlayer();
};

class RGE_Static_Object {
public:
    char gap_04[0x08];                     // +0x04 .. +0x0B
    RGE_Player* owner;                     // +0x0C
    char gap_10[0x28];                     // +0x10 .. +0x37
    float world_x;                         // +0x38
    float world_y;                         // +0x3C
    int field_40;                          // +0x40

    virtual ~RGE_Static_Object();
    virtual void pad01();
    virtual void pad02();
    virtual void pad03();
    virtual void pad04();
    virtual void pad05();
    virtual void pad06();
    virtual void pad07();
    virtual void pad08();
    virtual void pad09();
    virtual void pad10();
    virtual void pad11();
    virtual void pad12();
    virtual void pad13();
    virtual void pad14();
    virtual void pad15();
    virtual void pad16();
    virtual void pad17();
    virtual void pad18();
    virtual void pad19();
    virtual void pad20();
    virtual void pad21();
    virtual void pad22();
    virtual void pad23();
    virtual void pad24();
    virtual void pad25();
    virtual void pad26();
    virtual void pad27();
    virtual void pad28();
    virtual void pad29();
    virtual void pad30();
    virtual void pad31();
    virtual void pad32();
    virtual void pad33();
    virtual void pad34();
    virtual void pad35();
    virtual void pad36();
    virtual void pad37();
    virtual void pad38();
    virtual void pad39();
    virtual void pad40();
    virtual void pad41();
    virtual void pad42();
    virtual void pad43();
    virtual void pad44();
    virtual void pad45();
    virtual void pad46();
    virtual void pad47();
    virtual void pad48();
    virtual void pad49();
    virtual void pad50();
    virtual void pad51();
    virtual void pad52();
    virtual void pad53();
    virtual void pad54();
    virtual void pad55();
    virtual void pad56();
    virtual void pad57();
    virtual void pad58();
    virtual void pad59();
    virtual void pad60();
    virtual void pad61();
    virtual void pad62();
    virtual float getSpeed();              // +0xFC
};

class TribeTradeShipUnitAIModule {
public:
    RGE_Static_Object* obj;                // +0x04 (vptr at +0x00)

    virtual ~TribeTradeShipUnitAIModule();
    virtual void pad01();
    virtual void pad02();
    virtual void pad03();
    virtual void pad04();
    virtual void pad05();
    virtual void pad06();
    virtual void pad07();
    virtual void pad08();
    virtual void pad09();
    virtual void pad10();
    virtual void pad11();
    virtual void pad12();
    virtual void pad13();
    virtual void pad14();
    virtual void pad15();
    virtual int findTarget(int, int, int, int, int); // +0x40
    virtual void pad17();
    virtual void pad18();
    virtual void pad19();
    virtual void pad20();
    virtual void pad21();
    virtual void pad22();
    virtual void pad23();
    virtual void pad24();
    virtual void pad25();
    virtual void pad26();
    virtual void pad27();
    virtual void pad28();
    virtual void pad29();
    virtual void pad30();
    virtual void pad31();
    virtual void pad32();
    virtual void pad33();
    virtual void pad34();
    virtual void pad35();
    virtual void pad36();
    virtual void pad37();
    virtual void pad38();
    virtual void moveTo(float, float, int, int);     // +0x9C

    int processIdle(int param_1);
};

int TribeTradeShipUnitAIModule::processIdle(int param_1)
{
    if (this->obj->owner->computerPlayer()) {
        int targetId = this->findTarget(-1, -1, -1, -1, 0);
        if (targetId != -1) {
            RGE_Static_Object* target = this->obj->owner->world->object(targetId);
            if (target != 0) {
                float speed = this->obj->getSpeed() * 7.0f;
                float xDiff = target->world_x - this->obj->world_x;
                float yDiff = target->world_y - this->obj->world_y;
                float distance = (float)sqrt(xDiff * xDiff + yDiff * yDiff);

                this->moveTo(
                    (float)(-(xDiff / distance * speed)) + this->obj->world_x,
                    (float)(-(yDiff / distance * speed)) + this->obj->world_y,
                    this->obj->field_40, 1);
                return 6;
            }
        }
    }

    return 5;
}

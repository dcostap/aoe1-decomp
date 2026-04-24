// compact combat attack wrapper first
// expected basin: a pre-attack owner/permission check, optional owner-side callback, then base combat attack

class RGE_Combat_Object;
class RGE_Static_Object;
class RGE_Player;

class AttackContext {
public:
    char pad_00[0x124];
    short field_124;
};

class RGE_Static_Object {
public:
    char pad_00[0xC];
    RGE_Player* owner;
};

class RGE_Game_World;

class RGE_Player {
public:
    char pad_00[0x38];
    RGE_Game_World* world;
    char pad_40[0xA];
    short id;

    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void vf18(void);
    virtual void vf1C(void);
    virtual void vf20(void);
    virtual void vf24(void);
    virtual void vf28(void);
    virtual void vf2C(void);
    virtual void vf30(void);
    virtual void vf34(void);
    virtual void vf38(void);
    virtual void vf3C(void);
    virtual void vf40(void);
    virtual void vf44(void);
    virtual void vf48(void);
    virtual void vf4C(void);
    virtual void vf50(void);
    virtual void vf54(void);
    virtual void vf58(void);
    virtual void vf5C(void);
    virtual void vf60(void);
    virtual void vf64(void);
    virtual void vf68(void);
    virtual void vf6C(void);
    virtual void vf70(void);
    virtual void vf74(void);
    virtual void vf78(void);
    virtual void vf7C(void);
    virtual void vf80(void);
    virtual void vf84(void);
    virtual void vf88(void);
    virtual void vf8C(void);
    virtual void vf90(void);
    virtual void vf94(int, float, float, float, int);
};

class RGE_Combat_Object {
public:
    char pad_00[0x8];
    AttackContext* context;
    char pad_0C[0x2C];
    float field_38;
    float field_3C;
    float field_40;

    unsigned char attack(RGE_Static_Object* target, RGE_Combat_Object* other);
};

class TRIBE_Combat_Object : public RGE_Combat_Object {
public:
    unsigned char attack(RGE_Static_Object* target, RGE_Combat_Object* other);
};

unsigned char TRIBE_Combat_Object::attack(RGE_Static_Object* target, RGE_Combat_Object* other) {
    if (this->context->field_124 >= 0 && target != 0 && target->owner->id > 0) {
        target->owner->vf94(0x70, this->field_38, this->field_3C, this->field_40, 0);
    }
    return RGE_Combat_Object::attack(target, other);
}

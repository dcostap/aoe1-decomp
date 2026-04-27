// ACCEPTED_DRIFT: VC5 prolog/register-save drift only. Rebuilt saves ebp before the count test and uses adjusted stack offsets, but the count predicate, get_obj loop, virtual attack-ground call arguments, decrement loop, and stack cleanup are equivalent.
// tried natural countdown with signed char count; worsened prolog by pushing ebp early.
// reverted to decompiler-shaped unsigned count/goto family; remaining mismatch is startup register-save shape around the count test.
class RGE_Obj_Info { public: long id; };

class RGE_Static_Object {
public:
    virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0C();
    virtual void vf10(); virtual void vf14(); virtual void vf18(); virtual void vf1C();
    virtual void vf20(); virtual void vf24(); virtual void vf28(); virtual void vf2C();
    virtual void vf30(); virtual void vf34(); virtual void vf38(); virtual void vf3C();
    virtual void vf40(); virtual void vf44(); virtual void vf48(); virtual void vf4C();
    virtual void vf50(); virtual void vf54(); virtual void vf58(); virtual void vf5C();
    virtual void vf60(); virtual void vf64(); virtual void vf68(); virtual void vf6C();
    virtual void vf70(); virtual void vf74(); virtual void vf78(); virtual void vf7C();
    virtual void vf80(); virtual void vf84(); virtual void vf88(); virtual void vf8C();
    virtual void vf90(); virtual void vf94(); virtual void vf98(); virtual void vf9C();
    virtual void vfA0(); virtual void vfA4(); virtual void vfA8(); virtual void vfAC();
    virtual void vfB0(); virtual void vfB4(); virtual void vfB8(); virtual void vfBC();
    virtual void vfC0(); virtual void vfC4(); virtual void vfC8(); virtual void vfCC();
    virtual void vfD0(); virtual void vfD4(); virtual void vfD8(); virtual void vfDC();
    virtual void vfE0(); virtual void vfE4(); virtual void vfE8(); virtual void vfEC();
    virtual void vfF0(); virtual void vfF4(); virtual void vfF8(); virtual void vfFC();
    virtual void vf100(); virtual void vf104(); virtual void vf108(); virtual void vf10C();
    virtual void vf110(); virtual void vf114(); virtual void vf118(); virtual void vf11C();
    virtual void vf120(); virtual void vf124(); virtual void vf128(); virtual void vf12C();
    virtual void vf130(); virtual void vf134(); virtual void vf138(); virtual void vf13C();
    virtual void vf140(); virtual void vf144(); virtual void vf148();
    virtual void vf14C(float x, float y, int z, int one);
};

class RGE_Game_World;
class RGE_Command {
public:
    char gap_00[0x4];
    RGE_Game_World* world;
    RGE_Static_Object* get_obj(RGE_Obj_Info obj);
};

class TRIBE_Command_Attack_Ground {
public:
    unsigned char command;
    unsigned char unit_num;
    unsigned char gap_02[0x2];
    float location_x;
    float location_y;
};

class TRIBE_Command : public RGE_Command {
public:
    void do_command_attack_ground(TRIBE_Command_Attack_Ground* param_1);
};

void TRIBE_Command::do_command_attack_ground(TRIBE_Command_Attack_Ground* param_1)
{
    RGE_Static_Object* pRVar2;
    unsigned int uVar3;
    TRIBE_Command_Attack_Ground* pTVar4;

    pTVar4 = param_1 + 1;
    uVar3 = (unsigned int)param_1->unit_num;
    if ((int)uVar3 <= 0)
        goto done;
    do {
        pRVar2 = this->get_obj(*(RGE_Obj_Info*)pTVar4);
        if (pRVar2 != 0)
            pRVar2->vf14C(param_1->location_x, param_1->location_y, 0, 1);
        pTVar4 = (TRIBE_Command_Attack_Ground*)((char*)pTVar4 + 4);
        uVar3--;
    } while (uVar3 != 0);
done:
    return;
}

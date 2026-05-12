// VA: 00430A90 RGE_Combat_Object::attack(float,float,float,int)
// PDB source: com_obj.cpp lines 827-869
// attempt 1: natural new RGE_Action_Attack with repeated current-action checks and EH new frame.
// attempt 2: action type virtual lives at +0x18 and attack ctor wants master short +0x12A, not +0x13E.
// attempt 3: object add_action virtual is at vtable +0x208, not +0x204.

class RGE_Action {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual short action_type(); // +0x18
    float targetX();
};

class RGE_Action_List {
public:
    unsigned char have_action();
    RGE_Action* get_action();
    void delete_list();
};

class RGE_Master_Combat_Object {
public:
    char gap_000[0x114];
    float field_114;
    char gap_118[0x0C];
    short field_124;
    char gap_126[4];
    short field_12A;
    char gap_12C[0x0C];
    float field_138;
};

class RGE_Action_Attack {
public:
    char gap_00[0x5C];
    RGE_Action_Attack(void* obj, float x, float y, float z, void* a, void* b, void* c, float f1, float f2, short s1, short s2);
};

class RGE_Combat_Object {
public:
    virtual void v000(); virtual void v004(); virtual void v008(); virtual void v00C();
    virtual void v010(); virtual void v014(); virtual void v018(); virtual void v01C();
    virtual void v020(); virtual void v024(); virtual void v028(); virtual void v02C();
    virtual void v030(); virtual void v034(); virtual void v038(); virtual void v03C();
    virtual void v040(); virtual void v044(); virtual void v048(); virtual void v04C();
    virtual void v050(); virtual void v054(); virtual void v058(); virtual void v05C();
    virtual void v060(); virtual void v064(); virtual void v068(); virtual void v06C();
    virtual void v070(); virtual void v074(); virtual void v078(); virtual void v07C();
    virtual void v080(); virtual void v084(); virtual void v088(); virtual void v08C();
    virtual void v090(); virtual void v094(); virtual void v098(); virtual void v09C();
    virtual void v0A0(); virtual void v0A4(); virtual void v0A8(); virtual void v0AC();
    virtual void v0B0(); virtual void v0B4(); virtual void v0B8(); virtual void v0BC();
    virtual void v0C0(); virtual void v0C4(); virtual void v0C8(); virtual void v0CC();
    virtual void v0D0(); virtual void v0D4(); virtual void v0D8(); virtual void v0DC();
    virtual void v0E0(); virtual void v0E4(); virtual void v0E8(); virtual void v0EC();
    virtual void v0F0(); virtual void v0F4(); virtual void v0F8(); virtual void v0FC();
    virtual void v100(); virtual void v104(); virtual void v108(); virtual void v10C();
    virtual void v110(); virtual void v114(); virtual void v118(); virtual void v11C();
    virtual void v120(); virtual void v124(); virtual void v128(); virtual void v12C();
    virtual void v130(); virtual void v134(); virtual void v138(); virtual void v13C();
    virtual void v140(); virtual void v144(); virtual void v148(); virtual void v14C();
    virtual void v150(); virtual void v154(); virtual void v158(); virtual void v15C();
    virtual void v160(); virtual void v164(); virtual void v168(); virtual void v16C();
    virtual void v170(); virtual void v174(); virtual void v178(); virtual void v17C();
    virtual void v180(); virtual void v184(); virtual void v188(); virtual void v18C();
    virtual void v190(); virtual void v194(); virtual void v198(); virtual void v19C();
    virtual void v1A0(); virtual void v1A4(); virtual void v1A8(); virtual void v1AC();
    virtual void v1B0(); virtual void v1B4(); virtual void v1B8(); virtual void v1BC();
    virtual void v1C0(); virtual void v1C4(); virtual void v1C8(); virtual void v1CC();
    virtual void v1D0(); virtual void v1D4(); virtual void v1D8(); virtual void v1DC();
    virtual void v1E0(); virtual void v1E4(); virtual void v1E8(); virtual void v1EC();
    virtual void v1F0(); virtual void v1F4(); virtual void v1F8(); virtual void v1FC();
    virtual void v200(); virtual void v204();
    virtual void add_action(RGE_Action_Attack* action); // +0x208

    char gap_004[4];
    RGE_Master_Combat_Object* master; // +0x08
    char gap_00C[0x178];
    RGE_Action_List* action_list;     // +0x184

    virtual int attack(float x, float y, float z, int force);
};

int RGE_Combat_Object::attack(float x, float y, float z, int force)
{
    if (force == 0) {
        if (this->action_list->have_action() == 1) {
            if (this->action_list->get_action()->targetX() == x) {
                if (this->action_list->get_action()->targetX() == y) {
                    if (this->action_list->get_action()->targetX() == z) {
                        if (this->action_list->get_action()->action_type() == 9) {
                            return 1;
                        }
                        if (this->action_list->get_action()->action_type() == 7) {
                            return 1;
                        }
                    }
                }
            }
        }
    }

    RGE_Action_Attack* action = new RGE_Action_Attack(this, x, y, z, 0, 0, 0,
        this->master->field_114, this->master->field_138, this->master->field_124, this->master->field_12A);
    if (action == 0) {
        return 0;
    }
    this->action_list->delete_list();
    this->add_action(action);
    return 1;
}

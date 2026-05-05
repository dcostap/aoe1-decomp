// attempt 1: natural TRIBE_Combat_Object::heal action replacement pattern
class RGE_Static_Object { public: char gap_00[0x38]; int x; int y; int z; };
class RGE_Game_World { public: RGE_Static_Object* object(int id); };
class GameShell { public: char gap_00[0x3C]; RGE_Game_World* world; };
class RGE_Action {
public:
    virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0C(); virtual void vf10(); virtual void vf14();
    virtual short action_id();
    virtual void vf1C(); virtual void vf20(); virtual void vf24(); virtual void vf28(); virtual void vf2C(); virtual void vf30();
    virtual void set_target(RGE_Static_Object*, int, int, int);
    virtual void vf38(); virtual void vf3C(); virtual void vf40(); virtual void vf44(); virtual void vf48();
    virtual RGE_Static_Object* target_obj();
};
class RGE_Action_List { public: unsigned char have_action(); RGE_Action* get_action(); void clear(); };
class TRIBE_Action_Heal : public RGE_Action { public: TRIBE_Action_Heal(void* owner, RGE_Action* obj, RGE_Static_Object* target); };
class TRIBE_Combat_Object {
public:
    virtual void vf000(); virtual void vf004(); virtual void vf008(); virtual void vf00C(); virtual void vf010(); virtual void vf014(); virtual void vf018(); virtual void vf01C();
    virtual void vf020(); virtual void vf024(); virtual void vf028(); virtual void vf02C(); virtual void vf030(); virtual void vf034(); virtual void vf038(); virtual void vf03C();
    virtual void vf040(); virtual void vf044(); virtual void vf048(); virtual void vf04C(); virtual void vf050(); virtual void vf054(); virtual void vf058(); virtual void vf05C();
    virtual void vf060(); virtual void vf064(); virtual void vf068(); virtual void vf06C(); virtual void vf070(); virtual void vf074(); virtual void vf078(); virtual void vf07C();
    virtual void vf080(); virtual void vf084(); virtual void vf088(); virtual void vf08C(); virtual void vf090(); virtual void vf094(); virtual void vf098(); virtual void vf09C();
    virtual void vf0A0(); virtual void vf0A4(); virtual void vf0A8(); virtual void vf0AC(); virtual void vf0B0(); virtual void vf0B4(); virtual void vf0B8(); virtual void vf0BC();
    virtual void vf0C0(); virtual void vf0C4(); virtual void vf0C8(); virtual void vf0CC(); virtual void vf0D0(); virtual void vf0D4(); virtual void vf0D8(); virtual void vf0DC();
    virtual void vf0E0(); virtual void vf0E4(); virtual void vf0E8(); virtual void vf0EC(); virtual void vf0F0(); virtual void vf0F4(); virtual void vf0F8(); virtual void vf0FC();
    virtual void vf100(); virtual void vf104(); virtual int add_action(RGE_Action*); virtual RGE_Action* make_action(RGE_Static_Object*, int, int, int);
    char gap_004[8]; GameShell* game; char gap_010[0x174]; RGE_Action_List* action_list;
    int heal(int id, int flag);
};

int TRIBE_Combat_Object::heal(int id, int flag) {
    RGE_Static_Object* target = this->game->world->object(id);
    if (target == 0) return 0;
    if (flag == 0 && this->action_list->have_action() == 1 && this->action_list->get_action()->target_obj() == target && this->action_list->get_action()->action_id() == 0x69) return 1;
    if (this->action_list->have_action() == 1 && this->action_list->get_action()->action_id() == 0x69) {
        this->action_list->get_action()->set_target(target, target->x, target->y, target->z);
        return 1;
    }
    RGE_Action* old = this->make_action(target, target->x, target->y, target->z);
    if (old == 0) return 0;
    TRIBE_Action_Heal* action = new TRIBE_Action_Heal(this, old, target);
    if (action == 0) return 0;
    this->action_list->clear();
    this->add_action(action);
    return 1;
}

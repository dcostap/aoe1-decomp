#ifndef ACT_ATAK_CONTEXT_H
class RGE_Sprite;

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char gap_04[0x14];
    RGE_Sprite* sprite;
    char gap_1C[0xA0];
};

class RGE_Master_Action_Object : public RGE_Master_Static_Object {
public:
    RGE_Sprite* move_sprite;
    char gap_C0[0x3C];
};

class RGE_Master_Combat_Object : public RGE_Master_Action_Object {
public:
    RGE_Sprite* fight_sprite;
};

class RGE_Action_Object {
public:
    virtual void vf00(void);

    int gap_04;
    RGE_Master_Static_Object* master_obj;
};

class RGE_Task {
public:
    char gap_00[0x34];
    RGE_Sprite* move_sprite;
    RGE_Sprite* work_sprite;
    RGE_Sprite* work_sprite2;
};

class RGE_Action_Attack {
public:
    virtual void vf00(void);

    char gap_04[0x04];
    RGE_Action_Object* obj;
    char gap_0C[0x34];
    RGE_Sprite* move_sprite;
    RGE_Sprite* fight_sprite;
    RGE_Sprite* wait_sprite;

    void copy_obj_sprites(RGE_Master_Action_Object* param_1, RGE_Task* param_2, RGE_Task* param_3);
};
#endif

void RGE_Action_Attack::copy_obj_sprites(RGE_Master_Action_Object* param_1, RGE_Task* param_2, RGE_Task* param_3) {
    if (this->move_sprite != 0) {
        if ((param_2 != 0) && (param_3 != 0) && (this->move_sprite == param_2->move_sprite)) {
            this->move_sprite = param_3->move_sprite;
        } else if (this->move_sprite ==
                   ((RGE_Master_Action_Object*)this->obj->master_obj)->move_sprite) {
            this->move_sprite = param_1->move_sprite;
        }
    }

    if (this->fight_sprite != 0) {
        if ((param_2 != 0) && (param_3 != 0) && (this->fight_sprite == param_2->work_sprite)) {
            this->fight_sprite = param_3->work_sprite;
        } else if ((param_2 != 0) && (param_3 != 0) && (this->fight_sprite == param_2->work_sprite2)) {
            this->fight_sprite = param_3->work_sprite2;
        } else if (this->fight_sprite ==
                   ((RGE_Master_Combat_Object*)this->obj->master_obj)->fight_sprite) {
            this->fight_sprite =
                ((RGE_Master_Combat_Object*)param_1)->fight_sprite;
        }
    }

    if (this->wait_sprite != 0) {
        if ((param_2 != 0) && (param_3 != 0) && (this->wait_sprite == param_2->work_sprite)) {
            this->wait_sprite = param_3->work_sprite;
            return;
        }
        if ((param_2 != 0) && (param_3 != 0) && (this->wait_sprite == param_2->work_sprite2)) {
            this->wait_sprite = param_3->work_sprite2;
            return;
        }
        if (this->wait_sprite == this->obj->master_obj->sprite) {
            this->wait_sprite = param_1->sprite;
        }
    }
}

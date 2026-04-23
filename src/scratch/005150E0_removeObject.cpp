// first pass: forward to the base removeObject, then notify playerAI unless the object is a village center or has a negative id
// tried direct field access, a local AI alias, and a register hint; the stable mismatch stayed at the playerAI load / vcall basin (first mismatch offset 32)

class RGE_Static_Object;
class RGE_Object_Node;
class TribeMainDecisionAIModule;

class RGE_Player {
public:
    virtual void removeObject(RGE_Static_Object* object, int param_2, int param_3, RGE_Object_Node* node);
};

class TRIBE_Player : public RGE_Player {
public:
    char gap_04[0x234];
    TribeMainDecisionAIModule* playerAI;

    virtual void removeObject(RGE_Static_Object* object, int param_2, int param_3, RGE_Object_Node* node);
};

class RGE_Master_Object {
public:
    char gap_00[0x14];
    unsigned short object_group;
};

class RGE_Static_Object {
public:
    char gap_00[0x8];
    RGE_Master_Object* master_obj;
    int id;
};

class TribeMainDecisionAIModule {
public:
    void** vftable;
};

void TRIBE_Player::removeObject(RGE_Static_Object* object, int param_2, int param_3, RGE_Object_Node* node) {
    RGE_Player::removeObject(object, param_2, param_3, node);
    register TribeMainDecisionAIModule* ai = this->playerAI;
    if (ai != 0 && object->master_obj->object_group != 0xB && object->id >= 0) {
        ((void (*)(TribeMainDecisionAIModule*, int))ai->vftable[0x11])(ai, object->id);
    }
}

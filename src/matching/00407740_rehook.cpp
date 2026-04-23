class RGE_Static_Object {
public:
    char gap_00[0x4];
    int id;
    RGE_Static_Object* get_object_pointer(int id);
};

class RGE_Action_List;

class RGE_Action {
public:
    char gap_00[0x8];
    RGE_Static_Object* obj;
    char gap_0C[0x4];
    RGE_Static_Object* target_obj;
    RGE_Static_Object* target_obj2;
    int target_id;
    int target2_id;
    char gap_20[0x14];
    RGE_Action_List* sub_actions;

    void rehook(void);
};

class RGE_Action_List {
public:
    void rehook(void);
};

void RGE_Action::rehook(void) {
    if (this->target_obj != 0) {
        this->target_obj = this->obj->get_object_pointer((int)this->target_obj);
        if (this->target_obj != 0) {
            this->target_id = this->target_obj->id;
        }
    }
    if (this->target_obj2 != 0) {
        this->target_obj2 = this->obj->get_object_pointer((int)this->target_obj2);
        if (this->target_obj2 != 0) {
            this->target2_id = this->target_obj2->id;
        }
    }
    if (this->sub_actions != 0) {
        this->sub_actions->rehook();
    }
}

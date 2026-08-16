class RGE_Action_List {
public:
    void delete_list();
};

class RGE_Static_Object {
public:
    virtual void recycle_out_of_game();
};

class RGE_Action_Object : public RGE_Static_Object {
public:
    char gap_04[0x180];
    RGE_Action_List* actions;

    virtual void recycle_out_of_game();
};

void RGE_Action_Object::recycle_out_of_game() {
    if (this->actions) {
        this->actions->delete_list();
    }
    RGE_Static_Object::recycle_out_of_game();
}

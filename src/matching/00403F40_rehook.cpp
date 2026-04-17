class RGE_Action {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void rehook(void);
};

class RGE_Action_Node {
public:
    RGE_Action* action;
    RGE_Action_Node* next;
};

class RGE_Action_List {
public:
    char gap_00[8];
    RGE_Action_Node* list;

    void rehook(void);
};

void RGE_Action_List::rehook(void) {
    RGE_Action_Node* node;

    node = this->list;
    while (node != 0) {
        node->action->rehook();
        node = node->next;
    }
}

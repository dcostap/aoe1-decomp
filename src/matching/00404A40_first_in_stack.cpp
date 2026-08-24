#ifndef ACT_MAKE_CONTEXT_H
class RGE_Action_Make_Node {
public:
    char gap_00[0x14];
    short value;
};

class RGE_Action_Make_Target {
public:
    char gap_00[0x48];
    short current;

    virtual int vf00(void);
    virtual int vf04(void);
    virtual int vf08(void);
    virtual int vf0C(void);
    virtual int vf10(void);
    virtual int vf14(void);
    virtual int vf18(void);
    virtual int vf1C(void);
    virtual int vf20(void);
    virtual int vf24(void);
    virtual int vf28(void);
    virtual int vf2C(void);
    virtual int vf30(void);
    virtual int vf34(void);
    virtual int vf38(void);
    virtual int vf3C(void);
    virtual int vf40(void);
    virtual int vf44(void);
    virtual int vf48(void);
    virtual int vf4C(void);
    virtual int vf50(void);
    virtual int vf54(void);
    virtual int vf58(void);
    virtual int vf5C(void);
    virtual int vf60(void);
    virtual int vf64(void);
    virtual int vf68(void);
    virtual int vf6C(void);
    virtual int vf70(void);
    virtual int vf74(void);
    virtual int vf78(void);
    virtual int vf7C(void);
    virtual void notify_value(short value, int zero);
};

class RGE_Action_Make {
public:
    virtual int vf00(void);
    virtual int vf04(void);
    virtual int vf08(void);
    virtual int vf0C(void);
    virtual int vf10(void);
    virtual int vf14(void);
    virtual int vf18(void);
    virtual int vf1C(void);
    virtual int vf20(void);
    virtual int vf24(void);
    virtual int vf28(void);
    virtual int vf2C(void);
    virtual int vf30(void);
    virtual int vf34(void);
    virtual int vf38(void);
    virtual int vf3C(void);
    virtual int vf40(void);
    virtual int vf44(void);
    virtual int vf48(void);
    virtual int vf4C(void);
    virtual int vf50(void);
    virtual int vf54(void);
    virtual int vf58(void);
    virtual void set_state(int state);
    char gap_04[4];
    RGE_Action_Make_Target* target;
    char gap_0C[0x24];
    RGE_Action_Make_Node* node;

    virtual void first_in_stack(unsigned char value);
};

void RGE_Action_Make::first_in_stack(unsigned char value) {
    short node_value;

    this->set_state(6);
    node_value = this->node->value;
    if (node_value >= 0 && this->target->current != node_value) {
        this->target->notify_value(node_value, 0);
    }
}
#else
void RGE_Action_Make::first_in_stack(unsigned char) {
    short attribute_type;

    this->set_state(6);
    attribute_type = this->task->attribute_type;
    if (attribute_type >= 0 && this->obj->attribute_type_held != attribute_type) {
        this->obj->set_attribute(attribute_type, 0);
    }
}
#endif

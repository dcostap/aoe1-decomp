class RGE_Action;
class RGE_Task;
class RGE_Master_Action_Object;

class RGE_Action_List {
public:
    virtual void vf000(void);
    virtual RGE_Action* vf004(RGE_Task* task, int flag, float x, float y, float z);
};

class RGE_Action_Object {
public:
    virtual void vf000(void);
    virtual void vf004(void);
    virtual void vf008(void);
    virtual void vf00C(void);
    virtual void vf010(void);
    virtual void vf014(void);
    virtual void vf018(void);
    virtual void vf01C(void);
    virtual void vf020(void);
    virtual void vf024(void);
    virtual void vf028(void);
    virtual void vf02C(void);
    virtual void vf030(void);
    virtual void vf034(void);
    virtual void vf038(void);
    virtual void vf03C(void);
    virtual void vf040(void);
    virtual void vf044(void);
    virtual void vf048(void);
    virtual void vf04C(void);
    virtual void vf050(void);
    virtual void vf054(void);
    virtual void vf058(void);
    virtual void vf05C(void);
    virtual void vf060(void);
    virtual void vf064(void);
    virtual void vf068(void);
    virtual void vf06C(void);
    virtual void vf070(void);
    virtual void vf074(void);
    virtual void vf078(void);
    virtual void vf07C(void);
    virtual void vf080(void);
    virtual void vf084(void);
    virtual void vf088(void);
    virtual void vf08C(void);
    virtual void vf090(void);
    virtual void vf094(void);
    virtual void vf098(void);
    virtual void vf09C(void);
    virtual void vf0A0(void);
    virtual void vf0A4(void);
    virtual void vf0A8(void);
    virtual void vf0AC(void);
    virtual void vf0B0(void);
    virtual void vf0B4(void);
    virtual void vf0B8(void);
    virtual void vf0BC(void);
    virtual void vf0C0(void);
    virtual void vf0C4(void);
    virtual void vf0C8(void);
    virtual void vf0CC(void);
    virtual void vf0D0(void);
    virtual void vf0D4(void);
    virtual void vf0D8(void);
    virtual void vf0DC(void);
    virtual void vf0E0(void);
    virtual void vf0E4(void);
    virtual void vf0E8(void);
    virtual void vf0EC(void);
    virtual void vf0F0(void);
    virtual void vf0F4(void);
    virtual void vf0F8(void);
    virtual void vf0FC(void);
    virtual void vf100(void);
    virtual void vf104(void);
    virtual void vf108(void);
    virtual void vf10C(void);
    virtual void vf110(void);
    virtual void vf114(void);
    virtual void vf118(void);
    virtual void vf11C(void);
    virtual void vf120(void);
    virtual void vf124(void);
    virtual void vf128(void);
    virtual void vf12C(void);
    virtual void vf130(void);
    virtual void vf134(void);
    virtual void vf138(void);
    virtual void vf13C(void);
    virtual void vf140(void);
    virtual void vf144(void);
    virtual void vf148(void);
    virtual void vf14C(void);
    virtual void vf150(void);
    virtual void vf154(void);
    virtual void vf158(void);
    virtual void vf15C(void);
    virtual void vf160(void);
    virtual void vf164(void);
    virtual void vf168(void);
    virtual void vf16C(void);
    virtual void vf170(void);
    virtual void vf174(void);
    virtual void vf178(void);
    virtual void vf17C(void);
    virtual void vf180(void);
    virtual void vf184(void);
    virtual void vf188(void);
    virtual void vf18C(void);
    virtual void vf190(void);
    virtual void vf194(void);
    virtual void vf198(void);
    virtual void vf19C(void);
    virtual void vf1A0(void);
    virtual void vf1A4(void);
    virtual void vf1A8(void);
    virtual void vf1AC(void);
    virtual void vf1B0(void);
    virtual void vf1B4(void);
    virtual void vf1B8(void);
    virtual void vf1BC(void);
    virtual void vf1C0(void);
    virtual void vf1C4(void);
    virtual void vf1C8(void);
    virtual void vf1CC(void);
    virtual void vf1D0(void);
    virtual void vf1D4(void);
    virtual void vf1D8(void);
    virtual void vf1DC(void);
    virtual void vf1E0(void);
    virtual void vf1E4(void);
    virtual void vf1E8(void);
    virtual void vf1EC(void);
    virtual void vf1F0(void);
    virtual void vf1F4(void);
    virtual void vf1F8(void);
    virtual void vf1FC(void);
    virtual void vf200(void);
    virtual void vf204(void);
    virtual void vf208(RGE_Action* action);

    char gap_04[0x04];
    RGE_Master_Action_Object* master_obj;
    char gap_0C[0x178];
    RGE_Action_List* actions;

    void set_task(short task_id);
};

class RGE_Master_Action_Object {
public:
    RGE_Task* get_task(short task_id);
};

void RGE_Action_Object::set_task(short task_id) {
    RGE_Task* task;
    RGE_Action* action;

    task = this->master_obj->get_task(task_id);
    if (task != 0) {
        action = this->actions->vf004(task, 0, -1.0f, -1.0f, -1.0f);
        if (action != 0) {
            this->vf208(action);
        }
    }
}

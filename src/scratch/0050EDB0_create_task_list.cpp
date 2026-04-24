// tried the direct `new TRIBE_Task_List` wrapper first; it compiled too small and missed the EH/new-expression basin
// tried adding explicit ctor/dtor surfaces to enlarge the basin; the extractor started landing on the wrong helper-shaped function at offset 0
// remaining gap: exact /GX-style new/ctor prolog and extraction order around the wrapper helper
class RGE_Task_List {
public:
    virtual void destroy();
    int list;
    short list_num;

    RGE_Task_List();
    virtual ~RGE_Task_List();
};

class TRIBE_Task_List : public RGE_Task_List {
public:
    TRIBE_Task_List() : RGE_Task_List() {
        this->list_num = 0;
        this->list = 0;
    }
    virtual ~TRIBE_Task_List() {
    }
};

class TRIBE_Master_Combat_Object {
public:
    virtual RGE_Task_List* create_task_list();
};

RGE_Task_List* TRIBE_Master_Combat_Object::create_task_list() {
    return new TRIBE_Task_List;
}

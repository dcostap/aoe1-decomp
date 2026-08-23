// The PDB owner is a nonpolymorphic list. The constructor clears list.
#ifndef RGE_STAT_OBJ_SHARED_CONTEXT
class RGE_Check_List {
public:
    void* list;
    RGE_Check_List();
};

#endif

RGE_Check_List::RGE_Check_List() {
    this->list = 0;
}

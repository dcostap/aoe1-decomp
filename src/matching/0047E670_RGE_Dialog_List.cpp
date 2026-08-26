#ifndef RDLG_LST_TU_CONTEXT
class BaseClass {
public:
    virtual ~BaseClass();
    BaseClass(int param);
};

class RGE_Dialog_List : public BaseClass {
public:
    virtual ~RGE_Dialog_List();
    RGE_Dialog_List(int param);
};
#endif

#ifdef RDLG_LST_TU_CONTEXT
RGE_Dialog_List::RGE_Dialog_List(char* name) : TListDialog(name) {
}
#else
RGE_Dialog_List::RGE_Dialog_List(int param) : BaseClass(param) {
}
#endif

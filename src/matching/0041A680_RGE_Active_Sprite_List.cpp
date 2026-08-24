// STATUS: EXACT emitted owner recovery; remains in scratch until promotion.
// FLAGS: /nologo /c /O2 /Oy from config/flags/default.rsp.
// BINARY NOTE: 0041A680 stores the class vptr, then tail-jumps to delete_list.
// BINARY NOTE: 0041A660 is the compiler-generated deleting destructor.
// OBSERVED: 0041A680 MATCH, 11/11 bytes, 0.0000%, owner symbol validated.
// GENERATED: 0041A660 MATCH, 30/30 bytes, 0.0000%, decorated symbol validated.
// BLOCKED: module registration needs main-agent review of the complete TU owner set.

#ifndef ASP_LIST_SHARED_CONTEXT
class RGE_Active_Sprite_List {
public:
    virtual ~RGE_Active_Sprite_List();
    void delete_list();
};
#endif

RGE_Active_Sprite_List::~RGE_Active_Sprite_List() {
    delete_list();
}

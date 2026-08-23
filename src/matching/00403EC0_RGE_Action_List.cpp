class RGE_Action_List {
public:
    virtual ~RGE_Action_List();
    void delete_list();
};

// BINARY NOTE: The shipped destructor restores its vptr, then tail-jumps to delete_list.
RGE_Action_List::~RGE_Action_List() {
    delete_list();
}

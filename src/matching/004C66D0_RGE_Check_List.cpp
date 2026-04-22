extern "C" void __cdecl free(void* block);

class RGE_Check_Node {
public:
    char gap_00[0x10];
    RGE_Check_Node* next;
};

class RGE_Check_List {
public:
    RGE_Check_Node* list;

    ~RGE_Check_List();
};

RGE_Check_List::~RGE_Check_List() {
    RGE_Check_Node* next;

    while (this->list != 0) {
        next = this->list->next;
        free(this->list);
        this->list = next;
    }
}

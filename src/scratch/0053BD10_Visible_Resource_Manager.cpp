// From vis_unit.cpp

void __cdecl operator_delete(void* ptr);

class Visible_Resource_Manager {
public:
    void** vtable;
    void* field_04;
    void* field_08;
    char gap_0C[4];
    int count;

    ~Visible_Resource_Manager();
};

Visible_Resource_Manager::~Visible_Resource_Manager() {
    int i;
    for (i = 0; i < this->count; i++) {
        void* ptr = this->vtable[i];
        if (ptr) operator_delete(ptr);
    }
    if (this->vtable) operator_delete(this->vtable);
    if (this->field_04) operator_delete(this->field_04);
    if (this->field_08) operator_delete(this->field_08);
}

// STATUS: scratch
void __cdecl operator_delete(void* p);

class RGE_Command {
public:
    int vtable;
    int field_04;
    void* field_08;
    char gap_0C[0x08];
    int field_14;

    ~RGE_Command();
};

RGE_Command::~RGE_Command() {
    *(int*)this = 0x56F4C0;
    this->field_04 = 0;
    this->field_14 = 0;
    void* p = this->field_08;
    if (p != 0) {
        operator_delete(p);
    }
}
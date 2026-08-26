#ifndef COMMAND_TU_CONTEXT
void __cdecl operator_delete(void* p);

class RGE_Command {
public:
    virtual ~RGE_Command();
    int field_04;
    void* field_08;
    char gap_0C[0x08];
    int field_14;

    ~RGE_Command();
};
#endif

// ABI NOTE: 00433D70 is a compiler-generated scalar deleting destructor.
// VC5 defines ??_G here and leaves ??_E as a weak external. The original
// FPO record calls the same body vector deleting, but cvdump and the original
// vtable assign ownership to scalar deleting. Do not add synthetic new[] use.

RGE_Command::~RGE_Command() {
    this->field_04 = 0;
    this->field_14 = 0;
    void* p = this->field_08;
    if (p != 0) {
        operator_delete(p);
    }
}

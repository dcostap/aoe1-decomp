#ifndef COMMAND_TU_CONTEXT
class RGE_Command {
public:
    virtual ~RGE_Command();
    int field_04;
    void* field_08;
    char gap_0C[0x08];
    int field_14;
};
#endif

extern "C" void __cdecl free(void* p);

// ABI NOTE: 00433D70 is a compiler-generated scalar deleting destructor.
// VC5 defines ??_G here and leaves ??_E as a weak external. The original
// FPO record calls the same body vector deleting, but cvdump and the original
// vtable assign ownership to scalar deleting. Do not add synthetic new[] use.
// TU NOTE: Binding cleanup to CRT free makes this owner exact, but a fresh
// grouped sweep regresses one registered Command.cpp owner. Keep this form
// until the shared compiler context explains that regression.
// BINARY NOTE: The direct cleanup target is CRT free, not operator_delete.

RGE_Command::~RGE_Command() {
    this->field_04 = 0;
    this->field_14 = 0;
    void* p = this->field_08;
    if (p != 0) {
        free(p);
    }
}

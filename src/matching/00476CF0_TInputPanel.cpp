// 00476CF0 TInputPanel::~TInputPanel
// try 6: ordinary C++ operator delete declaration, virtual base, no extra locals.
void operator delete(void* p);
class TTextPanel { public: char gap_00[0x184]; virtual ~TTextPanel(); };
class TInputPanel : public TTextPanel {
public:
    char pad_188[0x18]; char* input_buffer; char* input_buffer1; char* input_buffer2; virtual ~TInputPanel();
};
TInputPanel::~TInputPanel() {
    if (this->input_buffer1 != 0) { delete this->input_buffer1; this->input_buffer1 = 0; }
    if (this->input_buffer2 != 0) { delete this->input_buffer2; this->input_buffer2 = 0; }
    this->input_buffer = 0;
    *(int*)((char*)this + 0x80) = 1;
}

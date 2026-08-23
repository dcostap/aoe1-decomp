// 00477990 TInputPanel::set_text(char**, short)
// Pnl_inp.cpp:560; body 00477990-00477992. The shipped body is only ret 8.
// BINARY NOTE: The PDB-qualified symbol is virtual and uses char** plus short.
// Keep this overload empty: it has no input-state access, call, or cleanup work.

class TInputPanel {
public:
    virtual ~TInputPanel();
    virtual void set_text(char**, short);
};

void TInputPanel::set_text(char**, short) {}

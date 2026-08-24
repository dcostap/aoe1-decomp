#ifndef PNL_TXT_TU_CONTEXT
class TTextPanel {
public:
    void set_line(long line);
    void setCurrentLineNumber(int p);
};
#endif

// BINARY NOTE: The shipped helper forwards directly to set_line(long).
void TTextPanel::setCurrentLineNumber(int p) { this->set_line(p); }

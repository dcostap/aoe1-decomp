#ifndef PNL_TXT_TU_CONTEXT
class TTextPanel {
public:
    void get_text();
    void currentLine();
};
#endif

void TTextPanel::currentLine() { this->get_text(); }

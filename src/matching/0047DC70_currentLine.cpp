#ifndef PNL_TXT_TU_CONTEXT
class TTextPanel {
public:
    char* get_text();
    char* currentLine();
};
#endif

char* TTextPanel::currentLine() { return this->get_text(); }

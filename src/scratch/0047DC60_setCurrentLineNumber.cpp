#ifndef PNL_TXT_TU_CONTEXT
class TTextPanel {
public:
    void target_func(int p0);
    void setCurrentLineNumber(int p);
};
#endif

void TTextPanel::setCurrentLineNumber(int p) { this->target_func(p); }

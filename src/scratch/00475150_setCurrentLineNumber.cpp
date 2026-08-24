#ifndef PNL_DROP_CONTEXT
class TDropDownPanel {
public:
    void target_func(int p0);
    void setCurrentLineNumber(int p);
};
#endif

void TDropDownPanel::setCurrentLineNumber(int p) { this->target_func(p); }

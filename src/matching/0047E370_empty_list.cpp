#ifndef PNL_TXT_TU_CONTEXT
class TTextPanel {
public:
    void free_text();
    void empty_list();
};
#endif

void TTextPanel::empty_list() { this->free_text(); }

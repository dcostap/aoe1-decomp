class TDropDownPanel {
public:
    void target_func(int p0);
    void setCurrentLineNumber(int p);
};

void TDropDownPanel::setCurrentLineNumber(int p) { this->target_func(p); }

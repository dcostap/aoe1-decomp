// VA: 00475A30 update_text (192B)
// pnl_edit.cpp

class TEditPanel {
public:
    virtual ~TEditPanel();
    char gap0[0xF4];
    int field_F4;
    
    void update_text();
};

void TEditPanel::update_text() {
}

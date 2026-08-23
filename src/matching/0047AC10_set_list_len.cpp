// 0047AC10 TScrollBarPanel::set_list_len
// PDB: Pnl_scbr.cpp lines 258-261
class TScrollBarPanel {
public:
    char pad[0xF8];
    long list_len;
    void set_tab_pos(long position);
    void set_list_len(long len, long position);
};

void TScrollBarPanel::set_list_len(long len, long position) {
    this->list_len = len;
    this->set_tab_pos(position);
}

// VA: 0043C2B0 action (1659B)
// dlg_conf.cpp

class TribeConfigDialog {
public:
    char gap4[0x540];
    int field_544;
    
    int action(int a1, int a2, int a3);
};

int TribeConfigDialog::action(int a1, int a2, int a3) {
    char buf[256];
    
    if (!a1) return 0;
    
    if (a1 == field_544) {
        return 1;
    }
    return 0;
}

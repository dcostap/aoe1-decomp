// VA: 0043C0C0 ~TribeConfigDialog dtor (485B)
// dlg_conf.cpp
// EH frame (/GX)

class TribeConfigDialog {
public:
    int* vtable;
    char gap4[0x540];
    int field_544;
    
    ~TribeConfigDialog();
};

TribeConfigDialog::~TribeConfigDialog() {
    vtable = (int*)0x55D008;
    if (field_544) {
        field_544 = 0;
    }
}

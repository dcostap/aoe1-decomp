// VA: 0043FFF0 TMessageDialog::setup (wrapper)
// Dlg_msg.cpp lines 172-176

// attempt 1: wrapper that resolves string, calls main setup
// ret 24h

#ifndef DLG_MSG_CANONICAL_TU
class TPanel {
public:
    virtual ~TPanel();
    int get_string(int id, char* buffer, int max_len);
};

class TEasy_Panel : public TPanel {
public:
    virtual ~TEasy_Panel();
};

class TDialogPanel : public TEasy_Panel {
public:
    virtual ~TDialogPanel();
};

class TMessageDialog : public TDialogPanel {
public:
    TPanel* parent;
    char gap_44[0x450];
    TPanel* text;            // +0x494
    TPanel* button[3];       // +0x498, +0x49C, +0x4A0

    virtual ~TMessageDialog();
    long setup(TPanel* p1, char* p2, long p3, long p4, long p5,
        unsigned char p6, int p7, long p8, long p9);
};
#endif

long TMessageDialog::setup(TPanel* p1, char* p2, long p3, long p4, long p5,
    unsigned char p6, int p7, long p8, long p9) {
    
    char str[256];
    TPanel::get_string(p7, str, 0x100);
    
    return TMessageDialog::setup(p1, p2, p3, p4, p5, p6, (int)str, p8, p9);
}

class TMessageDialog {
public:
    virtual ~TMessageDialog();
    int key_down_action(int p0, int p1, int p2, int p3, int p4);
};

int TMessageDialog::key_down_action(int p0, int p1, int p2, int p3, int p4) { return 0; }

class TButtonPanel {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void vf18(void);
    virtual void vf1C(void);
    virtual void vf20(int param_1);

    char gap_04[0xF0];
    long id[9];
    char gap_118[0xDC];
    short num_states;
    short cur_state;

    void set_state_by_id(long id);
};

void TButtonPanel::set_state_by_id(long target_id) {
    int i;

    for (i = 0; i < num_states; i++) {
        if (id[i] == target_id) {
            cur_state = (short)i;
            vf20(1);
            return;
        }
    }
}

class TShape;

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
    long id2[9];
    long buttonTypeValue;
    long drawTypeValue;
    long notifyTypeValue;
    void* sound;
    TShape* pic[9];
    short pic_index[9];

    void set_picture(short param_1, TShape* param_2, short param_3);
};

void TButtonPanel::set_picture(short param_1, TShape* param_2, short param_3) {
    this->pic[param_1] = param_2;
    this->pic_index[param_1] = param_3;
    this->vf20(1);
}

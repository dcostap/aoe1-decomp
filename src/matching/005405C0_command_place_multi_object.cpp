class RGE_Main_View {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void vf18(void);
    virtual void vf1C(void);
    virtual void vf20(int mode);

    void set_selection_area(long x0, long y0, long x1, long y1);
    int command_place_multi_object(long a, long b, long c, long d, int mode);
};

int RGE_Main_View::command_place_multi_object(long a, long b, long c, long d, int mode) {
    set_selection_area(-1, -1, -1, -1);
    vf20(1);
    return 0;
}

class TRIBE_Dialog_Name {
public:
    void target_method(int a, int b, int c, int d);

    void wnd_proc(int a, int b, int c, int d);
};

void TRIBE_Dialog_Name::wnd_proc(int a, int b, int c, int d) {
    this->target_method(a, b, c, d);
}

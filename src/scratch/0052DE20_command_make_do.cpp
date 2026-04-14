class TRIBE_Main_View {
public:
    void target_method(int a, int b, int c, int d);

    void command_make_do(int a, int b, int c, int d);
};

void TRIBE_Main_View::command_make_do(int a, int b, int c, int d) {
    this->target_method(a, b, c, d);
}

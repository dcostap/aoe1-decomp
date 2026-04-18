class QuickSaveHost {
public:
    void helper0(void);
    void helper1(int a, int b);
    void command_quick_save(void);
};

void QuickSaveHost::command_quick_save(void) {
    this->helper0();
    this->helper1(0, 0);
}

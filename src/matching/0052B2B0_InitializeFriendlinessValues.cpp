class T_Scenario {
public:
    char gap_0[0x47A8];
    int arr_[256];
    void InitializeFriendlinessValues();
};

void T_Scenario::InitializeFriendlinessValues() {
    for (int i = 0; i < 256; i++) this->arr_[i] = 3;
}

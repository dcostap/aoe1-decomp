class TCommunications_Handler {
public:
    char gap_00[0x08];
    int Steps;

    int TEST(void);
    void Step(int amount);
};

void TCommunications_Handler::Step(int amount) {
    TEST();
    Steps += amount;
}

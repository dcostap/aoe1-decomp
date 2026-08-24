#if !defined(COM_HAND_TU_CONTEXT)
class TCommunications_Handler {
public:
    char gap_00[0x08];
    int Steps;

    int TEST(void);
    void Step(int amount);
};
#endif // COM_HAND_TU_CONTEXT


void TCommunications_Handler::Step(int amount) {
    TEST();
    Steps += amount;
}

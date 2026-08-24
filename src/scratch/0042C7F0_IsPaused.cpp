#if !defined(COM_HAND_TU_CONTEXT)
class RGE_Base_Game {
public:
    char gap_0[0x1558];
    int field_1558;
    int IsPaused();
};
#endif // COM_HAND_TU_CONTEXT


int RGE_Base_Game::IsPaused() {
    return this->field_1558 == 4;
}

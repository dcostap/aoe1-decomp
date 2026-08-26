#ifndef TRIBEGAM_TU_CONTEXT
struct MouseClickInfo;
class TRIBE_Game {
public:
    char gap_0[0xA24];
    int field_A24;
    int field_A28;
    int field_A2C;
    int field_A30;
    void SetClickTables(MouseClickInfo* a, int b, MouseClickInfo* c, int d);
};
#endif

void TRIBE_Game::SetClickTables(MouseClickInfo* a, int b,
                                MouseClickInfo* c, int d) {
    *(int*)((char*)this + 0xA24) = (int)a;
    *(int*)((char*)this + 0xA28) = b;
    *(int*)((char*)this + 0xA2C) = (int)c;
    *(int*)((char*)this + 0xA30) = d;
}

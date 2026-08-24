// VA: 00443680 GetIsLostErrorNum (68B)

#ifndef DRAWAREA_CANONICAL_TU
#ifndef DRAWAREA_CANONICAL_TU
class TDrawSystem {
public:
    int GetIsLostErrorNum(long error_num);
};
#endif
#endif

int TDrawSystem::GetIsLostErrorNum(long error_num) {
    switch (error_num) {
    case 0x88760082: return 0x6A4;
    case 0x80070057: return 0x6A5;
    case 0x887601C2: return 0x6A6;
    case 0: return 0;
    default: return 0x707;
    }
}

// VA: 00443680 TDrawSystem::GetIsLostErrorNum (68 B)
// Using /Od to disable optimizer transforms

class TDrawSystem {
public:
    int GetIsLostErrorNum(long error_num);
};

int TDrawSystem::GetIsLostErrorNum(long error_num)
{
    if (error_num > -0x7789FF7E) {
        if (error_num == -0x7789FE3E) return 0x6A6;
        if (error_num == 0) return 0;
        return 0x707;
    }
    if (error_num == -0x7789FF7E) return 0x6A4;
    if (error_num == -0x7FF8FFA9) return 0x6A5;
    return 0x707;
}

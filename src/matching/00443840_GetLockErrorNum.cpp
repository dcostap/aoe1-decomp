// VA: 00443840 TDrawSystem::GetLockErrorNum
// Drawarea.cpp:1414-1436

class TDrawSystem { public: int GetLockErrorNum(long hr); };

int TDrawSystem::GetLockErrorNum(long hr)
{
    switch (hr) {
    case 0:
        return 0;
    case (long)0x80004005:
        return 0x7D0;
    case (long)0x88760082:
        return 0x7D1;
    case (long)0x80070057:
        return 0x7D2;
    case (long)0x887601AE:
        return 0x7D3;
    case (long)0x887601C2:
        return 0x7D4;
    case (long)0x8876021C:
        return 0x7D5;
    case (long)0x8007000E:
        return 0x7D6;
    case (long)0x88760248:
        return 0x7D7;
    case (long)0x88760096:
        return 0x7D8;
    default:
        return 0x833;
    }
}

// VA: 00443AD0 TDrawSystem::GetCreateErrorNum
// Drawarea.cpp:1509-1538
// Natural sparse HRESULT switch, following the same-TU error-number helpers.

#ifndef DRAWAREA_CANONICAL_TU
class TDrawSystem {
public:
    int GetCreateErrorNum(long hr);
};
#endif

int TDrawSystem::GetCreateErrorNum(long hr)
{
    switch (hr) {
    case 0:
        return 0;
    case (long)0x80004005:
        return 0x8FC;
    case (long)0x88760082:
        return 0x8FD;
    case (long)0x80070057:
        return 0x8FE;
    case (long)0x8876017C:
        return 0x8FF;
    case (long)0x88760233:
        return 0x900;
    case (long)0x887600D4:
        return 0x901;
    case (long)0x88760064:
        return 0x902;
    case (long)0x88760091:
        return 0x903;
    case (long)0x887600B4:
        return 0x904;
    case (long)0x887600E6:
        return 0x905;
    case (long)0x88760154:
        return 0x906;
    case (long)0x887600E1:
        return 0x907;
    case (long)0x8007000E:
        return 0x908;
    case (long)0x88760234:
        return 0x909;
    case (long)0x88760235:
        return 0x90A;
    case (long)0x8876005F:
        return 0x90B;
    default:
        return 0x95F;
    }
}

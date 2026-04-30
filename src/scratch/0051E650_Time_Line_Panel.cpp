// 0051E650 TTimeLinePanel::TTimeLinePanel ctor
// tpnl_tml.cpp:98-109, 276 bytes, __thiscall

class TPanel {
public:
    void TPanel(void);
    unsigned char gap_00[0x80];
    int field_80;
};

class TTimeLinePanel : public TPanel {
public:
    unsigned char gap_84[0x478 - 0x84];
    int field_478;
    int field_47C;
    int field_480;
    int field_484;
    int field_488;
    int field_48C;
    int field_490;
    int field_494;
    int field_498;
    int field_49C;
    int field_4A0;
    int field_4A4;
    int field_4A8;
    int field_4AC;
    short field_4B0;
    short field_4B2;
    int field_4B4;
    unsigned char field_4B8;
    unsigned char gap_4B9[3];
    int field_4BC;
    unsigned char field_4C0;
    unsigned char gap_4C1[7];
    int field_4C8;
    unsigned char field_4CC;
    unsigned char field_4CD;
    unsigned char field_4CE;
    unsigned char field_4CF;
    unsigned char field_4D0;
    unsigned char field_4D1;
    unsigned char gap_4D2[2];
    int field_4D4;
    short field_4D8;
    short field_4DA;
    unsigned char gap_4DC[0x500 - 0x4DC];
    int field_500;
    unsigned char gap_504[0x508 - 0x504];
    int field_508;
    unsigned char gap_50C[0x50C - 0x50C];
    unsigned char field_50C;
    unsigned char gap_50D[0x518 - 0x50D];
    int field_518;
    unsigned char gap_51C[0x51C - 0x51C];
    unsigned char field_51C;
    unsigned char gap_51D[0x520 - 0x51D];
    int field_520;
    int field_524;
    int field_528;
    
    TTimeLinePanel();
};

TTimeLinePanel::TTimeLinePanel() : TPanel() {
    int zero = 0;
    field_490 = 2;
    field_478 = zero;
    field_47C = zero;
    field_480 = zero;
    field_484 = zero;
    field_488 = zero;
    field_48C = zero;
    field_494 = 0xFFFFFF;
    field_498 = zero;
    field_49C = 0xFFFF;
    field_4A0 = zero;
    field_4A4 = zero;
    field_4A8 = zero;
    field_4AC = zero;
    field_4B0 = 0;
    field_4B2 = 0;
    field_4B4 = zero;
    field_4B8 = 0xFF;
    field_4BC = zero;
    field_4C0 = 0;
    field_4C8 = zero;
    field_4CC = 0;
    field_4CD = 0;
    field_4CE = 0;
    field_4CF = 0;
    field_4D0 = 0;
    field_4D1 = 0;
    field_4D4 = zero;
    field_4D8 = 0;
    field_4DA = 0;
    field_508 = zero;
    field_518 = zero;
    *(int*)this = 0x576F88;
    field_80 = zero;
    field_51C = 1;
    field_50C = 0;
    field_500 = 0x0C;
    field_520 = zero;
    field_524 = zero;
    field_528 = zero;
}

extern int __stdcall strTableGet_0047E2E0(int id);

class Pnl_drop {
public:
    char gap_0[0x100];
    short field_100;
    int get_text2();
};

int Pnl_drop::get_text2() {
    return strTableGet_0047E2E0((int)this->field_100);
}

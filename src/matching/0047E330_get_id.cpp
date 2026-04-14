extern int __stdcall strTableGet_0047E330(int id);

class Pnl_drop {
public:
    char gap_0[0x100];
    short field_100;
    int get_id();
};

int Pnl_drop::get_id() {
    return strTableGet_0047E330((int)this->field_100);
}

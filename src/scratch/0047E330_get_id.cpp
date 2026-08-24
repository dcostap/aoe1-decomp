extern int __stdcall strTableGet_0047E330(int id);

#ifdef PNL_TXT_TU_CONTEXT
#define PNL_TXT_PNL_DROP_0047E330 Pnl_drop_0047E330
#define Pnl_drop PNL_TXT_PNL_DROP_0047E330
#endif
class Pnl_drop {
public:
    char gap_0[0x100];
    short field_100;
    int get_id();
};

int Pnl_drop::get_id() {
    return strTableGet_0047E330((int)this->field_100);
}
#ifdef PNL_TXT_TU_CONTEXT
#undef Pnl_drop
#undef PNL_TXT_PNL_DROP_0047E330
#endif

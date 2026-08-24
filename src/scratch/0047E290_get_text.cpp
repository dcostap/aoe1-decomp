extern int __stdcall strTableGet_0047E290(int id);

#ifdef PNL_TXT_TU_CONTEXT
#define PNL_TXT_PNL_DROP_0047E290 Pnl_drop_0047E290
#define Pnl_drop PNL_TXT_PNL_DROP_0047E290
#endif
class Pnl_drop {
public:
    char gap_0[0x100];
    short field_100;
    int get_text();
};

int Pnl_drop::get_text() {
    return strTableGet_0047E290((int)this->field_100);
}
#ifdef PNL_TXT_TU_CONTEXT
#undef Pnl_drop
#undef PNL_TXT_PNL_DROP_0047E290
#endif

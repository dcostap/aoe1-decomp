#ifndef T_C_OBJ_CONTEXT_H
struct InnerObj { char pad[0x14]; short field_14; };
class SomeClass {
public:
    unsigned char useSameZoneDropsite();
    char pad[0x08];
    InnerObj* field_08;
};
#endif
unsigned char SomeClass::useSameZoneDropsite() {
    int type = (int)this->field_08->field_14;
    if (type == 0x15 || type == 0x02) return 0;
    return 1;
}

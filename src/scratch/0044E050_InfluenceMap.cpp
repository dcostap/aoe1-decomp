void __stdcall init_map(int);

struct InfluenceMap {
    int vfptr;      // 0x00
    int field_4;    // 0x04
    int field_8;    // 0x08
    int field_C;    // 0x0C
    int field_10;   // 0x10
};

InfluenceMap* __fastcall InfluenceMap_ctor(InfluenceMap* self, int, int param) {
    self->field_4 = -1;
    self->field_8 = -1;
    self->vfptr = 0x00570444;
    self->field_C = 0;
    self->field_10 = 0;
    init_map(param);
    return self;
}

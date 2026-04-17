void __cdecl operator_delete(void*);

struct InfluenceMap {
    int vfptr;      // 0x00
    char gap_4[0x10];
    int field_14;   // 0x14
    int field_18;   // 0x18
};

void __fastcall InfluenceMap_dtor(InfluenceMap* self, int) {
    self->vfptr = 0x00570444;
    if (self->field_14) {
        operator_delete((void*)self->field_14);
    }
    if (self->field_18) {
        operator_delete((void*)self->field_18);
    }
}

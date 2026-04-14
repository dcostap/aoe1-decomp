void __stdcall operator_delete(void*);

struct InfluenceMap {
    int vfptr;
    int xSizeValue;
    int ySizeValue;
    int xReferencePointValue;
    int yReferencePointValue;
    int valueValue;
    int rowValue;
};

void __fastcall InfluenceMap_dtor(InfluenceMap* self, int, int flag) {
    self->vfptr = 0x005C0C44;
    if (flag & 1)
        operator_delete(self);
}

struct InfluenceMap {
    int vfptr;
    int xSizeValue;
    int ySizeValue;
    int xReferencePointValue;
    int yReferencePointValue;
    int valueValue;
    int rowValue;
};

InfluenceMap* __fastcall InfluenceMap_ctor(InfluenceMap* self, int) {
    self->vfptr = 0x005C0C44;
    self->xSizeValue = 0;
    self->ySizeValue = 0;
    self->xReferencePointValue = 0;
    self->yReferencePointValue = 0;
    self->valueValue = 0;
    self->rowValue = 0;
    return self;
}

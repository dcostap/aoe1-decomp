void __cdecl operator_delete(void*);

struct AIPlayBook {
    int vfptr;          // 0x00
    int field_4;        // 0x04
    char gap_8[0x44];
    int field_4C;       // 0x4C
};

void __fastcall AIPlayBook_dtor(AIPlayBook* self, int) {
    self->vfptr = 0x0056E970;
    if (self->field_4C) {
        self->field_4 = 0;
        operator_delete((void*)self->field_4C);
        self->field_4C = 0;
    }
}

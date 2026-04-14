void __stdcall operator_delete(void*);

struct AIPlayBook {
    int vfptr;
    int numberPlaysValue;
    char gap[0x7000];
};

void __fastcall AIPlayBook_dtor(AIPlayBook* self, int, int flag) {
    self->vfptr = 0x005CC478;
    if (flag & 1)
        operator_delete(self);
}

struct NotifyArgs {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
};

struct Commander {
    int vfptr;
};

struct SomeModule {
    char gap_0[0xB4];
    Commander* commander;
};

void __fastcall notifyCommander(SomeModule* self, int, NotifyArgs* args) {
    Commander* cmd = self->commander;
    if (cmd) {
        void (__stdcall **vtbl)(Commander*, int, int, int, int, int, int) = (void (__stdcall **)(Commander*, int, int, int, int, int, int))*(int*)cmd;
        vtbl[6](cmd, args->field_0, args->field_4, args->field_8, args->field_C, args->field_10, args->field_14);
    }
}

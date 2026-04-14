struct NotifyArgs {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
};

struct NotifyQueue {
    char gap_0[0xA8];
    int numEntries;
};

void __stdcall addNotifyEntry(NotifyQueue*, int, int, int, int, int, int);

void __fastcall addToNotifyQueue(NotifyQueue* self, int, NotifyArgs* args) {
    addNotifyEntry(self, args->field_0, args->field_4, args->field_8, args->field_C, args->field_10, args->field_14);
}

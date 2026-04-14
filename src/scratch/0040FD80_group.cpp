#pragma pack(push, 1)
struct AIPlayStatusEntry {
    int id;
    unsigned char group;
    unsigned char slot;
    char pad[2];
};
#pragma pack(pop)

struct AIPlayStatus {
    AIPlayStatusEntry entries[50];
};

unsigned char __fastcall group(AIPlayStatus* self, int, int id) {
    if (id < 0)
        return 0xFF;
    for (int i = 0; i < 50; i++) {
        if (self->entries[i].id == id)
            return self->entries[i].group;
    }
    return 0xFF;
}

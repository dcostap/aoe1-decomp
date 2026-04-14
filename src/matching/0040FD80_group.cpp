// AIPlayStatus::group
// Searches 0x32 (50) entries of 8-byte records for matching id
// Returns group byte if found, 0xFF if not found or id < 0
// ret 4 = 1 param

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

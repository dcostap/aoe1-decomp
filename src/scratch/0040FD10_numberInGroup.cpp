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

unsigned char __fastcall numberInGroup(AIPlayStatus* self, int, int groupIndex) {
    unsigned char count = 0;
    AIPlayStatusEntry* entry = self->entries;
    int remaining = 50;
    do {
        if (entry->id != -1) {
            if (entry->group == groupIndex)
                count++;
        }
        entry++;
        remaining--;
    } while (remaining);
    return count;
}

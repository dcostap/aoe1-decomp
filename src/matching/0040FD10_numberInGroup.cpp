// AIPlayStatus::numberInGroup
// Iterates 0x32 (50) entries of 8-byte records
// Each record: int id@0, uchar group@4
// Counts records where id != -1 and group == param
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

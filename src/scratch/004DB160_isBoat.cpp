int __stdcall getCombatLevel(int objectId);

int __fastcall isBoat(void* self, int, int objectId) {
    int level = getCombatLevel(objectId);
    if (level == 6 || level == 7)
        return 1;
    return 0;
}

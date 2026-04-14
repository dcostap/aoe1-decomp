int __stdcall getCombatLevel(int objectId);

int __fastcall isBuilding(void* self, int, int objectId) {
    int level = getCombatLevel(objectId);
    if (level == 4 || level == 5)
        return 1;
    return 0;
}

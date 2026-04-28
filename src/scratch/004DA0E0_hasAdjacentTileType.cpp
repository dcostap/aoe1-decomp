// VA: 004DA0E0 TribeInformationAIModule::hasAdjacentTileType(int, int, int)
// Source: taiinfmd.cpp lines 1853-1894
// Size: 141 bytes, __thiscall, ret 0Ch (3 params)
// Attempt: minimal locals, terrain reloaded inside loop

struct TribeInformationAIModule {
    char _gap[0x100];
    void* md;  // +0x100

    int hasAdjacentTileType(int param_1, int param_2, int param_3);
};

int TribeInformationAIModule::hasAdjacentTileType(int param_1, int param_2, int param_3) {
    int x = param_1;
    int y = param_2;

    for (int i = 0; i < 8; i++) {
        switch (i) {
            case 0: x = param_1 - 1; y = param_2 - 1; break;
            case 1:
            case 2: x++; break;
            case 3:
            case 4: y++; break;
            case 5:
            case 6: x--; break;
            case 7: y--; break;
        }

        if (x >= 0 && y >= 0) {
            int w = *(int*)(*(char**)(*(char**)(*(char**)((char*)this->md + 0x1256C) + 0x3C) + 0x28) + 8);
            int h = *(int*)(*(char**)(*(char**)(*(char**)((char*)this->md + 0x1256C) + 0x3C) + 0x28) + 0x0C);
            if (x <= w - 2 && y <= h - 2) {
                void* tile_map = *(void**)(*(char**)(*(char**)(*(char**)((char*)this->md + 0x1256C) + 0x3C) + 0x28) + 0x8D8C);
                unsigned char tile_type = ((unsigned char*)tile_map)[y * 4 + x * 24 + 5] & 0x1F;
                if ((int)tile_type == param_3) {
                    return 1;
                }
            }
        }
    }

    return 0;
}

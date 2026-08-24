extern "C" __declspec(dllimport) int __stdcall DeleteObject(void* object);

#ifndef AOE1_PANEL_CONTEXT_H
class TPanelSystem {
public:
    char gap_00[0x1C];
    void* palette[10];
    char palette_file[10][260];
    int palette_use_count[10];

    void release_palette(void* palette);
};

#endif
void TPanelSystem::release_palette(void* target_palette) {
    int i;

    for (i = 0; i < 10; i++) {
        if (palette[i] == target_palette) {
            palette_use_count[i]--;
            if (palette_use_count[i] == 0) {
                DeleteObject(palette[i]);
                palette[i] = 0;
                palette_file[i][0] = 0;
            }
            return;
        }
    }
}

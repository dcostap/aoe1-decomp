// PointMaker::MapCleanUpEliminatingSinglesOnly — real pass
// VA: 0044C510
void __fastcall MapCleanUpEliminatingSinglesOnly(void* _this, int _)
{
    int h = *(int*)((char*)_this + 0xFD8) - 1;  // Height - 1
    int w = *(int*)((char*)_this + 0xFD4) - 1;  // Width - 1
    if (h <= 1) return;
    for (int y = 1; y < h; y++) {
        if (w <= 1) continue;
        for (int x = 1; x < w; x++) {
            int width = *(int*)((char*)_this + 0xFD4);
            char* placement = (char*)(*(int*)((char*)_this + 0x1028));
            char* cell = placement + y * width + x;
            int count = 0;
            if (*(cell - width) > 0) count++;
            if (*(cell - 1) > 0) count++;
            if (*(cell + 1) > 0) count++;
            if (*(cell + width) > 0) count++;
            if (*cell > 0 && count == 0) *cell = 0;
        }
    }
}

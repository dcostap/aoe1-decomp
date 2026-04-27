// PointMaker::DrawCurrentSatelliteIntoProbArray — real pass
// VA: 0044BCD0
void __fastcall DrawCurrentSatelliteIntoProbArray(void* _this, int _, int param1)
{
    int r = *(int*)((char*)_this + 0xFFC);  // SatelliteRadius
    *(int*)((char*)_this + 0xFF4) = 2;       // ProbabilityAdd = 2
    for (int i = r; i >= 0; i--) {
        int px = *(int*)((char*)_this + 8 + param1 * 8 + 0);
        int py = *(int*)((char*)_this + 8 + param1 * 8 + 4);
        ((void(__fastcall*)(void*,int,int,int,int))0x44BF90)(_this, 0, px, py, i);  // AddingCircle
        *(int*)((char*)_this + 0xFF4) += 1;  // ProbabilityAdd++
    }
    int px = *(int*)((char*)_this + 8 + param1 * 8 + 0);
    int py = *(int*)((char*)_this + 8 + param1 * 8 + 4);
    int idx = py * *(int*)((char*)_this + 0xFD4) + px;  // y * Width + x
    int probAdd = *(int*)((char*)_this + 0xFF4);
    if (idx < 1) return;
    int sizeArrays = *(int*)((char*)_this + 0x1004);
    if (idx >= sizeArrays - 1) return;
    char* probArray = (char*)*(int*)((char*)_this + 0x1024);  // ProbArray
    char val = probArray[idx];
    if (val == 0) {
        probArray[idx] = (char)probAdd;
        *(int*)((char*)_this + 0xFEC) += 1;  // ProbabilityTiles++
        return;
    }
    int total = probAdd + (signed char)val;
    if (total >= 0xFF) {
        probArray[idx] = (char)0xFF;
        return;
    }
    probArray[idx] = (char)(probAdd + val);
    return;
}

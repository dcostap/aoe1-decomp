// PointMaker::DrawPrimaryIntoProbabilityArray — real pass
// VA: 0044BAA0
void __fastcall DrawPrimaryIntoProbabilityArray(void* _this, int _)
{
    int startX = *(int*)((char*)_this);           // Prime.x
    int startY = *(int*)((char*)_this + 4);       // Prime.y
    int radius = *(int*)((char*)_this + 0x1000);   // PrimaryRadius
    int x1 = startX - radius;
    int y1 = startY - radius;
    int x2 = startX + radius;
    int y2 = startY + radius;
    if (x1 < 0) x1 = 0;
    if (y1 < 0) y1 = 0;
    int width = *(int*)((char*)_this + 0xFD4);
    if (x2 > width - 1) x2 = width - 1;
    int height = *(int*)((char*)_this + 0xFD8);
    if (y2 > height - 1) y2 = height - 1;
    *(int*)((char*)_this + 0xFF4) = 1;  // ProbabilityAdd = 1
    for (int i = 0; i < radius; i++) {
        ((void(__fastcall*)(void*,int,int,int,int,int))0x44BD80)(_this, 0, x1, y1, x2, y2);  // AddingRect
        *(int*)((char*)_this + 0xFF4) += 1;  // ProbabilityAdd++
        x1++; y1++; x2--; y2--;
    }
}

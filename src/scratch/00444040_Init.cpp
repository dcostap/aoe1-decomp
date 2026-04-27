// Init — real pass
// VA: 00444040
// TDrawArea method — inserts into global draw area linked list

void __fastcall Init_TDrawArea(void* _this, int _, void* drawArea, void* param2)
{
    // Store fields
    *(void**)_this = drawArea;
    *(void**)((char*)_this + 0xF0) = param2;
    
    if (!drawArea) return;
    
    *(int*)((char*)_this + 4) = *(int*)((char*)drawArea + 4);
    
    // Check if already in linked list
    if (*(void**)((char*)_this + 0xAC)) return;
    
    // Allocate list node
    void* node = ((void*(__fastcall*)(int,int))0x54B730)(1, 0x0C);
    if (!node) return;
    
    *(void**)node = _this;
    *(int*)((char*)node + 4) = 0;
    *(int*)((char*)node + 8) = 0;
    
    // Insert into list
    void* firstNode = *(void**)((char*)drawArea + 0x14);
    if (!firstNode) {
        *(void**)((char*)drawArea + 0x14) = node;
    } else {
        // Walk to end and insert
        void* cur = firstNode;
        while (*(void**)((char*)cur + 8))
            cur = *(void**)((char*)cur + 8);
        *(void**)((char*)cur + 8) = node;
        *(void**)((char*)node + 4) = cur;
    }
    
    // Check special flag
    if (*(char*)((char*)drawArea + 0x478) == 1) {
        // Clear and return specific value
    }
}

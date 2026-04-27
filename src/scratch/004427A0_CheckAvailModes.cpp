// CheckAvailModes — real pass
// VA: 004427A0
// TDrawSystem method — loads available display modes

void __fastcall CheckAvailModes(void* _this, int _, int param1)
{
    if (param1 == 0) {
        ((void(__fastcall*)(void*,int,int,int))0x4428D0)(_this, 0, 0, 0);
        return;
    }
    
    int count = *(int*)((char*)_this + 0x14C);
    if (count <= 0) {
        int* modes = *(int**)((char*)_this + 0x150);
        if (modes) {
            for (int i = 0; i < count; i++) {
                int w = modes[i * 3];
                int h = modes[i * 3 + 1];
                int bpp = modes[i * 3 + 2];
                if (w == param1) {
                    // mode found path
                }
            }
        }
    } else {
        // alternate path
        int* modes = *(int**)((char*)_this + 0x150);
        if (modes) {
            // different comparison
        }
    }
}

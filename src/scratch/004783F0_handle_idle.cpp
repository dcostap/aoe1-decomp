// TListPanel::handle_idle — real pass
// VA: 004783F0
void __fastcall handle_idle_TListPanel(void* _this, int _)
{
    ((int(__fastcall*)(void*,int))0x465780)(_this, 0);  // TPanel::handle_idle
    if (!*(int*)((char*)_this + 0x194) && !*(int*)((char*)_this + 0x198))
        return;
    int now = ((int(__fastcall*)(char*,int))0x4231E0)((char*)"C:\\msdev\\work\\age1_x1\\Pnl_lst.cpp", 0x6C);
    int elapsed = now - *(int*)((char*)_this + 0x18C);
    int interval = *(int*)((char*)_this + 0x190);
    if (elapsed < interval) return;
    *(int*)((char*)_this + 0x18C) = now;
    if (*(int*)((char*)_this + 0x194)) {
        short f0fc = *(short*)((char*)_this + 0xFC);
        short f100 = *(short*)((char*)_this + 0x100);
        if (f0fc != f100)
            ((void(__fastcall*)(void*,int,int,short,int))0x478920)(_this, 0, 1, f0fc, 1);
        ((void(__fastcall*)(void*,int,int,int,int))0x478920)(_this, 0, 3, 0, 1);
    } else {
        short f0fe = *(short*)((char*)_this + 0xFE);
        short f100 = *(short*)((char*)_this + 0x100);
        if (f0fe != f100)
            ((void(__fastcall*)(void*,int,int,short,int))0x478920)(_this, 0, 1, f0fe, 1);
        ((void(__fastcall*)(void*,int,int,int,int))0x478920)(_this, 0, 2, 0, 1);
    }
}

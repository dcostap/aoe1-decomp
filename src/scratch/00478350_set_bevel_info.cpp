// TListPanel::set_bevel_info — real pass
// VA: 00478350
void __fastcall set_bevel_info_TListPanel(void* _this, int _, int param1, int param2, int param3, int param4, int param5, int param6, int param7)
{
    switch (param1) {
        case 3:
        case 6:
            *(int*)((char*)_this + 0x184) = 2;
            break;
        case 4:
        case 7:
            *(int*)((char*)_this + 0x184) = 3;
            break;
        default:
            *(int*)((char*)_this + 0x184) = 1;
            break;
    }
    ((void(__fastcall*)(void*,int,int,int,int,int,int,int,int))0x47CD40)(_this, 0, param1, param2, param3, param4, param5, param6, param7);
    if (!*(int*)((char*)_this + 0x180)) {
        *(int*)((char*)_this + 0x180) = 1;
        ((void(__fastcall*)(void*,int,int))0x47CE70)(_this, 0, 1);
    }
}

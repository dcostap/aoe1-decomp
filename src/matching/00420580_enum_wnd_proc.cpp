
int __stdcall enum_wnd_proc(void* param_1, long param_2) {
    char buffer[256];
    GetWindowTextA(param_1, buffer, 255);
    return 1;
}

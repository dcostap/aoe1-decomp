
int __stdcall enum_child_proc(void* param_1, long param_2) {
    char buffer[256];
    GetWindowTextA(param_1, buffer, 255);
    return 1;
}

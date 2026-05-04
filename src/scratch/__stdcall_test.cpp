// Test __stdcall virtual call
typedef unsigned long (__stdcall *RF)(void*);

unsigned long test_call(void* obj) {
    void** vt = *(void***)obj;
    return ((RF)vt[2])(obj);
}

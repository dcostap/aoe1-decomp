extern void* _pnhHeap;
void* __cdecl _query_new_handler(void) {
    return _pnhHeap;
}

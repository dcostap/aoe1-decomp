typedef void* (*_PNH)(unsigned int);
extern _PNH _pnhHeap;
_PNH __cdecl _set_new_handler(_PNH pnh) {
    _PNH old = _pnhHeap;
    _pnhHeap = pnh;
    return old;
}

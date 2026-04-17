extern "C" void __cdecl free(void* block);

void __cdecl operator_delete(void* block) {
    free(block);
}

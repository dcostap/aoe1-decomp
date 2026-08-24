extern "C" void __cdecl rge_write(int file_handle, void* data, int size);

#include "../../include/tairesmd_context.h"

int TribeResourceAIModule::save(int file_handle) {
    rge_write(file_handle, &this->numberResourcesValue, 4);
    return 1;
}

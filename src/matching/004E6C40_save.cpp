extern "C" void __cdecl rge_write(int file_handle, void* data, int size);

class TribeResourceAIModule {
public:
    char gap_00[0xF4];
    int numberResourcesValue;

    int save(int file_handle);
};

int TribeResourceAIModule::save(int file_handle) {
    rge_write(file_handle, &this->numberResourcesValue, 4);
    return 1;
}

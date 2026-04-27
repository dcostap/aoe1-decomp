// first pass: direct ready-byte guard and stack buffer build in packet order
// if this drifts, the remaining issue is likely just the exact sprintf / call shape
extern "C" int __cdecl sprintf(char* buffer, const char* format, ...);
extern "C" int __cdecl ds_stream_file(char* file_name, int param_2, long param_3);

class TSound_Driver {
public:
    unsigned char ready;
    unsigned char _pad_1[0x1B];
    char path[260];

    int stream_file(char* param_1, int param_2, long param_3);
};

int TSound_Driver::stream_file(char* param_1, int param_2, long param_3) {
    char file_name2[260];

    if (this->ready == 0) {
        return 0;
    }

    sprintf(file_name2, "%s%s", this->path, param_1);
    return ds_stream_file(file_name2, param_2, param_3);
}

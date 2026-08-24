extern "C" int __cdecl __chdir(const char* path);

#ifndef FILE_STF_SHARED_CONTEXT
class DriveInformation {
public:
    int changeDirectory(char* path);
    void updateDirectory(void);
};
#endif

int DriveInformation::changeDirectory(char* path) {
    if (__chdir(path) == 0) {
        updateDirectory();
        return 1;
    }
    return 0;
}

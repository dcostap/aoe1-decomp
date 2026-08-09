// VA: 004B2AA0 TRIBE_Screen_Sed::MakeFileList
// Baseline: period-style file enumeration used by the scenario-editor drop-down.

extern "C" int __cdecl sprintf(char* buffer, const char* format, ...);
extern "C" char* __cdecl strncpy(char* dst, const char* src, unsigned int count);
extern "C" unsigned int __cdecl strlen(const char* text);
extern "C" long __cdecl _findfirst(const char* filespec, void* file_info);
extern "C" int __cdecl _findnext(long handle, void* file_info);

class TDropDownPanel {
public:
    void empty_list();
    int append_line(long string_id, long value);
    int append_line(char* text, long value);
};

struct FindDataLocal {
    unsigned int attrib;
    long time_create;
    long time_access;
    long time_write;
    unsigned long size;
    char name[260];
};

class TRIBE_Screen_Sed {
public:
    int MakeFileList(TDropDownPanel* list, char* directory, char* extension,
                     unsigned char show_none, unsigned char show_random);
};

int TRIBE_Screen_Sed::MakeFileList(TDropDownPanel* list, char* directory,
                                   char* extension, unsigned char show_none,
                                   unsigned char show_random)
{
    char path[260];
    char file_name[260];
    FindDataLocal file_info;
    int count;
    int extension_strlen;
    long handle;

    count = 0;
    list->empty_list();
    if (show_none) {
        list->append_line(0x2775, 0);
    }
    if (show_random) {
        list->append_line(0x277B, 0);
    }

    sprintf(path, "%s*%s", directory, extension);
    handle = _findfirst(path, &file_info);
    extension_strlen = strlen(extension);
    if (handle != -1) {
        do {
            ++count;
            int length = strlen(file_info.name);
            length -= extension_strlen;
            strncpy(file_name, file_info.name, length);
            file_name[length] = 0;
            list->append_line(file_name, 0);
        } while (_findnext(handle, &file_info) != -1);
    }
    return count;
}

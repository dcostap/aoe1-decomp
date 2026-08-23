// VA: 004B2AA0 TRIBE_Screen_Sed::MakeFileList
// Baseline: period-style file enumeration used by the scenario-editor drop-down.

#include "../../include/scr_sed2_context.h"

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

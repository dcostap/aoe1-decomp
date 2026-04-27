// VA: 0047FC50 BUILDRES_get_files_resource_type (217B)
// Res_file.cpp
// Gets the resource type from a filename by finding the extension

#include <string.h>

int __cdecl BUILDRES_get_files_resource_type(const char* name) {
    int len = strlen(name);
    
    if (len < 5 || len >= 0x104) return -1;
    
    // Find the dot
    int i;
    for (i = len - 1; i > 0; i--) {
        if (name[i] == '.') break;
    }
    
    if (i == 0) return -1;
    
    // Check extension (3 chars after dot)
    int extLen = len - i - 1;
    if (extLen == 3) {
        const char* ext = name + i + 1;
        // Compare extension
    }
    
    return -1;
}

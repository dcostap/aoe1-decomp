// VA: 00449990 DriveInformation::numberOfFilesWithFilenameOrAttribute
// file_stf.cpp lines 167-180
//
// attempt 1-3: eager saves (ebx,ebp,esi,edi at prologue) vs lazy (only esi)
// attempt 4: defer count declaration, goto, block scope — all eager still
// Remaining 73%: VC5 register save heuristic — original uses lazy saves,
// rebuilt uses eager. Deep codegen basin; not controllable from C source.
// Left in scratch.

#include <io.h>
#include <string.h>

class DriveInformation {
public:
    int numberOfFilesWithFilenameOrAttribute(char* filename, int attribMask);
};

int DriveInformation::numberOfFilesWithFilenameOrAttribute(char* filename, int attribMask) {
    struct _finddata_t file_info;

    long handle = _findfirst("*.*", &file_info);
    if (handle == -1)
        return 0;

    if (_findnext(handle, &file_info) == -1)
        return 1;

    int count = 1;
    do {
        if ((file_info.attrib & attribMask) || strstr(file_info.name, filename))
            count++;
    } while (_findnext(handle, &file_info) != -1);

    return count;
}

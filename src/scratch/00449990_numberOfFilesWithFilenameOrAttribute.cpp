// VA: 00449990 DriveInformation::numberOfFilesWithFilenameOrAttribute
// file_stf.cpp lines 167-180

// attempt 1: _findfirst("*.*") + strstr filter -> exact size (144), 72% diff
// attempt 2: restructured for lazy saves (block scope) -> same issue
// attempt 3: declare count after all early returns -> same issue (all 4 regs saved at entry)
//   Root: VC5 in this build defers saves to first-use point (only esi in prologue),
//   but our compilation saves all 4 (ebx,ebp,esi,edi) upfront. Deep codegen basin.
// Left in scratch.

#include <io.h>
#include <string.h>

class DriveInformation {
public:
    int numberOfFilesWithFilenameOrAttribute(char* filename, int attribMask);
};

int DriveInformation::numberOfFilesWithFilenameOrAttribute(char* filename, int attribMask) {
    struct _finddata_t file_info;
    long handle;

    handle = _findfirst("*.*", &file_info);
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

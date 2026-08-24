#include <io.h>
#include <string.h>
#ifndef FILE_STF_SHARED_CONTEXT
class DriveInformation { public: int numberOfFilesWithFilenameOrAttribute(char*,int); };
#endif
int DriveInformation::numberOfFilesWithFilenameOrAttribute(char* filename,int attribMask){
    struct _finddata_t file_info; long h=_findfirst("*.*",&file_info); if(h==-1) return 0; int count=1; if(_findnext(h,&file_info)==-1) goto done; do { if((file_info.attrib & attribMask) || strstr(file_info.name,filename)) ++count; } while(_findnext(h,&file_info)!=-1); done: return count;
}

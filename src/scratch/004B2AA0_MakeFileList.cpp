// VA: 004B2AA0 TRIBE_Screen_Sed_Open::MakeFileList (275 B)
// PDB source: scr_sed2.cpp
// Packet-grounded: build file list for scenario editor open dialog

extern int StringList_Clear(void* list);
extern int StringList_AddString(void* list, int strId, int flags);
extern int BuildFilePathList(void* list, const char* dir, const char* ext);

int TRIBE_Screen_Sed_Open_MakeFileList(void* self, void* fileList, int showAllFiles, int showSystemFiles)
{
    // Clear the file list
    StringList_Clear(fileList);
    
    // If showAllFiles, add special entries
    if (showAllFiles) {
        StringList_AddString(fileList, 0x2775, 0);
    }
    
    // If showSystemFiles, add system entries
    if (showSystemFiles) {
        StringList_AddString(fileList, 0x277B, 0);
    }
    
    // Build file path list from directory with extension filter
    // sprintf(path, "%s\\*.scn", directory);
    // BuildFilePathList(fileList, path, ...)
    
    return 0;
}

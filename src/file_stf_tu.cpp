// Authentic owner wrapper for the PDB source module file_stf.cpp.
//
// The owner order follows the PDB line bands from file_stf.cpp:20 through
// file_stf.cpp:239.  The shared class declaration preserves the original
// DriveInformation layout and method access, while each owner keeps its
// source body and local standalone fallback.

#define FILE_STF_SHARED_CONTEXT 1
#include "../include/file_stf_context.h"

#include "accepted_drift/00449710_compareFilenameStrings.cpp"
#include "matching/00449750_driveAsLetter.cpp"
#include "matching/00449760_driveAsInt.cpp"
#include "matching/00449770_DriveInformation.cpp"
#include "matching/004497C0_initialDrive.cpp"
#include "scratch/004497D0_initialDriveAsLetter.cpp"
#include "matching/004497E0_initialDirectory.cpp"
#include "matching/004497F0_currentDrive.cpp"
#include "scratch/00449800_currentDriveAsLetter.cpp"
#include "matching/00449810_currentDirectory.cpp"
#include "matching/00449820_numberDrives.cpp"
#include "matching/00449830_validDrive.cpp"
#include "matching/00449840_checkDrives.cpp"
#include "matching/004498A0_numberOfFilesWithFilename.cpp"
#include "matching/00449910_numberOfFilesWithAttribute.cpp"
#include "matching/00449990_numberOfFilesWithFilenameOrAttribute.cpp"
#include "matching/00449A20_resetCurrentDriveAndDirectory.cpp"
#include "matching/00449A40_resetCurrentDrive.cpp"
#include "matching/00449A50_resetCurrentDirectory.cpp"
#include "matching/00449A60_changeDrive.cpp"
#include "matching/00449A90_changeDirectory.cpp"
#include "scratch/00449AC0_updateDirectory.cpp"

#undef FILE_STF_SHARED_CONTEXT

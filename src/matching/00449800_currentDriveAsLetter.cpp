// currentDriveAsLetter (00449800, 10 bytes, file_stf.cpp)
// simple getter: return this->currentDriveValue + '@'
#include "game_globals.h"
#include "game_types.h"

class DriveInformation {
public:
    int initialDriveValue;
    char initialDirectoryValue[256];
    int currentDriveValue;
};

char DriveInformation::currentDriveAsLetter() {
    return (char)(currentDriveValue + '@');
}

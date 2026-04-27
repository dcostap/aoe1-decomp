// driveAsInt (00449760, 9 bytes, file_stf.cpp)
// inverse of driveAsLetter
#include "game_globals.h"
#include "game_types.h"

int driveAsInt(char drive) {
    return drive - '@';
}

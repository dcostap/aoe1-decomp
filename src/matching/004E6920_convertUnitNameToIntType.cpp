// TribeAIPlayBook::convertUnitNameToIntType
// VA: 004E6920
// PDB: taipbook.cpp:43-57

#include "..\..\include\game_globals.h"
#include <string.h>

class AIPlayBook {
public:
    int convertUnitNameToIntType(char* name);
};

class TribeAIPlayBook : public AIPlayBook {
public:
    int convertUnitNameToIntType(char* name) const;
};

int TribeAIPlayBook::convertUnitNameToIntType(char* name) const
{
    if (strcmp(name, "Hand") == 0)
        return 0;
    if (strcmp(name, "Ranged") == 0)
        return 1;
    if (strcmp(name, "Priest") == 0)
        return 4;
    if (strcmp(name, "Siege") == 0)
        return 5;
    if (strcmp(name, "Cavalry") == 0)
        return 2;
    if (strcmp(name, "Legion") == 0)
        return 3;

    return ((AIPlayBook*)this)->convertUnitNameToIntType(name);
}

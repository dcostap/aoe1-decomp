// VA: 0045C300 GetDDBltError
// PDB source: Mouseptr.cpp
// Attempt log:

#include "../../include/mouseptr_context.h"

int TMousePointer::GetDDBltError(long a_hresult)
{
    switch (a_hresult) {
    case 0x80004005: return 1;
    case 0x80004001: return 17;
    case 0x88760037: return 18;
    case 0x80070057: return 4;
    case 0x88760082: return 3;
    case 0x8876006E: return 2;
    case 0x887600B4: return 6;
    case 0x88760096: return 5;
    case 0x887600FA: return 10;
    case 0x887600CD: return 8;
    case 0x88760122: return 12;
    case 0x88760118: return 11;
    case 0x88760154: return 14;
    case 0x88760136: return 13;
    case 0x887601C2: return 16;
    case 0x887601AE: return 15;
    case 0x8876023F: return 7;
    case 0x88760240: return 9;
    case 0: return 0;
    default: return -1;
    }
}

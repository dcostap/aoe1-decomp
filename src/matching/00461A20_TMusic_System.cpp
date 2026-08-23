// VA: 00461A20 TMusic_System::~TMusic_System (5B)
// PDB source: music.cpp line 64
// Natural destruction emits the original tail jump to close_device.
// The 00461910, 00461A20, 00462C30 grouped prefix retains all three boundaries.

#include "../../include/music_context.h"

TMusic_System::~TMusic_System()
{
    this->close_device();
}

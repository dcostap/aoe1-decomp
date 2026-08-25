// IsModeAvail — period-plausible TDrawSystem mode lookup
// VA: 004429C0
// Attempt log:
// - Initial scratch scaffold used a fake __fastcall signature and raw offsets.
//   Replaced it with the PDB-proven __thiscall(long, long, int) member surface.
// - baseline: natural <=640 dispatch with equality first; size matched but the
//   compiler placed the 640 return inline (first mismatch +0014).
// - probe 2: split <640 / ==640 / >640 arms; produced jge and worsened the
//   first block, so rolled back.
// - probe 3: nested <=640 with a !=640 low-width arm and equality else arm;
//   recovered the complete low-width dispatch, leaving only the high-width
//   equality-handler layout (44 differing bytes).
// - probe 4: nested negative high-width tests preserve late je handlers for
//   800/1024 and the inline 1280/1024-16 tails; exact match.

#include "../drawarea_phase2_context.h"

int TDrawSystem::IsModeAvail(long width, long height, int bpp)
{
    if (bpp == 8) {
        if (width <= 0x280) {
            if (width != 0x280) {
                if (width == 0x140) {
                    if (height == 0xC8) {
                        return this->ModeAvail320_200;
                    }
                    if (height == 0xF0) {
                        return this->ModeAvail320_240;
                    }
                }
            } else {
                return this->ModeAvail640;
            }
        } else {
            if (width != 0x320) {
                if (width != 0x400) {
                    if (width == 0x500) {
                        return this->ModeAvail1280;
                    }
                } else {
                    return this->ModeAvail1024;
                }
            } else {
                return this->ModeAvail800;
            }
        }
    } else if (bpp == 0x10) {
        if (width <= 0x280) {
            if (width != 0x280) {
                if (width == 0x140) {
                    if (height == 0xC8) {
                        return this->ModeAvail320_200_16;
                    }
                    if (height == 0xF0) {
                        return this->ModeAvail320_240_16;
                    }
                }
            } else {
                return this->ModeAvail640_16;
            }
        } else {
            if (width != 0x320) {
                if (width == 0x400) {
                    return this->ModeAvail1024_16;
                }
            } else {
                return this->ModeAvail800_16;
            }
        }
    }
    return 0;
}

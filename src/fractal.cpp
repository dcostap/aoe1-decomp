
#include "../include/fractal.h"
#include "../include/trig.h"

#include <stdlib.h>
#include <string.h>

extern int __cdecl debug_rand(char* file, int line);
extern TRIGONOMETRY trig;

void PointMaker::SetDefaultValues()
{
    NumberOfSatellites = 2;
    NumSplitsPerBranch = 3;
    Height = 0x118;
    Width = 0x118;
    SatelliteRadius = 2;
    BranchRadius = 3;
    BranchDistance = 3;
    ChanceOfNextNode = 0x32;
    MaxNumberOfBranches = 6;
    PrimaryRadius = 4;
    BorderDepthPercentage = 0x0F;
    MaxBranchFlag = 0;
    SatelliteDistance = 1;
    MaxNumberOfBranchLevels = 0x10;
    MinimumNumTiles = 0x7D0;
    memset(Point, 0, sizeof(Point));
    DoNotDrawOnFlag = 0;
    DrawOnOnlyFlag = 0;
    DrawToOneArrayFlag = 0;
    DrawOnlyInExternalArrayFlag = 0;
}

PointMaker::PointMaker()
{
    ProbArray = 0;
    PlacementArray = 0;
    SetDefaultValues();
    MakeArrays();
    CreateMasks();
}

PointMaker::~PointMaker()
{
    DeleteArrays();
    SetDefaultValues();
    ProbArray = 0;
    PlacementArray = 0;
    DeleteMasks();
}

void PointMaker::CreateMasks()
{
    Mask_2x2 = new char[16];
    Mask_3x3 = new char[25];
    Mask_4x4 = new char[36];
    Mask_5x5 = new char[49];

    char ptr2[16] = {0, 0, 0, 0, 0, 1, 1, 0,
                     0, 1, 1, 0, 0, 0, 0, 0};
    char ptr3[25] = {0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 2,
                     1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0};
    char ptr4[36] = {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0,
                     0, 1, 2, 2, 1, 0, 0, 1, 2, 2, 1, 0,
                     0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0};
    char ptr5[49] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
                     0, 0, 1, 2, 2, 2, 1, 0, 0, 1, 2, 3, 2,
                     1, 0, 0, 1, 2, 2, 2, 1, 0, 0, 1, 1, 1,
                     1, 1, 0, 0, 0, 0, 0, 0, 0};

    memcpy(Mask_2x2, ptr2, sizeof(ptr2));
    memcpy(Mask_3x3, ptr3, sizeof(ptr3));
    memcpy(Mask_4x4, ptr4, sizeof(ptr4));
    memcpy(Mask_5x5, ptr5, sizeof(ptr5));
}

void PointMaker::DeleteMasks()
{
    operator delete(Mask_2x2);
    operator delete(Mask_3x3);
    operator delete(Mask_4x4);
    operator delete(Mask_5x5);
}

void PointMaker::DrawMask(int param_1, int param_2, int param_3)
{
    int iVar1;
    int cVar3;
    char cVar4;
    char* pcVar2;
    int len;
    int iVar6;
    int iVar7 = param_1;
    int iVar8;
    int iVar9;

    if (iVar7 > Width) return;
    if (param_2 > Height) return;
    if (param_3 + 2 + iVar7 < 0) return;
    if (param_3 + 2 + param_2 < 0) return;

    iVar9 = Width;
    iVar1 = param_3 + 2;
    iVar6 = param_2;
    if (param_3 == 2) {
        if (iVar7 + 4 <= iVar9 && iVar7 < 0) {
            iVar7 = 0;
        }
        if (param_2 + 4 <= Height && param_2 < 0) {
            iVar6 = 0;
        }
    }
    if (param_3 == 3) {
        if (iVar7 + 5 <= iVar9 && iVar7 < 0) {
            iVar7 = 0;
        }
        iVar6 = param_2;
        iVar6 += (unsigned)(Height < 5);
    }

    if (param_3 == 4) {
        param_1 = (int)Mask_4x4;
        param_2 = iVar7 + 6;
        if (iVar9 < param_2) {
            param_2 = iVar9 - iVar7;
        } else if (iVar7 < 0) {
            param_1 = param_1 - iVar7;
            iVar7 = 0;
        } else {
            param_2 = 6;
        }
        iVar8 = iVar6 + 6;
        if (Height < iVar8) {
            iVar8 = Height - iVar6;
        } else if (iVar6 < 0) {
            param_1 = param_1 - iVar6 * iVar9;
            iVar6 = 0;
        } else {
            iVar8 = 6;
        }
    } else {
        param_1 = (int)Mask_5x5;
        param_2 = iVar7 + 7;
        if (iVar9 < param_2) {
            param_2 = iVar9 - iVar7;
        } else if (iVar7 < 0) {
            param_1 = param_1 - iVar7;
            iVar7 = 0;
        } else {
            param_2 = 7;
        }
        iVar8 = iVar6 + 7;
        if (Height < iVar8) {
            iVar8 = Height - iVar6;
        } else if (iVar6 < 0) {
            param_1 = param_1 - iVar6 * iVar9;
            iVar6 = 0;
        } else {
            iVar8 = 7;
        }
    }

    iVar7 = iVar6 * iVar9 + iVar7;
    int row_count = iVar8;
    if (row_count != 0) {
        do {
            if (param_2 > 0) {
                iVar9 = iVar7;
                param_3 = param_2;
                len = param_1 - iVar7;
                do {
                    cVar3 = *(char*)(len + iVar9);
                    if (iVar9 > 0 && iVar9 < SizeArrays - 1) {
                        cVar4 = ProbArray[iVar9];
                        pcVar2 = ProbArray + iVar9;
                        if (cVar4 == 0) {
                            *pcVar2 = (char)cVar3;
                            ProbabilityTiles++;
                        } else if (cVar3 + (int)cVar4 < 0xFF) {
                            *pcVar2 = (char)(cVar3 + cVar4);
                        } else {
                            *pcVar2 = (char)-1;
                        }
                    }
                    iVar9++;
                    param_3--;
                } while (param_3 != 0);
            }
            param_1 += iVar1;
            iVar7 += Width;
            row_count--;
        } while (row_count != 0);
    }
}

void PointMaker::ClearArrays()
{
    if (DrawToOneArrayFlag == 0 && PlacementArray != 0) {
        memset(PlacementArray, 0, SizeArrays);
    }
    if (ProbArray != 0) {
        memset(ProbArray, 0, SizeArrays);
    }
}

void PointMaker::DeleteArrays()
{
    if (ProbArray != 0) {
        operator delete(ProbArray);
    }
    if (PlacementArray != 0) {
        operator delete(PlacementArray);
    }
    ProbArray = 0;
    PlacementArray = 0;
}

void PointMaker::MakeArrays()
{
    SizeArrays = Height * Width;
    int count = 10;
    while (count-- != 0) {
        if (ProbArray != 0) break;
        ProbArray = (char*)operator new(SizeArrays);
    }
    count = 10;
    while (count-- != 0) {
        if (PlacementArray != 0) break;
        PlacementArray = (char*)operator new(SizeArrays);
    }
}

int PointMaker::CreateShape()
{
    NumNodes = 0;
    ClearArrays();
    PrepareLimits();

    x = debug_rand("C:\\msdev\\work\\age1_x1\\fractal.cpp", 0xD7) %
        ((Width * (50 - LeftLimit) * 2) / 100) + LeftLimit;
    y = debug_rand("C:\\msdev\\work\\age1_x1\\fractal.cpp", 0xD8) %
        ((Height * (50 - TopLimit) * 2) / 100) + TopLimit;
    ProbabilityTiles = 0;
    NumNodes = 0;
    Prime.x = x;
    Prime.y = y;

    DrawPrimaryIntoProbabilityArray();
    ErrorCheckingAndCorrection();

    int minimum_tiles = MinimumNumTiles;
    int probability_tiles = ProbabilityTiles;
    NumTilesActuallyChosen = 0;
    int attempts = 0;
    while (probability_tiles < minimum_tiles && attempts++ < 1500) {
        x = Prime.x;
        y = Prime.y;
        CurrentNumberOfBranchLevels = MaxNumberOfBranchLevels;
        NumNodes = 0;
        probability_tiles = MakeFirstLink();
        Branch(probability_tiles);
        probability_tiles = ProbabilityTiles;
    }

    CreateMapBasedOnProbabilityArray();
    MapCleanUpEliminatingSinglesOnly();
    return ProbabilityTiles;
}

int PointMaker::CreateShape(int param_1, int param_2)
{
    NumNodes = 0;
    ClearArrays();
    PrepareLimits();
    y = param_2;
    Prime.y = param_2;
    ProbabilityTiles = 0;
    NumNodes = 0;
    x = param_1;
    Prime.x = param_1;
    DrawPrimaryIntoProbabilityArray();
    ErrorCheckingAndCorrection();

    int minimum_tiles = MinimumNumTiles;
    int chosen_tiles = ProbabilityTiles;
    NumTilesActuallyChosen = 0;
    int attempts = 0;
    while (chosen_tiles < minimum_tiles && attempts++ < 1500) {
        chosen_tiles = Prime.y;
        x = Prime.x;
        y = chosen_tiles;
        CurrentNumberOfBranchLevels = MaxNumberOfBranchLevels;
        NumNodes = 0;
        chosen_tiles = MakeFirstLink();
        Branch(chosen_tiles);
        chosen_tiles = ProbabilityTiles;
    }
    CreateMapBasedOnProbabilityArray();
    MapCleanUpEliminatingSinglesOnly();
    return ProbabilityTiles;
}

void PointMaker::Branch(int point)
{
    if (CurrentNumberOfBranchLevels > 1 &&
        debug_rand("C:\\msdev\\work\\age1_x1\\fractal.cpp", 0x116) % 100 <
            ChanceOfNextNode * 10 &&
        ProbabilityTiles < MinimumNumTiles * 2) {
        CurrentNumberOfBranchLevels--;
        for (int i = 0; i < NumSplitsPerBranch; i++) {
            x = Point[point].x;
            y = Point[point].y;
            int link = MakeNewLink();
            DrawCurrentBranchIntoProbArray(link);
            Branch(link);
        }
    }
    for (int i = 0; i < NumberOfSatellites; i++) {
        int link = MakeSatelliteLink();
        DrawCurrentSatelliteIntoProbArray(link);
    }
}

int PointMaker::MakeFirstLink()
{
    int dx = debug_rand("C:\\msdev\\work\\age1_x1\\fractal.cpp", 0x134);
    dx = dx % BranchDistance + 2;
    if (debug_rand("C:\\msdev\\work\\age1_x1\\fractal.cpp", 0x134) % 2)
        dx = -dx;

    int dy = debug_rand("C:\\msdev\\work\\age1_x1\\fractal.cpp", 0x135);
    dy = dy % BranchDistance + 2;
    if (debug_rand("C:\\msdev\\work\\age1_x1\\fractal.cpp", 0x135) % 2)
        dy = -dy;

    DirX = dx;
    int nx = x + dx;
    int ny = y + dy;
    DirY = dy;

    if (nx < LeftLimit) {
        nx = LeftLimit;
        if (dx < 0) DirX = -dx;
    }
    if (ny < TopLimit) {
        ny = TopLimit;
        if (dy < 0) DirY = -dy;
    }
    if (nx >= RightLimit) {
        nx = RightLimit - 1;
        if (DirX > 0) DirX = -DirX;
    }
    if (ny >= BottomLimit) {
        ny = BottomLimit - 1;
        if (DirY > 0) DirY = -DirY;
    }

    y = ny;
    x = nx;
    Point[NumNodes].x = nx;
    Point[NumNodes].y = y;
    int result = NumNodes;
    NumNodes = result + 1;
    return result;
}

int PointMaker::MakeNewLink()
{
    int max_x;
    int r;
    int dx = debug_rand("C:\\msdev\\work\\age1_x1\\fractal.cpp", 0x14A);
    dx = dx % BranchDistance + 1;
    if (debug_rand("C:\\msdev\\work\\age1_x1\\fractal.cpp", 0x14A) % 2)
        dx = -dx;

    int dy = debug_rand("C:\\msdev\\work\\age1_x1\\fractal.cpp", 0x14B);
    dy = dy % BranchDistance + 1;
    if (debug_rand("C:\\msdev\\work\\age1_x1\\fractal.cpp", 0x14B) % 2)
        dy = -dy;

    int old_x = x;
    dx += DirX;
    dy += DirY;

    if (dx + old_x < 5) {
        dx = -dx;
        DirX = -DirX;
    }

    max_x = Width - 5;
    int sum_x = dx + old_x;
    if (sum_x >= max_x) {
        dx = -dx;
        DirX = -DirX;
    }

    int old_y = y;
    if (dy + old_y < 5) {
        // The shipped lower-y correction negates dx, not dy.
        dy = -dx;
        DirY = -DirY;
    }

    int max_y = Height - 5;
    if (dy + old_y >= max_y) {
        dy = -dy;
    }

    dx += old_x;
    dy += old_y;
    if (dx < 5) dx = 5;
    if (dx >= Width - 5) dx = Width - 5;
    if (dy < 5) dy = 5;
    if (dy >= Height - 5) dy = Height - 5;

    r = debug_rand("C:\\msdev\\work\\age1_x1\\fractal.cpp", 0x15A);
    if (r % 2) {
        r = debug_rand("C:\\msdev\\work\\age1_x1\\fractal.cpp", 0x15A);
        DirX = DirX + r % 3 - 1;
    }
    r = debug_rand("C:\\msdev\\work\\age1_x1\\fractal.cpp", 0x15B);
    if (r % 2) {
        r = debug_rand("C:\\msdev\\work\\age1_x1\\fractal.cpp", 0x15B);
        DirY = DirY + r % 3 - 1;
    }

    x = dx;
    y = dy;
    Point[NumNodes].x = x;
    Point[NumNodes].y = y;
    int result = NumNodes;
    NumNodes = result + 1;
    return result;
}

int PointMaker::MakeSatelliteLink()
{
    int dx = debug_rand("C:\\msdev\\work\\age1_x1\\fractal.cpp", 0x165);
    dx = dx % SatelliteDistance + 1;
    int r = debug_rand("C:\\msdev\\work\\age1_x1\\fractal.cpp", 0x165);
    if (r % 2) dx = -dx;

    int dy = debug_rand("C:\\msdev\\work\\age1_x1\\fractal.cpp", 0x166);
    dy = dy % SatelliteDistance + 1;
    r = debug_rand("C:\\msdev\\work\\age1_x1\\fractal.cpp", 0x166);
    if (r % 2) dy = -dy;

    dx += DirX;
    dy += DirY;
    if (dx + x < 3) {
        dx = -dx;
        DirX = -DirX;
    }
    if (dx + x >= Width - 3) {
        dx = -dx;
        DirX = -DirX;
    }
    if (dy + y < 3) {
        // The shipped lower-y correction negates dx, not dy.
        dy = -dx;
        DirY = -DirY;
    }
    if (dy + y >= Height - 3) {
        dy = -dy;
        DirY = -DirY;
    }

    x = x + dx;
    y = dy + y;
    Point[NumNodes].x = x;
    Point[NumNodes].y = y;
    int result = NumNodes;
    NumNodes = result + 1;
    return result;
}

void PointMaker::DrawPrimaryIntoProbabilityArray()
{
    int radius = PrimaryRadius;
    int left = Prime.x - radius;
    int top = Prime.y - radius;
    int bottom = Prime.y + radius;
    int right = Prime.x + radius;

    if (left < 0) left = 0;
    if (top < 0) top = 0;
    int max_x = Width - 1;
    if (right > max_x) right = max_x;
    int max_y = Height - 1;
    if (bottom > max_y) bottom = max_y;

    ProbabilityAdd = 1;
    int ring = 0;
    if (radius > 0) {
        do {
            AddingRect(left, top, right, bottom);
            ProbabilityAdd++;
            ring++;
            bottom--;
            top++;
            right--;
            left++;
        } while (ring < PrimaryRadius);
    }
}

void PointMaker::DrawCurrentBranchIntoProbArray(int which)
{
    int point_x = Point[which].x;
    int radius;
    int point_y;
    int max_x;
    int min_x;
    int min_y;
    int max_y;
    int ring;

    radius = BranchRadius;
    point_y = Point[which].y;
    min_x = point_x - radius;
    max_x = radius + point_x;
    min_y = point_y - radius;
    max_y = point_y + radius;

    if (max_x >= 0 && max_y >= 0 && min_x < Width && min_y < Height) {
        if (min_x < 0) min_x = 0;
        if (min_y < 0) min_y = 0;
        if (max_x >= Width) max_x = Width - 1;
        if (max_y >= Height) max_y = Height - 1;

        ProbabilityAdd = 1;
        ring = 0;
        if (BranchRadius > 0) {
            for (; ring < BranchRadius; ++ring) {
                AddingRect(min_x, min_y, max_x, max_y);
                ++min_x;
                if (min_x >= Width || ++min_y >= Height || --max_x < 0 ||
                    --max_y < 0) {
                    break;
                }
                ++ProbabilityAdd;
            }
        }

        int prob_idx = Width * Point[which].y + Point[which].x;
        int prob_add = ProbabilityAdd;
        char add = (char)prob_add;
        if (prob_idx >= 1 && prob_idx < SizeArrays - 1) {
            char& cur = ProbArray[prob_idx];
            if (cur == 0) {
                cur = add;
                ProbabilityTiles++;
                return;
            }
            if (prob_add + (int)cur < 0xFF) {
                cur = add + cur;
                return;
            }
            cur = (char)-1;
        }
    }
}

void PointMaker::DrawCurrentSatelliteIntoProbArray(int point)
{
    int radius = SatelliteRadius;
    ProbabilityAdd = 2;
    while (radius >= 0) {
        AddingCircle(Point[point].x, Point[point].y, radius);
        ProbabilityAdd++;
        radius--;
    }

    int prob_idx = Point[point].y * Width + Point[point].x;
    int prob_add = ProbabilityAdd;
    if (prob_idx >= 1 && prob_idx < SizeArrays - 1) {
        char* cell = ProbArray + prob_idx;
        if (*cell == 0) {
            *cell = (char)prob_add;
            ProbabilityTiles++;
        } else {
            int total = prob_add + (int)*cell;
            if (total < 0xFF) {
                *cell = (char)total;
            } else {
                *cell = (char)-1;
            }
        }
    }
}

void PointMaker::AddingRect(int x, int y, int w, int h)
{
    int iVar2;
    int iVar3;
    int iVar5;
    int iVar6;
    int iVar8;
    iVar5 = Width * y + x;
    iVar6 = w - x;
    iVar3 = h - y - 1;
    iVar8 = iVar3 * Width + iVar5;

    if (iVar6 >= 0) {
        if (h - y >= 0) {
            iVar2 = iVar5;
            if (w - x >= 0) {
                w = iVar6 + 1;
                do {
                    int prob_add = ProbabilityAdd;
                    if (iVar2 >= 1 && iVar2 < SizeArrays - 1) {
                        char* cell = ProbArray + iVar2;
                        if (*cell == 0) {
                            *cell = (char)prob_add;
                            ProbabilityTiles++;
                        } else if (prob_add + (int)*cell < 0xFF) {
                            *cell = (char)(prob_add + (int)*cell);
                        } else {
                            *cell = (char)-1;
                        }
                    }
                    prob_add = ProbabilityAdd;
                    if (iVar8 >= 1 && iVar8 < SizeArrays - 1) {
                        char* cell = ProbArray + iVar8;
                        char value = ProbArray[iVar8];
                        if (value == 0) {
                            *cell = (char)prob_add;
                            ProbabilityTiles++;
                        } else if (prob_add + (int)value < 0xFF) {
                            *cell = (char)(prob_add + (int)value);
                        } else {
                            *cell = (char)-1;
                        }
                    }
                    iVar8++;
                    iVar2++;
                    w--;
                } while (w != 0);
            }

            iVar5 += Width;
            if (iVar3 >= 0) {
                for (; iVar3 != 0; iVar3--) {
                    int prob_add = ProbabilityAdd;
                    if (iVar5 >= 1 && iVar5 < SizeArrays - 1) {
                        char* cell = ProbArray + iVar5;
                        char value = ProbArray[iVar5];
                        if (value == 0) {
                            *cell = (char)prob_add;
                            ProbabilityTiles++;
                        } else if (prob_add + (int)value < 0xFF) {
                            *cell = (char)(prob_add + (int)value);
                        } else {
                            *cell = (char)-1;
                        }
                    }
                    iVar8 = iVar6 + iVar5;
                    prob_add = ProbabilityAdd;
                    if (iVar8 >= 1 && iVar8 < SizeArrays - 1) {
                        char* cell = ProbArray + iVar8;
                        if (*cell == 0) {
                            *cell = (char)prob_add;
                            ProbabilityTiles++;
                        } else if (prob_add + (int)*cell < 0xFF) {
                            *cell = (char)(prob_add + (int)*cell);
                        } else {
                            *cell = (char)-1;
                        }
                    }
                    iVar5 += Width;
                }
            }
        }
    }
}

void PointMaker::AddingCircle(int param_1, int param_2, int param_3)
{
    if (param_3 == 0) param_3 = 1;

    int step = 360 / (param_3 * 3);
    float width = (float)Width;
    float offset;
    float x;
    float curx;
    float W;
    float lasty;
    lasty = 0.0f;
    W = 0.0f;
    float lastx;
    for (int angle = 0; angle < 360; angle += step) {
        lastx = trig.sin360(angle) * (float)param_3;
        curx = trig.cos360(angle) * (float)param_3;

        if (lastx != lasty || curx != W) {
            int loc = (int)(width * curx + lastx);
            int prob_add = ProbabilityAdd;
            char add = (char)prob_add;
            if (loc >= 1 && loc < SizeArrays - 1) {
                char& cur = ProbArray[loc];
                if (cur == 0) {
                    ProbArray[loc] = add;
                    ProbabilityTiles++;
                } else if (prob_add + (int)cur < 0xFF) {
                    ProbArray[loc] = add + cur;
                } else {
                    ProbArray[loc] = (char)-1;
                }
            }

            lasty = lastx;
            W = curx;
            int random = debug_rand(
                (char*)"C:\\msdev\\work\\age1_x1\\fractal.cpp", 0x1F1);
            if (random % 2) {
                x = trig.sin360(angle) * (float)param_3;
                offset = debug_rand(
                    (char*)"C:\\msdev\\work\\age1_x1\\fractal.cpp", 499) %
                    2 + x - 1.0f;
                float y = trig.cos360(angle) * (float)param_3;
                int random_2 = debug_rand(
                    (char*)"C:\\msdev\\work\\age1_x1\\fractal.cpp", 500) % 2;
                loc = (int)(width * ((float)random_2 + y - 1.0f) + offset);
                int addp1 = ProbabilityAdd + 1;
                if (loc >= 1 && loc < SizeArrays - 1) {
                    char add = (char)addp1;
                    char& cur = ProbArray[loc];
                    if (cur == 0) {
                        ProbArray[loc] = add;
                        ProbabilityTiles++;
                    } else if (addp1 + (int)cur < 0xFF) {
                        ProbArray[loc] = add + cur;
                    } else {
                        ProbArray[loc] = (char)-1;
                    }
                }
            }
        }
    }
}

void PointMaker::CreateMapBasedOnProbabilityArray()
{
    int hits = 0;
    int i = 0;
    if (SizeArrays > 0) {
        do {
            if (ProbArray[i] != 0) {
                ++hits;
                PlacementArray[i] = 1;
            }
            ++i;
        } while (i < SizeArrays);
    }
    NumTilesActuallyChosen += hits;
}

void PointMaker::SetPoint(int value_x, int value_y)
{
    x = value_x;
    y = value_y;
}

void PointMaker::SetMaxNumberOfBranches(int value)
{
    MaxNumberOfBranches = value;
}

void PointMaker::SetChanceOfNextNode(int value)
{
    ChanceOfNextNode = value;
}

void PointMaker::SetNumberOfSatellites(int value)
{
    NumberOfSatellites = value;
}

void PointMaker::SetSplitsPerBranch(int value)
{
    NumSplitsPerBranch = value;
}

void PointMaker::SetWidthAndHeight(int width, int height)
{
    Width = width;
    Height = height;
}

void PointMaker::SetStartPositionRadius(int value)
{
    PrimaryRadius = value;
}

void PointMaker::SetBranchsRadius(int value)
{
    BranchRadius = value;
}

void PointMaker::SetSatelliteRadius(int value)
{
    SatelliteRadius = value;
}

void PointMaker::SetMaxNumberOfBranchLevels(int value)
{
    MaxBranchFlag = 1;
    MaxNumberOfBranchLevels = value;
}

void PointMaker::SetSatelliteDistance(int value)
{
    SatelliteDistance = value;
}

void PointMaker::SetBranchDistance(int value)
{
    BranchDistance = value;
}

void PointMaker::SetMinimumNumberOfTiles(int value)
{
    MinimumNumTiles = value;
}

void PointMaker::SetDrawToOneArray()
{
    DrawToOneArrayFlag = 1;
}

void PointMaker::SetBorderDepthPercentage(int value)
{
    BorderDepthPercentage = value;
    if (value > 0x1E) {
        BorderDepthPercentage = 0x1E;
    }
    if (BorderDepthPercentage < 5) {
        BorderDepthPercentage = 5;
    }
    PrepareLimits();
}

char* PointMaker::RetrieveMap()
{
    return PlacementArray;
}

char* PointMaker::RetrieveProbMap()
{
    return ProbArray;
}

void PointMaker::ErrorCheckingAndCorrection()
{
    int width = Width;
    int size = Height * width;
    SizeArrays = size;

    if (BranchRadius > width) BranchRadius = (width * 2) / 3;
    if (SatelliteRadius > width) SatelliteRadius = (width * 2) / 3;
    if (PrimaryRadius > width) PrimaryRadius = (width * 2) / 3;
    if (NumSplitsPerBranch > 4) NumSplitsPerBranch = 4;
    if (NumberOfSatellites > 4) NumberOfSatellites = 4;

    size = size / MinimumNumTiles;
    DrawToOneArrayFlag = 0;
    int chance = (10 - size) * 10;
    ChanceOfNextNode = chance;
    if (chance < 0x23) ChanceOfNextNode = 0x23;
    if (ChanceOfNextNode > 0x50) ChanceOfNextNode = 0x50;
    if (MaxBranchFlag == 0) {
        MaxNumberOfBranchLevels = size - ChanceOfNextNode / 5;
    }
    if (MaxNumberOfBranchLevels < 10) MaxNumberOfBranchLevels = 10;
    if (MaxNumberOfBranchLevels > 0x1E) MaxNumberOfBranchLevels = 0x1E;
    MaxBranchFlag = 0;
}

void PointMaker::PrepareLimits()
{
    int width = Width;
    int border = BorderDepthPercentage;
    int left = (border * width) / 100;
    LeftLimit = left;
    RightLimit = width - left;
    int height = Height;
    int top = (border * height) / 100;
    TopLimit = top;
    BottomLimit = height - top;
}

void PointMaker::MapCleanUpEliminatingSinglesOnly()
{
    int bottom = Height - 1;
    int row = 1;
    int right = Width - 1;
    if (bottom > 1) {
        do {
            int column = 1;
            if (right > 1) {
                do {
                    int width = Width;
                    char* cell = PlacementArray + row * width + column;
                    int neighbors = 0;
                    if (cell[-width] > 0) neighbors = 1;
                    if (cell[-1] > 0) neighbors++;
                    if (cell[1] > 0) neighbors++;
                    if (cell[width] > 0) neighbors++;
                    if (*cell != 0 && neighbors == 0) {
                        *cell = 0;
                    }
                    column++;
                } while (column < right);
            }
            row++;
        } while (row < bottom);
    }
}

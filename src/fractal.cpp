
#include "../include/fractal.h"
#include "../include/trig.h"

#include <stdlib.h>
#include <string.h>

extern int __cdecl debug_rand(char* file, int line);
extern TRIGONOMETRY trig;

void PointMaker::SetDefaultValues() {
    NumberOfSatellites = 2;
    NumSplitsPerBranch = 3;
    Height = 280;
    Width = 280;
    SatelliteRadius = 2;
    BranchRadius = 3;
    BranchDistance = 3;
    ChanceOfNextNode = 50;
    MaxNumberOfBranches = 6;
    PrimaryRadius = 4;
    BorderDepthPercentage = 15;
    MaxBranchFlag = 0;
    SatelliteDistance = 1;
    MaxNumberOfBranchLevels = 16;
    MinimumNumTiles = 2000;
    memset(Point, 0, sizeof(Point));
    DoNotDrawOnFlag = 0;
    DrawOnOnlyFlag = 0;
    DrawToOneArrayFlag = 0;
    DrawOnlyInExternalArrayFlag = 0;
}

PointMaker::PointMaker() {
    ProbArray = 0;
    PlacementArray = 0;
    SetDefaultValues();
    MakeArrays();
    CreateMasks();
}

PointMaker::~PointMaker() {
    DeleteArrays();
    SetDefaultValues();
    ProbArray = 0;
    PlacementArray = 0;
    DeleteMasks();
}

void PointMaker::CreateMasks() {
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

void PointMaker::DeleteMasks() {
    operator delete(Mask_2x2);
    operator delete(Mask_3x3);
    operator delete(Mask_4x4);
    operator delete(Mask_5x5);
}

void PointMaker::DrawMask(int x, int y, int size) {
    int rows;
    int len;
    char* maskptr;
    int w;
    int mapptr;
    char* destination;
    char value;

    if (x > Width) return;
    if (y > Height) return;
    if (size + 2 + x < 0) return;
    if (size + 2 + y < 0) return;

    len = size + 2;
    if (size == 2) {
        if (x + 4 <= Width && x < 0) {
            x = 0;
        }
        if (y + 4 <= Height && y < 0) {
            y = 0;
        }
    } else if (size == 3) {
        if (x + 5 <= Width && x < 0) {
            x = 0;
        }
        y += (unsigned)(Height < 5);
    }

    if (size == 4) {
        maskptr = Mask_4x4;
        if (x + 6 > Width) {
            w = Width - x;
        } else if (x < 0) {
            maskptr -= x;
            w = x + 6;
            x = 0;
        } else {
            w = 6;
        }
        if (y + 6 > Height) {
            rows = Height - y;
        } else if (y < 0) {
            maskptr -= y * Width;
            rows = y + 6;
            y = 0;
        } else {
            rows = 6;
        }
    } else {
        maskptr = Mask_5x5;
        if (x + 7 > Width) {
            w = Width - x;
        } else if (x < 0) {
            maskptr -= x;
            w = x + 7;
            x = 0;
        } else {
            w = 7;
        }
        if (y + 7 > Height) {
            rows = Height - y;
        } else if (y < 0) {
            maskptr -= y * Width;
            rows = y + 7;
            y = 0;
        } else {
            rows = 7;
        }
    }

    mapptr = y * Width + x;
    while (rows-- != 0) {
        if (w > 0) {
            int map = mapptr;
            int count = w;
            int mask_offset = (int)maskptr - map;
            do {
                int mask = *(char*)(mask_offset + map);
                if (map >= 1 && map < SizeArrays - 1) {
                    value = ProbArray[map];
                    destination = ProbArray + map;
                    if (value == 0) {
                        *destination = mask;
                        ProbabilityTiles++;
                    } else if (mask + (int)value < 0xFF) {
                        *destination = (char)(mask + value);
                    } else {
                        *destination = (char)-1;
                    }
                }
                map++;
                count--;
            } while (count != 0);
        }
        maskptr += len;
        mapptr += Width;
    }
}

void PointMaker::ClearArrays() {
    if (DrawToOneArrayFlag == 0 && PlacementArray != 0) {
        memset(PlacementArray, 0, SizeArrays);
    }
    if (ProbArray != 0) {
        memset(ProbArray, 0, SizeArrays);
    }
}

void PointMaker::DeleteArrays() {
    if (ProbArray != 0) {
        operator delete(ProbArray);
    }
    if (PlacementArray != 0) {
        operator delete(PlacementArray);
    }
    ProbArray = 0;
    PlacementArray = 0;
}

void PointMaker::MakeArrays() {
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

int PointMaker::CreateShape() {
    NumNodes = 0;
    ClearArrays();
    PrepareLimits();

    x = debug_rand("C:\\msdev\\work\\age1_x1\\fractal.cpp", 215) %
        ((Width * (50 - LeftLimit) * 2) / 100) + LeftLimit;
    y = debug_rand("C:\\msdev\\work\\age1_x1\\fractal.cpp", 216) %
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

int PointMaker::CreateShape(int xt, int yt) {
    NumNodes = 0;
    ClearArrays();
    PrepareLimits();
    y = yt;
    Prime.y = yt;
    ProbabilityTiles = 0;
    NumNodes = 0;
    x = xt;
    Prime.x = xt;
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

void PointMaker::Branch(int which) {
    if (CurrentNumberOfBranchLevels > 1 &&
        debug_rand("C:\\msdev\\work\\age1_x1\\fractal.cpp", 278) % 100 <
            ChanceOfNextNode * 10 &&
        ProbabilityTiles < MinimumNumTiles * 2) {
        CurrentNumberOfBranchLevels--;
        for (int i = 0; i < NumSplitsPerBranch; i++) {
            x = Point[which].x;
            y = Point[which].y;
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

int PointMaker::MakeFirstLink() {
    int dx = debug_rand("C:\\msdev\\work\\age1_x1\\fractal.cpp", 308);
    dx = dx % BranchDistance + 2;
    if (debug_rand("C:\\msdev\\work\\age1_x1\\fractal.cpp", 308) % 2)
        dx = -dx;

    int dy = debug_rand("C:\\msdev\\work\\age1_x1\\fractal.cpp", 309);
    dy = dy % BranchDistance + 2;
    if (debug_rand("C:\\msdev\\work\\age1_x1\\fractal.cpp", 309) % 2)
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

int PointMaker::MakeNewLink() {
    int max_x;
    int r;
    int dx = debug_rand("C:\\msdev\\work\\age1_x1\\fractal.cpp", 330);
    dx = dx % BranchDistance + 1;
    if (debug_rand("C:\\msdev\\work\\age1_x1\\fractal.cpp", 330) % 2)
        dx = -dx;

    int dy = debug_rand("C:\\msdev\\work\\age1_x1\\fractal.cpp", 331);
    dy = dy % BranchDistance + 1;
    if (debug_rand("C:\\msdev\\work\\age1_x1\\fractal.cpp", 331) % 2)
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

    r = debug_rand("C:\\msdev\\work\\age1_x1\\fractal.cpp", 346);
    if (r % 2) {
        r = debug_rand("C:\\msdev\\work\\age1_x1\\fractal.cpp", 346);
        DirX = DirX + r % 3 - 1;
    }
    r = debug_rand("C:\\msdev\\work\\age1_x1\\fractal.cpp", 347);
    if (r % 2) {
        r = debug_rand("C:\\msdev\\work\\age1_x1\\fractal.cpp", 347);
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

int PointMaker::MakeSatelliteLink() {
    int dx = debug_rand("C:\\msdev\\work\\age1_x1\\fractal.cpp", 357);
    dx = dx % SatelliteDistance + 1;
    int r = debug_rand("C:\\msdev\\work\\age1_x1\\fractal.cpp", 357);
    if (r % 2) dx = -dx;

    int dy = debug_rand("C:\\msdev\\work\\age1_x1\\fractal.cpp", 358);
    dy = dy % SatelliteDistance + 1;
    r = debug_rand("C:\\msdev\\work\\age1_x1\\fractal.cpp", 358);
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

void PointMaker::DrawPrimaryIntoProbabilityArray() {
    int i;
    int call_right;
    int call_top;
    int call_left;
    int call_bottom;
    int prime_x = Prime.x;
    int prime_y = Prime.y;
    int radius = PrimaryRadius;
    int left = prime_x - radius;
    int top = prime_y - radius;
    int desty = prime_y + radius;
    int right = prime_x + radius;

    if (left < 0) left = 0;
    if (top < 0) top = 0;
    int max_x = Width - 1;
    if (right > max_x) right = max_x;
    int max_y = Height - 1;
    if (desty > max_y) {
        desty = max_y;
    }

    ProbabilityAdd = 1;
    i = 0;
    if (radius > 0) {
        do {
            call_left = left;
            call_top = top;
            left++;
            call_right = right;
            top++;
            call_bottom = desty;
            right--;
            desty--;
            AddingRect(call_left, call_top, call_right, call_bottom);
            ProbabilityAdd++;
            i++;
        } while (i < PrimaryRadius);
    }
}

void PointMaker::DrawCurrentBranchIntoProbArray(int which) {
    int point_x = Point[which].x;
    int radius;
    int point_y;
    int max_x;
    int min_x;
    int min_y;
    int desty;
    int i;

    radius = BranchRadius;
    point_y = Point[which].y;
    min_x = point_x - radius;
    max_x = radius + point_x;
    min_y = point_y - radius;
    desty = point_y + radius;

    if (max_x >= 0 && desty >= 0 && min_x < Width && min_y < Height) {
        if (min_x < 0) min_x = 0;
        if (min_y < 0) min_y = 0;
        if (max_x >= Width) max_x = Width - 1;
        if (desty >= Height) desty = Height - 1;

        ProbabilityAdd = 1;
        i = 0;
        if (BranchRadius > 0) {
            for (; i < BranchRadius; ++i) {
                AddingRect(min_x, min_y, max_x, desty);
                ++min_x;
                if (min_x >= Width || ++min_y >= Height || --max_x < 0 ||
                    --desty < 0) {
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

void PointMaker::DrawCurrentSatelliteIntoProbArray(int which) {
    int radius = SatelliteRadius;
    ProbabilityAdd = 2;
    while (radius >= 0) {
        AddingCircle(Point[which].x, Point[which].y, radius);
        ProbabilityAdd++;
        radius--;
    }

    int prob_idx = Point[which].y * Width + Point[which].x;
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

void PointMaker::AddingRect(int x1, int y1, int x2, int y2) {
    int start = y1 * Width + x1;
    int w = x2 - x1;
    int height = y2 - y1;
    int rows = height - 1;
    int top = rows * Width + start;

    if (w < 0) return;
    if (height < 0) return;

    if (w >= 0) {
        int count = w + 1;
        int map = start;
        do {
            int add_value = ProbabilityAdd;
            char add = (char)add_value;
            if (map > 0 && map < SizeArrays - 1) {
                char* cell = ProbArray + map;
                char value = *cell;
                if (value == 0) {
                    *cell = add;
                    ProbabilityTiles++;
                } else if (add_value + (int)value < 0xFF) {
                    *cell = add + value;
                } else {
                    *cell = (char)-1;
                }
            }

            add_value = ProbabilityAdd;
            add = (char)add_value;
            if (top > 0 && top < SizeArrays - 1) {
                char* cell = ProbArray + top;
                char value = *cell;
                if (value == 0) {
                    *cell = add;
                    ProbabilityTiles++;
                } else if (add_value + (int)value < 0xFF) {
                    *cell = add + value;
                } else {
                    *cell = (char)-1;
                }
            }
            ++map;
            ++top;
            --count;
        } while (count != 0);
    }

    start += Width;
    if (rows >= 0) {
        if (rows != 0) {
            do {
                int add_value = ProbabilityAdd;
                char add = (char)add_value;
                if (start > 0 && start < SizeArrays - 1) {
                    char* cell = ProbArray + start;
                    char value = *cell;
                    if (value == 0) {
                        *cell = add;
                        ProbabilityTiles++;
                    } else if (add_value + (int)value < 0xFF) {
                        *cell = add + value;
                    } else {
                        *cell = (char)-1;
                    }
                }

                int other = start + w;
                add_value = ProbabilityAdd;
                add = (char)add_value;
                if (other > 0 && other < SizeArrays - 1) {
                    char* cell = ProbArray + other;
                    char value = *cell;
                    if (value == 0) {
                        *cell = add;
                        ProbabilityTiles++;
                    } else if (add_value + (int)value < 0xFF) {
                        *cell = add + value;
                    } else {
                        *cell = (char)-1;
                    }
                }
                start += Width;
                --rows;
            } while (rows != 0);
        }
    }
}

void PointMaker::AddingCircle(int x1, int y1, int radius) {
    if (radius == 0) radius = 1;

    int step = 360 / (radius * 3);
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
        lastx = trig.sin360(angle) * (float)radius;
        curx = trig.cos360(angle) * (float)radius;

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
                (char*)"C:\\msdev\\work\\age1_x1\\fractal.cpp", 497);
            if (random % 2) {
                x = trig.sin360(angle) * (float)radius;
                offset = debug_rand(
                    (char*)"C:\\msdev\\work\\age1_x1\\fractal.cpp", 499) %
                    2 + x - 1.0f;
                float y = trig.cos360(angle) * (float)radius;
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

void PointMaker::CreateMapBasedOnProbabilityArray() {
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

void PointMaker::SetPoint(int x1, int y1) {
    x = x1;
    y = y1;
}

void PointMaker::SetMaxNumberOfBranches(int num) {
    MaxNumberOfBranches = num;
}

void PointMaker::SetChanceOfNextNode(int num) {
    ChanceOfNextNode = num;
}

void PointMaker::SetNumberOfSatellites(int num) {
    NumberOfSatellites = num;
}

void PointMaker::SetSplitsPerBranch(int num) {
    NumSplitsPerBranch = num;
}

void PointMaker::SetWidthAndHeight(int w, int h) {
    Width = w;
    Height = h;
}

void PointMaker::SetStartPositionRadius(int num) {
    PrimaryRadius = num;
}

void PointMaker::SetBranchsRadius(int num) {
    BranchRadius = num;
}

void PointMaker::SetSatelliteRadius(int num) {
    SatelliteRadius = num;
}

void PointMaker::SetMaxNumberOfBranchLevels(int num) {
    MaxBranchFlag = 1;
    MaxNumberOfBranchLevels = num;
}

void PointMaker::SetSatelliteDistance(int num) {
    SatelliteDistance = num;
}

void PointMaker::SetBranchDistance(int num) {
    BranchDistance = num;
}

void PointMaker::SetMinimumNumberOfTiles(int num) {
    MinimumNumTiles = num;
}

void PointMaker::SetDrawToOneArray() {
    DrawToOneArrayFlag = 1;
}

void PointMaker::SetBorderDepthPercentage(int num) {
    BorderDepthPercentage = num;
    if (num > 30) {
        BorderDepthPercentage = 30;
    }
    if (BorderDepthPercentage < 5) {
        BorderDepthPercentage = 5;
    }
    PrepareLimits();
}

char* PointMaker::RetrieveMap() {
    return PlacementArray;
}

char* PointMaker::RetrieveProbMap() {
    return ProbArray;
}

void PointMaker::ErrorCheckingAndCorrection() {
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
    if (chance < 35) ChanceOfNextNode = 35;
    if (ChanceOfNextNode > 80) ChanceOfNextNode = 80;
    if (MaxBranchFlag == 0) {
        MaxNumberOfBranchLevels = size - ChanceOfNextNode / 5;
    }
    if (MaxNumberOfBranchLevels < 10) MaxNumberOfBranchLevels = 10;
    if (MaxNumberOfBranchLevels > 30) MaxNumberOfBranchLevels = 30;
    MaxBranchFlag = 0;
}

void PointMaker::PrepareLimits() {
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

void PointMaker::MapCleanUpEliminatingSinglesOnly() {
    int h = Height - 1;
    int row = 1;
    int w = Width - 1;
    if (h > 1) {
        do {
            int column = 1;
            if (w > 1) {
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
                } while (column < w);
            }
            row++;
        } while (row < h);
    }
}

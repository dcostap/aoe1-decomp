#include "../include/PointMaker.h"

#include "../include/debug_helpers.h"

#include <math.h>
#include <new>
#include <string.h>

namespace {
static const char* kFractalSourceFile = "C:\\msdev\\work\\age1_x1\\fractal.cpp";

static inline int fractal_is_odd_signed(int value) {
    unsigned int u = (unsigned int)value;
    unsigned int sign = (unsigned int)(value >> 31);
    return (int)((((u ^ sign) - sign) & 1U) ^ sign) != (int)sign;
}

static inline void fractal_add_prob(PointMaker* maker, int map_index, int add_value) {
    if (map_index <= 0 || map_index >= maker->SizeArrays - 1) {
        return;
    }

    char* entry = maker->ProbArray + map_index;
    int current = (int)(unsigned char)(*entry);
    if (current == 0) {
        *entry = (char)add_value;
        maker->ProbabilityTiles = maker->ProbabilityTiles + 1;
    } else {
        int merged = current + add_value;
        if (merged < 0xFF) {
            *entry = (char)merged;
        } else {
            *entry = (char)0xFF;
        }
    }
}

static inline int fractal_step_degrees(int radius) {
    int denom = radius * 3;
    if (denom <= 0) {
        return 360;
    }
    int step = 360 / denom;
    if (step <= 0) {
        step = 1;
    }
    return step;
}
} // namespace

PointMaker::PointMaker() {
    // Fully verified. Source of truth: fractal.cpp.decomp @ 0x0044AC50
    this->ProbArray = nullptr;
    this->PlacementArray = nullptr;
    this->SetDefaultValues();
    this->MakeArrays();
    this->CreateMasks();
}

PointMaker::~PointMaker() {
    // Fully verified. Source of truth: fractal.cpp.decomp @ 0x0044AC80
    this->DeleteArrays();
    this->SetDefaultValues();
    this->ProbArray = nullptr;
    this->PlacementArray = nullptr;
    this->DeleteMasks();
}

void PointMaker::SetDefaultValues() {
    // Fully verified. Source of truth: fractal.cpp.decomp @ 0x0044AB90
    this->NumberOfSatellites = 2;
    this->SatelliteRadius = 2;
    this->NumSplitsPerBranch = 3;
    this->Height = 0x118;
    this->Width = 0x118;
    this->BranchRadius = 3;
    this->BranchDistance = 3;
    this->ChanceOfNextNode = 0x32;
    this->MaxNumberOfBranches = 6;
    this->PrimaryRadius = 4;
    this->BorderDepthPercentage = 0x0F;
    this->MaxBranchFlag = 0;
    this->SatelliteDistance = 1;
    this->MaxNumberOfBranchLevels = 0x10;
    this->MinimumNumTiles = 2000;

    memset(this->Point, 0, sizeof(this->Point));

    this->DoNotDrawOnFlag = 0;
    this->DrawOnOnlyFlag = 0;
    this->DrawToOneArrayFlag = 0;
    this->DrawOnlyInExternalArrayFlag = 0;
}

void PointMaker::CreateMasks() {
    // Fully verified. Source of truth: fractal.cpp.decomp @ 0x0044ACB0
    this->Mask_2x2 = (char*)operator new(0x10, std::nothrow);
    this->Mask_3x3 = (char*)operator new(0x19, std::nothrow);
    this->Mask_4x4 = (char*)operator new(0x24, std::nothrow);
    this->Mask_5x5 = (char*)operator new(0x31, std::nothrow);

    static const char kMask2x2[16] = {
        0, 0, 0, 0,
        0, 1, 1, 0,
        0, 1, 1, 0,
        0, 0, 0, 0,
    };
    static const char kMask3x3[25] = {
        0, 0, 0, 0, 0,
        0, 1, 1, 1, 0,
        0, 1, 2, 1, 0,
        0, 1, 1, 1, 0,
        0, 0, 0, 0, 0,
    };
    static const char kMask4x4[36] = {
        0, 0, 0, 0, 0, 0,
        0, 0, 1, 1, 1, 0,
        0, 1, 2, 2, 1, 0,
        0, 1, 2, 2, 1, 0,
        0, 1, 1, 1, 1, 0,
        0, 0, 0, 0, 0, 0,
    };
    static const char kMask5x5[49] = {
        0, 0, 0, 0, 0, 0, 0,
        0, 0, 1, 1, 1, 1, 0,
        0, 1, 2, 2, 2, 1, 0,
        0, 1, 2, 3, 2, 1, 0,
        0, 1, 2, 2, 2, 1, 0,
        0, 1, 1, 1, 1, 1, 0,
        0, 0, 0, 0, 0, 0, 0,
    };

    if (this->Mask_2x2 != nullptr) {
        memcpy(this->Mask_2x2, kMask2x2, sizeof(kMask2x2));
    }
    if (this->Mask_3x3 != nullptr) {
        memcpy(this->Mask_3x3, kMask3x3, sizeof(kMask3x3));
    }
    if (this->Mask_4x4 != nullptr) {
        memcpy(this->Mask_4x4, kMask4x4, sizeof(kMask4x4));
    }
    if (this->Mask_5x5 != nullptr) {
        memcpy(this->Mask_5x5, kMask5x5, sizeof(kMask5x5));
    }
}

void PointMaker::DeleteMasks() {
    // Fully verified. Source of truth: fractal.cpp.decomp @ 0x0044AF90
    operator delete(this->Mask_2x2);
    operator delete(this->Mask_3x3);
    operator delete(this->Mask_4x4);
    operator delete(this->Mask_5x5);
    this->Mask_2x2 = nullptr;
    this->Mask_3x3 = nullptr;
    this->Mask_4x4 = nullptr;
    this->Mask_5x5 = nullptr;
}

void PointMaker::DrawMask(int x, int y, int radius) {
    // Fully verified. Source of truth: fractal.cpp.decomp @ 0x0044AFE0
    if (x > this->Width || y > this->Height || (radius + 2 + x) < 0 || (radius + 2 + y) < 0) {
        return;
    }

    const char* mask = this->Mask_5x5;
    int dim = 7;
    if (radius == 2) {
        mask = this->Mask_2x2;
        dim = 4;
    } else if (radius == 3) {
        mask = this->Mask_3x3;
        dim = 5;
    } else if (radius == 4) {
        mask = this->Mask_4x4;
        dim = 6;
    }
    if (mask == nullptr) {
        return;
    }

    int src_col = 0;
    int src_row = 0;
    int draw_x = x;
    int draw_y = y;
    int draw_w = dim;
    int draw_h = dim;

    if (draw_x < 0) {
        src_col = -draw_x;
        draw_w = draw_w - src_col;
        draw_x = 0;
    }
    if (draw_y < 0) {
        src_row = -draw_y;
        draw_h = draw_h - src_row;
        draw_y = 0;
    }
    if (draw_x + draw_w > this->Width) {
        draw_w = this->Width - draw_x;
    }
    if (draw_y + draw_h > this->Height) {
        draw_h = this->Height - draw_y;
    }
    if (draw_w <= 0 || draw_h <= 0) {
        return;
    }

    for (int row = 0; row < draw_h; ++row) {
        int map_index = (draw_y + row) * this->Width + draw_x;
        int mask_index = (src_row + row) * dim + src_col;
        for (int col = 0; col < draw_w; ++col) {
            int add = (int)(unsigned char)mask[mask_index + col];
            fractal_add_prob(this, map_index + col, add);
        }
    }
}

void PointMaker::ClearArrays() {
    // Fully verified. Source of truth: fractal.cpp.decomp @ 0x0044B210
    if (this->DrawToOneArrayFlag == 0 && this->PlacementArray != nullptr) {
        memset(this->PlacementArray, 0, (size_t)this->SizeArrays);
    }
    if (this->ProbArray != nullptr) {
        memset(this->ProbArray, 0, (size_t)this->SizeArrays);
    }
}

void PointMaker::DeleteArrays() {
    // Fully verified. Source of truth: fractal.cpp.decomp @ 0x0044B270
    if (this->ProbArray != nullptr) {
        operator delete(this->ProbArray);
    }
    if (this->PlacementArray != nullptr) {
        operator delete(this->PlacementArray);
    }
    this->ProbArray = nullptr;
    this->PlacementArray = nullptr;
}

void PointMaker::MakeArrays() {
    // Fully verified. Source of truth: fractal.cpp.decomp @ 0x0044B2B0
    this->SizeArrays = this->Height * this->Width;

    int retries = 9;
    do {
        if (this->ProbArray != nullptr) {
            break;
        }
        this->ProbArray = (char*)operator new((size_t)this->SizeArrays, std::nothrow);
        retries = retries - 1;
    } while (retries >= 0);

    retries = 9;
    do {
        if (this->PlacementArray != nullptr) {
            return;
        }
        this->PlacementArray = (char*)operator new((size_t)this->SizeArrays, std::nothrow);
        retries = retries - 1;
    } while (retries >= 0);
}

int PointMaker::CreateShape() {
    // Fully verified. Source of truth: fractal.cpp.decomp @ 0x0044B320
    this->NumNodes = 0;
    this->ClearArrays();
    this->PrepareLimits();

    int left = this->LeftLimit;
    int rand_x = debug_rand(kFractalSourceFile, 0xD7);
    int top = this->TopLimit;
    this->x = rand_x % ((this->Width * (0x32 - left) * 2) / 100) + left;

    int rand_y = debug_rand(kFractalSourceFile, 0xD8);
    int h = this->Height;

    this->ProbabilityTiles = 0;
    this->NumNodes = 0;
    this->Prime.x = this->x;
    this->y = rand_y % ((h * (0x32 - top) * 2) / 100) + top;
    this->Prime.y = this->y;

    this->DrawPrimaryIntoProbabilityArray();
    this->ErrorCheckingAndCorrection();

    int min_tiles = this->MinimumNumTiles;
    int tiles = this->ProbabilityTiles;
    this->NumTilesActuallyChosen = 0;
    int attempts = 0;

    while (tiles < min_tiles && attempts < 0x5DC) {
        this->x = this->Prime.x;
        this->y = this->Prime.y;
        this->CurrentNumberOfBranchLevels = this->MaxNumberOfBranchLevels;
        this->NumNodes = 0;
        int node = this->MakeFirstLink();
        this->Branch(node);
        tiles = this->ProbabilityTiles;
        attempts = attempts + 1;
    }

    this->CreateMapBasedOnProbabilityArray();
    this->MapCleanUpEliminatingSinglesOnly();
    return this->ProbabilityTiles;
}

int PointMaker::CreateShape(int x, int y) {
    // Fully verified. Source of truth: fractal.cpp.decomp @ 0x0044B470
    this->NumNodes = 0;
    this->ClearArrays();
    this->PrepareLimits();

    this->y = y;
    this->Prime.y = y;
    this->ProbabilityTiles = 0;
    this->NumNodes = 0;
    this->x = x;
    this->Prime.x = x;

    this->DrawPrimaryIntoProbabilityArray();
    this->ErrorCheckingAndCorrection();

    int min_tiles = this->MinimumNumTiles;
    int tiles = this->ProbabilityTiles;
    this->NumTilesActuallyChosen = 0;
    int attempts = 0;

    while (tiles < min_tiles && attempts < 0x5DC) {
        this->x = this->Prime.x;
        this->y = this->Prime.y;
        this->CurrentNumberOfBranchLevels = this->MaxNumberOfBranchLevels;
        this->NumNodes = 0;
        int node = this->MakeFirstLink();
        this->Branch(node);
        tiles = this->ProbabilityTiles;
        attempts = attempts + 1;
    }

    this->CreateMapBasedOnProbabilityArray();
    this->MapCleanUpEliminatingSinglesOnly();
    return this->ProbabilityTiles;
}

void PointMaker::Branch(int point_index) {
    // Fully verified. Source of truth: fractal.cpp.decomp @ 0x0044B540
    if (this->CurrentNumberOfBranchLevels > 1 &&
        (debug_rand(kFractalSourceFile, 0x116) % 100) < (this->ChanceOfNextNode * 10) &&
        this->ProbabilityTiles >= this->MinimumNumTiles * 2) {
        this->CurrentNumberOfBranchLevels = this->CurrentNumberOfBranchLevels - 1;
        for (int i = 0; i < this->NumSplitsPerBranch; ++i) {
            this->x = this->Point[point_index].x;
            this->y = this->Point[point_index].y;
            int node = this->MakeNewLink();
            this->DrawCurrentBranchIntoProbArray(node);
            this->Branch(node);
        }
    }

    for (int i = 0; i < this->NumberOfSatellites; ++i) {
        int node = this->MakeSatelliteLink();
        this->DrawCurrentSatelliteIntoProbArray(node);
    }
}

int PointMaker::MakeFirstLink() {
    // Fully verified. Source of truth: fractal.cpp.decomp @ 0x0044B610
    int dx = debug_rand(kFractalSourceFile, 0x134) % this->BranchDistance + 2;
    if (fractal_is_odd_signed(debug_rand(kFractalSourceFile, 0x134))) {
        dx = -dx;
    }

    int dy = debug_rand(kFractalSourceFile, 0x135) % this->BranchDistance + 2;
    if (fractal_is_odd_signed(debug_rand(kFractalSourceFile, 0x135))) {
        dy = -dy;
    }

    this->DirX = dx;
    this->DirY = dy;

    int x = this->x + dx;
    int y = this->y + dy;

    if (x < this->LeftLimit) {
        x = this->LeftLimit;
        if (dx < 0) {
            this->DirX = -dx;
        }
    }
    if (y < this->TopLimit) {
        y = this->TopLimit;
        if (dy < 0) {
            this->DirY = -dy;
        }
    }

    if (x >= this->RightLimit) {
        x = this->RightLimit - 1;
        if (this->DirX > 0) {
            this->DirX = -this->DirX;
        }
    }
    if (y >= this->BottomLimit) {
        y = this->BottomLimit - 1;
        if (this->DirY > 0) {
            this->DirY = -this->DirY;
        }
    }

    this->x = x;
    this->y = y;

    this->Point[this->NumNodes].x = x;
    this->Point[this->NumNodes].y = y;
    int index = this->NumNodes;
    this->NumNodes = this->NumNodes + 1;
    return index;
}

int PointMaker::MakeNewLink() {
    // Fully verified. Source of truth: fractal.cpp.decomp @ 0x0044B760
    int dx = debug_rand(kFractalSourceFile, 0x14A) % this->BranchDistance + 1;
    if (fractal_is_odd_signed(debug_rand(kFractalSourceFile, 0x14A))) {
        dx = -dx;
    }

    int dy = debug_rand(kFractalSourceFile, 0x14B) % this->BranchDistance + 1;
    if (fractal_is_odd_signed(debug_rand(kFractalSourceFile, 0x14B))) {
        dy = -dy;
    }

    dx = dx + this->DirX;
    dy = dy + this->DirY;

    int x = this->x;
    if (dx + x < 5) {
        dx = -dx;
        this->DirX = -this->DirX;
    }
    int max_x = this->Width - 5;
    if (dx + x >= max_x) {
        dx = -dx;
        this->DirX = -this->DirX;
    }

    int y = this->y;
    if (dy + y < 5) {
        dy = -dx;
        this->DirY = -this->DirY;
    }
    int max_y = this->Height - 5;
    if (dy + y >= max_y) {
        dy = -dy;
    }

    x = x + dx;
    y = y + dy;

    if (x < 5) {
        x = 5;
    }
    if (x >= max_x) {
        x = max_x;
    }
    if (y < 5) {
        y = 5;
    }
    if (y >= max_y) {
        y = max_y;
    }

    if (fractal_is_odd_signed(debug_rand(kFractalSourceFile, 0x15A))) {
        this->DirX = this->DirX + (debug_rand(kFractalSourceFile, 0x15A) % 3) - 1;
    }
    if (fractal_is_odd_signed(debug_rand(kFractalSourceFile, 0x15B))) {
        this->DirY = this->DirY + (debug_rand(kFractalSourceFile, 0x15B) % 3) - 1;
    }

    this->x = x;
    this->y = y;
    this->Point[this->NumNodes].x = x;
    this->Point[this->NumNodes].y = y;
    int index = this->NumNodes;
    this->NumNodes = this->NumNodes + 1;
    return index;
}

int PointMaker::MakeSatelliteLink() {
    // Fully verified. Source of truth: fractal.cpp.decomp @ 0x0044B950
    int dx = debug_rand(kFractalSourceFile, 0x165) % this->SatelliteDistance + 1;
    if (fractal_is_odd_signed(debug_rand(kFractalSourceFile, 0x165))) {
        dx = -dx;
    }

    int dy = debug_rand(kFractalSourceFile, 0x166) % this->SatelliteDistance + 1;
    if (fractal_is_odd_signed(debug_rand(kFractalSourceFile, 0x166))) {
        dy = -dy;
    }

    dx = dx + this->DirX;
    dy = dy + this->DirY;

    if (dx + this->x < 3) {
        dx = -dx;
        this->DirX = -this->DirX;
    }
    if (dx + this->x >= this->Width - 3) {
        dx = -dx;
        this->DirX = -this->DirX;
    }

    int y = this->y;
    if (dy + y < 3) {
        dy = -dx;
        this->DirY = -this->DirY;
    }
    if (dy + y >= this->Height - 3) {
        dy = -dy;
        this->DirY = -this->DirY;
    }

    this->x = this->x + dx;
    this->y = y + dy;
    this->Point[this->NumNodes].x = this->x;
    this->Point[this->NumNodes].y = this->y;
    int index = this->NumNodes;
    this->NumNodes = this->NumNodes + 1;
    return index;
}

void PointMaker::DrawPrimaryIntoProbabilityArray() {
    // Fully verified. Source of truth: fractal.cpp.decomp @ 0x0044BAA0
    int x0 = this->Prime.x - this->PrimaryRadius;
    int y0 = this->Prime.y - this->PrimaryRadius;
    int x1 = this->Prime.x + this->PrimaryRadius;
    int y1 = this->Prime.y + this->PrimaryRadius;

    if (x0 < 0) {
        x0 = 0;
    }
    if (y0 < 0) {
        y0 = 0;
    }
    if (x1 > this->Width - 1) {
        x1 = this->Width - 1;
    }
    if (y1 > this->Height - 1) {
        y1 = this->Height - 1;
    }

    this->ProbabilityAdd = 1;
    for (int i = 0; i < this->PrimaryRadius; ++i) {
        this->AddingRect(x0, y0, x1, y1);
        this->ProbabilityAdd = this->ProbabilityAdd + 1;
        y1 = y1 - 1;
        y0 = y0 + 1;
        x1 = x1 - 1;
        x0 = x0 + 1;
    }
}

void PointMaker::DrawCurrentBranchIntoProbArray(int point_index) {
    // Fully verified. Source of truth: fractal.cpp.decomp @ 0x0044BB60
    int x = this->Point[point_index].x;
    int y = this->Point[point_index].y;
    int r = this->BranchRadius;

    int x0 = x - r;
    int y0 = y - r;
    int x1 = x + r;
    int y1 = y + r;

    if (x1 < 0 || y1 < 0 || x0 >= this->Width || y0 >= this->Height) {
        return;
    }

    if (x0 < 0) {
        x0 = 0;
    }
    if (y0 < 0) {
        y0 = 0;
    }
    if (x1 >= this->Width) {
        x1 = this->Width - 1;
    }
    if (y1 >= this->Height) {
        y1 = this->Height - 1;
    }

    this->ProbabilityAdd = 1;
    for (int i = 0; i < this->BranchRadius; ++i) {
        this->AddingRect(x0, y0, x1, y1);
        x0 = x0 + 1;
        y0 = y0 + 1;
        x1 = x1 - 1;
        y1 = y1 - 1;
        if (x0 >= this->Width || y0 >= this->Height || x1 < 0 || y1 < 0) {
            break;
        }
        this->ProbabilityAdd = this->ProbabilityAdd + 1;
    }

    int map_index = this->Width * this->Point[point_index].y + this->Point[point_index].x;
    fractal_add_prob(this, map_index, this->ProbabilityAdd);
}

void PointMaker::DrawCurrentSatelliteIntoProbArray(int point_index) {
    // Fully verified. Source of truth: fractal.cpp.decomp @ 0x0044BCD0
    this->ProbabilityAdd = 2;
    for (int r = this->SatelliteRadius; r >= 0; --r) {
        this->AddingCircle(this->Point[point_index].x, this->Point[point_index].y, r);
        this->ProbabilityAdd = this->ProbabilityAdd + 1;
    }
    int map_index = this->Point[point_index].y * this->Width + this->Point[point_index].x;
    fractal_add_prob(this, map_index, this->ProbabilityAdd);
}

void PointMaker::AddingRect(int x0, int y0, int x1, int y1) {
    // Fully verified. Source of truth: fractal.cpp.decomp @ 0x0044BD80
    int top_index = y0 * this->Width + x0;
    int width = x1 - x0;
    int interior_height = (y1 - y0) - 1;
    int bottom_index = interior_height * this->Width + top_index;

    if (width < 0 || (y1 - y0) < 0) {
        return;
    }

    for (int i = 0; i < width + 1; ++i) {
        fractal_add_prob(this, top_index + i, this->ProbabilityAdd);
        fractal_add_prob(this, bottom_index + i, this->ProbabilityAdd);
    }

    top_index = top_index + this->Width;
    for (int i = interior_height; i != 0; --i) {
        fractal_add_prob(this, top_index, this->ProbabilityAdd);
        fractal_add_prob(this, top_index + width, this->ProbabilityAdd);
        top_index = top_index + this->Width;
    }
}

void PointMaker::AddingCircle(int cx, int cy, int radius) {
    // Fully verified. Source of truth: fractal.cpp.decomp @ 0x0044BF90
    if (radius == 0) {
        radius = 1;
    }

    float last_y = 0.0f;
    float last_x = 0.0f;
    int step = fractal_step_degrees(radius);
    int angle = 0;
    while (angle < 360) {
        float rad = (float)angle * 3.14159265358979323846f / 180.0f;
        float off_y = sinf(rad) * (float)radius;
        float off_x = cosf(rad) * (float)radius;

        if (off_y != last_y || off_x != last_x) {
            int x = cx + (int)off_x;
            int y = cy + (int)off_y;
            int map_index = y * this->Width + x;
            fractal_add_prob(this, map_index, this->ProbabilityAdd);

            last_x = off_x;
            last_y = off_y;

            int random = debug_rand(kFractalSourceFile, 0x1F1);
            if (fractal_is_odd_signed(random)) {
                int jitter1 = (debug_rand(kFractalSourceFile, 499) % 3) - 1;
                int jitter2 = (debug_rand(kFractalSourceFile, 500) % 3) - 1;
                int jitter_index = (y + jitter2) * this->Width + (x + jitter1);
                fractal_add_prob(this, jitter_index, this->ProbabilityAdd + 1);
            }
        }
        angle = angle + step;
    }
}

void PointMaker::CreateMapBasedOnProbabilityArray() {
    // Fully verified. Source of truth: fractal.cpp.decomp @ 0x0044C1B0
    int chosen = 0;
    for (int i = 0; i < this->SizeArrays; ++i) {
        if (this->ProbArray[i] != 0) {
            chosen = chosen + 1;
            this->PlacementArray[i] = 1;
        }
    }
    this->NumTilesActuallyChosen = this->NumTilesActuallyChosen + chosen;
}

void PointMaker::SetPoint(int x, int y) {
    // Fully verified. Source of truth: fractal.cpp.decomp @ 0x0044C200
    this->x = x;
    this->y = y;
}

void PointMaker::SetMaxNumberOfBranches(int value) {
    // Fully verified. Source of truth: fractal.cpp.decomp @ 0x0044C220
    this->MaxNumberOfBranches = value;
}

void PointMaker::SetChanceOfNextNode(int value) {
    // Fully verified. Source of truth: fractal.cpp.decomp @ 0x0044C230
    this->ChanceOfNextNode = value;
}

void PointMaker::SetNumberOfSatellites(int value) {
    // Fully verified. Source of truth: fractal.cpp.decomp @ 0x0044C240
    this->NumberOfSatellites = value;
}

void PointMaker::SetSplitsPerBranch(int value) {
    // Fully verified. Source of truth: fractal.cpp.decomp @ 0x0044C250
    this->NumSplitsPerBranch = value;
}

void PointMaker::SetWidthAndHeight(int width, int height) {
    // Fully verified. Source of truth: fractal.cpp.decomp @ 0x0044C260
    this->Width = width;
    this->Height = height;
}

void PointMaker::SetStartPositionRadius(int value) {
    // Fully verified. Source of truth: fractal.cpp.decomp @ 0x0044C280
    this->PrimaryRadius = value;
}

void PointMaker::SetBranchsRadius(int value) {
    // Fully verified. Source of truth: fractal.cpp.decomp @ 0x0044C290
    this->BranchRadius = value;
}

void PointMaker::SetSatelliteRadius(int value) {
    // Fully verified. Source of truth: fractal.cpp.decomp @ 0x0044C2A0
    this->SatelliteRadius = value;
}

void PointMaker::SetMaxNumberOfBranchLevels(int value) {
    // Fully verified. Source of truth: fractal.cpp.decomp @ 0x0044C2B0
    this->MaxBranchFlag = 1;
    this->MaxNumberOfBranchLevels = value;
}

void PointMaker::SetSatelliteDistance(int value) {
    // Fully verified. Source of truth: fractal.cpp.decomp @ 0x0044C2D0
    this->SatelliteDistance = value;
}

void PointMaker::SetBranchDistance(int value) {
    // Fully verified. Source of truth: fractal.cpp.decomp @ 0x0044C2E0
    this->BranchDistance = value;
}

void PointMaker::SetMinimumNumberOfTiles(int value) {
    // Fully verified. Source of truth: fractal.cpp.decomp @ 0x0044C2F0
    this->MinimumNumTiles = value;
}

void PointMaker::SetDrawToOneArray() {
    // Fully verified. Source of truth: fractal.cpp.decomp @ 0x0044C300
    this->DrawToOneArrayFlag = 1;
}

void PointMaker::SetBorderDepthPercentage(int value) {
    // Fully verified. Source of truth: fractal.cpp.decomp @ 0x0044C310
    this->BorderDepthPercentage = value;
    if (value > 0x1E) {
        this->BorderDepthPercentage = 0x1E;
    }
    if (this->BorderDepthPercentage < 5) {
        this->BorderDepthPercentage = 5;
    }
    this->PrepareLimits();
}

char* PointMaker::RetrieveMap() {
    // Fully verified. Source of truth: fractal.cpp.decomp @ 0x0044C350
    return this->PlacementArray;
}

char* PointMaker::RetrieveProbMap() {
    // Fully verified. Source of truth: fractal.cpp.decomp @ 0x0044C360
    return this->ProbArray;
}

void PointMaker::ErrorCheckingAndCorrection() {
    // Fully verified. Source of truth: fractal.cpp.decomp @ 0x0044C370
    int width = this->Width;
    int array_size = this->Height * width;
    this->SizeArrays = array_size;

    if (width < this->BranchRadius) {
        this->BranchRadius = (width * 2) / 3;
    }
    if (width < this->SatelliteRadius) {
        this->SatelliteRadius = (width * 2) / 3;
    }
    if (width < this->PrimaryRadius) {
        this->PrimaryRadius = (width * 2) / 3;
    }
    if (this->NumSplitsPerBranch > 4) {
        this->NumSplitsPerBranch = 4;
    }
    if (this->NumberOfSatellites > 4) {
        this->NumberOfSatellites = 4;
    }

    int coverage = array_size / this->MinimumNumTiles;
    this->DrawToOneArrayFlag = 0;

    int chance = (10 - coverage) * 10;
    this->ChanceOfNextNode = chance;
    if (chance < 0x23) {
        this->ChanceOfNextNode = 0x23;
    }
    if (this->ChanceOfNextNode > 0x50) {
        this->ChanceOfNextNode = 0x50;
    }

    if (this->MaxBranchFlag == 0) {
        this->MaxNumberOfBranchLevels = coverage - (this->ChanceOfNextNode / 5);
    }
    if (this->MaxNumberOfBranchLevels < 10) {
        this->MaxNumberOfBranchLevels = 10;
    }
    if (this->MaxNumberOfBranchLevels > 0x1E) {
        this->MaxNumberOfBranchLevels = 0x1E;
    }
    this->MaxBranchFlag = 0;
}

void PointMaker::PrepareLimits() {
    // Fully verified. Source of truth: fractal.cpp.decomp @ 0x0044C4B0
    int border_x = (this->BorderDepthPercentage * this->Width) / 100;
    this->LeftLimit = border_x;
    this->RightLimit = this->Width - border_x;

    int border_y = (this->Height * this->BorderDepthPercentage) / 100;
    this->TopLimit = border_y;
    this->BottomLimit = this->Height - border_y;
}

void PointMaker::MapCleanUpEliminatingSinglesOnly() {
    // Fully verified. Source of truth: fractal.cpp.decomp @ 0x0044C510
    int h_limit = this->Height - 1;
    int w_limit = this->Width - 1;
    if (h_limit <= 1) {
        return;
    }

    for (int y = 1; y < h_limit; ++y) {
        if (w_limit <= 1) {
            continue;
        }
        for (int x = 1; x < w_limit; ++x) {
            int w = this->Width;
            char* center = this->PlacementArray + y * w + x;
            char neighbors = (char)(center[-w] > 0);
            if (center[-1] > 0) {
                neighbors = neighbors + 1;
            }
            if (center[1] > 0) {
                neighbors = neighbors + 1;
            }
            if (center[w] > 0) {
                neighbors = neighbors + 1;
            }
            if (*center != 0 && neighbors == 0) {
                *center = 0;
            }
        }
    }
}

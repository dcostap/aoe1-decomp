#include "../include/InfluenceMap.h"

#include "../include/globals.h"
#include "../include/XYPoint.h"

#include <new>
#include <stdio.h>
#include <string.h>

static int influence_ftol(double value) {
    return (int)(long)value;
}

InfluenceMap::InfluenceMap() {
    this->xSizeValue = 0;
    this->ySizeValue = 0;
    this->xReferencePointValue = 0;
    this->yReferencePointValue = 0;
    this->valueValue = nullptr;
    this->rowValue = nullptr;
    this->coverageCountValue = 0;
    this->connectionCountValue = 0;
    this->unchangeableLimitValue = 0xFF;
}

InfluenceMap::InfluenceMap(int param_1, int param_2, uchar param_3) {
    // Source of truth: infmap.cpp.decomp @ 0x0044DF80
    this->ySizeValue = param_2;
    uint total = (uint)(param_2 * param_1);
    this->xSizeValue = param_1;
    this->xReferencePointValue = 0;
    this->yReferencePointValue = 0;

    uchar* value = (uchar*)::operator new(total);
    this->valueValue = value;
    for (uint i = 0; i < total; ++i) {
        value[i] = param_3;
    }

    uchar** rows = (uchar**)::operator new((size_t)this->ySizeValue * 4);
    this->rowValue = rows;
    if (rows != nullptr) {
        int row = 0;
        int offset = 0;
        while (row < this->ySizeValue) {
            this->rowValue[row] = this->valueValue + offset;
            ++row;
            offset += this->xSizeValue;
        }
    }
}

InfluenceMap::InfluenceMap(int param_1) {
    // Source of truth: infmap.cpp.decomp @ 0x0044E050
    this->xSizeValue = -1;
    this->ySizeValue = -1;
    this->xReferencePointValue = 0;
    this->yReferencePointValue = 0;
    this->load(param_1);
}

int InfluenceMap::initialize(uchar param_1) {
    // Fully verified. Source of truth: infmap.cpp.decomp @ 0x0044E0B0
    uint total = (uint)(this->ySizeValue * this->xSizeValue);
    uchar* value = this->valueValue;
    for (uint i = 0; i < total; ++i) {
        value[i] = param_1;
    }
    return 1;
}

void InfluenceMap::save(int param_1) {
    // Fully verified. Source of truth: infmap.cpp.decomp @ 0x0044E0F0
    rge_write(param_1, &this->xSizeValue, 4);
    rge_write(param_1, &this->ySizeValue, 4);
    rge_write(param_1, &this->xReferencePointValue, 4);
    rge_write(param_1, &this->yReferencePointValue, 4);
    rge_write(param_1, &this->unchangeableLimitValue, 1);

    for (int y = 0; y < this->ySizeValue; ++y) {
        for (int x = 0; x < this->xSizeValue; ++x) {
            rge_write(param_1, this->rowValue[y] + x, 1);
        }
    }
}

void InfluenceMap::load(int param_1) {
    // Source of truth: infmap.cpp.decomp @ 0x0044E1A0
    rge_read(param_1, &this->xSizeValue, 4);
    rge_read(param_1, &this->ySizeValue, 4);
    rge_read(param_1, &this->xReferencePointValue, 4);
    rge_read(param_1, &this->yReferencePointValue, 4);
    rge_read(param_1, &this->unchangeableLimitValue, 1);

    int value = 0;
    for (int y = 0; y < this->ySizeValue; ++y) {
        for (int x = 0; x < this->xSizeValue; ++x) {
            rge_read(param_1, &value, 1);
            this->rowValue[y][x] = (uchar)value;
        }
    }
}

void InfluenceMap::printToFile(char* param_1) {
    // Source of truth: infmap.cpp.decomp @ 0x0044E250
    // TODO: Keep aligning with original formatting strings from infmap.cpp ASM string table.
    if (param_1 == nullptr) {
        return;
    }

    FILE* file = fopen(param_1, "wa");
    if (file == nullptr) {
        return;
    }

    fprintf(file, "FILENAME: %s\n", param_1);
    fprintf(file, "  Dimensions: %d X %d\n", this->xSizeValue, this->ySizeValue);
    fprintf(file, "  Reference Point: (%d, %d)\n", this->xReferencePointValue, this->yReferencePointValue);
    fprintf(file, "\n");
    fprintf(file, "      ");
    for (int x = 0; x < this->xSizeValue; ++x) {
        fprintf(file, (x % 5 == 0) ? " %03d" : "  %03d", x);
    }
    fprintf(file, "\n");
    fprintf(file, "      ");
    for (int x = 0; x < this->xSizeValue; ++x) {
        fprintf(file, (x % 5 == 0) ? " ---" : " ----", x);
    }
    fprintf(file, "\n");

    for (int y = 0; y < this->ySizeValue; ++y) {
        fprintf(file, "R(%03d):", y);
        for (int x = 0; x < this->xSizeValue; ++x) {
            fprintf(file, (x % 5 == 0) ? " %03d" : "  %03d", this->rowValue[y][x]);
        }
        fprintf(file, (y % 5 == 0) ? " :R(%03d)\n" : "  :R(%03d)\n", y);
    }

    fprintf(file, "      ");
    for (int x = 0; x < this->xSizeValue; ++x) {
        fprintf(file, (x % 5 == 0) ? " ---" : " ----", x);
    }
    fprintf(file, "\n");
    fprintf(file, "      ");
    for (int x = 0; x < this->xSizeValue; ++x) {
        fprintf(file, (x % 5 == 0) ? " %03d" : "  %03d", x);
    }
    fprintf(file, "\n");
    fclose(file);
}

void InfluenceMap::setReferencePoint(int param_1, int param_2) {
    // Fully verified. Source of truth: infmap.cpp.decomp @ 0x0044E4C0
    this->xReferencePointValue = param_1;
    this->yReferencePointValue = param_2;
}

int InfluenceMap::lookupValue(int param_1, int param_2) {
    // Fully verified. Source of truth: infmap.cpp.decomp @ 0x0044E4E0
    return (uint)this->rowValue[param_2 - this->yReferencePointValue][param_1 - this->xReferencePointValue];
}

int InfluenceMap::setValue(int param_1, int param_2, uchar param_3) {
    // Fully verified. Source of truth: infmap.cpp.decomp @ 0x0044E510
    int x = param_1 - this->xReferencePointValue;
    int y = param_2 - this->yReferencePointValue;
    if ((x >= 0) && (y >= 0) && (x < this->xSizeValue) && (y < this->ySizeValue)) {
        this->rowValue[y][x] = param_3;
        return 1;
    }
    return 0;
}

int InfluenceMap::setValue(int param_1, int param_2, int param_3, int param_4, uchar param_5) {
    // Fully verified. Source of truth: infmap.cpp.decomp @ 0x0044E560
    int x0 = param_1 - this->xReferencePointValue;
    int x1 = param_3 - this->xReferencePointValue;
    int y0 = param_2 - this->yReferencePointValue;
    int y1 = param_4 - this->yReferencePointValue;

    if ((x0 >= 0) && (y0 >= 0) && (x0 < this->xSizeValue) && (y0 < this->ySizeValue) && (x1 >= 0) &&
        (y1 >= 0) && (x1 < this->xSizeValue) && (y1 < this->ySizeValue)) {
        for (int y = y0; y <= y1; ++y) {
            for (int x = x0; x <= x1; ++x) {
                this->rowValue[y][x] = param_5;
            }
        }
        return 1;
    }
    return 0;
}

int InfluenceMap::incrementValue(int param_1, int param_2, uchar param_3) {
    // Fully verified. Source of truth: infmap.cpp.decomp @ 0x0044E600
    int x = param_1 - this->xReferencePointValue;
    int y = param_2 - this->yReferencePointValue;
    if ((x < 0) || (y < 0) || (this->xSizeValue <= x) || (this->ySizeValue <= y)) {
        return 0;
    }

    uchar limit = this->unchangeableLimitValue;
    uchar* cell = this->rowValue[y] + x;
    uchar value = *cell;
    if (limit <= value) {
        return 1;
    }

    uint sum = (uint)param_3 + (uint)value;
    if (limit <= sum) {
        *cell = (uchar)(limit - 1);
    } else {
        *cell = (uchar)sum;
    }
    return 1;
}

int InfluenceMap::incrementValue(int param_1, int param_2, int param_3, int param_4, uchar param_5) {
    // Source of truth: infmap.cpp.decomp @ 0x0044E680
    int x0 = param_1 - this->xReferencePointValue;
    int x1 = param_3 - this->xReferencePointValue;
    int y0 = param_2 - this->yReferencePointValue;
    int y1 = param_4 - this->yReferencePointValue;

    if (x0 < 0) {
        x0 = 0;
    } else if (this->xSizeValue <= x0) {
        x0 = this->xSizeValue - 1;
    }
    if (y0 < 0) {
        y0 = 0;
    } else if (this->xSizeValue <= y0) {
        y0 = this->xSizeValue - 1;
    }
    if (x1 < 0) {
        x1 = 0;
    } else if (this->xSizeValue <= x1) {
        x1 = this->xSizeValue - 1;
    }
    if (y1 < 0) {
        y1 = 0;
    } else if (this->xSizeValue <= y1) {
        y1 = this->xSizeValue - 1;
    }

    if (y0 <= y1) {
        int y = y0;
        while (y <= y1) {
            for (int x = x0; x <= x1; ++x) {
                uchar limit = this->unchangeableLimitValue;
                uchar* cell = &this->rowValue[y][x];
                if (*cell < limit) {
                    uint sum = (uint)param_5 + (uint)(*cell);
                    *cell = (sum < limit) ? (uchar)sum : (uchar)(limit - 1);
                }
            }
            ++y;
        }
    }
    return 1;
}

int InfluenceMap::decrementValue(int param_1, int param_2, uchar param_3) {
    // Fully verified. Source of truth: infmap.cpp.decomp @ 0x0044E790
    int x = param_1 - this->xReferencePointValue;
    int y = param_2 - this->yReferencePointValue;
    if ((x >= 0) && (y >= 0) && (x < this->xSizeValue) && (y < this->ySizeValue)) {
        uchar value = this->rowValue[y][x];
        if (this->unchangeableLimitValue <= value) {
            return 1;
        }
        int diff = (uint)value - (uint)param_3;
        this->rowValue[y][x] = (uchar)(((diff < 0) ? 0 : -1) & diff);
        return 1;
    }
    return 0;
}

int InfluenceMap::decrementValue(int param_1, int param_2, int param_3, int param_4, uchar param_5) {
    // Source of truth: infmap.cpp.decomp @ 0x0044E800
    int x0 = param_1 - this->xReferencePointValue;
    int x1 = param_3 - this->xReferencePointValue;
    int y0 = param_2 - this->yReferencePointValue;
    int y1 = param_4 - this->yReferencePointValue;

    if (x0 < 0) {
        x0 = 0;
    } else if (this->xSizeValue <= x0) {
        x0 = this->xSizeValue - 1;
    }
    if (y0 < 0) {
        y0 = 0;
    } else if (this->xSizeValue <= y0) {
        y0 = this->xSizeValue - 1;
    }
    if (x1 < 0) {
        x1 = 0;
    } else if (this->xSizeValue <= x1) {
        x1 = this->xSizeValue - 1;
    }
    if (y1 < 0) {
        y1 = 0;
    } else if (this->xSizeValue <= y1) {
        y1 = this->xSizeValue - 1;
    }

    if (y0 <= y1) {
        for (int y = y0; y <= y1; ++y) {
            for (int x = x0; x <= x1; ++x) {
                if (this->rowValue[y][x] < this->unchangeableLimitValue) {
                    int diff = (uint)this->rowValue[y][x] - (uint)param_5;
                    this->rowValue[y][x] = (uchar)(((diff < 0) ? 0 : -1) & diff);
                }
            }
        }
    }
    return 1;
}

int InfluenceMap::setCoverageCount(XYPoint* param_1, XYPoint* param_2, int param_3) {
    // Source of truth: infmap.cpp.decomp @ 0x0044E900
    this->coverageCountValue = 0;
    int x = param_1->x;
    if ((x >= 0) && (param_1->y >= 0) && (x < this->xSizeValue) && (param_1->y < this->ySizeValue) && (param_2->x >= 0) &&
        (param_2->y >= 0) && (param_2->x < this->xSizeValue) && (param_2->y < this->ySizeValue)) {
        for (int cx = x; cx <= param_2->x; ++cx) {
            for (int cy = param_1->y; cy <= param_2->y; ++cy) {
                if (param_3 <= (int)(uint)this->rowValue[cy - this->yReferencePointValue][cx - this->xReferencePointValue]) {
                    this->coverageCountValue = this->coverageCountValue + 1;
                }
            }
        }
        return this->coverageCountValue;
    }
    return 0;
}

int InfluenceMap::setConnectionCount(XYPoint* param_1, XYPoint* param_2, int param_3, int param_4, int param_5, int param_6) {
    // Source of truth: infmap.cpp.decomp @ 0x0044E9E0
    // TODO: Validate direction/edge counting rules against infmap.cpp.asm for exact parity.
    this->connectionCountValue = 0;

    int x0 = param_1->x;
    int y0 = param_1->y;
    int x1 = param_2->x;
    int y1 = param_2->y;
    if ((x0 < 0) || (y0 < 0) || (x0 >= this->xSizeValue) || (y0 >= this->ySizeValue) || (x1 < 0) || (y1 < 0) ||
        (x1 >= this->xSizeValue) || (y1 >= this->ySizeValue)) {
        return 0;
    }

    for (int x = x0; x <= x1; ++x) {
        for (int y = y0; y <= y1; ++y) {
            if (param_3 <= (int)(uint)this->rowValue[y - this->yReferencePointValue][x - this->xReferencePointValue]) {
                int nx = x;
                int ny = y;
                for (uint dir = 0; dir < 8; ++dir) {
                    switch (dir) {
                    case 0:
                        nx = nx - 1;
                    case 7:
                        ny = ny - 1;
                        break;
                    case 1:
                    case 2:
                        nx = nx + 1;
                        break;
                    case 3:
                    case 4:
                        ny = ny + 1;
                        break;
                    case 5:
                    case 6:
                        nx = nx - 1;
                        break;
                    }

                    if ((param_6 != 0) || ((dir & 1) != 0)) {
                        if ((nx < 0) || (nx >= this->xSizeValue) || (ny < 0) || (ny >= this->ySizeValue)) {
                            if (((param_4 == 1) && ((dir & 1) == 1)) || ((param_5 == 1) && ((dir & 1) == 0))) {
                                this->connectionCountValue = this->connectionCountValue + 1;
                            }
                        } else if (param_3 <= (int)(uint)this->rowValue[ny - this->yReferencePointValue][nx - this->xReferencePointValue]) {
                            this->connectionCountValue = this->connectionCountValue + 1;
                        }
                    }
                }
            }
        }
    }
    return this->connectionCountValue;
}

int InfluenceMap::coverageIncluding(XYPoint* param_1, XYPoint* param_2, uchar param_3, uchar param_4) {
    // Source of truth: infmap.cpp.decomp @ 0x0044EC00
    int ret = this->coverageCountValue;
    int x0 = param_1->x;
    int y0 = param_1->y;
    int x1 = param_2->x;
    int y1 = param_2->y;
    if ((x0 >= 0) && (y0 >= 0) && (x0 < this->xSizeValue) && (y0 < this->ySizeValue) && (x1 >= 0) && (y1 >= 0) &&
        (x1 < this->xSizeValue) && (y1 < this->ySizeValue)) {
        for (int x = x0; x <= x1; ++x) {
            for (int y = y0; y <= y1; ++y) {
                uchar value = this->rowValue[y - this->yReferencePointValue][x - this->xReferencePointValue];
                if ((value < param_3) && ((uint)param_3 <= (uint)value + (uint)param_4)) {
                    ret = ret + 1;
                }
            }
        }
        return ret;
    }
    return 0;
}

int InfluenceMap::connectionsIncluding(XYPoint* param_1, XYPoint* param_2, uchar param_3, uchar param_4, int param_5, int param_6, int param_7) {
    // Source of truth: infmap.cpp.decomp @ 0x0044ED20
    // TODO: Validate this transliteration against infmap.cpp.asm edge-path handling.
    int x = param_1->x;
    int ret = this->connectionCountValue;
    if ((x < 0) || (param_1->y < 0) || (x >= this->xSizeValue) || (param_1->y >= this->ySizeValue) || (param_2->x < 0) || (param_2->y < 0) ||
        (param_2->x >= this->xSizeValue) || (param_2->y >= this->ySizeValue)) {
        return 0;
    }

    while (true) {
        if (param_2->x < x) {
            return ret;
        }

        if (param_1->y <= param_2->y) {
            for (int y = param_1->y; y <= param_2->y; ++y) {
                uchar value = this->rowValue[y - this->yReferencePointValue][x - this->xReferencePointValue];
                if ((uint)param_3 <= (uint)value + (uint)param_4) {
                    if (param_3 <= value) {
                        uint dir = 0;
                        int ny = y;
                        int nx = x;
                        while (dir < 8) {
                            switch (dir) {
                            case 0:
                                nx = nx - 1;
                            case 7:
                                ny = ny - 1;
                                break;
                            case 1:
                            case 2:
                                nx = nx + 1;
                                break;
                            case 3:
                            case 4:
                                ny = ny + 1;
                                break;
                            case 5:
                            case 6:
                                nx = nx - 1;
                                break;
                            }

                            if ((param_7 != 0) || ((dir & 1) != 0)) {
                                if (((nx < 0) || (nx >= this->xSizeValue) || (ny < 0) || (ny >= this->ySizeValue)) &&
                                    (((param_5 == 1) && ((dir & 1) == 1)) || ((param_6 == 1) && ((dir & 1) == 0)))) {
                                    ret = ret - 1;
                                }
                                if (ret < 1) {
                                    break;
                                }
                            }
                            ++dir;
                        }
                    }

                    uint dir = 0;
                    int ny = y;
                    int nx = x;
                    while (dir < 8) {
                        switch (dir) {
                        case 0:
                            nx = nx - 1;
                        case 7:
                            ny = ny - 1;
                            break;
                        case 1:
                        case 2:
                            nx = nx + 1;
                            break;
                        case 3:
                        case 4:
                            ny = ny + 1;
                            break;
                        case 5:
                        case 6:
                            nx = nx - 1;
                            break;
                        }

                        if ((param_7 != 0) || ((dir & 1) != 0)) {
                            if ((nx < 0) || (nx >= this->xSizeValue) || (ny < 0) || (ny >= this->ySizeValue)) {
                                if (((param_5 == 1) && ((dir & 1) == 1)) || ((param_6 == 1) && ((dir & 1) == 0))) {
                                    ret = ret - 1;
                                }
                            } else if (param_3 <= this->rowValue[ny - this->yReferencePointValue][nx - this->xReferencePointValue]) {
                                ret = ret + 2;
                            }
                        }
                        ++dir;
                    }
                }
            }
        }

        ++x;
    }
}

void InfluenceMap::setUnchangeableLimit(uchar param_1) {
    // Fully verified. Source of truth: infmap.cpp.decomp @ 0x0044F030
    if (param_1 != 0) {
        this->unchangeableLimitValue = param_1;
    }
}

int InfluenceMap::maxValue() {
    // Fully verified. Source of truth: infmap.cpp.decomp @ 0x0044F040
    int total = this->xSizeValue * this->ySizeValue;
    int i = 0;
    uint max = (uint)*this->valueValue;
    while (i < total) {
        uint value = (uint)this->valueValue[i];
        if (max < value) {
            max = value;
        }
        ++i;
    }
    return (int)max;
}

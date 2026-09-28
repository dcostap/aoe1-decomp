
#include "../include/infmap.h"
#include "../include/rge_fio.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <new.h>

static const char print_mode[] = "wa";
static const char print_filename[] = "FILENAME: %s\n";
static const char print_dimensions[] = "  Dimensions: %d X %d\n";
static const char print_reference[] = "  Reference Point: (%d, %d)\n";
static const char print_newline[] = "\n";
static const char print_indent[] = "      ";
static const char print_number[] = "%03d ";
static const char print_spaced_number[] = " %03d ";
static const char print_dash[] = "--- ";
static const char print_spaced_dash[] = " --- ";
static const char print_row[] = "R%03d: ";
static const char print_row_end[] = ":R%03d\n";
static const char print_row_end_last[] = ":R%03d\n\n";

InfluenceMap::InfluenceMap(int x, int y, unsigned char initialValue)
    : xSizeValue(x),
      xReferencePointValue(0),
      yReferencePointValue(0) {
    this->ySizeValue = y;
    int total = y * x;
    this->valueValue = (unsigned char*)::operator new(total);
    memset(this->valueValue, initialValue, total);
    this->rowValue = (unsigned char**)::operator new(this->ySizeValue * 4);
    if (this->rowValue) {
        int i = 0;
        int offset = 0;
        if (i < this->ySizeValue) {
            do {
                this->rowValue[i] = this->valueValue + offset;
                i++;
                offset += this->xSizeValue;
            } while (i < this->ySizeValue);
        }
    }
}

InfluenceMap::InfluenceMap(int infile) {
    this->xSizeValue = -1;
    this->ySizeValue = -1;
    this->xReferencePointValue = 0;
    this->yReferencePointValue = 0;
    this->load(infile);
}

InfluenceMap::~InfluenceMap() {
    if (this->valueValue) {
        ::operator delete(this->valueValue);
    }
    if (this->rowValue) {
        ::operator delete(this->rowValue);
    }
}

int InfluenceMap::initialize(unsigned char initialValue) {
    memset(this->valueValue, initialValue, this->xSizeValue * this->ySizeValue);
    return 1;
}

void InfluenceMap::save(int outfile) {
    rge_write(outfile, &xSizeValue, 4);
    rge_write(outfile, &ySizeValue, 4);
    rge_write(outfile, &xReferencePointValue, 4);
    rge_write(outfile, &yReferencePointValue, 4);
    rge_write(outfile, &unchangeableLimitValue, 1);

    for (int j = 0; j < ySizeValue; j++) {
        for (int i = 0; i < xSizeValue; i++) {
            rge_write(outfile, rowValue[j] + i, 1);
        }
    }
}

void InfluenceMap::load(int infile) {
    rge_read(infile, &xSizeValue, 4);
    rge_read(infile, &ySizeValue, 4);
    rge_read(infile, &xReferencePointValue, 4);
    rge_read(infile, &yReferencePointValue, 4);
    rge_read(infile, &unchangeableLimitValue, 1);

    for (int j = 0; j < ySizeValue; j++) {
        for (int i = 0; i < xSizeValue; i++) {
            unsigned char tempBYTE;
            rge_read(infile, &tempBYTE, 1);
            rowValue[j][i] = tempBYTE;
        }
    }
}

void InfluenceMap::printToFile(char* filename) {
    if (filename != 0) {
        FILE* f = fopen(filename, print_mode);
        if (f != 0) {
            fprintf(f, print_filename, filename);
            fprintf(f, print_dimensions, this->xSizeValue, this->ySizeValue);
            fprintf(f, print_reference, this->xReferencePointValue, this->yReferencePointValue);
            fprintf(f, print_newline);

            fprintf(f, print_indent);
            int i = 0;
            if (this->xSizeValue > 0) {
                do {
                    if (i % 5 == 0) {
                        fprintf(f, print_spaced_number, i);
                    } else {
                        fprintf(f, print_number, i);
                    }
                    i++;
                } while (i < this->xSizeValue);
            }
            fprintf(f, print_newline);

            fprintf(f, print_indent);
            i = 0;
            if (this->xSizeValue > 0) {
                do {
                    if (i % 5 == 0) {
                        fprintf(f, print_spaced_dash, i);
                    } else {
                        fprintf(f, print_dash, i);
                    }
                    i++;
                } while (i < this->xSizeValue);
            }
            fprintf(f, print_newline);

            int j = 0;
            if (this->ySizeValue > 0) {
                do {
                    fprintf(f, print_row, j);
                    i = 0;
                    if (this->xSizeValue > 0) {
                        do {
                            int val = this->rowValue[j][i];
                            if (i % 5 == 0) {
                                fprintf(f, print_spaced_number, val);
                            } else {
                                fprintf(f, print_number, val);
                            }
                            i++;
                        } while (i < this->xSizeValue);
                    }
                    int next = j + 1;
                    if (next % 5 == 0) {
                        fprintf(f, print_row_end_last, j);
                    } else {
                        fprintf(f, print_row_end, j);
                    }
                    j = next;
                } while (j < this->ySizeValue);
            }

            fprintf(f, print_indent);
            i = 0;
            if (this->xSizeValue > 0) {
                do {
                    if (i % 5 == 0) {
                        fprintf(f, print_spaced_dash, i);
                    } else {
                        fprintf(f, print_dash, i);
                    }
                    i++;
                } while (i < this->xSizeValue);
            }
            fprintf(f, print_newline);
            fprintf(f, print_indent);
            i = 0;
            if (this->xSizeValue > 0) {
                do {
                    if (i % 5 == 0) {
                        fprintf(f, print_spaced_number, i);
                    } else {
                        fprintf(f, print_number, i);
                    }
                    i++;
                } while (i < this->xSizeValue);
            }
            fprintf(f, print_newline);
            fclose(f);
        }
    }
}

void InfluenceMap::setReferencePoint(int x, int y) {
    this->xReferencePointValue = x;
    this->yReferencePointValue = y;
}

int InfluenceMap::lookupValue(int x, int y) {
    return this->rowValue[y - this->yReferencePointValue]
                       [x - this->xReferencePointValue];
}

int InfluenceMap::setValue(int x, int y, unsigned char v) {
    x -= this->xReferencePointValue;
    y -= this->yReferencePointValue;
    if (x < 0 || y < 0 || x >= this->xSizeValue || y >= this->ySizeValue) {
        return 0;
    }
    this->rowValue[y][x] = v;
    return 1;
}

int InfluenceMap::setValue(int minX, int minY, int maxX, int maxY,
                           unsigned char v) {
    minX -= this->xReferencePointValue;
    maxX -= this->xReferencePointValue;
    minY -= this->yReferencePointValue;
    maxY -= this->yReferencePointValue;

    if (minX < 0 || minY < 0 || minX >= this->xSizeValue || minY >= this->ySizeValue ||
        maxX < 0 || maxY < 0 || maxX >= this->xSizeValue || maxY >= this->ySizeValue)
        return 0;

    for (int j = minY; j <= maxY; j++) {
        for (int x = minX; x <= maxX; x++) {
            this->rowValue[j][x] = v;
        }
    }
    return 1;
}

int InfluenceMap::incrementValue(int x, int y, unsigned char v) {
    int rx = x - this->xReferencePointValue;
    int ry = y - this->yReferencePointValue;

    if (rx < 0 || ry < 0 || rx >= this->xSizeValue || ry >= this->ySizeValue)
        return 0;

    if (this->rowValue[ry][rx] >= this->unchangeableLimitValue)
        return 1;

    int sum = (int)(unsigned char)this->rowValue[ry][rx] + (int)(unsigned char)v;
    if (sum >= (int)(unsigned char)this->unchangeableLimitValue) {
        this->rowValue[ry][rx] = (unsigned char)((int)(unsigned char)this->unchangeableLimitValue - 1);
        return 1;
    }
    this->rowValue[ry][rx] = (unsigned char)sum;
    return 1;
}

int InfluenceMap::incrementValue(int minX, int minY, int maxX, int maxY,
                                 unsigned char v) {
    minX -= this->xReferencePointValue;
    maxX -= this->xReferencePointValue;
    minY -= this->yReferencePointValue;
    maxY -= this->yReferencePointValue;

    if (minX < 0)
        minX = 0;
    else if (minX >= this->xSizeValue)
        minX = this->xSizeValue - 1;

    // the shipped code compares y coordinates with xSizeValue.
    if (minY < 0)
        minY = 0;
    else if (minY >= this->xSizeValue)
        minY = this->xSizeValue - 1;

    if (maxX < 0)
        maxX = 0;
    else if (maxX >= this->xSizeValue)
        maxX = this->xSizeValue - 1;

    // the shipped code compares y coordinates with xSizeValue.
    if (maxY < 0)
        maxY = 0;
    else if (maxY >= this->xSizeValue)
        maxY = this->xSizeValue - 1;

    if (minY <= maxY) {
        for (int y = minY; y <= maxY; y++) {
            for (int x = minX; x <= maxX; x++) {
                if (this->rowValue[y][x] < this->unchangeableLimitValue) {
                    int value = (int)this->rowValue[y][x] + (int)v;
                    if (value >= this->unchangeableLimitValue)
                        this->rowValue[y][x] = this->unchangeableLimitValue - 1;
                    else
                        this->rowValue[y][x] = (unsigned char)value;
                }
            }
        }
    }

    return 1;
}

int InfluenceMap::decrementValue(int x, int y, unsigned char v) {
    int tx = x - xReferencePointValue;
    int ty = y - yReferencePointValue;

    if (tx < 0 || ty < 0 || tx >= xSizeValue || ty >= ySizeValue) {
        return 0;
    }

    unsigned char* cell = &rowValue[ty][tx];

    if (*cell >= unchangeableLimitValue) {
        return 1;
    }

    int diff = (int)*cell - (int)v;
    if (diff < 0) {
        *cell = 0;
    } else {
        *cell = (unsigned char)diff;
    }

    return 1;
}

int InfluenceMap::decrementValue(int minX, int minY, int maxX, int maxY,
                                 unsigned char v) {
    minX -= this->xReferencePointValue;
    maxX -= this->xReferencePointValue;
    minY -= this->yReferencePointValue;
    maxY -= this->yReferencePointValue;

    if (minX < 0)
        minX = 0;
    else if (minX >= this->xSizeValue)
        minX = this->xSizeValue - 1;

    // the shipped code compares y coordinates with xSizeValue.
    if (minY < 0)
        minY = 0;
    else if (minY >= this->xSizeValue)
        minY = this->xSizeValue - 1;

    if (maxX < 0)
        maxX = 0;
    else if (maxX >= this->xSizeValue)
        maxX = this->xSizeValue - 1;

    // the shipped code compares y coordinates with xSizeValue.
    if (maxY < 0)
        maxY = 0;
    else if (maxY >= this->xSizeValue)
        maxY = this->xSizeValue - 1;

    if (minY <= maxY) {
        for (int y = minY; y <= maxY; y++) {
            for (int x = minX; x <= maxX; x++) {
                if (this->rowValue[y][x] < this->unchangeableLimitValue) {
                    int value = (int)this->rowValue[y][x] - (int)v;
                    if (value < 0)
                        this->rowValue[y][x] = 0;
                    else
                        this->rowValue[y][x] = (unsigned char)value;
                }
            }
        }
    }

    return 1;
}

int InfluenceMap::setCoverageCount(const XYPoint& min, const XYPoint& max,
                                   int valueLevel) {
    this->coverageCountValue = 0;

    if (min.x < 0 || min.y < 0 || min.x >= this->xSizeValue || min.y >= this->ySizeValue || max.x < 0 || max.y < 0 ||
        max.x >= this->xSizeValue || max.y >= this->ySizeValue) {
        return 0;
    }

    for (int x = min.x; x <= max.x; x++) {
        for (int y = min.y; y <= max.y; y++) {
            int xr = x - this->xReferencePointValue;
            if (this->rowValue[y - this->yReferencePointValue][xr] >= valueLevel) {
                this->coverageCountValue++;
            }
        }
    }

    return this->coverageCountValue;
}

int InfluenceMap::setConnectionCount(
    const XYPoint& min, const XYPoint& max, int valueLevel,
    int countOrthogonalEdgesAsConnections, int countDiagonalEdgesAsConnections,
    int countDiagonalConnections) {
    InfluenceMap* self = this;

    self->connectionCountValue = 0;

    if (min.x < 0 || min.y < 0 || min.x >= self->xSizeValue || min.y >= self->ySizeValue || max.x < 0 || max.y < 0 ||
        max.x >= self->xSizeValue || max.y >= self->ySizeValue) {
        return 0;
    }

    for (int i = min.x; i <= max.x; ++i) {
        int j = min.y;
        if (j <= max.y) {
            unsigned char** rows = self->rowValue;
            int xOffset = i - self->xReferencePointValue;
            do {
                if (rows[j - self->yReferencePointValue][xOffset] >= valueLevel) {
                    int neighborX = i;
                    int neighborY = j;

                    for (int direction = 0; direction < 8; ++direction) {
                        switch (direction) {
                        case 0:
                            --neighborX;
                            --neighborY;
                            break;
                        case 1:
                        case 2:
                            ++neighborX;
                            break;
                        case 3:
                        case 4:
                            ++neighborY;
                            break;
                        case 5:
                        case 6:
                            --neighborX;
                            break;
                        case 7:
                            --neighborY;
                            break;
                        }

                        if (countDiagonalConnections || (direction % 2) != 0) {
                            if (neighborX >= 0 && neighborX < self->xSizeValue &&
                                neighborY >= 0 && neighborY < self->ySizeValue) {
                                if (rows[neighborY - self->yReferencePointValue]
                                    [neighborX - self->xReferencePointValue] >= valueLevel) {
                                    ++self->connectionCountValue;
                                }
                            } else if ((countOrthogonalEdgesAsConnections == 1 && (direction % 2) == 1) ||
                                       (countDiagonalEdgesAsConnections == 1 && (direction % 2) == 0)) {
                                ++self->connectionCountValue;
                            }
                        }
                    }
                }
                ++j;
            } while (j <= max.y);
        }
    }

    return self->connectionCountValue;
}

int InfluenceMap::coverageIncluding(const XYPoint& min, const XYPoint& max,
                                    unsigned char valueLevel,
                                    unsigned char newValueLevel) {
    int rVal = this->coverageCountValue;

    if (min.x < 0 || min.y < 0 || min.x >= this->xSizeValue || min.y >= this->ySizeValue || max.x < 0 || max.y < 0 ||
        max.x >= this->xSizeValue || max.y >= this->ySizeValue) {
        return 0;
    }

    for (int i = min.x; i <= max.x; ++i) {
        for (int j = min.y; j <= max.y; ++j) {
            int xr = i - this->xReferencePointValue;
            if (this->rowValue[j - this->yReferencePointValue] [xr] < valueLevel) {
                if (this->rowValue[j - this->yReferencePointValue] [xr] + newValueLevel >= valueLevel) {
                    ++rVal;
                }
            }
        }
    }

    return rVal;
}

int InfluenceMap::connectionsIncluding(const XYPoint& min, const XYPoint& max,
                                       unsigned char valueLevel,
                                       unsigned char newValueLevel,
                                       int countOrthogonalEdgesAsConnections,
                                       int countDiagonalEdgesAsConnections,
                                       int countDiagonalConnections) {
    int rVal = this->connectionCountValue;
    int i;
    int j;

    if (min.x < 0 || min.y < 0 || min.x >= this->xSizeValue || min.y >= this->ySizeValue || max.x < 0 || max.y < 0 ||
        max.x >= this->xSizeValue || max.y >= this->ySizeValue) {
        return 0;
    }

    for (i = min.x; i <= max.x; ++i) {
        j = min.y;
        if (j <= max.y) {
            unsigned char** rowsMap = this->rowValue;
            int xOffset = i - this->xReferencePointValue;

            do {
                if (this->rowValue[j - this->yReferencePointValue][xOffset] + newValueLevel >= valueLevel) {
                    if (this->rowValue[j - this->yReferencePointValue][xOffset] >= valueLevel) {
                        int neighborX = i;
                        int neighborY = j;

                        for (int direction = 0; direction < 8; ++direction) {
                            switch (direction) {
                            case 0:
                                --neighborX;
                                goto first_direction_case_7;
                            case 1:
                            case 2:
                                ++neighborX;
                                break;
                            case 3:
                            case 4:
                                ++neighborY;
                                break;
                            case 5:
                            case 6:
                                --neighborX;
                                break;
                            case 7:
                            first_direction_case_7:
                                --neighborY;
                                break;
                            }

                            if (countDiagonalConnections || direction % 2 != 0) {
                                if (neighborX < 0 || neighborX >= this->xSizeValue ||
                                    neighborY < 0 || neighborY >= this->ySizeValue) {
                                    if ((countOrthogonalEdgesAsConnections == 1 && direction % 2 == 1) ||
                                        (countDiagonalEdgesAsConnections == 1 && direction % 2 == 0)) {
                                        --rVal;
                                    }
                                }
                                if (rVal <= 0)
                                    break;
                            }
                        }
                    }

                    int neighborX = i;
                    int neighborY = j;
                    for (int direction = 0; direction < 8; ++direction) {
                        switch (direction) {
                        case 0:
                            --neighborX;
                            goto direction_case_7;
                        case 1:
                        case 2:
                            ++neighborX;
                            break;
                        case 3:
                        case 4:
                            ++neighborY;
                            break;
                        case 5:
                        case 6:
                            --neighborX;
                            break;
                        case 7:
                        direction_case_7:
                            --neighborY;
                            break;
                        }

                        if (countDiagonalConnections || direction % 2 != 0) {
                            if (neighborX < 0 || neighborX >= this->xSizeValue ||
                                neighborY < 0 || neighborY >= this->ySizeValue) {
                                if ((countOrthogonalEdgesAsConnections == 1 && direction % 2 == 1) ||
                                    (countDiagonalEdgesAsConnections == 1 && direction % 2 == 0)) {
                                    --rVal;
                                }
                            } else if (rowsMap[neighborY - this->yReferencePointValue]
                                       [neighborX - this->xReferencePointValue] >= valueLevel) {
                                rVal += 2;
                            }
                        }
                    }
                }
                ++j;
            } while (j <= max.y);
        }
    }

    return rVal;
}

void InfluenceMap::setUnchangeableLimit(unsigned char uL) {
    if (uL > 0)
        this->unchangeableLimitValue = uL;
}

int InfluenceMap::maxValue() {
    int total = this->xSizeValue * this->ySizeValue;
    int maxVal = (unsigned int)this->valueValue[0];
    int index = 0;
    if (total > 0) {
        do {
            int val = (unsigned int)this->valueValue[index];
            if (val <= maxVal) {
                // keep current max
            } else {
                maxVal = val;
            }
            ++index;
        } while (index < total);
    }
    return maxVal;
}

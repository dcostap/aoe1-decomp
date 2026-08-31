
#include "../include/infmap.h"
#include "../include/rge_fio.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* __cdecl operator_new(unsigned int size);
void __cdecl operator_delete(void* ptr);

static const char print_mode[] = "wt";
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

InfluenceMap::InfluenceMap(int xSize, int ySize, unsigned char fillValue)
    : xSizeValue(xSize),
      xReferencePointValue(0),
      yReferencePointValue(0) {
    this->ySizeValue = ySize;
    int total = ySize * xSize;
    this->valueValue = (unsigned char*)operator_new(total);
    memset(this->valueValue, fillValue, total);
    this->rowValue = (unsigned char**)operator_new(this->ySizeValue * 4);
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

InfluenceMap::InfluenceMap(int fd) {
    this->xSizeValue = -1;
    this->ySizeValue = -1;
    this->xReferencePointValue = 0;
    this->yReferencePointValue = 0;
    this->load(fd);
}

InfluenceMap::~InfluenceMap() {
    if (this->valueValue) {
        operator_delete(this->valueValue);
    }
    if (this->rowValue) {
        operator_delete(this->rowValue);
    }
}

int InfluenceMap::initialize(unsigned char value) {
    memset(this->valueValue, value, this->xSizeValue * this->ySizeValue);
    return 1;
}

void InfluenceMap::save(int fd) {
    rge_write(fd, &xSizeValue, 4);
    rge_write(fd, &ySizeValue, 4);
    rge_write(fd, &xReferencePointValue, 4);
    rge_write(fd, &yReferencePointValue, 4);
    rge_write(fd, &unchangeableLimitValue, 1);

    for (int i = 0; i < ySizeValue; i++) {
        for (int j = 0; j < xSizeValue; j++) {
            rge_write(fd, rowValue[i] + j, 1);
        }
    }
}

void InfluenceMap::load(int fd) {
    rge_read(fd, &xSizeValue, 4);
    rge_read(fd, &ySizeValue, 4);
    rge_read(fd, &xReferencePointValue, 4);
    rge_read(fd, &yReferencePointValue, 4);
    rge_read(fd, &unchangeableLimitValue, 1);

    for (int i = 0; i < ySizeValue; i++) {
        for (int j = 0; j < xSizeValue; j++) {
            unsigned char b;
            rge_read(fd, &b, 1);
            rowValue[i][j] = b;
        }
    }
}

void InfluenceMap::printToFile(char* filename)
{
    if (filename != 0) {
        FILE* f = fopen(filename, print_mode);
        if (f != 0) {
            fprintf(f, print_filename, filename);
            fprintf(f, print_dimensions, this->xSizeValue, this->ySizeValue);
            fprintf(f, print_reference, this->xReferencePointValue,
                    this->yReferencePointValue);
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

            int r = 0;
            if (this->ySizeValue > 0) {
                do {
                    fprintf(f, print_row, r);
                    i = 0;
                    if (this->xSizeValue > 0) {
                        do {
                            int val = this->rowValue[r][i];
                            if (i % 5 == 0) {
                                fprintf(f, print_spaced_number, val);
                            } else {
                                fprintf(f, print_number, val);
                            }
                            i++;
                        } while (i < this->xSizeValue);
                    }
                    int next = r + 1;
                    if (next % 5 == 0) {
                        fprintf(f, print_row_end_last, r);
                    } else {
                        fprintf(f, print_row_end, r);
                    }
                    r = next;
                } while (r < this->ySizeValue);
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

int InfluenceMap::setValue(int x, int y, unsigned char value) {
    x -= this->xReferencePointValue;
    y -= this->yReferencePointValue;
    if (x < 0 || y < 0 || x >= this->xSizeValue || y >= this->ySizeValue) {
        return 0;
    }
    this->rowValue[y][x] = value;
    return 1;
}

int InfluenceMap::setValue(int x1, int y1, int x2, int y2,
                           unsigned char value)
{
    x1 -= this->xReferencePointValue;
    x2 -= this->xReferencePointValue;
    y1 -= this->yReferencePointValue;
    y2 -= this->yReferencePointValue;

    if (x1 < 0 || y1 < 0 || x1 >= this->xSizeValue || y1 >= this->ySizeValue ||
        x2 < 0 || y2 < 0 || x2 >= this->xSizeValue || y2 >= this->ySizeValue)
        return 0;

    for (int y = y1; y <= y2; y++) {
        for (int x = x1; x <= x2; x++) {
            this->rowValue[y][x] = value;
        }
    }
    return 1;
}

int InfluenceMap::incrementValue(int x, int y, unsigned char value) {
    int rx = x - this->xReferencePointValue;
    int ry = y - this->yReferencePointValue;

    if (rx < 0 || ry < 0 || rx >= this->xSizeValue || ry >= this->ySizeValue)
        return 0;

    if (this->rowValue[ry][rx] >= this->unchangeableLimitValue)
        return 1;

    int sum = (int)(unsigned char)this->rowValue[ry][rx] + (int)(unsigned char)value;
    if (sum >= (int)(unsigned char)this->unchangeableLimitValue) {
        this->rowValue[ry][rx] = (unsigned char)((int)(unsigned char)this->unchangeableLimitValue - 1);
        return 1;
    }
    this->rowValue[ry][rx] = (unsigned char)sum;
    return 1;
}

int InfluenceMap::incrementValue(int x1, int y1, int x2, int y2,
                                 unsigned char amount)
{
    x1 -= this->xReferencePointValue;
    x2 -= this->xReferencePointValue;
    y1 -= this->yReferencePointValue;
    y2 -= this->yReferencePointValue;

    if (x1 < 0)
        x1 = 0;
    else if (x1 >= this->xSizeValue)
        x1 = this->xSizeValue - 1;

    // the shipped code compares y coordinates with xSizeValue.
    if (y1 < 0)
        y1 = 0;
    else if (y1 >= this->xSizeValue)
        y1 = this->xSizeValue - 1;

    if (x2 < 0)
        x2 = 0;
    else if (x2 >= this->xSizeValue)
        x2 = this->xSizeValue - 1;

    // the shipped code compares y coordinates with xSizeValue.
    if (y2 < 0)
        y2 = 0;
    else if (y2 >= this->xSizeValue)
        y2 = this->xSizeValue - 1;

    if (y1 <= y2) {
        for (int y = y1; y <= y2; y++) {
            for (int x = x1; x <= x2; x++) {
                if (this->rowValue[y][x] < this->unchangeableLimitValue) {
                    int value = (int)this->rowValue[y][x] + (int)amount;
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

int InfluenceMap::decrementValue(int x, int y, unsigned char amount) {
    int tx = x - xReferencePointValue;
    int ty = y - yReferencePointValue;

    if (tx < 0 || ty < 0 || tx >= xSizeValue || ty >= ySizeValue) {
        return 0;
    }

    unsigned char* cell = &rowValue[ty][tx];

    if (*cell >= unchangeableLimitValue) {
        return 1;
    }

    int diff = (int)*cell - (int)amount;
    if (diff < 0) {
        *cell = 0;
    } else {
        *cell = (unsigned char)diff;
    }

    return 1;
}

int InfluenceMap::decrementValue(int x1, int y1, int x2, int y2,
                                 unsigned char amount)
{
    x1 -= this->xReferencePointValue;
    x2 -= this->xReferencePointValue;
    y1 -= this->yReferencePointValue;
    y2 -= this->yReferencePointValue;

    if (x1 < 0)
        x1 = 0;
    else if (x1 >= this->xSizeValue)
        x1 = this->xSizeValue - 1;

    // the shipped code compares y coordinates with xSizeValue.
    if (y1 < 0)
        y1 = 0;
    else if (y1 >= this->xSizeValue)
        y1 = this->xSizeValue - 1;

    if (x2 < 0)
        x2 = 0;
    else if (x2 >= this->xSizeValue)
        x2 = this->xSizeValue - 1;

    // the shipped code compares y coordinates with xSizeValue.
    if (y2 < 0)
        y2 = 0;
    else if (y2 >= this->xSizeValue)
        y2 = this->xSizeValue - 1;

    if (y1 <= y2) {
        for (int y = y1; y <= y2; y++) {
            for (int x = x1; x <= x2; x++) {
                if (this->rowValue[y][x] < this->unchangeableLimitValue) {
                    int value = (int)this->rowValue[y][x] - (int)amount;
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

int InfluenceMap::setCoverageCount(const XYPoint& from, const XYPoint& to,
                                   int threshold)
{
    this->coverageCountValue = 0;

    if (from.x < 0 || from.y < 0 || from.x >= this->xSizeValue ||
        from.y >= this->ySizeValue || to.x < 0 || to.y < 0 ||
        to.x >= this->xSizeValue || to.y >= this->ySizeValue) {
        return 0;
    }

    for (int x = from.x; x <= to.x; x++) {
        for (int y = from.y; y <= to.y; y++) {
            int xr = x - this->xReferencePointValue;
            if (this->rowValue[y - this->yReferencePointValue][xr] >= threshold) {
                this->coverageCountValue++;
            }
        }
    }

    return this->coverageCountValue;
}

int InfluenceMap::setConnectionCount(const XYPoint& from, const XYPoint& to,
                                     int minimum, int edgeHorizontal,
                                     int edgeVertical, int allDirections)
{
    InfluenceMap* self = this;

    self->connectionCountValue = 0;

    if (from.x < 0 || from.y < 0 || from.x >= self->xSizeValue ||
        from.y >= self->ySizeValue || to.x < 0 || to.y < 0 ||
        to.x >= self->xSizeValue || to.y >= self->ySizeValue) {
        return 0;
    }

    for (int x = from.x; x <= to.x; ++x) {
        int y = from.y;
        if (y <= to.y) {
            unsigned char** rows = self->rowValue;
            int xOffset = x - self->xReferencePointValue;
            do {
                if (rows[y - self->yReferencePointValue][xOffset] >= minimum) {
                    int neighborX = x;
                    int neighborY = y;

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

                        if (allDirections || (direction % 2) != 0) {
                            if (neighborX >= 0 && neighborX < self->xSizeValue &&
                                neighborY >= 0 && neighborY < self->ySizeValue) {
                                if (rows[neighborY - self->yReferencePointValue]
                                               [neighborX - self->xReferencePointValue] >= minimum) {
                                    ++self->connectionCountValue;
                                }
                            } else if ((edgeHorizontal == 1 &&
                                        (direction % 2) == 1) ||
                                       (edgeVertical == 1 &&
                                        (direction % 2) == 0)) {
                                ++self->connectionCountValue;
                            }
                        }
                    }
                }
                ++y;
            } while (y <= to.y);
        }
    }

    return self->connectionCountValue;
}

int InfluenceMap::coverageIncluding(const XYPoint& from, const XYPoint& to,
                                    unsigned char minimum,
                                    unsigned char amount)
{
    int rVal = this->coverageCountValue;

    if (from.x < 0 || from.y < 0 || from.x >= this->xSizeValue ||
        from.y >= this->ySizeValue || to.x < 0 || to.y < 0 ||
        to.x >= this->xSizeValue || to.y >= this->ySizeValue) {
        return 0;
    }

    for (int x = from.x; x <= to.x; x++) {
        if (from.y <= to.y) {
            int xOffset = x - this->xReferencePointValue;
            int y = from.y;
            int rows = (to.y - from.y) + 1;

            do {
                if (this->rowValue[y - this->yReferencePointValue][xOffset] < minimum &&
                    this->rowValue[y - this->yReferencePointValue][xOffset] + amount >= minimum) {
                    rVal++;
                }
                y++;
            } while (--rows);
        }
    }

    return rVal;
}

int InfluenceMap::connectionsIncluding(const XYPoint& from, const XYPoint& to,
                                       unsigned char minimum,
                                       unsigned char amount, int mode1,
                                       int mode2, int allDirections)
{
    int edgeResult;
    int result = this->connectionCountValue;

    if (from.x < 0 || from.y < 0 || from.x >= this->xSizeValue ||
        from.y >= this->ySizeValue || to.x < 0 || to.y < 0 ||
        to.x >= this->xSizeValue || to.y >= this->ySizeValue) {
        return 0;
    }

    for (int x = from.x; x <= to.x; ++x) {
        int y = from.y;
        if (from.y <= to.y) {
            unsigned char** rowsMap = this->rowValue;
            int xOffset = x - this->xReferencePointValue;

            do {
                if ((int)rowsMap[y - this->yReferencePointValue][xOffset] +
                        (int)amount >= (int)minimum) {
                    if (rowsMap[y - this->yReferencePointValue][xOffset] >= minimum) {
                        edgeResult = result;
                        int neighborY;
                        int neighborX;
                        neighborX = x;
                        neighborY = y;

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

                            if (allDirections || direction % 2 != 0) {
                                if (neighborX < 0 || neighborX >= this->xSizeValue ||
                                    neighborY < 0 || neighborY >= this->ySizeValue) {
                                    if ((mode1 == 1 && direction % 2 == 1) ||
                                        (mode2 == 1 && direction % 2 == 0)) {
                                        --edgeResult;
                                    }
                                    if (edgeResult <= 0)
                                        break;
                                }
                            }
                        }
                        result = edgeResult;
                    }

                    int neighborX = x;
                    int neighborY = y;
                    for (int direction = 0; direction < 8; ++direction) {
                        switch (direction) {
                        case 0:
                            --neighborX;
                            // fall through
                        case 7:
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
                        }

                        if (allDirections || direction % 2 != 0) {
                            if (neighborX < 0 || neighborX >= this->xSizeValue ||
                                neighborY < 0 || neighborY >= this->ySizeValue) {
                                if ((mode1 == 1 && direction % 2 == 1) ||
                                    (mode2 == 1 && direction % 2 == 0)) {
                                    --result;
                                }
                            } else if (rowsMap[neighborY - this->yReferencePointValue]
                                             [neighborX - this->xReferencePointValue] >= minimum) {
                                result += 2;
                            }
                        }
                    }
                }
                ++y;
            } while (y <= to.y);
        }
    }

    return result;
}

void InfluenceMap::setUnchangeableLimit(unsigned char value) {
    if (value > 0)
        this->unchangeableLimitValue = value;
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

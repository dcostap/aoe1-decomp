// VA: 0046B360 PathingSystem::printToFile(char*) (486B)
// pathsys.cpp lines 172-219
//
// Natural reconstruction of the path-obstruction text dump.  The source keeps
// the original four-tile row/column formatting, including the extra ignored
// varargs on the separator-only fprintf calls visible in the executable.
//
// Attempt log:
// - Baseline: typed stdio calls, x/y fields, the real obstruction member ABI,
//   and natural header/row scans aligned all 18 calls but stayed 20 bytes
//   short; the compiler chose EBX for the filename instead of the target's
//   EDI and folded the known-zero first-row modulo test.
// - Virtual/self context, local declaration scope, FILE lifetime, and while
//   versus do/while forms were codegen duplicates.  The target's footer uses
//   the old row quotient with a separately computed next row, so the living
//   source retains that explicit period-plausible nextRow form.
// - Best current reconstruction: 478 bytes, 141 strict differing bytes,
//   18/18 ordered calls, and exact size/call/CFG counts.  Remaining drift is
//   the persistent EBP/EDI coloring and first-row/footer block layout; no
//   compiler-steering volatility, raw addresses, or fake calls are retained.

struct FILE;
extern "C" FILE* __cdecl fopen(const char* filename, const char* mode);
extern "C" int __cdecl fprintf(FILE* file, const char* format, ...);
extern "C" int __cdecl fclose(FILE* file);

class PathingSystem {
public:
    virtual ~PathingSystem();
    int xSizeValue;
    int ySizeValue;
    char gap_0c[0x11DC2C - 0x0C];

    unsigned char obstruction(int x, int y);
    void printToFile(char* filename);
};

void PathingSystem::printToFile(char* filename)
{
    int row;
    int i;
    PathingSystem* path = this;
    if (filename != 0) {
        FILE* file = fopen(filename, "wa");
        if (file != 0) {
            fprintf(file, "FILENAME: %s\n", filename);
            fprintf(file, "  Dimensions: %d X %d\n",
                    path->xSizeValue << 2, path->ySizeValue << 2);
            fprintf(file, "\n");
            fprintf(file, "       ");

            i = 0;
            if (path->xSizeValue > 0) {
                do {
                    fprintf(file, "%04d ", i);
                    ++i;
                } while (i < path->xSizeValue);
            }

            fprintf(file, "\n");
            fprintf(file, "       ");
            i = 0;
            if (path->xSizeValue > 0) {
                do {
                    fprintf(file, "---- ", i);
                    ++i;
                } while (i < path->xSizeValue);
            }

            fprintf(file, "\n");

            row = 0;
            while (row < (path->ySizeValue << 2)) {
                    if (row % 4 == 0) {
                        fprintf(file, "R%03d: ", row / 4);
                    } else {
                        fprintf(file, "      ");
                    }

                    int column = 0;
                    if ((path->xSizeValue << 2) > 0) {
                        do {
                            if (column % 4 == 0) {
                                fprintf(file, " %1d", path->obstruction(column, row));
                            } else {
                                fprintf(file, "%1d", path->obstruction(column, row));
                            }
                            ++column;
                        } while (column < (path->xSizeValue << 2));
                    }

                    int nextRow = row + 1;
                    int rowNumber = row / 4;
                    fprintf(file,
                            ((nextRow % 4) == 0) ? "  :R%03d\n\n" : "\n",
                            rowNumber);
                    row = nextRow;
            }

            fprintf(file, "\n");
            fclose(file);
        }
    }
}

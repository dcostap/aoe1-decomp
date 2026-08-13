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
// - Best pre-footer reconstruction: 478 bytes, 141 strict differing bytes,
//   18/18 ordered calls, and exact size/call/CFG counts.  Its remaining drift
//   was the persistent EBP/EDI coloring and footer block layout.
// - Direct-member lifetime probe: removed the pre-guard self alias so the
//   natural source delays `this` until fopen succeeds, as the target does.
//   VC5 emitted the same 478 bytes, so no new structural lead remains.
// - Footer cleanup probe: split the conditional format into two ordinary
//   fprintf calls and kept the ignored quotient argument on the newline call.
//   This restored the target size and CFG, reducing the diff to 22 bytes.
// - Reused the header counter for rows and hoisted the column counter; VC5
//   retained the same 22-byte register-coloring drift, so this remains the
//   best natural source reconstruction.
// - Swapped the natural row/column declaration order to test EDI row and EBX
//   column coloring; VC5 emitted the same 486 bytes and 22-byte drift.

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
    int column;
    int i;
    if (filename != 0) {
        FILE* file = fopen(filename, "wa");
        if (file != 0) {
            fprintf(file, "FILENAME: %s\n", filename);
            fprintf(file, "  Dimensions: %d X %d\n",
                    this->xSizeValue << 2, this->ySizeValue << 2);
            fprintf(file, "\n");
            fprintf(file, "       ");

            i = 0;
            if (this->xSizeValue > 0) {
                do {
                    fprintf(file, "%04d ", i);
                    ++i;
                } while (i < this->xSizeValue);
            }

            fprintf(file, "\n");
            fprintf(file, "       ");
            i = 0;
            if (this->xSizeValue > 0) {
                do {
                    fprintf(file, "---- ", i);
                    ++i;
                } while (i < this->xSizeValue);
            }

            fprintf(file, "\n");

            i = 0;
            while (i < (this->ySizeValue << 2)) {
                    if (i % 4 == 0) {
                        fprintf(file, "R%03d: ", i / 4);
                    } else {
                        fprintf(file, "      ");
                    }

                    column = 0;
                    if ((this->xSizeValue << 2) > 0) {
                        do {
                            if (column % 4 == 0) {
                                fprintf(file, " %1d", this->obstruction(column, i));
                            } else {
                                fprintf(file, "%1d", this->obstruction(column, i));
                            }
                            ++column;
                        } while (column < (this->xSizeValue << 2));
                    }

                    int nextRow = i + 1;
                    if ((nextRow % 4) == 0) {
                        fprintf(file, "  :R%03d\n\n", i / 4);
                    } else {
                        fprintf(file, "\n", i / 4);
                    }
                    i = nextRow;
            }

            fprintf(file, "\n");
            fclose(file);
        }
    }
}

// VA: 0044E250 InfluenceMap::printToFile
// Attempt log:
// 1: direct reconstruction from packet/decompiler; use exact string addresses: close through headers, mismatch in row loop because rowValue offset modeled +14 not original +18.
// 2: added gap for rowValue +18; fixed row offset, remaining mismatch from row-byte spill/mask and missing saved row index stack slot.
// 3: changed rowValue to unsigned char** and val int; row loop now very close, diff down to 0.982% positional / 0.818% edit.
// 4: current best same-size 611 B, equal until offset 0x1A0 and after 0x1A7; only drift is `mov ebp,edi` scheduled before vs after `add esp,0Ch` following one fprintf in row footer, plus resulting branch displacement byte. Behavior/calls/stack cleanup/memory effects unchanged.
// accepted_drift proposal: localized instruction scheduling drift around independent row-index assignment after fprintf.

struct FILE;
extern "C" FILE* __cdecl fopen(const char*, const char*);
extern "C" int __cdecl fprintf(FILE*, const char*, ...);
extern "C" int __cdecl fclose(FILE*);

class InfluenceMap {
public:
    void* vtable;
    int xSizeValue;
    int ySizeValue;
    int xReferencePointValue;
    int yReferencePointValue;
    char gap_14[4];
    unsigned char** rowValue;
    void printToFile(char* filename);
};

void InfluenceMap::printToFile(char* filename)
{
    if (filename != 0) {
        FILE* f = fopen(filename, (char*)0x0057F4EC);
        if (f != 0) {
            fprintf(f, (char*)0x00584858, filename);
            fprintf(f, (char*)0x00584840, this->xSizeValue, this->ySizeValue);
            fprintf(f, (char*)0x00584820, this->xReferencePointValue, this->yReferencePointValue);
            fprintf(f, (char*)0x00583994);

            fprintf(f, (char*)0x00584818);
            int i = 0;
            if (this->xSizeValue > 0) {
                do {
                    if (i % 5 == 0) {
                        fprintf(f, (char*)0x00584810, i);
                    } else {
                        fprintf(f, (char*)0x00584808, i);
                    }
                    i++;
                } while (i < this->xSizeValue);
            }
            fprintf(f, (char*)0x00583994);

            fprintf(f, (char*)0x00584818);
            i = 0;
            if (this->xSizeValue > 0) {
                do {
                    if (i % 5 == 0) {
                        fprintf(f, (char*)0x00584800, i);
                    } else {
                        fprintf(f, (char*)0x005847F8, i);
                    }
                    i++;
                } while (i < this->xSizeValue);
            }
            fprintf(f, (char*)0x00583994);

            int r = 0;
            if (this->ySizeValue > 0) {
                do {
                    fprintf(f, (char*)0x005847F0, r);
                    i = 0;
                    if (this->xSizeValue > 0) {
                        do {
                            int val = this->rowValue[r][i];
                            if (i % 5 == 0) {
                                fprintf(f, (char*)0x00584810, val);
                            } else {
                                fprintf(f, (char*)0x00584808, val);
                            }
                            i++;
                        } while (i < this->xSizeValue);
                    }
                    int next = r + 1;
                    if (next % 5 == 0) {
                        fprintf(f, (char*)0x005847E4, r);
                    } else {
                        fprintf(f, (char*)0x005847DC, r);
                    }
                    r = next;
                } while (r < this->ySizeValue);
            }

            fprintf(f, (char*)0x00584818);
            i = 0;
            if (this->xSizeValue > 0) {
                do {
                    if (i % 5 == 0) {
                        fprintf(f, (char*)0x00584800, i);
                    } else {
                        fprintf(f, (char*)0x005847F8, i);
                    }
                    i++;
                } while (i < this->xSizeValue);
            }
            fprintf(f, (char*)0x00583994);
            fprintf(f, (char*)0x00584818);
            i = 0;
            if (this->xSizeValue > 0) {
                do {
                    if (i % 5 == 0) {
                        fprintf(f, (char*)0x00584810, i);
                    } else {
                        fprintf(f, (char*)0x00584808, i);
                    }
                    i++;
                } while (i < this->xSizeValue);
            }
            fprintf(f, (char*)0x00583994);
            fclose(f);
        }
    }
}

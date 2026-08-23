// VA: 004E7440 VictoryConditionRuleSystem::loadRules (394B)
// taistrmd.cpp
//
// Exact recovery notes:
// - The prior source used a 260-byte buffer prefix as the second integer output.
//   It matched all bytes except four parsed-character stack displacements.
// - Separate ruleIndex and ruleValue integers with a 256-byte line buffer recover
//   the original dword homes. They also keep first and second `%c` semantics.
// - The authentic taistrmd.cpp prefix loads taistrmd_context.h before this body.
//   A second shard-local include rotates the two byte homes under VC5.
// - Exact-finish walkback proved that both changes are required as one group.
//   Either the old buffer overlay or the repeated include restores the four-byte drift.
// - Sixteen natural declaration orders emitted one exact code group. The retained
//   order follows parse meaning. Array and overlay forms emitted a word load.
// Final reduced source: MATCH, 0 differing bytes, 394 bytes.

extern "C" int __cdecl strcmp(const char* left, const char* right);
extern "C" unsigned int __cdecl strlen(const char* text);
extern "C" int __cdecl sprintf(char* buffer, const char* format, ...);
extern "C" void* __cdecl fopen(const char* filename, const char* mode);
extern "C" char* __cdecl fgets(char* buffer, int count, void* stream);
extern "C" int __cdecl sscanf(const char* buffer, const char* format, ...);
extern "C" int __cdecl fclose(void* stream);
extern "C" char* __cdecl strstr(const char* text, const char* search);
extern "C" int __cdecl _unlink(const char* filename);

#pragma intrinsic(strcmp)
#pragma intrinsic(strlen)

int VictoryConditionRuleSystem::loadRules(char* filename)
{
    char commentTemp1;
    char commentTemp2;
    int ruleIndex;
    int ruleValue;
    char temp[256];
    void* file;

    if (strcmp(filename, "NONE") != 0 &&
        filename != 0 &&
        strlen(filename) != 0) {
        sprintf(temp, "%s", filename);
        file = fopen(temp, "r");
        if (file != 0) {
            while (fgets(temp, 0x100, file) != 0) {
                // BINARY NOTE: The shipped parser ignores both sscanf results.
                // Keep these outputs uninitialized for malformed input.
                sscanf(temp, " %c%c",
                       &commentTemp1, &commentTemp2);
                if ((commentTemp1 != '/' || commentTemp2 != '/') &&
                    (commentTemp1 != 'D' || commentTemp2 != 'E') &&
                    (commentTemp1 != 'V' || commentTemp2 != 'C')) {
                    if (commentTemp1 == 'E' && commentTemp2 == 'N') {
                        break;
                    }
                    sscanf(temp, "%d %d ",
                           &ruleIndex, &ruleValue);
                    if (ruleIndex >= 0 && ruleIndex < 0xE2) {
                        this->sn[ruleIndex] = ruleValue;
                    }
                }
            }
            fclose(file);
            if (strstr(filename, ".tmp") != 0) {
                _unlink(filename);
            }
            return 1;
        }
    }
    return 0;
}

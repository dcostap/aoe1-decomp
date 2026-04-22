// Keep <stdlib.h> as part of the proven dstring.cpp include context.
// On VC5 this otherwise unused header flips the `isspace` byte-load addressing
// into the original exact-match SIB family for this function.
#include <stdlib.h>

extern "C" int __cdecl isspace(int c);

class DString {
public:
    char* stringValue;
    int lengthValue;
    int numWordsValue;
    int indexValue;
    int currentWordValue;

    int numWords(void);
};

int DString::numWords(void) {
    int cached;
    int index;
    int inWord;

    cached = this->numWordsValue;
    if (cached == -1) {
        cached = this->lengthValue;
        if (cached == 0) {
            return cached;
        }

        if (this->stringValue[0] == ' ') {
            this->numWordsValue = 0;
            inWord = 0;
        } else {
            this->numWordsValue = 1;
            inWord = 1;
        }

        index = 0;
        if (cached > 0) {
            do {
                if (!inWord) {
                    if (isspace((int)index[this->stringValue])) {
                        goto still_in_gap;
                    }
                    cached = this->numWordsValue;
                    inWord = 1;
                    cached = cached + 1;
                    this->numWordsValue = cached;
                    goto next_index;
                }

still_in_gap:
                if (isspace((int)index[this->stringValue])) {
                    inWord = 0;
                }

next_index:
                cached = this->lengthValue;
                index = index + 1;
            } while (index < cached);
        }

        cached = this->numWordsValue;
    }

    return cached;
}

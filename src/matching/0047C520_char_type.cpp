// first pass: direct null/zero gate, IsDBCSLeadByte branch, then kana range
// if this stays close but not exact, the remaining mismatch is likely just VC5 codegen drift

#include <windows.h>

class TTextPanel {
public:
    enum CharType {
        SingleByteChar = 0,
        SingleByteKanaChar = 1,
        DoubleByteChar = 2,
    };

    CharType char_type(unsigned char* text);
};

TTextPanel::CharType TTextPanel::char_type(unsigned char* text) {
    if (text != 0 && *text != 0) {
        if (IsDBCSLeadByte(*text) != 0) {
            return DoubleByteChar;
        }

        if (*text >= 0xA1 && *text <= 0xDF) {
            return SingleByteKanaChar;
        }
    }

    return SingleByteChar;
}

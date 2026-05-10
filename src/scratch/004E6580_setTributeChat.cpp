// VA: 004E6580 setTributeChat (117B)
// taimdmd.cpp
//
// Attempt log:
// 1. Original scratch behavior right but source evaluated all strategicNumber calls before arithmetic, causing saved ECX/EBP stack-temp basin and broad shifted diff (78.6% pos / 73.5% edit).
// 2. Reordered source to perform rand % strategic(0x7E), then strategic(0x7E)/2, then add strategic(0x7D). This matches the original arithmetic/call interleave and improves to 35.0% pos / 24.8% edit, but VC5 keeps `this` in EBX and result in EDI instead of original `this` in EDI and result in EBX.
// 3. Tried direct member access vs tactical local, raw pointer offsets, self/out locals, register locals, early declarations, single final store, explicit half formula, and flags /Oa /Og /Ot /Ob0 /G5 /Gs /GX /O1 /Od. No exact; best remains ordered expression with this/result register swap.
// BLOCKER: remaining mismatch is a register-allocation basin from byte 0 (EBX/EDI swapped), not localized drift.

class TribeTacticalAIModule {
public:
    int strategicNumber(int id);
};

extern "C" int __cdecl debug_rand(char* file, int line);

class TribeMainDecisionAIModule {
public:
    char gap_00[0x1146C];
    TribeTacticalAIModule tacticalAI;
    char gap_after[0x12588 - 0x1146C - 1];
    int tributeChatTimeout;

    void setTributeChat();
};

void TribeMainDecisionAIModule::setTributeChat() {
    TribeTacticalAIModule* tactical = &this->tacticalAI;
    if (tactical->strategicNumber(0x7E) > 0) {
        int r = debug_rand("C:\\msdev\\work\\age1_x1\\taimdmd.cpp", 0x41D) % tactical->strategicNumber(0x7E);
        r -= tactical->strategicNumber(0x7E) / 2;
        r += tactical->strategicNumber(0x7D);
        this->tributeChatTimeout = r;
    } else {
        this->tributeChatTimeout = tactical->strategicNumber(0x7D);
    }
}

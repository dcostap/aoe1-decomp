#ifndef AIPBOOK_CANONICAL_TU
class AIPlay {
protected:
    char *convertToNameType(unsigned char value) const;
};
#endif

char *AIPlay::convertToNameType(unsigned char value) const {
    switch (value) {
    case 1:
        return "Attack";
    case 2:
        return "Annoy";
    case 3:
        return "Flank";
    case 4:
        return "Recon";
    default:
        return "Invalid";
    }
}

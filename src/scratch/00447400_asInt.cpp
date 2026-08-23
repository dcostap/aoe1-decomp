extern int __cdecl stringToInt(const char *s);

class TString {
public:
    const char *str;
    int asInt();
};

int TString::asInt() {
    return stringToInt(this->str);
}

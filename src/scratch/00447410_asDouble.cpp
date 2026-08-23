extern double __cdecl stringToDouble(const char *s);

class TString {
public:
    const char *str;
    double asDouble();
};

double TString::asDouble() {
    return stringToDouble(this->str);
}

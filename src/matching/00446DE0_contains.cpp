extern "C" char* __cdecl strstr(const char* string1, const char* string2);

class DString {
public:
    char* stringValue;
    long lengthValue;
    long numWordsValue;
    long indexValue;
    long currentWordValue;

    int contains(const char* value) const;
};

int DString::contains(const char* value) const {
    return strstr(this->stringValue, value) != 0;
}

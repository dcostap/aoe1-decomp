class istream {
public:
    char gap_00[4];
    int fGline;

    istream& get(char* buffer, int size, int delimiter);
};

class DString {
public:
    char* stringValue;
    long lengthValue;
    long numWordsValue;
    long indexValue;
    long currentWordValue;

    DString& operator=(const char* value);
};

istream& __cdecl operator>>(istream& stream, DString& value) {
    char buffer[256];

    stream.fGline = stream.fGline + 1;
    stream.get(buffer, 0x100, 10);
    value = buffer;
    return stream;
}

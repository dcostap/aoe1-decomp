class ostream {
public:
    ostream& operator<<(const char* value);
};

class DString {
public:
    char* stringValue;
};

ostream& __cdecl operator<<(ostream& stream, const DString& value) {
    if (value.stringValue != 0) {
        stream << value.stringValue;
    }
    return stream;
}

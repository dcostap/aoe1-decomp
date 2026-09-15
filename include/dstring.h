#ifndef AOE1_DSTRING_H
#define AOE1_DSTRING_H

// Shared declarations for the dstring.cpp source module.
// The executable stores stringValue at offset 0 and four int state fields after it.
class DString {
public:
    char* stringValue;
    int lengthValue;
    int numWordsValue;
    int indexValue;
    int currentWordValue;

    DString();
    DString(const DString& d);
    DString(const char* s);
    ~DString();
    DString& operator=(const char* s);
    DString& operator=(const DString& d);

    char& operator[](int i);
    operator char*() const;
    DString operator+(const DString& d) const;
    int length() const;
    int numWords();
    int index() const;
    int contains(DString s) const;
    int contains(const char* s) const;
    DString word(int num);
    DString nextWord(int incIndex);
    void moveToFirstWord();
    void moveToNextWord();
    DString subString(int start, int count);
    void append(DString d);
    DString stripTrailing(char c);
    DString stripLeading(char c);
    int asInt() const;
    double asDouble() const;
    void uppercase();
    DString asUppercase();
    void lowercase();
    DString asLowercase();
    void change(char o, char n);
};

class istream;
class ostream;

ostream& __cdecl operator<<(ostream& out, const DString& d);
istream& __cdecl operator>>(istream& in, DString& d);

int __cdecl operator==(const DString& one, const DString& two);
int __cdecl operator==(const DString& one, const char* two);
int __cdecl operator==(const char* one, const DString& two);
int __cdecl operator!=(const DString& one, const DString& two);
int __cdecl operator!=(const DString& one, const char* two);
int __cdecl operator!=(const char* one, const DString& two);
int __cdecl operator<(const DString& one, const DString& two);
int __cdecl operator<(const DString& one, const char* two);
int __cdecl operator<(const char* one, const DString& two);
int __cdecl operator>(const DString& one, const DString& two);
int __cdecl operator>(const DString& one, const char* two);
int __cdecl operator>(const char* one, const DString& two);

class DKeyString {
public:
    DString keyValue;
    DString valueValue;

    DKeyString();
    DKeyString(DString k, DString v);
    ~DKeyString();
    DString key() const;
    void setKey(DString k);
    DString value() const;
    void setValue(DString v);
};

#endif

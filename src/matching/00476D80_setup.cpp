// attempt 1: natural TInputPanel setup wrapper around TTextPanel::setup

unsigned long debug_timeGetTime(char* file, int line);
void* calloc(unsigned int, unsigned int);

class TDrawArea {}; class TPanel {}; class TDigital {};
class TTextPanel {
public:
    virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0c(); virtual void vf10(); virtual void vf14(); virtual void vf18(); virtual void vf1c();
    virtual void vf20(); virtual void vf24(); virtual void vf28(); virtual void vf2c(); virtual void vf30(); virtual void vf34(); virtual void vf38(); virtual void vf3c();
    virtual void vf40(); virtual void vf44(); virtual void vf48(); virtual void vf4c(); virtual void vf50(); virtual void vf54(); virtual void vf58(); virtual void vf5c();
    virtual void vf60(); virtual void vf64(); virtual void vf68(); virtual void vf6c(); virtual void vf70(); virtual void vf74(); virtual void vf78(); virtual void vf7c();
    virtual void vf80(); virtual void vf84(); virtual void vf88(); virtual void vf8c(); virtual void vf90(); virtual void vf94(); virtual void vf98(); virtual void vf9c();
    virtual void vfA0(); virtual void vfA4(); virtual void vfA8(); virtual void vfAC(); virtual void vfB0(); virtual void vfB4(); virtual void vfB8(); virtual void vfBC();
    virtual void vfC0(); virtual void vfC4(); virtual void vfC8(); virtual void vfCC(); virtual void vfD0(); virtual void vfD4(); virtual void vfD8(); virtual void vfDC();
    virtual void vfE0(); virtual void vfE4(); virtual void set_text(char*);
    long setup(TDrawArea*, TPanel*, long,long,long,long, void*, long,long,char*, long, unsigned char, long, unsigned char, long, char*);
    void set_alignment(int,int);
    void set_word_wrap(int);
};
class TInputPanel: public TTextPanel {
public:
    char gap[0x188 - 4];
    unsigned char field_188;
    char pad_189[7];
    unsigned long field_190;
    long field_194;
    TDigital* field_198;
    long field_19C;
    char* field_1A0;
    char* field_1A4;
    char* field_1A8;
    short field_1AC;
    short field_1AE;
    long setup(TDrawArea*, TPanel*, long,long,long,long, void*, long,long,char*, long, unsigned char, long, unsigned char, unsigned char, short, TDigital*, char*, long);
    void update_display();
};

long TInputPanel::setup(TDrawArea* da, TPanel* parent, long p3,long p4,long p5,long p6, void* p7, long p8,long p9,char* p10,long p11,unsigned char p12,long p13,unsigned char p14,unsigned char p15, short maxChars, TDigital* digital, char* text, long format) {
    long setupMax = (format == 7) ? 0 : maxChars;
    if (TTextPanel::setup(da,parent,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14,setupMax,0) == 0) {
        return 0;
    }
    this->field_188 = p15;
    this->field_19C = format;
    if (*(long*)((char*)this + 0x78)) {
        this->field_194 = 1;
        this->field_190 = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Pnl_inp.cpp", 89);
    }
    if (maxChars) this->field_198 = digital; else this->field_198 = 0;
    if (this->field_19C == 7) {
        this->set_alignment(3,1);
        this->set_word_wrap(1);
    } else {
        this->set_alignment(0,5);
    }
    this->field_1A4 = (char*)calloc((int)maxChars + (int)maxChars + 1,1);
    if (!this->field_1A4) return 0;
    this->field_1A8 = (char*)calloc((int)maxChars + (int)maxChars + 1,1);
    if (!this->field_1A8) return 0;
    this->field_1A0 = this->field_1A4;
    this->set_text(text);
    this->field_1AE = maxChars;
    this->update_display();
    return 1;
}

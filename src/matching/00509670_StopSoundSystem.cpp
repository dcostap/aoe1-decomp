void __cdecl operator delete(void* ptr);

class TDigital {
public:
    ~TDigital();
};

class TTaunt {
public:
    TDigital* Audio[4];

    void StopSoundSystem(void);
};

void TTaunt::StopSoundSystem(void) {
    int i = 4;
    TDigital** audio = this->Audio;

    do {
        TDigital* digital = *audio;
        if (digital != 0) {
            digital->~TDigital();
            operator delete(digital);
            *audio = 0;
        }
        audio = audio + 1;
        i = i - 1;
    } while (i != 0);
}

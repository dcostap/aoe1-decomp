// 00509530 TTaunt::PlayTauntNo
// Source: taunt.cpp lines 59-116
// Size: 209 bytes, no EH
//
// Attempt log:
// Baseline: canonical TTaunt layout and natural nested guards/Audio loops.
// Probe 2: break-based scan changed the physical tail but lost the distinct exhaustion return.
// Probe 3-5: explicit post-scan guards remained in the merged common-return basin.
// Probe 6: handle load/play/unload inside the positive scan arm; exact in variant lab.
// Probe 7: normal checker validation confirmed exact bytes (209/209).

extern "C" int __cdecl sprintf(char* buffer, const char* format, ...);

#ifndef AOE1_TAUNT_CONTEXT_H
class TDigital {
public:
    int is_playing();
    void unload();
    int load(char* name, long param);
    int play();
};

class TTaunt {
public:
    TDigital* Audio[4];
    int LastAudioPlayed;
    char TBuff[255];
    char TauntDir[128];
    unsigned char _pad_193;
    int Mute;

    int PlayTauntNo(int num);
};
#endif

int TTaunt::PlayTauntNo(int num)
{
    char FName[128];

    if (this->Mute == 0) {
        if (this->TauntDir != 0) {
            if (num != 0) {
                sprintf(FName, "%sTaunt%.3d.wav", this->TauntDir, num);

                int i;
                for (i = 0; i < 4; i++) {
                    if (this->Audio[i] != 0 && this->Audio[i]->is_playing() == 0) {
                        this->Audio[i]->unload();
                    }
                }

                for (i = 0; i < 4; i++) {
                    if (this->Audio[i] == 0 || this->Audio[i]->is_playing() != 0) {
                        continue;
                    }
                    if (this->Audio[i]->load(FName, -1) != 0)
                        return this->Audio[i]->play();
                    this->Audio[i]->unload();
                    return 0;
                }
                return 0;
            }
        }
    }
    return 0;
}

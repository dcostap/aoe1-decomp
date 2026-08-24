#include "../../include/cdaudio_context.h"

CCDAudio::~CCDAudio(void) {
    int playing;

    IsPlaying(playing);
    if (playing != 0) {
        Stop();
    }
    Close();
}

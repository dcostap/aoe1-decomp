class CCDAudio {
public:
    int m_Wnd;
    int m_bOpened;
    unsigned int m_nDeviceID;

    unsigned long IsPlaying(int* playing);
    unsigned long Stop(void);
    unsigned long Close(void);
    ~CCDAudio(void);
};

CCDAudio::~CCDAudio(void) {
    int playing;

    IsPlaying(&playing);
    if (playing != 0) {
        Stop();
    }
    Close();
}

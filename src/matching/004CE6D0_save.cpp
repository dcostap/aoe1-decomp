void rge_write(int file, void* data, int size);

struct DiscoverySizeInfo {
    char gap_00[0x3C];
    short size;
};

struct DiscoveryInfo {
    char gap_00[0x3C];
    DiscoverySizeInfo* size_info;
};

struct DiscoveryMaster {
    char gap_00[0x0C];
    DiscoveryInfo* info;
};

class RGE_Action {
public:
    virtual void vf00(void);
    char gap_04[0x04];
    void save(int file);
};

class TRIBE_Action_Discovery_Artifact : public RGE_Action {
public:
    DiscoveryMaster* master;
    char gap_0C[0x34];
    void* flags;

    void save(int file);
};

void TRIBE_Action_Discovery_Artifact::save(int file) {
    int size;

    RGE_Action::save(file);
    size = this->master->info->size_info->size;
    rge_write(file, this->flags, size);
}

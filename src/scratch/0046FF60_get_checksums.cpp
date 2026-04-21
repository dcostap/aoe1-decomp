class RGE_Player_gc {
public:
    unsigned char get_checksums(int* cksum1, int* cksum2, int* cksum3);
    void calculate_checksums(void);
    char gap_00[0x14];
    int checksum1;
    int checksum2;
    int checksum3;
    unsigned char checksums_valid;
};

unsigned char RGE_Player_gc::get_checksums(int* cksum1, int* cksum2, int* cksum3) {
    if (!this->checksums_valid)
        this->calculate_checksums();
    *cksum1 = this->checksum1;
    *cksum2 = this->checksum2;
    *cksum3 = this->checksum3;
    return 1;
}

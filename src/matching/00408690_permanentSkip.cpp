class BuildItem {
public:
    virtual ~BuildItem();
    char gap_04[0xA8];
    unsigned char permanentSkip_;

    unsigned char permanentSkip();
};

unsigned char BuildItem::permanentSkip() {
    return this->permanentSkip_;
}

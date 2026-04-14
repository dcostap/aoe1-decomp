class BuildItem {
public:
    virtual ~BuildItem();
    char gap_04[0xA8];
    unsigned char permanentSkip_;

    void setPermanentSkip(unsigned char);
};

void BuildItem::setPermanentSkip(unsigned char val) {
    this->permanentSkip_ = val;
}

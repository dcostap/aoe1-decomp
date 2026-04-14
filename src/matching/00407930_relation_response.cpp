class RGE_Action {
public:
    virtual unsigned char relation_response(long, unsigned char);
};

unsigned char RGE_Action::relation_response(long, unsigned char) {
    return 0;
}

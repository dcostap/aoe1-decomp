class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual void *vector_deleting_destructor(unsigned int param_1);
};

void operator_delete(void *param_1);

void *RGE_Base_Game::vector_deleting_destructor(unsigned int param_1) {
    this->RGE_Base_Game::~RGE_Base_Game();
    if ((param_1 & 1) != 0) {
        operator_delete(this);
    }
    return this;
}

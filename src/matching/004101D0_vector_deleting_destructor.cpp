// VA: 004101D0 AIPlayBook::`vector deleting destructor' (30B)
// Exact source recovery: preserve the virtual AIPlayBook destructor owner and
// qualified direct cleanup call, then apply the flag-controlled delete path.

class AIPlayBook {
public:
    virtual ~AIPlayBook();
    void *vector_deleting_destructor(unsigned int param_1);
};

void operator_delete(void *param_1);

void *AIPlayBook::vector_deleting_destructor(unsigned int param_1) {
    this->AIPlayBook::~AIPlayBook();
    if ((param_1 & 1) != 0) {
        operator_delete(this);
    }
    return this;
}

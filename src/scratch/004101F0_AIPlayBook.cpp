// 004101F0 AIPlayBook::~AIPlayBook

void operator_delete(void*);

AIPlayBook::~AIPlayBook() {
    if (this->plays) {
        this->numberPlaysValue = 0;
        operator_delete(this->plays);
        this->plays = 0;
    }
}

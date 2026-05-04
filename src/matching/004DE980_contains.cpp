// 004DE980 ManagedArray<int>::contains
// Source: utmarray.h lines 86-93
// exact result came from variant-lab reduction back to the simplest natural for-loop shape

class ManagedArray_int {
public:
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;

    int contains(const int& value) const;
};

int ManagedArray_int::contains(const int& value) const {
    int i;
    int wanted;
    int current;

    for (i = 0; i < this->numberValue; i++) {
        if (i >= this->maximumSizeValue) {
            return 0;
        }
        current = this->value[i];
        wanted = value;
        if (current == wanted) {
            return 1;
        }
    }
    return 0;
}

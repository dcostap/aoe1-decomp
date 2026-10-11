#ifndef UTMARRAY_H
#define UTMARRAY_H

#include <new.h>

template <class Type> class ManagedArray {
  public:
    typedef int(__cdecl* CompareFunction)(Type left, Type right);

    ManagedArray(int initialSize = 0) : value(0), numberValue(0), desiredNumberValue(0), maximumSizeValue(initialSize) {
        if (initialSize > 0)
            this->value = new Type[initialSize];
    }

    ~ManagedArray() {
        if (this->value != 0) {
            delete[] this->value;
            this->value = 0;
        }
        this->numberValue = 0;
        this->desiredNumberValue = 0;
        this->maximumSizeValue = 0;
    }

    Type& operator[](int v) {
        //! @bug This read never checks numberValue.
        //! Past the count it returns uninitialized memory from resize().
        //! Callers use that stale value as a game-object id. Preserve this read.
        if (v > this->maximumSizeValue - 1)
            this->resize(v + 1);
        return this->value[v];
    }

    int enlarge(int s) {
        this->desiredNumberValue += s;
        return this->desiredNumberValue;
    }

    int shrink(int amount) {
        this->desiredNumberValue -= amount;
        if (this->desiredNumberValue < 0)
            this->desiredNumberValue = 0;
        return this->desiredNumberValue;
    }

    int contains(const Type& r);

    int position(Type& r) {
        int i;
        for (i = 0; i < this->maximumSizeValue; i++) {
            if (this->value[i] == r)
                return i;
        }
        return -1;
    }

    int add(Type r);

    int remove(Type item) {
        int i = 0;
        int maximum = this->maximumSizeValue;

        for (; i < maximum; i++) {
            if (this->value[i] == item)
                break;
        }

        if (i >= maximum)
            return 0;

        maximum--;
        if (i < maximum) {
            do {
                this->value[i] = this->value[i + 1];
                i++;
            } while (i < this->maximumSizeValue - 1);
        }

        this->numberValue--;
        if (this->numberValue < 0)
            this->numberValue = 0;
        return 1;
    }

    const int number() const {
        return this->numberValue;
    }

    const int desiredNumber() const {
        return this->desiredNumberValue;
    }

    void setDesiredNumber(int desired_number) {
        this->desiredNumberValue = desired_number;
    }

    void zeroNumber() {
        this->numberValue = 0;
    }

    const int maximumSize() const {
        return this->maximumSizeValue;
    }

    void sort(CompareFunction cF) {
        int i;
        int j;
        Type temporary;

        for (i = 0; i < this->numberValue; i++) {
            for (j = i + 1; j < this->numberValue; j++) {
                if (cF(this->value[i], this->value[j]) > 0) {
                    temporary = this->value[i];
                    this->value[i] = this->value[j];
                    this->value[j] = temporary;
                }
            }
        }
    }

  public:
    // PDB marks resize protected. Reconstructed callers still require public
    // access, so keep the body here while the source-access boundary is open.
    int resize(int new_size) {
        Type* new_value = new Type[new_size];
        if (new_value == 0)
            return 0;

        int i;
        for (i = 0; i < this->maximumSizeValue && i < new_size; i++) {
            new_value[i] = this->value[i];
        }

        delete[] this->value;
        this->value = new_value;
        this->maximumSizeValue = new_size;
        return 1;
    }

  public:
    Type* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;
};

template <class Type> int ManagedArray<Type>::contains(const Type& r) {
    int i;
    Type wanted;
    Type current;

    for (i = 0; i < this->numberValue; i++) {
        if (i >= this->maximumSizeValue)
            return 0;
        current = this->value[i];
        wanted = r;
        if (current == wanted)
            return 1;
    }
    return 0;
}

template <class Type> int ManagedArray<Type>::add(Type r) {
    int i;

    for (i = 0; i < this->numberValue; i++) {
        if (i >= this->maximumSizeValue)
            break;
        if (this->value[i] == r)
            return 0;
    }
    if (this->numberValue > this->maximumSizeValue - 1) {
        int newSize = this->numberValue + 1;
        Type* newValue = (Type*) ::operator new(newSize * sizeof(Type));
        if (newValue != 0) {
            int j;
            for (j = 0; j < this->maximumSizeValue; j++) {
                if (j >= newSize)
                    break;
                newValue[j] = this->value[j];
            }
            ::operator delete(this->value);
            this->value = newValue;
            this->maximumSizeValue = newSize;
        }
    }
    this->value[this->numberValue] = r;
    this->numberValue++;
    return 1;
}

#endif

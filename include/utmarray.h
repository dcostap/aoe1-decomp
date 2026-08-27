#ifndef UTMARRAY_H
#define UTMARRAY_H

// Reconstructed from the original ManagedArray<int> CodeView type and the
// exact utmarray.h functions at 00408D20, 004147A0, 004DE980, 004DE9D0,
// 004EA750, and 004F1390.

extern "C" void* __cdecl operator_new(unsigned int size);
extern "C" void __cdecl operator_delete(void* ptr);

#ifndef TAIINFMD_PREFIX_CONTEXT
template <class T>
class ManagedArray {
public:
    typedef int (__cdecl* CompareFunction)(T left, T right);

    ManagedArray(int desired_number = 0)
        : value(0),
          numberValue(0),
          desiredNumberValue(0),
          maximumSizeValue(desired_number)
    {
        if (desired_number > 0)
            this->value = new T[desired_number];
    }

    ~ManagedArray()
    {
        if (this->value != 0) {
            delete[] this->value;
            this->value = 0;
        }
        this->numberValue = 0;
        this->desiredNumberValue = 0;
        this->maximumSizeValue = 0;
    }

    T& operator[](int index)
    {
        if (index > this->maximumSizeValue - 1)
            this->resize(index + 1);
        return this->value[index];
    }

    int enlarge(int amount)
    {
        this->desiredNumberValue += amount;
        return this->desiredNumberValue;
    }

    int shrink(int amount)
    {
        this->desiredNumberValue -= amount;
        if (this->desiredNumberValue < 0)
            this->desiredNumberValue = 0;
        return this->desiredNumberValue;
    }

    int contains(const T& item) const;

    int position(T& item)
    {
        int i;
        for (i = 0; i < this->maximumSizeValue; i++) {
            if (this->value[i] == item)
                return i;
        }
        return -1;
    }

    int add(T item);

    int remove(T item)
    {
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

    const int number() const
    {
        return this->numberValue;
    }

    const int desiredNumber() const
    {
        return this->desiredNumberValue;
    }

    void setDesiredNumber(int desired_number)
    {
        this->desiredNumberValue = desired_number;
    }

    void zeroNumber()
    {
        this->numberValue = 0;
    }

    const int maximumSize() const
    {
        return this->maximumSizeValue;
    }

    void sort(CompareFunction compare)
    {
        int i;
        int j;
        T temporary;

        for (i = 0; i < this->numberValue; i++) {
            for (j = i + 1; j < this->numberValue; j++) {
                if (compare(this->value[i], this->value[j]) > 0) {
                    temporary = this->value[i];
                    this->value[i] = this->value[j];
                    this->value[j] = temporary;
                }
            }
        }
    }

protected:
    int resize(int new_size)
    {
        T* new_value = new T[new_size];
        if (new_value == 0)
            return 0;

        int i;
        for (i = 0;
             i < this->maximumSizeValue && i < new_size;
             i++) {
            new_value[i] = this->value[i];
        }

        delete[] this->value;
        this->value = new_value;
        this->maximumSizeValue = new_size;
        return 1;
    }

public:
    T* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;
};
#endif

template <class T>
#ifdef TAIINFMD_PREFIX_CONTEXT
// BINARY NOTE: taiinfmd's FPO record uses the non-const member decoration.
int ManagedArray<T>::contains(const T& item)
#else
int ManagedArray<T>::contains(const T& item) const
#endif
{
    int i;
    T wanted;
    T current;

    for (i = 0; i < this->numberValue; i++) {
        if (i >= this->maximumSizeValue)
            return 0;
        current = this->value[i];
        wanted = item;
        if (current == wanted)
            return 1;
    }
    return 0;
}

template <class T>
int ManagedArray<T>::add(T val)
{
    int i;

    for (i = 0; i < this->numberValue; i++) {
        if (i >= this->maximumSizeValue)
            break;
        if (this->value[i] == val)
            return 0;
    }
    if (this->numberValue > this->maximumSizeValue - 1) {
        int newSize = this->numberValue + 1;
        T* newValue = (T*)operator_new(newSize * sizeof(T));
        if (newValue != 0) {
            int j;
            for (j = 0; j < this->maximumSizeValue; j++) {
                if (j >= newSize)
                    break;
                newValue[j] = this->value[j];
            }
            operator_delete(this->value);
            this->value = newValue;
            this->maximumSizeValue = newSize;
        }
    }
    this->value[this->numberValue] = val;
    this->numberValue++;
    return 1;
}

#endif

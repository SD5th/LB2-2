#include "DynamicArrayAndLinkedList.h"

template <typename T>
class ImmutableArraySequence;

template <typename T>
class Sequence
{
public:
    // декомпозиция
    virtual T GetFirst() = 0;
    virtual T GetLast() = 0;
    virtual T Get(int) = 0;
    virtual int GetSize() = 0;
    virtual Sequence<T> *GetSubsequence(int, int) = 0;

    // операции
    virtual Sequence<T> *Set(int, T) = 0;
    virtual Sequence<T> *Resize(int) = 0;
    virtual Sequence<T> *Insert(int, T) = 0;
    virtual Sequence<T> *Append(T) = 0;
    virtual Sequence<T> *Prepend(T) = 0;
    virtual Sequence<T> *Concat(ImmutableArraySequence<T> &) = 0;
};

template <typename T>
class ImmutableArraySequence : public Sequence<T>
{
public:
    // конструкторы
    ImmutableArraySequence();
    ImmutableArraySequence(int);
    ImmutableArraySequence(T *, int);
    ImmutableArraySequence(const ImmutableArraySequence<T> &);

    // декомпозиция
    T GetFirst() override;
    T GetLast() override;
    T Get(int) override;
    int GetSize() override;
    Sequence<T> *GetSubsequence(int, int) override;

    // операции
    Sequence<T> *Set(int, T) override;
    Sequence<T> *Resize(int) override;
    Sequence<T> *Insert(int, T) override;
    Sequence<T> *Append(T) override;
    Sequence<T> *Prepend(T) override;
    Sequence<T> *Concat(ImmutableArraySequence<T> &) override;

    DynamicArray<T> *array;
};

template <typename T>
ImmutableArraySequence<T>::ImmutableArraySequence() : array(new DynamicArray<T>)
{
}

template <typename T>
ImmutableArraySequence<T>::ImmutableArraySequence(int count) : array(new DynamicArray<T>(count))
{
}

template <typename T>
ImmutableArraySequence<T>::ImmutableArraySequence(T *items, int count) : array(new DynamicArray<T>(items, count))
{
}

template <typename T>
ImmutableArraySequence<T>::ImmutableArraySequence(const ImmutableArraySequence<T> &arraySequence) : array(new DynamicArray<T>(*(arraySequence.array)))
{
}

// декомпозиция

template <typename T>
T ImmutableArraySequence<T>::GetFirst()
{
    return this->array->GetFirst();
}

template <typename T>
T ImmutableArraySequence<T>::GetLast()
{
    return this->array->GetLast();
}

template <typename T>
T ImmutableArraySequence<T>::Get(int index)
{
    return this->array->Get(index);
}

template <typename T>
int ImmutableArraySequence<T>::GetSize()
{
    return this->array->GetSize();
}

template <typename T>
Sequence<T> *ImmutableArraySequence<T>::GetSubsequence(int startIndex, int endIndex)
{
    DynamicArray<T> *subArray = this->array->GetSubsequence(startIndex, endIndex);
    ImmutableArraySequence<T> *output = new ImmutableArraySequence;
    output->array = subArray;
    return output;
}

// операции
template <typename T>
Sequence<T> *ImmutableArraySequence<T>::Set(int index, T value)
{
    ImmutableArraySequence<T> *output = new ImmutableArraySequence(*this);
    output->array->Set(index, value);
    return output;
}

template <typename T>
Sequence<T> *ImmutableArraySequence<T>::Resize(int newSize)
{
    ImmutableArraySequence<T> *output = new ImmutableArraySequence(*this);
    output->array->Resize(newSize);
    return output;
}

template <typename T>
Sequence<T> *ImmutableArraySequence<T>::Insert(int index, T item)
{
    ImmutableArraySequence<T> *output = new ImmutableArraySequence(*this);
    output->array->Insert(index, item);
    return output;
}

template <typename T>
Sequence<T> *ImmutableArraySequence<T>::Append(T item)
{
    ImmutableArraySequence<T> *output = new ImmutableArraySequence(*this);
    output->array->Append(item);
    return output;
}

template <typename T>
Sequence<T> *ImmutableArraySequence<T>::Prepend(T item)
{
    ImmutableArraySequence<T> *output = new ImmutableArraySequence(*this);
    output->array->Prepend(item);
    return output;
}

template <typename T>
Sequence<T> *ImmutableArraySequence<T>::Concat(ImmutableArraySequence<T> &arraySequence)
{
    DynamicArray<T> *concatArray;
    concatArray = this->array->Concat(*(arraySequence.array));
    ImmutableArraySequence<T> *output = new ImmutableArraySequence;
    output->array = concatArray;
    return output;
}
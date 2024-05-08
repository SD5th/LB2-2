#include "Sequence.h"

// Sequence<T>
    template <typename T>
    SequenceType Sequence<T>::GetSequenceType()
    {
        return SequenceType::Seq;
    }

// ArraySequence<T>::
    // конструкторы
        template <typename T>
        ArraySequence<T>::ArraySequence() : 
            array(new DynamicArray<T>)
        { }

        template <typename T>
        ArraySequence<T>::ArraySequence(int count) : 
            array(new DynamicArray<T>(count))
        { }

        template <typename T>
        ArraySequence<T>::ArraySequence(T* items, int count) : 
            array(new DynamicArray<T>(items, count))
        { }

        template <typename T>
        ArraySequence<T>::ArraySequence(const ArraySequence<T>& arraySequence) : 
            array(new DynamicArray<T>(*(arraySequence.array)))
        { }

        template <typename T>
        ArraySequence<T>::ArraySequence(const ListSequence<T>& listSequence) : 
            array(LinkedListToDynamicArray(*(listSequence.list)))
        { }

    // декомпозиция
        template <typename T>
        SequenceType ArraySequence<T>::GetSequenceType()
        {
            return SequenceType::Array;
        }

        template <typename T>
        T ArraySequence<T>::GetFirst()
        {
            return this->array->GetFirst();
        }

        template <typename T>
        T ArraySequence<T>::GetLast()
        {
            return this->array->GetLast();
        }

        template <typename T>
        T ArraySequence<T>::Get(int index)
        {
            return this->array->Get(index);
        }

        template <typename T>
        int ArraySequence<T>::GetSize()
        {
            return this->array->GetSize();
        }

        template <typename T>
        Sequence<T> *ArraySequence<T>::GetSubsequence(int startIndex, int endIndex)
        {
            DynamicArray<T> *subArray = this->array->GetSubsequence(startIndex, endIndex);
            ArraySequence<T> *output = new ArraySequence();
            output->array = subArray;
            return output;
        }

    // операции
        template <typename T>
        void ArraySequence<T>::Set(int index, T value)
        {
            this->array->Set(index, value);
        }

        template <typename T>
        void ArraySequence<T>::Resize(int newSize)
        {
            this->array->Resize(newSize);
        }

        template <typename T>
        void ArraySequence<T>::Insert(int index, T item)
        {
            this->array->Insert(index, item);
        }

        template <typename T>
        void ArraySequence<T>::Append(T item)
        {
            this->array->Append(item);
        }

        template <typename T>
        void ArraySequence<T>::Prepend(T item)
        {
            this->array->Prepend(item);
        }

        template <typename T>
        Sequence<T>* ArraySequence<T>::Concat(ArraySequence<T> &arraySequence)
        {
            DynamicArray<T> *concatArray;
            concatArray = this->array->Concat(*(arraySequence.array));
            ArraySequence<T> *output = new ArraySequence;
            output->array = concatArray;
            return output;
        }

        template <typename T>
        Sequence<T>* ArraySequence<T>::Concat(ListSequence<T> &listSequence)
        {
            DynamicArray<T> *listToArray = LinkedListToDynamicArray(*(listSequence.list));
            DynamicArray<T> *concatArray;
            concatArray = this->array->Concat(*(listToArray));
            delete listToArray;
            ArraySequence<T> *output = new ArraySequence;
            output->array = concatArray;
            return output;
        }

// ListSequence<T>::
    // конструкторы
        template <typename T>
        ListSequence<T>::ListSequence() : 
            list(new LinkedList<T>())
        { }
        
        template <typename T>
        ListSequence<T>::ListSequence(int count) : 
            list(new LinkedList<T>(count))
        { }
        
        template <typename T>
        ListSequence<T>::ListSequence(T *items, int count) : 
            list(new LinkedList<T>(items, count))
        { }

        template <typename T>
        ListSequence<T>::ListSequence(const ArraySequence<T> &arraySequence) : 
            list(DynamicArrayToLinkedList(*(arraySequence.array)))
        { }

        template <typename T>
        ListSequence<T>::ListSequence(const ListSequence<T> &listSequence) : 
            list(new LinkedList<T>(*(listSequence.list)))
        { }
    // декомпозиция
        template <typename T>
        SequenceType ListSequence<T>::GetSequenceType()
        {
            return SequenceType::List;
        }
        
        template <typename T>
        T ListSequence<T>::GetFirst()
        {
            return this->list->GetFirst();
        }
        
        template <typename T>
        T ListSequence<T>::GetLast()
        {
            return this->list->GetLast();
        }
        
        template <typename T>
        T ListSequence<T>::Get(int index)
        {
            return this->list->Get(index);
        }
        
        template <typename T>
        int ListSequence<T>::GetSize()
        {
            return this->list->GetSize();
        }
        
        template <typename T>
        Sequence<T> *ListSequence<T>::GetSubsequence(int startIndex, int endIndex)
        {
            LinkedList<T> *subArray = this->list->GetSubsequence(startIndex, endIndex);
            ListSequence<T> *output = new ListSequence();
            output->list = subArray;
            return output;
        }
        
    // операции
        template <typename T>
        void ListSequence<T>::Set(int index, T value)
        {
            this->list->Set(index, value);
        }
        
        template <typename T>
        void ListSequence<T>::Resize(int newSize)
        {
            this->list->Resize(newSize);
        }
        
        template <typename T>
        void ListSequence<T>::Insert(int index, T item)
        {
            this->list->Insert(index, item);
        }
        
        template <typename T>
        void ListSequence<T>::Append(T item)
        {
            this->list->Append(item);
        }
        
        template <typename T>
        void ListSequence<T>::Prepend(T item)
        {
            this->list->Prepend(item);
        }

        template <typename T>
        Sequence<T> *ListSequence<T>::Concat(ArraySequence<T> &arraySequence)
        {
            LinkedList<T> *arrayToList = DynamicArrayToLinkedList(*(arraySequence.array));
            LinkedList<T> *concatList;
            concatList = this->list->Concat(*(arrayToList));
            delete arrayToList;
            ListSequence<T> *output = new ListSequence;
            output->list = concatList;
            return output;
        }

        template <typename T>
        Sequence<T> *ListSequence<T>::Concat(ListSequence<T> &listSequence)
        {
            LinkedList<T> *concatList;
            concatList = this->list->Concat(*(listSequence.list));
            ListSequence<T> *output = new ListSequence;
            output->list = concatList;
            return output;
        }
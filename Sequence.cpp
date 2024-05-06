#include <iostream>
#include "DynamicArray&LinkedList.h"

enum SequenceType
{
    Seq,
    Array,
    List
};

template <class T> class Sequence
{
    public:
        virtual SequenceType GetSequenceType()
        {
            return SequenceType::Seq;
        }
        
        // декомпозиция
        virtual T               GetFirst() = 0;
        virtual T               GetLast() = 0;
        virtual T               Get(int index) = 0;
        virtual int             GetSize() = 0;
        virtual Sequence<T>*    GetSubsequence(int startIndex, int endIndex) = 0;
        
        // операции
        virtual void            Set(int index, T value) = 0;
        virtual void            Resize(int newSize) = 0;
        virtual void            Insert(int index, T item) = 0;
        virtual void            Append(T item) = 0;
        virtual void            Prepend(T item) = 0;
        virtual Sequence<T>*    Concat(Sequence<T> & sequence) = 0;
};

template <class T> class ArraySequence : public Sequence<T>
{
    public:
        SequenceType GetSequenceType() override
        {
            return SequenceType::Array;
        }
        
        ArraySequence() : 
            array(DynamicArray<T>()) 
        { }

        ArraySequence(int count) : 
            array(DynamicArray<T>(count))
        { }

        ArraySequence(T* items, int count) : 
            array(DynamicArray<T>(items, count))
        { }

        ArraySequence(const Sequence<T> & sequence) : 
            array(DynamicArray<T>())  
        {
            if (sequence->GetSequenceType() == SequenceType::Array)
                this->array = new DynamicArray<T>(sequence.array);
            else if (sequence->GetSequenceType() == SequenceType::List)
                this->array = LinkedListToDynamicArray(sequence.list);
        }

        T GetFirst() override
        {
            return this->array->GetFirst();
        }

        T GetLast() override
        {
            return this->array->GetLast();
        }

        T Get(int index) override
        {
            return this->array->Get(index);
        }

        int GetSize() override
        {
            return this->array->GetSize();
        }

        Sequence<T>* GetSubsequence(int startIndex, int endIndex)
        {
            DynamicArray<T>* subArray = this->array.GetSubsequence(startIndex, endIndex);
            ArraySequence<T>* output = new ArraySequence();
            output->array = subArray;
            return output;
        }
    
        void Set(int index, T value) override
        {
            this->array->Set(index, value);
        }

        void Resize(int newSize) override
        {
            this->array->Resize(newSize);
        }

        void Insert(int index, T item) override
        {
            this->array->Insert(index, item);
        }

        void Append(T item) override
        {
            this->array->Append(item);
        }

        void Prepend(T item) override
        {
            this->array->Prepend(item);
        }

        Sequence<T>* Concat(Sequence<T> & sequence)
        {
            DynamicArray<T>* concatArray;
            if (sequence.GetSequenceType() == SequenceType::Array)
            {
                concatArray = this->array->Concat(*(sequence->array));
            }
            else if (sequence.GetSequenceType() == SequenceType::List)
            {
                DynamicArray<T>* listToArray = LinkedListToDynamicArray (*(sequence.list));
                concatArray = this->array->Concat(*(listToArray));
                delete listToArray;
            }
            ArraySequence<T>* output = new ArraySequence;
            output->array = concatArray; 
        }

    private:
        DynamicArray<T>* array;
};

template <class T> class ListSequence : public Sequence<T>
{
    public:
        SequenceType GetSequenceType() override
        {
            return SequenceType::List;
        }
        
        ListSequence() : 
            list(LinkedList<T>()) 
        { }

        ListSequence(int count) : 
            list(LinkedList<T>(count))
        { }

        ListSequence(T* items, int count) : 
            list(LinkedList<T>(items, count))
        { }

        ListSequence(const Sequence<T> & sequence) : 
            list(LinkedList<T>())  
        {
            if (sequence->GetSequenceType() == SequenceType::Array)
                this->list = DynamicArrayToLinkedList(*(sequence.array));
            else if (sequence->GetSequenceType() == SequenceType::List)
                this->list = new LinkedList<T>(*(sequence.list));
        }

        T GetFirst() override
        {
            return this->list->GetFirst();
        }

        T GetLast() override
        {
            return this->list->GetLast();
        }

        T Get(int index) override
        {
            return this->list->Get(index);
        }

        int GetSize() override
        {
            return this->list->GetSize();
        }

        Sequence<T>* GetSubsequence(int startIndex, int endIndex)
        {
            LinkedList<T>* subArray = this->list.GetSubsequence(startIndex, endIndex);
            ListSequence<T>* output = new ListSequence();
            output->list = subArray;
            return output;
        }
    
        void Set(int index, T value) override
        {
            this->list->Set(index, value);
        }

        void Resize(int newSize) override
        {
            this->list->Resize(newSize);
        }

        void Insert(int index, T item) override
        {
            this->list->Insert(index, item);
        }

        void Append(T item) override
        {
            this->list->Append(item);
        }

        void Prepend(T item) override
        {
            this->list->Prepend(item);
        }

        Sequence<T>* Concat(Sequence<T> & sequence)
        {
            LinkedList<T>* concatList;
            if (sequence.GetSequenceType() == SequenceType::Array)
            {
                LinkedList<T>* arrayToList = DynamicArrayToLinkedList (*(sequence.array));
                concatList = this->list->Concat(*(arrayToList));
                delete arrayToList;
            }
            else if (sequence.GetSequenceType() == SequenceType::List)
            {
                concatList = this->list->Concat(*(sequence->list));
            }
            ListSequence<T>* output = new LinkedList<T>;
            output->list = concatList; 
        }

    private:
        LinkedList<T>* list;
};


int main ()
{
    std::cout << "11";
}
#include "DynamicArrayAndLinkedList.h"
enum SequenceType
{
    Seq,
    Array,
    List
};

template <typename T> class ArraySequence;
template <typename T> class ListSequence;

template <typename T> class Sequence
{
    public:
        // декомпозиция
        virtual SequenceType    GetSequenceType();
        virtual T               GetFirst()                  = 0;
        virtual T               GetLast()                   = 0;
        virtual T               Get(int)                    = 0;
        virtual int             GetSize()                   = 0;
        virtual Sequence<T>*    GetSubsequence(int, int)    = 0;
        
        // операции
        virtual void            Set(int, T)                 = 0;
        virtual void            Resize(int)                 = 0;
        virtual void            Insert(int, T)              = 0;
        virtual void            Append(T)                   = 0;
        virtual void            Prepend(T)                  = 0;
        virtual Sequence<T>*    Concat(ArraySequence<T> &)  = 0;
        virtual Sequence<T>*    Concat(ListSequence<T> &)   = 0;
};

template <typename T> class ArraySequence : public Sequence<T>
{
    public:
        // конструкторы
        ArraySequence();
        ArraySequence(int);
        ArraySequence(T*, int);
        ArraySequence(const ArraySequence<T> &);
        ArraySequence(const ListSequence<T> &);

        // декомпозиция
        SequenceType    GetSequenceType()           override;
        T               GetFirst()                  override;
        T               GetLast()                   override;
        T               Get(int)                    override;
        int             GetSize()                   override;
        Sequence<T>*    GetSubsequence(int, int)    override;

        // операции 
        void            Set(int, T)                 override;
        void            Resize(int)                 override;
        void            Insert(int, T)              override;
        void            Append(T)                   override;
        void            Prepend(T)                  override;
        Sequence<T>*    Concat(ArraySequence<T> &)  override;
        Sequence<T>*    Concat(ListSequence<T> &)   override;
        
        DynamicArray<T>* array;
};

template <typename T> class ListSequence : public Sequence<T>
{
    public:
        //конструкторы
        ListSequence();
        ListSequence(int);
        ListSequence(T*, int);
        ListSequence(const ArraySequence<T> &);
        ListSequence(const ListSequence<T> &);
        
        // декомпозиция
        SequenceType    GetSequenceType()           override;
        T               GetFirst()                  override;
        T               GetLast()                   override;
        T               Get(int)                    override;
        int             GetSize()                   override;
        Sequence<T>*    GetSubsequence(int, int)    override;

        // операции 
        void            Set(int, T)                 override;
        void            Resize(int)                 override;
        void            Insert(int, T)              override;
        void            Append(T)                   override;
        void            Prepend(T)                  override;
        Sequence<T>*    Concat(ArraySequence<T> &)  override;
        Sequence<T>*    Concat(ListSequence<T> &)   override;

        LinkedList<T>*  list;
};
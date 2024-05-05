#include <iostream>

class IndexOutOfRange : public std::exception
{
    public:
        IndexOutOfRange(const char* msg) : std::exception(){
            this->msg = msg;
        }
        const char* what() const noexcept override{
            return msg;
        }
    private:
        const char* msg;
};

template <class T> class DynamicArray

{
    private:
        T* data;            // Элементы (ссылка на первый)
        int size;           // Количество элементов
        int capacity;       // Количество зарезервированных ячеек памяти
    
    public:
    //конструкторы

        DynamicArray(int count) :   size(count), 
                                    capacity(count*2), 
                                    data(new T [count*2]) 
        { }

        DynamicArray(T* items, int count) : size(count), 
                                            capacity(count*2), 
                                            data(new T [count*2])
        { 
            for (int i = 0; i < count; i++)
                *(data + i) = *(items + i);
        }

        DynamicArray(const DynamicArray & dynamicArray) :   size(dynamicArray.size), 
                                                            capacity(dynamicArray.capacity), 
                                                            data(new T [dynamicArray.capacity])
        {
            for (int i = 0; i < this->size; i++)
                *(this->data + i) = *(dynamicArray.data + i);
        }

        DynamicArray(): size(0), 
                        capacity(0), 
                        data(nullptr)            
        { }
        
    //деструктор

        ~DynamicArray()
        {
            delete[] data; 
        }
        
    //декомпозиция

        T GetFirst()        //Получить первый элемент
        {
            return *(this->data);
        }

        T GetLast()         //Получить последний элемент
        {
            return *(this->data+GetSize()-1);
        }

        T* GetData()
        {
            return this->data;
        }

        T Get(int index)    //Получить элемент по индексу
        {
            if (index < 0) 
                throw IndexOutOfRange("Function 'Get': Negative index.");
            if (index >= this->size) 
                throw IndexOutOfRange("Function 'Get': Index is greater than size.");
            return *(this->data + index);
        }

        DynamicArray<T>* GetSubsequence(int startIndex, int endIndex)
        {
            if (startIndex < 0)
                throw IndexOutOfRange("Function 'GetSubsequence': Negative startIndex.");
            if (startIndex > endIndex)
                throw IndexOutOfRange("Function 'GetSubsequence': startIndex is greater than endIndex.");
            if (endIndex >= this->GetSize())
                throw IndexOutOfRange("Function 'GetSubsequence': endIndex is equal or greater than size.");
            
            DynamicArray<T>* output = new DynamicArray<T>(endIndex - startIndex + 1);
            for (int i = startIndex; i <= endIndex; i++)
            {
                (*output).Set(i - startIndex, this->Get(i));
            }
            return output;
        }

        int GetSize()       //Получить size 
        {
            return this->size;
        }

        int GetCapacity()   //Получить capacity
        {
            return this->capacity;
        }

    //операции

        void Set(int index, T value)    //Присвоить значение по индексу
        {
            if (index < 0) 
                throw IndexOutOfRange("Function 'Set': Negative index.");
            if (index >= this->size) 
                throw IndexOutOfRange("Function 'Set': Index is greater than size.");
            *(this->data + index) = value;
        }

        void Resize(int newSize)        
        {
            if ((this->capacity >= newSize) && (newSize >= this->capacity/4))
            {
                this->size = newSize;
            }
            else
            {
                T* data_temp = new T [newSize * 2];
                for (int i = 0; i < std::min(this->size, newSize); i++)
                {
                    *(data_temp + i) = *(this->data + i);
                }
                delete[] this->data;
                this->size = newSize;
                this->capacity = newSize*2;
                this->data = data_temp;
            }
        }

        void Insert(int index, T item)
        {
            if (index < 0) 
                throw IndexOutOfRange("Function 'InsertAt': Negative index.");
            if (index > this->size) 
                throw IndexOutOfRange("Function 'InsertAt': Index is greater than size.");
            if (this->capacity > this->size)
            {
                T temp;
                this->size += 1;
                for (int i = this->size - 1; i > index; i -= 1)
                {
                    *(data + i) = *(data + i - 1);
                }
                *(data + index) = item;
            }
            else
            {
                this->size += 1;
                T* data_temp = new T [this->size * 2];
                for (int i = 0; i < index; i++)
                {
                    *(data_temp + i) = *(this->data + i);
                }
                *(data_temp + index) = item;
                for (int i = index + 1; i < this->size; i++)
                {
                    *(data_temp + i) = *(this->data + i - 1);
                }
            }   
        }

        void Append(T item)
        {
            this->Insert(this->size, item);
        }

        void Prepend(T item)
        {
            this->Insert(0, item);
        }

        DynamicArray<T>* Concat(DynamicArray<T> & array)
        {
            DynamicArray<T> * output = new DynamicArray<T>(*this);
            (*output).Resize(this->GetSize() + array.GetSize());
            for (int i = this->GetSize(); i < output->GetSize(); i++)
            {
                (*output).Set(i, array.Get(i-this->GetSize()));
            }
            return output; 
        }
    
    //вспомогательное
        void printall()
        {
            std::cout << "Size: " << this->GetSize();
            std::cout << "\nCapacity: " << this->GetCapacity() << " (" << this->GetCapacity() * sizeof(T) << " bytes)";
            std::cout << "\nData: \n";
            for (int i = 0; i < this->size; i++)
                std::cout << this->Get(i) << ' ';
            std::cout << "\n";
        }
};

template <class T> class LinkedList
{
    private:
        struct Node
        {
            T item;
            Node* next;
            Node(T value)
            {
                this->item = value;
                this->next = nullptr;
            }
            Node()
            {
                this->next = nullptr;
            }
        };
        
        Node* head;           
        Node* tail;            
    public:
    //конструкторы
        LinkedList(T* items, int count) :   head(nullptr),
                                            tail(nullptr)

        {
            if (count < 0)
                throw IndexOutOfRange("Constructor(items, count): Negative count.");
            else
                for (int i = 0; i < count; i++)
                    this->Append(*(items+i));
        }

        LinkedList (const LinkedList <T> & list) :  head(nullptr),
                                                    tail(nullptr)
        {   
            Node* current_list = list.head;

            while (current_list != nullptr)
            {
                this->Append(current_list->item);
                current_list = current_list->next;
            }
        }

        LinkedList() :  head(nullptr),
                        tail(nullptr)
        { }

    //деконструктор
        ~LinkedList()
        {
            Node* current = this->head;
            Node* next;
            while (current != nullptr)
            {
                next = current->next;
                delete current;
                current = next;
            }
        }

    //декомпозиция
        
        T GetFirst()
        {
            if (this->head == nullptr)
                throw IndexOutOfRange("Function 'GetFirst': List is empty.");
            return this->head->item;
        }

        T GetLast()
        {
            if (this->head == nullptr)
                throw IndexOutOfRange("Function 'GetLast': List is empty.");
            return this->tail->item;
        }

        T Get(int index)
        {

            if (index < 0)
                throw IndexOutOfRange("Function 'Get': Negative index.");
            if (index >= this->GetSize())
                throw IndexOutOfRange("Function 'Get': Index is greater than size.");
            Node* current = this->head;
            for (int i = 0; i < index; i++)
            {
                current = current->next;
            }
            return current->item;    
        }

        int GetSize()     
        {
            if (this->head == nullptr)
                return 0;
            int size = 1;
            Node* current = this->head;
            while (current != this->tail)
            {
                current = current->next;
                size++;
            }
            return size;
        }

        void Append(T item)
        {
            Node* last = new Node(item);
            if (this-> head == nullptr)
                this->head = last;
            else
                this->tail->next = last;
            this->tail = last;
        }

        void Prepend(T item)
        {
            Node* first = new Node(item);
            if (this-> head == nullptr)
                this->tail = first;
            else
                first->next = this->head;
            this->head = first;
        }

        void Set(int index, T value)
        {
            if (index < 0)
                throw IndexOutOfRange("Function 'Set': Negative index.");
            if (this->GetSize() <= index)
                throw IndexOutOfRange("Function 'Set': Index is greater than size.");

            Node* current = this->head;
            for (int i = 0; i < index; i++)
            {
                current = (*current).next;
            }
            (*current).item = value;    
        }

        void Insert(int index, T value)
        {
            if (index < 0)
                throw IndexOutOfRange("Function 'Insert': Negative index.");
            int size = this->GetSize();
            if (index > size)
                throw IndexOutOfRange("Function 'Insert': Index is greater than size.");
            if (index == 0){
                this->Prepend(value);
                return;
            }
            if (index == size){
                this->Append(value);
                return;
            }
            Node* prev = this->head;
            Node* next = prev->next;
            for (int i = 1; i < index; i++)
            {
                prev = next;
                next = next->next;
            }
            Node* insertion = new Node(value);
            insertion->next = next;
            prev->next = insertion;
        }

        LinkedList<T> * GetSubsequence(int startIndex, int endIndex)
        {
            if (startIndex < 0)
                throw IndexOutOfRange("Function 'GetSubsequence': Negative startIndex.");
            if (startIndex > endIndex)
                throw IndexOutOfRange("Function 'GetSubsequence': startIndex is greater than endIndex.");
            if (endIndex >= this->GetSize())
                throw IndexOutOfRange("Function 'GetSubsequence': endIndex is equal or greater than size.");
            LinkedList<T>* output = new LinkedList;
            Node* start = this->head;
            for (int i = 0; i < startIndex; i++)
                start = start->next;
            Node* end = start;
            for (int i = startIndex; i < endIndex; i++)
                end = end->next;
            while (start != end)
            {
                output->Append(start->item);
                start = start->next;
            }
            output->Append(start->item);
            return output;  
        }

        LinkedList<T> * Concat (const LinkedList<T> & list)
        {
            LinkedList<T>* output = new LinkedList(*this);
            Node* current;
            for (current = list.head; current != list.tail; current = current->next)
                output->Append(current->item);
            output->Append(current->item);
            return output;  
        }

        void printall()
        {
            std::cout << "Size: " << this->GetSize();
            std::cout << "\nData: \n";
            for (int i = 0; i < this->GetSize(); i++)
                std::cout << this->Get(i) << ' ';
            std::cout << "\n";
        }
};


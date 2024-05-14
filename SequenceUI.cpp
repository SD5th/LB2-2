#include "C:\Main\Kodiki\C++\SimpleConsoleUI\SimpleConsoleUI.h"
#include "Sequence.cpp"
#include "SequenceTests.cpp"

ArraySequence<Sequence<int>*> Sequences;
ArraySequence<string> SequenceNames;

Shell* Head = new Shell("Head Window", Head_Function, new Connector);
void Head_Function()
{
    cout << "Hello! This is User Interface for Sequence.h\n"
         << "In this realization all Sequences contains integer numbers.\n";
    Head->Set_Function(nullptr);
}

void CreateSequence_Function()
{
    cout << "Let's create sequence.\n"
         << "Input 'Array', 'List' or 'Break'.\n";
    string typeOfSequence;
    getline(cin, typeOfSequence);
    while(typeOfSequence != "Array" && typeOfSequence != "List" && typeOfSequence != "Break")
    {
        cout << "Wrong! Input 'Array', 'List' or 'Break'.\n";
        getline(cin, typeOfSequence);
    }
    if (typeOfSequence == "Break")
        return;
    if (typeOfSequence == "Array")
    {
        cout << "Input name of new ArraySequence\n";
        string name;
        getline(cin, name);
        while (name.size() == 0)
            getline(cin, name);
        SequenceNames.Append(name);
        Sequences.Append(new ArraySequence<int>);
    }
    else
    {
        cout << "Input name of new ListSequence\n";
        string name;
        getline(cin, name);
        while (name.size() == 0)
            getline(cin, name);
        SequenceNames.Append(name);
        Sequences.Append(new ListSequence<int>);
    }
    if (Sequences.GetSize() == 1)
    {
        Head->Get_Connector()->Append_Shell(SequenceOperations);
        Head->Get_Connector()->Append_Shell(ListOfSequences);
    }    

}

void ListOfSequences_Function()
{
    cout << "List of all Sequences:\n";
    for (int i = 0; i < Sequences.GetSize(); i++)
    {
        cout << i+1 << ") Name: " << SequenceNames.Get(i) << "\n";
        if (Sequences.Get(i)->GetSequenceType() == SequenceType::Array)
            cout << "Type: Array\n";
        else if (Sequences.Get(i)->GetSequenceType() == SequenceType::List)
            cout << "Type: List\n";
        cout << "Size: " << Sequences.Get(i)->GetSize() << "\n";
        cout << "Data:\n";
        for (int j = 0; j < Sequences.Get(i)->GetSize(); j++)
            cout << Sequences.Get(i)->Get(j) << ' ';
        cout << "\n\n";
    }
}
Shell* ListOfSequences = new Shell("List of Sequences", ListOfSequences_Function, new Connector);


Shell* SequenceOperations = new Shell("Sequence Operations", nullptr, new Connector);

void SetOperation_Function()
{
    cout << "Choose Sequence to Set.\n";
    cout << "From 1 to " << Sequences.GetSize();
    int number, index, item;
    cin >> number;
    cout << "Input index to Set.\n";
    cin >> index;
    cout << "Input item to Set.\n";
    cin >> item;
    Sequences.Get(number)->Set(index, item);
    cout << "Ready!\n";
}
Shell* SetOperation_Function = new Shell("Operation Set", SetOperation_Function, new Connector);

void ResizeOperation_Function()
{
    cout << "Choose Sequence to Resize.\n";
    cout << "From 1 to " << Sequences.GetSize();
    int number, newSize;
    cin >> number;
    cout << "Input new size.\n";
    cin >> newSize;
    Sequences.Get(number)->Resize(newSize);
    cout << "Ready!\n";
}
Shell* SetOperation_Function = new Shell("Operation Resize", ResizeOperation_Function, new Connector);

void InsertOperation_Function()
{
    cout << "Choose Sequence to Insert.\n";
    cout << "From 1 to " << Sequences.GetSize();
    int number, index, item;
    cin >> number;
    cout << "Input index to Set.\n";
    cin >> index;
    cout << "Input item to Set.\n";
    cin >> item;
    Sequences.Get(number)->Insert(index, item);
    cout << "Ready!\n";
}
Shell* SetOperation_Function = new Shell("Operation Insert", InsertOperation_Function, new Connector);

void AppendOperation_Function()
{
    cout << "Choose Sequence to Append.\n";
    cout << "From 1 to " << Sequences.GetSize();
    int number, item;
    cin >> number;
    cout << "Input item to Append.\n";
    cin >> item;
    Sequences.Get(number)->Append(item);
    cout << "Ready!\n";
}
Shell* SetOperation_Function = new Shell("Operation Append", AppendOperation_Function, new Connector);

void ConcatOperation_Function()
{
    cout << "Choose first Sequence to Concat.\n";
    cout << "From 1 to " << Sequences.GetSize();
    int number1, number2;
    cin >> number1;
    cout << "Choose second Sequence to Concat.\n";
    cin >> number2;

    ArraySequence<int> seq(*(Sequences.Get(number2)));
    

    if (Sequences.Get(number2)->GetSequenceType() == Array)
        Sequences.Append(Sequences.Get(number1)->Concat(seq));
    cout << "Ready!\n";
}
Shell* SetOperation_Function = new Shell("Operation Append", AppendOperation_Function, new Connector);


//        virtual Sequence<T>*    Concat(ArraySequence<T> &)  = 0;



Shell* Exit = new Shell("Exit Window", Exit_Function, new Connector);
void Exit_Function()
{
    cout << "Confirm exit from the program. Type EXIT\n";
    string UserText; 
    getline(cin, UserText);
    if (UserText == "EXIT")
    {
        cout << "So sad.. Bye!\n"; 
        exit(1);
    }
    else 
    {
        cout << "Then let's stay together!\n";
    }
}



int main()
{
    // Head->Get_Connector()->Append_Shell();
    // Head->Get_Connector()->Append_Shell();
}
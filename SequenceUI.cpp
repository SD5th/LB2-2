#include "C:\Main\Kodiki\C++\SimpleConsoleUI\SimpleConsoleUI.h"
#include "Sequence.h"
#include "SequenceTests.cpp"
#include "DynamicArrayTests.cpp"
#include "LinkedListTests.cpp"


ArraySequence<Sequence<int>*> Sequences;
ArraySequence<string> SequenceNames;

Shell* Head;
Shell* CreateSequence;
Shell* ListOfSequences;
Shell* SequenceOperations;
Shell* SetOperation;
Shell* ResizeOperation;
Shell* InsertOperation;
Shell* AppendOperation;
Shell* PrependOperation;
Shell* Test;
Shell* Exit;


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
        Head->Get_Connector()->Insert_Shell(ListOfSequences, 1);
        Head->Get_Connector()->Insert_Shell(SequenceOperations, 2);
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

//   SequenceOperations = nullptr

void SetOperation_Function()
{
    cout << "Choose Sequence to Set.\n";
    cout << "From 1 to " << Sequences.GetSize() << "\n";
    int number, index, item;
    cin >> number;
    cout << "Input index to Set.\n";
    cin >> index;
    cout << "Input item to Set.\n";
    cin >> item;
    Sequences.Get(number-1)->Set(index, item);
    cout << "Ready!\n";
}

void ResizeOperation_Function()
{
    cout << "Choose Sequence to Resize.\n";
    cout << "From 1 to " << Sequences.GetSize() << "\n";
    int number, newSize;
    cin >> number;
    cout << "Input new size.\n";
    cin >> newSize;
    Sequences.Get(number-1)->Resize(newSize);
    cout << "Ready!\n";
}

void InsertOperation_Function()
{
    cout << "Choose Sequence to Insert.\n";
    cout << "From 1 to " << Sequences.GetSize() << "\n";
    int number, index, item;
    cin >> number;
    cout << "Input index to Set.\n";
    cin >> index;
    cout << "Input item to Set.\n";
    cin >> item;
    Sequences.Get(number-1)->Insert(index, item);
    cout << "Ready!\n";
}

void AppendOperation_Function()
{
    cout << "Choose Sequence to Append.\n";
    cout << "From 1 to " << Sequences.GetSize() << "\n";
    int number, item;
    cin >> number;
    cout << "Input item to Append.\n";
    cin >> item;
    Sequences.Get(number-1)->Append(item);
    cout << "Ready!\n";
}

void PrependOperation_Function()
{
    cout << "Choose Sequence to Prepend.\n";
    cout << "From 1 to " << Sequences.GetSize() << "\n";
    int number, item;
    cin >> number;
    cout << "Input item to Prepend.\n";
    cin >> item;
    Sequences.Get(number-1)->Prepend(item);
    cout << "Ready!\n";
}
 
void Test_Function()
{
    ALLTESTS_DYNAMIC_ARRAY();
    ALLTESTS_LINKED_LIST();
    ALLTESTS_SEQUENCE();
}

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
    Head =               new Shell("Head Window",         Head_Function, new Connector);
    CreateSequence =     new Shell("Create Sequence",     CreateSequence_Function, new Connector);
    ListOfSequences =    new Shell("List of Sequences",   ListOfSequences_Function, new Connector);
    SequenceOperations = new Shell("Sequence Operations", nullptr, new Connector);
    SetOperation =       new Shell("Set",                 SetOperation_Function, new Connector);
    ResizeOperation =    new Shell("Resize",              ResizeOperation_Function, new Connector);
    InsertOperation =    new Shell("Insert",              InsertOperation_Function, new Connector);
    AppendOperation =    new Shell("Append",              AppendOperation_Function, new Connector);
    PrependOperation =   new Shell("Prepend",             PrependOperation_Function, new Connector);
    Test =               new Shell("Test",                Test_Function, new Connector);
    Exit =               new Shell("Exit",                Exit_Function, new Connector);

    Head->Get_Connector()->Append_Shell(CreateSequence);
    Head->Get_Connector()->Append_Shell(Test);
    Head->Get_Connector()->Append_Shell(Exit);
    
    CreateSequence->Get_Connector()->Append_Shell(Head);

    ListOfSequences->Get_Connector()->Append_Shell(Head);

    SequenceOperations->Get_Connector()->Append_Shell(SetOperation);
    SequenceOperations->Get_Connector()->Append_Shell(ResizeOperation);
    SequenceOperations->Get_Connector()->Append_Shell(InsertOperation);
    SequenceOperations->Get_Connector()->Append_Shell(AppendOperation);
    SequenceOperations->Get_Connector()->Append_Shell(PrependOperation);
    SequenceOperations->Get_Connector()->Append_Shell(Head);

    SetOperation->Get_Connector()->Append_Shell(SetOperation);
    SetOperation->Get_Connector()->Append_Shell(Head);

    ResizeOperation->Get_Connector()->Append_Shell(Head);

    InsertOperation->Get_Connector()->Append_Shell(InsertOperation);
    InsertOperation->Get_Connector()->Append_Shell(Head);

    AppendOperation->Get_Connector()->Append_Shell(AppendOperation);
    AppendOperation->Get_Connector()->Append_Shell(Head);
    
    PrependOperation->Get_Connector()->Append_Shell(PrependOperation);
    PrependOperation->Get_Connector()->Append_Shell(Head);
    
    Test->Get_Connector()->Append_Shell(Head);

    Exit->Get_Connector()->Append_Shell(Head);

    ActiveShell Active(Head);
    Active.StartUI();
}
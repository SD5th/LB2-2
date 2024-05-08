#include <iostream>
#include "Sequence.cpp"

using namespace std;

enum GeneralDialogueOption
{
    CreateObject,
    OperationWithObject,
    Help,
    Exit,
    Unknown
};

//enum 

GeneralDialogueOption UserTextToDialogueOption(const string & UserText)
{
    if (UserText == "Help")
        return Help;
    if (UserText == "Exit")
        return Exit;
    return Unknown;
}

int main(){
    setlocale(LC_ALL, "");
    cout << "Введите 'Help', чтобы увидеть список доступных команд.\n";
    bool UI = true;
    string UserText;
    while(UI)
    {
        getline(cin, UserText);

        switch(UserTextToDialogueOption(UserText)){
            
            
            case Help:
                cout << "Help!!!\n";
                break;
            case Exit:
                UI = false;
                break;
            default:
                cout << "Неизвестная команда! Введите 'Help', чтобы увидеть список доступных команд.\n";
        }
    }
}
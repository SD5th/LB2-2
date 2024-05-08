#include <iostream>
#include "Sequence.h"
#include <vector>
using namespace std;

enum GeneralDialogueOption
{
    CreateObject,
    OperationWithObject,
    Help,
    Exit,
    UnknownDialogueOption
}; 

GeneralDialogueOption UserTextToDialogueOption(const string & UserText)
{
    if (UserText == "Help")
        return Help;
    if (UserText == "Exit")
        return Exit;
    return UnknownDialogueOption;
}

int main(){
    setlocale(LC_ALL, "");
    ArraySequence<Sequence<int>*> ass;
    //ArraySequence<Sequence<int>> ArrayOfSequences;
    string UserText;
    
    cout << "───▄▀▀▀▄▄▄▄▄▄▄▀▀▀▄───                                      \n"
         << "───█▒▒░░░░░░░░░▒▒█───      Приветствую всех пользователей  \n"
         << "────█░░█░░░░░█░░█────    прикольной оболочки АТД 'Sequence'\n"
         << "─▄▄──█░░░▀█▀░░░█──▄▄─       Если не знаешь, что сделать,   \n"
         << "█░░█─▀▄░░░░░░░▄▀─█░░█                пиши  help            \n"
         << "█░░█──█░░░░░░░█──█░░█                                      \n";
         

    while(bool UI = true == true)
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
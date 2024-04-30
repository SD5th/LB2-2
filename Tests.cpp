#include "classes.cpp"
//#include <iostream>

using namespace std;


int main()
{
    
    setlocale(LC_ALL, "");
    int A[10] = { 11, 22, 33, 44, 55, 66, 77, 88, 99, 1010 };
    LinkedList<int> arr;
    arr.printall();
    arr.Set(2, 999);
    arr.printall();
    cout << arr.GetFirst() << endl << arr.GetLast();
}

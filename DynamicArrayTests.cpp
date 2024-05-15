#include <iostream>
#include <cassert>
#include "DynamicArrayAndLinkedList.h"

void testDefaultConstructor()
{
    DynamicArray<int> arr;
    assert(arr.GetSize() == 0);
    assert(arr.GetCapacity() == 0);
    assert(arr.GetData() == nullptr);
    std::cout << "testDefaultConstructor: OK\n";
}

void testCountConstructor()
{
    DynamicArray<double> arr(5);
    assert(arr.GetSize() == 5);
    assert(arr.GetCapacity() == 10); 
    std::cout << "testCountConstructor: OK\n";
}

void testCountConstructorFromPointer() {
  int data[] = {1, 2, 3, 4, 5};
  int size = 5;

  DynamicArray<int> arr(data, size);

  assert(arr.GetSize() == size);
  for (int i = 0; i < size; ++i) {
    assert(arr.Get(i) == data[i]);
  }
  
  assert(arr.GetData() != data);

  std::cout << "testCountConstructorFromPointer: OK\n";
}

void testCopyConstructor()
{
    DynamicArray<int> arr1(10);
    for (int i = 0; i < 10; ++i)
    {
        arr1.Set(i, i + 1);
    }

    DynamicArray arr2(arr1);
    assert(arr2.GetSize() == arr1.GetSize());
    assert(arr2.GetCapacity() == arr1.GetCapacity());

    for (int i = 0; i < 10; ++i)
    {
        assert(arr2.Get(i) == arr1.Get(i));
        assert(arr2.GetData() != arr1.GetData()); 
    }
    std::cout << "testCopyConstructor: OK\n";
}

void testGetFirst()
{
    DynamicArray<std::string> arr(2);
    arr.Set(0, "Hello");
    assert(arr.GetFirst() == "Hello");
    std::cout << "testGetFirst: OK\n";
}

void testGetLast()
{
    DynamicArray<char> arr(3);
    arr.Set(0, 'A');
    arr.Set(2, 'C');
    assert(arr.GetLast() == 'C');
    std::cout << "testGetLast: OK\n";
}

void testGetSize()
{
    DynamicArray<int> arr(7);
    assert(arr.GetSize() == 7);
    std::cout << "testGetSize: OK\n";
}

void testGetCapacity()
{
    DynamicArray<float> arr(4);
    assert(arr.GetCapacity() == 8); 
    std::cout << "testGetCapacity: OK\n";
}

void testSetValidIndex()
{
    DynamicArray<int> arr(5);
    arr.Set(2, 10);
    assert(arr.Get(2) == 10);
    std::cout << "testSetValidIndex: OK\n";
}

void testSetNegativeIndex_ThrowsException()
{
    DynamicArray<double> arr(3);
    try
    {
        arr.Set(-1, 3.14);
        assert(false); 
    }
    catch (const IndexOutOfRange &excep)
    {
        assert(std::string(excep.what()) == "Function 'Set': Negative index.");
    }
    std::cout << "testSetNegativeIndex_ThrowsException: OK\n";
}

void testSetOutOfSizeIndex_ThrowsException()
{
    DynamicArray<char> arr(2);
    try
    {
        arr.Set(3, 'X');
        assert(false); 
    }
    catch (const IndexOutOfRange &excep)
    {
        assert(std::string(excep.what()) == "Function 'Set': Index is greater than size.");
    }
    std::cout << "testSetOutOfSizeIndex_ThrowsException: OK\n";
}

void testAppend()
{
    DynamicArray<int> arr(4);
    arr.Append(1);
    arr.Append(2);
    arr.Append(3);

    assert(arr.GetSize() == 7);
    assert(arr.Get(4) == 1);
    assert(arr.Get(5) == 2);
    assert(arr.Get(6) == 3);
    std::cout << "testAppend: OK\n";
}

void testPrepend()
{
    DynamicArray<char> arr(3);
    arr.Prepend('A');
    arr.Prepend('B');
    arr.Prepend('C');

    assert(arr.GetSize() == 6);
    assert(arr.Get(0) == 'C');
    assert(arr.Get(1) == 'B');
    assert(arr.Get(2) == 'A');
    std::cout << "testPrepend: OK\n";
}

void testConcat()
{
    DynamicArray<int> arr1(3);
    arr1.Set(0, 1);
    arr1.Set(1, 2);
    arr1.Set(2, 3);

    DynamicArray<int> arr2(2);
    arr2.Set(0, 4);
    arr2.Set(1, 5);

    DynamicArray<int> *result = arr1.Concat(arr2);
    assert(result->GetSize() == 5);
    assert(result->Get(0) == 1);
    assert(result->Get(1) == 2);
    assert(result->Get(2) == 3);
    assert(result->Get(3) == 4);
    assert(result->Get(4) == 5);

    delete result;
    std::cout << "testConcat: OK\n";
}

void testGetSubsequence()
{
    DynamicArray<int> arr(5);
    for (int i = 0; i < 5; ++i)
    {
        arr.Set(i, i + 1);
    }

    DynamicArray<int> *sub = arr.GetSubsequence(1, 3);
    assert(sub->GetSize() == 3);
    assert(sub->Get(0) == 2);
    assert(sub->Get(1) == 3);
    assert(sub->Get(2) == 4);

    delete sub; 
    std::cout << "testGetSubsequence: OK\n";
}

void testGetSubsequence_ThrowsException_NegativeStartIndex()
{
    DynamicArray<int> arr(4);
    try
    {
        arr.GetSubsequence(-1, 2);
        assert(false); 
    }
    catch (const IndexOutOfRange &excep)
    {
        assert(std::string(excep.what()) == "Function 'GetSubsequence': Negative startIndex.");
    }
    std::cout << "testGetSubsequence_ThrowsException_NegativeStartIndex: OK\n";
}

void testGetSubsequence_ThrowsException_StartIndexGreaterThanEndIndex()
{
    DynamicArray<int> arr(5);
    try
    {
        arr.GetSubsequence(3, 2);
        assert(false); 
    }
    catch (const IndexOutOfRange &excep)
    {
        assert(std::string(excep.what()) == "Function 'GetSubsequence': startIndex is greater than endIndex.");
    }
    std::cout << "testGetSubsequence_ThrowsException_StartIndexGreaterThanEndIndex: OK\n";
}

void testGetSubsequence_ThrowsException_EndIndexOutOfSize()
{
    DynamicArray<int> arr(3);
    try
    {
        arr.GetSubsequence(1, 4);
        assert(false);           
    }
    catch (const IndexOutOfRange &excep)
    {
        assert(std::string(excep.what()) == "Function 'GetSubsequence': endIndex is equal or greater than size.");
    }
    std::cout << "testGetSubsequence_ThrowsException_EndIndexOutOfSize: OK\n";
}

void ALLTESTS_DYNAMIC_ARRAY()
{
    std::cout << "\nTESTS DYNAMIC ARRAY:\n\n";

    testDefaultConstructor();
    testCountConstructor();
    testCountConstructorFromPointer();
    testCopyConstructor();
    testGetFirst();
    testGetLast();
    testGetSize();
    testGetCapacity();
    testSetValidIndex();
    testSetNegativeIndex_ThrowsException();
    testSetOutOfSizeIndex_ThrowsException();
    testAppend();
    testPrepend();
    testConcat();
    testGetSubsequence();
    testGetSubsequence_ThrowsException_NegativeStartIndex();
    testGetSubsequence_ThrowsException_StartIndexGreaterThanEndIndex();
    testGetSubsequence_ThrowsException_EndIndexOutOfSize();
}
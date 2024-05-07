#include <iostream>
#include <cassert>
#include "DynamicArray&LinkedList.h"

void testConstructors()
{
    LinkedList<int> list1;
    assert(list1.GetSize() == 0);

    int data[] = {1, 2, 3};
    int size = 3;
    LinkedList<int> list2(data, size);
    assert(list2.GetSize() == size);
    assert(list2.Get(0) == 1);
    assert(list2.Get(1) == 2);
    assert(list2.Get(2) == 3);

    LinkedList<int> list4(list2);
    assert(list4.GetSize() == list2.GetSize());
    assert(list4.Get(0) == list2.Get(0));
    assert(list4.Get(1) == list2.Get(1));
    assert(list4.Get(2) == list2.Get(2));

    std::cout << "testConstructors: OK\n";
}

void testGetFirst_EmptyList()
{
    LinkedList<int> list;
    try
    {
        list.GetFirst();
        assert(false); // This shouldn't be reached
    }
    catch (const IndexOutOfRange &excep)
    {
        assert(std::string(excep.what()) == "Function 'Get': List is empty.");
    }

    std::cout << "testGetFirst_EmptyList: OK\n";
}

void testGetLast_EmptyList()
{
    LinkedList<int> list;
    try
    {
        list.GetLast();
        assert(false); // This shouldn't be reached
    }
    catch (const IndexOutOfRange &excep)
    {
        assert(std::string(excep.what()) == "Function 'Get': List is empty.");
    }

    std::cout << "testGetLast_EmptyList: OK\n";
}

void testGet_NegativeIndex()
{
    LinkedList<int> list;
    list.Append(1);
    try
    {
        list.Get(-1);
        assert(false); // This shouldn't be reached
    }
    catch (const IndexOutOfRange &excep)
    {
        assert(std::string(excep.what()) == "Function 'Get': Negative index.");
    }

    std::cout << "testGet_NegativeIndex: OK\n";
}

void testGet_OutOfBoundsIndex()
{
    LinkedList<int> list;
    list.Append(1);
    try
    {
        list.Get(2);   // Index out of bounds
        assert(false); // This shouldn't be reached
    }
    catch (const IndexOutOfRange &excep)
    {
        assert(std::string(excep.what()) == "Function 'Get': Index is greater than size.");
    }

    std::cout << "testGet_OutOfBoundsIndex: OK\n";
}

void testGet_ValidIndex()
{
    LinkedList<int> list;
    list.Append(1);
    list.Append(2);
    assert(list.Get(0) == 1);
    std::cout << "testGet_ValidIndex: OK\n";
}

void testGetSize_EmptyList()
{
    LinkedList<int> list;
    assert(list.GetSize() == 0);

    std::cout << "testGetSize_EmptyList: OK\n";
}

void testGetSize_NonEmptyList()
{
    LinkedList<int> list;
    list.Append(1);
    list.Append(2);
    list.Append(3);
    assert(list.GetSize() == 3);

    std::cout << "testGetSize_NonEmptyList: OK\n";
}

void testAppend_EmptyList()
{
    LinkedList<int> list;
    list.Append(1);
    assert(list.GetSize() == 1);
    assert(list.Get(0) == 1);

    std::cout << "testAppend_EmptyList: OK\n";
}

void testAppend_NonEmptyList()
{
    LinkedList<int> list;
    list.Append(1);
    list.Append(2);
    list.Append(3);
    assert(list.GetSize() == 3);
    assert(list.Get(0) == 1);
    assert(list.Get(1) == 2);
    assert(list.Get(2) == 3);

    std::cout << "testAppend_NonEmptyList: OK\n";
}

void testPrepend_EmptyList()
{
    LinkedList<int> list;
    list.Prepend(1);
    assert(list.GetSize() == 1);
    assert(list.Get(0) == 1);

    std::cout << "testPrepend_EmptyList: OK\n";
}

void testPrepend_NonEmptyList()
{
    LinkedList<int> list;
    list.Append(2);
    list.Append(3);
    list.Prepend(1);
    assert(list.GetSize() == 3);
    assert(list.Get(0) == 1);
    assert(list.Get(1) == 2);
    assert(list.Get(2) == 3);

    std::cout << "testPrepend_NonEmptyList: OK\n";
}

void testSet_NegativeIndex()
{
    LinkedList<int> list;
    list.Append(1);
    try
    {
        list.Set(-1, 2); // Negative index
        assert(false);   // This shouldn't be reached
    }
    catch (const IndexOutOfRange &excep)
    {
        assert(std::string(excep.what()) == "Function 'Set': Negative index.");
    }

    std::cout << "testSet_NegativeIndex: OK\n";
}

void testSet_OutOfBoundsIndex()
{
    LinkedList<int> list;
    list.Append(1);
    try
    {
        list.Set(2, 2); // Index out of bounds
        assert(false);  // This shouldn't be reached
    }
    catch (const IndexOutOfRange &excep)
    {
        assert(std::string(excep.what()) == "Function 'Set': Index is greater than size.");
    }

    std::cout << "testSet_OutOfBoundsIndex: OK\n";
}

void testInsert_NegativeIndex()
{
    LinkedList<int> list;
    list.Append(1);
    try
    {
        list.Insert(-1, 2); // Negative index
        assert(false);      // This shouldn't be reached
    }
    catch (const IndexOutOfRange &excep)
    {
        assert(std::string(excep.what()) == "Function 'Insert': Negative index.");
    }

    std::cout << "testInsert_NegativeIndex: OK\n";
}

void testInsert_OutOfBoundsIndex()
{
    LinkedList<int> list;
    list.Append(1);
    try
    {
        list.Insert(3, 2); // Index out of bounds
        assert(false);     // This shouldn't be reached
    }
    catch (const IndexOutOfRange &excep)
    {
        assert(std::string(excep.what()) == "Function 'Insert': Index is greater than size.");
    }

    std::cout << "testInsert_OutOfBoundsIndex: OK\n";
}

void testInsert_ValidIndex()
{
    LinkedList<int> list;
    list.Append(1);
    list.Append(3);
    list.Insert(1, 2);
    assert(list.GetSize() == 3);
    assert(list.Get(0) == 1);
    assert(list.Get(1) == 2);
    assert(list.Get(2) == 3);

    std::cout << "testInsert_AtMiddle: OK\n";
}

void testGetSubsequence_NegativeStartIndex()
{
    LinkedList<int> list;
    list.Append(1);
    try
    {
        list.GetSubsequence(-1, 0);
        assert(false); // This shouldn't be reached
    }
    catch (const IndexOutOfRange &excep)
    {
        assert(std::string(excep.what()) == "Function 'GetSubsequence': Negative startIndex.");
    }

    std::cout << "testGetSubsequence_NegativeStartIndex: OK\n";
}

void testGetSubsequence_StartIndexGreaterThanEndIndex()
{
    LinkedList<int> list;
    list.Append(1);
    try
    {
        list.GetSubsequence(1, 0);
        assert(false); // This shouldn't be reached
    }
    catch (const IndexOutOfRange &excep)
    {
        assert(std::string(excep.what()) == "Function 'GetSubsequence': startIndex is greater than endIndex.");
    }

    std::cout << "testGetSubsequence_StartIndexGreaterThanEndIndex: OK\n";
}

void testGetSubsequence_EndIndexGreaterThanSize()
{
    LinkedList<int> list;
    list.Append(1);
    try
    {
        list.GetSubsequence(0, 2); // EndIndex out of bounds
        assert(false);             // This shouldn't be reached
    }
    catch (const IndexOutOfRange &excep)
    {
        assert(std::string(excep.what()) == "Function 'GetSubsequence': endIndex is equal or greater than size.");
    }

    std::cout << "testGetSubsequence_EndIndexGreaterThanSize: OK\n";
}

void testGetSubsequence_PartOfList()
{
    LinkedList<int> list;
    list.Append(1);
    list.Append(2);
    list.Append(3);
    list.Append(4);
    LinkedList<int> *subsequence = list.GetSubsequence(1, 3);
    assert(subsequence->GetSize() == 3);
    assert(subsequence->Get(0) == 2);
    assert(subsequence->Get(1) == 3);
    assert(subsequence->Get(2) == 4);
    delete subsequence;

    std::cout << "testGetSubsequence_PartOfList: OK\n";
}

void testConcat_NonEmptyLists()
{
    LinkedList<int> list1;
    list1.Append(1);
    list1.Append(2);
    LinkedList<int> list2;
    list2.Append(3);
    list2.Append(4);
    LinkedList<int> *result = list1.Concat(list2);
    assert(result->GetSize() == 4);
    assert(result->Get(0) == 1);
    assert(result->Get(1) == 2);
    assert(result->Get(2) == 3);
    assert(result->Get(3) == 4);
    delete result;

    std::cout << "testConcat_NonEmptyLists: OK\n";
}

void testResize_FromEmpty()
{
    LinkedList<int> list;
    list.Resize(3);
    assert(list.GetSize() == 3);
    
    std::cout << "testResize_FromEmpty: OK\n";
}

void testResize_ToEmpty()
{
    LinkedList<int> list(3);
    
    list.Resize(0);
    assert(list.GetSize() == 0);
    
    std::cout << "testResize_ToEmpty: OK\n";
}

void testResize_Increase()
{
    LinkedList<int> list(3);
    
    list.Resize(5);
    assert(list.GetSize() == 5);
    
    std::cout << "testResize_Increase: OK\n";
}

void testResize_Decrease()
{
    LinkedList<int> list(5);
    
    list.Resize(3);
    assert(list.GetSize() == 3);
    
    std::cout << "testResize_Decrease: OK\n";
}

int main()
{
    testConstructors();
    testGetFirst_EmptyList();
    testGetLast_EmptyList();
    testGet_NegativeIndex();
    testGet_OutOfBoundsIndex();
    testGet_ValidIndex();
    testGetSize_EmptyList();
    testGetSize_NonEmptyList();
    testGetSize_EmptyList();
    testGetSize_NonEmptyList();
    testAppend_EmptyList();
    testAppend_NonEmptyList();
    testPrepend_EmptyList();
    testPrepend_NonEmptyList();
    testSet_NegativeIndex();
    testSet_OutOfBoundsIndex();
    testInsert_NegativeIndex();
    testInsert_OutOfBoundsIndex();
    testInsert_ValidIndex();
    testGetSubsequence_NegativeStartIndex();
    testGetSubsequence_StartIndexGreaterThanEndIndex();
    testGetSubsequence_EndIndexGreaterThanSize();
    testGetSubsequence_PartOfList();
    testConcat_NonEmptyLists();
    testResize_FromEmpty();
    testResize_ToEmpty();
    testResize_Increase();
    testResize_Decrease();
}
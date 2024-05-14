#include <iostream>
#include <cassert>
#include "Sequence.cpp"

void Test_DefaultConstructor_ArraySequence()
{
    ArraySequence<int> sequence;
    assert(sequence.GetSize() == 0);

    std::cout << "TestDefaultConstructor_ArraySequence: OK\n";
}

void Test_SizeConstructor_ArraySequence()
{
    ArraySequence<int> sequence(5);
    assert(sequence.GetSize() == 5);

    std::cout << "TestSizeConstructor_ArraySequence: OK\n";
}

void Test_CountConstructorFromPointer_ArraySequence()
{
    int data[] = {1, 2, 3, 4, 5};
    int size = 5;
    ArraySequence<int> sequence(data, size);

    assert(sequence.GetSize() == 5);
    assert(sequence.Get(0) == 1);
    assert(sequence.Get(1) == 2);
    assert(sequence.Get(2) == 3);
    assert(sequence.Get(3) == 4);
    assert(sequence.Get(4) == 5);
    std::cout << "TestCountConstructorFromPointer_ArraySequence: OK\n";
}

void Test_CopyConstructor_FromArraySequence_ArraySequence()
{
    ArraySequence<int> sequence1(3);
    sequence1.Set(0, 1);
    sequence1.Set(1, 2);
    sequence1.Set(2, 3);

    ArraySequence<int> sequence2(sequence1);
    assert(sequence2.GetSize() == 3);
    assert(sequence2.Get(0) == 1);
    assert(sequence2.Get(1) == 2);
    assert(sequence2.Get(2) == 3);

    sequence1.Set(1, 5);
    assert(sequence2.Get(1) == 2);

    std::cout << "TestCopyConstructorFromArraySequence_ArraySequence: OK\n";
}

void Test_CopyConstructor_FromListSequence_ArraySequence()
{
    ListSequence<int> sequence1(3);
    sequence1.Set(0, 1);
    sequence1.Set(1, 2);
    sequence1.Set(2, 3);

    ArraySequence<int> sequence2(sequence1);
    assert(sequence2.GetSize() == 3);
    assert(sequence2.Get(0) == 1);
    assert(sequence2.Get(1) == 2);
    assert(sequence2.Get(2) == 3);

    sequence1.Set(1, 5);
    assert(sequence2.Get(1) == 2);

    std::cout << "TestCopyConstructorFromListSequence_ArraySequence: OK\n";
}

void Test_Get_SequenceType_ArraySequence()
{
    ArraySequence<int> sequence;
    assert(sequence.GetSequenceType() == SequenceType::Array);

    std::cout << "TestGetSequenceType_ArraySequence: OK\n";
}

void Test_Get_FirstEmpty_ArraySequence()
{
    ArraySequence<int> sequence;

    try
    {
        sequence.GetFirst();
        assert(false);
    }
    catch (const IndexOutOfRange &excep)
    {
        assert(std::string(excep.what()) == "Function 'Get': List is empty.");
    }

    std::cout << "TestGetFirstEmpty_ArraySequence: OK\n";
}

void Test_Get_FirstNonEmpty_ArraySequence()
{
    ArraySequence<int> sequence(1);
    sequence.Set(0, 10);

    assert(sequence.GetFirst() == 10);

    std::cout << "TestGetFirstNonEmpty_ArraySequence: OK\n";
}

void Test_Get_LastEmpty_ArraySequence()
{
    ArraySequence<int> sequence;

    try
    {
        sequence.GetLast();
        assert(false); // Ожидается исключение IndexOutOfRange
    }
    catch (const IndexOutOfRange &excep)
    {
        assert(std::string(excep.what()) == "Function 'Get': List is empty.");
    }

    std::cout << "TestGetLastEmpty_ArraySequence: OK\n";
}

void Test_Get_ValidIndex_ArraySequence()
{
    ArraySequence<int> sequence(3);
    sequence.Set(0, 1);
    sequence.Set(1, 2);
    sequence.Set(2, 3);

    assert(sequence.Get(0) == 1);
    assert(sequence.Get(1) == 2);
    assert(sequence.Get(2) == 3);

    std::cout << "TestGet_ValidIndex_ArraySequence: OK\n";
}

void Test_Get_InvalidIndex_ArraySequence()
{
    ArraySequence<int> sequence(2);
    sequence.Set(0, 1);
    sequence.Set(1, 2);

    try
    {
        sequence.Get(-1);
        assert(false); // Ожидается исключение IndexOutOfRange
    }
    catch (const IndexOutOfRange &excep)
    {
        assert(std::string(excep.what()) == "Function 'Get': Negative index.");
    }

    try
    {
        sequence.Get(2);
        assert(false); // Ожидается исключение IndexOutOfRange
    }
    catch (const IndexOutOfRange &excep)
    {
        assert(std::string(excep.what()) == "Function 'Get': Index is greater than size.");
    }
    std::cout << "TestGet_InvalidIndex_ArraySequence: OK\n";
}

void Test_Insert_AtBeginning_ArraySequence()
{
    ArraySequence<int> sequence(3);
    sequence.Set(0, 1);
    sequence.Set(1, 2);
    sequence.Set(2, 3);

    assert(sequence.GetSize() == 3);

    sequence.Insert(0, 0);
    assert(sequence.GetSize() == 4);
    assert(sequence.Get(0) == 0);
    assert(sequence.Get(1) == 1);
    assert(sequence.Get(2) == 2);
    assert(sequence.Get(3) == 3);

    std::cout << "TestInsert_AtBeginning_ArraySequence: OK\n";
}

void Test_Insert_AtMiddle_ArraySequence()
{
    ArraySequence<int> sequence(3);
    sequence.Set(0, 0);
    sequence.Set(1, 2);
    sequence.Set(2, 3);

    assert(sequence.GetSize() == 3);

    sequence.Insert(1, 1);
    assert(sequence.GetSize() == 4);
    assert(sequence.Get(0) == 0);
    assert(sequence.Get(1) == 1);
    assert(sequence.Get(2) == 2);
    assert(sequence.Get(3) == 3);

    std::cout << "TestInsert_AtMiddle_ArraySequence: OK\n";
}

void Test_Insert_AtEnd_ArraySequence()
{
    ArraySequence<int> sequence(3);
    sequence.Set(0, 1);
    sequence.Set(1, 2);
    sequence.Set(2, 3);

    assert(sequence.GetSize() == 3);

    sequence.Insert(3, 4);
    assert(sequence.GetSize() == 4);
    assert(sequence.Get(0) == 1);
    assert(sequence.Get(1) == 2);
    assert(sequence.Get(2) == 3);
    assert(sequence.Get(3) == 4);

    std::cout << "TestInsert_AtEnd_ArraySequence: OK\n";
}

void Test_Append_ArraySequence()
{
    ArraySequence<int> sequence1(2);
    sequence1.Set(0, 1);
    sequence1.Set(1, 2);

    sequence1.Append(3);
    assert(sequence1.GetSize() == 3);
    assert(sequence1.Get(0) == 1);
    assert(sequence1.Get(1) == 2);
    assert(sequence1.Get(2) == 3);

    std::cout << "TestAppend_ArraySequence: OK\n";
}

void Test_Append_Empty_ArraySequence()
{
    ArraySequence<int> sequence1;
    sequence1.Append(10);

    assert(sequence1.GetSize() == 1);
    assert(sequence1.Get(0) == 10);

    std::cout << "TestAppend_EmptyArraySequence: OK\n";
}

void Test_Prepend_ArraySequence()
{
    ArraySequence<int> sequence1(2);
    sequence1.Set(0, 1);
    sequence1.Set(1, 2);

    sequence1.Prepend(0);
    assert(sequence1.GetSize() == 3);
    assert(sequence1.Get(0) == 0);
    assert(sequence1.Get(1) == 1);
    assert(sequence1.Get(2) == 2);

    std::cout << "TestPrepend_ArraySequence: OK\n";
}

void Test_Prepend_Empty_ArraySequence()
{
    ArraySequence<int> sequence1;
    sequence1.Prepend(10);

    assert(sequence1.GetSize() == 1);
    assert(sequence1.Get(0) == 10);

    std::cout << "TestPrepend_EmptyArraySequence: OK\n";
}

void Test_Concat_FromArraySequence_ArraySequence()
{
    ArraySequence<int> sequence1(2);
    sequence1.Set(0, 1);
    sequence1.Set(1, 2);

    ArraySequence<int> sequence2(3);
    sequence2.Set(0, 3);
    sequence2.Set(1, 4);
    sequence2.Set(2, 5);

    Sequence<int> *result = sequence1.Concat(sequence2);
    assert(result->GetSize() == 5);
    assert(result->Get(0) == 1);
    assert(result->Get(1) == 2);
    assert(result->Get(2) == 3);
    assert(result->Get(3) == 4);
    assert(result->Get(4) == 5);

    std::cout << "TestConcatFromArraySequence_ArraySequence: OK\n";
}

void Test_Concat_FromListSequence_ArraySequence()
{
    ListSequence<int> sequence1(2);
    sequence1.Set(0, 1);
    sequence1.Set(1, 2);

    ArraySequence<int> sequence2(3);
    sequence2.Set(0, 3);
    sequence2.Set(1, 4);
    sequence2.Set(2, 5);

    Sequence<int> *result = sequence1.Concat(sequence2);
    assert(result->GetSize() == 5);
    assert(result->Get(0) == 1);
    assert(result->Get(1) == 2);
    assert(result->Get(2) == 3);
    assert(result->Get(3) == 4);
    assert(result->Get(4) == 5);

    std::cout << "TestConcatFromListSequence_ArraySequence: OK\n";
}

void Test_Concat_Empty_FromArraySequence_ArraySequence()
{
    ArraySequence<int> sequence1;
    ArraySequence<int> sequence2(3);
    sequence2.Set(0, 1);
    sequence2.Set(1, 2);
    sequence2.Set(2, 3);

    Sequence<int> *result = sequence1.Concat(sequence2);
    assert(result->GetSize() == 3);
    assert(result->Get(0) == 1);
    assert(result->Get(1) == 2);
    assert(result->Get(2) == 3);

    std::cout << "TestConcatEmptyFromArraySequence_ArraySequence: OK\n";
}

void Test_Concat_Empty_FromListSequence_ArraySequence()
{
    ArraySequence<int> sequence1;
    ListSequence<int> sequence2(3);
    sequence2.Set(0, 1);
    sequence2.Set(1, 2);
    sequence2.Set(2, 3);

    Sequence<int> *result = sequence1.Concat(sequence2);
    assert(result->GetSize() == 3);
    assert(result->Get(0) == 1);
    assert(result->Get(1) == 2);
    assert(result->Get(2) == 3);

    std::cout << "TestConcatEmptyFromListSequence_ArraySequence: OK\n";
}

void Test_Concat_EmptyToNonEmpty_FromArraySequence_ArraySequence()
{
    ArraySequence<int> sequence1(2);
    sequence1.Set(0, 1);
    sequence1.Set(1, 2);

    ArraySequence<int> sequence2;

    Sequence<int> *result = sequence1.Concat(sequence2);
    assert(result->GetSize() == 2);
    assert(result->Get(0) == 1);
    assert(result->Get(1) == 2);

    std::cout << "TestConcatEmptyToNonEmptyFromArraySequence_ArraySequence: OK\n";
}

void Test_Concat_EmptyToNonEmpty_FromListSequence_ArraySequence()
{
    ArraySequence<int> sequence1(2);
    sequence1.Set(0, 1);
    sequence1.Set(1, 2);

    ListSequence<int> sequence2;

    Sequence<int> *result = sequence1.Concat(sequence2);
    assert(result->GetSize() == 2);
    assert(result->Get(0) == 1);
    assert(result->Get(1) == 2);

    std::cout << "TestConcatEmptyToNonEmptyFromListSequence_ArraySequence: OK\n";
}

///////////////

void TestGetSequenceType_ListSequence()
{
    ListSequence<int> list;
    assert(list.GetSequenceType() == SequenceType::List);

    std::cout << "TestGetSequenceType_ListSequence: OK\n";
}

void TestGetters_EmptyList_ListSequence()
{
    ListSequence<int> list;
    assert(list.GetSize() == 0);
    try
    {
        list.GetFirst();
        assert(false); // Ожидается исключение IndexOutOfRange
    }
    catch (const IndexOutOfRange &excep)
    {
        assert(std::string(excep.what()) == "Function 'Get': List is empty.");
    }
    try
    {
        list.GetLast();
        assert(false); // Ожидается исключение IndexOutOfRange
    }
    catch (const IndexOutOfRange &excep)
    {
        assert(std::string(excep.what()) == "Function 'Get': List is empty.");
    }

    std::cout << "TestGetters_EmptyList_ListSequence: OK\n";
}

void TestGetters_WithElements_ListSequence()
{
    ListSequence<int> list;
    list.Append(1);
    list.Append(2);
    list.Append(3);

    assert(list.GetSize() == 3);
    assert(list.GetFirst() == 1);
    assert(list.GetLast() == 3);
    assert(list.Get(0) == 1);
    assert(list.Get(1) == 2);
    assert(list.Get(2) == 3);

    std::cout << "TestGetters_WithElements_ListSequence: OK\n";
}

void TestSet_ListSequence()
{
    ListSequence<int> list(3);
    list.Set(0, 1);
    list.Set(1, 2);
    list.Set(2, 3);

    assert(list.Get(0) == 1);
    assert(list.Get(1) == 2);
    assert(list.Get(2) == 3);
    std::cout << "TestSet_ListSequence: OK\n";
}

void TestResize_Smaller_ListSequence()
{
    ListSequence<int> list;
    list.Append(1);
    list.Append(2);
    list.Append(3);

    list.Resize(2);
    assert(list.GetSize() == 2);
    assert(list.Get(0) == 1);
    assert(list.Get(1) == 2); // Третий элемент должен быть удален

    std::cout << "TestResize_Smaller_ListSequence: OK\n";
}

void TestResize_Larger_ListSequence()
{
    ListSequence<int> list;
    list.Append(1);

    list.Resize(5);
    assert(list.GetSize() == 5);
    assert(list.Get(0) == 1);
    // Элементы с индексами 1, 2, 3 должны быть пустыми (nullptr)

    std::cout << "TestResize_Larger_ListSequence: OK\n";
}

void TestGetSubsequence_InvalidIndices_ListSequence()
{
    ListSequence<int> list;
    list.Append(1);
    list.Append(2);
    list.Append(3);

    // Некорректные индексы
    try
    {
        Sequence<int> *subsequence1 = list.GetSubsequence(-1, 0);
        assert(false); // Ожидается исключение IndexOutOfRange
    }
    catch (const IndexOutOfRange &excep)
    {
        assert(std::string(excep.what()) == "Function 'GetSubsequence': Negative startIndex.");
    }

    try
    {
        Sequence<int> *subsequence2 = list.GetSubsequence(3, 2);
        assert(false); // Ожидается исключение IndexOutOfRange
    }
    catch (const IndexOutOfRange &excep)
    {
        assert(std::string(excep.what()) == "Function 'GetSubsequence': startIndex is greater than endIndex.");
    }

    try
    {
        Sequence<int> *subsequence3 = list.GetSubsequence(1, 3);
        assert(false); // Ожидается исключение IndexOutOfRange
    }
    catch (const IndexOutOfRange &excep)
    {
        assert(std::string(excep.what()) == "Function 'GetSubsequence': endIndex is equal or greater than size.");
    }

    std::cout << "TestGetSubsequence_InvalidIndices_ListSequence: OK\n";
}

void TestGetSubsequence_FullList_ListSequence()
{
    ListSequence<int> list;
    list.Append(1);
    list.Append(2);
    list.Append(3);

    Sequence<int> *subsequence = list.GetSubsequence(0, 2);
    assert(subsequence->GetSize() == 3);
    assert(subsequence->Get(0) == 1);
    assert(subsequence->Get(1) == 2);
    assert(subsequence->Get(2) == 3);

    std::cout << "TestGetSubsequence_FullList_ListSequence: OK\n";
}

void TestGetSubsequence_PartList_ListSequence()
{
    ListSequence<int> list;
    list.Append(1);
    list.Append(2);
    list.Append(3);

    Sequence<int> *subsequence = list.GetSubsequence(1, 1);
    assert(subsequence->GetSize() == 1);
    assert(subsequence->Get(0) == 2);

    std::cout << "TestGetSubsequence_PartList_ListSequence: OK\n";
}

void TestDefaultConstructor_ListSequence()
{
    ListSequence<int> list;
    assert(list.GetSize() == 0);

    std::cout << "TestDefaultConstructor_ListSequence: OK\n";
}

void TestConstructor_WithSize_ListSequence()
{
    ListSequence<int> sequence(5);
    assert(sequence.GetSize() == 5);

    std::cout << "TestConstructor_WithSize_ListSequence: OK\n";
}

void TestConstructor_WithArray_ListSequence()
{
    int arr[] = {1, 2, 3, 4, 5};
    ListSequence<int> sequence(arr, 5);
    assert(sequence.GetSize() == 5);
    for (int i = 0; i < 5; ++i)
    {
        assert(sequence.Get(i) == arr[i]);
    }

    std::cout << "TestConstructor_WithArray_ListSequence: OK\n";
}

void TestCopyConstructor_ListSequence()
{
    ListSequence<int> listSequence;
    listSequence.Append(1);
    listSequence.Append(2);
    listSequence.Append(3);

    ArraySequence<int> arraySequence;
    arraySequence.Append(1);
    arraySequence.Append(2);
    arraySequence.Append(3);

    ListSequence<int> sequence1(listSequence);
    ListSequence<int> sequence2(arraySequence);

    assert(sequence1.GetSize() == 3);
    assert(sequence2.GetSize() == 3);
    assert(sequence1.Get(0) == 1);
    assert(sequence2.Get(0) == 1);
    assert(sequence1.Get(1) == 2);
    assert(sequence2.Get(1) == 2);
    assert(sequence1.Get(2) == 3);
    assert(sequence2.Get(2) == 3);

    std::cout << "TestCopyConstructor_ListSequence: OK\n";
}

void TestConcat_ListSequence()
{
    ListSequence<int> original;
    original.Append(1);
    original.Append(2);
    original.Append(3);

    ListSequence<int> listSequence;
    listSequence.Append(4);
    listSequence.Append(5);
    listSequence.Append(6);

    ArraySequence<int> arraySequence;
    arraySequence.Append(4);
    arraySequence.Append(5);
    arraySequence.Append(6);

    Sequence<int> *sequence1 = original.Concat(listSequence);
    Sequence<int> *sequence2 = original.Concat(arraySequence);

    assert(sequence1->GetSize() == 6);
    assert(sequence2->GetSize() == 6);
    for (int i = 0; i < 6; i++)
    {
        assert(sequence1->Get(i) == i + 1);
        assert(sequence2->Get(i) == i + 1);
    }

    std::cout << "TestConcat_ListSequence: OK\n";
}

void ALLTESTS_SEQUENCE()
{
    std::cout << "Tests ArraySequence\n\n";
    Test_DefaultConstructor_ArraySequence();
    Test_SizeConstructor_ArraySequence();
    Test_CountConstructorFromPointer_ArraySequence();
    Test_CopyConstructor_FromArraySequence_ArraySequence();
    Test_CopyConstructor_FromListSequence_ArraySequence();
    Test_Get_SequenceType_ArraySequence();
    Test_Get_FirstEmpty_ArraySequence();
    Test_Get_FirstNonEmpty_ArraySequence();
    Test_Get_LastEmpty_ArraySequence();
    Test_Get_ValidIndex_ArraySequence();
    Test_Get_InvalidIndex_ArraySequence();
    Test_Insert_AtBeginning_ArraySequence();
    Test_Insert_AtMiddle_ArraySequence();
    Test_Insert_AtEnd_ArraySequence();
    Test_Append_ArraySequence();
    Test_Append_Empty_ArraySequence();
    Test_Prepend_ArraySequence();
    Test_Prepend_Empty_ArraySequence();
    Test_Concat_FromArraySequence_ArraySequence();
    Test_Concat_FromListSequence_ArraySequence();
    Test_Concat_Empty_FromArraySequence_ArraySequence();
    Test_Concat_Empty_FromListSequence_ArraySequence();
    Test_Concat_EmptyToNonEmpty_FromArraySequence_ArraySequence();
    Test_Concat_EmptyToNonEmpty_FromListSequence_ArraySequence();
    std::cout << "\nTests ListSequence:\n\n";
    TestGetSequenceType_ListSequence();
    TestGetters_EmptyList_ListSequence();
    TestGetters_WithElements_ListSequence();
    TestSet_ListSequence();
    TestResize_Smaller_ListSequence();
    TestResize_Larger_ListSequence();
    TestGetSubsequence_InvalidIndices_ListSequence();
    TestGetSubsequence_FullList_ListSequence();
    TestGetSubsequence_PartList_ListSequence();
    TestDefaultConstructor_ListSequence();
    TestConstructor_WithSize_ListSequence();
    TestConstructor_WithArray_ListSequence();
    TestCopyConstructor_ListSequence();
    TestConcat_ListSequence();
}

// int main ()
// {
//     ALLTESTS_SEQUENCE();
// }
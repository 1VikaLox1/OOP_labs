#include "myset.h"

MySet::MySet()
{
    elems = new int[10];
    setSize = 0;
    freeSize = 10;
}

MySet::MySet(int *arr, int arrSize)
{
    this->elems = new int[arrSize];
    for (int i = 0; i < arrSize; i++)
    {
        elems[i] = arr[i];
    }
}

MySet::MySet(const MySet &obj)
{
    this->elems = new int[obj.setSize];
    for (int i = 0; i < obj.setSize; i++)
    {
        elems[i] = obj.elems[i];
    }
}

MySet::~MySet()
{
    delete[] elems;
}

void MySet::addElem(int newElem)
{
    if(freeSize == setSize)
    {
        freeSize += 10;
        int *tempArr = new int[freeSize];
        //tempArr = elems;
        for (int i = 0; i < setSize; i++)
        {
            tempArr[i] = elems[i];
        }
        tempArr[setSize++] = newElem;
        //setSize++;
        delete[] elems;
        elems = tempArr;
    }
    if(freeSize > setSize)
    {
        elems[setSize++] = newElem;
    }
}

void MySet::deleteElem(int indToDel)
{
    int *tempArr = new int[freeSize];
    for (int i = 0; i < setSize; i++)
    {
        if(i == indToDel)
        {
            continue;
        }
        tempArr[i] = elems[i];
    }
    delete[] elems;
    elems = tempArr;
}

int MySet::findMin()
{
    int min;
    min = elems[0];
    for(int i = 1; i < setSize; i++)
    {
        if(min > elems[i])
        {
            min = elems[i];
        }
    }
    return min;
}

int MySet::findMax()
{
    int max;
    max = elems[0];
    for(int i = 1; i < setSize; i++)
    {
        if(max < elems[i])
        {
            max = elems[i];
        }
    }
    return max;
}

int MySet::findP()
{
    return setSize;
}

int MySet::isElem(int elem) //якщо елемента немає, то повератє -1, якщо є, то повертає індекс першого елемента
{
    int indOfElem = -1;
    for (int i = 0; i < setSize; i++)
    {
        if(elems[i] == elem)
        {
            indOfElem = i;
            break;
        }
    }
    return indOfElem;
}

MySet* MySet::operator=(const MySet &b)
{
    this->setSize = b.setSize;
    this->freeSize = b.freeSize;
    for (int i = 0; i < b.setSize; i++)
    {
        this->elems[i] = b.elems[i];
    }
    return this;
}

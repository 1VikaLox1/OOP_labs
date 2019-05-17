#include "myset.h"
#include <QString>

int *MySet::getElems() const
{
    return elems;
}

MySet::MySet()
{
    elems = new int[10];
    setSize = 0;
    freeSize = 10;
}

MySet::MySet(int *arr, int arrSize)
{
    this->elems = new int[arrSize];
    freeSize = arrSize;
    setSize = arrSize;
    for (int i = 0; i < arrSize; i++)
    {
        this->addElem(arr[i]);
    }
    //TODO recalculate setSize after adding all elems
}

MySet::MySet(const MySet &obj)
{
    elems = new int[obj.freeSize];
    freeSize = obj.freeSize;
    setSize = obj.setSize;
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
    if(!isElem(newElem))
    {
        if(freeSize == setSize)
        {
            freeSize += 10;
            int *tempArr = new int[freeSize];
            for (int i = 0; i < setSize; i++)
            {
                tempArr[i] = elems[i];
            }
            tempArr[setSize++] = newElem;
            //setSize++;
            delete[] elems;
            elems = tempArr;
        }
        else if(freeSize > setSize)
        {
            elems[setSize++] = newElem;
        }
    }
}

void MySet::deleteElem(int indToDel) //TODO check if too much freeSize
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

int MySet::findP() const
{
    return setSize;
}

bool MySet::isElem(int elem)
{
    int flagIsElem = false;
    for (int i = 0; i < setSize; i++)
    {
        if(elems[i] == elem)
        {
            flagIsElem = true;
            break;
        }
    }
    return flagIsElem;
}

void MySet::clear()
{
    if(elems)
    {
        delete [] elems;
        elems = nullptr;
    }
    setSize = 0;
    freeSize = 0;
}

MySet MySet::operator+(const MySet &obj)
{
    MySet newSet(obj);
    for (int i = 0; i < this->setSize; i++)
    {
        newSet.addElem(this->elems[i]);
    }
    return newSet;
}

MySet MySet::operator-(MySet b)
{
    MySet newSet;
    for (int i = 0; i < this->setSize; i++)
    {
        if(this->isElem(this->elems[i]) && b.isElem(this->elems[i]))
        {
            newSet.addElem(this->elems[i]);
        }
    }

    for (int i = 0; i < b.setSize; i++)
    {
        if(this->isElem(b.elems[i]) && b.isElem(b.elems[i]))
        {
            newSet.addElem(b.elems[i]);
        }
    }
    return newSet;
}

MySet MySet::operator/(MySet b)
{
    MySet newSet;
    for (int i = 0; i < this->setSize; i++)
    {
        if(this->isElem(this->elems[i]) && !(b.isElem(this->elems[i])))
        {
            newSet.addElem(this->elems[i]);
        }
    }

    for (int i = 0; i < b.setSize; i++)
    {
        if(!(this->isElem(b.elems[i])) && b.isElem(b.elems[i]))
        {
            newSet.addElem(b.elems[i]);
        }
    }
    return newSet;
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

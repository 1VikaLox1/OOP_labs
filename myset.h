#ifndef MYSET_H
#define MYSET_H


namespace Ui {
class MainWindow;
}

class MySet
{
private:
    int *elems;
    int setSize; //потужність
    int freeSize;
public:
    MySet();
    MySet(int *arr, int arrSize);
    MySet(const MySet &obj);
    ~MySet();
    void addElem(int elem);
    int *getElems() const;
    void deleteElem(int ind);
    int findMin();
    int findMax();
    int findP() const;
    bool isElem(int elem);
    void clear();
    MySet operator+ (MySet);
    MySet operator- (MySet);
    MySet operator/ (MySet);
    MySet* operator= (const MySet &b);
    friend Ui::MainWindow* operator<< (Ui::MainWindow *ui, MySet const &a);
    friend Ui::MainWindow* operator>> (Ui::MainWindow *ui, MySet &a);

};


#endif // MYSET_H

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
    void deleteElem(int ind);
    //void generateSet();
    int findMin();
    int findMax();
    int findP();
    bool isElem(int elem);
    MySet operator+ (MySet);
    MySet operator- (MySet);
    MySet operator/ (MySet);
    MySet* operator= (const MySet &b);
    friend Ui::MainWindow* operator<< (MySet, Ui::MainWindow *ui);
    friend Ui::MainWindow* operator>> (MySet, Ui::MainWindow *ui);
};

#endif // MYSET_H

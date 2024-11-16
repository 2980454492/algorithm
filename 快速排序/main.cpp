#include<iostream>
#include"QuickSort.cpp"

using namespace std;

int main()
{
    vector<int> v{5,6,8,1,2,7,9,4,3,8};
    QuickSort<int> Q(10,v);
    Q.PrintElem();
    Q.QSort(0,9);
    Q.PrintElem();
    return 0;
}

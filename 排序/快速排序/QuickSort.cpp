#include"QuickSort.h"

template<typename T>
QuickSort<T>::QuickSort(int number,vector<T> elem) noexcept:
    m_number(number),m_elem(elem){}

template<typename T>
void QuickSort<T>::QSort(int left_i,int right_i)
{
    if(left_i>=right_i)
    {
        return ;
    }
    T piovt=m_elem[left_i]; //piovt是主元
    int li=left_i,ri=right_i; //li和ri分别遍历待排数组的左端和右端
    while(li<ri)
    {
        //找到右侧第一个小于等于主元的元素，将其放在li的位置，并退出循环
        while(piovt<=m_elem[ri] && li<ri)
        {
            ri--;
        }
        if(li<ri)
        {
            m_elem[li++]=m_elem[ri];
        }
        
        //找到左侧第一个大于主元的元素，将其放在ri的位置，并退出循环
        while(piovt>m_elem[li] && li<ri)
        {
            li++;
        }
        if(li<ri)
        {
            m_elem[ri++]=m_elem[li];
        }
        
    }
    m_elem[li]=piovt; //将主元放到合适的位置
    QSort(left_i,li-1); //递归排序左半部分
    QSort(li+1,right_i); //递归排序右半部分
}

template<typename T>
void QuickSort<T>::PrintElem() const
{
    for(const auto& it : m_elem)
    {
        cout<<it<<" ";
    }
    cout<<endl;
}

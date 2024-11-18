#include"InsertionSort.h"

template<typename T>
Insertion<T>::Insertion(int number,vector<T> elem) noexcept : m_number(number),m_elem(elem) {}

template<typename T>
void Insertion<T>::InsertionSort()
{
    for(int i=0;i<m_number;i++)
    {
        T x=m_elem[i];
        int j;
        for(j=i-1;j>=0 && x<m_elem[j];j--)
        {
            m_elem[j+1]=m_elem[j];
        }
        m_elem[j+1]=x;
    }
}

template<typename T>
void Insertion<T>::PrintElem() const 
{
    for(const auto& it : m_elem)
    {
        cout<<it<<" ";
    }
    cout<<endl;
}
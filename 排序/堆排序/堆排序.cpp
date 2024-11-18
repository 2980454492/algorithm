#include <iostream>  
using namespace std;

//建立最大堆类
template<class T>
class MaxHeap
{
    public:
        MaxHeap()=delete;
        MaxHeap(int size,T *data) noexcept;
        MaxHeap(const MaxHeap& A)=delete;
        MaxHeap(MaxHeap&& A)=delete;

    public:
        //堆排序
        void HeapSort();
        //建立最大堆
        void BuildMaxHeap();
        //维护最大堆的性质
        void MaxHeapify(int index);

    public:
        //交换两个位置的元素
        void Swap(int i1,int i2);
        //输出数组
        void print();

    public:
        T *m_data;
        //数组最大元素个数
        int m_maxSize;
        //数组当前待排元素个数
        int m_conSize;
};

int main()
{
    int a[11]={0,9,5,8,4,3,1,3,6,8,2};
    MaxHeap<int> A(10,a);
    A.print();
    A.HeapSort();
    A.print();
    return 0;
}




template<class T>
MaxHeap<T>::MaxHeap(int size,T *data) noexcept
{
    m_data=new T[size+1];
    for(int i=0;i<=size;i++)
    {
        m_data[i]=data[i];
    }
    m_maxSize=size;
    m_conSize=size;
}

template<class T>
void MaxHeap<T>::HeapSort()
{
    BuildMaxHeap();
    for(int i=m_maxSize;i>0;i--)
    {
        Swap(1,i);
        m_conSize--;
        MaxHeapify(1);
    }
}

template<class T>
void MaxHeap<T>::BuildMaxHeap()
{
    for(int i=m_conSize/2;i>0;i--)
    {
        MaxHeapify(i);
    }
}

template<class T>
void MaxHeap<T>::MaxHeapify(int index)
{
    int l=index*2,r=index*2+1;
    int largest_i=index; //最大数字的序号
    //选出根、左、右种最大的数字
    if(m_data[l]>m_data[largest_i] && l<=m_conSize)
    {
        largest_i=l;
    }
    if(m_data[r]>m_data[largest_i] && r<=m_conSize)
    {
        largest_i=r;
    }
    if(largest_i!=index)
    {
        Swap(index,largest_i);
        MaxHeapify(largest_i);
    }
}

template<class T>
void MaxHeap<T>::Swap(int i1,int i2)
{
    T temp=m_data[i1];
    m_data[i1]=m_data[i2];
    m_data[i2]=temp;    
}

template<class T>
void MaxHeap<T>::print()
{
    for(int i=1;i<=m_maxSize;i++)
    {
        cout<<m_data[i]<<" ";
    }
    cout<<endl;
}

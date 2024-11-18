#pragma once
#include<iostream>
using namespace std;
#include<vector>

//快速排序类
template<typename T>
class QuickSort
{
public:
    //禁止默认构造
    QuickSort(void)=delete;
    //构造函数
    QuickSort(int number,vector<T> elem) noexcept;
    //禁止拷贝构造
    QuickSort(const QuickSort& Q)=delete;
    //析构函数
    ~QuickSort(void)=default;

    //快速排序函数
    void QSort(int left_i,int right_i);
    //输出函数
    void PrintElem() const;
private:
    vector<T> m_elem; //数组
    int m_number; //数组的元素个数
};

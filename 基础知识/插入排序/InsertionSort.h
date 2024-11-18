#pragma once
#include<iostream>
using namespace std;
#include<vector>

//直接插入类
template<typename T>
class Insertion
{
public:
    //禁止默认构造
    Insertion(void)=delete;
    //构造函数
    Insertion(int number,vector<T> elem) noexcept;
    //禁止拷贝构造
    Insertion(const Insertion& Q)=delete;
    //析构函数
    ~Insertion(void)=default;

    //直接插入函数
    void InsertionSort();
    //输出函数
    void PrintElem() const;
private:
    vector<T> m_elem; //数组
    int m_number; //数组的元素个数
};
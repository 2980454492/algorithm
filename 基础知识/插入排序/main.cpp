#include"InsertionSort.cpp"
#include"string"

int main()
{
    vector<string> v={"zhangsan","lisi","wangwu","wangliu","liuxiao"};
    Insertion<string> I(5,v);
    //排序前输出
    cout<<"排序前："<<endl;
    I.PrintElem();

    //直接插入排序
    I.InsertionSort();

    //排序后输出
    cout<<"排序后:"<<endl;
    I.PrintElem();
    return 0;
}

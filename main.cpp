#include<stdio.h>
#include<stdlib.h>
#define N 10000

//计算跨越中点的数组最大和
void find_max_crossing_subarray(int *A,int low,int mid,int high,int &left_index,int &right_index,int &sum)
{
    int left_sum=-1000000,right_sum=-1000000; //分别计算从中间到左右两边的最大连续数组
    sum=0;
    for(int i=mid;i>=low;i--)
    {
        sum+=A[i];
        if(sum>left_sum)
        {
            left_sum=sum;
            left_index=i; //跨越中点的数组的最大子数组的左下标
        }
    }
    sum=0;
    for(int i=mid+1;i<=high;i++)
    {
        sum+=A[i];
        if(sum>right_sum)
        {
            right_sum=sum;
            right_index=i; //跨越中点的数组的最大子数组的右下标
        }
    }
    sum=left_sum+right_sum; //跨域中点的数组的最大子数组之和
}

//用递归的思想求解最大子数组问题
void find_maxisum_subarray(int *A,int low,int high,int &left_index,int &right_index,int &sum)
{
    if(low==high) //该子数组中只有一个元素
    {
        left_index=right_index=low;
        sum=A[low];
        return ;
    }
    int mid=(low+high)/2;
    int left_low,left_high,left_sum;
    find_maxisum_subarray(A,low,mid,left_low,left_high,left_sum); //完全在中点左边的最大子数组
    int right_low,right_high,right_sum;
    find_maxisum_subarray(A,mid+1,high,right_low,right_high,right_sum); //完全在中点右边的最大子数组
    int cross_low,cross_high,cross_sum;
    find_max_crossing_subarray(A,low,mid,high,cross_low,cross_high,cross_sum); //跨越中点的最大子数组
    if(left_sum>=right_sum&&left_sum>=cross_sum)
    {
        left_index=left_low;
        right_index=left_high;
        sum=left_sum;
    }
    else if(right_sum>=left_sum&&right_sum>=cross_sum)
    {
        left_index=right_low;
        right_index=right_high;
        sum=right_sum;
    }
    else
    {
        left_index=cross_low;
        right_index=cross_high;
        sum=cross_sum;
    }
}

int main()
{
    int A[N];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    int left_index,right_index,sum; //最大子数组的左下标，右下标和和值
    find_maxisum_subarray(A,0,n-1,left_index,right_index,sum);
    printf("%d %d %d",left_index,right_index,sum);
    return 0;
}
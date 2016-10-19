/*
 * 刷题的时候经常遇到二分查找的问题
 * 但是根据问题的不同，所需要返回的数组下标也不一样
 * 这里就好好思考一下每一种情况，写出代码实现
 * 每个函数可能只有几个符号不同，注意体会
 */
int BS_e(int a[],int begin,int end,int target)
//返回所查询的数组a的下标区间[begin,end]中值 “ 等于 ” target的下标
//如果区间中不存在这样的值，将返回-1
{
    int mid;
    while(begin<=end) {//循环终止时只有一种可能，即 begin=end
        mid=(begin+end)>>1;
        if(a[mid]==target) return mid;
        else if(a[mid]>target) end=mid-1;
        else begin=mid+1;
    }
    return -1;
}

int BS_ge(int a[],int begin,int end,int target)
//返回所查询的数组a的下标区间[begin,end]中值 “ 大于等于 ” target的最小下标
//如果区间中不存在这样的值，将返回end
{
    int mid;
    while(begin<end) {//循环终止时只有一种可能，即 begin=end
        mid=(begin+end)>>1;
        if(a[mid]>=target) end=mid;
        else begin=mid+1;
    }
    return begin;
}

int BS_g(int a[],int begin,int end,int target)
//返回所查询的数组a的下标区间[begin,end]中值 “ 大于 ” target的最小下标
//如果区间中不存在这样的值，将返回end
{
    int mid;
    while(begin<end) {//循环终止时只有一种可能，即 begin=end
        mid=(begin+end)>>1;
        if(a[mid]>target) end=mid;
        else begin=mid+1;
    }
    return begin;
}

int BS_le(int a[],int begin,int end,int target)
//返回所查询的数组a的下标区间[begin,end]中值 “ 小于等于 ” target的最大下标
//如果区间中不存在这样的值，将返回begin
{
    int mid;
    while(begin<end) {//循环终止时只有一种可能，即 begin=end
        mid=(begin+end+1)>>1;
        if(a[mid]<=target) begin=mid;
        else end=mid-1;
    }
    return begin;
}

int BS_l(int a[],int begin,int end,int target)
//返回所查询的数组a的下标区间[begin,end]中值 “ 小于 ” target的最大下标
//如果区间中不存在这样的值，将返回begin
{
    int mid;
    while(begin<end) {//循环终止时只有一种可能，即 begin=end
        mid=(begin+end+1)>>1;
        if(a[mid]<target) begin=mid;
        else end=mid-1;
    }
    return begin;
}





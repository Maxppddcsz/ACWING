/*
vector, 自动变长数组,倍增思想
        size() empty() clear()
        front() back
        push_back()插入一个数 pop_back()最后一个数删掉
        迭代器 begin()第一个数 end()最后一个数后的数
        比较运算

pair<int,int> 二元组
        first second
        比较运算，第一/第二关键字

string, 字符串, substr() 返回子串,c_str()
        size() empty() clear()

queue,  队列 没有clear -> q=queue<int>();
        push()
        pop() 弹出队头
        front() 返回队头
        back() 返回队尾

priority_queue, 优先队列,push(),pop() 堆顶,top() 默认是大根堆
        小根堆->插入-x 或 priority_queue<int,vector<int>,greater<int>> heap)

stack, 栈,push(),pop(),top()

deque, 双端队列 size() empty() clear()
        front()/back()
        push_back()/pop_back()
        push_front()/pop_front()

set 不重复,map,mutiset 可重复,multimap, 基于平衡二叉树,动态维护有序序列
        set/multi_set
            insert()
            find()
            count()
            erase() 输入是一个数x，删除所有x；输入迭代器，删除迭代器
            lower_bound 返回大于等于x/upper_bound 返回小于等于x()
        map/multi_map 映射
            insert() 插入一个pair
            erase()
            find()
            []
            时间复杂度 logn

unordered_set,unordered_map,unordered_mutiset,unordered_multimap, 哈希表
        不支持lower_bound /upper_bound

bitset, 压位
        节省八位内存
        bitset<10000> S;
        ~s,&,^
        >>,<<
        []
        count() 返回多少个1
        any 判断至少一个1
        none 判断是否全为空
        set()所有位置1
        set(k,v) k位变成v
        reset 所有位变成0
        flip() 等价于~
        flip(k) k位取反
 */

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>

using namespace std;

int main()
{
    // vector<int> a(10, 3); 定义一个长度为10的vector，里面均为3
    vector<int> a(4, 3), b(3, 4);
    if (a < b)
        puts("a<b");

    for (int i = 0; i < 10; i++)
        a.push_back(i);

    for (int i = 0; i < a.size(); i++)
        cout << a[i] << ' ';
    cout << endl;

    // for (vector<int>::iterator i = a.begin(); i != a.end(); i++)
    for (auto i = a.begin(); i != a.end(); i++)
        cout << *i << ' ';
    cout << endl;

    for (auto x : a)
        cout << x << ' ';
    cout << endl;

    // pair<int,<int,int>>
    pair<int, string> p;
    p = make_pair(10, "pzx");

    // string
    string str = "pzx";
    str += "abc";
    cout << str.substr(1, 2) << endl;
    printf("%s\n", str.c_str()); // printf无法直接输出string类型

    // 优先队列 -> 堆
    // map
    map<string, int> c;
    c["pzx"] = 1;
    cout << c["pzx"] << " ";
    return 0;
}
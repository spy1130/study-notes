#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

// BF算法
int BF(string A, string B)
{
    cout << "请输入查询开始的位置：(第一位为0)" << endl;
    int i = 0; // 主串上的
    cin >> i;
    int j = 0; // 子串上的
    while (i < (int)A.length() && j < (int)B.length())
    { // 两个字符串均为比较到串尾（只有有一个到串尾就跳出循环）
        if (A[i] == B[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 1; // i-(j-1),回到本轮匹配的起始位置
            j = 0;
        }
    }
    if (j >= (int)B.length())
    {
        cout << "已查询到！" << endl;
        return i - (int)B.length();
    }
    else
    {
        cout << "未查询到！" << endl;
        return -1;
    }
}
// 获取NEXT数组
void getNext(const string& p,int next[])
{

    int len = (int)p.size();
    next[0] = -1;// 位置 0 上的元素前面没有子串,判断为无效位，所以写成-1，也能使next对应最大相等前缀和后缀
    int k = -1;// 用来记录每一个next数组下标对应的最大相等前缀和后缀
    int j = 0;// i当前主串正在匹配的字符位置，也是next数组的索引
    while(j < len - 1)
    {
        if(k == -1 || p[j] == p[k])
        {
            ++j;
            ++k;
            next[j] = k;
        }
        else
        {
            k = next[k];
        }
    }
}
// 是一个递推
// 看这个图解法https://www.bilibili.com/video/BV16X4y137qw/?p=1&t=1307
//next实现https://zhuanlan.zhihu.com/p/159429201
int kmp(const string &A, const string &B)
{
    int n = (int)A.size();
    int ans = -1;
    int i = 0;
    int j = 0;
    int patternLen = (int)B.size();

    int next[patternLen] = {0}; // 不用管
    getNext(B, next);

    while (i < n)
    {
        if (j == -1 || A[i] == B[j])
        {
            ++i;
            ++j;
        }
        else
        {
            j = next[j];
        }

        if (j == patternLen)
        {
            ans = i - patternLen;
            break;
        }
    }

    return ans;
}
int main()
{
    string a = "abbbadabaabcabadba";
    string b = "abaabcaba";
    string chose;
    cout << "请输入查找方式(BF/KMP):"<<endl ;
    cin>>chose;
    if (chose == "BF")
    {
        int flag = BF(a, b);
        if (flag == -1)
        {
            cout << "模式串在主串之中不存在！" << endl;
        }
        else
        {
            cout << "模式串在主串之中存在！" << endl;
            cout << "起始位置为：" << flag + 1 << endl;
        }
    }
    else if (chose == "KMP")
    {
        cout << kmp(a, b) << endl;
        return 0;
    }
    else
    {
        cout << "你乱输**?" << endl;
        return -1;
    }

    system("pause");
    return EXIT_SUCCESS;
}
// string A = "abbbadabaabcabadba";
// string B = "abaabcaba";
// cout << "请输入主串：" << endl;
//string a; // 文本串（主串）
//cin >> a;
//cout << "请输入模式串：" << endl;
//string b;
//cin >> b; // 模板串/模式串(将被匹配的子串)

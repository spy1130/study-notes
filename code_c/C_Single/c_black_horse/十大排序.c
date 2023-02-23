#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BASE 10 // 基数排序的基数
#define Len(arr) sizeof(arr) / sizeof(*arr)

typedef struct // 快速排序的结构体
{
    int start, end;
} Range;

Range new_Range(int s, int e) // 快速排序的结构体
{
    Range r;
    r.start = s;
    r.end = e;
    return r;
}

/* 以下为十大排序 */

void bubble_sort(int *arr, int len) // 冒泡排序
{
    for (int i = 0; i < len - 1; i++)
        for (int j = 0, temp; j < len - 1 - i; j++)
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

void selection_sort(int *arr, int len) // 选择排序
{
    for (int min, temp, i = 0; i < len - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < len; j++)
            if (arr[j] < arr[min])
                min = j;
        temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

void insertion_sort(int *arr, int len) // 插入排序
{
    for (int i = 1, j, key; i < len; i++)
    {
        key = arr[i];
        j = i - 1;
        while ((j >= 0) && (arr[j] > key))
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void shell_sort(int *arr, int len) // 希尔排序
{
    for (int temp, gap = len >> 1; gap > 0; gap >>= 1)
        for (int j, i = gap; i < len; i++)
        {
            temp = arr[i];
            for (j = i - gap; j >= 0 && arr[j] > temp; j -= gap)
                arr[j + gap] = arr[j];
            arr[j + gap] = temp;
        }
}

void merge_sort(int *arr, int len) // 归并排序
{
    int *a = arr, *b = (int *)malloc(len * sizeof(int));
    for (int *temp, seg = 1; seg < len; seg += seg)
    {
        for (int start = 0; start < len; start += seg * 2)
        {
            int low = start, mid = start + seg < len ? start + seg : len, high = start + seg * 2 < len ? start + seg * 2 : len;
            int k = low;
            int start1 = low, end1 = mid;
            int start2 = mid, end2 = high;
            while (start1 < end1 && start2 < end2)
                b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
            while (start1 < end1)
                b[k++] = a[start1++];
            while (start2 < end2)
                b[k++] = a[start2++];
        }
        temp = a;
        a = b;
        b = temp;
    }
    if (a != arr)
    {
        for (int i = 0; i < len; i++)
            b[i] = a[i];
        b = a;
    }
    free(b);
}

void quick_sort(int *arr, const int len) // 快速排序
{
    if (len <= 0)
        return; // 避免len等於負值時引發段錯誤（Segment Fault）
    // r[]模擬列表,p為數量,r[p++]為push,r[--p]為pop且取得元素
    Range r[len];
    int p = 0, temp, mid, left, right;
    r[p++] = new_Range(0, len - 1);
    while (p)
    {
        Range range = r[--p];
        if (range.start >= range.end)
            continue;
        mid = arr[(range.start + range.end) / 2]; // 選取中間點為基準點
        left = range.start;
        right = range.end;
        do
        {
            while (arr[left] < mid)
                ++left; // 檢測基準點左側是否符合要求
            while (arr[right] > mid)
                --right; // 檢測基準點右側是否符合要求
            if (left <= right)
            {
                temp = arr[right];
                arr[right] = arr[left];
                arr[left] = temp;
                left++;
                right--; // 移動指針以繼續
            }
        } while (left <= right);
        if (range.start < right)
            r[p++] = new_Range(range.start, right);
        if (range.end > left)
            r[p++] = new_Range(left, range.end);
    }
}

void quick_sort_recursive(int *arr, int start, int end) // 快速排序（递归法）start = 0, end = len - 1
{
    int temp, mid, left, right;
    if (start >= end)
        return;
    mid = arr[end];
    left = start;
    right = end - 1;
    while (left < right)
    {
        while (arr[left] < mid && left < right)
            left++;
        while (arr[right] >= mid && left < right)
            right--;
        temp = arr[right];
        arr[right] = arr[left];
        arr[left] = temp;
    }
    if (arr[left] >= arr[end])
    {
        temp = arr[end];
        arr[end] = arr[left];
        arr[left] = temp;
    }
    else
        left++;
    if (left)
        quick_sort_recursive(arr, start, left - 1);
    quick_sort_recursive(arr, left + 1, end);
}

void heap_sort(int *arr, int len) // 堆排序
{
    int i, temp;
    // 初始化，i从最后一个父节点开始调整
    for (i = len / 2 - 1; i >= 0; i--)
    {
        // 建立父节点指标和子节点指标
        int dad = i, son = dad * 2 + 1;
        while (son <= len - 1)
        { // 若子节点指标在范围内才做比较
            if (son + 1 <= len - 1 && arr[son] < arr[son + 1])
                son++; // 先比较两个子节点大小，选择最大的
            if (arr[dad] > arr[son])
                break; // 如果父节点大于子节点代表调整完毕，跳出循环
            else
            { // 否则交换父子内容再继续子节点和孙节点比较
                temp = arr[dad];
                arr[dad] = arr[son];
                arr[son] = temp;
                dad = son;
                son = dad * 2 + 1;
            }
        }
    }
    // 先将第一个元素和已排好元素前一位做交换，再重新调整，直到排序完毕
    for (i = len - 1; i > 0; i--)
    {
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        // 建立父节点指标和子节点指标
        int dad = 0, son = dad * 2 + 1;
        while (son <= i - 1)
        { // 若子节点指标在范围内才做比较
            if (son + 1 <= i - 1 && arr[son] < arr[son + 1])
                son++; // 先比较两个子节点大小, 选择最大的
            if (arr[dad] > arr[son])
                break; // 如果父节点大于子节点代表调整完毕，跳出循环
            else
            { // 否则交换父子内容再继续子节点和孙节点比较
                temp = arr[dad];
                arr[dad] = arr[son];
                arr[son] = temp;
                dad = son;
                son = dad * 2 + 1;
            }
        }
    }
}

void counting_sort(int *arr, int len) // 计数排序
{
    int *count_arr = (int *)malloc(sizeof(int) * 100), *sorted_arr = (int *)malloc(sizeof(int) * len);
    for (int k = 0; k < 100; k++)
        count_arr[k] = 0;
    for (int i = 0; i < len; i++)
        count_arr[arr[i]]++;
    for (int k = 1; k < 100; k++)
        count_arr[k] += count_arr[k - 1];
    for (int j = len; j > 0; j--)
        sorted_arr[--count_arr[arr[j - 1]]] = arr[j - 1];
    memcpy(arr, sorted_arr, sizeof(int) * len); // 将排好的数组复制到原数组中
    free(count_arr);
    free(sorted_arr);
}

void bucket_sort(int *arr, int len) // 桶排序
{
    int tmpArrLen = arr[0];
    for (int i = 1; i < len; i++) // 遍历获取数组最大值并赋值给tmpArrLen
        if (arr[i] > tmpArrLen)
            tmpArrLen = arr[i];
    int *tmpArr = (int *)malloc(sizeof(int) * ++tmpArrLen); // 获得空桶大小
    for (int i = 0; i < tmpArrLen; i++)                     // 空桶初始化
        tmpArr[i] = 0;
    for (int i = 0; i < len; i++) // 寻访序列，并且把项目一个一个放到对应的桶子去。
        tmpArr[arr[i]]++;
    for (int i = 0, j = 0; i < tmpArrLen; i++)
    {
        while (tmpArr[i] != 0) // 对每个不是空的桶子进行排序。
        {
            arr[j] = i; // 从不是空的桶子里把项目再放回原来的序列中。
            j++;
            tmpArr[i]--;
        }
    }
    free(tmpArr);
}

void radix_sort(int *arr, int len) // 基数排序
{
    int m = arr[0], exp = 1;
    int *b = (int *)malloc(sizeof(int) * len);
    for (int i = 1; i < len; i++)
        if (arr[i] > m)
            m = arr[i];
    while (m / exp > 0)
    {
        int bucket[BASE] = {0};
        for (int i = 0; i < len; i++)
            bucket[(arr[i] / exp) % BASE]++;
        for (int i = 1; i < BASE; i++)
            bucket[i] += bucket[i - 1];
        for (int i = len - 1; i >= 0; i--)
            b[--bucket[(arr[i] / exp) % BASE]] = arr[i];
        for (int i = 0; i < len; i++)
            arr[i] = b[i];
        exp *= BASE;
    }
    free(b);
}

void test(int *arr, int len, int num)
{
    switch (num)
    {
    case 1:
        printf("冒泡排序 time");
        bubble_sort(arr, len);
        break;
    case 2:
        printf("选择排序 time");
        selection_sort(arr, len);
        break;
    case 3:
        printf("插入排序 time");
        insertion_sort(arr, len);
        break;
    case 4:
        printf("希尔排序 time");
        shell_sort(arr, len);
        break;
    case 5:
        printf("归并排序 time");
        merge_sort(arr, len);
        break;
    case 6:
        printf("快速排序 time");
        quick_sort(arr, len);
        break;
    case 7:
        printf("堆排序   time");
        heap_sort(arr, len);
        break;
    case 8:
        printf("计数排序 time");
        counting_sort(arr, len);
        break;
    case 9:
        printf("桶排序   time");
        bucket_sort(arr, len);
        break;
    case 10:
        printf("基数排序 time");
        radix_sort(arr, len);
        break;
    }
}

int main()
{
    int n = 50000; // 设定乱序列表长度
    int *arr = (int *)malloc(sizeof(int) * n), *arr1 = (int *)malloc(sizeof(int) * n);
    clock_t start, end;
    srand(time(0));
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 100;
    printf("1~%d的乱序排序:\n", n);
    for (int  i = 4; i < 5; i++)
    {
        if (i == 6 && n >= 260000) continue;
        memcpy(arr1, arr, sizeof(int) * n);
        start = clock();
        test(arr1, n, i);
        end = clock();
        double count = (double)(end - start) / CLOCKS_PER_SEC;
        count ? printf(" = %gs\n", count) : printf(" < 0.000001s\n");
    }
    return 0;
}
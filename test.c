#include<stdio.h>
#include<stdlib.h>
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {//将合并后的数组放到nums1中
    int i = 0;
    int j = 0;
    int* a = (int*)malloc(sizeof(int)*(n + m));
    int cnt = 0;
    while(i < m && j < n){//两个序列中都有
        if(nums1[i] < nums2[j]){//取出小的放到新序列中
            a[cnt++] = nums1[i++];
        }
        else{
            a[cnt++] = nums2[j++];
        }
    }
    while(i < m){//第一个序列没用完，直接续上
        a[cnt++] = nums1[i++];
    }
    while(j < n){//第二个序列直接续上
        a[cnt++] = nums2[j++];
    }
    for(int i = 0; i < cnt; ++i){
        nums1[i] = a[i];
    }
    
    free(a);//释放辅助空间
}
void Merge_Sort(int* a, int lo, int hi){//数组a，在[lo, hi)范围内排序
    if(hi - lo < 2) return;//一个元素，已经有序
    int mid = (lo + hi)/2;//从中间分开
    Merge_Sort(a, lo, mid);//两边分别排序
    Merge_Sort(a, mid, hi);
    merge(&a[lo], hi - lo, mid - lo, &a[mid], hi - mid, hi - mid);//将排序好的数组合并
}
int main(){
    int* a = (int*)malloc(sizeof(int)*100);
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &a[i]);
    }
    Merge_Sort(a, 0, n);
    for(int i = 0; i < n; ++i){
        printf("%d ", a[i]);
    }
    return 0;
}
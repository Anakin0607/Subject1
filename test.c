#include<stdio.h>
#include<stdlib.h>
int Binary_Search(int* a, int lo, int hi, int k){//在a中[lo, hi)范围内查找小于k的最大值
    if(hi - lo < 2) return lo;//只有一个值，直接返回
    int mid = (lo + hi)/2;
    if(a[mid] < k){
        return Binary_Search(a, mid, hi, k);
    }
    else{
        return Binary_Search(a, lo, mid, k);
    }
}
int main(){
    int* a = (int*)malloc(sizeof(int)*100);
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; ++i){
        scanf("%d", &a[i]);
    }
    printf("%d", a[Binary_Search(a, 0, n, k)]);
    return 0;
}
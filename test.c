#include<stdio.h>
#include<stdlib.h>
int Binary_Search_it(int* a, int lo, int hi, int k){//在[lo, hi)中查找小于k的最大值
    while(hi - lo > 1){
        int mid = (lo + hi) / 2;
        if(a[mid] < k){
            lo = mid;
        }
        else{
            hi = mid;
        }
    }
    return lo;
}
int main(){
    int* a = (int*)malloc(sizeof(int)*100);
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; ++i){
        scanf("%d", &a[i]);
    }
    printf("%d", a[Binary_Search_it(a, 0, n, k)]);
    return 0;
}
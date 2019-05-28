#include <stdio.h>
#include <stdlib.h>

int sorting_function(int n, int arr[]){
        int arr_len=n,c;
        while(arr_len>=1){
                for(int i=0;i<n-arr_len;i++){
                        if(arr[i]>arr[i+arr_len]){
                                c=arr[i];
                                arr[i]=arr[i+arr_len];
                                arr[i+arr_len]=c;
                        }
                }
                arr_len/=1.24733;
        }
}
int main(){
        int n;
        scanf("%d",&n);
        int arr[n];
        for(int i=0;i<n;i++){
                scanf("%d",&arr[i]);
        }
        sorting_function(n,arr);
        for(int i=0;i<n;i++){
                printf("%d",arr[i]);
                if (i==n-1)
                printf("\n");
                else
                printf(" ");
        }
        return 0;
}

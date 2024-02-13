#include <stdio.h>
int main (void){
	// ordenamiento shakesort
	int arr[10] = {43, 432, 36, 5, 6, 57, 94, 63, 3, 44};
	int p, i,n=10,temp;
    for (p=1;p<=5; p++){
        for (i = p - 1; i <n - p; i++){
            if (arr[i] > arr[i+1]){
                temp=arr[i+1];
                arr[i+1]=arr[i];
                arr[i]=temp;
           };
        };
        for (i = n - p - 1; i >= p; i--){
            if (arr[i] < arr[i-1]){
                temp=arr[i-1];
                arr[i-1]=arr[i];
                arr[i]=temp;
              };
         };
    };
    for (i = 0 ; i < 10; i++){
        printf("%d ", arr[i]);
     };
    return 0;
}

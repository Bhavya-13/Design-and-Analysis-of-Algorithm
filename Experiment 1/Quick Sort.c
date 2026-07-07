#include <stdio.h>


// Quick Sort function
void quickSort(int arr[], int low, int high) {

	if(low >= high)
		return;

	int pivot = low;
	int p = low+1;
	int q = high;

	while(p<=q){
		
		//p right
		while (p <= high && arr[p]<=arr[pivot]){
			p++;
		}
		//q left
		while(q>=low && arr[q]>arr[pivot]){
			q--;
		}

		if(p<q){
			//swap pivot and p
			int t2 = arr[pivot];
			arr[pivot]=arr[q];
			arr[q]=t2;
		}
	}

int temp = arr[pivot];
arr[pivot] = arr[q];
arr[q]=temp;


quickSort(arr, low, q-1);
quickSort(arr,q+1,high);
    
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    // Input the size of the array
    scanf("%d", &n);
    int arr[n];
    
    // Input the elements of the array
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Print the original array
    printArray(arr, n);

    // Sort the array using quick sort
    quickSort(arr, 0, n - 1);
    
    // Print the sorted array
    printArray(arr, n);

    return 0;
}

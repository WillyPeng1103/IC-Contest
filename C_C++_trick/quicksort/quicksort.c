// An iterative implementation of quick sort
#include <stdio.h>

// A utility function to swap two elements
int partition(int arr[], int low, int high) {
    // 選擇最後一個元素作為 pivot
    int piv_index = (low+high)/2;
    int pivot = arr[piv_index];
    printf("low = %d high = %d\n",low,high);
    // 小於 pivot 的元素放在左邊，大於 pivot 的元素放在右邊
    int i = low - 1;
    int dick;
    for (int j = low; j <= high; j++) {
        if(j < piv_index | (j > piv_index  & (i+1)< piv_index)){
            dick = 0;
        }
        else if(j > piv_index ){
            dick = 1;
        }
        
        if (arr[j] <= arr[piv_index] & j != piv_index) {
            i++;
            int temp = arr[i+dick];
            arr[i+dick] = arr[j];
            arr[j] = temp;
        }

    }
    printf("--------------------\n");
    // 交換 arr[i+1] 和 arr[high] (pivot)
    int temp = arr[i + 1];
    arr[i + 1] = arr[piv_index];
    arr[piv_index ] = temp;
    // 返回分割點的索引
    return i + 1;
}

/* A[] --> Array to be sorted, 
   l  --> Starting index, 
   h  --> Ending index */
void quickSortIterative (int arr[], int l, int h)
{
    // Create an auxiliary stack
    int stack[ h - l + 1 ];

    // initialize top of stack
    int top = -1;

    // push initial values of l and h to stack
    stack[ ++top ] = l;
    stack[ ++top ] = h;

    // Keep popping from stack while is not empty
    while ( top >= 0 )
    {
        printf("top = %d\n",top);
        // Pop h and l
        for(int k=0;k<=top;k++){
            printf("stack[%d] = %d\n",k,stack[k]);
        }
        h = stack[ top-- ];
        l = stack[ top-- ];
        printf("h = %d\n",h);
        printf("l = %d\n",l);
        // Set pivot element at its correct position
        // in sorted array
        int p = partition( arr, l, h );
        printf("p = %d\n",p);

        // If there are elements on left side of pivot,
        // then push left side to stack
        if ( p-1 > l )
        {
            stack[ ++top ] = l;
            stack[ ++top ] = p - 1;
        }

        // If there are elements on right side of pivot,
        // then push right side to stack
        if ( p+1 < h )
        {
            stack[ ++top ] = p + 1;
            stack[ ++top ] = h;
        }
    }
}

// A utility function to print contents of arr
void printArr( int arr[], int n )
{
    int i;
    for ( i = 0; i < n; ++i )
        printf( "%d ", arr[i] );
}

// Driver program to test above functions
int main()
{
    int arr[] = {10,9,8,7,6,5,4,3,2,1,0};
    int n = sizeof( arr ) / sizeof( *arr );
    quickSortIterative( arr, 0, n - 1 );
    printArr( arr, n );
    return 0;
}
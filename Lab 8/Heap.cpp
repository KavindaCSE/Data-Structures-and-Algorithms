#include <iostream>
using namespace std;

// function to heapify the tree
void heapify(int arr[], int n, int root)
{
    int left = root * 2 + 1, right = root * 2 + 2, max = root;
    if (arr[left] > arr[root] && left < n) {
        max = left;
    }
    if (right < n && arr[right] > arr[max]) {
        max = right;
    }
    if (max != root) {
        int temp = arr[max];
        arr[max] = arr[root];
        arr[root] = temp;
        heapify(arr, n, max);
    }
}

// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
    for (int i = n / 2 - 1; i > -1; i--) {
        heapify(arr, n, i);
    }

   // extracting elements from heap one by one
    for (int i = n - 1; i > -1; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }

}

/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}

// main program
int main()
{
    cout << "Enter the length: ";
    int n;
    cin >> n;
    cout << endl;
    int heap_arr[n];
    for (int i = 0; i < n; i++) {
        heap_arr[i] = rand() % 50;
    }
    cout<<"Input array"<<endl;
    displayArray(heap_arr,n);

    heapSort(heap_arr, n);

    cout << "Sorted array"<<endl;
    displayArray(heap_arr, n);
}
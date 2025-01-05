#include <iostream>
using namespace std;

void insert(int arr[], int n) 
{
    for (int i = 1; i < n; i++) 
	{
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) 
		{
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key; 
    }
}

void display(int arr[], int n) 
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";    	
	}

    cout << endl;
}

int main() 
{
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / 4;

    cout << "Array before sorting: ";
    display(arr, n);

    insertionSort(arr, n);

    cout << "Array after Insertion Sort: ";
    display(arr, n);

    return 0;
}


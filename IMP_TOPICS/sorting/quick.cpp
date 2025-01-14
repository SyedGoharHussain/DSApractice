#include <iostream>
using namespace std;

int sep(int arr[], int low, int high) 
{
    int pivot = arr[high];  
    int i = low - 1;        

    for (int j = low; j <= high - 1; j++) 
	{
        if (arr[j] < pivot) 
		{
            i++;
            swap(arr[i],arr[j]);
        }
    }
	swap(arr[high],arr[i+1]);
    return i + 1;
}

void Sort(int arr[], int low, int high) 
{
    if (low < high) 
	{

        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / 4;

    cout << "Array before sorting: ";
    display(arr, n);

    quickSort(arr, 0, n - 1);

    cout << "Array after Quick Sort: ";
    display(arr, n);

    return 0;
}


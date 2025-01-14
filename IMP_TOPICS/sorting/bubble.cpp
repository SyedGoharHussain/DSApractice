#include <iostream>
using namespace std;

void bubble(int arr[], int n) 
{
    for (int i = 0; i < n - 1; i++) 
	{
        for (int j = 0; j < n - i - 1; j++) 
		{
            if (arr[j] > arr[j + 1]) 
			{
                swap(arr[j],arr[j+1]);
            }
        }
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

int main() {
    int arr[] = {5, 1, 4, 2, 8};
    int n = sizeof(arr) /4;

    cout << "Array before sorting: ";
    display(arr, n);

    bubbleSort(arr, n);

    cout << "Array after Bubble Sort: ";
    display(arr, n);

    return 0;
}


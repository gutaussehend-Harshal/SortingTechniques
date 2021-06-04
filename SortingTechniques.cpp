#include <bits/stdc++.h>
using namespace std;

// MergeSort -->

void merge(int arr[], int l, int mid, int h) 
{
  int i = l, j = mid + 1, k = l;
  int B[100];

  while(i <= mid && j <= h) 
  {
    if(arr[i] < arr[j]) 
    {
      B[k++] = arr[i++];
    }
    else 
    {
      B[k++] = arr[j++];
    }
  }

  while(i <= mid) 
  {
    B[k++] = arr[i++];
  }

  while(j <= h) 
  {
    B[k++] = arr[j++];
  }
  
  for(int i = l; i <= h; i++) 
  {
    arr[i] = B[i];
  }
}

void mergeSort(int arr[], int l, int h) 
{
  int mid;
  if(l < h) 
  {
    mid = (l + h) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, h);
    merge(arr, l, mid, h);
  }
}

// QuickSort -->

int partition(int arr[], int l, int h) 
{
  int pivot = arr[l];
  int i = l, j = h;

  do
  {
    do
    {
      i++;
    } while(arr[i] <= pivot);

    do
    {
      j--;
    } while(arr[j] > pivot);
    
    if(i < j) 
    {
      swap(arr[i], arr[j]);
    }
  } while(i < j);

  swap(arr[l], arr[j]);
  return j;
}

void quickSort(int arr[], int l, int h) 
{
  int j;
  if(l < h) 
  {
    j = partition(arr, l , h);
    quickSort(arr, l, j);
    quickSort(arr, j + 1, h);
  }
}

// SelectionSort -->

void selectionSort(int arr[], int n) 
{
  int i, j, k;  // k = min   min = i;
  for(i = 0; i < n - 1; i++) 
  {
    // cout << "No of passes: " << i + 1 << endl;
    for(j = k = i; j < n; j++) // Order of i,j,k should not change here.
    {
      // cout << "No of comparisons: " << j + 1 << endl;
      if(arr[j] < arr[k]) 
      {
        k = j;
      }
    }
    swap(arr[i], arr[k]);
  }
}

// InsertionSort -->

void insertionSort(int arr[], int n) 
{
  for(int i = 1; i < n; i++) 
  {
    int j = i - 1;
    int key = arr[i];
    // cout << "No of passes: " << i << endl;
    while(j > -1 && arr[j] > key) 
    {
      // cout << "No of comparisons: " << j << endl;
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}

// BubbleSort -->

void BubbleSort(int arr[], int n) 
{
  int flag;
  for(int i = 0; i < n - 1; i++) 
  {
    flag = 0;
    // cout << "No of passes: " << i + 1 << endl;
    for(int j = 0; j < n - 1 - i; j++) 
    {
      // cout << "No of comparisons: " << j + 1 << endl;
      if(arr[j] > arr[j+1]) 
      {
        swap(arr[j], arr[j+1]);
        flag = 1;
      }
    }
    if(flag == 0) 
    {
      break;
    }
  }
}

int main() 
{
  int arr[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3};
  // int arr[] = {8, 5, 7, 3, 2};
  int n = sizeof(arr)/sizeof(arr[0]);

  // BubbleSort(arr,n);
  // insertionSort(arr, n);
  // selectionSort(arr, n);
  // quickSort(arr, 0, n);
  // mergeSort(arr, 0, n - 1);

  for(int i = 0; i < n; i++) 
  {
    cout << arr[i] << " ";
  }


}
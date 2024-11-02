#include<iostream>
#include<algorithm>
using namespace std;


void print(int* arr,int size){
  for(int i = 0; i < size; i++){
    cout << *(arr + i) << " ";
  }
}

// Merge Sort
void merge(int* arr,int s,int e){
  int mid = (s+e)/2;

  int l1 = mid - s + 1;
  int l2 = e - mid;

  int* left = new int[l1];
  int* right = new int[l2];


  for(int i = 0; i < l1; i++){
    left[i] = arr[s+i];
  }
  
  for(int j = 0; j < l2; j++){
    right[j] = arr[mid + 1 + j];
  }

  int index1 = 0;
  int index2 = 0;
  while(index1 < l1 && index2 < l2){
    if(left[index1] < right[index2]){
      arr[s++] = left[index1++];
    }else{
      arr[s++] = right[index2++];
    }
  }

  while(index1 < l1){
    arr[s++] = left[index1++];
  }

  while(index2 < l2){
    arr[s++] = right[index2++];
  }

  delete[] left;
  delete[] right;
}



void mergeSort(int* arr,int s,int e){
  if(s >= e)
    return;

  int mid = (s+e)/2;
  mergeSort(arr,s,mid);

  mergeSort(arr,mid+1,e);


  merge(arr,s,e);
}


// Quick Sort
int partition(int* arr,int s,int e){
  int pivotElement = arr[s];
  int count = 0;

  for(int i = s+1; i <= e; i++){
    if(arr[i] <= pivotElement){
      count++;
    }
  }

  int rightPosition = s + count;
  swap(arr[s],arr[rightPosition]);
  int pivotIndex = rightPosition;

  int i = s;
  int j = e;
  while(i < pivotIndex && j > pivotIndex){
    if(arr[i] <= arr[pivotIndex]){
      i++;
    }else if(arr[j] > arr[pivotIndex]){
      j--;
    }else{
      swap(arr[i++],arr[j--]);
    }
  }
  return pivotIndex;
}

void quickSort(int* arr,int s,int e){
  if(s >= e)
    return;

  int p = partition(arr,s,e);

  quickSort(arr,s,p-1);

  quickSort(arr,p+1,e);
}




int main(){
  int arr[16] = {-2,4,3,9,-1,5,5,55,5,5,55,5,5,5,55,5};
  int size = 16;

  // merge sort
  int s = 0;
  int e = size - 1;

  mergeSort(arr,s,e);

  // quickSort(arr,s,e);


  print(arr,size);
}
#include<iostream>

void findPosition(int arr[], int k, int len) {
  int i = 0;
  int j = 0;
  while(arr[i] != k) {
    i++;
    j++;
  }
  while(arr[j] == k) {
    j++;
  }
  std::cout << i << " " << j-1;
}

int main(){
  int arr[] = {2, 2, 3, 4, 5, 6, 8, 8, 8};
  findPosition(arr, 2, 7);
  std::cout << std::endl;
  findPosition(arr, 8, 7);
  std::cout << std::endl;
  findPosition(arr, 5, 7);
  // int arr[] = {1};
  // findPosition(arr, 1, 1);
  return 0;
}
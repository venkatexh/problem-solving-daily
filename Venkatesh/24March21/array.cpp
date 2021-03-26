// Find all elements that appear more than n/k times

#include<iostream>
#include<unordered_map>

void findElements(int arr[], int k, int len) {
  int limit = len/k;
  std::unordered_map<int, int> map;
  
  for(int i = 0; i < len; i++) {
    map[arr[i]]++;
  }

  for(auto it : map) {
    if(it.second > limit) {
      std::cout << it.first << std::endl;
    }
  }
}

int main() {
  int arr[] = {2, 3, 4, 4, 2, 3, 4, 3, 8};
  findElements(arr, 4, 8);
  return 0;
}
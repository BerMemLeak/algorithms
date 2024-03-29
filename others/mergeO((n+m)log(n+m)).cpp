#import <iostream>
using namespace std;
#include <vector>
#include <algorithm>

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    for(int i = m; i < m + n; i++){
        nums1[i] = nums2[i - m];
    }
    std::sort(begin(nums1), end(nums1));
    for (int i : nums1) {
        cout << i << ' ';
    }
}
    
int main (){
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    int m = 3;
    int n = 3;

    merge(nums1,m,nums2,n);
    
    return 1;
}
//You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
//
//Merge nums1 and nums2 into a single array sorted in non-decreasing order.
//
//The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.


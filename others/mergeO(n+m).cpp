#import <iostream>
#import <vector>
#import <algorithm>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int first = 0;
    int sec = 0;
    int allMass = 0;
    vector<int> nums3;
    while (first < m && sec < n) {
        if (nums1[first] <= nums2[sec]) {
            nums3.push_back(nums1[first]);
            first++;
        }else {
            nums3.push_back(nums2[sec]) ;
            sec++;
        }
        allMass++;
    }
    while (first < m) {
        nums3.push_back(nums1[first]);
        first++;
    }
    while (sec < n) {
        nums3.push_back(nums2[sec]);
        sec++;
    }

    for (int i : nums3) {
        cout << i << ' ';
    }
}

int main (){
    vector<int> nums1 = {2,4,6,0,0,0};
    vector<int> nums2 = {1,3,5};
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


// Source : https://leetcode.com/problems/median-of-two-sorted-arrays/
// Author : Manoj A (ManojTGN)
// Date   : 2022-09-17

/***************************************************************************************************** 
 * Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
 * 
 * The overall run time complexity should be O(log (m+n)).
 * 
 * Example 1:
 *
 * Input: nums1 = [1,3], nums2 = [2]
 * Output: 2.00000
 * Explanation: merged array = [1,2,3] and median is 2.
 * 
 * Example 2:
 * 
 * Input: nums1 = [1,2], nums2 = [3,4]
 * Output: 2.50000
 * Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 * 
 * Constraints:
 * 
 * nums1.length == m
 * nums2.length == n
 * 0 <= m <= 1000
 * 0 <= n <= 1000
 * 1 <= m + n <= 2000
 * -106 <= nums1[i], nums2[i] <= 106
 ******************************************************************************************************/
#include <stdlib.h>
#include <stdio.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){

    double result = 0.0;
    unsigned short int index[3] = {0,0,0}; //i,j,s
    signed long int *sortedArray = malloc(sizeof(long)*(nums1Size+nums2Size));

    while(1){

        if(index[0] >= nums1Size && index[1] >= nums2Size)
            break;

        if(index[0] >= nums1Size){
            sortedArray[index[2]] = nums2[index[1]];
            index[1]++;
            index[2]++;
            continue;
        }else if(index[1] >= nums2Size){
            sortedArray[index[2]] = nums1[index[0]];
            index[0]++;
            index[2]++;
            continue;
        }

        if( nums1[index[0]] < nums2[index[1]] ){
            sortedArray[index[2]] = nums1[index[0]];
            index[0]++;
            index[2]++;
        }else if(nums1[index[0]] > nums2[index[1]]){
            sortedArray[index[2]] = nums2[index[1]];
            index[1]++;
            index[2]++;
        }else{
            sortedArray[index[2]] = nums1[index[0]];
            index[0]++;
            index[2]++;

            sortedArray[index[2]] = nums2[index[1]];
            index[1]++;
            index[2]++;
            
        }

    }
    

    result = index[2] % 2 == 0?(sortedArray[(index[2]-1)/2]+sortedArray[((index[2]-1)/2)+1])/2.0:sortedArray[(index[2]-1)/2];
    return result;
}

int main(){
    /*
    int num1[12] = {1,1,1,1,1,1,1,1,1,1,4,4};int *pnum1 = num1;
    int num2[11] = {1,3,4,4,4,4,4,4,4,4,4};int *pnum2 = num2;
    findMedianSortedArrays(pnum1,12,pnum2,11);
    */

    int num1[2] = {1,1};int *pnum1 = num1;
    int num2[2] = {1,2};int *pnum2 = num2;
    printf("%lf",findMedianSortedArrays(pnum1,2,pnum2,2));

    return 0;
}
/*
    for(int i = 0; i < (nums1Size+nums2Size); i++){
        printf("%d ",sortedArray[i]);
    }printf("length:%d result:%lf\n",saLength,result);
    
*/
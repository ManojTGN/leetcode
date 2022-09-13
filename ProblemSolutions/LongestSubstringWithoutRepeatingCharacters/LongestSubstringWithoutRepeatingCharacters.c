// Source : https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Author : Manoj A (ManojTGN)
// Date   : 2022-08-27

/***************************************************************************************************** 
 * Given a string s, find the length of the longest substring without repeating characters.
 * 
 * Example 1:
 * 
 * Input: s = "abcabcbb"
 * Output: 3
 * Explanation: The answer is "abc", with the length of 3.
 * 
 * Example 2:
 * 
 * Input: s = "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 * 
 * Example 3:
 * 
 * Input: s = "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3.
 * Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 * 
 * Constraints:
 *  0 <= s.length <= 5 * 104
 *  s consists of English letters, digits, symbols and spaces.
 ******************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int getsize(char *p){
    
    int length = 0;
    while( *p != '\0' ){
        p++;
        length++;
    }

    return length;
}

int isThere(char *str,char *substring){

}

int lengthOfLongestSubstring(char * s){
    unsigned short int length = getsize(s);
    unsigned short int max = 0;

    char *substring = malloc(length*sizeof(char));
    for(int i = 0; i< length; i++){substring[i] = '\0';}

    unsigned short int ssIndex = 0;
    for(int i = 0; i < length; i++){
    

    }

    return max;
}

void main(){
    char input[11] = "abcabcbb";
    char *ptr = input;
    printf("%d",lengthOfLongestSubstring(ptr));
}
//printf("%s %i -flag:%d -max:%d\n",substring,ssIndex,sameFlag,max);
// Source : https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Author : Manoj A (ManojTGN)
// Date   : 2022-09-17

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

int lengthOfLongestSubstring(char * s){

    unsigned short int max = 0;
    unsigned short int score = 0;
    unsigned short int isThereFlag = 0;
    unsigned short int length = getsize(s);

    for(int i = 0; i < length; i++){

        score = 0;
        for(int j = i; j < length;j++){
            
            isThereFlag = 0;
            for(int k = i; k < j; k++){
                if(s[k] == s[j]){ isThereFlag = 1;break; }
            }
            
            
            if(isThereFlag){
                if(score > max) max = score;
                score = 0;
                break;
            }else{
                score++;
            }
        }
        if(score > max) max = score;

    }

    return max;
}

void main(){
    char input[11] = " ";
    char *ptr = input;
    printf("%d",lengthOfLongestSubstring(ptr));
}
//printf("[string:%s] [i:%d j:%d] [score:%d max:%d] [isThere:%d]\n",s,i,j,score,max,isThereFlag);
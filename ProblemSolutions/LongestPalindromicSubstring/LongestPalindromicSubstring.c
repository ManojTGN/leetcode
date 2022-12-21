// Source : https://leetcode.com/problems/median-of-two-sorted-arrays/
// Author : Manoj A (ManojTGN)
// Date   : 2023-12-21

/***************************************************************************************************** 
 * Given a string s, return the longest palindromic substring in s.
 * 
 * A string is called a palindrome string if the reverse of that string is the same as the original string.
 * 
 * Example 1:
 * 
 * Input: s = "babad"
 * Output: "bab"
 * Explanation: "aba" is also a valid answer.
 * 
 * Example 2:
 * 
 * Input: s = "cbbd"
 * Output: "bb"
 * 
 * Constraints:
 * 
 * 1 <= s.length <= 1000
 * s consist of only digits and English letters.
 ******************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

char * slice(char * s, int start, int end){
    int i;
    char *substr = (char *) malloc( (end-start)+2 );
    
    for(i  = start; i < end+1; i++){
        *(substr + (i-start)) =  *(s + i);
    }   *(substr + (i-start)) = '\0';

    return substr;
}

void getPalindrome(char * s, int left, int right, char **substring, int *length){

    while( (left >= 0 && *(s+right) != '\0') && (*(s+left) ==  *(s+right)) ){
        
        if( *length < right-left + 1){
            *substring = slice(s,left,right);
            *length = right-left + 1;
        }

        right++;
        left--;
    }
}

char * longestPalindrome(char * s){
    if(*s == '\0'){ return s; }

    int len = 0; 
    int index = 0;
    char *substring;

    while(*(s+index) != '\0'){
        getPalindrome(s, index, index    , &substring, &len);
        getPalindrome(s, index, index + 1, &substring, &len);
        index++;
    }

    return substring;
}
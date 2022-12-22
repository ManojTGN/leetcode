// Source : https://leetcode.com/problems/two-sum/
// Author : Manoj A (ManojTGN)
// Date   : 2023-12-21

/***************************************************************************************************** 
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
 * 
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * And then read line by line: "PAHNAPLSIIGYIR"
 * 
 * Write the code that will take a string and make this conversion given a number of rows:
 * 
 * string convert(string s, int numRows);
 * 
 * 
 * Example 1:
 * 
 * Input: s = "PAYPALISHIRING", numRows = 3
 * Output: "PAHNAPLSIIGYIR"
 * Example 2:
 * 
 * Input: s = "PAYPALISHIRING", numRows = 4
 * Output: "PINALSIGYAHRPI"
 * Explanation:
 * P     I    N
 * A   L S  I G
 * Y A   H R
 * P     I
 * Example 3:
 * 
 * Input: s = "A", numRows = 1
 * Output: "A"
 *  
 * 
 * Constraints:
 * 
 * 1 <= s.length <= 1000
 * s consists of English letters (lower-case and upper-case), ',' and '.'.
 * 1 <= numRows <= 1000
 ******************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void print(char *s){
    while( *s != '\0'){ printf("%c",*s);s++; }
}

int len(char * s){
    int length = 0;
    while( *s != '\0'){ length++; s++; }
    return length;
}

char * convert(char * s, int numRows){
    int length = len(s);
    char *ptr = (char *) malloc(length * sizeof(char));

    for(int i = 0; i< length; i++){
        *(ptr+i) = *(s+ i*(numRows+numRows/2));
    }

    return ptr;
}

int main(){
    char arr[15] = "PAYPALISHIRING\0";
    char *s = arr;

    print(convert(arr, 3));
    return 0;
}
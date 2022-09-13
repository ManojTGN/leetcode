// Source : https://leetcode.com/problems/add-two-numbers/
// Author : Manoj A (ManojTGN)
// Date   : 2022-08-27

/***************************************************************************************************** 
 * You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
 *
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 *
 * Example 1:
 *  
 *  (https://assets.leetcode.com/uploads/2020/10/02/addtwonumber1.jpg) 
 * 
 * Input: l1 = [2,4,3], l2 = [5,6,4]
 * Output: [7,0,8]
 * Explanation: 342 + 465 = 807.
 *
 * Example 2:
 *
 * Input: l1 = [0], l2 = [0]
 * Output: [0]
 *
 * Example 3:
 *
 * Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
 * Output: [8,9,9,9,0,0,0,1]
 *
 *
 * Constraints:
 *
 * The number of nodes in each linked list is in the range [1, 100].
 * 0 <= Node.val <= 9
 * It is guaranteed that the list represents a number that does not have leading zeros.
 ******************************************************************************************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void printValue(struct ListNode tmp){

    while(1){
        printf("%d",tmp.val);
        if(tmp.next == NULL || !tmp.next) return;
        tmp = *tmp.next;
    }
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){

    struct ListNode *head = malloc(sizeof(struct ListNode ));
    struct ListNode *end = head;

    head->val = 0;
    head->next = NULL;

    short unsigned int sum;
    short unsigned int carryFlag = 0;
    while(1){
        if(l1 != NULL && l2 != NULL) sum = (l1->val + l2->val) + carryFlag;
        else if (l1 != NULL && l2 == NULL) sum = (l1->val +      0 ) + carryFlag;
        else if (l1 == NULL && l2 != NULL) sum = ( 0      + l2->val) + carryFlag;
        else sum = carryFlag; 

        end->val = sum%10;
        carryFlag = (sum/=10)%10;

        if(l1 != NULL) l1 = l1->next;
        if(l2 != NULL) l2 = l2->next;
        if(l1 == NULL && l2 == NULL && carryFlag == 0){
            end->next = NULL;
            break;
        }
        

        end->next = malloc(sizeof(struct ListNode ));
        end = end->next;
    }

    return head;
}

void main(){
    /*
    struct ListNode n1,n2,n3; n1.val = 2;n2.val = 4;n3.val = 3; n1.next = &n2;n2.next = &n3;n3.next = NULL;
    struct ListNode m1,m2,m3; m1.val = 5;m2.val = 6;m3.val = 4; m1.next = &m2;m2.next = &m3;m3.next = NULL;
    */

    /*
    struct ListNode n1; n1.val = 0; n1.next = NULL;
    struct ListNode m1; m1.val = 0; m1.next = NULL;
    */

    struct ListNode n1; n1.val = 9; n1.next = NULL;
    struct ListNode m1,m2,m3,m4,m5,m6,m7,m8,m9,m10; 
    m1.val = 1;m2.val = 9;m3.val = 9;m4.val = 9;m5.val = 9;m6.val = 9;m7.val = 9;m8.val = 9;m9.val = 9;m10.val = 9;
    m1.next=&m2; m2.next=&m3; m3.next=&m4; m4.next=&m5; m5.next=&m6; m6.next=&m7; m7.next=&m8; m8.next=&m9; m9.next=&m10; m10.next= NULL;

    struct ListNode *ls = addTwoNumbers(&n1,&m1);
    printValue(*ls);
}
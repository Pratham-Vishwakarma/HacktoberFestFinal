// Distribute Money to Maximum Children

// You are given an integer money denoting the amount of money (in dollars) that you have and another integer children denoting the number of children that you must distribute the money to.

// You have to distribute the money according to the following rules:

// All money must be distributed.
// Everyone must receive at least 1 dollar.
// Nobody receives 4 dollars.
// Return the maximum number of children who may receive exactly 8 dollars if you distribute the money according to the aforementioned rules. If there is no way to distribute the money, return -1.

 

// Example 1:

// Input: money = 20, children = 3
// Output: 1
// Explanation: 
// The maximum number of children with 8 dollars will be 1. One of the ways to distribute the money is:
// - 8 dollars to the first child.
// - 9 dollars to the second child. 
// - 3 dollars to the third child.
// It can be proven that no distribution exists such that number of children getting 8 dollars is greater than 1.
// Example 2:

// Input: money = 16, children = 2
// Output: 2
// Explanation: Each child can be given 8 dollars.
 

// Constraints:

// 1 <= money <= 200
// 2 <= children <= 30
#include<stdio.h>

int distMoney(int money, int children) {
    int A[children], i, remain, count=0;
    for(i=0; i<children;i++){
        A[i]=1;
    }
    remain=money-children;
    for(i=0;i<children;i++){
        if(remain>=7){
            A[i]=8;
            remain=remain-7;
        }
        else{
            A[i]=A[i]+remain;
        }
    }
    for(i=0;i<children;i++){
        if(A[i]==4){
            A[i-1]=9;
            A[i]=A[i]-1;
        }
    }
    for(i=0;i<children;i++){
        if(A[i]==8){
            count++;
        }
    }
    printf("%d", count);

}

int main(){
    int money,children;
    printf("Enter Money: ");
    scanf("%d",&money);
    printf("Enter Children: ");
    scanf("%d", &children);
    distMoney(money,children);
}
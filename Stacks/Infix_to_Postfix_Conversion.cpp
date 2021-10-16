/*
Given an INFIX expression, we need to convert it to POST-FIX expression and print out the same.

Algorithm : To do this, we will create a Stack to store
the operators and '(' character entered in the expression by the user to Stack[top] location
while the operands will be printed out right away and won't be stored in the Stack in order to get the correct POST-FIX expression.
*/

#include<iostream>
#include<cwctype>
using namespace std;

//creating an array to use it as a Stack
//and initializing integer 'top' to -1 to use it to navigate in the stack
char Stack[50];
int top = -1;

//creating a PUSH function that accepts character as parameter 
//and adds it to the Stack whilst incrementing the 'top' to the next location in Stack
void push(char a)
{
    top++;
    Stack[top] = a;
}

//POP function that return the value stored at the location at which 'top' is at in the Stack, i.e. Stack[top],
//or returns -1 if the Stack is empty, i.e top = -1
char pop()
{
    char val;

    if( top == -1 )
        return -1;
    else
    {
        val = Stack[top];
        top -= 1;
        return val;
    }
}

//PRECEDENCE function that accepts a character as parameter 
//this function defines a level of precedence for the character entered
//to help decide whether to PUSH or POP the character further in the program
int precedence(char a)
{
    if( a == '(' )
        return 0;
    if( a == '-' || a == '+' )
        return 1;
    if( a == '/' || a == '*' )
        return 2;
    return 0;
}

int main()
{
    //declaring an array expression of size 100 bytes
    //a character pointer exp and a character z
    char expression[100];
    char *exp, z;

    //Inputting the expression from the user
    cout<<endl<<"Enter the expression : ";
    cin>>expression;

    exp = expression;

    cout<<endl<<"Post-Fix Expression is : ";
    //this while loop keeps iterating until value in *exp becomes \0 (NULL)
    while( *exp != '\0' )
    {
        //checking if the value in '*exp' is 'alphanumeric' by CALLING the 'iswalnum()' function from cwctype library 
        //and if yes, then printing it out
        if( iswalnum(*exp) )
            cout<<*exp;
        
        //checking if the value in *exp is '(' 
        //and if yes then CALLING the PUSH function on *exp
        //to add '(' to the Stack
        else if( *exp == '(' )
            push( *exp );
        
        //checking if the value in *exp is ')' 
        //and if yes, then running a WHILE Loop 
        else if( *exp == ')' )
        {
            
            //this WHILE Loop has a condition which first CALLS the POP function and 
            //returns the value to 'z' character , then compares if it is '('
            //If 'z' is NOT equal to '(' then it prints out the value of z 
            //and loop keeps running until it finds '(' in the Stack or till Stack gets empty
            while( (z = pop()) != '(' )
            {
                cout<<z;
            }
        }
    
        //this ELSE condition is used when the '*exp' has an 'operator' value in it and runs a WHILE LOOP
        //which checks if the *exp's precedence is equal to or less than the present element on top of the stack
        //if yes, then it CALLS the POP function and prints out the returned value, i.e Stack[top]
        //and once the loop ends then it CALLS the PUSH function on the *exp and adds it to the TOP of the Stack
        else
        {
            while(precedence(Stack[top]) >= precedence( *exp ))
            {
                cout<<pop();
            }

            push( *exp );
        }

        //incrementing 'exp' by 1 to perform and check conditions on next operand or operator in the expression
        exp++;
    }

    //this WHILE Loop calls the POP function and prints out the returned value 
    //and keeps running until the Stack is empty, i.e top = -1.
    //This loop is used to print all the remaining elements in the Stack.
    while(top != -1)
    {
        cout<<pop();
    }

    return 0;
}

/*
Time Complexity : O(n^2)
Space Complexity : O(n)


Test Case 1 :-
Input:
Enter the expression : (((a+b)/2)-d)
Output:
Post-Fix Expression is : ab+2/d-

Test Case 2 :-
Input:
Enter the expression : z+(j*k-(e*f+i)/2)*h
Output:
Post-Fix Expression is : zjk*ef*i+2/-h*+
*/
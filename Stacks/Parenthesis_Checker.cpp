// C++ code to check balanced parenthesis

#include
#include //to use strlen(), we need to include this header
using namespace std;
char st[20];
int top=-1;

void push(char a)
{
st[++top]=a;
}
char pop()
{
return st[top–];
}

int main()
{
char a[20],t;
int i,f=1;
cout<<“Enter the String: “;
cin>>a;
for(i=0;i<strlen(a);i++)
{
if(a[i]=='(‘ || a[i]=='{‘ || a[i]=='[‘)
push(a[i]);
if(a[i]==’)’ || a[i]==’}’ ||a[i]==’]’)
{
if(top==-1)
f=0;
else
{
t=pop();
if(a[i]==’)’ && (t=='[‘ || t=='{‘))
f=0;
if(a[i]==’}’ && (t=='(‘ || t=='[‘))
f=0;
if(a[i]==’]’ && (t=='{‘ || t=='(‘))
f=0;
}
}
}
if(top>=0)
f=0;
if(f==0)
cout<<“Unbalanced”;
else
cout<<“Balanced”;
return 0;
}


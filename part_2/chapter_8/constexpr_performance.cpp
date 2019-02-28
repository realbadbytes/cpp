#include<iostream> 

using namespace std; 
  
long int fib(int n) 
{ 
    return (n <= 1)? n : fib(n-1) + fib(n-2); 
} 
  
int main () 
{ 
    // value of res is computed at runtime.  
    long int res = fib(45); 
    cout << res; 
    return 0; 
} 

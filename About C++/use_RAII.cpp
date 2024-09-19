/* Resource Acquisition Is Initialization */

#include <iostream>  

class T {  
public:  
  T() { puts("T()"); }  
  ~T() { puts("~T()"); }  
};  

int main()  
{  
  puts("before scope");  

  {  
    T t;  
  }    // use RAII to destruct object  

  puts("after scope");  
  // t = {};    // error  
}  

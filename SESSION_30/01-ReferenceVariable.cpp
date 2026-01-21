/* 
    This program illustrates the creation of reference variable 
    as a facility to create an alias to an existing memory block. 

    It does not cover application use-case. 
*/
#include<iostream>

int main(void)
{
    int n = 100; // on stack frame of main(), 4 bytes will be allocated, initialized to 100. 
                // n is a name given to 4 byte integer instance allocated on stack frame of main()

    // We can create an alternate name to aforementioned 4 bytes 
    int& ref = n;  //ref variable in inside is nothing but const pointer i.e.(int* const ref)

    // Once you have attached a referene variable to a memory block 
    // then you can access the block through the reference variable 
    
    //  All such accesses to that block happening through the 
    //  reference variabls are identical to accesses to the block 
    //  happening through an instance variable if there were one present. 
    return 0;
}
/* 
General Syntax: 
T& ref_Var_Name = EXPRESSION_WHICH_EVALUATES_TO_AN_OBJECT_OF_TYPE_T; 

T var;  // var is an instance of T       
T* p;   // p is a pointer to T 
T& ref = expression_depicting_object_of_T; // ref is a reference to T 

*/
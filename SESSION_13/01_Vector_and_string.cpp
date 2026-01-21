#include<iostream>
#include<string>
#include<vector>

using std::cout;
using std::endl;
using std::vector;
using std::string;

void string_demo(void);
void vector_demo(void);

int main(void)
{
    string_demo();
   // vector_demo();
    return 0;
}

void string_demo(void)
{
    string s1;
    string s2("hello");
    string s3(s2);

    cout<<" s1:"<<s1<<endl; //empty
    cout<<" s2:"<<s2<<endl; //hello
    cout<<" s2:"<<s3<<endl; //hello
    cout<<" addr(s2):"<< &s2 << endl;
    cout<<" addr(s3):"<< &s3 << endl;
    cout<<" contents of s2 and s3 are same but not address , this proves that s3 is clone of s2"<<endl;

    for(string::size_type i = 0; i!=s2.size(); ++i)
    {
        cout<<"s2["<< i << "]" << s2[i] << endl;
    }
    cout<< "METHOD 1 End";

    cout<< "------String DEMO End-------";
}

void vector_demo(void)
{

}
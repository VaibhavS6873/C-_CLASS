#include<iostream>
#include<string>

using std::cout;
using std::endl;
using std::string;

void string_iterator_demo(void);

int main(void)
{
    string_iterator_demo();
    return 0;
}

void string_iterator_demo(void)
{
    string s("ABCDE");
    //1:using iterator and while
    string::iterator itr = s.begin();
    while(itr!= s.end())
    {
        cout<<"current char:"<<*itr<<endl;
        ++itr;
    } 

    //2:repeate 2
    string::iterator itr_1 = s.begin();
    while(itr_1!= s.end())
    {
        cout<<"current char:"<<*itr_1<<endl;
        itr_1++;
    }

    //3:repeate 3
    string::iterator itr_2 = s.begin();
    while(itr_2!=s.end())
    {
        cout<<"current char:"<<*itr_2<<endl;
        itr_2 = itr_2 + 1;
    }


    //1:for loop
    for(string::iterator itr_1 = s.begin() ; itr_1!=s.end(); itr_1++)
    {
        cout<<"*itr_1:"<<*itr_1<<endl;
    }

    //2:repeat 2
    for(string::iterator itr_2 = s.begin(); itr_2!=s.end(); ++itr_2)
    {
        cout<<"*itr_2:"<<*itr_2<<endl;
    }

    //3:repeate 3
    for(string::iterator itr_3 = s.begin(); itr_3!=s.end(); itr_3=itr_3+1)
    {
        cout<<"*itr_3:"<<*itr_3<<endl;
    }
}
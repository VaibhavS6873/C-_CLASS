#include<iostream>
#include<string>
#include<vector>

using std::cout;
using std::endl;
using std::string;
using std::vector; //vector is a class template defined in std namespace(header->vector)

class Date
{
    private:
        int day,month,year;
    public:
        Date(int init_day, int init_month, int init_year)
        {
            day = init_day;
            month = init_month;
            year = init_year;
        }

        void show()
        {
            cout<<day<<"/"<<month<<"/"<<year;
        }
};

void vector_demo(void);

int main(void)
{
    vector_demo();
    return 0;
}

void vector_demo(void)
{
    //vector of ints
    vector<int> ivec1;
    vector<int> ivec2{10,20,30,40,50};
    vector<int> ivec3(ivec2);
    vector<int> ivec4(5);
    vector<int> ivec5(5,100);

    //Traverese through all the vectors
    //ivec2: method:index
    cout<<"ivec2 iteration: index method";
    for(vector<int>::size_type i = 0; i!=ivec2.size(); i++)
    {
        cout<<"ivec2["<<i<<"]:"<<ivec2[i]<<endl;
    }

    cout<<"ivec2 iteration: iterator method";
    for(vector<int>::iterator it = ivec2.begin(); it!=ivec2.end(); ++it)
    {
        cout<<"*it"<<*it<<endl;
    }

    //similer do for other vectors;

    //vector of floats
    vector<float>f_vec1;
    vector<float>f_vec2{1.1f, 2.2f, 5.6f, 6.6f, 4.4f};
    vector<float>f_vec3(f_vec2);
    vector<float>f_vec4(5); // vector of floats with pre-allocation for 5 floats 
                             // those 5  floats should ideally be 0.0f but 
                            // cannot be guarenteed on all implementations
    vector<float>f_vec5(5, 5.5f); // vector of floats with pre-allocation for 5 floats 
                                // each of them initialized to 5.5f (guaranteed)

    cout<<"f_vec2 iteration: index method";
    for(vector<float>::size_type i = 0; i!=f_vec2.size(); i++)
    {
        cout<<"f_vec2["<<i<<"]:"<<f_vec2[i]<<endl;
    }
                            
    cout<<"f_vec2 iteration: iterator method";
    for(vector<float>::iterator it = f_vec2.begin(); it!=f_vec2.end(); ++it)
    {
        cout<<"*it"<<*it<<endl;
    }
    //do same for other vectors

    //vector of string
    vector<string>str_vec1;
    vector<string>str_vec2{string("hello"),string("world"), string("iterator"), string("amazing!")};
    vector<string>str_vec3(str_vec2);
    vector<string>str_vec4(5);
    vector<string>str_vec5(5, string("one"));

    cout<<"str_vec2 iteration: index method";
    for(vector<string>::size_type i = 0; i!=str_vec2.size(); i++)
    {
        cout<<"str_vec2["<<i<<"]:"<<str_vec2[i]<<endl;
    }
                            
    cout<<"2 iteration: iterator method";
    for(vector<string>::iterator it = str_vec2.begin(); it!=str_vec2.end(); ++it)
    {
        cout<<"*it"<<*it<<endl;
    }

    //vector of class

    vector<Date>date_vec1;
    vector<Date>date_vec2{
        Date(8,12,2014),
        Date(4,5,2028),
        Date(5,6,1999)
    };

    cout<<"date_vec2 iteration: index method"<<endl;

    for(vector<Date>::size_type i =0; i!=date_vec2.size();i++)
    {
        date_vec2[i].show();
    }

    for(vector<Date>::iterator it = date_vec2.begin(); it!=date_vec2.end(); ++it)
    {
      (*it).show();
    }
}
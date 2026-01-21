#include<iostream>
#include<stdexcept>
#include<cstdlib>
#include<CString>

class Date
{
    private:
        int day, month, year;

        static bool isValidInstance(int _dd, int _mm, int _yy)
        {
            return true;
        }

        public:
            Date() : day(1), month(1), year(1970)
            {

            }

            Date(int dd, int mm, int yy)
            {
                if(!isValidInstance(dd, mm, yy))
                   throw std::domain_error("invalid date values");

                this->day = dd;
                this->month = mm;
                this->year = yy;
            }

            Date(const char* dateStr)
            {
                std::size_t length = strlen(dateStr);
                char* tmpStr = (char*)malloc(length+1);
                memcpy((void*)tmpStr, (void*)dateStr, length+1);
                char* sep = "/";

                int dd = atoi(strtok(tmpStr, sep));
                int mm = atoi(strtok(NULL, sep));
                int yy = atoi(strtok(NULL, sep));

                if(!isValidInstance(dd,mm,yy))
                    throw std::domain_error("invalid date values");

                this->day = dd;
                this->month = mm;
                this->year = yy;

                free(tmpStr);
                tmpStr = NULL;
            }

            void show() const
            {
                std::cout<<day<<"/"<<month<<"/"<<year<<std::endl;
            }
};

int main(void)
{
     Date myDate1(1, 1, 2023);
     Date myDate2("29/04/2023");
     Date myDate3;

     myDate1.show();
     myDate2.show();
     myDate3.show();

     return 0;
}
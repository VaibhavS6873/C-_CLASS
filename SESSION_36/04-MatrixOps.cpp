#include<cstdio>
#include<cstdlib>
#include<cassert>

class Matrix
{
    private:
        int* pMat;
    public:
        Matrix()
        {
            pMat = (int*)malloc(3*3*sizeof(int));
            assert(pMat);
            for(int i = 0; i < 3; ++i)
            {
                for(int j = 0; j<3; ++j)
                {
                    if(i == j)
                        *(pMat + i*3 +j) = 1;
                    else
                        *(pMat + i*3 +j) = 0;
                }
            }
        }

        void show(const char* msg = 0)
        {
            if(msg)
                puts(msg);
            for(int i = 0; i < 3; ++i)
            {
                for(int j = 0; j < 3; j++)
                {
                    printf("m[%d][%d] = %d\n", i, j, *(pMat + i*3 + j));
                }
            }
        }

        Matrix operator+(const Matrix &other)const
        {
            Matrix sum;
            for(int i = 0; i < 3; i++)
            {
                for(int j = 0; j < 3; ++j)
                    *(sum.pMat + i*3 + j) = *(this->pMat + i*3 + j) + *(other.pMat + i*3 + j);
            }
            return sum;
        }

        Matrix operator-(const Matrix &other)const
        {
            Matrix sub;
            for(int i = 0; i < 3; i++)
            {
                for(int j = 0; j < 3; j++)
                {
                    *(sub.pMat + i*3 + j) = *(this->pMat + i*3 + j)- *(other.pMat + i*3 +j);
                }
            }
            return sub;
        }

        void release()
        {
            if(pMat)
                free(pMat);
                pMat = 0;
        }
};

void test(void);

int main(void)
{
    test();
    puts("Application terminated successfully");
    return 0;
}

void test(void)
{
    Matrix m1,m2;
    Matrix sum = m1+m2; //m1.operator+(m2) //Matrix::operator+(&m1,m2)

    m1.show("showing m1:"); //Matrix::show(&m1,"showing m1:");
    m2.show("showing m2:"); //Matrix::show(&m2,"showing m2:");
    sum.show("showing sum:"); //Matrix::show(&sum,"showing sum:");

    m1.release(); //Matrix::release(&m1);
    m2.release(); //Matrix::release(&m2);
    sum.release(); //matrix::release(&sum);
}


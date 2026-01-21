extern int num;
extern test_function(void);

int main(void)
{
    num = 100;
    test_function();

    return 0;
}
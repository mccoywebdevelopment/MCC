#include <iostream>
int sample1();
void sample();
using namespace std;
int main()
{
    sample();
}
int sample1()
{
    int one;
    int *pc;
    int list[5];

    list[0]=11;
    list[1]=22;
    list[2]=33;
    list[3]=44;
    list[4]=55;
    one=1;
    pc=&one;

    cout<<one<<endl;
    cout<<&one<<endl;
    cout<<pc<<endl;
    cout<<&pc<<endl;
    cout<<*pc<<endl;

    return 0;
}

int* test (int a[5], int b[5])
{
    int *c = new int[5];
    for (int i = 0; i < 5; i++) c[i] = a[i]+b[i];
    return c;
}
}

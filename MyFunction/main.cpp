#include "futility.h"
#include <iostream>


using namespace std;
using namespace binaire;

void modf(bool &test)
{
    test = true;
}

class A
{
public:
    A() = default;
    virtual ~A() = default;
    void modf(bool &test)
    {
        test = true;
    }
};

int main()
{
    bool work(false);
    auto test1 = make_Function([](bool &test){
        test = true;
    });
    IFunction<void, bool &> &_test1 = test1;
    _test1(work);
    cout << "Test 1 " << (work ? "Sucess" : "fail") << endl;
    work = false;

    auto test2 = make_Function(modf);
    IFunction<void, bool &> &_test2 = test2;
    _test2(work);
    cout << "Test 2 " << (work ? "Sucess" : "fail") << endl;
    work = false;

    A b;
    auto test3 = make_Function(&b, &A::modf);
    IFunction<void, bool &> &_test3 = test3;
    _test3(work);
    cout << "Test 3 " << (work ? "Sucess" : "fail") << endl;
    work = false;


    return 0;
}

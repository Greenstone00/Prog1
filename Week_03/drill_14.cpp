#include "std_lib_facilities.h"

class B
{
    public:
    virtual void pvf() = 0;
};


class B1 : public B
{
    public:
    virtual void vf(){ cout << "B1::vf()" << endl; }
    void f() { cout << "B1::f()" << endl; }
    void pvf() override { cout << "B1::pvf()" << endl; };

};


class D1 : public B1
{
    public:
    void vf() override { cout << "D1::vf()" << endl; }
    void f() { cout << "D1::f()" << endl; }
    void pvf() override { cout << "D1::pvf()" << endl; };

};


class D2 : public D1
{
    public:
    void pvf() override { cout << "D2::pvf()" << endl; };
};


class B2
{
    public:
    virtual void pvf() = 0;
};



struct D21 : B2
{

    void pvf() override { cout << str << endl; }
    private:
    string str = "D21::pvf()";
};



struct D22 : B2
{
    void pvf() override { cout << "value of the string --> " << i << endl; }
    private:
    int i = 139;
};




void f(B2& b2ref)
{ 
    b2ref.pvf();
}




int main() 
try {


B1 b1;
D1 d1;
B1& b1_ref = d1;
D2 d2;
D21 d21;
D22 d22;


//1es
b1.vf();
b1.f(); 
b1.pvf();

//2es
d1.vf();
d1.f();
d1.pvf();

//3as
b1_ref.vf();
b1_ref.f();
b1_ref.pvf();

//6os
d2.vf();
d2.f();
d2.pvf();

//7es
f(d21);
f(d22);


return 0;



} catch(exception& e) {
    cerr << e.what() << endl;
} catch(...) {
    cerr << "Something went wrong..." << endl;
}


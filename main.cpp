#include <iostream>
struct A{
    virtual void f() = 0;
};

struct B: A{
    virtual void f() override{
        std::cout<< 1;
    }
};

struct C:B{
    int a;
};

int main() {
  B rb;
  C rc;
  rc.f();



}

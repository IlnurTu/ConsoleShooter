#include <iostream>
struct A{
    virtual void f() = 0;
};
struct B: A{
   void f() override{
       std::cout<<"Hello";
   }
   void g(){
       std::cout<<"HI";
   }
};
int main() {
    A* pb = new B;
    dynamic_cast<B*>(pb)->g();
}

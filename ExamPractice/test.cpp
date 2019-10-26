#include <iostream>
#include "string.h"
using namespace std;
class A {
  public:
      A(char* = "Kalin", int = 5);
      ~A();
      A(const A&);
      A& operator=(const A&);
      void print() const;
   private:
      char* name;
      int x;
};

A::A(char* st, int y) {
   cout  << "A(" << st << ", " << y << ")\n";
   name = new char[strlen(st)+1];
   //assert(name != NULL);
   strcpy(name, st);
   x = y;
}

A::~A() {
 cout << "~A(" << name << ", " << x << ")\n";
 delete [] name;
}

A::A(const A& st) {
   cout << "A(const A&)\n";
   name = new char[strlen(st.name)+1];
   //assert(name!=NULL);
   strcpy(name, st.name);
   x = st.x;
}

A& A::operator=(const A& st) {
   cout << "A::operator=()\n";
   if (this != &st) {
      delete name;
      name = new char[strlen(st.name)+1];
      strcpy(name, st.name);
      x = st.x;
   }
   return *this;
}

void A::print() const {
  cout << name << ", " << x;
}

class B {
  public:
       B(int, A);
        ~B();
       B(const B&);
       B& operator=(const B&);
       void print() const;
   private:
      int x;
      A a;
};

B::B(int d, A e) : a(e) {
    cout << "B::B(d, e)\n";
    x = d;
}
B::~B() {
   cout << "~B(" << x << ", ";
   a.print(); cout << ")\n";
}
B::B(const B& p) {
   cout << "B::B(const B&)\n";
   x = p.x;
   a = p.a;
}
B& B::operator=(const B& p) {
    cout << "B::operator=()\n";
    if (this != &p)  {
       x = p.x;
       a = p.a;
    }
    return *this;
}
void B::print() const {
   cout << x << endl;
   a.print(); cout << endl;
}

int main() {
   A a1("Ivan", 1), a2("Ana");
   B b1(4, a1), b2(2, a2), b3(b2);
   b1.print();
   b2.print();
   b3.print();
   b3 = b1;
   b3.print();
   return 0;
}


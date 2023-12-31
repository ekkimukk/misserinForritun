#include <iostream>
#include <string>
using namespace std;

class COne {
  int n_;
  string s_;

public:
  // Конструктор умолчания
  COne() : n_(0), s_("") {}

  // Конструктор с параметром
  COne(int n, string s) : n_(n), s_(s) {}

  // Конструктор копирования
  COne(const COne &arg) : n_(arg.n_), s_(arg.s_) {}

  // Деструктор
  ~COne() { cout << "COne deleted." << endl; }

  // Перегруженный оператор присваивания
  COne operator=(COne arg) {
    n_ = arg.n_;
    s_ = arg.s_;
    return *this;
  }

  // Методы доступа
  int get_n() { return n_; }

  string get_s() { return s_; }

  void set_n(int n) { n_ = n; }

  void set_s(string s) { s_ = s; }

  // Метод print()
  void print() {
    cout << "n = " << n_ << endl;
    cout << "s = " << s_ << endl;
  }
};

class CTwo {
  string s_;
  COne p_;

public:
  // Конструктор умолчания
  CTwo() : s_(""), p_() {}

  // Конструктор с параметром
  CTwo(string s, const COne &arg) : s_(s), p_(arg) {}

  // Конструктор копирования
  CTwo(const CTwo &arg) : s_(arg.s_), p_(arg.p_) {}

  // Деструктор (не нужен)

  // Перегруженный оператор присваивания
  CTwo operator=(CTwo arg) {
    s_ = arg.s_;
    p_ = arg.p_;
    return *this;
  }

  // Методы доступа
  string get_s() { return s_; }

  COne get_p() { return p_; }

  void set_s(string s) { s_ = s; }

  void set_p(COne p) { p_ = p; }

  // Метод print()
  void print() {
    cout << "s = " << s_ << endl;
    p_.print();
  }
};

int main(int argv, char *argc[]) {
  cout << "ПРОВЕРКА COne" << endl;
  cout << "Конструктор умолчания" << endl;
  COne cls1;
  cls1.print();

  cout << "Конструктор с параметром" << endl;
  COne cls2(13243546, "Text");
  cls2.print();

  cout << "Конструктор копирования" << endl;
  COne cls3(cls2);
  cls3.print();

  cout << "Перегруженный оператор присваивания" << endl;
  cls3 = cls1;
  cls3.print();

  cout << "Методы доступа" << endl;
  cls3.set_n(777);
  cls3.set_s("OTHER");
  cls3.print();

  cout << endl;
  cout << "ПРОВЕРКА CTwo" << endl;
  cout << "Конструктор умолчания" << endl;
  CTwo cls4;
  cls4.print();

  cout << "Конструктор с параметром" << endl;
  CTwo cls5("Rejkyavik", cls3);
  cls5.print();

  cout << "Конструктор копирования" << endl;
  CTwo cls6(cls5);
  cls6.print();

  cout << "Перегруженный оператор присваивания" << endl;
  CTwo cls7 = cls6;
  cls7.print();

  cout << "Методы доступа" << endl;
  cls7.set_s("Iceland");
  cls7.set_p(cls2);
  COne cls8 = cls7.get_p();
  cout << "s = " << cls7.get_s() << endl;
  cls8.print();

  return 0;
}

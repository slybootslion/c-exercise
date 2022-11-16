#include <iostream>
#include <cstring>
using namespace std;

namespace Diy {
  class Student {
   public:
    char *name;
    int age;
    float score;
   public:
    void say() const {
      printf("%s的年龄是 %d，成绩是 %f\n", name, age, score);
    }
  };
}

int main() {
  Diy::Student stu1;
//  strcpy(stu1.name, "zhangsan");
  stu1.age = 15;
  stu1.score = 92.5f;
  stu1.say();

  return 0;
}

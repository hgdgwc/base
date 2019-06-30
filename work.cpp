
#include <list>
#include <iostream>
#include <string.h>

using namespace std;


class student {
    public:
      int age;
      char name[30];
};




int main(int argc, char const *argv[])
{
        std::cout;
    //std::endl;
    list<student> data;
    student s1,s2,s3;
    s1.age = 16;
    strcpy(s1.name,"lihua");

    s2.age = 18;
    strcpy(s2.name,"zhangsan");

    s3.age = 20;
    strcpy(s3.name,"wangwu");

    data.push_back(s1);
    data.push_back(s2);
    data.push_back(s3);

    cout << "name " << "age" << endl;
    //
    
    //cout << data.size << endl;
    //cout << data.begin << endl;
   // cout << data.end << endl;

    
    return 0;
}


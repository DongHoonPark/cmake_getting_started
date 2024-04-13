#include <iostream>
#include "happy.h" // It needs header file!
int main(void)
{
    auto happy = new HappyFoo();
    std::cout<<"My happiness is "<<happy->happiness<<std::endl;
}
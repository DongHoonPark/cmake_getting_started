#include <iostream>
#include "foo.h"

int main(void)
{
    auto foo = AwesomeFoo();
    foo.addValue(10);

    std::cout<<foo.value<<std::endl;
}
#include <iostream>
#include <vector>
#include <string>


using std::vector;

typedef std::string string;

int main(void)
{
    std::vector<int> v{1, 2, 3};
for (typedef int Foo; Foo f : v)
//   ^^^^^^^^^^^^^^^ init-statement
{
    (void)f;
}

}
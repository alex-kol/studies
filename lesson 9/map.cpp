#include <iostream>
#include <string.h>
#include "map.h"

using namespace std;

int main()
{
    Map map;

    map.inputInMap("hello", 11);
    map.inputInMap("world", 15);
    map.inputInMap("my", 35);

    cout<<map.getOfMap("hello")<<endl;
    cout<<map.getOfMap("my")<<endl;

    return 0;
}

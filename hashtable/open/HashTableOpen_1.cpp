#include <iostream>
#include "Hashtable.h"
int main()
{
    srand(time(0));
    Hashtable ht;
    ht.generate(100, 0, 50);
    ht.print();

    ht.add(228);
    ht.add(65764);

    ht.add(65561);
    ht.deleteValue(25);

    ht.deleteHash(4);

    std::cout << "\n";
    ht.print();
}

#include <iostream>
#include "BinaryTree.h"
using namespace std;

int main()
{
    srand(time(0));
    Binarytree bt;
    bt.generate(10, 0, 10);
    cout << bt.print() <<" - size\n\n";

    int toDelete;
    while (true) {
        cin >> toDelete;
        bt.removeNode(toDelete);
        cout << bt.print() << " - size\n\n";
    }
}

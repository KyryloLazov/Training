#include <iostream>
#include <string>
#include "BinaryTree.h"

using namespace std;

int main()
{
    string s = "1+5*7/3+4-3/2-1"; //+ (1) (+ (*(5)(/(7)(3))) (-(4)(-(/(3)(2))(1))))
    BinaryTree bt(s); //+1+*5/73-4-/321
    bt.printPrefix();
}

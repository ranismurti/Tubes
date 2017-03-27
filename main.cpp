#include <iostream>
#include "aplikasi.h"

using namespace std;

int main()
{
    list_child LC;
    list_parent LP;
    list_relasi LR;
    createList(LC);
    createList(LP);
    createList(LR);
    menu(LC,LP,LR);
    return 0;
}

#include <iostream>
#include "LinkedDouble.cpp"
#include "BackPack.h"

using namespace std;

int main() {
    LinkedDouble<BackPack> *linked = new LinkedDouble<BackPack>();

    //linked->addNodeFirst(BackPack("123", "maleta", "n"));
    //linked->addNodeFirst(BackPack("463", "Hu", "fds"));
    //cout<<linked->findNode("123");


    for (BackPack backPack : linked->getLinkedList(false)){
        cout<<backPack<<endl;
    }



    return 0;
}

#include <iostream>
#include <string>
#include <fstream>
#include "Tree.h"

using namespace std;

int main()
{
    Tree MyTree;
    char input;
    fstream nameFile;
    nameFile.open("letters.txt", ios::in);

    while(nameFile)
    {
        nameFile.get(input);
        MyTree.insertNode(input);
        
    }
    MyTree.displayInOrder();
    nameFile.close();
    
    return 0;
}

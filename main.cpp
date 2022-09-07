#include "tRegistry.h"

int main() {
    std::cout << "---Registry template---" << std::endl;
    tRegistry<string,int> myReg;
    myReg.add("a",1);
    myReg.add("a",2);
    myReg.add("a",3);
    myReg.add("b",4);
    myReg.printAll("a");
    cout << "Delete key 'a'" << endl;
    myReg.deleteAll("a");
    myReg.printAll("a");
    myReg.printAll("b");
    std::cout << "---Bye, bye!---" << std::endl;
    return 0;
}

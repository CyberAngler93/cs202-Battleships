//Created by Matthew Perry for testing object creation.
#include "ship.cpp"
// pure test file for object creation and manipulation
int main(){
Carrier  b('c',2,DOWN);
b.print(std::cout);
b.setShipHealth(0);
b.print(std::cout);
if(b.isDestroyed() == 1){
        std::cout << "Carrier has been sunk!" << std::endl;
}
Submarine s('a',10,RIGHT);
s.print(std::cout);
Destroyer myDestroyer('j',1,LEFT);
myDestroyer.print(std::cout);

return 0;
}

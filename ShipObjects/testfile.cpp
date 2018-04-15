#include "ship.hpp"
// pure test file for object creation and manipulation
int main(){
Carrier  playerOneCarrier('c',2,RIGHT);
playerOneCarrier.print(std::cout);
playerOneCarrier.setShipHealth(0);
playerOneCarrier.print(std::cout);
if(playerOneCarrier.isDestroyed() == 1){
        std::cout << "Carrier has been sunk!" << std::endl;
}
Submarine s('a',10,LEFT);
s.print(std::cout);
Destroyer myDestroyer('j',1,RIGHT);
myDestroyer.print(std::cout);
if(playerOneCarrier.isHit('c',1)== 1){
    std::cout << "Ship Has Been Hit" << std::endl;
}
else{
    std::cout << "Ship Missed Suckka" << std::endl;
}
if(playerOneCarrier.isHit('c',5)== 1){
    std::cout << "Ship Has Been Hit" << std::endl;
}
else{
    std::cout << "Ship Missed Suckka" << std::endl;
}

return 0;
}

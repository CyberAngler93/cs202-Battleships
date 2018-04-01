//Created by Matthew Perry
//3/30/18 Battle Ship Object Files
//This is the ship.cpp file giving full creation of functions of ship class.

#include "ship.hpp"
//overloaded opperator for print functions
std::ostream & operator << (std::ostream & os, const Ship & userShip){
    userShip.print(os);
    return os;
}

std::string Ship::getShipType()const{
    if(_shipType == CARRIER){
        return std::string("Carrier");
    }
    else if(_shipType == DESTROYER){
        return std::string("Destroyer");
    }
    else if(_shipType == CRUISER){
        return std::string("Cruiser");
    }
    else if(_shipType == SUBMARINE){
        return std::string("Submarine");
    }
    else if (_shipType ==BATTLESHIP){
        return std::string("Battleship");
    }
    else{
     return std::string("Out of Bounds");
    }
}

int Ship::getShipHealth()const{
    return _shipHealth;
}

int Ship::getShipSize()const{
    return _shipSize;
}

ShipLocation Ship::getShipLoaction()const{
    return _shipLocation;
}

void Ship::setShipLocation(int userHorizonalLocation, char userVerticalLocation, ShipOrientation userShipDirection){
    int range = getShipHealth();
    for(int i = 0; i < range; i++){
            _shipLocation.horizonalLocation.push_back(userHorizonalLocation);
            _shipLocation.verticalLocation.push_back(userVerticalLocation);
            if(userShipDirection == LEFT){
                userHorizonalLocation --;
            }
            else if(userShipDirection == RIGHT){
                userHorizonalLocation ++;
            }
            else if(userShipDirection == UP){
                userVerticalLocation --;
            }
            else if(userShipDirection == DOWN){
                userVerticalLocation ++;

            }
    }
}

void Ship::setShipSize(int userShipSize){
    _shipSize = userShipSize;
}

void Ship::setShipHealth(int userHealth){
    _shipHealth = userHealth;
}

void Ship::setShipType(ShipType userShipType){
    _shipType = userShipType;
}

bool Ship::isDestroyed(){
    if(getShipHealth() == 0){
        return true;
    }
    else{
        return false;
    }
}

void Ship::print(std::ostream & os) const{
    os << std::endl;
    os << getShipType() << " is located at these points " << std::endl;
    for(auto i = 0; i < getShipSize(); i++){
        os << _shipLocation.horizonalLocation[i] << " : " << _shipLocation.verticalLocation[i];
        os << std::endl;
    }
    os << "and has " << getShipHealth() << " health remaining" << std::endl;
    os << std::endl;
    os<< std:: endl;

}

Ship::~Ship(){

}

Carrier::Carrier(){
    setShipHealth(5);
    setShipLocation('a',1,DOWN);
    setShipType(CARRIER);
    setShipSize(5);
}

Carrier::Carrier(int userHorizonalLocation, char userVerticalLocation, ShipOrientation userShipDirection){
    setShipHealth(5);
    setShipLocation(userHorizonalLocation, userVerticalLocation, userShipDirection);
    setShipType(CARRIER);
    setShipSize(5);
}

Carrier::Carrier(const Carrier & oldCarrier){
    setShipHealth(oldCarrier._shipHealth);
    // NEED TO FINISH COPY CONSTRUCTOR
}

Carrier::~Carrier(){
// NEED TO FINISH DESTRUCTOR
}

Battleship::Battleship(){
    setShipHealth(4);
    setShipLocation('a',1,DOWN);
    setShipType(BATTLESHIP);
    setShipSize(4);
}

Battleship::Battleship(int userHorizonalLocation, char userVerticalLocation, ShipOrientation userShipDirection){
    setShipHealth(4);
    setShipLocation(userHorizonalLocation, userVerticalLocation, userShipDirection);
    setShipType(BATTLESHIP);
    setShipSize(4);
}

Battleship::Battleship(const Battleship & oldBattleship){
    setShipHealth(oldBattleship._shipHealth);
    //NEED TO FINISH COPY CONSTRUCTOR
}

Battleship::~Battleship(){
// NEED TO FINISH DESTRUCTOR
}

Cruiser::Cruiser(){
    setShipHealth(3);
    setShipLocation('a',1,DOWN);
    setShipType(CRUISER);
    setShipSize(3);
}

Cruiser::Cruiser(int userHorizonalLocation, char userVerticalLocation, ShipOrientation userShipDirection){
    setShipHealth(3);
    setShipLocation(userHorizonalLocation, userVerticalLocation, userShipDirection);
    setShipType(CRUISER);
    setShipSize(3);
}

Cruiser::Cruiser(const Cruiser & oldCruiser){
    setShipHealth(oldCruiser._shipHealth);
    //NEED TO FINISH COPY CONSTRUCTOR
}

Cruiser::~Cruiser(){
//NEED TO FINISH DESTRUCTOR
}

Submarine::Submarine(){
    setShipHealth(3);
    setShipLocation('a',1,DOWN);
    setShipType(SUBMARINE);
    setShipSize(3);
}

Submarine::Submarine(int userHorizonalLocation, char userVerticalLocation, ShipOrientation userShipDirection){
    setShipHealth(3);
    setShipLocation(userHorizonalLocation, userVerticalLocation, userShipDirection);
    setShipType(SUBMARINE);
    setShipSize(3);
}

Submarine::Submarine(const Submarine & oldSubmarine){
    setShipHealth(oldSubmarine._shipHealth);
    //NEED TO FINISH COPY CONTSTRUCTOR
}

Submarine::~Submarine(){
//NEED TO FINISH DESTRUCTOR
}

Destroyer::Destroyer(){
    setShipHealth(2);
    setShipLocation('a',1,DOWN);
    setShipType(DESTROYER);
    setShipSize(2);
}

Destroyer::Destroyer(int userHorizonalLocation, char userVerticalLocation, ShipOrientation userShipDirection){
    setShipHealth(2);
    setShipLocation(userHorizonalLocation, userVerticalLocation, userShipDirection);
    setShipType(DESTROYER);
    setShipSize(2);
}

Destroyer::Destroyer(const Destroyer & oldDestroyer){
    setShipHealth(oldDestroyer._shipHealth);
    //NEED TO FINISH COPY CONSTRUCTOR
}

Destroyer::~Destroyer(){
//NEED TO FINISH DESTRUCTOR
}



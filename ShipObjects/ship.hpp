//Created by Matthew Perry
//3/30/2018
//Header File for ship objects for Battle Ships

#ifndef SHIP_HPP_INCLUDED
#define SHIP_HPP_INCLUDED
#include <vector> // needed for vector management
#include <ostream> // needed for ostream overload
#include <string> // needed for string
#include <iostream> // needed for

//enum definition forward declaration
enum ShipOrientation{LEFT,RIGHT,UP,DOWN};
enum ShipType{CARRIER,BATTLESHIP,CRUISER,SUBMARINE,DESTROYER};
//Struct definition forward declaration
struct ShipLocation{
    std::vector<char> horizonalLocation;
    std::vector<int> verticalLocation;
    };
//base class of ships
class Ship{
    //friend of all for printing to any ostream default cout
    friend std::ostream & operator <<(std::ostream & os, const Ship & userShip);
public:
    //bool test for dead ship
    bool isDestroyed();
    //print function for all classes
    void print(std::ostream & os)const;
    // pure virtual destructor
    virtual ~Ship() =0;
    //setFunctions for ships
    void setShipType(ShipType userShipType);
    void setShipHealth(int userHealth);
    void setShipSize( int userShipSize);
    void setShipLocation(int userHorizonalLocation, char userVerticalLocation, ShipOrientation userShipDirection);
    //getFunctions for ships
    std::string getShipType()const;
    int getShipHealth()const;
    int getShipSize()const;
    ShipLocation getShipLoaction()const;

protected:
    //ENUM VALUES
    ShipType _shipType;
    ShipOrientation _shipOrientation;
    //STRUCT FOR MANAGING VECTORS OF SHIP LOCATION
    ShipLocation _shipLocation;
    int _shipHealth;
    int _shipSize;
};
//derived class from ship
class Carrier : public Ship{
    using Ship::Ship;
public:
    Carrier(); //default
    Carrier(int userHorizonalLocation, char userVerticalLocation, ShipOrientation userShipDirection);
    Carrier(const Carrier & oldCarrier); //copy
    ~Carrier() override; //destruct
};
//derived class from ship
class Battleship : public Ship{
    using Ship::Ship;
public:
    Battleship(); //default
    Battleship(int userHorizonalLocation, char userVerticalLocation, ShipOrientation userShipDirection);
    Battleship(const Battleship & oldBattleship); //copy
    ~Battleship() override; //destruct
};
//derived class from ship
class Cruiser : public Ship{
    using Ship::Ship;
public:
    Cruiser(); //default
    Cruiser(int userHorizonalLocation, char userVerticalLocation, ShipOrientation userShipDirection);
    Cruiser(const Cruiser & oldCruiser); //copy
    ~Cruiser() override; //destruct
};
//derived class from ship
class Submarine : public Ship{
    using Ship::Ship;
public:
    Submarine(); //default
    Submarine(int userHorizonalLocation, char userVerticalLocation, ShipOrientation userShipDirection);
    Submarine(const Submarine & oldSubmarine); //copy
    ~Submarine() override; //destruct
};
//derived class from ship
class Destroyer : public Ship{
    using Ship::Ship;
public:
    Destroyer(); //default
    Destroyer(int userHorizonalLocation, char userVerticalLocation, ShipOrientation userShipDirection);
    Destroyer(const Destroyer & oldDestroyer); //copy
    ~Destroyer() override; //destruct
};
#endif // SHIP_HPP_INCLUDED

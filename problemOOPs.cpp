#include <iostream>
#include <queue>
#include <sstream>
#include <vector>
#include <iomanip>

class Passenger{
    private:
    std::string passengerID;
    std::string passengerName;
    std::string destination;
    static int totalPassengers;

    public:
    Passenger(const std::string passengerID,const  std::string passengerName,const  std::string destination) : passengerID(passengerID) , passengerName(passengerName), destination(destination){
        totalPassengers++;
    }

    std::string getPassengerID(){return passengerID;}
    std::string getPassengerName(){return passengerName;}
    std::string getDestination(){return destination;}

    static int getTotalPassengers();
    ~Passenger() = default;
};

int Passenger::totalPassengers = 0;

int Passenger::getTotalPassengers(){return totalPassengers;}

class Flight{
    private:
    std::string flightID;
    std::string origin;
    std::string destination;
    static int totalFlights;

    public:
    Flight(const std::string flightID,const  std::string origin,const  std::string destination): flightID(flightID), origin(origin) , destination(destination){
        totalFlights++;
    }
    std::string getFlightID(){return flightID;}
    std::string getOrigin(){return origin;}
    std::string getDestination(){return destination;}

    std::string getFlightInfo(){
        std::ostringstream info;

        info << "Flight ID: " << std::setw(12) << std::left << flightID ;
        info << " | Origin: " << std::setw(12) << std::left << origin ;
        info << " | Destination: " << std::setw(12) << std::left << destination << "\n" ;

        return info.str();
    }
    static int getTotalFlights();

};
int Flight::totalFlights = 0;

int Flight::getTotalFlights(){return totalFlights;}

class CheckInCounter{
    private:
    std::string counterCode;
    Flight plane;
    std::queue<Passenger*> travellers;

    public:
    CheckInCounter(const std::string counterCode , Flight plane): counterCode(counterCode) , plane(plane){}

    std::string getCounterCode(){return counterCode;}
    Flight getPlane(){return plane;}
    void joinQueue(Passenger* p){
        travellers.push(p);
    }

    Passenger* checkInNext(){
        if(!travellers.empty()){
            Passenger* temp = travellers.front();
            travellers.pop();
            return temp;
        }else{
            return nullptr;
        }
    }

    int getQueueLength(){
        return travellers.size();
    }
};

class Airport{
    private:
    std::string airportName;
    std::vector<CheckInCounter> checkIn;

    public:
    Airport(std::string airportName) : airportName(airportName){}

    void addCounter(CheckInCounter c){
        checkIn.push_back(c);
    }
    std::string getAirportStatus(){
        std::ostringstream status;

        status << "\n==== " << airportName << " ====\n";
       for(auto& ptr: checkIn){
        status << "Counter Code: " << ptr.getCounterCode() << "\n";
        status << "Flight Info: " << ptr.getPlane().getFlightInfo() << "\n";
        status << "Queue Length: " << ptr.getQueueLength() << "\n" ;

       }
        return status.str(); 
    }
};

int main(){
    
    Airport a("Istanbul International Airport");

    Flight f1("AI-202", "JFK", "LHR");
    Flight f2("EK-501", "DXB", "SYD");

    CheckInCounter c1("CTR-A1", f1);
    CheckInCounter c2("CTR-B2", f2);
    
    
    Passenger* p1 = new Passenger("P101", "Alice Smith", "LHR");
    Passenger* p2 = new Passenger("P102", "Bob Jones", "LHR");
    Passenger* p3 = new Passenger("P203", "Clark Kent", "SYD");
    
    Passenger* p01 = new Passenger("P201", "Charlie Brown", "LHR");
    Passenger* p02 = new Passenger("P103", "Diana Prince", "SYD");
    Passenger* p03 = new Passenger("P202", "Bruce Wayne", "SYD");
    
    c1.joinQueue(p1);
    c1.joinQueue(p2);
    c1.joinQueue(p3);
    
    c2.joinQueue(p01);
    c2.joinQueue(p02);
    c2.joinQueue(p03);
    
    Passenger* checkedOut = c1.checkInNext();
    Passenger* checkedOut2 = c2.checkInNext();

    a.addCounter(c1);
    a.addCounter(c2);

    std::cout << a.getAirportStatus() << std::endl;
    std::cout << "Total Passengers Created: " << Passenger::getTotalPassengers() << std::endl;
    std::cout << "Total Flights Created: " << Flight::getTotalFlights() << std::endl;

    delete p1;
    delete p2;
    delete p3;
    delete p01;
    delete p02;
    delete p03;

    return 0;
}
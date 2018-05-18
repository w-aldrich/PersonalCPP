//
//  main.cpp
//  TripPlanner
//
//  Created by William Aldrich on 3/21/18.
//  Copyright © 2018 William Aldrich. All rights reserved.
//
// Might add python script to find information from web for all vehicles
// https://stackoverflow.com/questions/49137/calling-python-from-a-c-program-for-distribution

#include <iostream>
#include "tripCalculations.hpp"


void findFile() {
    
}

void newTrip(bool isBill) {
    std::string make;
    std::string model;
    std::string year;
    double tankSize;
    double totalTripMilage;

    if(isBill) {
        std::string suby;
        std::cout << "Suby?\n";
        std::cin >> suby;
        if(suby.find("y") != std::string::npos) {
            make = "Subaru";
            model = "Outback";
            year = "2014";
            tankSize = 18.5;
        } else {
            make = "Saturn";
            model = "SL1";
            year = "1999";
            tankSize = 12.1;
        }
    } else {
        std::cout << "\nPlease enter the make of your vehicle\n";
        std::cin >> make;
        std::cout << "\nPlease enter the model of your vehicle\n";
        std::cin >> model;
        std::cout << "\nPlease enter the year of your vehicle\n";
        std::cin >> year;
        
        std::cout << "\nPlease enter the amount in gallons that your vehicle tank holds\n";
        std::cin >> tankSize;
    }
    
    std::cout << "\nPlease enter the total trip milage\n";
    std::cin >> totalTripMilage;
    
    
    
}

int main(int argc, const char * argv[]) {
    std::cout << "This program will compute the average mpg for a trip," <<
    " the ideal amount of stops for your car on the trip" <<
    " as well as projected or actual cost of trip. \n";
    
    std::string oldOrNew;
    std::cout << "Would you like to load a old trip or create a new trip?\n" <<
    "Enter \"load\" to load a old trip or \"new\" to enter a new trip\n";
    std::cin >> oldOrNew;
    
    if(oldOrNew.find("l") != std::string::npos || oldOrNew.find("L") != std::string::npos) {
        findFile();
    } else {
        if(argc > 1) {
            newTrip(true);
        }
        else{
            newTrip(false);
        }
    }
}

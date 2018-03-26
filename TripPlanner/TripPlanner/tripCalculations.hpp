//
//  tripCalculations.hpp
//  TripPlanner
//
//  Created by William Aldrich on 3/22/18.
//  Copyright © 2018 William Aldrich. All rights reserved.
//

#ifndef tripCalculations_hpp
#define tripCalculations_hpp

#include <stdio.h>
#include <iostream>
#include <vector>

struct addGasInfo {
    double gallonsUsed;
    double pricePerGallon;
    double totalCost;
    std::string cityGotGasIn;
    double distanceToCity;
    
    addGasInfo(double gallonsUsed, double pricePerGallon, double totalCost) {
        this->gallonsUsed = gallonsUsed;
        this->pricePerGallon = pricePerGallon;
        this->totalCost = totalCost;
    }
    addGasInfo(double gallonsUsed, double pricePerGallon, double totalCost,
               std::string cityGotGasIn, double distanceToCity) {
        this->gallonsUsed = gallonsUsed;
        this->pricePerGallon = pricePerGallon;
        this->totalCost = totalCost;
        this->cityGotGasIn = cityGotGasIn;
        this->distanceToCity = distanceToCity;
    }
    
};


double calculateTotalDistance(std::vector<addGasInfo> gasInfo);
double calculateAverageMPG(std::vector<addGasInfo> gasInfo, double totalDistance);
double calculateTotalCost(std::vector<addGasInfo> gasInfo);
double calculateIdealStopsInMiles(double tankSize, double avgMPG);
double caclulateAverageDistanceBetweenStops(std::vector<addGasInfo> gasInfo);

#endif /* tripCalculations_hpp */

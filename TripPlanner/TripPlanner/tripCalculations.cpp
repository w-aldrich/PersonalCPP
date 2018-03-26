//
//  tripCalculations.cpp
//  TripPlanner
//
//  Created by William Aldrich on 3/22/18.
//  Copyright © 2018 William Aldrich. All rights reserved.
//

#include "tripCalculations.hpp"
#include <vector>


double calculateTotalDistance(std::vector<addGasInfo> gasInfo) {
    double totalDistance = 0;
    for(addGasInfo agi: gasInfo) {
        totalDistance += agi.distanceToCity;
    }
    return totalDistance;
}

double calculateAverageMPG(std::vector<addGasInfo> gasInfo, double totalDistance){
    double totalGallonsUsed = 0;
    for(addGasInfo agi: gasInfo) {
        totalGallonsUsed += agi.gallonsUsed;
    }
    return totalDistance / totalGallonsUsed;
}

double calculateTotalCost(std::vector<addGasInfo> gasInfo) {
    double totalCost = 0;
    for (addGasInfo agi: gasInfo) {
        totalCost += agi.totalCost;
    }
    return totalCost;
}

double calculateTotalGalUsed(std::vector<addGasInfo> gasInfo) {
    double totalUsed = 0;
    for(addGasInfo agi: gasInfo) {
        totalUsed += agi.gallonsUsed;
    }
    return totalUsed;
}

double calculateIdealStopsInMiles(double tankSize, double avgMPG) {
    double halfTankGas = tankSize/2;
    return avgMPG * halfTankGas;
}

double caclulateAverageDistanceBetweenStops(std::vector<addGasInfo> gasInfo) {
    double averageDist = 0;
    for(addGasInfo agi: gasInfo) {
        averageDist += agi.distanceToCity;
    }
    return (averageDist /= gasInfo.size());
}

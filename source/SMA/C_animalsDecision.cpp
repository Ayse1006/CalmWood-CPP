#include <unistd.h>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

#include "U_randomGenerator.hpp"
#include "C_animal.hpp"
#include "C_plant.hpp"
#include "C_animal.hpp"
#include "C_environment.hpp"

int Leucorrhinia::decision ( Environment * environment, std::unordered_multimap<int, Animal *> * VisibleAnimals, std::unordered_map<int,int> * VisiblePlants, std::vector<int> * CellSpecs )
{

        int timeOfDay = environment->getTimeOfDay();
        int month = environment->getMonth();
        int viability = CellSpecs->at ( 0 );
        int wetLand = CellSpecs->at ( 3 );
        int X = CellSpecs->at ( 4 );
        int Y = CellSpecs->at ( 5 );

        float temperature = environment->getEnvironmentParameters() [0];
        float hygrometry = environment->getEnvironmentParameters() [1];
        float antropizationRate = environment->getEnvironmentParameters() [2];

        int actionProbability = runRNG ( 0,100 );
        
        satietyIndex -= 10;
        
        if ( temperature < 15.0 || temperature > 30.0 )
                dead ( environment );

        if ( antropizationRate > 0.8 )
                dead ( environment );

        if ( hygrometry < 0.2 || hygrometry > 0.95 ) {
                dead ( environment );
        }

        if ( month < 5 && month >= 9 && sex == 1 ) {
                hidden = true;
                deadProbability = 0;
        }

//         if ( actionProbability < deadProbability )
//                 dead ( environment );

        if ( actionProbability < growthProbability )
                growth ( environment );

        if ( actionProbability < eatProbability )
                eat();

        if ( growthState == 1 ) {
                if ( actionProbability < moveProbability && wetLand == 1 ) {
                        moveTowards ( environment, X, Y );
                }
        }

        if ( growthState == 2 ) {
            
                if ( sex == 0 ) {

                        if ( viability == 1 && month >= 4 && month < 7 ) {
                                protectTerritory = true;
                                territoryCoordinates = {location[0],location[1]};
                                detectionRadius[2] = 1;
                        }

                        if ( actionProbability < reproductionProbability && protectTerritory )
                                reproduction ( VisibleAnimals,0 );

                        if ( actionProbability < attackProbability && protectTerritory )
                                attack ( environment, VisibleAnimals, X, Y, 0 );

                        if ( month < 4 && month >= 7 )
                                protectTerritory = false;
                }

                if ( ( actionProbability < moveProbability && month >= 5 && month < 9 && growthState > 0 && ! protectTerritory ) || viability == 0 )
                        move ( environment );
        }

        return 0;
}

int Hyla::decision ( Environment * environment, std::unordered_multimap<int, Animal *> * VisibleAnimals, std::unordered_map<int,int> * VisiblePlants, std::vector<int> * CellSpecs )
{
        return 0;
}


int Phengaris::decision ( Environment * environment, std::unordered_multimap<int, Animal *> * VisibleAnimals, std::unordered_map<int,int> * VisiblePlants, std::vector<int> * CellSpecs )
{
        return 0;
}

int Zootoca::decision ( Environment * environment, std::unordered_multimap<int, Animal *> * VisibleAnimals, std::unordered_map<int,int> * VisiblePlants, std::vector<int> * CellSpecs )
{
        return 0;
}

int Vipera::decision ( Environment * environment, std::unordered_multimap<int, Animal *> * VisibleAnimals, std::unordered_map<int,int> * VisiblePlants, std::vector<int> * CellSpecs )
{
        return 0;
}

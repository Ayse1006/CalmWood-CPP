/* 
 * Copyright 2020 Axel Polin, univ_apolin@protonmail.com
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *   http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * 
*/
#include <unistd.h>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

#include "C_plant.hpp"
#include "C_environment.hpp"

Plant::Plant ( int newId, std::string newName )
{
        id = newId;
        name = newName;
        
};

Plant::~Plant () {};

int Plant::getID()
{
        return id;
}

std::string Plant::getName()
{
    return name;
}

int Plant::growth ( int targetState )
{
        return 0;
}

int Plant::getDeadType()
{
    return deadType;
}

int Plant::setDeadType(int i)
{
    deadType=i;
    return 0;
}

int Plant::damage()
{
        return 0;
}

int Plant::setLocation ( std::vector<int> newLocation )
{
        if ( newLocation.size() != 3 )
                return -1;

        location = newLocation;

        return 0;
}

std::vector<int> Plant::getLocation()
{
        return location;
}

int Plant::dead ( Environment* environment )
{
        environment->getCell ( location[0], location[1] )->removePlant ( id, this );
        death = true;

        return 0;
}

bool Plant::isDead()
{
    return death;
}

int Plant::decision ( Environment * environment)
{

        int month = environment->getMonth();

        int X = 0;
        int Y = 0;
        int randomTry = 0;

        float temperature = environment->getEnvironmentParameters() [0];
        float hygrometry = environment->getEnvironmentParameters() [1];
        float antropizationRate = environment->getEnvironmentParameters() [2];




        if ( temperature < 5.0 || temperature > 30.0 ) {

                dead ( environment );
                setDeadType(0);
                return 0;
        }

        if ( antropizationRate > 0.8 ) {
                dead ( environment );
                setDeadType(0);
                return 0;
        }

        if ( hygrometry < 0.1 || hygrometry > 0.95 ) {
                dead ( environment );
                setDeadType(0);
                return 0;
        }

        return 0;
}

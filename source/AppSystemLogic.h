/* Copyright (C) 2005-2020, UNIGINE. All rights reserved.
 *
 * This file is a part of the UNIGINE 2.11.0.1 SDK.
 *
 * Your use and / or redistribution of this software in source and / or
 * binary form, with or without modification, is subject to: (i) your
 * ongoing acceptance of and compliance with the terms and conditions of
 * the UNIGINE License Agreement; and (ii) your inclusion of this notice
 * in any version of this software that you use or redistribute.
 * A copy of the UNIGINE License Agreement is available by contacting
 * UNIGINE. at http://unigine.com/
 * 
 * Modified by Axel Polin, 2020, univ_apolin@protonmail.com
 */


#ifndef __APP_SYSTEM_LOGIC_H__
#define __APP_SYSTEM_LOGIC_H__

using namespace Unigine;
using namespace Math;
using namespace std;

class AppWorldLogic;

class AppSystemLogic : public Unigine::SystemLogic
{
public:
    AppSystemLogic();
    virtual ~AppSystemLogic();
    int write_data(string file, string content);
    int init() override;

    int update() override;
    int postUpdate() override;

    int shutdown() override;

    AppWorldLogic *worldlogic_ptr;

    Environment environment;
    
    vector<Animal *> animals;
    vector<Plant *> plants;
    
    int getDeadCount();
    
    int getSpawnCount();
    int setDeadTypeCountAn();
    int setDeadTypeCountPl();
    int setDeadCountAn();

protected :
    
    vector<Animal *>::iterator agentAnimal;
    vector<Plant *>::iterator agentPlant;

    int deadNatCount= 0;
    int deadStarvCount=0;
    int deadEnvCount=0;
    int deadPredCount=0;
    vector<int>deadLeuco{deadNatCount,deadStarvCount,deadEnvCount,deadPredCount};
    vector<int>deadHyla{deadNatCount,deadStarvCount,deadEnvCount,deadPredCount};
    vector<int>deadVipera{deadNatCount,deadStarvCount,deadEnvCount,deadPredCount};
    vector<int>deadLeucoVector{};
    vector<int>deadHylaVector{};
    vector<int>deadViperaVector{};

    int deadCount=0;
    int deadLeucoCount=0;
    int deadHylaCount=0;
    int deadViperaCount=0;


    int deadEnvCountCarex=0;
    int deadPredCountCarex=0;
    vector<int>deadCarex{deadEnvCount,deadPredCount};
    vector<int>deadCountVectorCarex{};
    int deadCountCarex=0;
    int spawnCount = 0;
    int spawnCountL= 0;
    int spawnCountH = 0;
    int spawnCountV = 0;  
    


    bool simulationEnd = false;
    float ifps = 0.0;

    vector<int> location = {0,0};

    const int SimulationDuration = environment.MaxAgentRun * environment.MaxRunPerRunTime * environment.MaxRunTime;

    float runTime = environment.RunDuration;
    float timeDuration = environment.MaxRunPerRunTime;
    float simulationTime = SimulationDuration;

    int spawn ( Animal * animal );

};

#endif // __APP_SYSTEM_LOGIC_H__



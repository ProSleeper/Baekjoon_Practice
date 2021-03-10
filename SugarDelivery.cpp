//
//  SugarDelivery.cpp
//  Baekjoon_Practice
//
//  Created by kyw on 10/03/2021.
//  Copyright © 2021 kyw. All rights reserved.
//

#include <iostream>

using namespace std;

int main()
{
    int sugarWeight = 0;
    int divideSugar = 0;
    int leftOverSugar = 0;
    int sackOfSugar = 0;
    int RestFiveSugar = 0;
    int countThreeValue = 0;
    int countThreeRest = 0;
    
    cin >> sugarWeight;
    
    leftOverSugar = sugarWeight % 5;
    divideSugar = sugarWeight / 5;
    
    if (leftOverSugar == 0) {
        cout << divideSugar;
        return 0;
    }
    
    

    
    for (int i = 0; i <= divideSugar; i++) {
        RestFiveSugar = sugarWeight - ((divideSugar * 5) - (i * 5));
        
        countThreeValue = RestFiveSugar / 3;
        countThreeRest = RestFiveSugar % 3;
        
        if (countThreeRest == 0) {
            sackOfSugar = (divideSugar - i) + countThreeValue;
            cout << sackOfSugar;
            break;
        }
    }
    if (sackOfSugar == 0) {
        cout << -1;
    }
    
    return 0;
}

//
//  main.cpp
//  first_cli
//
//  Created by Boluwatife Onifade on 15/12/2024.
//

#include <iostream>
#include <vector>
#include "src/tife_1792.cpp"
#include "src/tife_2415.cpp"


using namespace tife::leetcode;
void executeExercise(std::vector<Solution*>& exercises){
    for(auto sol: exercises){
        sol->run();
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::vector<Solution*> exercises;
    exercises.push_back(new Solution1792());
    exercises.push_back(new Solution2415());
    executeExercise(exercises);
    return 0;
}

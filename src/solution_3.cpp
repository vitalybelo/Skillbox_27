#include <iostream>
#include <random>
#include "Team.h"
#include "use_lib.h"
using namespace std;

void solution_3() {

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> team_dist (4,8);

    Team team{"DEPT-1"};
    team.generateTeam(team_dist(gen));

    cout << team << endl;

}
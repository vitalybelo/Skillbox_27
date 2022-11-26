#include <iostream>
#include <random>
#include "Team.h"
#include "Company.h"
#include "use_lib.h"
using namespace std;

void solution_3() {

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> team_dist (4,8);

    //Team team{1,"Отдел-1"};
    //team.generateTeam(team_dist(gen));


    Company company("BUBLIKOV & SONS");
    company.generateCompany(5);

    cout << company << endl;


}
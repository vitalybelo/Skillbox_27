#include <iostream>
#pragma once

enum Post { BOSS = 0, MANAGER, WORKER, SECRETARY, NOBODY, UNDER_NOBODY, WORSE_UNDER_NOBODY, SHOES_DIRT };

class Employee {

private:
    std::string name = "John Smith";
    Post post = WORKER;

public:
    // constructors
    Employee(const char *name, Post post);
    Employee(const std::string &name, Post post);

    // getters & setters
    void setName(std::string newName);
    void setPost(Post post);

    std::string getName() const;
    Post getPost() const;

};

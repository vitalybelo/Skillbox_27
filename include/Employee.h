#include <iostream>
#pragma once

enum Post { BOSS = 0, MANAGER, WORKER, NOBODY, UNDER_NOBODY, WORSE_UNDER_NOBODY, SHOES_DIRT };

class Employee {

private:
    std::string name = "John Smith";
    Post post = WORKER;

public:
    Employee(const char *name, Post post);
    Employee(const std::string &name, Post post);

    void setName(const std::string &newName);
    void setPost(Post post);

    std::string getName() const;
    Post getPost() const;

};

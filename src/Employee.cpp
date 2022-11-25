#include "Employee.h"

Employee::Employee(const char *name, Post post) {
    this->name = name;
    if (post < 2)
        this->post = post;
}

Employee::Employee(const std::string &name, Post post) {
    this->name = name;
    if (post < 2)
        this->post = post;
}

std::string Employee::getName() const {
    return name;
}

void Employee::setName(const std::string &newName) {
    Employee::name = newName;
}

Post Employee::getPost() const {
    return post;
}

void Employee::setPost(Post newPost) {
    Employee::post = newPost;
}




#include "Employee.h"

#include <utility>

Employee::Employee(const char *name, Post post) {
    this->name = name;
    this->post = post;
}

Employee::Employee(const std::string &name, Post post) {
    this->name = name;
    this->post = post;
}

std::string Employee::getName() const {
    return name;
}

void Employee::setName(std::string newName) {
    Employee::name = std::move(newName);
}

Post Employee::getPost() const {
    return post;
}

void Employee::setPost(Post newPost) {
    Employee::post = newPost;
}




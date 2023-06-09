#pragma once

#include <string>

using namespace std;

namespace LIB_1 {
    class Employee {
    private:
        string _firstName;
        string _lastName;
        string _position;
        unsigned int _projects;

    public:
        Employee(string firstName, string lastName, string position) : _firstName(firstName),
                                                                                            _lastName(lastName),
                                                                                            _position(position) {
            _projects = 0;
        }

        string getPosition(){
            return _position;
        }

        string getName(){
            return _lastName + " " + _firstName;
        }

        unsigned int getProjects(){
            return _projects;
        }

        void addProjects() {
            if (_projects < 3) {
                _projects++;
            }
        }
        void delProjects() {
            if (_projects > 0) {
                _projects--;
            }
        }
    };
}


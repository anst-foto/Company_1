#pragma once

#include <string>
#include <vector>

#include "Employee.h"
#include "Department.h"

using namespace std;

namespace LIB_1 {
    class Company {
    private:
        string _name;
        Employee* _general;
        vector<Department*>* _departments;
    public:
        explicit Company(string name) : _name(name) {
            _departments = new vector<LIB_1::Department *>;
        }

        virtual ~Company() {
            delete _general;
            delete _departments;
        }

        string getName() {
            return _name;
        }

        Employee *getGeneral() {
            return _general;
        }

        void setGeneral(Employee *general) {
            _general = general;
        }

        void AddDepartment(Department* department) {
            bool repeat = false;
            for (auto d : *_departments) {
                if (d == department) {
                    repeat = true;
                }
            }
            if (!repeat) {
                _departments->push_back(department);
            }
        }
        void DelDepartment(Department* department) {
            for (auto i = _departments->begin(); i < _departments->end(); ++i) {
                if (*i == department) {
                    _departments->erase(i);
                    break;
                }
            }
        }
        vector<Department *> *getDepartments() {
            return _departments;
        }
    };
}

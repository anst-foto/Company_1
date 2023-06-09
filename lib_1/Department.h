#pragma once

#include <string>
#include <vector>

#include "Employee.h"

using namespace std;

namespace LIB_1 {
    class Department {
    private:
        string _name;
        Employee* _manager;
        vector<Employee*>* _workers;

    public:
        explicit Department(string name) : _name(name) {
            _workers = new vector<LIB_1::Employee*>;
        }

        virtual ~Department() {
            delete _manager;
            delete _workers;
        }

        string getName() {
            return _name;
        }

        Employee *getManager() {
            return _manager;
        }

        void setManager(Employee *manager) {
            _manager = manager;
        }

        void AddWorker(Employee* worker) {
            bool repeat = false;
            for (auto w : *_workers) {
                //TODO переопределение оператора сравнения
                if (w == worker) {
                    repeat = true;
                }
            }
            if (!repeat) {
                _workers->push_back(worker);
            }
        }
        void DelWorker(Employee* worker) {
            for (auto i = _workers->begin(); i < _workers->end(); ++i) {
                if (*i == worker) {
                    _workers->erase(i);
                    break;
                }
            }
        }

        vector<Employee *> *getWorkers() {
            return _workers;
        }
    };
}

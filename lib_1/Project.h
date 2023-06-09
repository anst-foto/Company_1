#pragma once

#include <string>
#include <vector>

#include "Employee.h"

using namespace std;

namespace LIB_1 {

    class Project {
    private:
        string _name;
        vector<Employee*>* _workers;

    public:
        explicit Project(string name) : _name(name) {
            _workers = new vector<LIB_1::Employee*>;
        }

        virtual ~Project() {
            delete _workers;
        }

        string getName() {
            return _name;
        }

        void AddWorker(Employee* worker) {
            bool repeat = false;
            for (auto w : *_workers) {
                //TODO переопределение оператора сравнения
                if (w == worker) {
                    repeat = true;
                }
            }
            if (!repeat && worker->getProjects() < 3) {
                _workers->push_back(worker);
                worker->addProjects();
            }
        }
        void DelWorker(Employee* worker) {
            for (auto i = _workers->begin(); i < _workers->end(); ++i) {
                if (*i == worker) {
                    _workers->erase(i);
                    worker->delProjects();
                    break;
                }
            }
        }

        vector<Employee *> *getWorkers() {
            return _workers;
        }
    };
}

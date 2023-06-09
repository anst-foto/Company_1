#include <iostream>

#include "./lib_1/Company.h"
#include "./lib_1/Department.h"
#include "./lib_1/Project.h"
#include "./lib_1/Employee.h"

using namespace std;

void PrintCompany(LIB_1::Company* company);
void PrintDepartment(LIB_1::Department* department);
void PrintEmployee(LIB_1::Employee* employee);
void PrintProject(LIB_1::Project* project);

int main() {
    auto company = new LIB_1::Company("company");
    company->setGeneral(new LIB_1::Employee("A", "AA", "general"));
    company->AddDepartment(new LIB_1::Department("department"));
    auto department = company->getDepartments()->at(0);
    department->setManager(new LIB_1::Employee("B", "BB", "major"));
    department->AddWorker(new LIB_1::Employee("C", "CC", "worker"));
    auto worker = department->getWorkers()->at(0);
    auto project = new LIB_1::Project("project");
    project->AddWorker(worker);

    PrintCompany(company);
    PrintProject(project);

    return 0;
}

void PrintCompany(LIB_1::Company* company) {
    cout << company->getName() << " - " << company->getGeneral()->getName() << ", " << company->getGeneral()->getPosition() << endl;
    for (auto d : *company->getDepartments()) {
        PrintDepartment(d);
    }
}

void PrintDepartment(LIB_1::Department* department) {
    cout << department->getName() << " - " << department->getManager()->getName() << ", " << department->getManager()->getPosition() << endl;
    for (auto w : *department->getWorkers()) {
        PrintEmployee(w);
    }
}

void PrintEmployee(LIB_1::Employee* employee) {
    cout << employee->getName() << " : " << employee->getPosition() << " [ " << employee->getProjects() << " ]"  << endl;
}

void PrintProject(LIB_1::Project* project) {
    cout << project->getName() << endl;
    for (auto w : *project->getWorkers()) {
        PrintEmployee(w);
    }
}
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

class Employee{
    private:
    std::string employeeID;
    std::string employeeName;
    double baseSalary;

    public:
    Employee(std::string employeeID, std::string employeeName, double baseSalary) : employeeID(employeeID) , employeeName(employeeName), baseSalary(baseSalary){}

    std::string getEmployeeID()const{return employeeID;}
    std::string getEmployeeName()const{return employeeName;}
    double getBaseSalary()const{return baseSalary;}

    virtual std::string getPayDetails(){
        std::ostringstream fix;
        fix << std::fixed << std::setprecision(2) << getBaseSalary();
        return ("Base salary for " + employeeName + ": " + fix.str()); 
    }

    virtual ~Employee() = default;
};

class FullTimeEmployee : public Employee{
    private:
    double bonus;

    public:
        FullTimeEmployee(std::string employeeID, std::string employeeName, double baseSalary, double bonus) : Employee(employeeID, employeeName, baseSalary) , bonus(bonus){}

        std::string getPayDetails()override{
            std::ostringstream fix;
            fix << Employee::getPayDetails() << std::fixed << std::setprecision(2) << " | Bonus: " << bonus;
            return fix.str();
        }

};

class PartTimeEmployee : public Employee{
    private:
    int hoursWorked;
    double hourlyRate;

    public:
    PartTimeEmployee(std::string employeeID, std::string employeeName, double baseSalary, int hoursWorked, double hourlyRate) : Employee(employeeID, employeeName, baseSalary) , hoursWorked(hoursWorked) , hourlyRate(hourlyRate){}

    std::string getPayDetails()override{
        std::ostringstream fix;
        fix << Employee::getPayDetails() << std::fixed << std::setprecision(2) << " | Hours Worked: " << hoursWorked << " | Hourly Rate: " << hourlyRate;
        return fix.str();
    }
};

class Contractor : public Employee{
    private:
    double contractAmount;

    public:
    Contractor(std::string employeeID, std::string employeeName, double baseSalary, double contractAmount) : Employee(employeeID, employeeName, baseSalary) , contractAmount(contractAmount){}

    std::string getPayDetails()override{
        std::ostringstream fix;
        fix << Employee::getPayDetails() << std::fixed << std::setprecision(2) << " | Contract Amount: " << contractAmount;
        return fix.str();
    }
};

class PayrollSystem{
    private:
    std::string companyName;
    std::vector<Employee*> emp;

    public:
    PayrollSystem(std::string companyName): companyName(companyName){}

    std::string getCompanyName()const{return companyName;}

    void addEmployee(Employee* e){
        emp.push_back(e);
    }

    std::string generatePayrollReport(){
        std::ostringstream summary;

        summary << "\n---- All employee Detail ----\n";

        for(auto& ptr: emp){
             summary << std::fixed << std::setprecision(2) << ptr->getPayDetails() << std::endl;
        }
        return summary.str();
    }
    ~PayrollSystem() = default;
};

int main(){

    Employee* e1 = new FullTimeEmployee("R45Y23", "Mohd Faisal", 45000, 15000);
    Employee* e2 = new PartTimeEmployee("Q67U98", "Abdul Rahman", 54000, 90, 600);
    Employee* e3 = new Contractor("B76V12", "Yaseen", 23000, 23000);

    PayrollSystem p("Infosys & Tech");

    p.addEmployee(e1);
    p.addEmployee(e2);
    p.addEmployee(e3);

    std::cout << p.generatePayrollReport();

    delete e1;
    delete e2;
    delete e3;
    
    return 0;
}
#include <iostream>
#include <unordered_set>
#include <list>
#include <sstream>
#include <iomanip>

class Trackable
{

public:
    virtual std::string getID() = 0;
    virtual std::string getSummary() = 0;
    virtual ~Trackable() = default;
};
class UniversityMember
{
private:
    std::string memberID;
    std::string memberName;

public:
    UniversityMember(const std::string memberID, const std::string memberName) : memberID(memberID), memberName(memberName) {}

    std::string getMemberID() const { return memberID; }
    std::string getMemberName() const { return memberName; }

    virtual std::string getRole() = 0;

    virtual ~UniversityMember() = default;
};

class Professor : public Trackable, public UniversityMember
{
private:
    std::string subject;
    std::unordered_set<std::string> researchTopic;

public:
    Professor(const std::string memberID, const std::string memberName, const std::string subject) : UniversityMember(memberID, memberName), subject(subject) {}

    void addResearchTopic(std::string topic)
    {
        researchTopic.insert(topic);
    }

    std::string getID() override { return getMemberID(); }
    std::string getRole() override { return "Professor"; }
    std::string getSummary() override
    {
        std::ostringstream summary;
        // summary << "Role: " << std::setw(15) << getRole();
        summary << "Member ID: " << std::setw(10) << std::left <<  getMemberID();
        summary << "Name: " << std::setw(25)<< std::left  << getMemberName();
        summary << "Subject: " << std::setw(30) << std::left << subject;
        summary << "Topic: " ;
        bool first = true;
        for (const auto &ptr : researchTopic)
        {
            if(!first) summary << ", ";
                summary << ptr;
                first = false;
        }
        return summary.str();
    }
};

class GradStudent : public UniversityMember, public Trackable
{
private:
    std::string thesisTopic;
    std::string supervisorID;

public:
    GradStudent(const std::string memberID, const std::string memberName, const std::string thesisTopic, const std::string supervisorID) : UniversityMember(memberID, memberName), thesisTopic(thesisTopic), supervisorID(supervisorID) {}

    std::string getRole()override { return "Graduate Student"; }

    std::string getID() override { return getMemberID(); }
    std::string getSummary() override
    {
        std::ostringstream summary;
        summary << "Supervisor ID: " << std::setw(10)<<std::left << supervisorID;
        summary << "Name: " << std::setw(15) << std::left << getMemberName();
        summary << "Thesis Topic: " << std::setw(15) << thesisTopic;

        return summary.str();
    }
};

class Department
{
private:
    std::string departmentName;
    std::list<Professor *> faculty;
    std::list<GradStudent *> grads;

public:
    Department(std::string departmentName)
    {
        this->departmentName = departmentName; // i used this coz kaafi din ho gye the yeh wala constructor banay
    }
    void addProfessor(Professor *prof)
    {
        faculty.push_back(prof);
    }
    void addGradStudent(GradStudent *studt)
    {
        grads.push_back(studt);
    }
    std::string getDepartmentReport()
    {
        std::ostringstream report;
        report << "\n---- Detail Report ----\n";
        report << " Professor Detail \n";
        int count = 0;
        for (const auto &ptr : faculty)
        {
            report << ++count << "- " << ptr->getSummary() << "\n";
        }
        report << "\n Graduate Student Detail \n";
        count = 0;
        for (const auto &ptr : grads)
        {
            report << ++count << "- " << ptr->getSummary() << "\n";
        }
        return report.str();
    }
   
};

int main()
{

    Professor *p1 = new Professor("A34U98", "A.P.J Abdul kalam azad", "Aeronautics Engineering");
    Professor *p2 = new Professor("H76O12", "Mohd Faisal", "Computer Science");

    GradStudent *g1 = new GradStudent("R6584Y1", "Furkan", "Neural Networks Optimization", "P101");
    GradStudent *g2 = new GradStudent("H9823Q3", "Aliya", "Autonomous Drone Navigation", "P102");

    Department college("School of Computer Engineering");

    college.addProfessor(p1);
    college.addProfessor(p2);
    college.addGradStudent(g1);
    college.addGradStudent(g2);

    p1->addResearchTopic("AI");
    p1->addResearchTopic("Machine Learning");
    p1->addResearchTopic("AI");
    p1->addResearchTopic("Data Science");

    p2->addResearchTopic("VLSI");
    p2->addResearchTopic("Robotics");
    p2->addResearchTopic("VLSI");
    p2->addResearchTopic("Embedded Systems");

    std::cout << college.getDepartmentReport();

    delete p1;
    delete p2;
    delete g1;
    delete g2;

    return 0;
}

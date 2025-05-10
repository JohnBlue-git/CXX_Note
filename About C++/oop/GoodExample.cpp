#include <iostream>
#include <map>
#include <string>

using EmployeeList = std::map<unsigned int, std::string>;      // <EmployeeID, EmployeeName>
using BranchList = std::map<unsigned int, EmployeeList>;       // <BranchID, EmployeeList>
using CompanyList = std::map<std::string, BranchList>;     // <CompanyName, BranchList>

class Cache {
public:
    static Cache& getInstance()
    {
        static Cache instance;
        return instance;
    }

    void updateEmployee(
        const std::string& companyName,
        unsigned int branchID,
        unsigned int employeeID,
        const std::string& employeeName)
    {
        BranchList& company = companyList[companyName];
        EmployeeList& branch = company[branchID];
        branch[employeeID] = employeeName;
    }

    void updateBranch(
        const std::string& companyName,
        unsigned int branchID,
        const EmployeeList& branch)
    {
        // Improved readability: Clearly separates the steps — first get the company's branch list, then update the branch.
        // Easier debugging: You can inspect company directly.
        // More maintainable: If you reuse company multiple times in a function, this avoids repeated lookups.
        BranchList& company = companyList[companyName];
        company[branchID] = branch;
    }

    void updateCompany(
        const std::string& companyName,
        const BranchList& company)
    {
        // Concise: Great for quick, simple updates.
        companyList[companyName] = company;
    }


    void print() const
    {
        for (const auto& [companyName, branches] : companyList)
        {
            std::cout << "Company: " << companyName << "\n";
            for (const auto& [branchID, employees] : branches)
            {
                std::cout << "  Branch ID: " << branchID << "\n";
                for (const auto& [employeeID, name] : employees)
                {
                    std::cout << "    Employee ID: " << employeeID
                              << ", Name: " << name << "\n";
                }
            }
        }
    }

private:
    Cache() = default;
    ~Cache() = default;
    Cache(const Cache&) = delete;
    Cache(Cache&&) = delete;
    Cache& operator=(const Cache&) = delete;

private:
    CompanyList companyList;
};

int main()
{
    Cache& cache = Cache::getInstance();

    // Add single employee
    cache.updateEmployee("OpenAI", 101, 1, "Alice");
    cache.updateEmployee("OpenAI", 101, 2, "Bob");

    // Add branch
    EmployeeList branchEmployees = {
        {3, "Charlie"},
        {4, "Diana"}
    };
    cache.updateBranch("OpenAI", 102, branchEmployees);

    // Add company with branches
    BranchList newCompany = {
        {201, {{5, "Eve"}, {6, "Frank"}}},
        {202, {{7, "Grace"}}}
    };
    cache.updateCompany("DeepMind", newCompany);

    // Print everything
    cache.print();

    return 0;
}

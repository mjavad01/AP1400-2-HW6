#ifndef Q2_H
#define Q2_H

#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>
#include <vector>

namespace q2 {

    struct Patient
    {
    	std::string name;
    	size_t age;
    	size_t smokes;
    	size_t area_q;
    	size_t alkhol;
    };


    std::vector<Patient> read_csv(const std::string& filename)
    {
        std::vector<Patient> result {};
        std::ifstream csv_file(filename);
        std::string line {};
        std::regex rgx(R"((\w+)\s*,(\w+)\s*,(\d+),(\d+),(\d+),(\d+)\s*)");
        std::smatch match;
        if (csv_file.is_open())
        {
            while (getline(csv_file, line))
            {
                Patient p{};
                if (std::regex_match(line, match, rgx))
                 {
                    p.name = std::string(match[1]) + " " + std::string(match[2]);
                    p.age = std::stoi(match[3]);
                    p.smokes = std::stoi(match[4]);
                    p.area_q = std::stoi(match[5]);
                    p.alkhol = std::stoi(match[6]);
                    result.push_back(p);
                }
            result.push_back(p);
            }
        csv_file.close();
        }
    return result;
    }

    // display patients vector in csv format
    void display_csv(std::vector<Patient>& patients)
    {
        for (auto& p : patients)
        {
            std::cout << p.name << "," << p.age << "," << p.smokes << "," << p.area_q << "," << p.alkhol << std::endl;
        }
    }


    bool compare(Patient& a, Patient& b)
    {
        size_t cancer_probaplity_a {3*a.age + 5*a.smokes + 2*a.area_q + 4*a.alkhol};
        size_t cancer_probaplity_b{3*b.age + 5*b.smokes + 2*b.area_q + 4*b.alkhol};
        
        return cancer_probaplity_a > cancer_probaplity_b;
    }

    void sort(std::vector<Patient>& patients)
    {
        std::sort(patients.begin(), patients.end(), compare);
    }

}

#endif // Q2_H
#include "data_loader.h"
#include <fstream>
#include <sstream>
#include <algorithm>


std::string trim(const std::string& s) {
    auto start = s.find_first_not_of(" \t\r\n");
    auto end = s.find_last_not_of(" \t\r\n");
    return (start == std::string::npos) ? "" : s.substr(start, end - start + 1);
}

std::vector<Internship> DataLoader::fetchActualInternships(const std::string& filePath) {
    std::vector<Internship> data;
    std::ifstream file(filePath);
    
    if (!file.is_open()) return data;

    std::string line;
    while (std::getline(file, line)) {
        line = trim(line);
        if (line.empty() || line[0] == '#') continue;

        std::stringstream ss(line);
        std::string item;
        std::vector<std::string> fields;


        while (std::getline(ss, item, ';')) {
            fields.push_back(trim(item));
        }

        
        if (fields.size() >= 7) {
            std::unordered_set<std::string> tags;
            std::stringstream tagStream(fields[5]);
            std::string tag;
            while (std::getline(tagStream, tag, ',')) {
                tags.insert(trim(tag));
            }

            data.emplace_back(
                fields[0], // id
                fields[1], // title
                fields[2], // company
                fields[3], // description
                fields[4], // url
                tags,      // tags
                true,      // is_active
                fields[6]  // deadline
            );
        }
    }
    return data;
}

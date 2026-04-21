#pragma once
#include "internship.h"
#include <vector>
#include <string>

class DataLoader {
public:
    static std::vector<Internship> fetchActualInternships(const std::string& filePath);
};

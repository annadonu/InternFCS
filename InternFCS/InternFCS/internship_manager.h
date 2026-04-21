#pragma once

#include "internship.h"
#include <vector>
#include <unordered_map>
#include <string_view>
#include <optional>

class InternshipManager {
public:
    InternshipManager() = default;
    ~InternshipManager() = default;

    void addInternship(const Internship& internship);
    void removeInternship(std::string_view id);
    
    std::vector<Internship> getAllActive() const;
    std::vector<Internship> filterByCompany(std::string_view company_name) const;
    std::vector<Internship> filterByTag(std::string_view tag) const;

    std::optional<Internship> getById(std::string_view id) const;

private:
    std::unordered_map<std::string, Internship> database_;
};

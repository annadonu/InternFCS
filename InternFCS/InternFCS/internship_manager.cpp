#include "internship_manager.h"
#include <algorithm>

void InternshipManager::addInternship(const Internship& internship) {
    database_.insert_or_assign(internship.id, internship);
}

void InternshipManager::removeInternship(std::string_view id) {
    database_.erase(std::string(id));
}

std::vector<Internship> InternshipManager::getAllActive() const {
    std::vector<Internship> result;
    result.reserve(database_.size());
    
    for (auto it = database_.cbegin(); it != database_.cend(); ++it) {
        if (it->second.is_active) {
            result.push_back(it->second);
        }
    }
    return result;
}

std::vector<Internship> InternshipManager::filterByCompany(std::string_view company_name) const {
    std::vector<Internship> result;
    
    for (auto it = database_.cbegin(); it != database_.cend(); ++it) {
        if (it->second.company == company_name) {
            result.push_back(it->second);
        }
    }
    return result;
}

std::vector<Internship> InternshipManager::filterByTag(std::string_view tag) const {
    std::vector<Internship> result;
    std::string tag_str(tag);
    
    for (auto it = database_.cbegin(); it != database_.cend(); ++it) {
        if (it->second.tags.find(tag_str) != it->second.tags.end()) {
            result.push_back(it->second);
        }
    }
    return result;
}

std::optional<Internship> InternshipManager::getById(std::string_view id) const {
    std::string id_str(id);
    auto it = database_.find(id_str);
    
    if (it != database_.end()) {
        return it->second;
    }
    return std::nullopt;
}

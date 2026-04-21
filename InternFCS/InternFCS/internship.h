#pragma once
#include <string>
#include <unordered_set>

struct Internship {
    std::string id;
    std::string title;
    std::string company;
    std::string description;
    std::string url;
    std::unordered_set<std::string> tags;
    bool is_active;
    std::string deadline; 
    Internship(std::string id_val, std::string title_val, std::string company_val,
               std::string desc_val, std::string url_val,
               std::unordered_set<std::string> tags_val, bool active_val,
               std::string deadline_val);
};

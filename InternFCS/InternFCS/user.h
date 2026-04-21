#pragma once
#include <string>
#include <unordered_set>
#include <string_view>

class User {
public:
    User(std::string id);

    bool isFavorite(const std::string& internshipId) const;
    void addFavorite(const std::string& internshipId);
    void removeFavorite(const std::string& internshipId);

private:
    std::string id_;
    std::unordered_set<std::string> favorites_;
};

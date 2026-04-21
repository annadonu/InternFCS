#include "user.h"

User::User(std::string id_val) : id_(std::move(id_val)) {}

bool User::isFavorite(const std::string& internshipId) const {
    return favorites_.find(internshipId) != favorites_.end();
}

void User::addFavorite(const std::string& internshipId) {
    favorites_.insert(internshipId);
}

void User::removeFavorite(const std::string& internshipId) {
    favorites_.erase(internshipId);
}

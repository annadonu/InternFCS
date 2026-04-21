#include "internship.h"

Internship::Internship(std::string id_val, std::string title_val, std::string company_val,
                       std::string desc_val, std::string url_val,
                       std::unordered_set<std::string> tags_val, bool active_val,
                       std::string deadline_val)
    : id(std::move(id_val))
    , title(std::move(title_val))
    , company(std::move(company_val))
    , description(std::move(desc_val))
    , url(std::move(url_val))
    , tags(std::move(tags_val))
    , is_active(active_val)
    , deadline(std::move(deadline_val)) 
{
    
}

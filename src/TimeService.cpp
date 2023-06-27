#include <uuid/uuid.h>
#include <string>
#include <chrono>
#include "TimeService.h"

twt::TimeService::TimeService()
{

}

const std::vector<twt::TimeEntry> &twt::TimeService::GetEntries() const
{
    return entries;
}

void twt::TimeService::StartNewEntry(const std::string &label)
{
    uuid_t uuid;
    uuid_generate_time_safe(uuid);
    char uuidStr[37];
    uuid_unparse_lower(uuid, uuidStr);
    const std::string id(uuidStr);

    const auto timestamp = std::chrono::system_clock::now();
    entries.push_back(twt::TimeEntry(id, label, timestamp));
}
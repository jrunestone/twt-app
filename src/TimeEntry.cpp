#include <chrono>
#include <fmt/core.h>
#include <fmt/chrono.h>
#include "TimeEntry.h"

twt::TimeEntry::TimeEntry(const std::string &id, const std::string &label, const std::chrono::time_point<std::chrono::system_clock> &timestamp) 
    : id(id), label(label), timestamp(timestamp), duration(0)
{

}

const std::string twt::TimeEntry::FormatTimestamp() const
{
    return fmt::format("{:%Y-%m-%d %H:%M:%S}", timestamp);
}

const std::string twt::TimeEntry::FormatDuration() const
{
    return fmt::format("{}", duration);
}
#pragma once

#include <string>
#include <chrono>

namespace twt
{
    class TimeEntry
    {
        public:
            std::string id;
            std::string label;
            std::chrono::time_point<std::chrono::system_clock> timestamp;
            int duration;

        public:
            TimeEntry(const std::string &id, const std::string &label, const std::chrono::time_point<std::chrono::system_clock> &timestamp);

            const std::string FormatTimestamp() const;
            const std::string FormatDuration() const;
    };
}
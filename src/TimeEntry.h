#pragma once

#include <string>

namespace twt
{
    class TimeEntry
    {
        public:
            std::string id;
            std::string label;
            int64_t timestamp;

        public:
            TimeEntry(const std::string &id,
                      const std::string &label,
                      int64_t timestamp) : id(id), label(label), timestamp(timestamp)
                      {

                      }
    };
}
#pragma once

#include <vector>
#include <string>
#include "TimeEntry.h"

namespace twt
{
    class TimeService
    {
        private:
            std::vector<twt::TimeEntry> entries;
            
        public:
            TimeService();

            const std::vector<twt::TimeEntry> &GetEntries() const;
            void StartNewEntry(const std::string &label);
    };
}
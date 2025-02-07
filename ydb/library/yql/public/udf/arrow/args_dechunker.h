#pragma once

#include <arrow/datum.h>
#include <vector>
#include <deque>

#include "util.h"

namespace NYql {
namespace NUdf {

class TArgsDechunker {
public:
    explicit TArgsDechunker(std::vector<arrow::Datum>&& args);
    bool Next(std::vector<arrow::Datum>& chunk);

private:
    const std::vector<arrow::Datum> Args;
    std::vector<std::deque<std::shared_ptr<arrow::ArrayData>>> Arrays;
    bool Finish = false;
};

}
}

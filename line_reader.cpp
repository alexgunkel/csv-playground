#include "line_reader.hpp"

#include <concepts>

#include <absl/strings/str_split.h>

namespace play {
namespace {
std::string_view trim(std::string_view in) noexcept {
    return in.substr(in.find_first_not_of(' '));
}
}

[[maybe_unused]] LineReader::LineReader(std::string_view header) : fields_{absl::StrSplit(header, ",")} {
    std::transform(fields_.begin(), fields_.end(), fields_.begin(), trim);
}

std::vector<std::pair<std::string_view, std::string_view>> LineReader::readLine(std::string_view str) const {
    std::vector<std::string_view> split = absl::StrSplit(str, ",");
    if (split.size() != fields_.size()) {
        throw DataError{"field count must match"};
    }

    std::vector<std::pair<std::string_view, std::string_view>> result;
    result.resize(fields_.size());

    std::transform(
            fields_.begin(),
            fields_.end(),
            split.begin(),
            result.begin(),
            [](auto field, auto value) {
                return std::pair<std::string_view, std::string_view>{field, trim(value)};
            }
    );

    return result;
}
} // play
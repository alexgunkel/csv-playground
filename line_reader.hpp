#ifndef CSV_PLAYGROUND_LINE_READER_HPP
#define CSV_PLAYGROUND_LINE_READER_HPP

#include <string_view>
#include <map>
#include <vector>
#include <stdexcept>

namespace play {

class LineReader {
public:
    [[maybe_unused]] explicit LineReader(std::string_view header);
    [[nodiscard]] std::vector<std::pair<std::string_view, std::string_view>> readLine(std::string_view) const;

    class DataError : public std::runtime_error {
        using std::runtime_error::runtime_error;
    };
private:
    std::vector<std::string_view> fields_{};
};

} // play

#endif //CSV_PLAYGROUND_LINE_READER_HPP

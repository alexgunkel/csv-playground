#include <iostream>
#include <ranges>

#include "line_reader.hpp"

int main() {
    constexpr std::string_view input{"id, ring, part"};

    for (play::LineReader reader{input}; auto const &[key, value] : reader.readLine("2, a, b")) {
        std::cout << key << ": " << value << "\n";
    }
    return 0;
}

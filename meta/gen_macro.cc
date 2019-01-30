// Copyright (c) 2019 Aleksandr Derbenev. All rights reserved.

#include <cerrno>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>

int main(int argc, const char* argv[]) {
  if (argc != 3) {
    std::cerr << "Exactly 2 arguments expected!" << std::endl;
    std::cerr << R"(
Exactly 2 arguments expected!
Usage: gen_macro OUTPUT MAX_META_STRING_LITERAL_SIZE

OUTPUT
    Path to the output header file.

MAX_META_STRING_LITERAL_SIZE
    Positive integer limit for meta string literal size.
)" << std::endl;
    return 1;
  }

  int size = atoi(argv[2]);
  if (size <= 0) {
    std::cerr << "maximum literal size should be positive integer number."
        << std::endl;
    return 1;
  }

  std::fstream stream;
  stream.open(argv[1], std::ios_base::out | std::ios_base::trunc);
  if (!stream.good()) {
    std::cerr << argv[0] << ": error: " << std::strerror(errno) << std::endl;
    return 1;
  }

  stream <<
      R"(// Copyright (c) 2019 Aleksandr Derbenev. All rights reserved.

#pragma once

#define META_STR_IMPL(literal) \
    ::meta::impl::LiteralSizeLimiter< \
)";
  for (int i = 0; i < size; ++i) {
    stream << "      ::meta::impl::PushBackChar< \\\n";
  }
  stream << "        ::meta::String<>, \\\n";
  for (int i = 0; i < size; ++i) {
    stream << "      ::meta::impl::CharAt(literal, " << i << ")>::type, \\\n";
  }
  stream << R"(      sizeof(literal) - 1>::type

#define MAX_META_STRING_LITERAL_SIZE )" << size << std::endl;
  return 0;
}

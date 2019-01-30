// Copyright (c) 2019 Aleksandr Derbenev. All rights reserved.

#include <iostream>
#include <string_view>

#include "meta/string.h"

using FooString = meta::String<'F', 'o', 'o'>;
using BarString = meta::String<'B', 'a', 'r'>;

using FooBarString = meta::Concat<FooString, BarString>::type;

int main(int argc, const char* argv[]) {
  std::string_view content(
      meta::Get<FooBarString>::value, sizeof(meta::Get<FooBarString>::value));

  std::cout << "FooBarString content: `" << content << '`' << std::endl;

  return 0;
}

// Copyright (c) 2019 Aleksandr Derbenev. All rights reserved.

#include <string_view>
#include <iostream>

#include "meta/string.h"

using FooString = meta::String<'F', 'o', 'o'>;

int main(int argc, const char* argv[]) {
  std::string_view content(
      meta::Get<FooString>::value, sizeof(meta::Get<FooString>::value));

  std::cout << "FooString content: `" << content << '`' << std::endl;
  return 0;
}

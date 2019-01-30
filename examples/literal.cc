// Copyright (c) 2019 Aleksandr Derbenev. All rights reserved.

#include <iostream>
#include <string_view>

#include "meta/string.h"

using FooString = STR("Foo");

int main(int argc, const char* argv[]) {
  std::string_view content(
      meta::Get<FooString>::value, sizeof(meta::Get<FooString>::value));
  std::cout << "FooString content: `" << content << '`' << std::endl;
  return 0;
}

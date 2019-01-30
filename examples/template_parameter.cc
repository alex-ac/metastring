// Copyright (c) 2019 Aleksandr Derbenev. All rights reserved.

#include "meta/string.h"

using FooString = ::meta::String<'F', 'O', 'O'>;

int main(int argc, const char* argv[]) {
  FooString foo_string;
  // Use sizeof(foo_string) to prevent unused-variable warning.
  return sizeof(foo_string) - sizeof(foo_string);
}

// Copyright (c) 2019 Aleksandr Derbenev. All rights reserved.

#ifndef META_STRING_H_
#define META_STRING_H_

#include <cstddef>

#include "meta/gen_string_macro.h"

namespace meta {

template <char... Chars>
struct String {};

template <class T>
struct Get;

template <char... Chars>
struct Get<String<Chars...>> {
  static constexpr char value[] = { Chars... };
};

template <class A, class B>
struct Concat;

template <char... Chars, char... ExtraChars>
struct Concat<String<Chars...>, String<ExtraChars...>> {
  using type = String<Chars..., ExtraChars...>;
};

namespace impl {

template <class T, char c>
struct PushBackChar;

template <char... Chars, char c>
struct PushBackChar<String<Chars...>, c> {
  using type = String<Chars..., c>;
};

template <char... Chars>
struct PushBackChar<String<Chars...>, '\0'> {
  using type = String<Chars...>;
};

template <size_t N>
constexpr char CharAt(const char (&s)[N], size_t i) {
  return i >= N ? '\0' : s[i];
}

#define _NUMBER_TO_STR(n) #n
#define NUMBER_TO_STR(n) _NUMBER_TO_STR(n)
template <class String, size_t size>
struct LiteralSizeLimiter {
  using type = String;
  static_assert(size <= MAX_META_STRING_LITERAL_SIZE,
      "at most " NUMBER_TO_STR(MAX_META_STRING_LITERAL_SIZE)
      " characters allowed for constexpr string literal");
};
#undef NUMBER_TO_STR
#undef _NUMBER_TO_STR

#define STR(literal) META_STR_IMPL(literal)

}  // namespace impl

}  // namespace meta

#endif  // META_STRING_H_

// Copyright (c) 2019 Aleksandr Derbenev. All rights reserved.

#ifndef META_STRING_H_
#define META_STRING_H_

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

}  // namespace meta

#endif  // META_STRING_H_

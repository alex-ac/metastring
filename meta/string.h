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

}  // namespace meta

#endif  // META_STRING_H_

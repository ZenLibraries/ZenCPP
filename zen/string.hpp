#ifndef ZEN_STRING_HPP
#define ZEN_STRING_HPP

#include <string>

#include "zen/config.h"
#include "zen/maybe.hpp"

ZEN_NAMESPACE_START

// TODO This should be a strong type
using Glyph = char32_t;

inline constexpr const Glyph eof = 0xFFFF;
inline constexpr const Glyph invalid = 0xFFFE;

// TODO The internal representation should be converted to UTF-8
using String = std::basic_string<Glyph>;

// TODO The internal representation should be converted to UTF-8
using string_view = std::basic_string_view<Glyph>;

template<>
class Maybe<Glyph> {

  Glyph value;

public:

  inline Maybe():
    value(eof) {}

  inline Maybe(Glyph value):
    value(value) {}

  Glyph& operator*() {
    ZEN_ASSERT(value != eof);
    return value;
  }

  const Glyph& operator*() const {
    ZEN_ASSERT(value != eof);
    return value;
  }

  bool is_some() const {
    return value != eof;
  }

  bool is_empty() const {
    return value == eof;
  }

};

// FIXME Currently only works for ASCII values.
inline String from_utf8(std::string_view raw) {
  return String { raw.begin(), raw.end() };
}

template<std::size_t N>
inline String from_utf8(const char ptr[N]) {
  return String { ptr, ptr + N };
}


inline bool is_alpha(Glyph ch) {
  return (ch >= 65 && ch <= 90) || (ch >= 96 && ch <= 122);
}

inline bool is_numeric(Glyph ch) {
  return ch >= 48 && ch <= 57;
}

inline bool is_alnum(Glyph ch) {
  return is_alpha(ch) || is_numeric(ch);
}


#define ZEN_STRING_LITERAL(literal) ::zen::from_utf8(literal)

ZEN_NAMESPACE_END

#endif // of #ifndef ZEN_STRING_HPP

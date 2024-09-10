#pragma once

#include <cstdint>

using u8 = uint8_t;
using u16 = uint16_t;

#define STRINGIFY_DETAIL(x) #x
#define STRINGIFY(x) STRINGIFY_DETAIL(x)

#define UNIMPLEMENTED() static_assert(false, "Function not yet implemented in: " __FILE__ ":" STRINGIFY(__LINE__))

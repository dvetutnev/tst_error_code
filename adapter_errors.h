#pragma once

#include <system_error>

namespace net
{

enum class AdapterErrors {
    InvalidContext = 1,
    InvalidContent
};

std::error_code make_error_code(AdapterErrors);

} // namespace net

namespace std
{
template<>
struct is_error_code_enum<net::AdapterErrors> : true_type {};
}

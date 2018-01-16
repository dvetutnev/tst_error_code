#pragma once

#include <system_error>

#include "adapter_errors.h"

namespace net
{

class Exception : public std::system_error
{
public:
    template<typename Errc,
             typename = std::enable_if< std::is_enum<Errc>::value >::type>
    Exception(Errc ec)
        : system_error{ec}
    {}

    template<typename Errc, typename String,
             typename = std::enable_if< std::is_enum<Errc>::value >::type,
             typename = std::enable_if< std::is_convertible<String, std::string>::value >::type>
    Exception(Errc ec, String what_str)
        : system_error{ec, what_str}
    {}
};

class InvalidContext : public Exception
{
public:
    InvalidContext()
        : Exception{AdapterErrors::InvalidContext}
    {}

    template<typename String,
             typename = std::enable_if< std::is_convertible<String, std::string>::value >::type>
    InvalidContext(String what_str)
        : Exception{AdapterErrors::InvalidContext, what_str}
    {}
};

} // namespace net

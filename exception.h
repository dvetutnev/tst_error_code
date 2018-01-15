#pragma once

#include <system_error>

#include "adapter_errors.h"

namespace net
{

class Exception : public std::system_error
{
public:
    template<typename... Args>
    Exception(Args... args)
        : system_error{args...}
    {}
};

class InvalidContext : public Exception
{
public:
    InvalidContext()
        : Exception{AdapterErrors::InvalidContext}
    {}
};

} // namespace net

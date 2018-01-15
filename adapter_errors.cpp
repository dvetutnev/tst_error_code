#include "adapter_errors.h"

using namespace net;

namespace
{

class AdapterErrorsCategory : public std::error_category
{
    const char* name() const noexcept override;
    std::string message(int) const override;
};

const char* AdapterErrorsCategory::name() const noexcept {
    return "AdapterErrors";
}

std::string AdapterErrorsCategory::message(int ev) const {
    switch (static_cast<AdapterErrors>(ev)) {
    case AdapterErrors::InvalidContext:
        return "InvalidContext";
    case AdapterErrors::InvalidContent:
        return "InvalidContent";
    default:
        return "(unrecognized error)";
    }
}

const AdapterErrorsCategory _adapterErrorsCategory;

} // anonymous namespace

std::error_code net::make_error_code(AdapterErrors ev) {
    return {static_cast<int>(ev), _adapterErrorsCategory};
}

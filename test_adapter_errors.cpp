#include <gtest/gtest.h>

#include "adapter_errors.h"
#include "exception.h"

TEST(AdapterErrors, is_error) {
    std::error_code ec = net::AdapterErrors::InvalidContext;
    ASSERT_TRUE(ec);
    std::cout << ec << std::endl;
    std::cout << ec.message()<< std::endl;
}

TEST(AdapterErrors, equal) {
    std::error_code ec = net::AdapterErrors::InvalidContent;
    ASSERT_EQ(ec, net::AdapterErrors::InvalidContent);
    ASSERT_NE(ec, net::AdapterErrors::InvalidContext);
    std::cout << ec << std::endl;
    std::cout << ec.message() << std::endl;
}

TEST(AdapterErrors, exception) {
    try {
        throw net::InvalidContext{};
    } catch (const net::Exception& e) {
        std::cout << "code => " << e.code() << std::endl;
        std::cout << "what => " << e.what() << std::endl;
    }
    ASSERT_TRUE(true);
}

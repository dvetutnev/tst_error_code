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

TEST(AdapterErrors, exception_with_str) {
    try {
        throw net::InvalidContext{"Additional string"};
        //throw net::InvalidContext{42};
        //throw net::InvalidContext{"Additional string", 42};
    } catch (const net::Exception& e) {
        std::cout << "code => " << e.code() << std::endl;
        std::cout << "what => " << e.what() << std::endl;
    }
    ASSERT_TRUE(true);
}

TEST(Typecheck, enum_errc) {
    net::Exception e1{net::AdapterErrors::InvalidContext};
    //net::Exception e2{static_cast<int>(42)};
    //net::Exception e3{std::string{"err"}};
    net::Exception e4{net::AdapterErrors::InvalidContext, "42"};
    net::Exception e5{net::AdapterErrors::InvalidContext, std::string{"42"}};
    //net::Exception e6{net::AdapterErrors::InvalidContext, 42};
    ASSERT_TRUE(true);
}

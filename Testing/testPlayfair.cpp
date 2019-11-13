// Test that the playfair cipher works
#define CATCH_CONFIG_MAIN

#include <PlayfairCipher.hpp>
#include "catch.hpp"

TEST_CASE("Playfair Cipher Double Xs and odd length", "[playfair]") {
    PlayfairCipher cc{"qwetyiopsdfhjkzxvbm"};
    REQUIRE(cc.applyCipher("XXX", CipherMode::Encrypt) == "FYFYFX");
}



TEST_CASE("Playfair Cipher I for J swapping and double letter", "[playfair]") {
    PlayfairCipher cc{"qwetyiopsdfhjkzxvbm"};
    REQUIRE(cc.applyCipher("IJ", CipherMode::Encrypt) == "DFSF");
}

TEST_CASE("Playfair Cipher all three types of swapping", "[playfair]"){
    PlayfairCipher cc{"qwetyiopsdfhjkzxvbm"};
    REQUIRE(cc.applyCipher("QIQWQF", CipherMode::Encrypt) == "IFWEIV");
}
//! Unit Tests for MPAGSCipher CaesarCipher Class
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "VigenereCipher.hpp"

TEST_CASE("Vigenere Cipher encryption", "[vigenere]") {
  VigenereCipher vc{""};
  REQUIRE( vc.applyCipher("INPUTSTRINGTEST", CipherMode::Encrypt) == "LRUUNDMBMLJXJSN");
}

TEST_CASE("Vigenere Cipher decryption", "[vigenere]") {
  VigenereCipher vc{""};
  REQUIRE( vc.applyCipher("LRUUNDMBMLJXJSN", CipherMode::Decrypt) == "INPUTSTRINGTEST");
}
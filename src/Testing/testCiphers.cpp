//! Unit Tests for MPAGSCipher CaesarCipher Class
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include<iostream>

#include "Cipher.hpp"
#include "CipherMode.hpp"
#include "CaesarCipher.hpp"
#include "PlayfairCipher.hpp"
#include "VigenereCipher.hpp"

bool testCipher (const Cipher& cipher, const CipherMode mode, 
    const std::string& inputText, const std::string& outputText){
      
      return cipher.applyCipher(inputText, mode) == outputText;
    }

TEST_CASE("Cipher Dynamic Polymorphism", "[cipher]"){
  CaesarCipher cc{"27"};
  PlayfairCipher pc{"KEY"};
  VigenereCipher vc{"KEY"};
  REQUIRE( testCipher(cc, CipherMode::Encrypt, "INPUTTEXT", "JOQVUUFYU"));
  REQUIRE( testCipher(pc, CipherMode::Encrypt, "INPUTTEXT", "LOUKSZQBZS"));
  REQUIRE( testCipher(vc, CipherMode::Encrypt, "INPUTTEXT", "SRNEXROBR"));
}


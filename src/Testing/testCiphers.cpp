//! Unit Tests for MPAGSCipher CaesarCipher Class
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include<iostream>

#include "Cipher.hpp"
#include "CipherMode.hpp"
#include "CaesarCipher.hpp"
#include "PlayfairCipher.hpp"
#include "VigenereCipher.hpp"
#include "CipherFactory.hpp"

bool testCipher (const Cipher& cipher, const CipherMode mode, 
    const std::string& inputText, const std::string& outputText){
      
      return cipher.applyCipher(inputText, mode) == outputText;
    }

TEST_CASE("Cipher Dynamic Polymorphism", "[ciphers]"){
  std::vector<std::unique_ptr<Cipher>> inventory;
  inventory.push_back(cipherFactory(CipherType::Caesar, "27"));
  inventory.push_back(cipherFactory(CipherType::Playfair, "Key"));
  inventory.push_back(cipherFactory(CipherType::Vigenere, "Key"));

  for (const auto& v : inventory) {
    if (v == inventory[0]){REQUIRE(v->applyCipher("INPUTTEXT", CipherMode::Encrypt) == "JOQVUUFYU");}
    if (v == inventory[1]){REQUIRE(v->applyCipher("INPUTTEXT", CipherMode::Encrypt) == "LOUKSZQBZS");}
    if (v == inventory[2]){REQUIRE(v->applyCipher("INPUTTEXT", CipherMode::Encrypt) == "SRNEXROBR");}

    if (v == inventory[0]){REQUIRE(v->applyCipher("INPUTTEXT", CipherMode::Decrypt) == "HMOTSSDWS");}
    if (v == inventory[1]){REQUIRE(v->applyCipher("INPUTTEXT", CipherMode::Decrypt) == "OMIPSZQBZS");}
    if (v == inventory[2]){REQUIRE(v->applyCipher("INPUTTEXT", CipherMode::Decrypt) == "YJRKPVUTV");}
  }

  /*CaesarCipher cc{"27"};
  PlayfairCipher pc{"KEY"};
  VigenereCipher vc{"KEY"};
  REQUIRE( testCipher(cc, CipherMode::Encrypt, "INPUTTEXT", "JOQVUUFYU"));
  REQUIRE( testCipher(pc, CipherMode::Encrypt, "INPUTTEXT", "LOUKSZQBZS"));
  REQUIRE( testCipher(vc, CipherMode::Encrypt, "INPUTTEXT", "SRNEXROBR"));
  REQUIRE( testCipher(cc, CipherMode::Decrypt, "INPUTTEXT", "HMOTSSDWS"));
  REQUIRE( testCipher(pc, CipherMode::Decrypt, "INPUTTEXT", "OMIPSZQBZS"));
  REQUIRE( testCipher(vc, CipherMode::Decrypt, "INPUTTEXT", "YJRKPVUTV"));*/
}


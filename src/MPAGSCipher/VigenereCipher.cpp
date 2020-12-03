
// Standard library includes
#include <string>
#include <algorithm>
#include <iostream>
#include <typeinfo>

// Out project headers
#include "Alphabet.hpp"
#include "VigenereCipher.hpp"
#include "CaesarCipher.hpp"

VigenereCipher::VigenereCipher( const std::string& key )
{
  // Set the given key
  setKey( key );
}

void VigenereCipher::setKey( const std::string& key )
{
  // Store the key
  key_ = key;
  // Make sure the key is uppercase
  std::transform( std::begin(key_), std::end(key_), std::begin(key_), ::toupper );
  // Remove non-alphabet characters
  key_.erase( std::remove_if( std::begin(key_), std::end(key_), [](char c){ return !std::isalpha(c); } ),
              std::end(key_) );
  // Check if the key is empty and replace with default if so
  if (key_.size() == 0){key_ = "DEFAULTKEY";}
  //error here saying tis default
  // loop over the key
  for ( std::string::size_type i{0}; i < key_.size(); ++i ) {
        // Find the letter position in the alphabet
        std::size_t caesarKey_{Alphabet::alphabet.find(key_.at(i))};
        // Create a CaesarCipher using this position as a key
        CaesarCipher caesar {caesarKey_};
        // Insert a std::pair of the letter and CaesarCipher into the lookup
        charLookup_.insert(std::make_pair(key_.at(i),caesar));
  }
}

std::string VigenereCipher::applyCipher( const std::string& inputText, const CipherMode cipherMode ) const
{
  // Create the output string, initially a copy of the input text
  std::string outputText {""};
  //store key size object size_type..
  std::string::size_type keySize {key_.size()};
  // For each letter in input:
  //using index loop
  for ( std::string::size_type i{0}; i < inputText.size(); ++i ) {
        // Find the corresponding letter in the key, repeating/truncating as required
        char keyChar { key_[i % keySize] };
        // Find the Caesar cipher from the lookup
        const CaesarCipher& caesar {charLookup_.at(keyChar)};
        // Run the (de)encryption
        // Add the result to the output
        std::string oldChar {inputText[i]};
	      outputText += caesar.applyCipher( oldChar, cipherMode );
  }
  return outputText;
}

#ifndef MPAGSCIPHER_CIPHER_HPP
#define MPAGSCIPHER_CIPHER_HPP

#include "CipherMode.hpp"

/**
 * \file Cipher.hpp
 * \brief Contains the declaration of the Cipher polymorphism class,
 * 
 *  which holds the common functions in the Cipher implementations
 * 
 */

/**
 * \namespace Cipher
 * \brief Class to hold Cipher-related common functions
 */
class Cipher {
  public:
      Cipher() = default;
      Cipher(const Cipher& rhs) = default;
      Cipher(Cipher&& rhs) = default;
      Cipher& operator=(const Cipher& rhs) = default;
      Cipher& operator=(Cipher&& rhs) = default;

      virtual std::string applyCipher(const std::string& input, const CipherMode mode) const = 0;

};

#endif // MPAGSCIPHER_CIPHER_HPP 

#ifndef MPAGSCIPHER_CIPHERFACTORY_HPP
#define MPAGSCIPHER_CIPHERFACTORY_HPP

// Standard library includes
#include <memory>

// Our project headers
#include "Cipher.hpp"
#include "CipherType.hpp"

//enum class CipherTypes {Caesar, Playfair, Vigenere}; this is in ciphertype.hpp

std::unique_ptr<Cipher> cipherFactory(const CipherType type, std::string const& key);

#endif

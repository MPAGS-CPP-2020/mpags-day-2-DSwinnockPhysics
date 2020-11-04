#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::string runCaesarCipher( const std::string& inputText,const size_t key, const bool encrypt ) {
  /* Perform a caesar shift on the input text using the key, either encrypting or decrypting.

  const std::string inputText: The text to be processed
  const size_t key: The amount to shift letters
  const bool encrypt: True if the cipher is being encrypted, false if decrypted.

  return: String containing the encrypted/decrypted text.
  */
    std::vector<char> alphabet{'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    std::string outputText{""};
    // Make an integer version of the key otherwise decryption going below 0 messes up.
    int key_int = key;
    for(char workingCharacter : inputText) {
        // Find the location of the letter in the alphabet and then find the corresponding index
        auto alphabetLocation = std::find(std::begin(alphabet),std::end(alphabet),workingCharacter);
        int alphabetIndex = std::distance(alphabet.begin(),alphabetLocation);
        if (encrypt == true) {
            alphabetIndex=(alphabetIndex+key_int)%26;         
        }
        else {
            alphabetIndex=(alphabetIndex-key_int)%26;
            if (alphabetIndex<0) { // If the index would be less than 0, shift back up to between 0 and 25
                alphabetIndex+=26;
            }
        }
        // After the new index is determined, add the correspoding letter to the output
        outputText+=alphabet[alphabetIndex];
    }
    // Once that is all done return outputText
    return outputText;
}
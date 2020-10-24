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
    std::vector<char> alphabet{'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    std::string outputText{""};
    for(char workingCharacter : inputText) {
        auto alphabetLocation = std::find(std::begin(alphabet),std::end(alphabet),workingCharacter);
        int alphabetIndex = std::distance(alphabet.begin(),alphabetLocation);
        //std::cout << alphabetIndex;
        if (encrypt == true) {
            alphabetIndex=(alphabetIndex+key)%26;
            
        }
        else {
            alphabetIndex=(alphabetIndex-key)%26;
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
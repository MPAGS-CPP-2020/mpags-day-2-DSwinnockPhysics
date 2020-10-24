#include "ProcessCommandLine.hpp"

#include <iostream>
#include <vector>
#include <string>

bool processCommandLine(  const std::vector<std::string>& cmdLineArgs,
  bool& helpRequested,
  bool& versionRequested,
  std::string& inputFile,
  std::string& outputFile,
  size_t& key,
  bool& encrypt
  ) 
  {
  // Add a typedef that assigns another name for the given type for clarity
  typedef std::vector<std::string>::size_type size_type;
  const size_type nCmdLineArgs {cmdLineArgs.size()};

  // Process command line arguments - ignore zeroth element, as we know this to
  // be the program name and don't need to worry about it
  for (size_type i {1}; i < nCmdLineArgs; ++i) {

    if (cmdLineArgs[i] == "-h" || cmdLineArgs[i] == "--help") {
      helpRequested = true;
    }
    else if (cmdLineArgs[i] == "--version") {
      versionRequested = true;
    }
    else if (cmdLineArgs[i] == "-i") {
      // Handle input file option
      // Next element is filename unless -i is the last argument
      if (i == nCmdLineArgs-1) {
	std::cerr << "[error] -i requires a filename argument" << std::endl;
  // Return false to indicate an error occurred
	return false;
      }
      else {
	// Got filename, so assign value and advance past it
	inputFile = cmdLineArgs[i+1];
	++i;
      }
    }
    else if (cmdLineArgs[i] == "-o") {
      // Handle output file option
      // Next element is filename unless -o is the last argument
      if (i == nCmdLineArgs-1) {
        std::cerr << "[error] -o requires a filename argument" << std::endl;
        // Return false to indicate an error occurred
        return false;
      }
      else {
        // Got filename, so assign value and advance past it
        outputFile = cmdLineArgs[i+1];
        ++i;
      }
    }
    else if (cmdLineArgs[i] == "-k") {
      if (i == nCmdLineArgs-1) {
        std::cerr << "[error] -k requires a key argument" << std::endl;
        // Return false to indicate an error occurred
        return false;
      }
      else {    
        key = stoul(cmdLineArgs[i+1]);
        if (key>25) {
          std::cerr << "[error] key should be between 0 and 25" << std::endl;
          return false;
        }
        // Got key, so assign value and advance past it
        ++i;
      }  
    }
    else if (cmdLineArgs[i] == "--encrypt") {
      if (i == nCmdLineArgs-1) {
        std::cerr << "[error] --encrypt requires a bool argument" << std::endl;
        // Return false to indicate an error occurred
        return false;
      }
      else {
        if (cmdLineArgs[i+1] == "true") {
          encrypt = true;
          ++i;
        }
        else if (cmdLineArgs[i+1] == "false") {
          encrypt = false;
          ++i;
        }
        else {
          std::cerr << "[error] --encrypt should be followed by true or false" << std::endl;
          return false;
        }
      }
    }
    else {
      // Have an unknown flag to output error message and return false
      // exit status to indicate failure
      std::cerr << "[error] unknown argument '" << cmdLineArgs[i] << "'\n";
      return false;
    }
  }



  return true;

}
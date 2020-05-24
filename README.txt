I will be followig the below procedure to edit, sanitize and compile my c++ code.

1. Sanitize the file with Google c++ style guide, with the below command.
    python ~/bin/cpplint.py <file-name>.cpp

2. Compile the file with all the warnings enabled as errors.
    g++ -Wall -Weffc++ -Wextra -Wsign-conversion --std=c++17 <file-name>.cpp


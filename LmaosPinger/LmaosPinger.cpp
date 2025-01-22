// LmaosPinger.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cstdlib>

void pingHost(const std::string& command) {
    int result = system(command.c_str());
    if (result == 0) {
        std::cout << "Ping command executed successfully." << std::endl;
    }
    else {
        std::cout << "Ping command failed with error code: " << result << std::endl;
    }
}

int main(int argc, char* argv[]) {
    std::string host;
    int count = 4; // Default number of pings
    std::string options;
    bool loop = true;

    if (argc > 1) {
        // If options and parameters are provided, use them and avoid the loop
        for (int i = 1; i < argc; ++i) {
            options += std::string(argv[i]) + " ";
        }
        loop = false;
    }
    else {
        std::cout << "Enter the host to ping: ";
        std::cin >> host;

        std::cout << "Enter the number of pings: ";
        std::cin >> count;

        std::cout << "Enter any additional ping options (or leave blank for default): ";
        std::cin.ignore(); // To ignore the newline character left in the buffer
        std::getline(std::cin, options);
    }

    std::string command = "ping " + host + " -c " + std::to_string(count) + " " + options;

    if (loop) {
        while (true) {
            pingHost(command);
            std::cout << "Press Ctrl+C to stop..." << std::endl;
        }
    }
    else {
        pingHost(command);
    }

    return 0;
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

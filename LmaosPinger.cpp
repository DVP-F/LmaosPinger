#include <iostream>
#include <string>
#include <cstdlib>

// void pingHost(const std::string& command) {
//     int result = system(command.c_str());
//     if (result == 0) {
//         std::cout << "Ping command executed successfully." << std::endl;
//     }
//     else {
//         std::cout << "Ping command failed with error code: " << result << std::endl;
//     }
// }

// Construct packets at socket level instead. Max customizability and max CVE coverage
// I'm also banning any WIN32 api use. This will be usable on linux native too

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
            // pingHost(command);
            std::cout << "Press Ctrl+C to stop..." << std::endl;
        }
    }
    else {
        // pingHost(command);
    }

    return 0;
}


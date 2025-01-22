// LmaosPinger.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <signal.h>

// Global flag to control the infinite loop
volatile bool running = true;

// Signal handler for interrupt (Ctrl+C)
void handle_signal(int signal) {
    if (signal == SIGINT) {
        running = false;
    }
}

void print_usage() {
    std::cout << "Usage: ping_app [options]\n";
    std::cout << "Options:\n";
    std::cout << "  -h <host>        Host to ping (required)\n";
    std::cout << "  -c <count>       Number of pings (default: infinite)\n";
    std::cout << "  -s <src_ip>      Source IP address (optional)\n";
    std::cout << "  -t <timeout>     Timeout in seconds (optional)\n";
    std::cout << "  -p <payload>     Payload data (optional)\n";
    std::cout << "  --help           Show this help message\n";
}

int main(int argc, char* argv[]) {
    std::string host;
    std::string src_ip;
    int count = 0;  // 0 means infinite
    std::string timeout;
    std::string payload;

    // Parse command-line arguments
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];

        if (arg == "-h" && i + 1 < argc) {
            host = argv[++i];
        }
        else if (arg == "-c" && i + 1 < argc) {
            count = std::stoi(argv[++i]);
        }
        else if (arg == "-s" && i + 1 < argc) {
            src_ip = argv[++i];
        }
        else if (arg == "-t" && i + 1 < argc) {
            timeout = argv[++i];
        }
        else if (arg == "-p" && i + 1 < argc) {
            payload = argv[++i];
        }
        else if (arg == "--help") {
            print_usage();
            return 0;
        }
        else {
            std::cerr << "Unknown option: " << arg << "\n";
            print_usage();
            return 1;
        }
    }

    // Validate required parameters
    if (host.empty()) {
        std::cerr << "Host is required. Use --help for usage.\n";
        return 1;
    }

    // Construct the ping command
    std::string command = "ping";

    if (!src_ip.empty()) {
        command += " -I " + src_ip;  // Use -I for source IP on Linux
    }

    if (count > 0) {
        command += " -c " + std::to_string(count);
    }

    if (!timeout.empty()) {
        command += " -W " + timeout;  // Timeout
    }

    if (!payload.empty()) {
        command += " -p " + payload;  // Payload
    }

    command += " " + host;

    // Infinite loop if count is 0
    if (count == 0) {
        std::cout << "Press Ctrl+C to stop.\n";
        signal(SIGINT, handle_signal);  // Register signal handler

        while (running) {
            int result = std::system(command.c_str());
            if (result != 0) {
                std::cerr << "Ping command failed with error code: " << result << std::endl;
            }
            std::cout << "Pinging " << host << "...\n";
        }
    }
    else {
        // Single execution with specified count
        int result = std::system(command.c_str());
        if (result != 0) {
            std::cerr << "Ping command failed with error code: " << result << std::endl;
        }
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

#include <iostream>
#include <string>
#include <csignal>

void cmd_exit() {
    exit(EXIT_SUCCESS);
}

void handle_ctrl_c(int signum) {
    cmd_exit();
}

int main() {
    signal(SIGINT, handle_ctrl_c);
    std::string prompt("microsql » ");
    std::string command;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, command);

        if (command == "exit" || command == "quit") {
            cmd_exit();
        } 
        else if (!command.empty()) {
            std::cout << "Unknown command" << std::endl;
        }
        else {
            std::cout << command;
        }
    }
    return 0;
}
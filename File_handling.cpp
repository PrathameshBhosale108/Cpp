#include <iostream>
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

void list_files(const fs::path& dir_path) {
    std::cout << "Contents of " << dir_path << ":\n";
    for (const auto& entry : fs::directory_iterator(dir_path)) {
        std::cout << (entry.is_directory() ? "[DIR] " : "[FILE] ") << entry.path().filename().string() << '\n';
    }
}

void create_directory(const fs::path& dir_path) {
    try {
        if (fs::create_directory(dir_path)) {
            std::cout << "Directory created successfully: " << dir_path << '\n';
        } else {
            std::cerr << "Failed to create directory: " << dir_path << '\n';
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }
}

void copy_file(const fs::path& source, const fs::path& destination) {
    try {
        fs::copy(source, destination);
        std::cout << "File copied successfully from " << source << " to " << destination << '\n';
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }
}

void move_file(const fs::path& source, const fs::path& destination) {
    try {
        fs::rename(source, destination);
        std::cout << "File moved successfully from " << source << " to " << destination << '\n';
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }
}

void display_menu() {
    std::cout << "\nFile Manager Menu:\n"
              << "1. List files in a directory\n"
              << "2. Create a directory\n"
              << "3. Copy a file\n"
              << "4. Move a file\n"
              << "5. Exit\n"
              << "Enter your choice: ";
}

int main() {
    int choice;
    fs::path current_path = fs::current_path();
    std::cout << "Welcome to the Command-Line File Manager!\n";

    do {
        display_menu();
        std::cin >> choice;
        switch (choice) {
            case 1: {
                std::cout << "Enter directory path to list files: ";
                std::string path;
                std::cin >> path;
                list_files(path);
                break;
            }
            case 2: {
                std::cout << "Enter the directory path to create: ";
                std::string path;
                std::cin >> path;
                create_directory(path);
                break;
            }
            case 3: {
                std::cout << "Enter the source file path to copy: ";
                std::string source, destination;
                std::cin >> source;
                std::cout << "Enter the destination file path: ";
                std::cin >> destination;
                copy_file(source, destination);
                break;
            }
            case 4: {
                std::cout << "Enter the source file path to move: ";
                std::string source, destination;
                std::cin >> source;
                std::cout << "Enter the destination file path: ";
                std::cin >> destination;
                move_file(source, destination);
                break;
            }
            case 5:
                std::cout << "Exiting File Manager. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}

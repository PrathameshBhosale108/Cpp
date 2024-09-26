#include <iostream>
#include <string>
#include <map>
#include <algorithm>

// Convert user input to lowercase for easier comparison
std::string toLowerCase(const std::string &str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

// Function to simulate chatbot responses
void chatBotResponse(const std::string &input, std::map<std::string, std::string> &memory) {
    std::string lowerInput = toLowerCase(input);

    // Basic responses
    if (lowerInput == "hello" || lowerInput == "hi") {
        std::cout << "Chatbot: Hello! How can I help you today?" << std::endl;
    } else if (lowerInput == "how are you?" || lowerInput == "how's it going?") {
        std::cout << "Chatbot: I'm just a program, but I'm doing great! How about you?" << std::endl;
    } else if (lowerInput == "bye" || lowerInput == "goodbye") {
        std::cout << "Chatbot: Goodbye! Have a great day!" << std::endl;
    } else if (lowerInput.find("my name is") != std::string::npos) {
        std::string name = input.substr(input.find("is") + 3);
        memory["userName"] = name;
        std::cout << "Chatbot: Nice to meet you, " << name << "!" << std::endl;
    } else if (lowerInput == "what's my name?" || lowerInput == "who am i?") {
        if (memory.find("userName") != memory.end()) {
            std::cout << "Chatbot: Your name is " << memory["userName"] << "." << std::endl;
        } else {
            std::cout << "Chatbot: I don't know your name yet. Can you tell me your name?" << std::endl;
        }
    } else {
        // Handle unknown input
        std::cout << "Chatbot: I'm not sure about that. Can you provide more details?" << std::endl;
    }
}

int main() {
    std::string input;
    std::map<std::string, std::string> memory;  // To store user-specific information

    std::cout << "Chatbot: Hi! I'm your chatbot. Type 'bye' to exit." << std::endl;

    // Chat loop
    while (true) {
        std::cout << "You: ";
        std::getline(std::cin, input);

        if (toLowerCase(input) == "bye") {
            chatBotResponse(input, memory);
            break;
        }

        chatBotResponse(input, memory);
    }

    return 0;
}

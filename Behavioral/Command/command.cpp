#include <iostream>
#include <string>
#include <memory>
#include <unordered_map>
#include <functional>

// Base Command Interface
class ICommand {
public:
    virtual ~ICommand() = default;
    virtual void execute() const = 0;
};

// Concrete Commands
class SaveCommand : public ICommand {
public:
    void execute() const override {
        std::cout << "Saving the document.\n";
    }
};

class OpenCommand : public ICommand {
public:
    void execute() const override {
        std::cout << "Opening a document.\n";
    }
};

class ExitCommand : public ICommand {
public:
    void execute() const override {
        std::cout << "Exiting the application.\n";
    }
};

// Command Delegator
class CommandDelegator {
private:
    std::unordered_map<std::string, std::shared_ptr<ICommand>> commandMap_;
public:
    void registerCommand(const std::string& commandName, std::shared_ptr<ICommand> command) {
        commandMap_[commandName] = command;
    }
    void executeCommand(const std::string& commandName) const {
        auto it = commandMap_.find(commandName);
        if (it != commandMap_.end() && it->second) {
            it->second->execute();
        } else {
            std::cout << "Command not found: " << commandName << "\n";
        }
    }
};

// Client code: Buttons and Shortcuts
int main() {
    // Create commands
    auto saveCmd = std::make_shared<SaveCommand>();
    auto openCmd = std::make_shared<OpenCommand>();
    auto exitCmd = std::make_shared<ExitCommand>();

    // Register commands with the delegator
    CommandDelegator delegator;
    delegator.registerCommand("save", saveCmd);
    delegator.registerCommand("open", openCmd);
    delegator.registerCommand("exit", exitCmd);

    // Simulating button clicks
    std::cout << "Button clicked: Save\n";
    delegator.executeCommand("save");

    std::cout << "Button clicked: Open\n";
    delegator.executeCommand("open");

    // Simulating a keyboard shortcut
    std::cout << "Shortcut pressed: Ctrl+Q\n";
    delegator.executeCommand("exit");

    return 0;
}

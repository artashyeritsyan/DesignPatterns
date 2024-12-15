#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Observer {
public:
    virtual void update(const std::string& chatName, const std::string& message) = 0;
    virtual ~Observer() = default;
};

class Subject {
public:
    virtual void subscribe(Observer* observer) = 0;
    virtual void unsubscribe(Observer* observer) = 0;
    virtual void notify(const std::string& message) = 0;
    virtual ~Subject() = default;
};

class Chat : public Subject {
private:
    std::string _name;
    std::vector<Observer*> _observers;

public:
    Chat(const std::string& name) : _name(name) {}

    void subscribe(Observer* observer) override {
        _observers.push_back(observer);
    }

    void unsubscribe(Observer* observer) override {
        _observers.erase(
            std::remove(_observers.begin(), _observers.end(), observer),
            _observers.end()
        );
    }

    void notify(const std::string& message) override {
        for (auto observer : _observers) {
            observer->update(_name, message);
        }
    }

    void postMessage(const std::string& message) {
        std::cout << "[Chat: " << _name << "] " << message << std::endl;
        notify(message);
    }
};

class User : public Observer {
private:
    std::string _name;

public:
    User(const std::string& name) : _name(name) {}

    void update(const std::string& chatName, const std::string& message) override {
        std::cout << "[Notification for " << _name << "] New message in " << chatName << ": " << message << std::endl;
    }
};

int main() {
    Chat chat("EDA group");

    User user1("John");
    User user2("Bob");

    chat.subscribe(&user1);
    chat.subscribe(&user2);

    chat.postMessage("Hello guys");

    chat.unsubscribe(&user1);

    chat.postMessage("How are you ?");

    return 0;
}

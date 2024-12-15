#include <iostream>

class GameState {
public:
    virtual void handleAction() = 0;
    virtual ~GameState() = default;
};

class Game {
private:
    GameState* _state;

public:
    explicit Game(GameState* initialState) : _state(initialState) {}

    void changeState(GameState* newState) {
        _state = newState;
    }

    void execute() {
        _state->handleAction();
    }
};

class ExploringState : public GameState {
public:
    void handleAction() override {
        std::cout << "Exploring mode!" << std::endl;
    }
};

class CombatState : public GameState {
public:
    void handleAction() override {
        std::cout << "Combat mode!" << std::endl;
    }
};

class RestingState : public GameState {
public:
    void handleAction() override {
        std::cout << "Resting mode" << std::endl;
    }
};

int main() {
    ExploringState exploringState;
    CombatState combatState;
    RestingState restingState;

    Game game(&exploringState);

    game.execute();

    std::cout << "Switching to Combat state" << std::endl;
    game.changeState(&combatState);
    game.execute();

    std::cout << "Switching to Resting state" << std::endl;
    game.changeState(&restingState);
    game.execute();

    std::cout << "Back to Exploring" << std::endl;
    game.changeState(&exploringState);
    game.execute();

    return 0;
}

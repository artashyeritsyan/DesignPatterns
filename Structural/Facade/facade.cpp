#include <iostream>

class Amplifier {
public:
    void TurnOnAmplifier() {
        std::cout << "Turning on the amplifier" << std::endl;
    }

    void TurnOffAmplifier() {
        std::cout << "Turning off the amplifier" << std::endl;
    }

};

class DVDPlayer {
public:
    void Play() {
        std::cout << "Play the DVD player" << std::endl;
    }

    void Stop() {
        std::cout << "Stop the DVD player" << std::endl;
    }
};

class Projector {
public:
    void TurnOnProjector() {
        std::cout << "Turning on the Projector" << std::endl;
    }

    void TurnOffProjector() {
        std::cout << "Turning off the Projector" << std::endl;
    }
};

class Screen {
public:
    void RiseScreen() {
        std::cout << "Screen is rised" << std::endl;
    }

    void LowerScreen() {
        std::cout << "Screen is lowered" << std::endl;
    }
};

class Lights {
public:
    void TurnOnLights() {
        std::cout << "Lights turned on" << std::endl;
    }

    void TurnOffLights() {
        std::cout << "Lights dimmed" << std::endl;
    }
};

class HomeTheaterFacade {
public:
    void watchMovie() {
        amplifier->TurnOnAmplifier();
        dvdPlayer->Play();
        projector->TurnOnProjector();
        screen->LowerScreen();
        lights->TurnOffLights();
    }

    void endMovie() {
        amplifier->TurnOffAmplifier();
        dvdPlayer->Stop();
        projector->TurnOffProjector();
        screen->RiseScreen();
        lights->TurnOnLights();
    }

private:
    Amplifier* amplifier;
    DVDPlayer* dvdPlayer;
    Projector* projector;
    Screen* screen;
    Lights* lights;
};

int main() {
    HomeTheaterFacade* homeThreater = new HomeTheaterFacade;

    homeThreater->watchMovie();

    std::cout << "\n I am Watching the movie \n" <<std::endl;
    homeThreater->endMovie();

    return 0;
}


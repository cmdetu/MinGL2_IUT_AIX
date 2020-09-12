#include <thread>

#include "audio/minglaudioengine.h"
#include "gui/text.h"
#include "transition/transition_engine.h"

/**
 * @brief FPS_LIMIT : The framerate limit for the game
 */
#define FPS_LIMIT 60

using namespace std;

void displayFramerate(const std::chrono::microseconds &frameTime, MinGL &window)
{
    const string framerateStr = to_string(1 / (frameTime.count() / 1000000.f));
    window << nsGui::Text(Vec2D(5, 15), framerateStr + " FPS", KPurple);
} // displayFramerate()

int main()
{
    // Initialise the graphics and event systems
    MinGL Window("minGL 2", Vec2D(640, 640), KBlack);
    Window.initGlut();
    Window.initGraphic();

    // Instantie un texte
    nsGui::Text text(Vec2D(320, 320), "Hello, World!", KRed, GlutFont::BITMAP_9_BY_15, nsGui::Text::HorizontalAlignment::ALIGNH_CENTER,
                     nsGui::Text::VerticalAlignment::ALIGNV_CENTER);

    // Instantie un gestionnaire de transition
    nsTransition::TransitionEngine transitionEngine;
    transitionEngine.startContract(nsTransition::TransitionContract(text, nsGui::Text::TransitionIds::TRANSITION_COLOR_RGB,
                                                                    chrono::seconds(1), {0, 0, 255}, chrono::seconds::zero(),
                                                                    nsTransition::Transition::TransitionMode::MODE_LOOP_SMOOTH));


    nsAudio::MinGLAudioEngine Ae;
    Ae.setMusic("resources/theme.wav", true);
    Ae.startMusicFromBeginning();

    chrono::microseconds frameTime = chrono::microseconds::zero();
    while (!Window.isExitRequested())
    {
        // Gets system clock at the beginning of the loop
        chrono::time_point<chrono::steady_clock> start = chrono::steady_clock::now();

        // Clear screen each frame
        Window.clearScreen();

        // Met a jour le gestionnaire de transition
        transitionEngine.update(frameTime);

        // Affiche le texte
        Window << text;

        // Display the framerate
        displayFramerate(frameTime, Window);

        // Push frame to the window
        Window.updateGraphic();

        // Wait a bit to limit the framerate and let the CPU relax
        this_thread::sleep_for(chrono::milliseconds(1000 / FPS_LIMIT) - chrono::duration_cast<chrono::microseconds>(chrono::steady_clock::now() - start));

        // Get system time at the end to compute rendering time
        frameTime = chrono::duration_cast<chrono::microseconds>(chrono::steady_clock::now() - start);
    }

    return 0;
} // main()

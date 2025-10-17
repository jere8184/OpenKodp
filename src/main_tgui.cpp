#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SDL-Renderer.hpp>

#include <SDL2/SDL.h>      // At least 2.0.18

#include "frontend/window.hpp"

bool runExample(tgui::BackendGui& gui)
{
	std::shared_ptr<tgui::Slider> slider = tgui::Slider::create(0, 100);
	slider->setPosition(350, 280);
	slider->setSize(100, 20);
	slider->setVisible(true);
	slider->getRenderer()->setTrackColor(tgui::Color::Red);
	slider->getRenderer()->setThumbColor(tgui::Color::Blue);
	//slider->onValueChange([](float value){ std::cout << "Slider value changed: " << value << std::endl; });
	slider->onFocus([]{ std::cout << "Slider focused" << std::endl; });
	slider->onUnfocus([]{ std::cout << "Slider focus lost" << std::endl; });
	slider->onMouseEnter([]{ std::cout << "Mouse entered slider" << std::endl; });
	slider->onMouseLeave([&gui]{ std::cout << "Mouse left slider. New value is: " << gui.get<tgui::Slider>("slider")->getValue() << std::endl; });
		
    gui.add(slider, "slider");
	return true;
}

// We don't put this code in main() to make sure that all TGUI resources are destroyed before destroying SDL
void run_application(window* window)
{
    tgui::Gui gui{window->sdl_window, window->sdl_render};
    if (!runExample(gui))
        return;

    gui.mainLoop();
}

// Note that no error checking is performed on SDL initialization in this example code
int main(int, char**)
{
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

	window window("TGUI example - SDL_RENDERER backend", 800, 600);

    // SDL_TTF (and SDL) needs to be initialized before using TGUI

    run_application(&window);

    // All TGUI resources must be destroyed before SDL_TTF (and SDL) is cleaned up
    TTF_Quit();
    SDL_Quit();
    return 0;
}

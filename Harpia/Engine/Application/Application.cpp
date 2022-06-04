//
// Created by Ricardo Bustamante <ricardo@busta.dev> on 29/05/2022.
//

#include "Application.h"

#include <SDL.h>

#include "Debug.h"
#include "Renderer.h"
#include "InputSystem.h"
#include "AudioSystem.h"

namespace Harpia {
    Application::Application(Renderer *renderer, void(*configure)(Configuration &config)) {
        if (renderer == nullptr) {
            DebugLogError("No renderer set.");
            return;
        }
        _renderer = renderer;

        _input = new InputSystem();

        _audioSystem = new AudioSystem();

        _createdWithSuccess = true;
        DebugLog("Application created");

        if (configure == nullptr) {
            DebugLogError("Configure method missing");
            return;
        }
        configure(configuration);
    }

    Application::~Application() {
        delete _input;
        _input = nullptr;

        delete _audioSystem;
        _audioSystem = nullptr;

        DebugLog("Application destroyed");
    }

    int Application::Initialize() {
        if(_input== nullptr || _audioSystem == nullptr || _renderer == nullptr){
            DebugLogError("Mandatory system was null.");
            return -1;
        }

        auto result = SDL_Init(SDL_INIT_VIDEO | _audioSystem->GetInitFlags());
        if (result < 0) {
            DebugLogError("SDL was not initialized. SDL_Error: %s", SDL_GetError());
            return result;
        }

        _window = SDL_CreateWindow(configuration.game.title.c_str(), SDL_WINDOWPOS_UNDEFINED,
                                   SDL_WINDOWPOS_UNDEFINED, configuration.window.size.x, configuration.window.size.y,
                                   SDL_WINDOW_SHOWN | _renderer->GetWindowFlags());

        if (_window == nullptr) {
            DebugLogError("Window could not be created! SDL Error: %s", SDL_GetError());
            return -1;
        }

        result = _renderer->Initialize(configuration.game, _window);

        if (result < 0) {
            DebugLogError("Renderer was not initialized. SDL_Error: %s", SDL_GetError());
            return result;
        }

        result = _input->Initialize(configuration.input);
        if (result < 0) {
            DebugLogError("InputSystem was not initialized. SDL_Error: %s", SDL_GetError());
            return result;
        }

        result = _audioSystem->Initialize(configuration.audio);
        if(result < 0){
            DebugLogError("AudioSystem was not initialized. SDL_Error: %s", SDL_GetError());
            return result;
        }

        return 0;
    }

    void Application::Quit() {
        _renderer->Destroy();
        delete _renderer;
        _renderer = nullptr;

        SDL_DestroyWindow(_window);
        _window = nullptr;

        SDL_Quit();
    }

    int Application::Execute() {
        if (!_createdWithSuccess) {
            DebugLogError("Application not created with success.");
            return -1;
        }

        DebugLog("Application %s is starting", configuration.game.title.c_str());
        _result = Initialize();
        if (_result != 0) {
            return _result;
        }

        bool quit = false;
        SDL_Event e;

        while (!quit) {
            _input->CleanKeyState();

            while (SDL_PollEvent(&e) != 0) {
                switch (e.type) {
                    case SDL_QUIT:
                        quit = true;
                        DebugLog("Requested to quit");
                        break;
                    case SDL_KEYDOWN: {
                        _input->OnKeyDown(&e);
                        break;
                    }
                    case SDL_KEYUP: {
                        _input->OnKeyUp(&e);
                        break;
                    }
                }
            }

            _renderer->UpdateFrame();
        }

        DebugLog("Quit");
        Quit();
        return _result;
    }
}
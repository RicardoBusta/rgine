//
// Created by Ricardo Bustamante <ricardo@busta.dev> on 04/06/2022.
//

#include "MainScene.h"
#include "Debug.h"
#include "AudioComponent.h"
#include "MusicComponent.h"
#include "CameraComponent.h"
#include "TestAudio.h"

namespace SampleGame {
    void SampleGame::MainScene::Load(Harpia::Application *application) {
        DebugLog("Starting MainScene");

        auto audioObject = CreateObject();

        auto audio = audioObject->AddComponent<Harpia::AudioComponent>();
        audio->SetAudioFile("Assets/Audio/jump.wav");

        auto music = audioObject->AddComponent<Harpia::MusicComponent>();
        music->SetMusicFile("Assets/Music/idle.ogg");

        audioObject->AddComponent<TestAudio>();

        auto cameraObject = CreateObject();
        auto camera = cameraObject->AddComponent<Harpia::CameraComponent>();
        camera->SetViewport(Harpia::RectInt(0,0,200,200));
        camera->SetClearColor(Harpia::Color(1,0,0,1));
        auto camera2 = cameraObject->AddComponent<Harpia::CameraComponent>();
        camera2->SetViewport(Harpia::RectInt(200,0,200,200));
        camera2->SetClearColor(Harpia::Color(0,0,1,1));

    }
}
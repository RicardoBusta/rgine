//
// Created by Ricardo Bustamante <ricardo@busta.dev> on 06/06/2022.
//
#include "TestAudio.h"

namespace SampleGame {
    void TestAudio::Start() {
        audio = GetComponent<Harpia::AudioComponent>();
    }

    void TestAudio::Update() {
        //if(Input.GetKey(SDLK_UP).down){
        audio->Play();
        //}
    }
} // SampleGame
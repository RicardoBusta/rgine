//
// Created by Ricardo Bustamante <ricardo@busta.dev> on 06/06/2022.
//

#ifndef HARPIAGAMEENGINE_MUSICCOMPONENT_H
#define HARPIAGAMEENGINE_MUSICCOMPONENT_H

#include <string>
#include "Component.h"
#include "GlobalDefines.h"

namespace Harpia {
    class MusicComponent : public Component {
    private:
        MusicAsset *_music = nullptr;
        Internal::AudioSystem *_audioSystem = nullptr;
    public:
        void SetMusicFile(const std::string &path);

        void Play();

        void Pause(bool pause);

        bool IsPaused();

    protected:
        void Initialize_Internal(Internal::Application_Internal *applicationInternal) override;
    };
} // Harpia

#endif //HARPIAGAMEENGINE_MUSICCOMPONENT_H
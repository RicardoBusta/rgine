//
// Created by Ricardo Bustamante <ricardo@busta.dev> on 16/06/2022.
//

#ifndef HARPIAGAMEENGINE_UI_SYSTEM_H
#define HARPIAGAMEENGINE_UI_SYSTEM_H

#include "hge/i_application_system.h"
#include "hge/internal_defines.h"
#include "imgui/imgui.h"

namespace Harpia::Internal {
    class UISystem : public Internal::IApplicationSystem {
    public:
        int Initialize(GameConfiguration &configuration, Application *application, CoreSystem *coreSystem);
        int GetInitFlags() override;
        int GetWindowFlags() override;
        void Quit() override;
    };
}

#endif //HARPIAGAMEENGINE_UI_SYSTEM_H

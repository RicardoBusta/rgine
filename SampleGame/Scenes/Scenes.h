//
// Created by Ricardo Bustamante <ricardo@busta.dev> on 04/06/2022.
//

#ifndef HARPIAGAMEENGINE_SCENES_H
#define HARPIAGAMEENGINE_SCENES_H

namespace Harpia{
    class ISceneDescription;
}

namespace SampleGame {
    class Scenes{
        Harpia::ISceneDescription * MainScene();
    };
}

#endif //HARPIAGAMEENGINE_SCENES_H
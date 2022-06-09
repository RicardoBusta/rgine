//
// Created by Ricardo Bustamante <ricardo@busta.dev> on 05/06/2022.
//

#ifndef HARPIAGAMEENGINE_COMPONENT_H
#define HARPIAGAMEENGINE_COMPONENT_H

#include "Component_Internal.h"
#include "Object.h"
#include "InputReader.h"

namespace Harpia {
class Component : private Internal::Component_Internal {
    private:
    public:
        Object *GetObject();

        template<class T>
        T *GetComponent() {
            return _object->GetComponent<T>();
        }

        virtual void Start() {};

        virtual void Update() {};

        InputReader *Input();

//    protected:
//        void Initialize_Internal(Internal::Application_Internal *applicationInternal) override;
    };
} // Harpia

#endif //HARPIAGAMEENGINE_COMPONENT_H
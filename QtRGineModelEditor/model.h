#ifndef MODEL_H
#define MODEL_H

#include <QMap>
#include <QString>
#include "modelobject.h"
#include "modelanimation.h"

class Model
{
public:
    Model();

    //each separated object on the model. has its own vertexes, normals, material and texture.
    QMap<QString,ModelObject> object;
    //each interval of animation (starting frame and ending frame)
    QMap<QString, ModelAnimation> animation;
    //map each keyframe into it's frame position
    QMap<int,int> keyframes;

    void load(QString filename);
    void addFace();
};

#endif // MODEL_H
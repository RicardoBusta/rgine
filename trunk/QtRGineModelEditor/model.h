#ifndef MODEL_H
#define MODEL_H

#include <QMap>
#include <QString>
#include "material.h"

/**************************************************************************\
    Model Structure Classes
\**************************************************************************/

class ModelAnimation
{
public:
    ModelAnimation(){
        keyframeStart=keyframeEnd=0;
    }

    int keyframeStart;
    int keyframeEnd;
};

class ModelNormal
{
public:
    ModelNormal(){
        x=y=z=0;
    }

    int id;

    float x,y,z;
};

class ModelVertex
{
public:
    ModelVertex(){
        x=y=z=0;
    }

    int id;

    float x,y,z;
};

class ModelTexCoord
{
public:
    ModelTexCoord(){
        u=v=0;
    }

    int id;

    float u,v;
};

class ModelFace
{
public:
    ModelFace(){
        for(int i=0;i<3;i++){
            vertex[i]=normal[i]=texcoord[i]=0;
        }
    }

    int id;

    int vertex[3];
    int normal[3];
    int texcoord[3];
};

class ModelObject
{
public:
    ModelObject(){
        material=0;
        texture="";
        hide=false;
    }

    QString name;

    bool hide; //make per-keyframe option
    int material;
    QString texture;

    QMap<int, ModelVertex> vertex;
    QMap<int, ModelNormal> normal;
    QMap<int, ModelTexCoord> texcoord;
    QMap<int, ModelFace> face;
};

/**************************************************************************\
    Main Model Class
\**************************************************************************/

class Model
{
public:
    Model();

    QString name;

    int keyframeCount;

    //each separated object on the model. has its own vertexes, normals, material and texture.
    QMap<QString,ModelObject> object;
    //each interval of animation (starting frame and ending frame)
    QMap<QString, ModelAnimation> animation;
    //map each keyframe into it's frame position
    QMap<int,int> keyframe;
    //materials
    QMap<int,Material> material;

    void clear();
    void save(QString filename);
    void load(QString filename);

    QString currentObject;

    int maxVertexId;
    int maxFaceId;

    int currentVertexId;
    int currentFaceId;

    void addFace();
    void addVertex();

    void removeFace();
    void removeVertex();
};

#endif // MODEL_H
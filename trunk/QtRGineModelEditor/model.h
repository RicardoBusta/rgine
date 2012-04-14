#ifndef MODEL_H
#define MODEL_H

#include <QMap>
#include <QString>
#include "material.h"
#include "normal.h"

/**************************************************************************\
    Model Structure Classes
\**************************************************************************/

enum CURRENT_EDIT_MODE{CURRENT_NONE,CURRENT_MODEL,CURRENT_OBJECT,CURRENT_VERTEX,CURRENT_NORMAL,CURRENT_TEXTURE,CURRENT_FACE,CURRENT_MATERIAL};

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
        a=t=0;
    }

    int id;

    int a,t;
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

    CURRENT_EDIT_MODE current_mode;

    QString currentObjectId;

    int maxMaterialId;
    int maxNormalId;
    int maxVertexId;
    int maxFaceId;
    int maxTextureId;

    int currentMaterialId;
    int currentNormalId;
    int currentVertexId;
    int currentFaceId;
    int currentTextureId;

    ModelVertex *currentVertex();
    ModelNormal *currentNormal();
    ModelFace *currentFace();

    /* Object Control */
    void objectAdd();
    void removeObject();

    /* Material Control */
    void materialAdd();
    void removeMaterial();

    /* Face Control */
    void faceAdd();
    void removeFace();

    /* Vertex Control */
    void addVertex();
    void removeVertex();
    void changeVertexX(float v);
    void changeVertexY(float v);
    void changeVertexZ(float v);
};

#endif // MODEL_H

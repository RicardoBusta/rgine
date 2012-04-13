#include "model.h"

#include <QFile>
#include <QTextStream>
#include <QStringList>

Model::Model()
{
    clear();
}

void Model::clear(){
    keyframeCount = 0;
    currentObject = "";

    maxMaterialId = -1;
    maxFaceId = -1;
    maxVertexId = -1;

    currentMaterialId = -1;
    currentFaceId = -1;
    currentVertexId = -1;

    foreach(ModelObject o, object){
        o.normal.clear();
        o.texcoord.clear();
        o.texture.clear();
        o.vertex.clear();
    }
    animation.clear();
    object.clear();
    keyframe.clear();
    material.clear();
}

void Model::load(QString filename)
{
    QFile file(filename);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream in(&file);
        QString line = in.readLine();
        QString currentObject = "";
        int currentId;
        while (!line.isNull()) {
            QStringList list;
            QStringList listassist;
            list = line.split(" ");
            if(list.at(0).length()!=1){
                //loadError();
            }

            switch(list.first().toAscii().at(0)){
            case '#':
                break;
            case 's':
                if(list.size()==2){
                    name = list.at(1);
                }else{
                    //loadError();
                }
                break;
            case 'k':
                if(list.size()==2){
                    keyframe[keyframeCount++] = list.at(1).toInt();
                }else{
                    //loadError();
                }
                break;
            case 'a':
                if(list.size()==2){
                    QString id = list.at(1);
                    animation[id] = ModelAnimation();
                    animation[id].keyframeStart = list.at(2).toInt();
                    animation[id].keyframeEnd = list.at(3).toInt();
                }else{
                    //loadError();
                }
                break;
            case 'm':
                if(list.size()==15){
                    int id = list.at(1).toInt();
                    material[id] = Material();

                    material[id].id = id;

                    material[id].emission[0] = list.at(2).toFloat();
                    material[id].emission[1] = list.at(3).toFloat();
                    material[id].emission[2] = list.at(4).toFloat();
                    material[id].emission[3] = list.at(5).toFloat();

                    material[id].diffuse[0] = list.at(6).toFloat();
                    material[id].diffuse[1] = list.at(7).toFloat();
                    material[id].diffuse[2] = list.at(8).toFloat();
                    material[id].diffuse[3] = list.at(9).toFloat();

                    material[id].specular[0] = list.at(10).toFloat();
                    material[id].specular[1] = list.at(11).toFloat();
                    material[id].specular[2] = list.at(12).toFloat();
                    material[id].specular[3] = list.at(13).toFloat();

                    material[id].shininess[0] = list.at(14).toFloat();
                }else{
                    //loadError();
                }
                break;
            case 'o':
                if(list.size()==4){
                    currentObject = list.at(1);
                    object[currentObject] = ModelObject();
                    object[currentObject].name = currentObject;
                    object[currentObject].material = list.at(2).toInt();
                    object[currentObject].texture = list.at(3);
                }else{
                    //loadError();
                }
                break;
            case 'v':
                if(list.size()==5){
                    currentId = list.at(1).toInt();
                    if(currentId > maxVertexId){
                        maxVertexId = currentId;
                    }
                    object[currentObject].vertex[currentId] = ModelVertex();
                    object[currentObject].vertex[currentId].id = currentId;
                    object[currentObject].vertex[currentId].x = list.at(2).toFloat();
                    object[currentObject].vertex[currentId].y = list.at(3).toFloat();
                    object[currentObject].vertex[currentId].z = list.at(4).toFloat();
                }else{
                    //loadError();
                }
                break;
            case 'n':
                if(list.size()==5){
                    currentId = list.at(1).toInt();
                    object[currentObject].normal[currentId] = ModelNormal();
                    object[currentObject].normal[currentId].id = currentId;
                    object[currentObject].normal[currentId].x = list.at(2).toFloat();
                    object[currentObject].normal[currentId].y = list.at(3).toFloat();
                    object[currentObject].normal[currentId].z = list.at(4).toFloat();
                }else{
                    //loadError();
                }
                break;
            case 't':
                if(list.size()==4){
                    currentId = list.at(1).toInt();
                    object[currentObject].texcoord[currentId] = ModelTexCoord();
                    object[currentObject].texcoord[currentId].id = currentId;
                    object[currentObject].texcoord[currentId].u = list.at(2).toFloat();
                    object[currentObject].texcoord[currentId].v = list.at(3).toFloat();
                    currentId ++;
                }else{
                    //loadError();
                }
                break;
            case 'f':
                currentId = list.at(1).toInt();
                if(currentId > maxFaceId){
                    maxFaceId = currentId;
                }
                object[currentObject].face[currentId] = ModelFace();
                if(list.size()==5){
                    for(int i=0;i<3;i++){
                        listassist = list.at(i+2).split("/");
                        object[currentObject].face[currentId].id = currentId;
                        object[currentObject].face[currentId].vertex[i]=listassist.at(0).toFloat();
                        object[currentObject].face[currentId].texcoord[i]=listassist.at(1).toFloat();
                        object[currentObject].face[currentId].normal[i]=listassist.at(2).toFloat();
                    }
                }else{
                    //loadError();
                }
                break;
            default:
                //loadError();
                break;
            }
            line = in.readLine();
        }
        file.close();
    }
}

void Model::save(QString filename){
    QFile file(filename);
    if (file.open(QIODevice::WriteOnly)){
        QTextStream out(&file);
        out << "s " << name << "\r\n";
        foreach(ModelAnimation a,this->animation){

        }
        foreach(Material m,this->material){
            out << "m "<< m.id;
            out << " " << m.emission[0] << " " << m.emission[1] << " " << m.emission[2] << " " << m.emission[3];
            out << " " << m.diffuse[0] << " " << m.diffuse[1] << " " << m.diffuse[2] << " " << m.diffuse[3];
            out << " " << m.specular[0] << " " << m.specular[1] << " " << m.specular[2] << " " << m.specular[3];
            out << " " << m.shininess[0] << "\r\n";
        }
        /*foreach(int k,this->keyframe){

        }*/
        foreach(ModelObject o, this->object){
            out << "o " << o.name << " " << o.material << " " << o.texture << "\r\n";
            foreach(ModelVertex v, o.vertex){
                out << "v " << v.id << " "<< v.x << " " << v.y << " " << v.z << "\r\n";
            }
            foreach(ModelNormal n, o.normal){
                out << "n " << n.id << " "<< n.x << " " << n.y << " " << n.z << "\r\n";
            }
            foreach(ModelTexCoord t, o.texcoord){
                out << "t " << t.id << " " << t.u << " " << t.v << "\r\n";
            }
            foreach(ModelFace f, o.face){
                out << "f " << f.id ;
                for(int i=0;i<3;i++){
                    out << " " << f.vertex[i] << "/" << f.texcoord[i] << "/" << f.normal[i];
                }
                out << "\r\n";
            }
        }
        file.close();
    }
}

/*
  Edit Methods
 */

void Model::addObject(){
    int i=0;
    while(object.contains(QString("New Object ").append(QString::number(i)))){
        i++;
    }
    currentObject = QString("New Object ").append(QString::number(i));
    object[currentObject] = ModelObject();
    object[currentObject].name = currentObject;
}

void Model::addMaterial(){
    if(currentObject!=""){
        maxMaterialId++;
        material[maxMaterialId] = Material();
        material[maxMaterialId].id = maxMaterialId;
    }
}

void Model::addFace()
{
    if(currentObject!=""){
        maxFaceId++;
        object[currentObject].face[maxFaceId] = ModelFace();
        object[currentObject].face[maxFaceId].id = maxFaceId;
    }
}

void Model::addVertex()
{
    if(currentObject!=""){
        maxVertexId++;
        object[currentObject].vertex[maxVertexId] = ModelVertex();
        object[currentObject].vertex[maxVertexId].id = maxVertexId;
    }
}

void Model::removeObject(){
    if(currentObject!=""){
        object.remove(currentObject);
    }
}
void Model::removeMaterial(){
    material.remove(currentMaterialId);
}

void Model::removeFace(){
    if(currentObject!="" and currentFaceId !=-1){
        object[currentObject].face.remove(currentFaceId);
    }
}

void Model::removeVertex(){
    if(currentObject!="" and currentVertexId !=-1){
        object[currentObject].vertex.remove(currentVertexId);
    }
}

/**
 * @file
 * @author Ricardo Bustamante de Queiroz <ricardobqueiroz@gmail.com>
 * @version
 *
 * @section LICENSE
 *
 * This file is part of RGine.
 *
 * RGine is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Foobar is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with RGine.  If not, see <http://www.gnu.org/licenses/>.
 *
 * @section DESCRIPTION
 * 
 * File: RPhysicalCapsule.cpp
 * Created on: Aug 5, 2011
 */

//#include "RPhysicalCapsule.h"
/*
RPhysicalCapsule::RPhysicalCapsule(REntity *entity, double mass)
    :RPhysicalObject(entity, mass) {

    float radius, height;
    vector3df scale = irrcapsule->getScale();

    vector3df min = ((IAnimatedMeshSceneNode*)irrcapsule)->getMesh()->getBoundingBox().MinEdge;
    vector3df max = ((IAnimatedMeshSceneNode*)irrcapsule)->getMesh()->getBoundingBox().MaxEdge;

    radius = ((max.X - min.X)/2.0)*scale.X;
    height = (max.Y - min.Y)*scale.Y;

    initialize(new btCapsuleShape(radius, height - 2.0*radius));
}*/
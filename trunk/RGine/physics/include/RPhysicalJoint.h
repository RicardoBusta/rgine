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
 * File: RPhysicalJoint.h
 * Created on: Aug 5, 2011
 */

#ifndef RPHYSICALJOINT_H_
#define RPHYSICALJOINT_H_

#include <btBulletDynamicsCommon.h>

#include "RPhysicalObject.h"

enum Joints {
	RJ_HINGE, RJ_UNIVERSAL, RJ_BALL, RJ_FIXED
};

class RPhysicalJoint {
public:
	btTypedConstraint* getConstraint();

private:
	Joints jointType;

	btTypedConstraint* constraint;

	//anchor: anchor position relative to obj1 basis
	btHingeConstraint* createHinge(RPhysicalObject* obj1,
			RPhysicalObject* obj2, btVector3 anchor, btVector3 axis);

public:
	RPhysicalJoint(RPhysicalObject* obj1, RPhysicalObject* obj2, btVector3 anchor,
			btVector3 axis);
	~RPhysicalJoint();

	Joints getType();

	//Hinge Joint
	void setLimits(float min, float max);
	void move(float force);

};

#endif /* RPHYSICALJOINT_H_ */
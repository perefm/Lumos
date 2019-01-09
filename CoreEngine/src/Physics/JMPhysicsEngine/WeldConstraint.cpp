#include "JM.h"
#include "Maths/Maths.h"
#include "WeldConstraint.h"
#include "PhysicsObject3D.h"

#include "Graphics/Renderers/DebugRenderer.h"

namespace jm
{

	WeldConstraint::WeldConstraint(PhysicsObject3D *obj1, PhysicsObject3D *obj2)
		: m_pObj1(obj1)
		, m_pObj2(obj2)
	{
		m_positionOffset = obj2->GetPosition() - obj1->GetPosition();
		m_orientation = obj2->GetOrientation();
	}

	void WeldConstraint::ApplyImpulse()
	{
		// Position
		maths::Vector3 pos(m_positionOffset);
		maths::Quaternion::RotatePointByQuaternion(m_pObj1->GetOrientation(), pos);
		pos += m_pObj1->GetPosition();
		m_pObj2->SetPosition(pos);

		// Orientation
		m_pObj2->SetOrientation(m_pObj1->GetOrientation() * m_orientation);
	}

	void WeldConstraint::DebugDraw() const
	{
		maths::Vector3 posA = m_pObj1->GetPosition();
		maths::Vector3 posB = m_pObj2->GetPosition();

		DebugRenderer::DrawThickLine(posA, posB, 0.02f, maths::Vector4(0.0f, 0.0f, 0.0f, 1.0f));
		DebugRenderer::DrawPointNDT(posA, 0.05f, maths::Vector4(1.0f, 0.8f, 1.0f, 1.0f));
		DebugRenderer::DrawPointNDT(posB, 0.05f, maths::Vector4(1.0f, 0.8f, 1.0f, 1.0f));
	}
}
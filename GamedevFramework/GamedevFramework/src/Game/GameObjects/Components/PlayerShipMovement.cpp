/***************************************************************************************
*	Title: PlayerShipMovement.cpp
*	Author: Brandao, Anderson
*	Date: 2015
*
***************************************************************************************/

#include "PlayerShipMovement.h"

PlayerShipMovement::PlayerShipMovement(GameObject* pOwner) : MovementComponent(pOwner) {
    setMaxSpeed(18.0f);
    setFrictionMultiplier(0.9f);
}

PlayerShipMovement::~PlayerShipMovement() {

}

void PlayerShipMovement::preMovement() {
}
void PlayerShipMovement::postMovement() {
    TransformComponent* pTransformComp(component_cast<TransformComponent>(*getOwner()));
    assert(pTransformComp);

    const Vector3& tr(pTransformComp->getTranslation());

    float limit(23.3f);

    if (tr.getX() < -limit) {
        pTransformComp->setTranslation(Vector3(-limit, tr.getY(), tr.getZ()));
        velocity_ *= Vector3(0.0f, 1.0f, 1.0f);
	} else if (tr.getX() > limit) {
        pTransformComp->setTranslation(Vector3(limit, tr.getY(), tr.getZ()));
        velocity_ *= Vector3(0.0f, 1.0f, 1.0f);
    }


}
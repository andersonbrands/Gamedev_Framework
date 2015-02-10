/***************************************************************************************
*	Title: PlayerShipMovement.cpp
*	Author: Brandao, Anderson
*	Date: 2015
*
***************************************************************************************/

#include "PlayerShipMovement.h"

PlayerShipMovement::PlayerShipMovement(GameObject* pOwner) : MovementComponent(pOwner) {

}

PlayerShipMovement::~PlayerShipMovement() {

}

void PlayerShipMovement::preMovement() {
}
void PlayerShipMovement::postMovement() {
    TransformComponent* pTransformComp(component_cast<TransformComponent>(*getOwner()));
    assert(pTransformComp);

    const Vector3& tr(pTransformComp->getTranslation());

    float limit(24.0f);

    if (tr.getX() < -limit) {
        pTransformComp->setTranslation(Vector3(-limit, tr.getY(), tr.getZ()));
        velocity_ *= Vector3(0.0f, 1.0f, 1.0f);
    } else if (tr.getX() > 24.0f) {
        pTransformComp->setTranslation(Vector3(limit, tr.getY(), tr.getZ()));
        velocity_ *= Vector3(0.0f, 1.0f, 1.0f);
    }


}
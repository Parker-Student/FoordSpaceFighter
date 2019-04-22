
#include "BioEnemyShip.h"

// sets the rules of the ship (speed,hp,hitbox)
BioEnemyShip::BioEnemyShip()
{
	SetSpeed(150);
	SetMaxHitPoints(1);
	SetCollisionRadius(20);
}


void BioEnemyShip::Update(const GameTime *pGameTime)
{   
	if (IsActive())//activates the ship after checking the game time
	{
		float x = sin(pGameTime->GetTotalTime() * Math::PI + GetIndex()); // uses sin to determine the path of the ship (should apear as waves.) 
		x *= GetSpeed() * pGameTime->GetTimeElapsed() * 1.4f;            // sets the speed of enemies based on the time elapsed in the game. Longer the game faster the enemies.
		TranslatePosition(x, GetSpeed() * pGameTime->GetTimeElapsed()); 

		if (!IsOnScreen()) Deactivate(); // stops the ships after they go off screen.
	}

	EnemyShip::Update(pGameTime); //updates enemy ships based on the game time.
}


void BioEnemyShip::Draw(SpriteBatch *pSpriteBatch) //draws the enemy ship.
{
	if (IsActive())
	{
		pSpriteBatch->Draw(m_pTexture, GetPosition(), Color::White, m_pTexture->GetCenter(), Vector2::ONE, Math::PI, 1);
	}
}

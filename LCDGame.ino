const float g = 1.5f;

#include "LCDGameEngine.h"
#include "Characters.h"
#include "GameObject.h"

class JumpAndRun : public LCDGameEngine {
  public:
    byte newState1, oldState1 = LOW;
    byte newState2, oldState2 = LOW;

    Player player;

  public:
    JumpAndRun(): 
      LCDGameEngine(16, 2, 11, 12, 4, 5, 6, 7)
    {
    }

  protected:
    virtual void setup() override
    {
      createChar(playerChar, playerData);
    }

    virtual void loop(float elapsed) override
    {

      newState1 = digitalRead(2);
      newState2 = digitalRead(3);

      if (newState1 == HIGH and oldState1 == LOW)
        jump();

      if (newState2 == HIGH and oldState2 == LOW)
        crouch();

      oldState1 = newState1;
      oldState2 = newState2;

      fill(' ');

      player.update(elapsed);
      player.draw(this);
    }

  public:
    void jump()
    {
      player.vy -= 0.5;
      Serial.println("Jump");
    }

    void crouch()
    {
      player.vy += 0.5;
      Serial.println("Courch");
    }
};


JumpAndRun game;

void setup()
{
  Serial.begin(9600);
  game.start();
}

void loop()
{
  game.update();
}

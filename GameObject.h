class GameObject {
  public:
    float x, y;
    float height;
    float vx, vy;
    char character;

    GameObject() = default;

    GameObject(float x, float y, float height, float vx, float vy, char character)
    {
      this->x = x;
      this->y = y;
      this->height = height;
      this->vx = vx;
      this->vy = vy;
      this->character = character;
    }

    virtual void update(float elapsed) {
      vy += g * elapsed;
      x += vx * elapsed;
      y += vy * elapsed;
    };

    virtual void draw(LCDGameEngine* game)
    {
      game->drawChar(x, y, character);
    }

};

class Player : public GameObject {
  public:
    Player() : GameObject(1.0f / 16.0f, 0.5f, 0.5f, 0.0f, 0.0f, playerChar)
    {
    }

    virtual void update(float elapsed) override
    {
      vy += g * elapsed;
      x += vx * elapsed;
      y += vy * elapsed;


      if (y > (1.0f - height)) {
        y = 1.0f - height;
        vy = 0.0f;
      }

      if (y < 0.0f) {
        y = 0.0f;
        vy = 0.0f;
      }
    }
};

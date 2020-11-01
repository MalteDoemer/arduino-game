class GameObject {
  public:
    float x, y;
    float w, h;
    float vx, vy;
    char character;

    GameObject() = default;

    GameObject(float x, float y, float w, float h, float vx, float vy, char character)
    {
      this->x = x;
      this->y = y;
      this->w = w;
      this->h = h;
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
    Player() : GameObject(0.0625, 0.5f, 0.0625, 0.5f, 0.0f, 0.0f, playerChar)
    {
    }

    virtual void update(float elapsed) override
    {
      vy += g * elapsed;
      x += vx * elapsed;
      y += vy * elapsed;


      if (y > (1.0f - h)) {
        y = 1.0f - h;
        vy = 0.0f;
      }

      if (y < 0.0f) {
        y = 0.0f;
        vy = 0.0f;
      }
    }
};

class Enemy : public GameObject {
  public:
    bool collide(Player* player) {
      
    }
};


#include <LiquidCrystal.h>

class LCDGameEngine {
  private:
    unsigned long time1, time2;

  protected:
    LiquidCrystal lcd;
    char* video;
    int width;
    int height;


  public:
    LCDGameEngine(int w, int h, byte rs, byte en, byte d0, byte d1, byte d2, byte d3, byte d4, byte d5, byte d6, byte d7)
      : lcd(rs, en, d0, d1, d2, d3, d4, d5, d6, d7)
    {
      width = w;
      height = h;
      video = new char[width * height];
    }

    LCDGameEngine(int w, int h, byte rs, byte en, byte d0, byte d1, byte d2, byte d3)
      : lcd(rs, en, d0, d1, d2, d3)
    {
      width = w;
      height = h;
      video = new char[width * height];
      lcd.begin(w, h);
      lcd.noBlink();
      lcd.noCursor();
    }

    ~LCDGameEngine()
    {
      if (video)
        delete[] video;
    }

    void start()
    {
      time1 = time2 = micros();
      setup();
    }

    void update()
    {
      time2 = micros();
      float elapsed = (float)(time2 - time1) / 1000000.0f;
      time1 = micros();

      loop(elapsed);

      for (int i = 0; i < width * height; i++) {
        lcd.setCursor(i % width, i / width);
        lcd.write(video[i]);
      }
    }

    void createChar(byte idx, byte charmap[])
    {
      lcd.createChar(idx, charmap);
    }

    void fill(char c)
    {
      memset(video, c, width * height);
    }

    void drawChar(int x, int y, char c)
    {
      video[y * width + y] = c;
    }

    void drawChar(float x, float y, char c)
    {
      int rx, ry;
      rx = x * width;
      ry = y * height;
      video[ry * width + rx] = c;
    }

  protected:
    virtual void setup() = 0;
    virtual void loop(float elapsed) = 0;
};

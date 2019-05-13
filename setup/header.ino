class App {
   private:
    String name = "unnamed";

   public:
    void setName(String name);
    String getName();
    virtual String print();
    virtual void refresh();
};

class FullColor : public App {
   private:
    byte color[3];

   public:
    FullColor(byte r, byte g, byte b);
    ~FullColor();
    String print();
    void refresh();
};

class SnakeA : public App {
   private:
    int delay;
    byte colorIndex;
    byte colorCount;
    short int position;
    byte colors[10];  //max 10 different colors
    long unsigned int lastMillis;

   public:
    SnakeA(int delay, byte colorCount, byte colors[]);
    ~SnakeA();
    String print();
    void refresh();
};

class Configuration {
   private:
   public:
    String wifiSSIDs[];
    String wifiKeys[];
    byte wifiIndex;
    byte brightness;
    byte cmdIndex;
    byte commandCount;
    String cmdArr[];
    void load();
    void store();
};
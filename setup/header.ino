class App {
   private:
    String name = "unnamed";

   public:
    void setName(String name);
    String getName();
    virtual void refresh();                 //Is called on every loop iteration / frame, so the current app can draw the pixels
    virtual String get();                   //returns cmd part that contains info for that object
    virtual void set(String parameters[]);  //sets object to info contained in parameters
};

class FullColor : public App {
   private:
    byte color[3] = {
        200, 50, 10};

   public:
    FullColor();
    ~FullColor();
    void refresh();
    String get();
    void set(String parameters[]);
};

class SnakeA : public App {
   private:
    int delay = 50;
    byte colorIndex;
    short int xPos;
    short int yPos;
    byte colorCount = 3;
    byte colors[10] = {
        2, 5, 8, 0, 0, 0, 0, 0, 0, 0};  //max 10 different colors
    long unsigned int lastMillis;
    boolean up = true;     // !up is down
    boolean right = true;  // !right is left
    boolean bounce = true;

   public:
    SnakeA();
    ~SnakeA();
    void refresh();
    String get();
    void set(String parameters[]);
};


class Clock : public App {
   private:
    byte color[2] = {5, 10};

   public:
    Clock();
    ~Clock();
    void refresh();
    String get();
    void set(String parameters[]);
};

class configManager {
   private:
   public:
    static void load();
    static void store();
};

class draw {
   private:
   public:
    static void pixel(short p, byte r, byte g, byte b);
    static void fill(byte r, byte g, byte b);
    static void xy(short x, short y, byte r, byte g, byte b);
    static void digit(byte digit, byte xOffs, byte yOffs, byte r, byte g, byte b);
};
void setup(void);

void loop(void);
void parser(String cmd);
void errorOut();
void output(String msg);
void outputln(String msg);
void btn_a_ISR();
void next(int steps);
void previous(int steps);
void checkSerial();
void sysReset();
void setTime(String parameters[]);
void printTime();
void addApp(String* parameters);
void delApp(int n);
void printApps();
void switchApps(int a, int b);
#define MAX_HOURS 24    // one record per hour of the day
#define BLANK_HOUR (-1) // marks a record that has not been captured yet

typedef struct reading {
  int hour;             // hour of the day (0 to 23)
  double temperature;   // temperature in degrees Celsius
  double humidity;      // relative humidity as a percentage
} Reading;

int createBlankFile(const char filename[]);
int writeReading(const char filename[], Reading reading);
int readReading(const char filename[], int hour, Reading *readingPtr);
void displayAllReadings(const char filename[]);
void displayFileInfo(const char filename[]);

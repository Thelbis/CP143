#include "A.h"
#include <stdio.h>

int main() {
  int choice;
  Reading tmpReading;
  char filename[21];
  printf("Enter a filename for the data file: ");
  scanf("%20s", filename);

  createBlankFile(filename);

  do {
    printf("\nMenu: 1=capture  2=show hour  3=show all  4=file info  0=exit\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 0:
        printf("Goodbye!\n");
        break;
      case 1:
        printf("Enter the hour (0 to 23): ");
        scanf("%d", &tmpReading.hour);
        if (tmpReading.hour < 0 || tmpReading.hour > MAX_HOURS-1) {
          printf("Hour not in range of 0 to 23\n");
          break;
        }
        printf("Enter the temperature and the humidity: ");
        scanf("%lf", &tmpReading.temperature);
        scanf("%lf", &tmpReading.humidity);

        if (writeReading(filename, tmpReading)) {
          printf("Reading for hour %d written to record %d.\n", tmpReading.hour, tmpReading.hour);
        } else {
          printf("Error while writing reading for hour %d\n", tmpReading.hour);
        }
        break;

      case 2:
        printf("Enter the hour (0 to 23): ");
        int hour;
        scanf("%d", &hour);
        if (hour < 0 || hour > MAX_HOURS-1) {
          printf("Hour not in range of 0 to 23\n");
          break;
        }
        printf("\n");

        readReading(filename, hour, &tmpReading);
        if (tmpReading.hour == BLANK_HOUR) {
          printf("No reading has been captured for hour %d yet.\n", hour);
          break;
        }
        printf("Hour  Temp (degC)  Humidity (%%)\n");
        printf("%4d  %11.1f  %12.1f\n", tmpReading.hour, tmpReading.temperature, tmpReading.humidity);
        break;

      case 3:
        printf("\n");
        displayAllReadings(filename);
        break;

      case 4:
        printf("\n");
        displayFileInfo(filename);
        break;

      default:
        printf("Not an allowed choice\n");
    }
  } while (choice != 0);
}

int createBlankFile(const char *filename) {
  FILE* fp = fopen(filename, "wb");
  if (fp == NULL) return 0;

  static const Reading blank = {BLANK_HOUR, 0.0, 0.0};
  Reading blankFile[MAX_HOURS];

  for (int i = 0; i < MAX_HOURS; i++) {
    blankFile[i] = blank;
  }

  fwrite(blankFile, sizeof(Reading), 24, fp);
  fclose(fp);

  return 1;
}

int writeReading(const char filename[], Reading reading) {
  FILE* fp = fopen(filename, "rb+");
  if (fp == NULL) return 0;

  fseek(fp, (long) reading.hour * sizeof(Reading), SEEK_SET);
  fwrite(&reading, sizeof(Reading), 1, fp);

  fclose(fp);
  return 1;
}

int readReading(const char filename[], int hour, Reading *readingPtr) {
  FILE* fp = fopen(filename, "rb");
  if (fp == NULL) return 0;

  fseek(fp, (long) hour * sizeof(Reading), SEEK_SET);
  fread(readingPtr, sizeof(Reading), 1, fp);

  fclose(fp);

  return 1;
}

void displayAllReadings(const char filename[]) {
  FILE* fp = fopen(filename, "rb");
  if (fp == NULL) return;

  int totalCaptured = 0;
  Reading fullFile[MAX_HOURS];

  fread(fullFile, sizeof(Reading), MAX_HOURS, fp);
  fclose(fp);

  printf("Hour  Temp (degC)  Humidity (%%)\n");
  for (int i = 0; i < MAX_HOURS; i++) {
    if (fullFile[i].hour == BLANK_HOUR) continue;

    totalCaptured++;
    printf("%4d  %11.1f  %12.1f\n", fullFile[i].hour, fullFile[i].temperature, fullFile[i].humidity);
  }

  printf("%d of the %d records have been captured.\n", totalCaptured, MAX_HOURS);
}

void displayFileInfo(const char filename[]) {
  FILE* fp = fopen(filename, "rb");
  if (fp == NULL) return;

  fseek(fp, 0, SEEK_END);
  long fileSize = ftell(fp);

  fclose(fp);

  printf("Size of one record: %ld bytes\n", sizeof(Reading));
  printf("Size of the file:   %ld bytes\n", fileSize);
  printf("Number of records:  %ld\n", fileSize / sizeof(Reading));
}

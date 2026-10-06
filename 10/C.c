#include <stdio.h>
#define NO_MONTHS 12
#define MAX_BAR_WIDTH 300


int readValues(int *values);
void writeReport(int *values, char months[][4]);


int main() {
  int rainfallValues[NO_MONTHS];
  char months[NO_MONTHS][4] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
  if (!readValues(rainfallValues)) {
    printf("Could not read rainfall values.\n");
    return 1;
  }

  writeReport(rainfallValues, months);
  return 0;
}

int readValues(int *values) {
  FILE *fp = fopen("rainfall.txt", "r");
  if (fp == NULL) {
    perror("fopen");
    return 0;
  }

  for (int i = 0; i < NO_MONTHS; i++) {
    fscanf(fp, "%d", &values[i]);
  }

  fclose(fp);
  return 1;
}

void writeReport(int *values, char months[][4]) {
  int maximum = values[0];
  FILE *fp = fopen("report.html", "w");
  if (fp == NULL) {
    perror("fopen");
    return;
  }
  //HEADING
  fprintf(fp, "<!DOCTYPE html>\n<html>\n<head><title>Report</title></head>\n<body>\n<h1>Report</h1>\n<table cellpadding=\"6\">\n");

  for (int month = 0; month < NO_MONTHS; month++) {
    if (values[month] > maximum) maximum = values[month];
  }
  for (int month = 0; month < NO_MONTHS; month++) {
    int barWidth = (int) ((double) values[month] / maximum * MAX_BAR_WIDTH);

    fprintf(fp, "<tr>\n");
    fprintf(fp, "<td>%s</td>\n", months[month]);
    fprintf(fp, "<td>%d</td>\n", values[month]);
    fprintf(fp, "<td><div style=\"background-color:steelblue; height:18px; width:%dpx;\"></div></td>\n", barWidth);
    fprintf(fp, "</tr>\n");
  }

  fprintf(fp, "</table>\n</body>\n</html>");

  fclose(fp);
  return;
}

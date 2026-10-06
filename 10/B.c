#include <stdio.h>
#include <stdlib.h>
#define MAP_SIZE 12

enum MapEntryEnum {EMPTY, WALL, START, END};
typedef enum MapEntryEnum MapEntry;

struct PositionStruct {
  int row;
  int col;
};
typedef struct PositionStruct Position;

int readMap(char *filename, MapEntry map[][MAP_SIZE]);
void printMap(MapEntry map[][MAP_SIZE], Position robot);
Position findStart(MapEntry map[][MAP_SIZE]);
void moveUp(MapEntry map[][MAP_SIZE], Position *robot);
void moveDown(MapEntry map[][MAP_SIZE], Position *robot);
void moveLeft(MapEntry map[][MAP_SIZE], Position *robot);
void moveRight(MapEntry map[][MAP_SIZE], Position *robot);


int main() {
  MapEntry map[MAP_SIZE][MAP_SIZE];
  Position robot;
  char choice;
  char mapFilename[30];

  printf("Enter the name of the map file: ");
  scanf("%29s", mapFilename);

  int readStatus = readMap(mapFilename, map);
  if (readStatus == 0) {
    printf("Could not find file: '%s'", mapFilename);
    return 1;
  } else if (readStatus != 1) {
    printf("Map file reading error.");
    return 1;
  }

  robot = findStart(map);

  while (1) {
    printMap(map, robot);
    if (map[robot.row][robot.col] == END) break;
    printf("up (w), down (s), left (a), right (d), exit (x) ");
    scanf(" %c", &choice);

    switch (choice) {
      case 'w':
        moveUp(map, &robot);
        break;
      case 's':
        moveDown(map, &robot);
        break;
      case 'a':
        moveLeft(map, &robot);
        break;
      case 'd':
        moveRight(map, &robot);
        break;
      case 'x':
        return 0;
    }
  }
}

int readMap(char *filename, MapEntry map[][MAP_SIZE]) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("fopen");
    return 0;
  }

  char rowBuffer[MAP_SIZE + 1];
  for (int row = 0; row < MAP_SIZE; row++) {
    fscanf(fp, "%12s", rowBuffer);
    for (int col = 0; col < MAP_SIZE; col++) {
      switch (rowBuffer[col]) {
        case '*':
          map[row][col] = WALL;
          break;

        case '-':
          map[row][col] = EMPTY;
          break;

        case 'S':
          map[row][col] = START;
          break;

        case 'E':
          map[row][col] = END;
          break;

        default:
          printf("ERROR: Unknow character in map.");
          return 2;
      }
    }
  }

  fclose(fp);
  return 1;
}

void printMap(MapEntry map[][MAP_SIZE], Position robot) {
  for (int row = 0; row < MAP_SIZE; row++) {
    for (int col = 0; col < MAP_SIZE; col++) {
      if (row == robot.row && col == robot.col) {
        printf("X ");
        continue;
      }

      switch (map[row][col]) {
        case EMPTY:
        case START:
          printf("  ");
          break;

        case WALL:
          printf("* ");
          break;

        case END:
          printf("E ");
          break;
      }
    }
    printf("\n");
  }
}

Position findStart(MapEntry map[][MAP_SIZE]) {
  for (int row = 0; row < MAP_SIZE; row++) {
    for (int col = 0; col < MAP_SIZE; col++) {
      if (map[row][col] == START) {
        return (Position){.row = row, .col = col};
      }
    }
  }
  perror("ERROR: No START for map.");
  exit(1);
}

void moveUp(MapEntry map[][MAP_SIZE], Position *robot) {
  if (map[robot->row-1][robot->col] == WALL) {
    return;
  }
  robot->row -= 1;
}
void moveDown(MapEntry map[][MAP_SIZE], Position *robot) {
  if (map[robot->row+1][robot->col] == WALL) {
    return;
  }
  robot->row += 1;
}
void moveLeft(MapEntry map[][MAP_SIZE], Position *robot) {
  if (map[robot->row][robot->col-1] == WALL) {
    return;
  }
  robot->col -= 1;
}
void moveRight(MapEntry map[][MAP_SIZE], Position *robot) {
  if (map[robot->row][robot->col+1] == WALL) {
    return;
  }
  robot->col += 1;
}

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

#define MAP { {WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL}, {WALL,START,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,WALL,END,EMPTY,EMPTY,WALL}, {WALL,EMPTY,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,EMPTY,WALL}, {WALL,EMPTY,WALL,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,WALL,WALL,EMPTY,WALL}, {WALL,EMPTY,WALL,EMPTY,WALL,EMPTY,WALL,WALL,WALL,WALL,EMPTY,WALL}, {WALL,EMPTY,WALL,WALL,WALL,EMPTY,WALL,EMPTY,EMPTY,EMPTY,EMPTY,WALL}, {WALL,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,WALL,EMPTY,WALL,WALL,EMPTY,WALL}, {WALL,WALL,WALL,WALL,WALL,EMPTY,WALL,EMPTY,WALL,WALL,EMPTY,WALL}, {WALL,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,WALL,WALL,EMPTY,WALL}, {WALL,EMPTY,WALL,WALL,WALL,WALL,WALL,EMPTY,WALL,WALL,EMPTY,WALL}, {WALL,EMPTY,EMPTY,EMPTY,WALL,EMPTY,EMPTY,EMPTY,WALL,EMPTY,EMPTY,WALL}, {WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL} }

void printMap(MapEntry map[][MAP_SIZE], Position robot);
Position findStart(MapEntry map[][MAP_SIZE]);
void moveUp(MapEntry map[][MAP_SIZE], Position *robot);
void moveDown(MapEntry map[][MAP_SIZE], Position *robot);
void moveLeft(MapEntry map[][MAP_SIZE], Position *robot);
void moveRight(MapEntry map[][MAP_SIZE], Position *robot);


int main() {
  MapEntry map[MAP_SIZE][MAP_SIZE] = MAP;

  Position robot = findStart(map);
  char choice;

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
  printf("ERROR: No START for map.");
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

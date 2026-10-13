#define MAX_HOURS 24    // one record per hour of the day

typedef struct reading {
  int hour;             // hour of the day (0 to 23)
  double temperature;   // temperature in degrees Celsius
  double humidity;      // relative humidity as a percentage
} Reading;

struct listNode {
  Reading data;
  struct listNode *nextPtr;
};
typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;

void addNodeAtFront(ListNodePtr *startPtrPtr, Reading data);
void addNodeAtBack(ListNodePtr *startPtrPtr, Reading data);
void printList(ListNodePtr startPtr);
int countNodes(ListNodePtr startPtr);
void clearList(ListNodePtr *startPtrPtr);

#include <stdio.h>
// Add any extra import statements you may need here


// Add any helper functions you may need here


int* CountSubarrays(int arr[], int n, int *output_size) {
  // Write your code here
  // Set output_size for test cases to run correctly

}












// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom.
void printIntegerArray(int array[], int size) {
  printf("[");
  for (int i = 0; i < size; i++) {
    if (i != 0) {
      printf(", ");
    }
    printf("%d", array[i]);
  }
  printf("]");
}

int test_case_number = 1;

void check(int expected[], int output[], int size, int out_size) {
  int expected_size = size;
  int output_size = out_size;
  int result = 1;
  if (expected_size != output_size) {
    result = 0;
  }
  else {
    for (int i = 0; i < size; i++) {
      result &= (output[i] == expected[i]);
    }
  }
  const char* rightTick = u8"\u2713";
  const char* wrongTick = u8"\u2717";
  if (result) {
    printf("%s Test #%d\n", rightTick, test_case_number);
  }
  else {
    printf("%s Test #%d: Expected ", wrongTick, test_case_number);
    printIntegerArray(expected, size);
    printf(" Your output: ");
    printIntegerArray(output, output_size);
    printf("\n");
  }
  test_case_number++;
}

int main() {
  // testcase 1
  int test_1[] = {3, 4, 1, 6, 2};
  int expected_1[] = {1, 3, 1, 5, 1};
  int output_1_size;
  int *output_1 = CountSubarrays(test_1, 5, &output_1_size);
  check(expected_1, output_1, 5, output_1_size);

  // testcase 2
  int test_2[] = {2, 4, 7, 1, 5, 3};
  int expected_2[] = {1, 2, 6, 1, 3, 1};
  int output_2_size;
  int *output_2 = CountSubarrays(test_2, 6, &output_2_size);
  check(expected_2, output_2, 6, output_2_size);

  // Add your own test cases here

}

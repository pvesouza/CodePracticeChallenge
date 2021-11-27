#include <stdio.h>
// Add any extra import statements you may need here

int *ptr = nullptr;


// Find the Three Large
int* findThreeLargest (int arr[], int n, int *ptr_aux) {

    int threeLargest[3] = {0, 0, 0};
    int lastPosition[3] = {0, 0, 0};

    for (int i = 0; i < n; i++){
        if (threeLargest[2] < arr[i]) {
            threeLargest[2] = arr[i];
            lastPosition[2] = i;
        }
    }

    for (int i = 0; i < n; i++) {
        if (i != lastPosition[2]) {
            if (threeLargest[1] < arr[i]) {
                threeLargest[1] = arr[i];
                lastPosition[1] = i;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (i != lastPosition[2] && i != lastPosition[1]) {
            if (threeLargest[0] < arr[i]) {
                threeLargest[0] = arr[i];
                lastPosition[0] = i;
            }
        }
    }

    ptr_aux = threeLargest;
    return ptr_aux;

}


int* findMaxProduct(int arr[], int n, int *output_size) {



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
  // Testcase 1
  int n_1 = 5;
  int arr_1[] = {1, 2, 3, 4, 5};
  int expected_1[] = {-1, -1, 6, 24, 60};
  int output_1_size;
  int *output_1 = findMaxProduct(arr_1, n_1, &output_1_size);
  check(expected_1, output_1, n_1, output_1_size);

  // Testcase 2
  int n_2 = 6;
  int arr_2[] = {2, 4, 7, 1, 5, 3};
  int expected_2[] = {-1, -1, 56, 56, 140, 140};
  int output_2_size;
  int *output_2 = findMaxProduct(arr_2, n_2, &output_2_size);
  check(expected_2, output_2, n_2, output_2_size);

  // Add your own test cases here

}

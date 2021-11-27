#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int test_case_number = 1;

char rotate(char a, char inf, char sup, int rotationFactor) {

    for (int i = 0; i < rotationFactor; i++){
        if (a == sup) {
            a = inf;
        }else{
            a = a + 1;
        }
    }
    return a;
}

char* rotationalCipher(char input[], int rotationFactor) {

    int inputSize = strlen(input);
    char result[inputSize];                 //Declares a result with the size of input

    for (int i = 0; input[i] != '\0'; i++){

        // Character is numeric ?
        if (input[i] >= '0' && input[i] <= '9') {

            input[i] = rotate(input[i], '0', '9', rotationFactor);

        }else if (input[i] >= 'A' && input[i] <= 'Z') { // Is input alphanumeric ?
            input[i] = rotate(input[i], 'A', 'Z', rotationFactor);

        }else if (input[i] >= 'a' && input[i] <= 'z') {
            input[i] = rotate(input[i], 'a', 'z', rotationFactor);

        }

        //printf("%c", input[i]);
    }

    //printf("\n");

    return input;

}


// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom.

void printCharArray(char arr[]) {

  printf("[\"");
  for (int i = 0; arr[i] != '\0'; i++) {
    printf("%c", arr[i]);
  }
  printf("\"]");
}


void check(char expected[], char output[]) {


    int result = !strcmp(expected, output);
    const char* rightTick = u8"\u2713";
    const char* wrongTick = u8"\u2717";

    if (result) {
        printf("%s Test #%d\n", rightTick, test_case_number);
    }
    else {

        printf("%s Test # %d: Expected ", wrongTick, test_case_number);
        printCharArray(expected);
        printf(" Your output: ");
        printCharArray(output);
        printf("\n");
    }

    test_case_number++;

}

int main(void) {

  char input_1[] = "All-convoYs-9-be:Alert1.";
  int rotationFactor_1 = 4;
  char expected_1[] = "Epp-gsrzsCw-3-fi:Epivx5.";
  char* output_1 = rotationalCipher(input_1, rotationFactor_1);
  check(expected_1, output_1);

  char input_2[] = "abcdZXYzxy-999.@";
  int rotationFactor_2 = 200;
  char expected_2[] = "stuvRPQrpq-999.@";
  char* output_2 = rotationalCipher(input_2, rotationFactor_2);
  check(expected_2, output_2);

  // Add your own test cases here
  return 0;

}

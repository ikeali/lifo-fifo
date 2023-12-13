#include "monty.h"

int main(void) {
    bus_t bus = {NULL, NULL, NULL, 0};

    FILE *file = fopen("example.txt", "r");
    if (!file) {
    }

    bus.file = file;


    fclose(bus.file);

    return 0;
}


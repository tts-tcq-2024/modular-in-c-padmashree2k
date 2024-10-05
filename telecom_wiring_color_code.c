#include <stdio.h>
#include "telecom_wiring_color_code.h"

// Array of major colors
const char* major_colors[MAJOR_COLOR_COUNT] = {"White", "Red", "Black", "Yellow", "Violet"};

// Array of minor colors
const char* minor_colors[MINOR_COLOR_COUNT] = {"Blue", "Orange", "Green", "Brown", "Slate"};

// Function to get the major color based on index
const char* get_major_color(int index) {
    if (index < 0 || index >= MAJOR_COLOR_COUNT) {
        return "Invalid";
    }
    return major_colors[index];
}

// Function to get the minor color based on index
const char* get_minor_color(int index) {
    if (index < 0 || index >= MINOR_COLOR_COUNT) {
        return "Invalid";
    }
    return minor_colors[index];
}

// Function to print the color reference table
void print_color_reference() {
    printf("%-10s%-15s%-15s\n", "Pair No.", "Major Color", "Minor Color");

    int pair_number = 1;
    for (int major = 0; major < MAJOR_COLOR_COUNT; ++major) {
        for (int minor = 0; minor < MINOR_COLOR_COUNT; ++minor) {
            printf("%-10d%-15s%-15s\n", pair_number, get_major_color(major), get_minor_color(minor));
            pair_number++;
        }
    }
}

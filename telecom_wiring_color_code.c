#include "color_pair.h"
#include <stdio.h>

// Arrays storing names of Major and Minor Colors
const char* MajorColorNames[] = { "White", "Red", "Black", "Yellow", "Violet" };
const char* MinorColorNames[] = { "Blue", "Orange", "Green", "Brown", "Slate" };

// Constants to calculate the number of colors
int numberOfMajorColors = sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);
int numberOfMinorColors = sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);

// Function to convert a color pair to a string
void ColorPairToString(const ColorPair* colorPair, char* buffer) {
    sprintf(buffer, "%s %s", MajorColorNames[colorPair->majorColor], MinorColorNames[colorPair->minorColor]);
}

// Function to get the ColorPair based on pair number
ColorPair GetColorFromPairNumber(int pairNumber) {
    ColorPair colorPair;
    int zeroBasedPairNumber = pairNumber - 1;
    colorPair.majorColor = (enum MajorColor)(zeroBasedPairNumber / numberOfMinorColors);
    colorPair.minorColor = (enum MinorColor)(zeroBasedPairNumber % numberOfMinorColors);
    return colorPair;
}

// Function to get the pair number from ColorPair
int GetPairNumberFromColor(const ColorPair* colorPair) {
    return colorPair->majorColor * numberOfMinorColors + colorPair->minorColor + 1;
}

// Function to print color reference manual for wiring personnel
void printColorReferenceManual() {
    printf("%-10s%-15s%-15s\n", "Pair No.", "Major Color", "Minor Color");

    int pairNumber = 1;
    for (int major = 0; major < numberOfMajorColors; ++major) {
        for (int minor = 0; minor < numberOfMinorColors; ++minor) {
            ColorPair colorPair = GetColorFromPairNumber(pairNumber);
            char colorPairNames[16];
            ColorPairToString(&colorPair, colorPairNames);
            printf("%-10d%-15s%-15s\n", pairNumber, MajorColorNames[colorPair.majorColor], MinorColorNames[colorPair.minorColor]);
            pairNumber++;
        }
    }
}

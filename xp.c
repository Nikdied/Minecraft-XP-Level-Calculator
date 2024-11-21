#include <stdio.h>

#define XP 250000
/* remove "//" in line below and set value if you want to know how many xp you need for a specific level */
#define LEVEL 1000000
/* remove "//" in line below to skip output of iterations */
#define SKIP

#define START_XP 7
#define START_SECTION_TWO 16
#define START_SECTION_THREE 31

#define XP_VALUE_ONE 2
#define XP_VALUE_TWO 5
#define XP_VALUE_THREE 9

int getXPDifferenceFromLevel(int level);

int main(int charc, char* charv) {
    int xpNeededPerLevel = START_XP - XP_VALUE_ONE;
    int level = 0;
    int levelDifference = 0;
    long long int xpFromZero = 0;

    #ifndef LEVEL
    int xpLeft = 0;
    #endif

    int running = 1;
    while(running) {
        levelDifference = getXPDifferenceFromLevel(level);

        xpNeededPerLevel = levelDifference + xpNeededPerLevel;
        xpFromZero = xpFromZero + xpNeededPerLevel;

        #ifndef LEVEL
        if(xpFromZero >= XP) {
        #endif

        #ifdef LEVEL
        if(level == LEVEL) {
        #endif

            xpFromZero = xpFromZero - xpNeededPerLevel;
            xpNeededPerLevel = xpNeededPerLevel - levelDifference;

            #ifndef SKIP
            printf("Done\n");
            #endif

            #ifdef SKIP

                #ifndef LEVEL
                printf("Level: %i   XP needed: %i   XP from zero: %lli   XP-Left: %i\n", level, xpNeededPerLevel, xpFromZero, xpLeft);
                #endif

                #ifdef LEVEL
                printf("Level: %i   XP needed: %i   XP from zero: %lli\n", level, xpNeededPerLevel, xpFromZero);
                #endif

            #endif

            running = 0;
        } else {
            #ifndef LEVEL
            xpLeft = XP - xpFromZero;
            #endif

            level++;
        }

        #ifndef SKIP

            #ifndef LEVEL
            printf("Level: %i   XP needed: %i   XP from zero: %lli   XP-Left: %i\n", level, xpNeededPerLevel, xpFromZero, xpLeft);
            #endif

            #ifdef LEVEL
            printf("Level: %i   XP needed: %i   XP from zero: %lli\n", level, xpNeededPerLevel, xpFromZero);
            #endif

        #endif
    }
    return 0;
}

int getXPDifferenceFromLevel(int level) {
    if(level < START_SECTION_TWO) {
        return XP_VALUE_ONE;
    }
    else if(level < START_SECTION_THREE) {
        return XP_VALUE_TWO;
    } else {
        return XP_VALUE_THREE;
    }
}
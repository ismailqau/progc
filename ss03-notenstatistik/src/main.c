/* -----------------------
 ____  _  _   __   _  _
(__  )/ )( \ / _\ / )( \
 / _/ ) __ (/    \\ /\ /
(____)\_)(_/\_/\_/(_/\_)
-------------------------- */
/**
 * @file
 * @brief Generates Marks and Stats given points
 * User can input the scores of their students and then generate stats based
 * on the minimum score needed for mark 6.
 * The same scores can be used to generate different stats with different minimum points.
 */
#include <stdio.h>
#include <stdlib.h>

const int MAX_POINTS_SIZE = 100;

typedef struct {
    int perMarkCount[6];
    int worstMark;
    int bestMark;
    int markSum;
    int averageMark;
    int passedCount;
    double passedPercent;
} stats;

void readMinPoints(int *minPoints)
{
    (void) printf("How many points are needed for mark 6? ");
    scanf("%d", minPoints);
    (void) printf("\n");
}

int readPoints(int points[MAX_POINTS_SIZE], int *pointsLen)
{
    (void) printf("Type in the points of your students:\n");
    int i = 0;
    int point;
    do {
        point = -2; // reset point so it fails when no number is entered.
        (void) scanf("%d", &point);
        if (point >= 0) {
            points[i] = point;
            i += 1;
        }
    } while(point >= 0);

    // if input is -1 the user broke out correctly.
    if (point == -1) {
        *pointsLen = i;
        return 1;
    }
    // Otherwise there was an illegal input
    (void) printf("Illegal input!\n");
    return 0;
}

int calcRoundedMark(int minPoints, int points)
{
    double mark = 1 + (points * 5) / (minPoints * 1.0);
    int roundedDown = mark;
    double rest = mark - roundedDown;
    int result;
    if (rest >= 0.5) {
        result = roundedDown + 1;
    }
    result = roundedDown;
    if (result > 6) {
        return 6;
    }
    if (result < 0 ) {
        return 0;
    }
    return result;
}

stats calcStats(const int minPoints, const int points[MAX_POINTS_SIZE], const int studentsAmount)
{
    stats stats = { { 0 } };
    stats.worstMark = 6;
    stats.bestMark = 0;
    stats.markSum = 0;
    stats.averageMark = 0;
    stats.passedCount = 0;
    stats.passedPercent = 0;


    for (int i = 0; i < studentsAmount; i++) {
        int point = points[i];
        int mark = calcRoundedMark(minPoints, point);
        stats.bestMark = stats.bestMark > mark ? stats.bestMark : mark;
        stats.worstMark = stats.worstMark < mark ? stats.worstMark : mark;
        stats.markSum += mark;
        stats.passedCount = mark >= 4 ? stats.passedCount + 1 : stats.passedCount;
        stats.perMarkCount[mark - 1] += 1;
    }
    stats.averageMark = stats.markSum / studentsAmount;
    stats.passedPercent = stats.passedCount * 1.0 / studentsAmount * 100;
    return stats;
}

void printStats(const int minPoints, const int studentsAmount, const stats stats)
{
    (void) printf("------------------------------------------\n");
    (void) printf("Statistic (%d students, %d Points for Mark 6):\n", studentsAmount, minPoints);
    (void) printf("\n");
    for (int i = 5; i >= 0; i--) {
        (void) printf("Mark %d:\t%3d\n", i + 1, stats.perMarkCount[i]);
    }
    (void) printf("\n");
    (void) printf("Best Mark:\t%d\n", stats.bestMark);
    (void) printf("Worst Mark:\t%d\n", stats.worstMark);
    (void) printf("Average Mark:\t%d\n", stats.averageMark);
    (void) printf("Mark >= 4:\t%d Students (%5.2f%%)\n", stats.passedCount, stats.passedPercent);
    (void) printf("------------------------------------------\n");
}

/**
 * @brief Main entry point.
 * @returns Returns EXIT_SUCCESS (=0) on success,
 *                  EXIT_FAILURE (=1) if there was an illegal input
 */
int main(void)
{
    (void) printf("Generate stats: \n");
    int points[MAX_POINTS_SIZE];
    int pointsLen;
    int minPoints;
    int repeat;

    if (readPoints(points, &pointsLen)) {
        do {
            repeat = 0;
            minPoints = 0;
            (void) readMinPoints(&minPoints);

            if (minPoints == 0) {
                return EXIT_FAILURE;
            }
            stats stats = calcStats(minPoints, points, pointsLen);
            (void) printStats(minPoints, pointsLen, stats);

            (void) printf("Try out another metric? (Yes=1 / No=0) \n");
            scanf("%d", &repeat);
        } while(repeat);

        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}

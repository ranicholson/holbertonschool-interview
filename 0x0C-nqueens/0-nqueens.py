#!/usr/bin/python3

"""Program that solves the N queens puzzle"""

import sys

if len(sys.argv) != 2:
    print("Usage: nqueens N")
    sys.exit(1)

if not sys.argv[1].isnumeric():
    print("N must be a number")
    sys.exit(1)

if int(sys.argv[1]) < 4:
    print("N must be at least 4")
    sys.exit(1)

N = int(sys.argv[1])
solutionStash = []


def checkTheQueens(queenPosition):
    """Main function to check positions to safely place N queens"""

    while queenPosition[0] < N:
        while queenPosition[1] < N:
            if not emptySpotCheck(queenPosition) and\
             not protectedSpot(queenPosition):
                solutionStash.append(queenPosition.copy())

                if len(solutionStash) == N:
                    print(solutionStash)
                    solutionStash.pop()
                    return

                checkTheQueens(queenPosition.copy())
                solutionStash.pop()

            queenPosition[1] += 1

        queenPosition[1] = 0
        queenPosition[0] += 1


def emptySpotCheck(queenPosition):
    """Checks that the current position is empty"""

    for position in solutionStash:
        if queenPosition[0] == position[0] and queenPosition[1] == position[1]:
            return True

    return False


def protectedSpot(queenPosition):
    """
    Checks that a queen placed in a position will not
    be open to attack from another queen
    """

    for position in solutionStash:
        if queenPosition[0] == position[0] or queenPosition[1] == position[1]:
            return True

        tmpVar1CausePep8 = abs(queenPosition[0] - position[0])
        tmpVar2CausePep8 = abs(queenPosition[1] - position[1])
        if tmpVar1CausePep8 == tmpVar2CausePep8:
            return True

    return False

checkTheQueens([0, 0])

import math

def cubicPerms():
    N = 345
    digitDict = dict()
    while True:
        cube = N ** 3
        sortedDigits = ''.join(sorted(str(cube)))
        
        if sortedDigits in digitDict.keys():
            digitDict[sortedDigits] = [digitDict[sortedDigits][0], digitDict[sortedDigits][1] + 1]
        else:
            digitDict.update({sortedDigits: [cube, 1]})

        if digitDict[sortedDigits][1] == 5:
            print("Smallest Cube: ", digitDict[sortedDigits][0])
            break
        N += 1


if __name__ == "__main__":
    cubicPerms()

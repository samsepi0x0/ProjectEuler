import collections

class Hand:
    cardval = list()
    suits = set()

    lookup = {'2':2, '3': 3, '4': 4, '5': 5, '6': 6, '7': 7, '8':8, 
            '9':9, 'T': 10, 'J': 11, 'Q': 12, 'K':13, 'A': 14}

    def __init__(self, hand):
        self.cardval = list()
        self.suits = set()
        
        for val in hand:
            self.cardval.append(self.lookup[val[0]])
            self.suits.add(val[1])
        
        sorted(self.cardval, reverse=True)
    
    def isConsecutive(self):
        arr = sorted(self.cardval)
        increment = True
        for i in range(1, 5):
            if abs(arr[i] - arr[i-1]) != 1:
                increment = False
        return increment

    def calculateHand(self):
        incremented = self.isConsecutive()
        rank = -1
        value = list()
        if len(self.suits) == 1:
            if incremented:
                if sorted(self.cardval, reverse = True)[4] == 10:
                    rank = 10
                    value = sorted(self.cardval, reverse = True)
                     
                else:
                    rank = 9
                    value = sorted(self.cardval, reverse = True)
                     
            else:
                rank = 6
                value = sorted(self.cardval, reverse = True)
                
        if incremented:
            if rank == -1:
                rank = 5
                value = sorted(self.cardval, reverse = True)   
        
        cardFreq = collections.Counter(self.cardval)
        
        if len(cardFreq) == 2:
            for key, freq in cardFreq.items():
                if (freq == 4):
                    rank = 8
                    value = [key] + value
                elif (freq == 3):
                    rank = 7
                    value = [key] + value
                else:
                    value.append(key)
        
        if (rank > -1):
            return rank, value  
            
        elif len(cardFreq) == 3:
            threeFreq = False
            for key, freq in cardFreq.items():
                if (freq == 3):
                    threeFreq = True
                    rank = 4
                    value = [key] + value
                elif (freq == 2):
                    rank = 3
                    value = [key] + value
                else:
                    value.append(key)
            if not threeFreq:
                maxval = max(value[0], value[1])
                minval = min(value[0], value[1])

                value = [value[0], value[1]] + sorted(value[2:], reverse = True)
            else:
                value = [value[0]] + sorted(value[1:], reverse = True)
            
        else:
            if 2 in cardFreq.values():
                pair = -1
                for key, freq in cardFreq.items():
                    if (freq == 2):
                        pair = key
                    else:
                        value.append(key)
                rank = 2
                value = [pair] + sorted(value, reverse = True) 
                
            else:
                rank = 1
                value = sorted(self.cardval, reverse=True)
        
        return rank, value


def winner(player1, player2):
    """
        0 -> player1 wins
        1 -> player2 wins 
    """

    P1 = Hand(player1)
    P2 = Hand(player2)

    P1_rank, P1_value = P1.calculateHand()
    P2_rank, P2_value = P2.calculateHand()
    
    # print(P1.cardval, P1.suits, P1_value, P1_rank)
    # print(P2.cardval, P2.suits, P2_value, P2_rank)

    if (P1_rank > P2_rank):
        return 0
    elif (P1_rank < P2_rank):
        return 1
    else:
        for x, y in zip(P1_value, P2_value):
            if (x > y):
                return 0
            if (x < y):
                return 1

    return -1

def main():
    file = open("poker.txt", 'r')
    lines = file.readlines()
    score = [0, 0]

    for line in lines:
        cards = line.strip().split(" ")
        player1, player2 = cards[0:5], cards[5:]
        playerWin = winner(player1, player2)
        # print( "Player 1" if playerWin == 0 else "Player 2")
        score[playerWin] += 1

    print(f"Player 1 wins {score[0]} times.")
    print(f"Player 2 wins {score[1]} times.")

if __name__ == "__main__":
  main()

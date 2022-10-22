def lottery(maxW, items, n):
    # Sorting the items list in descending order of prices/weight ratio
    sortedP = sorted(items, key=lambda item: item[0]/item[1], reverse=True)

    # Creating 3 empty arrays to store price, weight and name of each item
    prices = [0] * n
    weights = [0] * n
    names = [0] * n
    total = 0.00

    # Assigning values to empty arrays from sorted list
    for i in range(n):
        prices[i], weights[i], names[i] = sortedP[i]
    print("Selected items:")

    # Iterating the items from sorted list
    for i in range(n):
        if maxW == 0:
            break

        # If the weight of an item is lesser than max weight, it will be included totally
        if weights[i] <= maxW:
            maxW = maxW - weights[i]
            total += prices[i]
            # Printing name and weight of selected item
            print(names[i], weights[i])
        
        # Else, fraction of that particular item will be selected
        else:
            total += prices[i] * (maxW / weights[i])
            # Printing name and weight of selected item
            print(names[i], maxW)
            maxW = 0
    return total
            
# Main Code
items = [(1050,1,"Apple"), (600,6,"Banana"), (400,8,"Papaya"), (1500,5,"Watermelon"), (800,4,"Orange"), (1800,6,"Potato"),
        (300,1,"Carrot"), (900,2,"Egg Plant"), (600,3,"Beetroot"), (1000,5,"Ladies' Fingers")]
maxW = 30
n = len(items)
print ("Maximum price of the selection = ", lottery(maxW, items, n), " Rupees")

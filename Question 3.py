#SCS2201 DSA III
#Assignment
#Question Number 03
#L.H.T.Lakshan
#20001012

#Enter the string

MsgString = input("Enter your message ")

class NodeTree(object):
    def __init__(self, left=None, right=None):
        self.left = left
        self.right = right
    def children(self):
        return (self.left, self.right)
    def nodes(self):
        return (self.left, self.right)
    def __str__(self):
        return '%s_%s' % (self.left, self.right)

# Main function implementation of huffman coding

def huffman_code_tree(node, left=True, binString=''):
    if type(node) is str:
        return {node: binString}
    (l, r) = node.children()
    d = dict()
    d.update(huffman_code_tree(l, True, binString + '0'))
    d.update(huffman_code_tree(r, False, binString + '1'))
    return d
    
#Calculate the frequency of letters in the given string

freq = {}

LetterCount = 0

for i in MsgString:
    LetterCount +=1
    if i in freq:
        freq[i] += 1
    else:
        freq[i] = 1

def sortSecond(val):
    return val[1]
freq= sorted(freq.items() ,key=sortSecond ,reverse=True)
nodes = freq

while len(nodes) > 1:
    (key1, c1) = nodes[-1]
    (key2, c2) = nodes[-2]
    nodes = nodes[:-2]
    node = NodeTree(key1, key2)
    nodes.append((node, c1 + c2))

    nodes= sorted(nodes ,key=sortSecond ,reverse=True)
huffman_code = huffman_code_tree(nodes[0][0])

print("\n------------------------------------------------")
print(" The Huffman code is")
print("------------------------------------------------")
for (char, frequency) in freq:
    print(' %-2r |%12s' % (char, huffman_code[char]))

print("\nMessage  :" +MsgString)
EncodedBits = 0
for c in MsgString:
    print(huffman_code[c]+ " " ,end = " ")
    EncodedBits = EncodedBits + len(huffman_code[c])

print("\n------------------------------------------------")
print("Total number of characters in the above message : " +str(LetterCount))
print("Each character takes 1 byte. So, the total number of bits needed :" +str(LetterCount*8))
print("After Huffman coding, total number of bits needed :" +str(EncodedBits))
print("Number of bits saved :" +str(LetterCount*8 - EncodedBits))
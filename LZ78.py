#LZ78 compression
import sys

def encode(text):
    #text="BABAABRRRA"#for test
    #text="abcdefsabcefssdfsdsdfdsf"
    mydict = dict()
    i = 0
    index = 1
    Numbers = []
    Letters = []
    #writing your code to encode text with LZ78
    p = ''#prefix
    c = ''#character
    mydict[p]=0
    for ch in text:
        c = ch
        if (p+c) in mydict:
            p=p+c
        else:
            Numbers.append(mydict[p])#add to current stream output
            Letters.append(c)#update Letters
            mydict[p+c]= index#add to dict<-- now valid
            index+=1
            p=''
    if p!='':
        Numbers.append(mydict[p])
        Letters.append('')
        
    return Numbers, Letters, mydict
        
def decode(lstNumbers, lstLetters, mydict):
    i = 0
    while i < len(lstNumbers):
        if (lstNumbers[i] != 0):    
            print(list(mydict.keys())[list(mydict.values()).index(lstNumbers[i])], end="")
        print(lstLetters[i], end="")
        i = i+1
    print('\n')

def dosth(stringToEncode):
    [lstNumbers, lstLetters, mydict] = encode(stringToEncode)
    print("Encoded string: ", end="")
    i = 0
    while i < len(lstNumbers):
        print ("<{0}, {1}>".format(lstNumbers[i], lstLetters[i]), end=" ")
        i = i + 1
    print('\n')
    print("Decoded string: ", end = "")
    decode(lstNumbers, lstLetters, mydict)

if __name__ == "__main__":
    if (len(sys.argv) != 2):
        exit("Usage:(Run with python lz78.py abracadabra)")
    dosth("abcdefsabcefssdfsdsdfdsf")
    dosth("qwertrtewertetrewerewr")

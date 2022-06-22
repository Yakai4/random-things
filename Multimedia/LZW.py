#LZW compression practice
import sys

def encode(text):
    #text="abcdefsabcefssdfsdsdfdsf"#for test
    
    mydict = dict()
    # prepare the initial mydict 
    mydict=dict.fromkeys(text)
    num = 0
    for i in mydict:
        mydict[i]=num
        num+=1
    output = []
    # write your encoding code here... 
    p = ''#prefix
    c = ''#character
    for ch in text:
        c=ch
        if (p+c) in mydict:
            p=p+c
        else:
            output.append(mydict[p])#add to current stream output
            mydict[p+c]= num#add to dict<-- now valid
            num+=1
            p=c
    if p!='':
        output.append(mydict[p])
    return output, mydict
        
def decode(output, mydict):
    i = 0
    while i < len(output):
        print(list(mydict.keys())[list(mydict.values()).index(output[i])], end="")
        i = i+1
    print('\n')

def dosth(text):
    [output, mydict] = encode(text)
    print("output string: ", output)
    print("Decoded string: ", end = "")
    decode(output, mydict)

if __name__ == "__main__":
    if (len(sys.argv) != 2):
        exit("Usage:(Run with python lzw.py abracadabra)")
    dosth("abcdefsabcefssdfsdsdfdsf")
    dosth("qwertrtewertetrewerewr")
    
#copied from jupyter notebook.
#and never mind.

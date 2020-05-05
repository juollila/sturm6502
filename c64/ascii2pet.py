#/usr/bin/python

import string
import argparse
import re

def parseArguments():
    parser = argparse.ArgumentParser()
    parser.add_argument("file", help="ascii file to be converted to petscii")
    args = parser.parse_args()
    return args

if __name__ == "__main__":
    args = parseArguments()

    with open(args.file, 'r') as f:
        inputdata = f.read()

    petscii_uppercase_list = []
    for i in range(0xc1,0xdb):
        petscii_uppercase_list.append(chr(i))
    petscii_uppercase = ''.join(petscii_uppercase_list)

    table = string.maketrans(string.uppercase+'\x0a',petscii_uppercase+'\x0d')
    table2 = string.maketrans(string.lowercase,string.uppercase)

    outputdata = string.translate(inputdata,table)
    outputdata = string.translate(outputdata,table2)
    outputdata = re.sub('\t', "    ", outputdata)
    print outputdata

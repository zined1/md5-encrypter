#!/usr/bin/env python3
import hashlib, subprocess, random, string, sys
if len(sys.argv) > 2:
    print("Usage : ./check.py or ./checkpy with a number")
else:
    number = 30
    if len(sys.argv) == 2:
        number = int(sys.argv[1])
    for i in range(number):
        text = ''.join(random.choice(string.ascii_uppercase + string.digits) for _ in range(random.randint(1, number)))
        my = (subprocess.run(['./md5encrypter', text], stdout=subprocess.PIPE)).stdout.decode('utf-8').rstrip()
        ref = hashlib.md5(text.encode('utf-8')).hexdigest()
        print(text + " -> " + my + " = ", end='')
        if (my == ref):
            print("\033[92m"+ 'PASS' + "\033[00m")
        else:
            print("\033[91m"+ 'FAIL' + "\033[00m")
    

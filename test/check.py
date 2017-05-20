#!/usr/bin/env python3
import hashlib, subprocess, random, string
for i in range(50):
    text = ''.join(random.choice(string.ascii_uppercase + string.digits) for _ in range(random.randint(1, 50)))
    my = (subprocess.run(['./md5encrypter', text], stdout=subprocess.PIPE)).stdout.decode('utf-8').rstrip()
    ref = hashlib.md5(text.encode('utf-8')).hexdigest()
    print(text + " -> " + my + " = ", end='')
    if (my == ref):
        print("\033[92m"+ 'PASS' + "\033[00m")
    else:
        print("\033[91m"+ 'FAIL' + "\033[00m")
    

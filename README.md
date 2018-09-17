
# MD5Encrypter

Resume
------

This project is a simple MD5Encrypter. I did this project to better understand the MD5.

___
Execution
---------

First, at the root of the project:

    > make
    
Launch the program with the word "simple" is simple:

    > ./md5encrypter "simple"
    < 8dbdda48fb8748d6746f1965824e966a

___
Tests
-------

To run all the tests:

    > make test
    < R7ZKP -> 8571e761b4c351f42c7926521cf0f816 = PASS
      5N5D1D7FGL6PXB -> 288488485b5fd7956d934d0f594170e1 = PASS
      5X87F1JY6 -> 65f93f5cfa721a870e335c93bac19c06 = PASS
      G5OY44DPA212T -> 7e1ade645e37d6691f24d2669509cefa = PASS
      ...

The test will generate random strings. Theses strings will be encrypted thanks to hashlib (python) and compared with the program.

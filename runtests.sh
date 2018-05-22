myexec='runtests'
g++ -std=c++11 -isystem ~/build/googletest/googletest/include/ -pthread ./tests.cpp  ~/build/googletest/googletest/libgtest.a -o $myexec
./$myexec

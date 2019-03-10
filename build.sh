#!/bin/bash

echo {"Usage: ./build.sh filename"}
gcc msgpub.c -o msgpub -lczmq -lzmq
gcc msgsub.c -o msgsub -lczmq -lzmq
gcc msgproxy.c -o msgproxy   -lczmq -lzmq

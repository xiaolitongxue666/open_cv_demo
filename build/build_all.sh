#!/bin/sh
cmake ..
make clean
make
clear
./open_cv_demo ../test_images/Lenna.png


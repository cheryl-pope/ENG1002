#!/usr/bin/env bash

apt-get update
apt-get install -y python3 python3-pip python3-dev
apt-get install -y g++
apt-get install -y jsoncpp

apt-get install -y libjsoncpp-dev

apt-get install -y clang

pip3 install -r /autograder/source/requirements.txt

ln -s /usr/bing/clang++ /usr/bin/clang++

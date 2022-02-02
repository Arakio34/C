#!/bin/bash

sed -i "s/schema/$1/g" ../*
mv ../schema.c ../$1.c
mv ../schema.h ../$1.h

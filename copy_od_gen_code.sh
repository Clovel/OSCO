#!/bin/bash

# This script copies the generated C code
# that implements the CANOpen object dictionaries
# into the correct directory for compilation

# Variable declarations -------------------------
MY_DIR=$(dirname $(readlink -f $0))
DEST_DIR="$MY_DIR/gen/"

# Check that the destination directory exists ---
if [[ ! -d $DEST_DIR ]]; then
    echo "[ERROR] Destination directory $DEST_DIR doesn't exist"
    exit 1
fi

# Check arguments -------------------------------
SRC_DIR="$1"
echo "[INFO ] Copying generated OD C code from $SRC_DIR to $DEST_DIR"

if [[ ! -d $SRC_DIR ]]; then
    echo "[ERROR] Source directory $SRC_DIR doesn't exist"
    exit 1
fi

# Check that all expected files are present -----
MISSING_FILES=
if [[ ! -f "$SRC_DIR/OSCOGenNodeID.h" ]]; then
    echo "[ERROR] Missing generated file : OSCOGenNodeID.h"
    MISSING_FILES="YES"
fi
if [[ ! -f "$SRC_DIR/OSCOGenOD.h" ]]; then
    echo "[ERROR] Missing generated file : OSCOGenOD.h"
    MISSING_FILES="YES"
fi
if [[ ! -f "$SRC_DIR/OSCOGenOD.c" ]]; then
    echo "[ERROR] Missing generated file : OSCOGenOD.c"
    MISSING_FILES="YES"
fi
if [[ ! -f "$SRC_DIR/OSCOGenOD_Values.c" ]]; then
    echo "[ERROR] Missing generated file : OSCOGenOD_Values.c"
    MISSING_FILES="YES"
fi
if [[ ! -f "$SRC_DIR/OSCOGenOD_DefaultValues.c" ]]; then
    echo "[ERROR] Missing generated file : OSCOGenOD_DefaultValues.c"
    MISSING_FILES="YES"
fi
if [[ ! -f "$SRC_DIR/OSCOGenOD_MaxValues.c" ]]; then
    echo "[ERROR] Missing generated file : OSCOGenOD_MaxValues.c"
    MISSING_FILES="YES"
fi
if [[ ! -f "$SRC_DIR/OSCOGenOD_MinValues.c" ]]; then
    echo "[ERROR] Missing generated file : OSCOGenOD_MinValues.c"
    MISSING_FILES="YES"
fi

if [[ "YES" -eq "$MISSING_FILES" ]]; then
    exit 1
fi

# Backup the CMakeLists.txt ---------------------
mv $DEST_DIR/CMakeLists.txt $MY_DIR/CMakeLists.txt.bak

# Clear the destination directory ---------------
rm -rf $DEST_DIR/*

# Copy files to the destination directory -------
cp -rv $SRC_DIR/* $DEST_DIR/

# Restore CMakeLists.txt ------------------------
mv $MY_DIR/CMakeLists.txt.bak $DEST_DIR/CMakeLists.txt

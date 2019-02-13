#!/bin/bash
ls -lRa | grep "^-" | rev | cut -d" " -f1 | rev | grep -v ".sh$"

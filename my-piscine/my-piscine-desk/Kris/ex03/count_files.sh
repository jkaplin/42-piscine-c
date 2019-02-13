#!/bin/bash
ls -Rl | grep -v "^./" | grep -v "^total" | wc -l | bc

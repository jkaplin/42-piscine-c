#!/bin/bash
ldapsearch "(uid=z*)" cn | grep "cn: " | cut -d" " -f2- | sort -f -r
